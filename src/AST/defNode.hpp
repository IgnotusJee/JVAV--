#pragma once

#include "ASTNode.hpp"

class defNode : public ASTNode {
public:
    defNode(Position pos) : ASTNode(pos) {}

    std::string toString() const override {
        return "defNode";
    }
};