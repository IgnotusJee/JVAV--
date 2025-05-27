#pragma once

#include "Type.hpp"

class nullType : public Type {
public:
    nullType() : Type("null") {}

    bool equal(const Type &other) const override {
        return other.typeName == "null";
    }

    std::string toString() const override {
        return "null";
    }
};