#pragma once

#include "ASTNode.hpp"

class stmtNode : public ASTNode {
public:
    stmtNode(Position pos) : ASTNode(pos) {}
    std::string toString() const override {
        return "stmtNode";
    }
};