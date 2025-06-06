#include <llvm/IR/Constants.h>
#include <llvm/IR/Instructions.h>

using namespace llvm;

class ASMBuilder {
    llvm::Module* module;
    std::ofstream out;
    int regCount = 0;
    std::unordered_map<const llvm::Value*, std::string> valueToReg;
    std::vector<std::string> usedSavedRegs; // 记录使用的保存寄存器
    
    // 新增：当前函数的栈帧信息
    unsigned stackSize;   // 栈帧总大小
    unsigned calleeSaved; // 保存的寄存器数量
    unsigned localSize;   // 局部变量总大小

public:
    ASMBuilder(Module* m) : module(m) {}

    void generate(const std::string& outputFile) {
        out.open(outputFile);
        if (!out.is_open()) {
            errs() << "Failed to open output file: " << outputFile << "\n";
            return;
        }

        emit(".data");
        for (const auto& global : module->globals()) {
            if (global.hasInitializer()) {
                if (auto *ci = dyn_cast<ConstantInt>(global.getInitializer())) {
                    out << global.getName().str() << ": .word " << ci->getSExtValue() << "\n";
                } else if (auto *carr = dyn_cast<ConstantDataArray>(global.getInitializer())) {
                    std::string data;
                    for (unsigned i = 0; i < carr->getNumElements(); ++i) {
                        char ch = carr->getElementAsInteger(i);
                        data += (ch ? ch : ' ');
                    }
                    out << global.getName().str() << ": .asciz \"" << data << "\"\n";
                }
            } else {
                out << global.getName().str() << ": .word 0\n";
            }
        }

        emit(".text");
        emit(".globl main");
        for (const auto& func : module->functions()) {
            if (!func.isDeclaration()) {
                emitFunction(func);
            }
        }
        out.close();
    }

    void emit(const std::string& line) {
        out << "\t" << line << "\n";
    }

    std::string freshReg() {
        return "t" + std::to_string((regCount++) % 7); // use t0-t6
    }

    std::string getReg(const Value* val) {
        if (isa<ConstantInt>(val)) {
            auto* ci = cast<ConstantInt>(val);
            std::string reg = freshReg();
            emit("li " + reg + ", " + std::to_string(ci->getSExtValue()));
            return reg;
        }
        if (isa<GlobalVariable>(val)) {
            std::string reg = freshReg();
            emit("la " + reg + ", " + val->getName().str());
            valueToReg[val] = reg;
            return reg;
        }
        if (valueToReg.count(val)) return valueToReg[val];
        auto reg = freshReg();
        valueToReg[val] = reg;
        return reg;
    }

    void emitFunction(const Function& func) {
        valueToReg.clear();
        regCount = 0;
        usedSavedRegs.clear();  // 重置保存寄存器记录
        
        // 计算保存寄存器空间（ra + s0 + 其他可能使用的s寄存器）
        calleeSaved = 4; // ra
        calleeSaved += 4; // s0
        
        // 处理函数参数分配
        unsigned argRegs = 0;
        for (const auto& arg : func.args()) {
            if (argRegs < 8) argRegs++;
            else calleeSaved += 4;  // 额外参数需要栈空间
        }
        
        // 计算局部变量空间
        localSize = 0;
        for (const auto& bb : func) {
            for (const auto& inst : bb) {
                if (isa<AllocaInst>(&inst)) {
                    localSize += 4;
                }
            }
        }
        
        // 总栈空间 = 保存寄存器空间 + 局部变量空间
        stackSize = calleeSaved + localSize;
        // 16字节对齐
        stackSize = (stackSize + 15) & ~15;
        
        // 函数Prologue
        out << func.getName().str() << ":\n";
        emit("addi sp, sp, -" + std::to_string(stackSize));
        emit("sw ra, " + std::to_string(stackSize - 4) + "(sp)");
        emit("sw s0, " + std::to_string(stackSize - 8) + "(sp)");
        emit("addi s0, sp, " + std::to_string(stackSize));
        
        // 关键修复：为Alloca指令分配保存寄存器
        auto allocateSavedReg = [&]() -> std::string {
            for (char s = '1'; s <= '9'; s++) {
                std::string reg = "s";
                reg += s;
                if (std::find(usedSavedRegs.begin(), usedSavedRegs.end(), reg) == usedSavedRegs.end()) {
                    usedSavedRegs.push_back(reg);
                    // 保存该寄存器
                    int offset = 8 + 4 * (usedSavedRegs.size() - 1);
                    emit("sw " + reg + ", " + std::to_string(stackSize - offset) + "(sp)");
                    return reg;
                }
            }
            return freshReg(); // 没有可用保存寄存器时使用临时寄存器
        };
        
        // 处理Alloca指令（使用保存寄存器）
        for (const auto& bb : func) {
            for (const auto& inst : bb) {
                if (auto* alloca = dyn_cast<AllocaInst>(&inst)) {
                    std::string reg;
                    // 关键修复：循环计数器特殊处理
                    if (alloca->getName() == "i" || alloca->getName().starts_with("loop")) {
                        reg = allocateSavedReg();
                    } else {
                        reg = freshReg();
                    }
                    valueToReg[alloca] = reg;
                    static int offset = -calleeSaved - 4;
                    offset -= 4;
                    emit("addi " + reg + ", s0, " + std::to_string(offset));
                }
            }
        }

		for (const auto& bb : func) {
            emitBasicBlock(bb);
        }
    }

    void emitBasicBlock(const BasicBlock& bb) {
        if(bb.getName().str() != "entry")
            out << bb.getName().str() << ":\n";
        for (const auto& inst : bb) {
            emitInstruction(inst);
        }
    }

    void emitInstruction(const Instruction& inst) {
        switch (inst.getOpcode()) {
            case Instruction::Add:
                emitBinaryOp(inst, "add"); break;
            case Instruction::Sub:
                emitBinaryOp(inst, "sub"); break;
            case Instruction::Mul:
                emitBinaryOp(inst, "mul"); break;
            case Instruction::SDiv:
                emitBinaryOp(inst, "div"); break;
            case Instruction::SRem:
                emitBinaryOp(inst, "rem"); break;
            case Instruction::And:
                emitBinaryOp(inst, "and"); break;
            case Instruction::Or:
                emitBinaryOp(inst, "or"); break;
            case Instruction::Xor:
                emitBinaryOp(inst, "xor"); break;
            case Instruction::Shl:
                emitBinaryOp(inst, "sll"); break;
            case Instruction::AShr:
                emitBinaryOp(inst, "sra"); break;
            case Instruction::ICmp: {
                const auto* cmp = cast<ICmpInst>(&inst);
                auto lhs = getReg(cmp->getOperand(0));
                auto rhs = getReg(cmp->getOperand(1));
                auto dst = getReg(cmp);
                switch (cmp->getPredicate()) {
                    case ICmpInst::ICMP_EQ:
                        emit("xor " + dst + ", " + lhs + ", " + rhs);
                        emit("seqz " + dst + ", " + dst);
                        break;
                    case ICmpInst::ICMP_NE:
                        emit("xor " + dst + ", " + lhs + ", " + rhs);
                        emit("snez " + dst + ", " + dst);
                        break;
                    case ICmpInst::ICMP_SLT:
                        emit("slt " + dst + ", " + lhs + ", " + rhs);
                        break;
                    case ICmpInst::ICMP_SGT:
                        emit("slt " + dst + ", " + rhs + ", " + lhs);
                        break;
                    case ICmpInst::ICMP_SLE:
                        emit("slt " + dst + ", " + rhs + ", " + lhs);
                        emit("xori " + dst + ", " + dst + ", 1");
                        break;
                    case ICmpInst::ICMP_SGE:
                        emit("slt " + dst + ", " + lhs + ", " + rhs);
                        emit("xori " + dst + ", " + dst + ", 1");
                        break;
                    default:
                        emit("# unhandled icmp predicate");
                        break;
                }
                break;
            }
            case Instruction::Alloca:
                emitAlloca(cast<AllocaInst>(inst)); break;
            case Instruction::Store:
                emitStore(cast<StoreInst>(inst)); break;
            case Instruction::Load:
                emitLoad(cast<LoadInst>(inst)); break;
            case Instruction::Ret:
                emitReturn(cast<ReturnInst>(inst)); break;
            case Instruction::Call:
                emitCall(cast<CallInst>(inst)); break;
            case Instruction::Br: {
                auto* br = cast<BranchInst>(&inst);
                if (br->isUnconditional()) {
                    emit("j " + br->getSuccessor(0)->getName().str());
                } else {
                    auto cond = getReg(br->getCondition());
                    emit("bnez " + cond + ", " + br->getSuccessor(0)->getName().str());
                    emit("j " + br->getSuccessor(1)->getName().str());
                }
                break;
            }
            default:
                emit("# unhandled: " + std::string(inst.getOpcodeName()));
                break;
        }
    }

    void emitBinaryOp(const Instruction& inst, const std::string& op) {
        auto lhs = getReg(inst.getOperand(0));
        auto rhs = getReg(inst.getOperand(1));
        auto dst = getReg(&inst);
        emit(op + " " + dst + ", " + lhs + ", " + rhs);
    }

    void emitAlloca(const AllocaInst& inst) {
        // 修改：直接计算偏移地址，不再动态调整sp
        auto reg = getReg(&inst);
        // 局部变量在栈帧中的偏移：从s0向下计算
        static int offset = -calleeSaved - 4; // 从calleeSaved区域后开始
        offset -= 4;
        emit("addi " + reg + ", s0, " + std::to_string(offset));
    }

    void emitStore(const StoreInst& inst) {
        auto val = getReg(inst.getValueOperand());
        auto ptr = getReg(inst.getPointerOperand());
        emit("sw " + val + ", 0(" + ptr + ")");
    }

    void emitLoad(const LoadInst& inst) {
        auto ptr = getReg(inst.getPointerOperand());
        auto dst = getReg(&inst);
        emit("lw " + dst + ", 0(" + ptr + ")");
    }

    void emitReturn(const ReturnInst& inst) {
        if (inst.getReturnValue()) {
            auto reg = getReg(inst.getReturnValue());
            emit("mv a0, " + reg);
        }
        
        // 恢复所有保存的寄存器
        emit("lw s0, " + std::to_string(stackSize - 8) + "(sp)");
        for (int i = 0; i < usedSavedRegs.size(); i++) {
            int offset = 12 + 4 * i;
            emit("lw " + usedSavedRegs[i] + ", " + std::to_string(stackSize - offset) + "(sp)");
        }
        emit("lw ra, " + std::to_string(stackSize - 4) + "(sp)");
        emit("addi sp, sp, " + std::to_string(stackSize));
        emit("ret");
    }

    void emitCall(const CallInst& inst) {
        for (unsigned i = 0; i < inst.arg_size(); ++i) {
            auto reg = getReg(inst.getArgOperand(i));
            emit("mv a" + std::to_string(i) + ", " + reg);
        }
        emit("call " + inst.getCalledFunction()->getName().str());
        if (!inst.getType()->isVoidTy()) {
            auto dst = getReg(&inst);
            emit("mv " + dst + ", a0");
        }
    }
};
