#pragma once

#include "ASTNode.hpp"
#include "Type.hpp"
#include "ASTVisitor.h"

class typeNode : public ASTNode {
public:
    Type* type;

    typeNode(Position pos, Type* type)
        : ASTNode(pos), type(type) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        return "typeNode(" + type->toString() + ")";
    }
};
