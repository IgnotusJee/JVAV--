
// Generated from ./JvavParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "JvavParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by JvavParser.
 */
class  JvavParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(JvavParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(JvavParser::ProgramContext *ctx) = 0;

  virtual void enterFunc_def(JvavParser::Func_defContext *ctx) = 0;
  virtual void exitFunc_def(JvavParser::Func_defContext *ctx) = 0;

  virtual void enterTypedargslist(JvavParser::TypedargslistContext *ctx) = 0;
  virtual void exitTypedargslist(JvavParser::TypedargslistContext *ctx) = 0;

  virtual void enterArgslist(JvavParser::ArgslistContext *ctx) = 0;
  virtual void exitArgslist(JvavParser::ArgslistContext *ctx) = 0;

  virtual void enterClass_def(JvavParser::Class_defContext *ctx) = 0;
  virtual void exitClass_def(JvavParser::Class_defContext *ctx) = 0;

  virtual void enterClass_suite(JvavParser::Class_suiteContext *ctx) = 0;
  virtual void exitClass_suite(JvavParser::Class_suiteContext *ctx) = 0;

  virtual void enterConstruct_stmt(JvavParser::Construct_stmtContext *ctx) = 0;
  virtual void exitConstruct_stmt(JvavParser::Construct_stmtContext *ctx) = 0;

  virtual void enterVar_def(JvavParser::Var_defContext *ctx) = 0;
  virtual void exitVar_def(JvavParser::Var_defContext *ctx) = 0;

  virtual void enterVar_stmt(JvavParser::Var_stmtContext *ctx) = 0;
  virtual void exitVar_stmt(JvavParser::Var_stmtContext *ctx) = 0;

  virtual void enterSuite(JvavParser::SuiteContext *ctx) = 0;
  virtual void exitSuite(JvavParser::SuiteContext *ctx) = 0;

  virtual void enterBlock(JvavParser::BlockContext *ctx) = 0;
  virtual void exitBlock(JvavParser::BlockContext *ctx) = 0;

  virtual void enterVarDefStmt(JvavParser::VarDefStmtContext *ctx) = 0;
  virtual void exitVarDefStmt(JvavParser::VarDefStmtContext *ctx) = 0;

  virtual void enterBranchStmt(JvavParser::BranchStmtContext *ctx) = 0;
  virtual void exitBranchStmt(JvavParser::BranchStmtContext *ctx) = 0;

  virtual void enterLoopStmt(JvavParser::LoopStmtContext *ctx) = 0;
  virtual void exitLoopStmt(JvavParser::LoopStmtContext *ctx) = 0;

  virtual void enterFlowStmt(JvavParser::FlowStmtContext *ctx) = 0;
  virtual void exitFlowStmt(JvavParser::FlowStmtContext *ctx) = 0;

  virtual void enterExprStmt(JvavParser::ExprStmtContext *ctx) = 0;
  virtual void exitExprStmt(JvavParser::ExprStmtContext *ctx) = 0;

  virtual void enterBranch_stmt(JvavParser::Branch_stmtContext *ctx) = 0;
  virtual void exitBranch_stmt(JvavParser::Branch_stmtContext *ctx) = 0;

  virtual void enterLoop_stmt(JvavParser::Loop_stmtContext *ctx) = 0;
  virtual void exitLoop_stmt(JvavParser::Loop_stmtContext *ctx) = 0;

  virtual void enterWhile_stmt(JvavParser::While_stmtContext *ctx) = 0;
  virtual void exitWhile_stmt(JvavParser::While_stmtContext *ctx) = 0;

  virtual void enterFor_stmt(JvavParser::For_stmtContext *ctx) = 0;
  virtual void exitFor_stmt(JvavParser::For_stmtContext *ctx) = 0;

  virtual void enterFlow_stmt(JvavParser::Flow_stmtContext *ctx) = 0;
  virtual void exitFlow_stmt(JvavParser::Flow_stmtContext *ctx) = 0;

  virtual void enterReturn_stmt(JvavParser::Return_stmtContext *ctx) = 0;
  virtual void exitReturn_stmt(JvavParser::Return_stmtContext *ctx) = 0;

  virtual void enterBreak_stmt(JvavParser::Break_stmtContext *ctx) = 0;
  virtual void exitBreak_stmt(JvavParser::Break_stmtContext *ctx) = 0;

  virtual void enterContinue_stmt(JvavParser::Continue_stmtContext *ctx) = 0;
  virtual void exitContinue_stmt(JvavParser::Continue_stmtContext *ctx) = 0;

  virtual void enterExpr_stmt(JvavParser::Expr_stmtContext *ctx) = 0;
  virtual void exitExpr_stmt(JvavParser::Expr_stmtContext *ctx) = 0;

  virtual void enterNewExpr(JvavParser::NewExprContext *ctx) = 0;
  virtual void exitNewExpr(JvavParser::NewExprContext *ctx) = 0;

  virtual void enterThisExpr(JvavParser::ThisExprContext *ctx) = 0;
  virtual void exitThisExpr(JvavParser::ThisExprContext *ctx) = 0;

  virtual void enterFuncExpr(JvavParser::FuncExprContext *ctx) = 0;
  virtual void exitFuncExpr(JvavParser::FuncExprContext *ctx) = 0;

  virtual void enterArrayExpr(JvavParser::ArrayExprContext *ctx) = 0;
  virtual void exitArrayExpr(JvavParser::ArrayExprContext *ctx) = 0;

  virtual void enterMemberExpr(JvavParser::MemberExprContext *ctx) = 0;
  virtual void exitMemberExpr(JvavParser::MemberExprContext *ctx) = 0;

  virtual void enterBinaryExpr(JvavParser::BinaryExprContext *ctx) = 0;
  virtual void exitBinaryExpr(JvavParser::BinaryExprContext *ctx) = 0;

  virtual void enterPrefixUnaryExpr(JvavParser::PrefixUnaryExprContext *ctx) = 0;
  virtual void exitPrefixUnaryExpr(JvavParser::PrefixUnaryExprContext *ctx) = 0;

  virtual void enterVarExpr(JvavParser::VarExprContext *ctx) = 0;
  virtual void exitVarExpr(JvavParser::VarExprContext *ctx) = 0;

  virtual void enterTernaryExpr(JvavParser::TernaryExprContext *ctx) = 0;
  virtual void exitTernaryExpr(JvavParser::TernaryExprContext *ctx) = 0;

  virtual void enterPureExpr(JvavParser::PureExprContext *ctx) = 0;
  virtual void exitPureExpr(JvavParser::PureExprContext *ctx) = 0;

  virtual void enterAssignExpr(JvavParser::AssignExprContext *ctx) = 0;
  virtual void exitAssignExpr(JvavParser::AssignExprContext *ctx) = 0;

  virtual void enterSuffixUnaryExpr(JvavParser::SuffixUnaryExprContext *ctx) = 0;
  virtual void exitSuffixUnaryExpr(JvavParser::SuffixUnaryExprContext *ctx) = 0;

  virtual void enterConstExpr(JvavParser::ConstExprContext *ctx) = 0;
  virtual void exitConstExpr(JvavParser::ConstExprContext *ctx) = 0;

  virtual void enterConst_expr(JvavParser::Const_exprContext *ctx) = 0;
  virtual void exitConst_expr(JvavParser::Const_exprContext *ctx) = 0;

  virtual void enterFunc_expr(JvavParser::Func_exprContext *ctx) = 0;
  virtual void exitFunc_expr(JvavParser::Func_exprContext *ctx) = 0;

  virtual void enterNew_expr(JvavParser::New_exprContext *ctx) = 0;
  virtual void exitNew_expr(JvavParser::New_exprContext *ctx) = 0;

  virtual void enterNewerror_expr(JvavParser::Newerror_exprContext *ctx) = 0;
  virtual void exitNewerror_expr(JvavParser::Newerror_exprContext *ctx) = 0;

  virtual void enterNewvar_expr(JvavParser::Newvar_exprContext *ctx) = 0;
  virtual void exitNewvar_expr(JvavParser::Newvar_exprContext *ctx) = 0;

  virtual void enterTypename(JvavParser::TypenameContext *ctx) = 0;
  virtual void exitTypename(JvavParser::TypenameContext *ctx) = 0;

  virtual void enterBasic_type(JvavParser::Basic_typeContext *ctx) = 0;
  virtual void exitBasic_type(JvavParser::Basic_typeContext *ctx) = 0;


};

