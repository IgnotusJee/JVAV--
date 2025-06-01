
// Generated from ./JvavParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  JvavParser : public antlr4::Parser {
public:
  enum {
    Annotation = 1, BlockAnnotation = 2, LineAnnotation = 3, Newline = 4, 
    Whitespace = 5, Lparenthesis = 6, Rparenthesis = 7, Lbracket = 8, Rbracket = 9, 
    Lbrace = 10, Rbrace = 11, Dot = 12, Comma = 13, Semicolon = 14, Question = 15, 
    Colon = 16, Increment = 17, Decrement = 18, Not = 19, Inv = 20, Mul = 21, 
    Div = 22, Mod = 23, Add = 24, Sub = 25, Lshift = 26, Rshift = 27, Lessthan = 28, 
    Greaterthan = 29, Lessthanequal = 30, Greaterthanequal = 31, Equal = 32, 
    Notequal = 33, Bitand = 34, Bitxor = 35, Bitor = 36, And = 37, Or = 38, 
    Assign = 39, Class = 40, If = 41, Else = 42, While = 43, For = 44, Return = 45, 
    Break = 46, Continue = 47, This = 48, True = 49, False = 50, Null = 51, 
    New = 52, Bool = 53, Int = 54, Void = 55, String = 56, Number = 57, 
    Identifier = 58, Str = 59
  };

  enum {
    RuleProgram = 0, RuleFunc_def = 1, RuleTypedargslist = 2, RuleArgslist = 3, 
    RuleClass_def = 4, RuleClass_suite = 5, RuleConstruct_stmt = 6, RuleVar_def = 7, 
    RuleVar_stmt = 8, RuleSuite = 9, RuleStmt = 10, RuleBranch_stmt = 11, 
    RuleLoop_stmt = 12, RuleWhile_stmt = 13, RuleFor_stmt = 14, RuleFlow_stmt = 15, 
    RuleReturn_stmt = 16, RuleBreak_stmt = 17, RuleContinue_stmt = 18, RuleExpr_stmt = 19, 
    RuleExpression = 20, RuleConst_expr = 21, RuleFunc_expr = 22, RuleNew_expr = 23, 
    RuleNewerror_expr = 24, RuleNewvar_expr = 25, RuleTypename = 26, RuleBasic_type = 27
  };

  explicit JvavParser(antlr4::TokenStream *input);

  JvavParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~JvavParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class Func_defContext;
  class TypedargslistContext;
  class ArgslistContext;
  class Class_defContext;
  class Class_suiteContext;
  class Construct_stmtContext;
  class Var_defContext;
  class Var_stmtContext;
  class SuiteContext;
  class StmtContext;
  class Branch_stmtContext;
  class Loop_stmtContext;
  class While_stmtContext;
  class For_stmtContext;
  class Flow_stmtContext;
  class Return_stmtContext;
  class Break_stmtContext;
  class Continue_stmtContext;
  class Expr_stmtContext;
  class ExpressionContext;
  class Const_exprContext;
  class Func_exprContext;
  class New_exprContext;
  class Newerror_exprContext;
  class Newvar_exprContext;
  class TypenameContext;
  class Basic_typeContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Func_defContext *> func_def();
    Func_defContext* func_def(size_t i);
    std::vector<Class_defContext *> class_def();
    Class_defContext* class_def(size_t i);
    std::vector<Var_defContext *> var_def();
    Var_defContext* var_def(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  Func_defContext : public antlr4::ParserRuleContext {
  public:
    Func_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Lparenthesis();
    antlr4::tree::TerminalNode *Rparenthesis();
    SuiteContext *suite();
    TypenameContext *typename_();
    antlr4::tree::TerminalNode *Void();
    TypedargslistContext *typedargslist();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_defContext* func_def();

  class  TypedargslistContext : public antlr4::ParserRuleContext {
  public:
    TypedargslistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypenameContext *> typename_();
    TypenameContext* typename_(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypedargslistContext* typedargslist();

  class  ArgslistContext : public antlr4::ParserRuleContext {
  public:
    ArgslistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgslistContext* argslist();

  class  Class_defContext : public antlr4::ParserRuleContext {
  public:
    Class_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Class();
    antlr4::tree::TerminalNode *Identifier();
    Class_suiteContext *class_suite();
    antlr4::tree::TerminalNode *Semicolon();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_defContext* class_def();

  class  Class_suiteContext : public antlr4::ParserRuleContext {
  public:
    Class_suiteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Lbrace();
    antlr4::tree::TerminalNode *Rbrace();
    std::vector<Var_defContext *> var_def();
    Var_defContext* var_def(size_t i);
    std::vector<Func_defContext *> func_def();
    Func_defContext* func_def(size_t i);
    std::vector<Construct_stmtContext *> construct_stmt();
    Construct_stmtContext* construct_stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_suiteContext* class_suite();

  class  Construct_stmtContext : public antlr4::ParserRuleContext {
  public:
    Construct_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Lparenthesis();
    antlr4::tree::TerminalNode *Rparenthesis();
    SuiteContext *suite();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Construct_stmtContext* construct_stmt();

  class  Var_defContext : public antlr4::ParserRuleContext {
  public:
    Var_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypenameContext *typename_();
    std::vector<Var_stmtContext *> var_stmt();
    Var_stmtContext* var_stmt(size_t i);
    antlr4::tree::TerminalNode *Semicolon();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_defContext* var_def();

  class  Var_stmtContext : public antlr4::ParserRuleContext {
  public:
    Var_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Assign();
    ExpressionContext *expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_stmtContext* var_stmt();

  class  SuiteContext : public antlr4::ParserRuleContext {
  public:
    SuiteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Lbrace();
    antlr4::tree::TerminalNode *Rbrace();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SuiteContext* suite();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtContext() = default;
    void copyFrom(StmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FlowStmtContext : public StmtContext {
  public:
    FlowStmtContext(StmtContext *ctx);

    Flow_stmtContext *flow_stmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarDefStmtContext : public StmtContext {
  public:
    VarDefStmtContext(StmtContext *ctx);

    Var_defContext *var_def();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LoopStmtContext : public StmtContext {
  public:
    LoopStmtContext(StmtContext *ctx);

    Loop_stmtContext *loop_stmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprStmtContext : public StmtContext {
  public:
    ExprStmtContext(StmtContext *ctx);

    Expr_stmtContext *expr_stmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BlockContext : public StmtContext {
  public:
    BlockContext(StmtContext *ctx);

    SuiteContext *suite();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BranchStmtContext : public StmtContext {
  public:
    BranchStmtContext(StmtContext *ctx);

    Branch_stmtContext *branch_stmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StmtContext* stmt();

  class  Branch_stmtContext : public antlr4::ParserRuleContext {
  public:
    Branch_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> If();
    antlr4::tree::TerminalNode* If(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Lparenthesis();
    antlr4::tree::TerminalNode* Lparenthesis(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Rparenthesis();
    antlr4::tree::TerminalNode* Rparenthesis(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Else();
    antlr4::tree::TerminalNode* Else(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Branch_stmtContext* branch_stmt();

  class  Loop_stmtContext : public antlr4::ParserRuleContext {
  public:
    Loop_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    While_stmtContext *while_stmt();
    For_stmtContext *for_stmt();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Loop_stmtContext* loop_stmt();

  class  While_stmtContext : public antlr4::ParserRuleContext {
  public:
    While_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *While();
    antlr4::tree::TerminalNode *Lparenthesis();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Rparenthesis();
    StmtContext *stmt();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  While_stmtContext* while_stmt();

  class  For_stmtContext : public antlr4::ParserRuleContext {
  public:
    JvavParser::ExpressionContext *init = nullptr;
    JvavParser::ExpressionContext *cond = nullptr;
    JvavParser::ExpressionContext *step = nullptr;
    For_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *For();
    antlr4::tree::TerminalNode *Lparenthesis();
    std::vector<antlr4::tree::TerminalNode *> Semicolon();
    antlr4::tree::TerminalNode* Semicolon(size_t i);
    antlr4::tree::TerminalNode *Rparenthesis();
    StmtContext *stmt();
    Var_defContext *var_def();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_stmtContext* for_stmt();

  class  Flow_stmtContext : public antlr4::ParserRuleContext {
  public:
    Flow_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Return_stmtContext *return_stmt();
    Break_stmtContext *break_stmt();
    Continue_stmtContext *continue_stmt();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Flow_stmtContext* flow_stmt();

  class  Return_stmtContext : public antlr4::ParserRuleContext {
  public:
    Return_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Return();
    antlr4::tree::TerminalNode *Semicolon();
    ExpressionContext *expression();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Return_stmtContext* return_stmt();

  class  Break_stmtContext : public antlr4::ParserRuleContext {
  public:
    Break_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Break();
    antlr4::tree::TerminalNode *Semicolon();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Break_stmtContext* break_stmt();

  class  Continue_stmtContext : public antlr4::ParserRuleContext {
  public:
    Continue_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Continue();
    antlr4::tree::TerminalNode *Semicolon();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Continue_stmtContext* continue_stmt();

  class  Expr_stmtContext : public antlr4::ParserRuleContext {
  public:
    Expr_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Semicolon();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr_stmtContext* expr_stmt();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NewExprContext : public ExpressionContext {
  public:
    NewExprContext(ExpressionContext *ctx);

    New_exprContext *new_expr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ThisExprContext : public ExpressionContext {
  public:
    ThisExprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *This();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FuncExprContext : public ExpressionContext {
  public:
    FuncExprContext(ExpressionContext *ctx);

    Func_exprContext *func_expr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrayExprContext : public ExpressionContext {
  public:
    ArrayExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Lbracket();
    antlr4::tree::TerminalNode *Rbracket();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MemberExprContext : public ExpressionContext {
  public:
    MemberExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Dot();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BinaryExprContext : public ExpressionContext {
  public:
    BinaryExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Mul();
    antlr4::tree::TerminalNode *Div();
    antlr4::tree::TerminalNode *Mod();
    antlr4::tree::TerminalNode *Add();
    antlr4::tree::TerminalNode *Sub();
    antlr4::tree::TerminalNode *Lshift();
    antlr4::tree::TerminalNode *Rshift();
    antlr4::tree::TerminalNode *Lessthan();
    antlr4::tree::TerminalNode *Greaterthan();
    antlr4::tree::TerminalNode *Lessthanequal();
    antlr4::tree::TerminalNode *Greaterthanequal();
    antlr4::tree::TerminalNode *Equal();
    antlr4::tree::TerminalNode *Notequal();
    antlr4::tree::TerminalNode *Bitand();
    antlr4::tree::TerminalNode *Bitxor();
    antlr4::tree::TerminalNode *Bitor();
    antlr4::tree::TerminalNode *And();
    antlr4::tree::TerminalNode *Or();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrefixUnaryExprContext : public ExpressionContext {
  public:
    PrefixUnaryExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Increment();
    antlr4::tree::TerminalNode *Decrement();
    antlr4::tree::TerminalNode *Not();
    antlr4::tree::TerminalNode *Inv();
    antlr4::tree::TerminalNode *Sub();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarExprContext : public ExpressionContext {
  public:
    VarExprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *Identifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TernaryExprContext : public ExpressionContext {
  public:
    TernaryExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Question();
    antlr4::tree::TerminalNode *Colon();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PureExprContext : public ExpressionContext {
  public:
    PureExprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *Lparenthesis();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Rparenthesis();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignExprContext : public ExpressionContext {
  public:
    AssignExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Assign();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SuffixUnaryExprContext : public ExpressionContext {
  public:
    SuffixUnaryExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Increment();
    antlr4::tree::TerminalNode *Decrement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConstExprContext : public ExpressionContext {
  public:
    ConstExprContext(ExpressionContext *ctx);

    Const_exprContext *const_expr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  Const_exprContext : public antlr4::ParserRuleContext {
  public:
    Const_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *True();
    antlr4::tree::TerminalNode *False();
    antlr4::tree::TerminalNode *Number();
    antlr4::tree::TerminalNode *Str();
    antlr4::tree::TerminalNode *Null();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Const_exprContext* const_expr();

  class  Func_exprContext : public antlr4::ParserRuleContext {
  public:
    Func_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Lparenthesis();
    antlr4::tree::TerminalNode *Rparenthesis();
    ArgslistContext *argslist();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_exprContext* func_expr();

  class  New_exprContext : public antlr4::ParserRuleContext {
  public:
    New_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Newerror_exprContext *newerror_expr();
    Newvar_exprContext *newvar_expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  New_exprContext* new_expr();

  class  Newerror_exprContext : public antlr4::ParserRuleContext {
  public:
    Newerror_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *New();
    Basic_typeContext *basic_type();
    std::vector<antlr4::tree::TerminalNode *> Lbracket();
    antlr4::tree::TerminalNode* Lbracket(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Rbracket();
    antlr4::tree::TerminalNode* Rbracket(size_t i);
    antlr4::tree::TerminalNode *Lparenthesis();
    antlr4::tree::TerminalNode *Rparenthesis();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Newerror_exprContext* newerror_expr();

  class  Newvar_exprContext : public antlr4::ParserRuleContext {
  public:
    Newvar_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *New();
    Basic_typeContext *basic_type();
    std::vector<antlr4::tree::TerminalNode *> Lbracket();
    antlr4::tree::TerminalNode* Lbracket(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Rbracket();
    antlr4::tree::TerminalNode* Rbracket(size_t i);
    antlr4::tree::TerminalNode *Lparenthesis();
    antlr4::tree::TerminalNode *Rparenthesis();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Newvar_exprContext* newvar_expr();

  class  TypenameContext : public antlr4::ParserRuleContext {
  public:
    TypenameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Basic_typeContext *basic_type();
    std::vector<antlr4::tree::TerminalNode *> Lbracket();
    antlr4::tree::TerminalNode* Lbracket(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Rbracket();
    antlr4::tree::TerminalNode* Rbracket(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypenameContext* typename_();

  class  Basic_typeContext : public antlr4::ParserRuleContext {
  public:
    Basic_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Bool();
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *String();
    antlr4::tree::TerminalNode *Identifier();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Basic_typeContext* basic_type();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

