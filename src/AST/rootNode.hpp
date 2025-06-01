#pragma once

#include<vector>
#include<string>
#include"defNode.hpp"
#include "ASTVisitor.h"

class rootNode : public ASTNode{
public:
    std::vector<defNode*> Def;

    rootNode(std::vector<defNode*> Def) : Def(Def) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "rootNode";
    }
};