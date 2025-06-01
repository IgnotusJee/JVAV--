#pragma once

#include<vector>
#include<string>
#include "ASTNode.hpp"
#include "typeNode.hpp"

class paramNode : public ASTNode{
public:
    typeNode *typeName;
    std::string name;

    paramNode(typeNode *typeName, std::string &name) : typeName(typeName), name(name) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        return "paramNode";
    }
};