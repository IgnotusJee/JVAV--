#pragma once

#include "Type.hpp"

namespace AST {

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

} // namespace AST