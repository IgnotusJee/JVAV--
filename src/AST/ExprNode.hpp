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
    bool isLeftVal, isArray; // 当是左值时，addr记录的是左值的地址；当是数组时，entity记录的是数组的元素类型

    ExprNode() :name(nullptr), entity(nullptr), addr(nullptr), isLeftVal(false), isArray(false) {}

    std::string toString() const override {
        return "ExprNode";
    }
};