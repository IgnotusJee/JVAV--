#include "AST/ASTCollection.h"
#include "Tools/error.hpp"
#include "Frontend/SymbolTable.hpp"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Constants.h>
#include <llvm/ADT/APInt.h>
#include <llvm/IR/ValueSymbolTable.h>
#include <unordered_map>
#include <memory>
#include <cctype>
#include <stack>
#include <numeric>

using namespace llvm;

std::string join(const std::vector<std::string>& vec, const std::string &comma) {
    if (vec.empty()) return "";
    return std::accumulate(std::next(vec.begin()), vec.end(), vec[0],
        [&comma](const std::string& a, const std::string& b) {
            return a + comma + b;
        });
}

std::vector<std::string> split(const std::string& str, const char &comma) {
    std::vector<std::string> tokens;
    auto start = str.begin();

    while (start != str.end()) {
        auto end = std::find(start, str.end(), comma);
        tokens.push_back(std::string(start, end));
        start = end == str.end() ? end : end + 1;
    }

    return tokens;
}

class IRGenerator : public ASTVisitor {
    // LLVM核心组件
    std::unique_ptr<LLVMContext> context;
    std::unique_ptr<Module> module;
    IRBuilder<>* builder;

    // 符号表
    SymbolTable symbolTable;

    // 控制流状态
    struct ControlFlow {
        BasicBlock* loopStart = nullptr;
        BasicBlock* loopEnd = nullptr;
        BasicBlock* loopContinue = nullptr;
    };

    std::stack<ControlFlow> controlStack;

    // 当前上下文
    Function* currentFunction = nullptr;
    StructType* currentClass = nullptr;
    Value* thisPtr = nullptr;

    // 当前返回值
    Value* lastValue = nullptr;

	struct AccessContext {
        bool isLValue = false;   // 是否在左值上下文（需要地址）
        bool isLoadAllowed = true; // 是否允许加载值
    };

    std::vector<AccessContext> contextStack;  // 上下文堆栈

public:
    explicit IRGenerator(const std::string& moduleName = "jvav_module")
        : context(std::make_unique<LLVMContext>()),
          module(std::make_unique<Module>(moduleName, *context)),
          builder(new IRBuilder<>(*context)) {}

    ~IRGenerator() override {
        delete builder;
    }

	// 进入新的访问上下文
    void pushContext(bool isLValue = false, bool isLoadAllowed = true) {
        contextStack.push_back({isLValue, isLoadAllowed});
    }

    // 退出当前访问上下文
    void popContext() {
        if (!contextStack.empty()) {
            contextStack.pop_back();
        }
    }

    // 获取当前上下文
    AccessContext currentContext() const {
        if (!contextStack.empty()) {
            return contextStack.back();
        }
        return {false, true};  // 默认上下文
    }

    // 在左值上下文中访问表达式（获取地址）
    void accessLValue(ASTNode* node) {
        pushContext(true, false);  // 左值上下文，不允许加载
        node->accept((ASTVisitor &) *this);
        popContext();
    }

    // 在右值上下文中访问表达式（获取值）
    void accessRValue(ASTNode* node) {
        pushContext(false, true);  // 右值上下文，允许加载
        node->accept((ASTVisitor &) *this);
        popContext();
    }

    // 访问者接口实现
    void visit(rootNode *it) override {
        symbolTable.push(); // 全局作用域
        for (auto& decl : it->Def) {
            decl->accept((ASTVisitor &) *this);
        }
        if (!module->getFunction("main")) {
            auto* mainType = llvm::FunctionType::get(
                llvm::Type::getInt32Ty(*context), false);
            llvm::Function::Create(mainType,
                llvm::GlobalValue::ExternalLinkage, "main", module.get());
        }
        symbolTable.pop();
    }

    void visit(funcDefNode *it) override {
        llvm::Type* retType = getType(it->typeName);
        std::vector<llvm::Type*> paramTypes;

        for (auto& param : it->param) {
            paramTypes.push_back(getType(param->typeName));
        }

        // 如果是成员函数，添加this指针
        if (currentClass) {
            paramTypes.insert(paramTypes.begin(),
                llvm::PointerType::get(currentClass, 0));
        }

        auto* funcType = llvm::FunctionType::get(retType, paramTypes, false);
        auto* func = llvm::Function::Create(funcType,
            llvm::GlobalValue::ExternalLinkage,
            currentClass ? currentClass->getName().str() + "." + it->name : it->name,
            module.get());

        currentFunction = func;
        auto* entryBB = llvm::BasicBlock::Create(*context, "entry", func);
        builder->SetInsertPoint(entryBB);

        // 设置参数名
        symbolTable.push(); // 函数作用域
        auto argIt = func->arg_begin();

        if (currentClass) {
            // 第一个参数是this指针
            thisPtr = argIt++;
            thisPtr->setName("this");
            symbolTable.addValue("this", thisPtr);
        }

        for (auto& param : it->param) {
            auto* arg = argIt++;
            arg->setName(param->name);

            auto* alloca = builder->CreateAlloca(
                getType(param->typeName), nullptr, param->name);
            builder->CreateStore(arg, alloca);
            symbolTable.addValue(param->name, alloca);
        }

        it->suite->accept((ASTVisitor &) *this);

        // 添加隐式返回（如果函数体没有以返回结束）
        if (!entryBB->getTerminator()) {
            if (retType->isVoidTy()) {
                builder->CreateRetVoid();
            } else {
                builder->CreateRet(llvm::Constant::getNullValue(retType));
            }
        }

        symbolTable.pop(); // 离开函数作用域
        currentFunction = nullptr;
        thisPtr = nullptr;
    }

    void visit(varDefStmtNode *it) override {
        llvm::Type* varType = getType(it->typeName);

        for (auto& var : it->var) {
            auto* alloca = builder->CreateAlloca(
                varType, nullptr, var->name);

            if (var->init) {
                var->init->accept((ASTVisitor &) *this);
                auto* initVal = lastValue;

                if (varType != initVal->getType()) {
                    initVal = createTypeCast(initVal, varType);
                }

                builder->CreateStore(initVal, alloca);
            } else {
                builder->CreateStore(
                    llvm::Constant::getNullValue(varType), alloca);
            }

            symbolTable.addValue(var->name, alloca);
        }
    }

    void visit(assignExprNode *it) override {
        // 处理右值表达式
        it->rhs->accept((ASTVisitor&) *this);
        Value* rvalue = lastValue;

        // 处理左值表达式
        it->lhs->accept((ASTVisitor&) *this);
        Value* lvalue = lastValue;

        // 存储值
        builder->CreateStore(rvalue, lvalue);

        // 赋值表达式返回值是被赋的值
        lastValue = rvalue;
    }

    void visit(returnStmtNode *it) override {
        if (it->ret) {
            it->ret->accept((ASTVisitor&) *this);

			Value* retVal = lastValue;
			// 类型检查
            Type* expectedType = currentFunction->getReturnType();
            if (retVal->getType() != expectedType) {
                retVal = createTypeCast(retVal, expectedType);
            }

            builder->CreateRet(lastValue);
        } else {
            builder->CreateRetVoid();
        }
    }

    void visit(varNode *it) override {
	    // 查找变量
	    llvm::Value* varPtr = symbolTable.findValue(it->name);

	    // 类成员处理
	    if (!varPtr && thisPtr && currentClass) {
	        int index = getMemberIndex(it->name);
	        if (index >= 0) {
	            // 使用结构体指针和索引获取成员的地址
	            varPtr = builder->CreateStructGEP(
	                currentClass,
	                thisPtr,
	                index,
	                it->name + ".addr"
	            );
	        }
	    }

	    if (!varPtr) {
	        throw std::runtime_error("Undefined variable: " + it->name);
	    }

		 // 验证变量指针类型
	    if (!varPtr->getType()->isPointerTy()) {
	        throw std::runtime_error("Variable " + it->name + " is not a pointer type");
	    }

	    // 获取指针指向的元素类型
	    PointerType* ptrType = cast<PointerType>(varPtr->getType());
	    Type* elementType = getPointedType(ptrType);

	    // 获取当前上下文
	    auto context = currentContext();

	    // 在左值上下文或禁用加载时返回地址
	    if (context.isLValue || !context.isLoadAllowed) {
	        lastValue = varPtr;
	        return;
	    }

	    // 否则加载值（右值上下文）
	    lastValue = builder->CreateLoad(elementType, varPtr, it->name + ".val");
	}

    void visit(thisExprNode *it) override {
        if (!thisPtr) {
            throw std::runtime_error("'this' used outside class context");
        }
        lastValue = thisPtr;
    }

    void visit(paramNode *it) override {
        // 参数处理已在visit(funcDefNode)中完成
    }

    void visit(classDefNode *it) override {
        // 保存当前类上下文
        auto* prevClass = currentClass;

        // 创建类类型
        currentClass = StructType::create(*context, it->name);
        symbolTable.addType(it->name, currentClass);

        // 收集成员变量类型
        std::vector<Type*> memberTypes;
        std::vector<std::string> memberNames;

        // 处理成员变量
        for (auto& varDef : it->varDef) {
            Type* memberType = getType(varDef->typeName);
            for (auto& var : varDef->var) {
                memberTypes.push_back(memberType);
                memberNames.push_back(var->name);
            }
        }

        // 设置类结构体
        currentClass->setBody(memberTypes);

		MDString* memberNamesMD = MDString::get(*context, join(memberNames, ","));
		MDNode* classMetadata = MDNode::get(*context, memberNamesMD);

        // 添加类元数据（成员名称映射）
		module->getOrInsertNamedMetadata("class." + it->name)->addOperand(classMetadata);

        // 处理成员函数
        for (auto& func : it->funcDef) {
            func->accept((ASTVisitor&) *this);
        }

        // 恢复类上下文
        currentClass = prevClass;
    }

    void visit(blockStmtNode *it) override {
        symbolTable.push();  // 进入新作用域

        for (auto& stmt : it->stmt) {
            stmt->accept((ASTVisitor&) *this);

            // 提前返回检测
            if (builder->GetInsertBlock()->getTerminator()) break;
        }

        symbolTable.pop();  // 离开作用域
    }

    void visit(branchStmtNode *it) override {
        // 创建基本块
        BasicBlock* mergeBB = BasicBlock::Create(*context, "if.merge");
        std::vector<BasicBlock*> thenBlocks;
        std::vector<BasicBlock*> condBlocks;

        // 条件链处理
        for (size_t i = 0; i < it->cond.size(); i++) {
            // 条件块
            condBlocks.push_back(BasicBlock::Create(
                *context, "if.cond." + std::to_string(i), currentFunction));

            // then块
            thenBlocks.push_back(BasicBlock::Create(
                *context, "if.then." + std::to_string(i)));
        }

		int elseBranch = it->Stmt.size() - it->cond.size();
		if(elseBranch > 1)
			throw std::runtime_error("Too much else branch");

        // else块
        BasicBlock* elseBB = elseBranch ?
            BasicBlock::Create(*context, "if.else") : mergeBB;

        // 初始跳转
        builder->CreateBr(condBlocks[0]);

        // 处理各分支
        for (size_t i = 0; i < it->cond.size(); i++) {
            // 条件块
            builder->SetInsertPoint(condBlocks[i]);
            it->cond[i]->accept((ASTVisitor&) *this);
            Value* cond = lastValue;

            BasicBlock* nextCond = (i < it->cond.size() - 1) ?
                condBlocks[i + 1] : elseBB;

            builder->CreateCondBr(cond, thenBlocks[i], nextCond);

            // then块
            builder->SetInsertPoint(thenBlocks[i]);
            it->Stmt[i]->accept((ASTVisitor&) *this);
            if (!builder->GetInsertBlock()->getTerminator()) {
                builder->CreateBr(mergeBB);
            }
        }

        // else块
        if (elseBranch) {
            builder->SetInsertPoint(elseBB);
            it->Stmt[it->cond.size()]->accept((ASTVisitor&) *this);
            if (!builder->GetInsertBlock()->getTerminator()) {
                builder->CreateBr(mergeBB);
            }
        }

        // 合并块
        builder->SetInsertPoint(mergeBB);
    }

    void visit(exprStmtNode *it) override {
        for (auto& expr : it->expr) {
            expr->accept((ASTVisitor&) *this);
        }
    }

    void visit(whileStmtNode *it) override {
        // 创建基本块
        BasicBlock* condBB = BasicBlock::Create(
            *context, "while.cond", currentFunction);
        BasicBlock* bodyBB = BasicBlock::Create(*context, "while.body");
        BasicBlock* endBB = BasicBlock::Create(*context, "while.end");

        // 保存控制流状态
        controlStack.push({condBB, endBB, condBB});

        // 初始跳转
        builder->CreateBr(condBB);

        // 条件块
        builder->SetInsertPoint(condBB);
        it->cond->accept((ASTVisitor&) *this);
        Value* cond = lastValue;
        builder->CreateCondBr(cond, bodyBB, endBB);

        // 循环体
        builder->SetInsertPoint(bodyBB);
        it->stmt->accept((ASTVisitor&) *this);

        // 循环继续
        if (!builder->GetInsertBlock()->getTerminator()) {
            builder->CreateBr(condBB);
        }

        // 结束块
        builder->SetInsertPoint(endBB);

        controlStack.pop();
    }

    void visit(forDefStmtNode *it) override {
        symbolTable.push();  // for循环作用域

        // 初始化处理
        if (it->varDef) {
            it->varDef->accept((ASTVisitor&) *this);
        }

        // 创建基本块
        BasicBlock* condBB = BasicBlock::Create(
            *context, "for.cond", currentFunction);
        BasicBlock* bodyBB = BasicBlock::Create(*context, "for.body");
        BasicBlock* stepBB = BasicBlock::Create(*context, "for.step");
        BasicBlock* endBB = BasicBlock::Create(*context, "for.end");

        // 初始跳转
        builder->CreateBr(condBB);

        // 保存控制流状态
        controlStack.push({condBB, endBB, stepBB});

        // 条件块
        builder->SetInsertPoint(condBB);
        if (it->cond) {
            it->cond->accept((ASTVisitor&) *this);
            builder->CreateCondBr(lastValue, bodyBB, endBB);
        } else {
            builder->CreateBr(bodyBB);
        }

        // 循环体
        builder->SetInsertPoint(bodyBB);
        it->stmt->accept((ASTVisitor&) *this);

        // 循环继续
        if (!builder->GetInsertBlock()->getTerminator()) {
            builder->CreateBr(stepBB);
        }

        // 步进块
        builder->SetInsertPoint(stepBB);
        if (it->step) {
            it->step->accept((ASTVisitor&) *this);
        }
        builder->CreateBr(condBB);

        // 结束块
        builder->SetInsertPoint(endBB);

        controlStack.pop();
        symbolTable.pop();  // 离开for作用域
    }

    void visit(forExprStmtNode *it) override {
        // 类似forDefStmtNode，但初始化是表达式
        symbolTable.push();

        // 表达式初始化
        if (it->init) {
            it->init->accept((ASTVisitor&) *this);
        }

        // 创建基本块
        BasicBlock* condBB = BasicBlock::Create(
            *context, "for.cond", currentFunction);
        BasicBlock* bodyBB = BasicBlock::Create(*context, "for.body");
        BasicBlock* stepBB = BasicBlock::Create(*context, "for.step");
        BasicBlock* endBB = BasicBlock::Create(*context, "for.end");

        // 初始跳转
        builder->CreateBr(condBB);

        // 保存控制流状态
        controlStack.push({condBB, endBB, stepBB});

        // 条件块
        builder->SetInsertPoint(condBB);
        if (it->cond) {
            it->cond->accept((ASTVisitor&) *this);
            builder->CreateCondBr(lastValue, bodyBB, endBB);
        } else {
            builder->CreateBr(bodyBB);
        }

        // 循环体
        builder->SetInsertPoint(bodyBB);
        it->stmt->accept((ASTVisitor&) *this);

        // 循环继续
        if (!builder->GetInsertBlock()->getTerminator()) {
            builder->CreateBr(stepBB);
        }

        // 步进块
        builder->SetInsertPoint(stepBB);
        if (it->step) {
            it->step->accept((ASTVisitor&) *this);
        }
        builder->CreateBr(condBB);

        // 结束块
        builder->SetInsertPoint(endBB);

        controlStack.pop();
        symbolTable.pop();  // 离开for作用域
    }

    void visit(breakStmtNode *it) override {
        if (controlStack.empty()) {
            throw std::runtime_error("break outside loop");
        }
        builder->CreateBr(controlStack.top().loopEnd);
    }

    void visit(continueStmtNode *it) override {
        if (controlStack.empty()) {
            throw std::runtime_error("continue outside loop");
        }
        builder->CreateBr(controlStack.top().loopContinue);
    }

    void visit(memberVarExprNode *it) override {
        // 获取对象指针
        it->expr->accept((ASTVisitor&) *this);
        Value* objPtr = lastValue;

        // 成员变量访问
        int index = getMemberIndex(it->name);
        if (index < 0) {
            throw std::runtime_error("Member not found: " + it->name);
        }

        Value* memberPtr = builder->CreateStructGEP(
            getPointedType(objPtr->getType()), objPtr, index);

        // 作为左值处理，返回指针
        lastValue = memberPtr;
    }

	/**
	 * functionExpr 和 functionDef 相关的llvm ir函数调用我实在不知道怎么搞了
	 *
	 */

//    void visit(memberFuncExprNode *it) override {
//        // 获取对象指针
//        it->expr->accept((ASTVisitor&) *this);
//        Value* objPtr = lastValue;
//
//        // 成员函数调用
//        std::string funcName = std::string(getPointedType(objPtr->getType())->getStructName()) + "." + it->func->name;
//
//        Value* funcVal = symbolTable.find(funcName);
//        if (!funcVal) {
//            throw std::runtime_error("Member function not found: " + funcName);
//        }
//
//        // 准备参数（this指针+函数参数）
//        std::vector<Value*> args;
//        args.push_back(objPtr);  // this指针
//
//        for (auto& arg : it->func->args) {
//            arg->accept((ASTVisitor&) *this);
//            args.push_back(lastValue);
//        }
//
//        // 调用函数
//        FunctionType* funcType = cast<FunctionType>(
//            cast<PointerType>(funcVal->getType())->getElementType());
//
//        lastValue = builder->CreateCall(funcType, funcVal, args);
//    }

    void visit(arrayExprNode *it) override {
        // 获取数组指针
        it->name->accept((ASTVisitor&) *this);
        Value* arrayPtr = lastValue;

        // 获取索引
        it->index->accept((ASTVisitor&) *this);
        Value* index = lastValue;

        // 计算元素地址
        Type* arrayType = getPointedType(arrayPtr->getType());
        Value* elemPtr = builder->CreateInBoundsGEP(
            arrayType, arrayPtr, {builder->getInt32(0), index});

        lastValue = elemPtr;
    }

//    void visit(newExprNode *it) override {
//        // 基本类型处理
//        Type* baseType = getBasicType(it->typeName);
//
//        if (it->dim) {
//            // 数组分配
//            it->size->accept((ASTVisitor&) *this);
//            Value* size = lastValue;
//
//            // 创建malloc调用
//            Function* mallocFunc = getMallocFunction();
//            Value* arraySize = builder->CreateMul(
//                size, ConstantInt::get(size->getType(), getTypeSize(baseType)));
//
//            Value* arrayPtr = builder->CreateCall(mallocFunc, {arraySize});
//
//            // 类型转换
//            arrayPtr = builder->CreateBitCast(
//                arrayPtr, PointerType::get(baseType, 0));
//
//            lastValue = arrayPtr;
//        } else {
//            // 对象分配
//            Function* mallocFunc = getMallocFunction();
//            Value* size = ConstantInt::get(
//                Type::getInt32Ty(*context), getTypeSize(baseType));
//
//            Value* objPtr = builder->CreateCall(mallocFunc, {size});
//
//            // 类型转换
//            objPtr = builder->CreateBitCast(
//                objPtr, PointerType::get(baseType, 0));
//
//            // 调用构造函数
//            if (Function* ctor = module->getFunction(
//                getStructNameFromType(baseType) + "_ctor")) {
//
//                builder->CreateCall(ctor, {objPtr});
//            }
//
//            lastValue = objPtr;
//        }
//    }

    void visit(prefixUnaryExprNode *it) override {
        it->expr->accept((ASTVisitor&) *this);
        Value* operand = lastValue;

        switch (it->opCode) {
            case prefixUnaryExprNode::prefixOpType::Inc: {
                Value* newVal = builder->CreateAdd(
                    operand, ConstantInt::get(operand->getType(), 1));
                storeToLValue(it->expr, newVal);
                lastValue = newVal;
                break;
            }
            case prefixUnaryExprNode::prefixOpType::Dec: {
                Value* newVal = builder->CreateSub(
                    operand, ConstantInt::get(operand->getType(), 1));
                storeToLValue(it->expr, newVal);
                lastValue = newVal;
                break;
            }
            case prefixUnaryExprNode::prefixOpType::Not:
                lastValue = builder->CreateNot(operand);
                break;
            case prefixUnaryExprNode::prefixOpType::Inv:
                lastValue = builder->CreateNeg(operand);
                break;
            case prefixUnaryExprNode::prefixOpType::Sub:
                lastValue = builder->CreateNeg(operand);
                break;
            default:
                throw std::runtime_error("Unsupported prefix operator");
        }
    }

    void visit(suffixUnaryExprNode *it) override {
        it->expr->accept((ASTVisitor&) *this);
        Value* original = lastValue;

        switch (it->opCode) {
            case suffixUnaryExprNode::suffixOpType::Inc: {
                Value* newVal = builder->CreateAdd(
                    original, ConstantInt::get(original->getType(), 1));
                storeToLValue(it->expr, newVal);
                lastValue = original;  // 后缀返回原始值
                break;
            }
            case suffixUnaryExprNode::suffixOpType::Dec: {
                Value* newVal = builder->CreateSub(
                    original, ConstantInt::get(original->getType(), 1));
                storeToLValue(it->expr, newVal);
                lastValue = original;
                break;
            }
            default:
                throw std::runtime_error("Unsupported suffix operator");
        }
    }

    void visit(binaryExprNode *it) override {
    // 访问左操作数
        it->lhs->accept((ASTVisitor&) *this);
        Value* lhs = lastValue;

        // 访问右操作数
        it->rhs->accept((ASTVisitor&) *this);
        Value* rhs = lastValue;

        // 类型提升：确保左右操作数类型一致
        if (lhs->getType() != rhs->getType()) {
            if (lhs->getType()->isIntegerTy() && rhs->getType()->isIntegerTy()) {
                // 整数提升：将较小的整数类型提升到较大的类型
                IntegerType* lhsInt = cast<IntegerType>(lhs->getType());
                IntegerType* rhsInt = cast<IntegerType>(rhs->getType());
                if (lhsInt->getBitWidth() > rhsInt->getBitWidth()) {
                    rhs = builder->CreateIntCast(rhs, lhs->getType(), true, "cast");
                } else {
                    lhs = builder->CreateIntCast(lhs, rhs->getType(), true, "cast");
                }
            } else {
                // 其他类型转换逻辑（例如整型转浮点等）
                // 这里简化为错误
                throw std::runtime_error("Type mismatch in binary operator");
            }
        }

        // 生成操作
        switch (it->opCode) {
            case binaryExprNode::binaryOpType::Add:
                lastValue = builder->CreateAdd(lhs, rhs, "addtmp");
                break;
            case binaryExprNode::binaryOpType::Sub:
                lastValue = builder->CreateSub(lhs, rhs, "subtmp");
                break;
            case binaryExprNode::binaryOpType::Mul:
                lastValue = builder->CreateMul(lhs, rhs, "multmp");
                break;
            case binaryExprNode::binaryOpType::Div:
                lastValue = builder->CreateSDiv(lhs, rhs, "divtmp");
                break;
            case binaryExprNode::binaryOpType::Mod:
                lastValue = builder->CreateSRem(lhs, rhs, "modtmp");
                break;
            case binaryExprNode::binaryOpType::Eq:
                lastValue = builder->CreateICmpEQ(lhs, rhs, "cmptmp");
                break;
            case binaryExprNode::binaryOpType::Neq:
                lastValue = builder->CreateICmpNE(lhs, rhs, "cmptmp");
                break;
            case binaryExprNode::binaryOpType::Le:
                lastValue = builder->CreateICmpSLT(lhs, rhs, "cmptmp");
                break;
            case binaryExprNode::binaryOpType::Ge:
                lastValue = builder->CreateICmpSGT(lhs, rhs, "cmptmp");
                break;
            case binaryExprNode::binaryOpType::Leq:
                lastValue = builder->CreateICmpSLE(lhs, rhs, "cmptmp");
                break;
            case binaryExprNode::binaryOpType::Geq:
                lastValue = builder->CreateICmpSGE(lhs, rhs, "cmptmp");
                break;
            case binaryExprNode::binaryOpType::And:
                lastValue = builder->CreateAnd(lhs, rhs, "andtmp");
                break;
            case binaryExprNode::binaryOpType::Or:
                lastValue = builder->CreateOr(lhs, rhs, "ortmp");
                break;
            case binaryExprNode::binaryOpType::Bitand:
                lastValue = builder->CreateAnd(lhs, rhs, "bitandtmp");
                break;
            case binaryExprNode::binaryOpType::Bitor:
                lastValue = builder->CreateOr(lhs, rhs, "bitortmp");
                break;
            case binaryExprNode::binaryOpType::Bitxor:
                lastValue = builder->CreateXor(lhs, rhs, "bitxortmp");
                break;
            case binaryExprNode::binaryOpType::Lshift:
                lastValue = builder->CreateShl(lhs, rhs, "shltmp");
                break;
            case binaryExprNode::binaryOpType::Rshift:
                lastValue = builder->CreateAShr(lhs, rhs, "ashrtmp"); // 算术右移
                break;
            default:
                throw std::runtime_error("Unsupported binary operator");
        }
    }

    void visit(ternaryExprNode *it) override {
        // 条件部分
        it->cond->accept((ASTVisitor&) *this);
        Value* cond = lastValue;

        // 创建基本块
        Function* func = builder->GetInsertBlock()->getParent();
        BasicBlock* thenBB = BasicBlock::Create(*context, "ternary.then", func);
        BasicBlock* elseBB = BasicBlock::Create(*context, "ternary.else");
        BasicBlock* mergeBB = BasicBlock::Create(*context, "ternary.merge");

        builder->CreateCondBr(cond, thenBB, elseBB);

        // then部分
        builder->SetInsertPoint(thenBB);
        it->thenExpr->accept((ASTVisitor&) *this);
        Value* thenVal = lastValue;
        builder->CreateBr(mergeBB);
        thenBB = builder->GetInsertBlock(); // 更新thenBB，防止后面被修改

        // else部分
        builder->SetInsertPoint(elseBB);
        it->elseExpr->accept((ASTVisitor&) *this);
        Value* elseVal = lastValue;
        builder->CreateBr(mergeBB);
        elseBB = builder->GetInsertBlock();

        // 合并
        builder->SetInsertPoint(mergeBB);

        // 创建PHI节点
        Type* resultType = thenVal->getType();
        PHINode* phi = builder->CreatePHI(resultType, 2, "phi");
        phi->addIncoming(thenVal, thenBB);
        phi->addIncoming(elseVal, elseBB);
        lastValue = phi;
    }

    void visit(boolNode *it) override {
        lastValue = ConstantInt::get(Type::getInt1Ty(*context), it->val ? 1 : 0);
    }

    void visit(numberNode *it) override {
        // 假设整数类型
        lastValue = ConstantInt::get(Type::getInt32Ty(*context), it->val);
    }

    void visit(strNode *it) override {
        // 创建全局字符串常量
        GlobalVariable* strConst = builder->CreateGlobalString(it->val, "str", 0, module.get());
        lastValue = builder->CreateBitCast(strConst, PointerType::get(Type::getInt8Ty(*context), 0));
    }

    void visit(nullNode *it) override {
        lastValue = ConstantPointerNull::get(PointerType::get(Type::getInt8Ty(*context), 0));
    }

    void visit(typeNode *it) override {
        // 类型节点一般用于声明，在变量定义或函数参数处理时使用，不需要生成代码
        // 所以这里无需操作
    }

private:
    // 获取LLVM类型
    Type* getType(typeNode* typeNode) {
//        if (typeNode->isArray) {
//            return ArrayType::get(getBasicType(typeNode), 0);
//        }
        return getBasicType(typeNode->type);
    }

    Type* getBasicType(AST::Type* type) {
		if(dynamic_cast<AST::intType*>(type)) {
            return Type::getInt32Ty(*context);
		}
		else if(dynamic_cast<AST::boolType*>(type)) {
			return Type::getInt1Ty(*context);
		}
		else if(dynamic_cast<AST::voidType*>(type)) {
			return Type::getVoidTy(*context);
		}
		else if(dynamic_cast<AST::stringType*>(type) || dynamic_cast<AST::nullType*>(type)) {
			return PointerType::get(Type::getInt8Ty(*context), 0);
		}
		else if(dynamic_cast<AST::classType*>(type)) {
			return getOrCreateClassType(dynamic_cast<AST::classType*>(type)->className);
		}
        throw std::runtime_error("Unsupported type");
    }

    // 创建函数类型
    FunctionType* createFunctionType(funcDefNode* func) {
        Type* retType = getType(func->typeName);

        std::vector<Type*> paramTypes;
        for (auto& param : func->param) {
            paramTypes.push_back(getType(param->typeName));
        }

        // 如果是类成员函数，添加this指针
        if (currentClass) {
            paramTypes.insert(paramTypes.begin(),
                PointerType::get(currentClass, 0));
        }

        return FunctionType::get(retType, paramTypes, false);
    }

//    // 获取成员变量索引
//    int getMemberIndex(llvm::StructType* structType, const std::string& name) {
//	    unsigned index = 0;
//	    for (auto elementType : structType->elements()) {
//	        // 如果结构体有名称信息（在调试版本中）
//	        if (elementType->hasName() && elementType->getName() == name) {
//	            return index;
//	        }
//	        // 或者在索引中查找（如果是直接命名的结构体）
//	        if (structType->isLiteral() && index < structType->getNumElements()) {
//	            // 对于字面量结构体，我们可能没有名称信息
//	            // 这里可以添加自定义名称映射逻辑
//	        }
//	        index++;
//	    }
//	    return -1;
//	}

    // 获取或创建类类型
    StructType* getOrCreateClassType(const std::string& className) {
//        StructType* type = module->getIdentifiedStructTypes().;
//        if (!type) {
//            type = StructType::create(*context, className);
//            // 延迟填充成员 - 当定义类时设置
//        }
//        return type;
    }

        // 获取类型大小（字节数）
    uint64_t getTypeSize(Type* type) {
        return module->getDataLayout().getTypeAllocSize(type);
    }
    // 获取指针指向的类型
    Type* getPointedType(Type* ptrType) {
        return cast<PointerType>(ptrType)->getExtendedType(); // ????
    }
    // 获取存储类型的值类型（对于指针，获取指向的类型）
    Type* getValueType(Value* val) {
        if (val->getType()->isPointerTy()) {
            return getPointedType(val->getType());
        }
        return val->getType();
    }
    // 类型转换
    Value* createTypeCast(Value* val, Type* targetType) {
        Type* fromType = val->getType();
        if (fromType == targetType) return val;

         // 处理整数类型转换
	    if (targetType->isIntegerTy() && fromType->isIntegerTy()) {
	        return builder->CreateIntCast(val, targetType, true, "cast");
	    }

	    // 处理浮点类型转换
	    if (targetType->isFloatingPointTy() && fromType->isFloatingPointTy()) {
	        return builder->CreateFPCast(val, targetType, "fcast");
	    }

	    // 处理指针类型转换
	    if (targetType->isPointerTy() && fromType->isPointerTy()) {
	        return builder->CreateBitCast(val, targetType, "pcast");
	    }

	    // 处理整型到布尔类型的转换
	    if (targetType->isIntegerTy(1) && fromType->isIntegerTy()) {
	        llvm::Value* zero = llvm::ConstantInt::get(val->getType(), 0);
	        return builder->CreateICmpNE(val, zero, "boolcast");
	    }

	    // 其他转换类型...
	    throw std::runtime_error("Unsupported type conversion");
    }
    // 获取成员变量索引
    int getMemberIndex(const std::string& memberName) {
        if (!currentClass) return -1;
        // 从类元数据获取成员变量索引
        NamedMDNode* classMD = module->getNamedMetadata("class." + currentClass->getName());
        if (!classMD || classMD->getNumOperands() == 0) return -1;
        MDString* str = cast<MDString>(classMD->getOperand(0)->getOperand(0));
        std::vector<std::string> memberNames = split(std::string(str->getString()), ',');
        for (int i = 0; i < memberNames.size(); ++i) {
            if (memberNames[i] == memberName) {
                return i;
            }
        }
        return -1;
    }
    // 获取malloc函数
    Function* getMallocFunction() {
        Function* func = module->getFunction("malloc");
        if (!func) {
            Type* sizeType = Type::getInt64Ty(*context);
            FunctionType* mallocType = FunctionType::get(
                PointerType::get(Type::getInt8Ty(*context), 0), {sizeType}, false);
            func = Function::Create(mallocType, GlobalValue::ExternalLinkage, "malloc", module.get());
        }
        return func;
    }
    // 存储到左值（用于前缀和后缀++、--）
    void storeToLValue(ASTNode* node, Value* value) {
        // 左值表达式（如变量、成员访问、数组元素等）在访问时返回的是地址
        node->accept((ASTVisitor&) *this);
        Value* ptr = lastValue;
        builder->CreateStore(value, ptr);
    }

private:
    // 循环信息结构
    struct LoopInfo {
        BasicBlock* endBlock;
        BasicBlock* continueBlock;
    };
    std::vector<LoopInfo> loopStack;

    void pushLoop(BasicBlock* endBlock, BasicBlock* continueBlock) {
        loopStack.push_back({endBlock, continueBlock});
    }

    void popLoop() {
        if (!loopStack.empty()) {
            loopStack.pop_back();
        }
    }

    Value* createCast(Value* value, Type* targetType, const std::string& name = "") {
        if (value->getType() == targetType) {
            return value;
        }

        // 整型类型转换
        if (targetType->isIntegerTy() && value->getType()->isIntegerTy()) {
            return builder->CreateIntCast(value, targetType, true, name);
        }

        // 指针转换
        if (targetType->isPointerTy() && value->getType()->isPointerTy()) {
            return builder->CreateBitCast(value, targetType, name);
        }

        // 整型到布尔类型
        if (targetType->isIntegerTy(1) && value->getType()->isIntegerTy()) {
            Value* zero = ConstantInt::get(value->getType(), 0);
            return builder->CreateICmpNE(value, zero, name);
        }

        // 其他转换处理...
        throw std::runtime_error("Unsupported cast");
    }

};

// 初始化
void generateIR(ASTNode* root) {
    IRGenerator generator;
    root->accept(&generator);

    // 验证并输出
    if (verifyModule(*generator.getModule(), &errs())) {
        errs() << "IR verification failed\n";
    } else {
        generator.getModule()->print(outs(), nullptr);
    }
}
