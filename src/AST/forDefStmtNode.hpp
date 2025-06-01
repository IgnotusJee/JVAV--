#pragma once

#include<vector>
#include<string>
#include "loopStmtNode.hpp"
#include "varDefStmtNode.hpp"
#include "ExprNode.hpp"
#include "StmtNode.hpp"
#include "ASTVisitor.h"

class forDefStmtNode : public loopStmtNode{
public:
    varDefStmtNode *varDef;
    ExprNode *cond;
    ExprNode *step;
    StmtNode *stmt;

    forDefStmtNode(varDefStmtNode *varDef, ExprNode *cond, ExprNode *step, StmtNode *stmt) : varDef(varDef), cond(cond), step(step), stmt(stmt) {}

    void accept(ASTVisitor &visitor) override {
        visitor.visit(this);
    }

    std::string toString() const override {
        return "forDefStmtNode";
    }
};