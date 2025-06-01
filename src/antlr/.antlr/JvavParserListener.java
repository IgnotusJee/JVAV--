// Generated from /home/hanminghao/privatespace/compiling/jvav/JVAV--/src/antlr/JvavParser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link JvavParser}.
 */
public interface JvavParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link JvavParser#program}.
	 * @param ctx the parse tree
	 */
	void enterProgram(JvavParser.ProgramContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#program}.
	 * @param ctx the parse tree
	 */
	void exitProgram(JvavParser.ProgramContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#func_def}.
	 * @param ctx the parse tree
	 */
	void enterFunc_def(JvavParser.Func_defContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#func_def}.
	 * @param ctx the parse tree
	 */
	void exitFunc_def(JvavParser.Func_defContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#typedargslist}.
	 * @param ctx the parse tree
	 */
	void enterTypedargslist(JvavParser.TypedargslistContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#typedargslist}.
	 * @param ctx the parse tree
	 */
	void exitTypedargslist(JvavParser.TypedargslistContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#argslist}.
	 * @param ctx the parse tree
	 */
	void enterArgslist(JvavParser.ArgslistContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#argslist}.
	 * @param ctx the parse tree
	 */
	void exitArgslist(JvavParser.ArgslistContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#class_def}.
	 * @param ctx the parse tree
	 */
	void enterClass_def(JvavParser.Class_defContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#class_def}.
	 * @param ctx the parse tree
	 */
	void exitClass_def(JvavParser.Class_defContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#class_suite}.
	 * @param ctx the parse tree
	 */
	void enterClass_suite(JvavParser.Class_suiteContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#class_suite}.
	 * @param ctx the parse tree
	 */
	void exitClass_suite(JvavParser.Class_suiteContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#construct_stmt}.
	 * @param ctx the parse tree
	 */
	void enterConstruct_stmt(JvavParser.Construct_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#construct_stmt}.
	 * @param ctx the parse tree
	 */
	void exitConstruct_stmt(JvavParser.Construct_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#var_def}.
	 * @param ctx the parse tree
	 */
	void enterVar_def(JvavParser.Var_defContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#var_def}.
	 * @param ctx the parse tree
	 */
	void exitVar_def(JvavParser.Var_defContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#var_stmt}.
	 * @param ctx the parse tree
	 */
	void enterVar_stmt(JvavParser.Var_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#var_stmt}.
	 * @param ctx the parse tree
	 */
	void exitVar_stmt(JvavParser.Var_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#suite}.
	 * @param ctx the parse tree
	 */
	void enterSuite(JvavParser.SuiteContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#suite}.
	 * @param ctx the parse tree
	 */
	void exitSuite(JvavParser.SuiteContext ctx);
	/**
	 * Enter a parse tree produced by the {@code block}
	 * labeled alternative in {@link JvavParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterBlock(JvavParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by the {@code block}
	 * labeled alternative in {@link JvavParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitBlock(JvavParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by the {@code varDefStmt}
	 * labeled alternative in {@link JvavParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterVarDefStmt(JvavParser.VarDefStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code varDefStmt}
	 * labeled alternative in {@link JvavParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitVarDefStmt(JvavParser.VarDefStmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code branchStmt}
	 * labeled alternative in {@link JvavParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterBranchStmt(JvavParser.BranchStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code branchStmt}
	 * labeled alternative in {@link JvavParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitBranchStmt(JvavParser.BranchStmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code loopStmt}
	 * labeled alternative in {@link JvavParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterLoopStmt(JvavParser.LoopStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code loopStmt}
	 * labeled alternative in {@link JvavParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitLoopStmt(JvavParser.LoopStmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code flowStmt}
	 * labeled alternative in {@link JvavParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterFlowStmt(JvavParser.FlowStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code flowStmt}
	 * labeled alternative in {@link JvavParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitFlowStmt(JvavParser.FlowStmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprStmt}
	 * labeled alternative in {@link JvavParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterExprStmt(JvavParser.ExprStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprStmt}
	 * labeled alternative in {@link JvavParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitExprStmt(JvavParser.ExprStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#branch_stmt}.
	 * @param ctx the parse tree
	 */
	void enterBranch_stmt(JvavParser.Branch_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#branch_stmt}.
	 * @param ctx the parse tree
	 */
	void exitBranch_stmt(JvavParser.Branch_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#loop_stmt}.
	 * @param ctx the parse tree
	 */
	void enterLoop_stmt(JvavParser.Loop_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#loop_stmt}.
	 * @param ctx the parse tree
	 */
	void exitLoop_stmt(JvavParser.Loop_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#while_stmt}.
	 * @param ctx the parse tree
	 */
	void enterWhile_stmt(JvavParser.While_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#while_stmt}.
	 * @param ctx the parse tree
	 */
	void exitWhile_stmt(JvavParser.While_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#for_stmt}.
	 * @param ctx the parse tree
	 */
	void enterFor_stmt(JvavParser.For_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#for_stmt}.
	 * @param ctx the parse tree
	 */
	void exitFor_stmt(JvavParser.For_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#flow_stmt}.
	 * @param ctx the parse tree
	 */
	void enterFlow_stmt(JvavParser.Flow_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#flow_stmt}.
	 * @param ctx the parse tree
	 */
	void exitFlow_stmt(JvavParser.Flow_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#return_stmt}.
	 * @param ctx the parse tree
	 */
	void enterReturn_stmt(JvavParser.Return_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#return_stmt}.
	 * @param ctx the parse tree
	 */
	void exitReturn_stmt(JvavParser.Return_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#break_stmt}.
	 * @param ctx the parse tree
	 */
	void enterBreak_stmt(JvavParser.Break_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#break_stmt}.
	 * @param ctx the parse tree
	 */
	void exitBreak_stmt(JvavParser.Break_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#continue_stmt}.
	 * @param ctx the parse tree
	 */
	void enterContinue_stmt(JvavParser.Continue_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#continue_stmt}.
	 * @param ctx the parse tree
	 */
	void exitContinue_stmt(JvavParser.Continue_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#expr_stmt}.
	 * @param ctx the parse tree
	 */
	void enterExpr_stmt(JvavParser.Expr_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#expr_stmt}.
	 * @param ctx the parse tree
	 */
	void exitExpr_stmt(JvavParser.Expr_stmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code newExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterNewExpr(JvavParser.NewExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code newExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitNewExpr(JvavParser.NewExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code thisExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterThisExpr(JvavParser.ThisExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code thisExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitThisExpr(JvavParser.ThisExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code funcExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterFuncExpr(JvavParser.FuncExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code funcExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitFuncExpr(JvavParser.FuncExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code arrayExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterArrayExpr(JvavParser.ArrayExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code arrayExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitArrayExpr(JvavParser.ArrayExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code memberExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterMemberExpr(JvavParser.MemberExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code memberExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitMemberExpr(JvavParser.MemberExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code binaryExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterBinaryExpr(JvavParser.BinaryExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code binaryExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitBinaryExpr(JvavParser.BinaryExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code prefixUnaryExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterPrefixUnaryExpr(JvavParser.PrefixUnaryExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code prefixUnaryExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitPrefixUnaryExpr(JvavParser.PrefixUnaryExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code varExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterVarExpr(JvavParser.VarExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code varExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitVarExpr(JvavParser.VarExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ternaryExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterTernaryExpr(JvavParser.TernaryExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ternaryExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitTernaryExpr(JvavParser.TernaryExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code pureExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterPureExpr(JvavParser.PureExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code pureExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitPureExpr(JvavParser.PureExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code assignExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterAssignExpr(JvavParser.AssignExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code assignExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitAssignExpr(JvavParser.AssignExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code suffixUnaryExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterSuffixUnaryExpr(JvavParser.SuffixUnaryExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code suffixUnaryExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitSuffixUnaryExpr(JvavParser.SuffixUnaryExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code constExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterConstExpr(JvavParser.ConstExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code constExpr}
	 * labeled alternative in {@link JvavParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitConstExpr(JvavParser.ConstExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void enterConst_expr(JvavParser.Const_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#const_expr}.
	 * @param ctx the parse tree
	 */
	void exitConst_expr(JvavParser.Const_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#func_expr}.
	 * @param ctx the parse tree
	 */
	void enterFunc_expr(JvavParser.Func_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#func_expr}.
	 * @param ctx the parse tree
	 */
	void exitFunc_expr(JvavParser.Func_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#new_expr}.
	 * @param ctx the parse tree
	 */
	void enterNew_expr(JvavParser.New_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#new_expr}.
	 * @param ctx the parse tree
	 */
	void exitNew_expr(JvavParser.New_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#newerror_expr}.
	 * @param ctx the parse tree
	 */
	void enterNewerror_expr(JvavParser.Newerror_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#newerror_expr}.
	 * @param ctx the parse tree
	 */
	void exitNewerror_expr(JvavParser.Newerror_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#newvar_expr}.
	 * @param ctx the parse tree
	 */
	void enterNewvar_expr(JvavParser.Newvar_exprContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#newvar_expr}.
	 * @param ctx the parse tree
	 */
	void exitNewvar_expr(JvavParser.Newvar_exprContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#typename}.
	 * @param ctx the parse tree
	 */
	void enterTypename(JvavParser.TypenameContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#typename}.
	 * @param ctx the parse tree
	 */
	void exitTypename(JvavParser.TypenameContext ctx);
	/**
	 * Enter a parse tree produced by {@link JvavParser#basic_type}.
	 * @param ctx the parse tree
	 */
	void enterBasic_type(JvavParser.Basic_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link JvavParser#basic_type}.
	 * @param ctx the parse tree
	 */
	void exitBasic_type(JvavParser.Basic_typeContext ctx);
}