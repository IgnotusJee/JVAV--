#pragma once

#include<string>
#include "StmtNode.hpp"

class flowStmtNode : public StmtNode{
public:

    flowStmtNode() {}

    std::string toString() const override {
        return "flowStmtNode";
    }
};