#pragma once

#include <list>

#include "stmtNode.hpp"
#include "ASTVisitor.h"

class blockStmtNode : public stmtNode {
public:
    std::list<stmtNode*> stmts;

    bool newScope;
    blockStmtNode(Position pos, std::list<stmtNode*> statements)
        : stmtNode(pos), stmts(statements), newScope(true) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        return "blockStmtNode(" + std::to_string(stmts.size()) + " statements)";
    }
};