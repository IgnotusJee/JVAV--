#pragma once

#include <string>
#include <unordered_map>
#include "AST/Type/Type.hpp"

#include <llvm-18/llvm/IR/Value.h>

class Scope {
protected:
    std::unordered_map<std::string, AST::Type*> members;
    std::unordered_map<std::string, llvm::Value*> vars;
    
public:
    Scope* fatherScope;
    bool inloop;

    explicit Scope(Scope* fatherScope = nullptr);
    
    void putType(const std::string& name, AST::Type* type);
    AST::Type* getType(const std::string& name, bool recall);
    
    void putVar(const std::string& name, llvm::Value* var);
    llvm::Value* getVar(const std::string& name, bool recall);
};
