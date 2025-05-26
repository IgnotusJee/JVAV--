
// Generated from ./JvavParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "JvavParserListener.h"


/**
 * This class provides an empty implementation of JvavParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  JvavParserBaseListener : public JvavParserListener {
public:

  virtual void enterProgram(JvavParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(JvavParser::ProgramContext * /*ctx*/) override { }

  virtual void enterFunc_def(JvavParser::Func_defContext * /*ctx*/) override { }
  virtual void exitFunc_def(JvavParser::Func_defContext * /*ctx*/) override { }

  virtual void enterTypedargslist(JvavParser::TypedargslistContext * /*ctx*/) override { }
  virtual void exitTypedargslist(JvavParser::TypedargslistContext * /*ctx*/) override { }

  virtual void enterArgslist(JvavParser::ArgslistContext * /*ctx*/) override { }
  virtual void exitArgslist(JvavParser::ArgslistContext * /*ctx*/) override { }

  virtual void enterClass_def(JvavParser::Class_defContext * /*ctx*/) override { }
  virtual void exitClass_def(JvavParser::Class_defContext * /*ctx*/) override { }

  virtual void enterClass_suite(JvavParser::Class_suiteContext * /*ctx*/) override { }
  virtual void exitClass_suite(JvavParser::Class_suiteContext * /*ctx*/) override { }

  virtual void enterConstruct_stmt(JvavParser::Construct_stmtContext * /*ctx*/) override { }
  virtual void exitConstruct_stmt(JvavParser::Construct_stmtContext * /*ctx*/) override { }

  virtual void enterVar_def(JvavParser::Var_defContext * /*ctx*/) override { }
  virtual void exitVar_def(JvavParser::Var_defContext * /*ctx*/) override { }

  virtual void enterVar_stmt(JvavParser::Var_stmtContext * /*ctx*/) override { }
  virtual void exitVar_stmt(JvavParser::Var_stmtContext * /*ctx*/) override { }

  virtual void enterSuite(JvavParser::SuiteContext * /*ctx*/) override { }
  virtual void exitSuite(JvavParser::SuiteContext * /*ctx*/) override { }

  virtual void enterBlock(JvavParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(JvavParser::BlockContext * /*ctx*/) override { }

  virtual void enterVarDefStmt(JvavParser::VarDefStmtContext * /*ctx*/) override { }
  virtual void exitVarDefStmt(JvavParser::VarDefStmtContext * /*ctx*/) override { }

  virtual void enterBranchStmt(JvavParser::BranchStmtContext * /*ctx*/) override { }
  virtual void exitBranchStmt(JvavParser::BranchStmtContext * /*ctx*/) override { }

  virtual void enterLoopStmt(JvavParser::LoopStmtContext * /*ctx*/) override { }
  virtual void exitLoopStmt(JvavParser::LoopStmtContext * /*ctx*/) override { }

  virtual void enterFlowStmt(JvavParser::FlowStmtContext * /*ctx*/) override { }
  virtual void exitFlowStmt(JvavParser::FlowStmtContext * /*ctx*/) override { }

  virtual void enterExprStmt(JvavParser::ExprStmtContext * /*ctx*/) override { }
  virtual void exitExprStmt(JvavParser::ExprStmtContext * /*ctx*/) override { }

  virtual void enterBranch_stmt(JvavParser::Branch_stmtContext * /*ctx*/) override { }
  virtual void exitBranch_stmt(JvavParser::Branch_stmtContext * /*ctx*/) override { }

  virtual void enterLoop_stmt(JvavParser::Loop_stmtContext * /*ctx*/) override { }
  virtual void exitLoop_stmt(JvavParser::Loop_stmtContext * /*ctx*/) override { }

  virtual void enterWhile_stmt(JvavParser::While_stmtContext * /*ctx*/) override { }
  virtual void exitWhile_stmt(JvavParser::While_stmtContext * /*ctx*/) override { }

  virtual void enterFor_stmt(JvavParser::For_stmtContext * /*ctx*/) override { }
  virtual void exitFor_stmt(JvavParser::For_stmtContext * /*ctx*/) override { }

  virtual void enterFlow_stmt(JvavParser::Flow_stmtContext * /*ctx*/) override { }
  virtual void exitFlow_stmt(JvavParser::Flow_stmtContext * /*ctx*/) override { }

  virtual void enterReturn_stmt(JvavParser::Return_stmtContext * /*ctx*/) override { }
  virtual void exitReturn_stmt(JvavParser::Return_stmtContext * /*ctx*/) override { }

  virtual void enterBreak_stmt(JvavParser::Break_stmtContext * /*ctx*/) override { }
  virtual void exitBreak_stmt(JvavParser::Break_stmtContext * /*ctx*/) override { }

  virtual void enterContinue_stmt(JvavParser::Continue_stmtContext * /*ctx*/) override { }
  virtual void exitContinue_stmt(JvavParser::Continue_stmtContext * /*ctx*/) override { }

  virtual void enterExpr_stmt(JvavParser::Expr_stmtContext * /*ctx*/) override { }
  virtual void exitExpr_stmt(JvavParser::Expr_stmtContext * /*ctx*/) override { }

  virtual void enterNewExpr(JvavParser::NewExprContext * /*ctx*/) override { }
  virtual void exitNewExpr(JvavParser::NewExprContext * /*ctx*/) override { }

  virtual void enterThisExpr(JvavParser::ThisExprContext * /*ctx*/) override { }
  virtual void exitThisExpr(JvavParser::ThisExprContext * /*ctx*/) override { }

  virtual void enterFuncExpr(JvavParser::FuncExprContext * /*ctx*/) override { }
  virtual void exitFuncExpr(JvavParser::FuncExprContext * /*ctx*/) override { }

  virtual void enterArrayExpr(JvavParser::ArrayExprContext * /*ctx*/) override { }
  virtual void exitArrayExpr(JvavParser::ArrayExprContext * /*ctx*/) override { }

  virtual void enterMemberExpr(JvavParser::MemberExprContext * /*ctx*/) override { }
  virtual void exitMemberExpr(JvavParser::MemberExprContext * /*ctx*/) override { }

  virtual void enterBinaryExpr(JvavParser::BinaryExprContext * /*ctx*/) override { }
  virtual void exitBinaryExpr(JvavParser::BinaryExprContext * /*ctx*/) override { }

  virtual void enterPrefixUnaryExpr(JvavParser::PrefixUnaryExprContext * /*ctx*/) override { }
  virtual void exitPrefixUnaryExpr(JvavParser::PrefixUnaryExprContext * /*ctx*/) override { }

  virtual void enterVarExpr(JvavParser::VarExprContext * /*ctx*/) override { }
  virtual void exitVarExpr(JvavParser::VarExprContext * /*ctx*/) override { }

  virtual void enterTernaryExpr(JvavParser::TernaryExprContext * /*ctx*/) override { }
  virtual void exitTernaryExpr(JvavParser::TernaryExprContext * /*ctx*/) override { }

  virtual void enterPureExpr(JvavParser::PureExprContext * /*ctx*/) override { }
  virtual void exitPureExpr(JvavParser::PureExprContext * /*ctx*/) override { }

  virtual void enterAssignExpr(JvavParser::AssignExprContext * /*ctx*/) override { }
  virtual void exitAssignExpr(JvavParser::AssignExprContext * /*ctx*/) override { }

  virtual void enterSuffixUnaryExpr(JvavParser::SuffixUnaryExprContext * /*ctx*/) override { }
  virtual void exitSuffixUnaryExpr(JvavParser::SuffixUnaryExprContext * /*ctx*/) override { }

  virtual void enterConstExpr(JvavParser::ConstExprContext * /*ctx*/) override { }
  virtual void exitConstExpr(JvavParser::ConstExprContext * /*ctx*/) override { }

  virtual void enterConst_expr(JvavParser::Const_exprContext * /*ctx*/) override { }
  virtual void exitConst_expr(JvavParser::Const_exprContext * /*ctx*/) override { }

  virtual void enterFunc_expr(JvavParser::Func_exprContext * /*ctx*/) override { }
  virtual void exitFunc_expr(JvavParser::Func_exprContext * /*ctx*/) override { }

  virtual void enterNew_expr(JvavParser::New_exprContext * /*ctx*/) override { }
  virtual void exitNew_expr(JvavParser::New_exprContext * /*ctx*/) override { }

  virtual void enterNewerror_expr(JvavParser::Newerror_exprContext * /*ctx*/) override { }
  virtual void exitNewerror_expr(JvavParser::Newerror_exprContext * /*ctx*/) override { }

  virtual void enterNewvar_expr(JvavParser::Newvar_exprContext * /*ctx*/) override { }
  virtual void exitNewvar_expr(JvavParser::Newvar_exprContext * /*ctx*/) override { }

  virtual void enterTypename(JvavParser::TypenameContext * /*ctx*/) override { }
  virtual void exitTypename(JvavParser::TypenameContext * /*ctx*/) override { }

  virtual void enterBasic_type(JvavParser::Basic_typeContext * /*ctx*/) override { }
  virtual void exitBasic_type(JvavParser::Basic_typeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

