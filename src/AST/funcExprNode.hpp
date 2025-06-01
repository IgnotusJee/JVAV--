#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"
#include "StmtNode.hpp"

class funcExprNode : public ExprNode{
public:
    std::string name;
    std::vector<ExprNode*> args;

    funcExprNode(std::string &name, std::vector<ExprNode*> args) : name(name), args(args) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        return "funcExprNode";
    }
};