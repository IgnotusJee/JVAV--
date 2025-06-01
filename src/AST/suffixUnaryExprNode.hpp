#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"

enum class suffixOpType {
    Inc, Dec
};

class suffixUnaryExprNode : public ExprNode{
public:
    ExprNode *expr;
    suffixOpType opCode;

    suffixUnaryExprNode(ExprNode *expr, suffixOpType opCode) : expr(expr), opCode(opCode) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        return "suffixUnaryExprNode";
    }
};