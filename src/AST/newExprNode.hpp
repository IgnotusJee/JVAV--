#pragma once

#include<vector>
#include<string>
#include "Type/Type.hpp"
#include "ExprNode.hpp"
#include "ASTVisitor.h"

class newExprNode : public ExprNode{
public:
    Type *typeName;
    std::vector<ExprNode*> expr;
    int dim;

    newExprNode(Type *typeName, std::vector<ExprNode*> expr, int dim) : typeName(typeName), expr(expr), dim(dim) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "newExprNode";
    }
};