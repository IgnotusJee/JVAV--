#pragma once

#include<vector>
#include<string>
#include "flowStmtNode.hpp"
#include "ASTVisitor.h"

class continueStmtNode : public flowStmtNode{
public:

    continueStmtNode() {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "continueStmtNode";
    }
};