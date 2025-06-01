#pragma once

#include <string>
#include "ASTVisitor.h"

class ASTNode {
public:

    // Accepts a visitor to perform operations on this AST node
    virtual void accept(ASTVisitor &visitor) = 0;

    // Returns a string representation of the AST node
    virtual std::string toString() const = 0;

    ASTNode* getself() {
        return this;
    }
};