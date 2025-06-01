#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"
#include "ASTNode.hpp"
#include "ASTVisitor.h"

class varNode : public ASTNode{
public:
    std::string name;
    ExprNode *init;

    varNode(std::string &name, ExprNode *init) : name(name), init(init) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "varNode";
    }
};