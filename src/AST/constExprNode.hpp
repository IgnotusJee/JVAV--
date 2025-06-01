#pragma once

#include<string>
#include "ExprNode.hpp"
#include "ASTVisitor.h"

class constExprNode : public ExprNode{
public:

    constExprNode() {}

    std::string toString() const override {
        return "constExprNode";
    }
};