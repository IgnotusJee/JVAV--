#pragma once

#include "Tools/scope.h"
#include "AST/Type/classType.hpp"

#include <llvm-18/llvm/IR/Function.h>

class globalScope : public Scope {
public:
    std::unordered_map<std::string, Type*> basic;
    std::unordered_map<std::string, llvm::Function*> funcs;
    std::unordered_map<std::string, classType*> classes;
    std::unordered_map<std::string, int> BuiltinFunc;

    globalScope(Scope* fatherScope = nullptr);
    
    void putBasic(const std::string& name, Type* type);
    Type* getBasic(const std::string& name);
    
    void putFunc(const std::string& name, llvm::Function* func);
    llvm::Function* getFunc(const std::string& name);
    
    void putClass(const std::string& name, classType* cl);
    classType* getClass(const std::string& name);
};
