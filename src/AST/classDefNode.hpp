#pragma once

#include<vector>
#include<string>
#include "defNode.hpp"
#include "varDefNode.hpp"
#include "funcDefNode.hpp"
#include "ASTVisitor.h"

class classDefNode : public defNode{
public:
    std::string name;
    std::vector<varDefNode*> varDef;
    std::vector<funcDefNode*> funcDef;

    classDefNode(std::string &name, std::vector<varDefNode*> varDef, std::vector<funcDefNode*> funcDef) : name(name), varDef(varDef), funcDef(funcDef) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "classDefNode";
    }
};