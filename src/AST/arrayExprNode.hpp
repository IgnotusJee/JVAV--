#pragma once

#include<string>
#include "ASTVisitor.h"
#include "ExprNode.hpp"

class arrayExprNode : public ExprNode{
public:
    ExprNode *name; // 生成数组地址的表达式
    ExprNode *index; // 计算数组索引的表达式

    arrayExprNode(ExprNode *name, ExprNode *index)
        : name(name), index(index) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "arrayExprNode";
    }
};