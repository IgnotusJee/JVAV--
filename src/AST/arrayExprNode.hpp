#pragma once

#include<string>
#include "ExprNode.hpp"

class arrayExprNode : public ExprNode{
public:
    ExprNode *name;
    ExprNode *index;

    arrayExprNode(ExprNode *name, ExprNode *index)
        : name(name), index(index) {
        this->isAssign = true;
    }

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        return "arrayExprNode";
    }
};