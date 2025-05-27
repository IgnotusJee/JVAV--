#pragma once

#include <list>

#include "defNode.hpp"
#include "typeNode.hpp"
#include "paramNode.hpp"
#include "blockStmtNode.hpp"
#include "ASTVisitor.h"

class funcDefNode : public defNode {
public:
    typeNode* returnType;  // Return type of the function
    std::string funcName;  // Name of the function
    std::list<paramNode*> params;  // List of parameters
    blockStmtNode* body;  // Body of the function

    funcDefNode(Position pos, typeNode* returnType, const std::string& funcName,
                std::list<paramNode*> params, blockStmtNode* body)
        : defNode(pos), returnType(returnType), funcName(funcName),
          params(params), body(body) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        std::string paramsStr;
        for (const auto& param : params) {
            if (!paramsStr.empty()) {
                paramsStr += ", ";
            }
            paramsStr += param->toString();
        }
        return "funcDefNode(" + returnType->toString() + " " + funcName + "(" + paramsStr + "), " + body->toString() + ")";
    }

    ~funcDefNode() {
        delete returnType;
        for (auto param : params) {
            delete param;
        }
        delete body;
    }
};