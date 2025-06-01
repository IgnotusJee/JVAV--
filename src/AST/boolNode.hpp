#pragma once

#include<string>
#include "constExprNode.hpp"

class boolNode : public constExprNode{
public:
    bool val;

    boolNode(bool val) : val(val) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        return "boolNode";
    }
};