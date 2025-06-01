#pragma once

#include<vector>
#include<string>
#include "flowStmtNode.hpp"
#include "ASTVisitor.h"

class breakStmtNode : public flowStmtNode{
public:

    breakStmtNode() {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "breakStmtNode";
    }
};