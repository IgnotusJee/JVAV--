#pragma once

#include<string>
#include "ASTNode.hpp"
#include "ASTVisitor.h"

class defNode : public ASTNode{
public:
    defNode() {}

    std::string toString() const override {
        return "defNode";
    }
};