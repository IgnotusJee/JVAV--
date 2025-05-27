#pragma once

#include <string>

#include "Position.hpp"

class ASTVisitor;

class ASTNode {
public:
    Position pos;  // Position in the source code

    ASTNode(Position position = Position())
        : pos(position) {}

    // Accepts a visitor to perform operations on this AST node
    virtual void accept(ASTVisitor &visitor) = 0;

    // Returns a string representation of the AST node
    virtual std::string toString() const = 0;
};