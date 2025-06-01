#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"

class varExprNode : public ExprNode{
public:
    std::string name;

    varExprNode(std::string &name) : name(name) {
        this->isAssign = true;
    }

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        return "varExprNode";
    }
};