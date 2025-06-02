#pragma once

#include "Type.hpp"

namespace AST {

class intType : public Type {
public:
    intType() : Type("int") {}

    bool equal(const Type &other) const override {
        return other.typeName == "int";
    }

    std::string toString() const override {
        return "int";
    }
};

} // namespace AST