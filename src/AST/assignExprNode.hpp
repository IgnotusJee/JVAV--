#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"
#include "ASTVisitor.h"

class assignExprNode : public ExprNode{
public:
    ExprNode *lhs, *rhs;
    assignExprNode(ExprNode *lhs, ExprNode *rhs) : lhs(lhs), rhs(rhs) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "assignExprNode";
    }
};