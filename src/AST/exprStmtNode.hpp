#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"
#include "StmtNode.hpp"
#include "ASTVisitor.h"

class exprStmtNode : public StmtNode{
public:
    std::vector<ExprNode*> expr;

    exprStmtNode(std::vector<ExprNode*> expr) : expr(expr) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "exprStmtNode";
    }
};