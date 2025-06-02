#pragma once

#include <list>
#include "Type.hpp"

namespace AST {

class classType : public Type {
public:
    std::string className;
    std::list<Type*> memberTypes;

    classType(std::string className) : Type("class"), className(className) {}

    bool equal(const Type &other) const override {
        return other.typeName == "class" && 
                static_cast<const classType&>(other).className == className;
    }

    std::string toString() const override {
        return "class<" + className + ">";
    }
};

} // namespace AST