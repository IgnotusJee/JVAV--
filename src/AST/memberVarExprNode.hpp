#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"
#include "ASTVisitor.h"

class memberVarExprNode : public ExprNode{
public:
    ExprNode *expr; // 产生对象的表达式
    std::string name; // 类成员名称

    memberVarExprNode(ExprNode *expr, std::string &name) : expr(expr), name(name) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "memberVarExprNode";
    }
};