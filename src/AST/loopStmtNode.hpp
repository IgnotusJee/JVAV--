#pragma once

#include<vector>
#include<string>
#include "StmtNode.hpp"
#include "ASTVisitor.h"

class loopStmtNode : public StmtNode{
public:

    loopStmtNode() {}

    std::string toString() const override {
        return "loopStmtNode";
    }
};