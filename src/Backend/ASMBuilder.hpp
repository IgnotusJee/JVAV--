#include <llvm/IR/Constants.h>
#include <llvm/IR/Instructions.h>

using namespace llvm;

class ASMBuilder {
    llvm::Module* module;
    std::ofstream out;
    int regCount = 0;
    std::unordered_map<const llvm::Value*, std::string> valueToReg;
    
    unsigned stackSize;
    unsigned calleeSaved;
    unsigned localSize;
    int nextParamOffset; // 用于追踪栈传递参数的偏移量

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
        
        // 计算局部变量空间
        localSize = 0;
        for (const auto& bb : func) {
            for (const auto& inst : bb) {
                if (isa<AllocaInst>(&inst)) {
                    localSize += 4; // 每个alloca分配4字节
                }
            }
        }
        
        // 计算栈传递参数的空间（超过8个参数的情况）
        int numParams = func.arg_size();
        int stackParamSpace = (numParams > 8) ? (numParams - 8) * 4 : 0;
        
        calleeSaved = 8; // ra和s0各占4字节
        stackSize = calleeSaved + localSize + stackParamSpace;
        stackSize = (stackSize + 15) / 16 * 16; // 16字节对齐

        nextParamOffset = stackSize - 8; // 栈传递参数的起始位置（在保存区之上）

        out << func.getName().str() << ":\n";
        
        // 函数prologue
        emit("addi sp, sp, -" + std::to_string(stackSize));
        emit("sw ra, " + std::to_string(stackSize - 4) + "(sp)");
        emit("sw s0, " + std::to_string(stackSize - 8) + "(sp)");
        emit("addi s0, sp, " + std::to_string(stackSize));
        
        // 正确获取函数参数
        int paramCount = 0;
        for (const Argument& arg : func.args()) {
            std::string reg = freshReg();
            valueToReg[&arg] = reg;
            
            if (paramCount < 8) {
                // 前8个参数从a0-a7寄存器获取
                emit("mv " + reg + ", a" + std::to_string(paramCount));
            } else {
                // 第9个及以后的参数从栈上获取
                int offset = nextParamOffset + (paramCount - 8) * 4;
                emit("lw " + reg + ", " + std::to_string(offset) + "(s0)");
            }
            paramCount++;
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
        static int offset = -calleeSaved - 4;
        offset -= 4;
        auto reg = getReg(&inst);
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
        emit("lw ra, " + std::to_string(stackSize - 4) + "(sp)");
        emit("lw s0, " + std::to_string(stackSize - 8) + "(sp)");
        emit("addi sp, sp, " + std::to_string(stackSize));
        emit("ret");
    }

    void emitCall(const CallInst& inst) {
        // 保存可能被破坏的临时寄存器（简单实现）
        emit("# Save temporary registers");
        int savedRegs = 0;
        std::vector<std::string> saved;
        for (int i = 0; i < 7; i++) {
            std::string reg = "t" + std::to_string(i);
            emit("sw " + reg + ", " + std::to_string(i * 4) + "(sp)");
            saved.push_back(reg);
            savedRegs++;
        }
        
        // 传递参数
        for (unsigned i = 0; i < inst.arg_size(); ++i) {
            auto reg = getReg(inst.getArgOperand(i));
            emit("mv a" + std::to_string(i) + ", " + reg);
        }
        
        // 调用函数
        emit("call " + inst.getCalledFunction()->getName().str());
        
        // 恢复临时寄存器
        emit("# Restore temporary registers");
        for (int i = savedRegs - 1; i >= 0; i--) {
            emit("lw " + saved[i] + ", " + std::to_string(i * 4) + "(sp)");
        }
        
        // 处理返回值
        if (!inst.getType()->isVoidTy()) {
            auto dst = getReg(&inst);
            emit("mv " + dst + ", a0");
        }
    }
};
