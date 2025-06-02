#include "AST/ASTVisitor.h"
#include "Tools/scope.h"
#include "Tools/globalScope.h"
#include "AST/Type/Type.hpp"
#include "AST/Type/intType.hpp"
#include "AST/Type/boolType.hpp"
#include "AST/Type/voidType.hpp"
#include "AST/Type/nullType.hpp"
#include "AST/Type/stringType.hpp"
#include "AST/Type/classType.hpp"
#include "AST/Type/arrayType.hpp"
#include "AST/Type/funcType.hpp"
#include "Tools/error.hpp"

#include "AST/rootNode.hpp"
#include "AST/varDefNode.hpp"
#include "AST/classDefNode.hpp"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Constants.h>
#include <llvm/ADT/APInt.h>
#include <unordered_map>
#include <memory>
#include <cctype>

class IRGenerator : public ASTVisitor {
private:
    llvm::LLVMContext &context;
    llvm::Module *module;
    llvm::IRBuilder<> builder;
    globalScope *global;
    Scope *currentScope;
    AST::Type *currentType;
    llvm::Value *currentThis;
    llvm::StructType *currentClass;
    bool getVal;
    llvm::BasicBlock *currentBlock;
    llvm::BasicBlock *globalInit;
    llvm::BasicBlock *beginBlock;
    llvm::BasicBlock *endBlock;
    llvm::Function *currentFunction;
    std::unordered_map<std::string, llvm::GlobalVariable*> strMap;
    int count;
    llvm::Type *llvmI32Type;
    llvm::Type *llvmI8Type;
    llvm::Type *llvmI1Type;
    llvm::Type *llvmStrType;
    llvm::Type *llvmVoidType;
    std::unordered_map<llvm::Function*, llvm::BasicBlock*> retBlocks;

public:
    IRGenerator(llvm::LLVMContext &ctx, llvm::Module *mod, globalScope *glob) 
        : context(ctx), module(mod), builder(ctx), global(glob),
          currentScope(glob), currentType(nullptr), currentThis(nullptr),
          currentClass(nullptr), getVal(true), currentBlock(nullptr),
          globalInit(nullptr), beginBlock(nullptr), endBlock(nullptr),
          currentFunction(nullptr), count(0) {
        
        // 初始化基本类型
        llvmI32Type = llvm::Type::getInt32Ty(context);
        llvmI8Type = llvm::Type::getInt8Ty(context);
        llvmI1Type = llvm::Type::getInt1Ty(context);
        llvmStrType = llvm::PointerType::get(llvmI8Type, 0);
        llvmVoidType = llvm::Type::getVoidTy(context);
    }

    // 辅助函数：创建临时变量
    llvm::Value* createTemp(llvm::Type *type, const std::string &name) {
        return builder.CreateAlloca(type, nullptr, name + "." + std::to_string(++count));
    }

    // 类型转换
    llvm::Type* convertType(AST::Type *astType) {
        if (dynamic_cast<AST::intType*>(astType)) {
            return llvmI32Type;
        } else if (dynamic_cast<AST::boolType*>(astType)) {
            return llvmI1Type;
        } else if (dynamic_cast<AST::voidType*>(astType) ||
                   dynamic_cast<AST::nullType*>(astType)) {
            return llvmVoidType;
        } else if (dynamic_cast<AST::stringType*>(astType)) {
            return llvmStrType;
        } else if (auto classType = dynamic_cast<AST::classType*>(astType)) {
            return llvm::PointerType::getUnqual(llvm::StructType::create(context, classType->className));
        } else if (auto arrayType = dynamic_cast<AST::arrayType*>(astType)) {
            llvm::Type *elemType = convertType(arrayType->elemType);
            for (int i = 0; i < arrayType->dim; i++) {
                elemType = llvm::PointerType::getUnqual(elemType);
            }
            return elemType;
        } else {
            throw InternalError("Unknown type");
        }
    }

    // 初始化全局结构
    void init() {
        // 处理全局函数和类定义
        for (auto &[name, type] : global->basic) {
            if (auto funcType = dynamic_cast<AST::funcType*>(type)) {
                llvm::Function *func = createFunction(funcType->func);
                global->putFunc(name, func);
                // 处理内置函数
                auto builtinIt = global->BuiltinFunc.find(name);
                if (builtinIt != global->BuiltinFunc.end()) {
                    // 添加内置函数声明
                    std::vector<llvm::Type*> argTypes;
                    for (auto &param : func->getFunctionType()->params()) {
                        argTypes.push_back(param);
                    }
                    llvm::FunctionType *pFunctionType = llvm::FunctionType::get(func->getReturnType(), argTypes, false);
                    llvm::Function::Create(pFunctionType, llvm::Function::ExternalLinkage, name, module);
                }
            } else if (auto classType = dynamic_cast<AST::classType*>(type)) {
                llvm::StructType *structType = llvm::StructType::create(context, classType->className);
                global->putClass(classType->className, structType);
            }
        }

        // 添加malloc声明
        llvm::FunctionType *mallocType = llvm::FunctionType::get(llvmStrType, {llvmI32Type}, false);
        llvm::Function::Create(mallocType, llvm::Function::ExternalLinkage, "malloc", module);
    }

    // 创建函数
    llvm::Function* createFunction(funcDefNode *funcDef) {
        // 确定返回类型
        llvm::Type *retType = convertType(funcDef->typeName->type);
        
        // 构造参数类型列表
        std::vector<llvm::Type*> paramTypes;
        if (currentClass) {
            paramTypes.push_back(llvm::PointerType::getUnqual(currentClass));
        }

        for (auto &param : funcDef->param) {
            paramTypes.push_back(convertType(param->typeName->type));
        }
        
        // 创建函数类型
        llvm::FunctionType *funcType = llvm::FunctionType::get(retType, paramTypes, false);
        
        // 确定函数名
        std::string funcName = funcDef->name;
        if (currentClass) {
            funcName = currentClass->getName().str() + "." + funcName;
        }
        
        // 创建函数
        llvm::Function *func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, funcName, module);
        return func;
    }

    // 访问根节点
    void visit(rootNode *it) override {
        globalInit = llvm::BasicBlock::Create(context, "_global_init");
        init();
        
        // 处理所有定义
        for (auto def : it->Def) {
            def->accept((ASTVisitor &) *this);
        }
        
        // 添加全局初始化结束
        builder.SetInsertPoint(globalInit);
        builder.CreateRet(llvm::ConstantInt::get(llvmI32Type, 0));
    }

    // 变量声明
    void visit(varDefNode *it) override {
        currentType = it->typeName->type;
        for (auto var : it->var) {
            var->accept((ASTVisitor &) *this);
        }
        currentType = nullptr;
    }

    // 类定义
    void visit(classDefNode *it) override {
        currentScope = new Scope(currentScope);
        currentClass = global->getClass(it->name);

        std::vector<llvm::Type*> class_types;
        
        // 处理成员变量
        int offset = 0;
        for (auto varDef : it->varDef) {
            llvm::Type *type = convertType(varDef->typeName->type);
            for (auto var : varDef->var) {
                // 添加类成员
                auto *classType = currentClass;
                class_types.push_back(type);
                auto local_val = new llvm::AllocaInst(type, )
                currentScope->putVar(var->name, type);
            }
        }
        
        // 处理成员函数
        bool hasConstructor = false;
        for (auto func : it->funcDef) {
            if (func->name == it->name) hasConstructor = true;
            func->accept(this);
        }
        
        // 生成默认构造函数
        if (!hasConstructor) {
            llvm::FunctionType *ctorType = llvm::FunctionType::get(llvmVoidType, {PointerType::getUnqual(currentClass)}, false);
            llvm::Function *ctor = llvm::Function::Create(ctorType, llvm::Function::ExternalLinkage, 
                                            it->name + "." + it->name, module);
            
            llvm::BasicBlock *entry = llvm::BasicBlock::Create(context, "entry", ctor);
            builder.SetInsertPoint(entry);
            builder.CreateRetVoid();
        }
        
        currentClass = nullptr;
        currentScope = currentScope->fatherScope;
    }

    // 函数定义
    void visit(funcDefNode *it) override {
        currentScope = new Scope(currentScope);
        
        // 获取函数
        std::string funcName = it->name;
        if (currentClass) {
            funcName = cast<llvm::StructType>(currentClass)->getName().str() + "." + it->name;
        }
        currentFunction = global->getFunc(funcName);
        
        // 创建基本块
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(context, "entry", currentFunction);
        llvm::BasicBlock *funcBody = llvm::BasicBlock::Create(context, "funcBody", currentFunction);
        llvm::BasicBlock *retBlock = llvm::BasicBlock::Create(context, "return", currentFunction);
        retBlocks[currentFunction] = retBlock;
        
        builder.SetInsertPoint(entry);
        
        // 处理参数
        unsigned idx = 0;
        for (auto &arg : currentFunction->args()) {
            if (idx == 0 && currentClass) {
                arg.setName("this");
                currentScope->putVar("this", &arg, it->pos);
            } else {
                paramNode *param = it->param->params[idx - (currentClass ? 1 : 0)];
                arg.setName(param->name);
                currentScope->putVar(param->name, &arg, it->pos);
            }
            idx++;
        }
        
        // 生成返回值空间
        llvm::Value *retVal = nullptr;
        if (!currentFunction->getReturnType()->isVoidTy()) {
            retVal = builder.CreateAlloca(currentFunction->getReturnType(), nullptr, "retval");
            if (funcName == "main") {
                builder.CreateStore(llvm::ConstantInt::get(llvmI32Type, 0), retVal);
            }
        }
        
        // 跳转到函数体
        builder.CreateBr(funcBody);
        builder.SetInsertPoint(funcBody);
        
        // 处理函数体
        it->suite->accept(this);
        
        // 跳转到返回块
        if (!builder.GetInsertBlock()->getTerminator()) {
            builder.CreateBr(retBlock);
        }
        
        // 返回块处理
        builder.SetInsertPoint(retBlock);
        if (currentFunction->getReturnType()->isVoidTy()) {
            builder.CreateRetVoid();
        } else if (retVal) {
            llvm::Value *retValue = builder.CreateLoad(currentFunction->getReturnType(), retVal);
            builder.CreateRet(retValue);
        }
        
        currentScope = currentScope->fatherScope;
        currentFunction = nullptr;
    }

    // 变量节点
    void visit(varNode *it) override {
        Type *type = convertType(currentType, it->pos);
        
        if (dynamic_cast<globalScope*>(currentScope)) {
            // 全局变量
            llvm::GlobalVariable *globalVar = new llvm::GlobalVariable(
                *module, type, false, GlobalValue::ExternalLinkage,
                Constant::getNullValue(type), it->name
            );
            currentScope->putVar(it->name, globalVar, it->pos);
            
            if (it->init) {
                it->init->accept(this);
                if (auto strVal = dynamic_cast<strNode*>(it->init)) {
                    llvm::GlobalVariable *strConst = storeString(strVal->val);
                    builder.CreateStore(strConst, globalVar);
                } else {
                    // 其他初始化处理
                }
            }
        } else {
            // 局部变量
            llvm::Value *var = builder.CreateAlloca(type, nullptr, it->name);
            currentScope->putVar(it->name, var, it->pos);
            
            if (it->init) {
                it->init->accept(this);
                llvm::Value *initVal = it->init->getLLVMValue(); // 假设AST节点有方法获取LLVM值
                builder.CreateStore(initVal, var);
            }
        }
    }

    // 其他visit方法根据类似模式实现...

private:
    // 存储字符串常量
    llvm::GlobalVariable* storeString(const std::string &str) {
        if (strMap.find(str) != strMap.end()) {
            return strMap[str];
        }
        
        Constant *strConst = ConstantDataArray::getString(context, str);
        llvm::GlobalVariable *strVar = new llvm::GlobalVariable(
            *module, strConst->getType(), true,
            GlobalValue::PrivateLinkage, strConst, "str." + std::to_string(++count)
        );
        
        strMap[str] = strVar;
        return strVar;
    }

    // 创建分配空间
    llvm::Value* createEntryBlockAlloca(llvm::Function *func, Type *type, const std::string &name) {
        IRBuilderBase::InsertPointGuard guard(builder);
        llvm::BasicBlock *entry = &func->getEntryBlock();
        builder.SetInsertPoint(entry);
        return builder.CreateAlloca(type, nullptr, name);
    }

    // 获取变量值
    llvm::Value* getVariableValue(const std::string &name, Position pos) {
        llvm::Value *var = currentScope->getVar(name, true);
        if (!var) {
            throw InternalError(pos, "Undefined variable: " + name);
        }
        return builder.CreateLoad(var->getType()->getPointerElementType(), var);
    }
};

