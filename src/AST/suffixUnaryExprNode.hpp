#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"
#include "ASTVisitor.h"

class suffixUnaryExprNode : public ExprNode{
public:

    enum class suffixOpType {
        Inc, Dec
    };

    ExprNode *expr;
    suffixOpType opCode;

    suffixUnaryExprNode(ExprNode *expr, suffixOpType opCode) : expr(expr), opCode(opCode) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "suffixUnaryExprNode";
    }
};