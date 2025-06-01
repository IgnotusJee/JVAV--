#pragma once

#include<vector>
#include<string>
#include "constExprNode.hpp"
#include "ASTVisitor.h"

class strNode : public constExprNode{
public:
    std::string val;

    strNode(std::string &val) : val(val) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "strNode";
    }
};