#pragma once

#include<string>
#include "StmtNode.hpp"
#include "ASTVisitor.h"

class flowStmtNode : public StmtNode{
public:

    flowStmtNode() {}

    std::string toString() const override {
        return "flowStmtNode";
    }
};