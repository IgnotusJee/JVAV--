#include "AST/ASTVisitor.h"
#include "AST/ASTCollection.h"
#include "Tools/error.hpp"
#include "Frontend/SymbolTable.hpp"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Constants.h>
#include <llvm/ADT/APInt.h>
#include <llvm/IR/ValueSymbolTable.h>
#include <llvm/IR/Verifier.h>
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
        tokens.emplace_back(start, end);
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

	auto getModule() const {
		return module.get();
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
        Type* retType = getType(it->typeName);
        std::vector<llvm::Type*> paramTypes;

        for (auto& param : it->param) {
            paramTypes.push_back(getType(param->typeName));
        }

        // 如果是成员函数，添加this指针
        if (currentClass) {
            paramTypes.insert(paramTypes.begin(),
                llvm::PointerType::get(currentClass, 0));
        }

		std::string funcName;
		if(!currentClass) funcName = it->name;
		else {
			if(currentClass->getName().str() == it->name)
				funcName = currentClass->getName().str() + "_ctor";
			else funcName = currentClass->getName().str() + "." + it->name;
		}

        auto* funcType = FunctionType::get(retType, paramTypes, false);
        auto* func = Function::Create(funcType,
            GlobalValue::ExternalLinkage,
            funcName,
            module.get());

        currentFunction = func;
        auto* entryBB = BasicBlock::Create(*context, "entry", func);
        builder->SetInsertPoint(entryBB);

        // 设置参数名
        symbolTable.push(); // 函数作用域
        auto argIt = func->arg_begin();

        if (currentClass) {
            // 第一个参数是this指针
            thisPtr = argIt++;
            thisPtr->setName("this");
            symbolTable.addValue("this", thisPtr, llvm::PointerType::get(currentClass, 0));
        }

        for (auto& param : it->param) {
            auto* arg = argIt++;
            arg->setName(param->name);

			bool isArray;
			auto argType = getType(param->typeName, isArray);
            auto* alloca = builder->CreateAlloca(argType, nullptr, param->name);
            builder->CreateStore(arg, alloca);
            symbolTable.addValue(param->name, alloca, argType, isArray);
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

	// 全局变量声明和类内部声明
	void visit(varDefNode *it) override {
		// 获取当前生成类型的 llvm 类型
		bool isArray;
		llvm::Type* varType = getType(it->typeName, isArray);

		if(currentClass == nullptr) {
            Constant* zeroInit = Constant::getNullValue(varType);
			for (auto& var : it->var) {
				auto globalVar = new GlobalVariable(
				    *module,                    // 所属模块
				    isArray ? PointerType::get(varType, 0) : varType,                       // 变量类型
				    false,                // 是否为常量
				    GlobalValue::LinkageTypes::ExternalLinkage, // 链接类型
                    zeroInit,
				    // ConstantInt::get(varType, 0),                // 初始值 (Constant*)
				    var->name               // 变量名
				);
				symbolTable.addValue(var->name, globalVar, varType, isArray);
			}
		}
		else {
			throw std::runtime_error("we current assume that this cannot be reached");
		}
	}

	// 局部变量定义和初始化
    void visit(varDefStmtNode *it) override {
		// 获取当前生成类型的 llvm 类型
        llvm::Type* varType = getType(it->typeName);

        for (auto& var : it->var) {
            auto* localVar = builder->CreateAlloca(
                varType, nullptr, var->name);

            if (var->init) {
                var->init->accept((ASTVisitor &) *this);
                auto* initVal = var->init->addr;

                if (varType != initVal->getType()) {
                    initVal = createTypeCast(initVal, varType);
                }

                builder->CreateStore(initVal, localVar);
            } else {
                builder->CreateStore(
		                llvm::Constant::getNullValue(varType), localVar);
            }

			bool isArray = false;
			if(dynamic_cast<AST::arrayType*>(it->typeName->type)) {
				isArray = true;
				varType = getBasicType(dynamic_cast<AST::arrayType*>(it->typeName->type)->elemType);
			}

            symbolTable.addValue(var->name, localVar, varType, isArray);
        }
    }

	void visit(varExprNode *it) override {
		if(currentClass && thisPtr) {
			auto [memberPtr, type] = getObjectMember(thisPtr, currentClass, it->name);
			if(memberPtr) {
				it->addr = memberPtr;
				it->entity = type;
				it->isLeftVal = true;
				return;
			}
		}
        auto [value, type, isArray] = symbolTable.findValue(it->name);
		it->addr = value;
		it->entity = type;
		if(!it->addr | !it->entity)
			throw std::runtime_error("Symbol \"" + it->name + "\" not found");
		it->isLeftVal = true;
		it->isArray = isArray;
	}

    void visit(assignExprNode *it) override {
        // 处理右值表达式
        it->rhs->accept((ASTVisitor&) *this);
        Value* rvalue = it->rhs->addr;

		if(it->rhs->isLeftVal)
			rvalue = builder->CreateLoad(it->rhs->entity, rvalue, "loadrhs");

        // 处理左值表达式
        it->lhs->accept((ASTVisitor&) *this);
        Value* lvalue = it->lhs->addr;

		if(!it->lhs->isLeftVal)
			throw std::runtime_error("Leftside of assign must be left value");

        // 存储值
        builder->CreateStore(rvalue, lvalue);

        // 赋值表达式返回值是左值
        it->addr = lvalue;
		it->entity = it->rhs->entity;
		it->isLeftVal = true;
    }

    void visit(returnStmtNode *it) override {
        if (it->ret) {
            it->ret->accept((ASTVisitor&) *this);

			Value* retVal = it->ret->addr;
			Type* retType = it->ret->entity;

			if(it->ret->isLeftVal)
				retVal = builder->CreateLoad(retType, retVal, "loadreturn");

			// 类型检查
            Type* expectedType = currentFunction->getReturnType();
            if (retType != expectedType) {
                retVal = createTypeCast(retVal, expectedType);
            }

            builder->CreateRet(retVal);
        } else {
            builder->CreateRetVoid();
        }
    }

    void visit(varNode *it) override {
	    throw std::runtime_error("currently we assume this cannot be visited");

//void visit(varNode *it) override {
//    // 获取当前的访问上下文（是左值还是右值，是否允许加载）。
//    AccessContext ctx = currentContext();
//
//    // 1. 尝试在符号表中查找局部变量或函数参数。
//    Value* val = symbolTable.findValue(it->name);
//    if (val) {
//        // 如果找到了局部变量/参数 (它是一个 AllocaInst，即地址)
//        if (ctx.isLValue) { // 如果是左值上下文，需要地址
//            lastValue = val; // 直接使用其地址
//        } else if (ctx.isLoadAllowed) { // 如果是右值上下文且允许加载
//            lastValue = builder->CreateLoad(val->getType()->getPointerElementType(), val, it->name.c_str()); // 加载该地址处的值
//        } else { // 右值上下文但不允许加载 (例如，在 &x 中 x 的情况，虽然不常见于此)
//            lastValue = val; // 仍然是地址
//        }
//        return; // 找到并处理完毕
//    }
//
//    // 2. 如果不是局部变量，并且当前在类方法中 (thisPtr 有效)，则尝试作为类成员查找。
//    if (thisPtr) {
//        StructType* classType = dyn_cast<StructType>(thisPtr->getType()->getPointerElementType());
//        if (classType) {
//            try {
//                // 获取成员变量在类结构中的索引。
//                int memberIdx = getMemberIndex(classType, it->name);
//                // 创建 GEP 指令获取成员变量的地址。
//                // 参数：类型，this指针，0（用于解引用this指针），成员索引。
//                Value* memberPtr = builder->CreateStructGEP(classType, thisPtr, memberIdx, it->name.c_str());
//
//                if (ctx.isLValue) { // 左值上下文
//                    lastValue = memberPtr; // 结果是成员地址
//                } else if (ctx.isLoadAllowed) { // 右值上下文，允许加载
//                    lastValue = builder->CreateLoad(classType->getElementType(memberIdx), memberPtr, it->name.c_str()); // 加载成员的值
//                } else { // 右值上下文，不允许加载
//                    lastValue = memberPtr; // 结果是成员地址
//                }
//                return; // 找到并处理完毕
//            } catch (const std::runtime_error& e) {
//                // 成员未找到，继续尝试全局变量 (或者可以报错，取决于语言设计)
//            }
//        }
//    }
//
//    // 3. 尝试作为全局变量查找。
//    GlobalVariable* gVar = module->getNamedGlobal(it->name);
//    if (gVar) {
//        if (ctx.isLValue) { // 左值上下文
//            lastValue = gVar; // 全局变量本身就是指针 (地址)
//        } else if (ctx.isLoadAllowed) { // 右值上下文，允许加载
//            lastValue = builder->CreateLoad(gVar->getValueType(), gVar, it->name.c_str()); // 加载全局变量的值
//        } else { // 右值上下文，不允许加载
//            lastValue = gVar; // 结果是全局变量的地址
//        }
//        return; // 找到并处理完毕
//    }
//
//    // 如果变量在任何地方都未找到，则抛出错误。
//    throw std::runtime_error("Undefined variable: " + it->name);
//}
	}

    void visit(thisExprNode *it) override {
        if (!thisPtr) {
            throw std::runtime_error("'this' used outside class context");
        }
        it->addr = thisPtr;
		it->entity = currentClass;
		it->isLeftVal = true;
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
        BasicBlock* mergeBB = BasicBlock::Create(*context, "if.merge", currentFunction);
        std::vector<BasicBlock*> thenBlocks;
        std::vector<BasicBlock*> condBlocks;

        // 条件链处理
        for (size_t i = 0; i < it->cond.size(); i++) {
            // 条件块
            condBlocks.push_back(BasicBlock::Create(
                *context, "if.cond." + std::to_string(i), currentFunction));

            // then块
            thenBlocks.push_back(BasicBlock::Create(
                *context, "if.then." + std::to_string(i), currentFunction));
        }

		int elseBranch = it->Stmt.size() - it->cond.size();
		if(elseBranch > 1)
			throw std::runtime_error("Too much else branch");

        // else块
        BasicBlock* elseBB = elseBranch ?
            BasicBlock::Create(*context, "if.else", currentFunction) : mergeBB;

        // 初始跳转
        builder->CreateBr(condBlocks[0]);

        // 处理各分支
        for (size_t i = 0; i < it->cond.size(); i++) {
            // 条件块
            builder->SetInsertPoint(condBlocks[i]);
            it->cond[i]->accept((ASTVisitor&) *this);
            Value* cond = it->cond[i]->addr;

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
        BasicBlock* bodyBB = BasicBlock::Create(*context, "while.body", currentFunction);
        BasicBlock* endBB = BasicBlock::Create(*context, "while.end", currentFunction);

        // 保存控制流状态
        controlStack.push({condBB, endBB, condBB});

        // 初始跳转
        builder->CreateBr(condBB);

        // 条件块
        builder->SetInsertPoint(condBB);
        it->cond->accept((ASTVisitor&) *this);
        Value* cond = it->cond->addr;
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
        BasicBlock* bodyBB = BasicBlock::Create(*context, "for.body", currentFunction);
        BasicBlock* stepBB = BasicBlock::Create(*context, "for.step", currentFunction);
        BasicBlock* endBB = BasicBlock::Create(*context, "for.end", currentFunction);

        // 初始跳转
        builder->CreateBr(condBB);

        // 保存控制流状态
        controlStack.push({condBB, endBB, stepBB});

        // 条件块
        builder->SetInsertPoint(condBB);
        if (it->cond) {
            it->cond->accept((ASTVisitor&) *this);
            builder->CreateCondBr(it->cond->addr, bodyBB, endBB);
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
        BasicBlock* bodyBB = BasicBlock::Create(*context, "for.body", currentFunction);
        BasicBlock* stepBB = BasicBlock::Create(*context, "for.step", currentFunction);
        BasicBlock* endBB = BasicBlock::Create(*context, "for.end", currentFunction);

        // 初始跳转
        builder->CreateBr(condBB);

        // 保存控制流状态
        controlStack.push({condBB, endBB, stepBB});

        // 条件块
        builder->SetInsertPoint(condBB);
        if (it->cond) {
            it->cond->accept((ASTVisitor&) *this);
            builder->CreateCondBr(it->cond->addr, bodyBB, endBB);
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
        Value* objPtr = it->expr->addr;
	    auto classType = it->expr->entity;
		if(!classType->isStructTy())
			throw std::runtime_error(std::string (objPtr->getName()) + " is not a class instance");

        auto [memberPtr, memberType] = getObjectMember(objPtr, classType, it->name);

		if(!memberPtr || !memberType)
			throw std::runtime_error("\" " + it->name + "\" is not member of class \" " + classType->getStructName().str());

        // 作为左值处理，返回指针
        it->addr = memberPtr;
		it->entity = memberType;
		it->isLeftVal = true;
    }

    void visit(funcExprNode *it) override {
        // 1. 获取基本信息
        bool isMember = false;
        std::string funcName = it->name;
        std::vector<Value*> args;
		Function* func;

        if (currentClass != nullptr) {
            funcName = currentClass->getName().str() + "." + it->name;
            isMember = true;
        }

        // 2. 在模块中查找函数，先找成员函数，如果找不到则尝试全局。
		func = module->getFunction(funcName);
        if (!func) {
            func = module->getFunction(it->name);
            isMember = false;
			// 在内建函数中找函数
			if(!func) {
				func = getInlineFunction(it->name);
	            if (!func) throw std::runtime_error("Function '" + funcName + "' not found.");
			}
        }

        // 添加this指针（如果是成员函数）。
        if (isMember) {
            if (thisPtr) args.push_back(thisPtr);
            else throw std::runtime_error("No this pointer in member function");
        }

		visitFuncExpr(it, args, func, funcName);
    }

     void visit(memberFuncExprNode *it) override {
        std::vector<Value*> args;
		Function* func;

	     // 获取对象指针
	     it->expr->accept((ASTVisitor&) *this);
	     Value* objPtr = it->expr->addr;
	     auto structType = (it->expr->entity);
	     if(!structType->isStructTy())
		     throw std::runtime_error(std::string (objPtr->getName()) + " is not a class instance");

		 auto classType = static_cast<StructType *>(structType);

		 std::string funcName = classType->getName().str() + "." + it->func->name;
		// 2. 在模块中查找成员函数
		func = module->getFunction(funcName);
		if (!func) throw std::runtime_error(funcName + " is not a member of " + std::string(classType->getName()));

		args.push_back(objPtr); // 刚才计算出的 this 指针

		visitFuncExpr(it->func, args, func, funcName, it);
    }

    void visit(arrayExprNode *it) override {
        // 获取数组指针
        it->name->accept((ASTVisitor&) *this);
        Value* arrayPtr = it->name->addr;
		if(!it->name->isArray)
			throw std::runtime_error("Not a array type");

        // 获取索引
        it->index->accept((ASTVisitor&) *this);
        Value* index = it->index->addr;
		if(it->index->isLeftVal)
			index = builder->CreateLoad(it->index->entity, index, "loadindex");

        // 计算元素地址
        Type* arrayType = it->name->entity;
		arrayPtr = builder->CreateLoad(PointerType::get(arrayType, 0), arrayPtr, "loadarray");
        Value* elemPtr = builder->CreateInBoundsGEP(
            arrayType, arrayPtr, {index});

        it->addr = elemPtr;
		it->entity = arrayType;
		it->isLeftVal = true;
    }

    void visit(newExprNode *it) override {
        // 基本类型处理
        Type* baseType = getBasicType(it->typeName);

        // 创建malloc调用
        Function* mallocFunc = getMallocFunction();

        if (it->dim) {
			Value* lastSize = nullptr;
			for(auto expr: it->exprs) {
				expr->accept((ASTVisitor&) *this);
				Value* curDimSize = expr->addr;
				if(lastSize == nullptr) lastSize = curDimSize;
				else lastSize = builder->CreateMul(lastSize, curDimSize);
			}

            Value* arraySize = builder->CreateMul(
                builder->CreateIntCast(lastSize, Type::getInt64Ty(*context), false),
				ConstantInt::get(Type::getInt64Ty(*context), getTypeSize(baseType)));
			if(getTypeSize(arraySize->getType()) != 8)
				throw std::runtime_error("Incompatible malloc param");
            Value* arrayPtr = builder->CreateCall(mallocFunc, {arraySize});

            // 类型转换
            arrayPtr = builder->CreateBitCast(
                arrayPtr, PointerType::get(baseType, 0));

            it->addr = arrayPtr;
			it->entity = baseType;
        } else {
            // 对象分配
            Value* size = ConstantInt::get(
                Type::getInt64Ty(*context), getTypeSize(baseType));

            Value* objPtr = builder->CreateCall(mallocFunc, {size});

            // 类型转换
            objPtr = builder->CreateBitCast(
                objPtr, PointerType::get(baseType, 0));

            // 调用构造函数
            if (baseType->isStructTy()) {
				Function* ctor = module->getFunction(std::string(baseType->getStructName()) + "_ctor");
				if(ctor)
	                builder->CreateCall(ctor, {objPtr});
            }

            it->addr = builder->CreateLoad(baseType, objPtr, "loadobj");
			it->entity = baseType;
        }
		it->isLeftVal = false;
    }

    void visit(prefixUnaryExprNode *it) override {
        it->expr->accept((ASTVisitor&) *this);
        Value* operand = it->expr->addr;
		Type* opertype = it->expr->entity;

		if(operand->getType()->isPointerTy())
			operand = builder->CreateLoad(opertype, operand, "loadoperand");

        switch (it->opCode) {
            case prefixUnaryExprNode::prefixOpType::Inc: {
                Value* newVal = builder->CreateAdd(
                    operand, ConstantInt::get(opertype, 1));
                storeToLValue(it->expr, newVal);
                it->addr = newVal;
                break;
            }
            case prefixUnaryExprNode::prefixOpType::Dec: {
                Value* newVal = builder->CreateSub(
                    operand, ConstantInt::get(opertype, 1));
                storeToLValue(it->expr, newVal);
                it->addr = newVal;
                break;
            }
            case prefixUnaryExprNode::prefixOpType::Not:
                it->addr = builder->CreateNot(operand);
                break;
            case prefixUnaryExprNode::prefixOpType::Inv:
                it->addr = builder->CreateNeg(operand);
                break;
            case prefixUnaryExprNode::prefixOpType::Sub:
                it->addr = builder->CreateNeg(operand);
                break;
            default:
                throw std::runtime_error("Unsupported prefix operator");
        }
		it->entity = it->expr->entity;
		it->isLeftVal = false;
    }

    void visit(suffixUnaryExprNode *it) override {
        it->expr->accept((ASTVisitor&) *this);
        Value* original = it->expr->addr;
		Type* oritype = it->expr->entity;

		if(original->getType()->isPointerTy())
			original = builder->CreateLoad(oritype, original, "loadoriginal");

        switch (it->opCode) {
            case suffixUnaryExprNode::suffixOpType::Inc: {
                Value* newVal = builder->CreateAdd(
                    original, ConstantInt::get(oritype, 1));
                storeToLValue(it->expr, newVal);
                it->addr = original;  // 后缀返回原始值
                break;
            }
            case suffixUnaryExprNode::suffixOpType::Dec: {
                Value* newVal = builder->CreateSub(
                    original, ConstantInt::get(oritype, 1));
                storeToLValue(it->expr, newVal);
                it->addr = original;
                break;
            }
            default:
                throw std::runtime_error("Unsupported suffix operator");
        }
		it->entity = it->expr->entity;
    }

    void visit(binaryExprNode *it) override {
	    // 访问左操作数
        it->lhs->accept((ASTVisitor&) *this);
        Value* lhs = it->lhs->addr;

        // 访问右操作数
        it->rhs->accept((ASTVisitor&) *this);
        Value* rhs = it->rhs->addr;

//        std::cerr << "[assign] lhs: ";
//        if (lhs) lhs->print(llvm::errs());
//        else std::cerr << "null";
//        std::cerr << std::endl;
//        it->lhs->entity->print(llvm::errs());
//        std::cerr << std::endl;
//
//        std::cerr << "[assign] rhs: ";
//        if (rhs) rhs->print(llvm::errs());
//        else std::cerr << "null";
//        std::cerr << std::endl;
//        it->rhs->entity->print(llvm::errs());
//        std::cerr << std::endl;

        if (lhs && lhs->getType()->isPointerTy()) {
            lhs = builder->CreateLoad(it->lhs->entity, lhs, "loadlhs");
        }
        if (rhs && rhs->getType()->isPointerTy()) {
            rhs = builder->CreateLoad(it->rhs->entity, rhs, "loadrhs");
        }


//        // 类型提升：确保左右操作数类型一致
//        if (lhs->getType() != rhs->getType()) {
//            if (it->lhs->entity->isIntegerTy() && it->rhs->entity->isIntegerTy()) {
//                // 整数提升：将较小的整数类型提升到较大的类型
//                IntegerType* lhsInt = cast<IntegerType>(lhs->getType());
//                IntegerType* rhsInt = cast<IntegerType>(rhs->getType());
//                if (lhsInt->getBitWidth() > rhsInt->getBitWidth()) {
//                    rhs = builder->CreateIntCast(rhs, lhs->getType(), true, "cast");
//                } else {
//                    lhs = builder->CreateIntCast(lhs, rhs->getType(), true, "cast");
//                }
//            } else {
//                // 其他类型转换逻辑（例如整型转浮点等）
//                // 这里简化为错误
//                throw std::runtime_error("Type mismatch in binary operator");
//            }
//        }

        // 生成操作
        switch (it->opCode) {
            case binaryExprNode::binaryOpType::Add:
                it->addr = builder->CreateAdd(lhs, rhs, "addtmp");
                break;
            case binaryExprNode::binaryOpType::Sub:
                it->addr = builder->CreateSub(lhs, rhs, "subtmp");
                break;
            case binaryExprNode::binaryOpType::Mul:
                it->addr = builder->CreateMul(lhs, rhs, "multmp");
                break;
            case binaryExprNode::binaryOpType::Div:
                it->addr = builder->CreateSDiv(lhs, rhs, "divtmp");
                break;
            case binaryExprNode::binaryOpType::Mod:
                it->addr = builder->CreateSRem(lhs, rhs, "modtmp");
                break;
            case binaryExprNode::binaryOpType::Eq:
                it->addr = builder->CreateICmpEQ(lhs, rhs, "cmptmp");
                break;
            case binaryExprNode::binaryOpType::Neq:
                it->addr = builder->CreateICmpNE(lhs, rhs, "cmptmp");
                break;
            case binaryExprNode::binaryOpType::Le:
                it->addr = builder->CreateICmpSLT(lhs, rhs, "cmptmp");
                break;
            case binaryExprNode::binaryOpType::Ge:
                it->addr = builder->CreateICmpSGT(lhs, rhs, "cmptmp");
                break;
            case binaryExprNode::binaryOpType::Leq:
                it->addr = builder->CreateICmpSLE(lhs, rhs, "cmptmp");
                break;
            case binaryExprNode::binaryOpType::Geq:
                it->addr = builder->CreateICmpSGE(lhs, rhs, "cmptmp");
                break;
            case binaryExprNode::binaryOpType::And:
                it->addr = builder->CreateAnd(lhs, rhs, "andtmp");
                break;
            case binaryExprNode::binaryOpType::Or:
                it->addr = builder->CreateOr(lhs, rhs, "ortmp");
                break;
            case binaryExprNode::binaryOpType::Bitand:
                it->addr = builder->CreateAnd(lhs, rhs, "bitandtmp");
                break;
            case binaryExprNode::binaryOpType::Bitor:
                it->addr = builder->CreateOr(lhs, rhs, "bitortmp");
                break;
            case binaryExprNode::binaryOpType::Bitxor:
                it->addr = builder->CreateXor(lhs, rhs, "bitxortmp");
                break;
            case binaryExprNode::binaryOpType::Lshift:
                it->addr = builder->CreateShl(lhs, rhs, "shltmp");
                break;
            case binaryExprNode::binaryOpType::Rshift:
                it->addr = builder->CreateAShr(lhs, rhs, "ashrtmp"); // 算术右移
                break;
            default:
                throw std::runtime_error("Unsupported binary operator");
        }
//        std::cerr << "[assign] binaryExprNode: ";
//        if (it->addr) it->addr->print(llvm::errs());
//        else std::cerr << "null";
//        std::cerr << std::endl;
		it->entity = it->lhs->entity;
		it->isLeftVal = false;
    }

    void visit(ternaryExprNode *it) override {
        // 条件部分
        it->cond->accept((ASTVisitor&) *this);
        Value* cond = it->cond->addr;
		if(it->cond->isLeftVal)
			cond = builder->CreateLoad(it->cond->entity, cond, "loadcond");

        // 创建基本块
        Function* func = builder->GetInsertBlock()->getParent();
        BasicBlock* thenBB = BasicBlock::Create(*context, "ternary.then", func);
        BasicBlock* elseBB = BasicBlock::Create(*context, "ternary.else", func);
        BasicBlock* mergeBB = BasicBlock::Create(*context, "ternary.merge", func);

        builder->CreateCondBr(cond, thenBB, elseBB);

        // then部分
        builder->SetInsertPoint(thenBB);
        it->thenExpr->accept((ASTVisitor&) *this);
        Value* thenVal = it->thenExpr->addr;
		if(it->thenExpr->isLeftVal)
			thenVal = builder->CreateLoad(it->thenExpr->entity, thenVal, "loadthen");
        builder->CreateBr(mergeBB);
        thenBB = builder->GetInsertBlock(); // 更新thenBB，防止后面被修改

        // else部分
        builder->SetInsertPoint(elseBB);
        it->elseExpr->accept((ASTVisitor&) *this);
        Value* elseVal = it->elseExpr->addr;
		if(it->elseExpr->isLeftVal)
			elseVal = builder->CreateLoad(it->elseExpr->entity, elseVal, "loadelse");
        builder->CreateBr(mergeBB);
        elseBB = builder->GetInsertBlock();

        // 合并
        builder->SetInsertPoint(mergeBB);

        // 创建PHI节点
        Type* resultType = thenVal->getType();
        PHINode* phi = builder->CreatePHI(resultType, 2, "phi");
        phi->addIncoming(thenVal, thenBB);
        phi->addIncoming(elseVal, elseBB);
        it->addr = phi;
		it->entity = resultType;
		it->isLeftVal = false;
    }

    void visit(boolNode *it) override {
        it->addr = ConstantInt::get(Type::getInt1Ty(*context), it->val ? 1 : 0);
		it->entity = it->addr->getType();
		it->isLeftVal = false;
    }

    void visit(numberNode *it) override {
        // 假设整数类型
        it->addr = ConstantInt::get(Type::getInt32Ty(*context), it->val);
		it->entity = it->addr->getType();
		it->isLeftVal = false;
    }

    void visit(strNode *it) override {
        // 创建全局字符串常量
        GlobalVariable* strConst = builder->CreateGlobalString(it->val, "str", 0, module.get());
        it->addr = builder->CreateBitCast(strConst, PointerType::get(Type::getInt8Ty(*context), 0));
		it->entity = it->addr->getType();
		it->isLeftVal = false;
    }

    void visit(nullNode *it) override {
        it->addr = ConstantPointerNull::get(PointerType::get(Type::getInt8Ty(*context), 0));
		it->entity = it->addr->getType();
		it->isLeftVal = false;
    }

    void visit(typeNode *it) override {
        // 类型节点一般用于声明，在变量定义或函数参数处理时使用，不需要生成代码
        // 所以这里无需操作
		throw std::runtime_error("currently we assume this cannot be visited");
    }

private:
    // 获取LLVM类型
    Type* getType(typeNode* typeNode) {
        return getBasicType(typeNode->type);
    }
	Type* getType(typeNode* typeNode, bool& isArray) {
		if(dynamic_cast<AST::arrayType*>(typeNode->type)) {
			isArray = true;
			return getBasicType(dynamic_cast<AST::arrayType*>(typeNode->type)->elemType);
		}
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
			return symbolTable.findType(dynamic_cast<AST::classType*>(type)->className);
		}
		else if(dynamic_cast<AST::arrayType*>(type)) {
			return PointerType::get(getBasicType(dynamic_cast<AST::arrayType*>(type)->elemType), 0);
		}
        throw std::runtime_error("Unsupported type");
    }

    // 创建函数类型
//    FunctionType* createFunctionType(funcDefNode* func) {
//        Type* retType = getType(func->typeName);
//
//        std::vector<Type*> paramTypes;
//        for (auto& param : func->param) {
//            paramTypes.push_back(getType(param->typeName));
//        }
//
//        // 如果是类成员函数，添加this指针
//        if (currentClass) {
//            paramTypes.insert(paramTypes.begin(),
//                PointerType::get(currentClass, 0));
//        }
//
//        return FunctionType::get(retType, paramTypes, false);
//    }

	std::tuple<Value*, Type*> getObjectMember(Value* objPtr, Type* classType, const std::string& memberName) {
		auto structType = static_cast<StructType *>(classType);
		int index = getMemberIndex(structType, memberName);
        if (index < 0) {
            return std::make_tuple((Value*) nullptr, (Type*) nullptr);
        }

		auto memberPtr = builder->CreateStructGEP(classType, objPtr, index);
		auto memberType = structType->elements()[index];

        return std::make_tuple(memberPtr, memberType);
	}

	void visitFuncExpr(funcExprNode* it, std::vector<Value*> &args, Function* func, const std::string& funcName, memberFuncExprNode* fit= nullptr) {

		// 3. 准备参数列表
        for (auto& argExpr : it->args) {
            pushContext(false, true); // 参数作为右值访问
            argExpr->accept((ASTVisitor&) *this);
            popContext();
            Value* argVal = argExpr->addr; // 获取参数值
			Type* argType = argExpr->entity;

            // 类型检查与转换：确保传递的参数类型与函数期望的参数类型匹配。
            if (args.size() < func->getFunctionType()->getNumParams()) {
                Type* expectedType = func->getFunctionType()->getParamType(args.size());
				if(argVal->getType()->isPointerTy() && !argType->isPointerTy())
					argVal = builder->CreateLoad(argType, argVal, "loadarg");
                if (argVal->getType() != expectedType) {
                    argVal = createTypeCast(argVal, expectedType);
                    if (!argVal) {
                        throw std::runtime_error("Type mismatch for argument " + std::to_string(args.size()) +
                                               " in call to '" + funcName + "'.");
                    }
                }
            }
            else {
                throw std::runtime_error("Too many arguments in call to '" + funcName + "'.");
            }
            args.push_back(argVal);
        }

        // 检查参数数量是否足够。
        if (args.size() < func->getFunctionType()->getNumParams()) {
             throw std::runtime_error("Too few arguments in call to '" + funcName + "'.");
        }

        // 4. 创建函数调用指令。
		if(fit) {
			if (func->getReturnType()->isVoidTy()) {
	            builder->CreateCall(func, args);
	            fit->addr = nullptr; // void 函数调用没有返回值
	        } else {
	            fit->addr = builder->CreateCall(func, args, "calltmp"); // 非 void 函数调用
	        }
			fit->entity = func->getReturnType();
			fit->isLeftVal = false;
		}
		else {
	        if (func->getReturnType()->isVoidTy()) {
	            builder->CreateCall(func, args);
	            it->addr = nullptr; // void 函数调用没有返回值
	        } else {
	            it->addr = builder->CreateCall(func, args, "calltmp"); // 非 void 函数调用
	        }
			it->entity = func->getReturnType();
			it->isLeftVal = false;
		}
	}

    // 获取成员变量索引
    int getMemberIndex(llvm::StructType* structType, const std::string& name) {
		NamedMDNode* classMD = module->getNamedMetadata("class." + structType->getName());
        if (!classMD || classMD->getNumOperands() == 0) return -1;
		auto* str = cast<MDString>(classMD->getOperand(0)->getOperand(0));
        std::vector<std::string> memberNames = split(std::string(str->getString()), ',');
        for (int i = 0; i < memberNames.size(); ++i) {
            if (memberNames[i] == name) {
                return i;
            }
        }
        return -1;
	}

	// 获取类型大小（字节数）
    uint64_t getTypeSize(Type* type) {
        return module->getDataLayout().getTypeAllocSize(type);
    }
    // 类型转换
    Value* createTypeCast(Value* val, Type* targetType) {
        Type* fromType = val->getType();
        if (fromType == targetType) return val;

         // 处理整数类型转换
	    if (targetType->isIntegerTy() && fromType->isIntegerTy()) {
	        return builder->CreateIntCast(val, targetType, true, "cast");
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

    // 获取malloc函数
    Function* getMallocFunction() {
		return getFunc("malloc", PointerType::get(Type::getInt8Ty(*context), 0), Type::getInt64Ty(*context));
    }
	Function* getInlineFunction(const std::string &name) {
		if(name == "print")
			return getFunc("print", Type::getVoidTy(*context), PointerType::get(Type::getInt8Ty(*context), 0));
		if(name == "println")
			return getFunc("println", Type::getVoidTy(*context), PointerType::get(Type::getInt8Ty(*context), 0));
		if(name == "printInt")
			return getFunc("printInt", Type::getVoidTy(*context), Type::getInt32Ty(*context));
		if(name == "printIntln")
			return getFunc("printIntln", Type::getVoidTy(*context), Type::getInt32Ty(*context));
		else if(name == "toString")
			return getFunc("toString", PointerType::get(Type::getInt8Ty(*context), 0), Type::getInt32Ty(*context));
		else if(name == "getInt")
			return getFunc("getInt", Type::getInt32Ty(*context));
		return nullptr;
	}
	// 获取特殊函数
	template <class retType, class ...Args>
	Function* getFunc(const std::string &name, retType retTypeRef, Args ...args) {
		Function* func = module->getFunction(name);
        if (!func) {
            FunctionType* funcType = FunctionType::get(retTypeRef, {args...}, false);
            func = Function::Create(funcType, GlobalValue::ExternalLinkage, name, module.get());
        }
        return func;
	}
	template <class retType>
	Function* getFunc(const std::string &name, retType retTypeRef) {
		Function* func = module->getFunction(name);
        if (!func) {
            FunctionType* funcType = FunctionType::get(retTypeRef, false);
            func = Function::Create(funcType, GlobalValue::ExternalLinkage, name, module.get());
        }
        return func;
	}
    // 存储到左值（用于前缀和后缀++、--）
    void storeToLValue(ExprNode* node, Value* value) {
        // 左值表达式（如变量、成员访问、数组元素等）在访问时返回的是地址
        node->accept((ASTVisitor&) *this);
        Value* ptr = node->addr;
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
Module* generateIR(ASTNode* root, const std::string& out_path) {
    IRGenerator generator;
    root->accept((ASTVisitor &) generator);

    // 验证并输出
    if (verifyModule(*generator.getModule(), &errs())) {
        errs() << "IR verification failed\n";
        return nullptr;
    } 
    else {
		std::error_code EC;
		auto out = raw_fd_ostream(out_path, EC);
        Module* jvavmodule = generator.getModule();
        jvavmodule->print(out, nullptr);
        return jvavmodule;
    }
}

Module* generateIR(ASTNode* root) {
    IRGenerator generator;
    root->accept((ASTVisitor &) generator);

    // 验证并输出
    if (verifyModule(*generator.getModule(), &errs())) {
        errs() << "IR verification failed\n";
        return nullptr;
    } 
    else {
        Module* jvavmodule = generator.getModule();
        jvavmodule->print(outs(), nullptr);
        return jvavmodule;
    }
}