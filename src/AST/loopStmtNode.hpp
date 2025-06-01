#pragma once

#include<vector>
#include<string>
#include "StmtNode.hpp"

class loopStmtNode : public StmtNode{
public:

    loopStmtNode() {}

    std::string toString() const override {
        return "loopStmtNode";
    }
};