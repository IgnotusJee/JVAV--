#pragma once

#include <map>
#include <vector>
#include <string>

#include <llvm/IR/Value.h>

class SymbolTable {
private:
    struct Scope {
        std::map<std::string, llvm::Value*> symbols;
        std::map<std::string, llvm::Type*> types;
    };

    std::vector<Scope> scopes;

public:
    SymbolTable() {
        push(); // 创建全局作用域
    }

    void push() {
        scopes.push_back(Scope());
    }

    void pop() {
        if (!scopes.empty()) {
            scopes.pop_back();
        }
    }

    void addValue(const std::string& name, llvm::Value* value) {
        if (scopes.empty()) push();
        scopes.back().symbols[name] = value;
    }

    void addType(const std::string& name, llvm::Type* type) {
        if (scopes.empty()) push();
        scopes.back().types[name] = type;
    }

    llvm::Value* findValue(const std::string& name) {
        for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
            auto entry = it->symbols.find(name);
            if (entry != it->symbols.end()) {
                return entry->second;
            }
        }
        return nullptr;
    }

    llvm::Type* findType(const std::string& name) {
        for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
            auto entry = it->types.find(name);
            if (entry != it->types.end()) {
                return entry->second;
            }
        }
        return nullptr;
    }
};
