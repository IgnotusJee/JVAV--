#include <llvm/IR/Constants.h>
#include <llvm/IR/Instructions.h>
#include <unordered_set>

using namespace llvm;

class ASMBuilder {
    Module* module;
    std::ofstream out;
    int regCount = 0;
    std::unordered_map<const Value*, std::string> valueToReg;
    std::vector<std::string> usedSavedRegs; 
    Function* currentFunction = nullptr;
    
    // 栈帧信息
    unsigned stackSize = 0;   
    unsigned calleeSaved = 0; 
    unsigned localSize = 0;   
    unsigned paramSpace = 0;

    // 寄存器使用统计
    std::unordered_map<const Value*, int> useCount;

public:
    ASMBuilder(Module* m) : module(m) {}

    void generate(const std::string& outputFile) {
        out.open(outputFile);
        if (!out.is_open()) {
            errs() << "Failed to open output file: " << outputFile << "\n";
            return;
        }

        // 全局数据段
        emit(".data");
        for (const auto& global : module->globals()) {
            if (global.hasInitializer()) {
                if (auto* ci = dyn_cast<ConstantInt>(global.getInitializer())) {
                    emit(global.getName().str() + ": .word " + std::to_string(ci->getSExtValue()));
                } else if (auto* carr = dyn_cast<ConstantDataArray>(global.getInitializer())) {
                    std::string data;
                    for (unsigned i = 0; i < carr->getNumElements(); ++i) {
                        char ch = carr->getElementAsInteger(i);
                        data += (ch ? ch : ' ');
                    }
                    emit(global.getName().str() + ": .asciz \"" + data + "\"");
                }
            } else {
                emit(global.getName().str() + ": .word 0");
            }
        }

        // 代码段
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

    std::string freshReg(const std::string& type = "temp") {
        if (type == "saved") {
            // 分配保存寄存器 (s1-s11)
            if (usedSavedRegs.size() < 11) {
                std::string reg = "s" + std::to_string(usedSavedRegs.size() + 1);
                usedSavedRegs.push_back(reg);
                return reg;
            }
        }
        // 默认分配临时寄存器 (t0-t6)
        std::string reg = "t" + std::to_string(regCount % 7);
        regCount++;
        return reg;
    }

    std::string getReg(const Value* val) {
        // 常量值特殊处理
        if (isa<ConstantInt>(val)) {
            auto* ci = cast<ConstantInt>(val);
            std::string reg = freshReg();
            emit("li " + reg + ", " + std::to_string(ci->getSExtValue()));
            return reg;
        }
        
        // 全局变量特殊处理
        if (isa<GlobalVariable>(val)) {
            std::string reg = freshReg();
            emit("la " + reg + ", " + val->getName().str());
            return reg;
        }
        
        // 已分配寄存器直接返回
        if (valueToReg.count(val)) return valueToReg[val];
        
        // 分配新寄存器
        std::string reg = freshReg();
        valueToReg[val] = reg;
        return reg;
    }

    void emitFunction(const Function& func) {
        currentFunction = &const_cast<Function&>(func);
        valueToReg.clear();
        regCount = 0;
        usedSavedRegs.clear();
        calleeSaved = 0;
        localSize = 0;
        paramSpace = 0;
        
        // 1. 准备栈帧
        calleeSaved = 4;      // ra
        calleeSaved += 4;     // s0
        
        // 处理函数参数
        unsigned argCount = func.arg_size();
        if (argCount > 8) {
            paramSpace = 4 * (argCount - 8); // a0-a7 外的参数需要栈空间
        }
        
        // 分析局部变量
        for (const auto& bb : func) {
            for (const auto& inst : bb) {
                if (isa<AllocaInst>(&inst)) {
                    localSize += 4;
                }
            }
        }
        
        // 总栈空间 = 保存寄存器空间 + 参数空间 + 局部变量空间
        stackSize = calleeSaved + paramSpace + localSize;
        // 16字节对齐
        stackSize = (stackSize + 15) & ~15;
        
        // 函数开始
        out << func.getName().str() << ":\n";
        emit("addi sp, sp, -" + std::to_string(stackSize));
        emit("sw ra, " + std::to_string(stackSize - 4) + "(sp)");
        emit("sw s0, " + std::to_string(stackSize - 8) + "(sp)");
        emit("addi s0, sp, " + std::to_string(stackSize));
        
        // 保存额外保存寄存器 (s1-s11)
        for (int i = 0; i < usedSavedRegs.size(); i++) {
            int offset = 8 + 4 * (i + 1);
            emit("sw " + usedSavedRegs[i] + ", " + std::to_string(stackSize - offset) + "(sp)");
        }
        
        // 2. 处理局部变量 (alloca)
        int localOffset = -calleeSaved; // 起始偏移位置
        for (const auto& bb : func) {
            for (const auto& inst : bb) {
                if (auto* alloca = dyn_cast<AllocaInst>(&inst)) {
                    // 优先使用保存寄存器存储地址
                    std::string reg = freshReg("saved");
                    
                    // 设置局部变量偏移
                    localOffset -= 4;
                    valueToReg[alloca] = reg;
                    emit("addi " + reg + ", s0, " + std::to_string(localOffset));
                }
            }
        }
        
        // 3. 处理函数参数
        unsigned argIndex = 0;
        for (const auto& arg : func.args()) {
            if (argIndex < 8) {
                // 使用a0-a7寄存器
                valueToReg[&arg] = "a" + std::to_string(argIndex);
            } else {
                // 超出寄存器数量的参数在栈上
                std::string reg = freshReg();
                int offset = stackSize - (8 + 4 * (argIndex - 8));
                emit("lw " + reg + ", " + std::to_string(offset) + "(s0)");
                valueToReg[&arg] = reg;
            }
            argIndex++;
        }
        
        // 4. 生成基本块指令
        for (const auto& bb : func) {
            emitBasicBlock(bb);
        }
        
        currentFunction = nullptr;
    }

    void emitBasicBlock(const BasicBlock& bb) {
        if (bb.getName() != "entry") {
            out << bb.getName().str() << ":\n";
        }
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
                // 已在函数头部处理
                break;
            case Instruction::Store: {
                auto val = getReg(inst.getOperand(0));
                auto ptr = getReg(inst.getOperand(1));
                emit("sw " + val + ", 0(" + ptr + ")");
                break;
            }
            case Instruction::Load: {
                auto ptr = getReg(inst.getOperand(0));
                auto dst = getReg(&inst);
                emit("lw " + dst + ", 0(" + ptr + ")");
                break;
            }
            case Instruction::Ret:
                emitReturn(cast<ReturnInst>(inst));
                break;
            case Instruction::Call:
                emitCall(cast<CallInst>(inst));
                break;
            case Instruction::Br: {
                auto* br = cast<BranchInst>(&inst);
                if (br->isUnconditional()) {
                    emit("j " + br->getSuccessor(0)->getName().str());
                } else {
                    auto cond = getReg(br->getCondition());
                    auto trueLabel = br->getSuccessor(0)->getName().str();
                    auto falseLabel = br->getSuccessor(1)->getName().str();
                    emit("bnez " + cond + ", " + trueLabel);
                    emit("j " + falseLabel);
                }
                break;
            }
            case Instruction::GetElementPtr: {
                auto ptr = getReg(inst.getOperand(0));
                auto idx = getReg(inst.getOperand(1));
                auto dst = getReg(&inst);
                emit("slli " + idx + ", " + idx + ", 2"); // 乘以4（假设4字节元素）
                emit("add " + dst + ", " + ptr + ", " + idx);
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
        
        if (op == "rem") {
            // RISC-V 没有直接取模指令
            emit("rem " + dst + ", " + lhs + ", " + rhs);
        } else {
            emit(op + " " + dst + ", " + lhs + ", " + rhs);
        }
    }

    void emitCall(const CallInst& inst) {
        // 设置函数参数
        for (unsigned i = 0; i < inst.arg_size(); ++i) {
            auto reg = getReg(inst.getArgOperand(i));
            if (i < 8) {
                emit("mv a" + std::to_string(i) + ", " + reg);
            } else {
                // 多余的参数需要压栈
                int offset = stackSize - (8 + 4 * i);
                emit("sw " + reg + ", " + std::to_string(offset) + "(sp)");
            }
        }
        
        // 调用函数
        emit("call " + inst.getCalledFunction()->getName().str());
        
        // 处理返回值
        if (!inst.getType()->isVoidTy()) {
            auto dst = getReg(&inst);
            emit("mv " + dst + ", a0");
        }
    }

    void emitReturn(const ReturnInst& inst) {
        // 设置返回值
        if (inst.getReturnValue()) {
            auto reg = getReg(inst.getReturnValue());
            emit("mv a0, " + reg);
        }
        
        // 恢复保存寄存器 (逆序恢复)
        for (int i = usedSavedRegs.size() - 1; i >= 0; i--) {
            int offset = stackSize - (12 + 4 * i);
            emit("lw " + usedSavedRegs[i] + ", " + std::to_string(offset) + "(sp)");
        }
        
        // 恢复框架指针和返回地址
        emit("lw s0, " + std::to_string(stackSize - 8) + "(sp)");
        emit("lw ra, " + std::to_string(stackSize - 4) + "(sp)");
        
        // 恢复栈指针并返回
        emit("addi sp, sp, " + std::to_string(stackSize));
        emit("ret");
    }
};
