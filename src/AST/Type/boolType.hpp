#pragma once

#include "Type.hpp"

namespace AST {

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

} // namespace AST