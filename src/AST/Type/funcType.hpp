#pragma once

#include "Type.hpp"
#include "funcDefNode.hpp"

class funcType : public Type {
public:
    funcDefNode* func;

    funcType(funcDefNode* func) : Type("func"), func(func) {}

    bool equal(const Type &other) const override {
        return other.typeName == "func" &&
               static_cast<const funcType&>(other).func->returnType->type->equal(*func->returnType->type) &&
               static_cast<const funcType&>(other).func->params.size() == func->params.size() &&
               std::equal(func->params.begin(), func->params.end(),
                          static_cast<const funcType&>(other).func->params.begin(),
                          [](const paramNode* a, const paramNode* b) {
                              return a->type->type->equal(*b->type->type);
                          });
    }

    std::string toString() const override {
        return "func";
    }
};