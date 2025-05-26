
// Generated from ./JvavParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "JvavParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by JvavParser.
 */
class  JvavParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by JvavParser.
   */
    virtual std::any visitProgram(JvavParser::ProgramContext *context) = 0;

    virtual std::any visitFunc_def(JvavParser::Func_defContext *context) = 0;

    virtual std::any visitTypedargslist(JvavParser::TypedargslistContext *context) = 0;

    virtual std::any visitArgslist(JvavParser::ArgslistContext *context) = 0;

    virtual std::any visitClass_def(JvavParser::Class_defContext *context) = 0;

    virtual std::any visitClass_suite(JvavParser::Class_suiteContext *context) = 0;

    virtual std::any visitConstruct_stmt(JvavParser::Construct_stmtContext *context) = 0;

    virtual std::any visitVar_def(JvavParser::Var_defContext *context) = 0;

    virtual std::any visitVar_stmt(JvavParser::Var_stmtContext *context) = 0;

    virtual std::any visitSuite(JvavParser::SuiteContext *context) = 0;

    virtual std::any visitBlock(JvavParser::BlockContext *context) = 0;

    virtual std::any visitVarDefStmt(JvavParser::VarDefStmtContext *context) = 0;

    virtual std::any visitBranchStmt(JvavParser::BranchStmtContext *context) = 0;

    virtual std::any visitLoopStmt(JvavParser::LoopStmtContext *context) = 0;

    virtual std::any visitFlowStmt(JvavParser::FlowStmtContext *context) = 0;

    virtual std::any visitExprStmt(JvavParser::ExprStmtContext *context) = 0;

    virtual std::any visitBranch_stmt(JvavParser::Branch_stmtContext *context) = 0;

    virtual std::any visitLoop_stmt(JvavParser::Loop_stmtContext *context) = 0;

    virtual std::any visitWhile_stmt(JvavParser::While_stmtContext *context) = 0;

    virtual std::any visitFor_stmt(JvavParser::For_stmtContext *context) = 0;

    virtual std::any visitFlow_stmt(JvavParser::Flow_stmtContext *context) = 0;

    virtual std::any visitReturn_stmt(JvavParser::Return_stmtContext *context) = 0;

    virtual std::any visitBreak_stmt(JvavParser::Break_stmtContext *context) = 0;

    virtual std::any visitContinue_stmt(JvavParser::Continue_stmtContext *context) = 0;

    virtual std::any visitExpr_stmt(JvavParser::Expr_stmtContext *context) = 0;

    virtual std::any visitNewExpr(JvavParser::NewExprContext *context) = 0;

    virtual std::any visitThisExpr(JvavParser::ThisExprContext *context) = 0;

    virtual std::any visitFuncExpr(JvavParser::FuncExprContext *context) = 0;

    virtual std::any visitArrayExpr(JvavParser::ArrayExprContext *context) = 0;

    virtual std::any visitMemberExpr(JvavParser::MemberExprContext *context) = 0;

    virtual std::any visitBinaryExpr(JvavParser::BinaryExprContext *context) = 0;

    virtual std::any visitPrefixUnaryExpr(JvavParser::PrefixUnaryExprContext *context) = 0;

    virtual std::any visitVarExpr(JvavParser::VarExprContext *context) = 0;

    virtual std::any visitTernaryExpr(JvavParser::TernaryExprContext *context) = 0;

    virtual std::any visitPureExpr(JvavParser::PureExprContext *context) = 0;

    virtual std::any visitAssignExpr(JvavParser::AssignExprContext *context) = 0;

    virtual std::any visitSuffixUnaryExpr(JvavParser::SuffixUnaryExprContext *context) = 0;

    virtual std::any visitConstExpr(JvavParser::ConstExprContext *context) = 0;

    virtual std::any visitConst_expr(JvavParser::Const_exprContext *context) = 0;

    virtual std::any visitFunc_expr(JvavParser::Func_exprContext *context) = 0;

    virtual std::any visitNew_expr(JvavParser::New_exprContext *context) = 0;

    virtual std::any visitNewerror_expr(JvavParser::Newerror_exprContext *context) = 0;

    virtual std::any visitNewvar_expr(JvavParser::Newvar_exprContext *context) = 0;

    virtual std::any visitTypename(JvavParser::TypenameContext *context) = 0;

    virtual std::any visitBasic_type(JvavParser::Basic_typeContext *context) = 0;


};

