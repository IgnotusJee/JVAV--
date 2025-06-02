#pragma once

#include "Type.hpp"

namespace AST {

class stringType : public Type {
public:
    stringType() : Type("null") {}

    bool equal(const Type &other) const override {
        return other.typeName == "null";
    }

    std::string toString() const override {
        return "stringType";
    }
};

} // namespace AST