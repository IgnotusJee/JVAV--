#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"
#include "StmtNode.hpp"
#include "ASTVisitor.h"

class branchStmtNode : public StmtNode{
public:
    std::vector<ExprNode*> cond;
    std::vector<StmtNode*> Stmt;

    branchStmtNode(std::vector<ExprNode*> cond, std::vector<StmtNode*> Stmt) : cond(cond), Stmt(Stmt) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "branchStmtNode";
    }
};