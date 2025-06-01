#pragma once

#include<vector>
#include<string>
#include "StmtNode.hpp"
#include "varNode.hpp"
#include "typeNode.hpp"

class varDefStmtNode : public StmtNode{
public:
    typeNode *typeName;
    std::vector<varNode*> var;

    varDefStmtNode(typeNode *typeName, std::vector<varNode*> var) : typeName(typeName), var(var) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        return "varDefStmtNode";
    }
};