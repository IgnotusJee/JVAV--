#pragma once

#include "Type.hpp"

namespace AST {

class voidType : public Type {
public:
    voidType() : Type("void") {}

    bool equal(const Type &other) const override {
        return other.typeName == "void";
    }

    std::string toString() const override {
        return "void";
    }
};

} // namespace AST