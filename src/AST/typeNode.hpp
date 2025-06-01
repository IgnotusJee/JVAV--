#pragma once

#include<vector>
#include<string>
#include "Type/Type.hpp"
#include "ASTNode.hpp"
#include "ASTVisitor.h"

class typeNode : public ASTNode{
public:
    Type *type;

    typeNode(Type *type) : type(type) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "paramNode";
    }
};