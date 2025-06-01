#pragma once

#include<vector>
#include<string>
#include "defNode.hpp"
#include "typeNode.hpp"
#include "varNode.hpp"

class varDefNode : public defNode{
public:
    typeNode *typeName;
    std::vector<varNode*> var;

    varDefNode(typeNode *typeName, std::vector<varNode*> var) : typeName(typeName), var(var) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        return "varDefNode";
    }
};