
// Generated from ./JvavParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "JvavParserVisitor.h"


/**
 * This class provides an empty implementation of JvavParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  JvavParserBaseVisitor : public JvavParserVisitor {
public:

  virtual std::any visitProgram(JvavParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_def(JvavParser::Func_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypedargslist(JvavParser::TypedargslistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgslist(JvavParser::ArgslistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_def(JvavParser::Class_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass_suite(JvavParser::Class_suiteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstruct_stmt(JvavParser::Construct_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_def(JvavParser::Var_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_stmt(JvavParser::Var_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSuite(JvavParser::SuiteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(JvavParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDefStmt(JvavParser::VarDefStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBranchStmt(JvavParser::BranchStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoopStmt(JvavParser::LoopStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFlowStmt(JvavParser::FlowStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprStmt(JvavParser::ExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBranch_stmt(JvavParser::Branch_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoop_stmt(JvavParser::Loop_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile_stmt(JvavParser::While_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_stmt(JvavParser::For_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFlow_stmt(JvavParser::Flow_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn_stmt(JvavParser::Return_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreak_stmt(JvavParser::Break_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinue_stmt(JvavParser::Continue_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_stmt(JvavParser::Expr_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewExpr(JvavParser::NewExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitThisExpr(JvavParser::ThisExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncExpr(JvavParser::FuncExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayExpr(JvavParser::ArrayExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemberExpr(JvavParser::MemberExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryExpr(JvavParser::BinaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrefixUnaryExpr(JvavParser::PrefixUnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarExpr(JvavParser::VarExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTernaryExpr(JvavParser::TernaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPureExpr(JvavParser::PureExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignExpr(JvavParser::AssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSuffixUnaryExpr(JvavParser::SuffixUnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstExpr(JvavParser::ConstExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConst_expr(JvavParser::Const_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_expr(JvavParser::Func_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNew_expr(JvavParser::New_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewerror_expr(JvavParser::Newerror_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewvar_expr(JvavParser::Newvar_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypename(JvavParser::TypenameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBasic_type(JvavParser::Basic_typeContext *ctx) override {
    return visitChildren(ctx);
  }


};

