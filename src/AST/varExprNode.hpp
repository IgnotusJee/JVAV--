#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"
#include "ASTVisitor.h"

class varExprNode : public ExprNode{
public:
    std::string name;

    varExprNode(std::string &name) : name(name) {
        this->isLeftVal = true;
    }

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "varExprNode";
    }
};