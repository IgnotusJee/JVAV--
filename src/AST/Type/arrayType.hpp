#pragma once

#include "Type.hpp"

namespace AST {

class arrayType : public Type {
public:
    Type* elemType;
    int dim;

    arrayType(Type* elemType, int dim) : Type("array"), elemType(elemType), dim(dim) {}

    bool equal(const Type &other) const override {
        return other.typeName == "array" && 
               static_cast<const arrayType&>(other).elemType->equal(*elemType) &&
               static_cast<const arrayType&>(other).dim == dim;
    }

    std::string toString() const override {
        return "array<" + elemType->toString() + ", " + std::to_string(dim) + ">";
    }
};

} // namespace AST