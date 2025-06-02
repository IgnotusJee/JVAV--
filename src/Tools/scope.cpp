#include "Tools/scope.h"
#include "Tools/error.hpp"

Scope::Scope(Scope* fatherScope) 
    : fatherScope(fatherScope), inloop(false)
{
    if (fatherScope) {
        inloop = fatherScope->inloop;
    }
}

void Scope::putType(const std::string& name, AST::Type* type) {
    if (members.find(name) != members.end()) {
        throw SemanticError("variable redefine");
    }
    members[name] = type;
}

AST::Type* Scope::getType(const std::string& name, bool recall) {
    auto it = members.find(name);
    if (it != members.end()) return it->second;
    if (fatherScope && recall) return fatherScope->getType(name, true);
    return nullptr;
}

void Scope::putVar(const std::string& name, llvm::Value* var) {
    if (vars.find(name) != vars.end()) {
        throw InternalError("variable redefine");
    }
    vars[name] = var;
}

llvm::Value* Scope::getVar(const std::string& name, bool recall) {
    auto it = vars.find(name);
    if (it != vars.end()) return it->second;
    if (fatherScope && recall) return fatherScope->getVar(name, true);
    return nullptr;
}
