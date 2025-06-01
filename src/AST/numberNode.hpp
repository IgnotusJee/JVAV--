#pragma once

#include<vector>
#include<string>
#include "constExprNode.hpp"

class numberNode : public constExprNode{
public:
    long long val;

    numberNode(long long val) : val(val) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        return "numberNode";
    }
};