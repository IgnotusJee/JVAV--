#pragma once

class rootNode;
class varDefNode;
class classDefNode;
class funcDefNode;
class varNode;
class paramNode;
class varDefStmtNode;
class blockStmtNode;
class branchStmtNode;
class exprStmtNode;
class whileStmtNode;
class forDefStmtNode;
class forExprStmtNode;
class returnStmtNode;
class breakStmtNode;
class continueStmtNode;
class varExprNode;
class thisExprNode;
class funcExprNode;
class memberVarExprNode;
class memberFuncExprNode;
class arrayExprNode;
class newExprNode;
class prefixUnaryExprNode;
class suffixUnaryExprNode;
class binaryExprNode;
class ternaryExprNode;
class assignExprNode;
class boolNode;
class numberNode;
class strNode;
class nullNode;
class typeNode;

// 访问者接口
class ASTVisitor {
public:
    virtual ~ASTVisitor() = default;  // 虚析构函数确保多态删除安全

    virtual void visit(rootNode *it) = 0;
    virtual void visit(varDefNode *it) = 0;
    virtual void visit(classDefNode *it) = 0;
    virtual void visit(funcDefNode *it) = 0;
    virtual void visit(varNode *it) = 0;
    virtual void visit(paramNode *it) = 0;
    virtual void visit(varDefStmtNode *it) = 0;
    virtual void visit(blockStmtNode *it) = 0;
    virtual void visit(branchStmtNode *it) = 0;
    virtual void visit(exprStmtNode *it) = 0;
    virtual void visit(whileStmtNode *it) = 0;
    virtual void visit(forDefStmtNode *it) = 0;
    virtual void visit(forExprStmtNode *it) = 0;
    virtual void visit(returnStmtNode *it) = 0;
    virtual void visit(breakStmtNode *it) = 0;
    virtual void visit(continueStmtNode *it) = 0;
    virtual void visit(varExprNode *it) = 0;
    virtual void visit(thisExprNode *it) = 0;
    virtual void visit(funcExprNode *it) = 0;
    virtual void visit(memberVarExprNode *it) = 0;
    virtual void visit(memberFuncExprNode *it) = 0;
    virtual void visit(arrayExprNode *it) = 0;
    virtual void visit(newExprNode *it) = 0;
    virtual void visit(prefixUnaryExprNode *it) = 0;
    virtual void visit(suffixUnaryExprNode *it) = 0;
    virtual void visit(binaryExprNode *it) = 0;
    virtual void visit(ternaryExprNode *it) = 0;
    virtual void visit(assignExprNode *it) = 0;
    virtual void visit(boolNode *it) = 0;
    virtual void visit(numberNode *it) = 0;
    virtual void visit(strNode *it) = 0;
    virtual void visit(nullNode *it) = 0;
    virtual void visit(typeNode *it) = 0;
};
