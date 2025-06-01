#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"
#include "ASTVisitor.h"
#include "funcExprNode.hpp"

class memberFuncExprNode : public ExprNode{
public:
    ExprNode *expr;
    funcExprNode *func;

    memberFuncExprNode(ExprNode *expr, funcExprNode *func) : expr(expr), func(func) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "memberFuncExprNode";
    }
};