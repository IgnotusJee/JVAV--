#pragma once

#include <string>

namespace AST {

class Type {
public:
    std::string typeName;

    Type(const std::string& name) : typeName(name) {}

    virtual bool equal(const Type &) const = 0;
    virtual std::string toString() const = 0;
};

}

