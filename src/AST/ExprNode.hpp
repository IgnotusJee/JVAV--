#pragma once

#include <string>
#include "ASTNode.hpp"
#include "ASTVisitor.h"
#include "Type/Type.hpp"
#include <llvm-18/llvm/IR/Type.h>
#include <llvm-18/llvm/IR/Value.h>

class ExprNode : public ASTNode{
public:
    AST::Type *name;
    llvm::Type* entity;
    llvm::Value* addr;
    bool isAssign, getEntity;

    ExprNode() :entity(nullptr), addr(nullptr) {
        this->isAssign = false;
        this->getEntity = true;
    }

    std::string toString() const override {
        return "ExprNode";
    }
};