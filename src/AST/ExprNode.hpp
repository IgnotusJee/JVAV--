#pragma once

#include<string>
#include "ASTNode.hpp"
#include "ASTVisitor.h"
#include "Type/Type.hpp"

class ExprNode : public ASTNode{
public:
    Type *name;
    // Entity entity;
    // varEntity addr;
    bool isAssign, getEntity;

    ExprNode() {
        this->isAssign = false;
        this->getEntity = true;
    }

    std::string toString() const override {
        return "ExprNode";
    }
};