#pragma once

#include "Type.hpp"
#include "../funcDefNode.hpp"
#include "../paramNode.hpp"

namespace AST {

class funcType : public Type {
public:
    funcDefNode* func;

    funcType(funcDefNode* func) : Type("func"), func(func) {}

    bool equal(const Type &other) const override {
        return other.typeName == "func" &&
               static_cast<const funcType&>(other).func->typeName->type->equal(*func->typeName->type) &&
               static_cast<const funcType&>(other).func->param.size() == func->param.size() &&
               std::equal(func->param.begin(), func->param.end(),
                          static_cast<const funcType&>(other).func->param.begin(),
                          [](const paramNode* a, const paramNode* b) {
                              return a->typeName->type->equal(*b->typeName->type);
                          });
    }

    std::string toString() const override {
        return "func";
    }
};

} // namespace AST