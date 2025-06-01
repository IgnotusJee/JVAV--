#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"

class thisExprNode : public ExprNode{
public:

    thisExprNode() {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        return "thisExprNode";
    }
};