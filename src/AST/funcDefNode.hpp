#pragma once

#include<string>
#include<vector>
#include "typeNode.hpp"
#include "paramNode.hpp"
#include "blockStmtNode.hpp"
#include "defNode.hpp"
#include "ASTVisitor.h"

class funcDefNode : public defNode{
public:
    typeNode *typeName;
    std::string name;
    std::vector<paramNode*> param;
    blockStmtNode *suite;

    funcDefNode(typeNode *typeName, std::string &name, std::vector<paramNode*> param, blockStmtNode *suite) : 
                typeName(typeName), name(name), param(param), suite(suite) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "funcDefNode";
    }
};