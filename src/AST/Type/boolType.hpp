#pragma once

#include "Type.hpp"

class boolType : public Type {
public:
    boolType() : Type("bool") {}

    bool equal(const Type &other) const override {
        return other.typeName == "bool";
    }

    std::string toString() const override {
        return "bool";
    }
};