#pragma once

#include <utility>
#include<vector>
#include<string>
#include "defNode.hpp"
#include "typeNode.hpp"
#include "varNode.hpp"
#include "ASTVisitor.h"

class varDefNode : public defNode{
public:
    typeNode *typeName;
    std::vector<varNode*> var;

    varDefNode(typeNode *typeName, std::vector<varNode*> var) : typeName(typeName), var(std::move(var)) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "varDefNode";
    }
};