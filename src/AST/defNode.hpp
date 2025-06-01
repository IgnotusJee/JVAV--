#pragma once

#include<string>
#include "ASTNode.hpp"

class defNode : public ASTNode{
public:
    defNode() {}

    std::string toString() const override {
        return "defNode";
    }
};