#pragma once

#include<string>
#include "ASTNode.hpp"
#include "ASTVisitor.h"

class StmtNode : public ASTNode{
public:

    StmtNode() {}

    std::string toString() const override {
        return "StmtNode";
    }
};