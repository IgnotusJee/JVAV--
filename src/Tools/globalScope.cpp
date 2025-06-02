#include "Tools/globalScope.h"
#include "Tools/error.hpp"

globalScope::globalScope(Scope* fatherScope)
    : Scope(fatherScope)
{
    // Constructor handles initialization via base class
}

void globalScope::putBasic(const std::string& name, AST::Type* type) {
    if (basic.find(name) != basic.end()) {
        throw SemanticError("multiple definition of " + name);
    }
    basic[name] = type;
}

AST::Type* globalScope::getBasic(const std::string& name) {
    auto it = basic.find(name);
    return it != basic.end() ? it->second : nullptr;
}

void globalScope::putFunc(const std::string& name, llvm::Function* func) {
    if (funcs.find(name) != funcs.end()) {
        throw InternalError("multiple definition of " + name);
    }
    funcs[name] = func;
}

llvm::Function* globalScope::getFunc(const std::string& name) {
    auto it = funcs.find(name);
    return it != funcs.end() ? it->second : nullptr;
}

void globalScope::putClass(const std::string& name, llvm::StructType* cl) {
    if (classes.find(name) != classes.end()) {
        throw InternalError("multiple definition of " + name);
    }
    classes[name] = cl;
}

llvm::StructType* globalScope::getClass(const std::string& name) {
    auto it = classes.find(name);
    return it != classes.end() ? it->second : nullptr;
}
