#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"
#include "ASTVisitor.h"

class prefixUnaryExprNode : public ExprNode{
public:
    
    enum class prefixOpType {
        Inc, Dec, Not, Inv, Sub
    };

    ExprNode *expr;
    prefixOpType opCode;

    prefixUnaryExprNode(ExprNode *expr, prefixOpType opCode) : expr(expr), opCode(opCode) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "prefixUnaryExprNode";
    }
};