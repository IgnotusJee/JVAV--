#pragma once

#include<vector>
#include<string>
#include "ExprNode.hpp"

enum class binaryOpType {
    Mul, Div, Mod, Add, Sub,
    Lshift, Rshift, Le, Ge, Leq, Geq,
    Eq, Neq, Bitand, Bitxor, Bitor,
    And, Or
};

class binaryExprNode : public ExprNode{
public:
    ExprNode *lhs, *rhs;
    binaryOpType opCode;

    binaryExprNode(ExprNode *lhs, ExprNode *rhs, binaryOpType opCode) : lhs(lhs), rhs(rhs), opCode(opCode) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(*this);
    }

    std::string toString() const override {
        return "binaryExprNode";
    }
};