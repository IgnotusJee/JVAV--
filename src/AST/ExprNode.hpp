#pragma once

#include <string>
#include "ASTNode.hpp"
#include "ASTVisitor.h"
#include "Type/Type.hpp"
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>

class ExprNode : public ASTNode{
public:
    AST::Type *name;
    llvm::Type* entity;
    llvm::Value* addr;
    bool isLeftVal;

    ExprNode() :name(nullptr), entity(nullptr), addr(nullptr), isLeftVal(false) {}

    std::string toString() const override {
        return "ExprNode";
    }
};