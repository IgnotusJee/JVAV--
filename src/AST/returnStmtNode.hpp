#pragma once

#include<vector>
#include<string>
#include "flowStmtNode.hpp"
#include "ExprNode.hpp"

class returnStmtNode : public flowStmtNode{
public:
    ExprNode *ret;

    returnStmtNode(ExprNode *ret) : ret(ret) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        return "returnStmtNode";
    }
};