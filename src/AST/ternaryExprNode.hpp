#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"
#include "ASTVisitor.h"

class ternaryExprNode : public ExprNode{
public:
    ExprNode *cond, *thenExpr, *elseExpr;

    ternaryExprNode(ExprNode *cond, ExprNode *thenExpr, ExprNode *elseExpr) : cond(cond), thenExpr(thenExpr), elseExpr(elseExpr) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "ternaryExprNode";
    }
};