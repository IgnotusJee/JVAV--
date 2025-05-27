#pragma once

#include "Type.hpp"

class stringType : public Type {
public:
    stringType() : Type("string") {}

    bool equal(const Type &other) const override {
        return other.typeName == "string";
    }

    std::string toString() const override {
        return "string";
    }
};