#pragma once

#include<string>
#include "ExprNode.hpp"

class constExprNode : public ExprNode{
public:

    constExprNode() {}

    std::string toString() const override {
        return "constExprNode";
    }
};