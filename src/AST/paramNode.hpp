#pragma once

#include "ASTNode.hpp"
#include "typeNode.hpp"
#include "ASTVisitor.h"

class paramNode : public ASTNode {
public:
    typeNode* type;
    std::string name;

    paramNode(Position pos, typeNode* type, const std::string& name)
        : ASTNode(pos), type(type), name(name) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        return "paramNode(" + type->toString() + ")";
    }
};
