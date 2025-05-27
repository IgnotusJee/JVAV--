#pragma once

#include "ASTNode.hpp"
#include "typeNode.hpp"
#include "funcDefNode.hpp"
#include "stmtNode.hpp"
#include "paramNode.hpp"
#include "blockStmtNode.hpp"

class ASTVisitor {
public:
    void visit(ASTNode &node);
    void visit(typeNode &node);
    void visit(funcDefNode &node);
    void visit(stmtNode &node);
    void visit(paramNode &node);
    void visit(blockStmtNode &node);

    // Add more visit methods for other AST node types as needed

};