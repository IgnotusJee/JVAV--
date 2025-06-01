#pragma once

#include<string>
#include<vector>
#include "StmtNode.hpp"
#include "ASTVisitor.h"

class blockStmtNode : public StmtNode{
public:

    std::vector<StmtNode*> stmt;
    bool newScope;

    blockStmtNode(std::vector<StmtNode*> stmt) : stmt(stmt), newScope(true) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "blockStmtNode";
    }
};