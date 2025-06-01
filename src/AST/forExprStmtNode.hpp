#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"
#include "StmtNode.hpp"
#include "ASTVisitor.h"

class forExprStmtNode : public StmtNode{
public:
    ExprNode *init;
    ExprNode *cond;
    ExprNode *step;
    StmtNode *stmt;

    forExprStmtNode(ExprNode *init, ExprNode *cond, ExprNode *step, StmtNode *stmt) : init(init), cond(cond), step(step), stmt(stmt) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "forExprStmtNode";
    }
};