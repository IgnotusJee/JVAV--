#pragma once

#include <stdexcept>

class SemanticError : public std::runtime_error {
public:
    SemanticError(const std::string& msg)
        : std::runtime_error("Semantic Error: " + msg) {}
};

class InternalError : public std::runtime_error {
public:
    InternalError(const std::string& msg)
        : std::runtime_error("Internal Error: " + msg) {}
};