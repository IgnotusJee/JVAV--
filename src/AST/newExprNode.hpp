#pragma once

#include <utility>
#include<vector>
#include<string>
#include "Type/Type.hpp"
#include "ExprNode.hpp"
#include "ASTVisitor.h"

class newExprNode : public ExprNode{
public:
    AST::Type *typeName; // 要新建的类型名
    std::vector<ExprNode*> exprs; //数组创建每一位的大小
    int dim;

    newExprNode(AST::Type *typeName, std::vector<ExprNode*> expr, int dim) : typeName(typeName), exprs(std::move(expr)), dim(dim) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "newExprNode";
    }
};