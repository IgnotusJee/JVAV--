#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"
#include "StmtNode.hpp"
#include "loopStmtNode.hpp"
#include "ASTVisitor.h"

class whileStmtNode : public loopStmtNode{
public:
    ExprNode *cond;
    StmtNode *stmt;

    whileStmtNode(ExprNode *cond, StmtNode *stmt) : cond(cond), stmt(stmt) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "whileStmtNode";
    }
};