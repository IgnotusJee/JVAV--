// Generated from /home/hanminghao/privatespace/compiling/jvav/JVAV--/src/antlr/JvavParser.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class JvavParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Annotation=1, BlockAnnotation=2, LineAnnotation=3, Newline=4, Whitespace=5, 
		Lparenthesis=6, Rparenthesis=7, Lbracket=8, Rbracket=9, Lbrace=10, Rbrace=11, 
		Dot=12, Comma=13, Semicolon=14, Question=15, Colon=16, Increment=17, Decrement=18, 
		Not=19, Inv=20, Mul=21, Div=22, Mod=23, Add=24, Sub=25, Lshift=26, Rshift=27, 
		Lessthan=28, Greaterthan=29, Lessthanequal=30, Greaterthanequal=31, Equal=32, 
		Notequal=33, Bitand=34, Bitxor=35, Bitor=36, And=37, Or=38, Assign=39, 
		Class=40, If=41, Else=42, While=43, For=44, Return=45, Break=46, Continue=47, 
		This=48, True=49, False=50, Null=51, New=52, Bool=53, Int=54, Void=55, 
		String=56, Number=57, Identifier=58, Str=59;
	public static final int
		RULE_program = 0, RULE_func_def = 1, RULE_typedargslist = 2, RULE_argslist = 3, 
		RULE_class_def = 4, RULE_class_suite = 5, RULE_construct_stmt = 6, RULE_var_def = 7, 
		RULE_var_stmt = 8, RULE_suite = 9, RULE_stmt = 10, RULE_branch_stmt = 11, 
		RULE_loop_stmt = 12, RULE_while_stmt = 13, RULE_for_stmt = 14, RULE_flow_stmt = 15, 
		RULE_return_stmt = 16, RULE_break_stmt = 17, RULE_continue_stmt = 18, 
		RULE_expr_stmt = 19, RULE_expression = 20, RULE_const_expr = 21, RULE_func_expr = 22, 
		RULE_new_expr = 23, RULE_newerror_expr = 24, RULE_newvar_expr = 25, RULE_typename = 26, 
		RULE_basic_type = 27;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "func_def", "typedargslist", "argslist", "class_def", "class_suite", 
			"construct_stmt", "var_def", "var_stmt", "suite", "stmt", "branch_stmt", 
			"loop_stmt", "while_stmt", "for_stmt", "flow_stmt", "return_stmt", "break_stmt", 
			"continue_stmt", "expr_stmt", "expression", "const_expr", "func_expr", 
			"new_expr", "newerror_expr", "newvar_expr", "typename", "basic_type"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, null, "'('", "')'", "'['", "']'", "'{'", 
			"'}'", "'.'", "','", "';'", "'?'", "':'", "'++'", "'--'", "'!'", "'~'", 
			"'*'", "'/'", "'%'", "'+'", "'-'", "'<<'", "'>>'", "'<'", "'>'", "'<='", 
			"'>='", "'=='", "'!='", "'&'", "'^'", "'|'", "'&&'", "'||'", "'='", "'class'", 
			"'if'", "'else'", "'while'", "'for'", "'return'", "'break'", "'continue'", 
			"'this'", "'true'", "'false'", "'null'", "'new'", "'bool'", "'int'", 
			"'void'", "'string'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "Annotation", "BlockAnnotation", "LineAnnotation", "Newline", "Whitespace", 
			"Lparenthesis", "Rparenthesis", "Lbracket", "Rbracket", "Lbrace", "Rbrace", 
			"Dot", "Comma", "Semicolon", "Question", "Colon", "Increment", "Decrement", 
			"Not", "Inv", "Mul", "Div", "Mod", "Add", "Sub", "Lshift", "Rshift", 
			"Lessthan", "Greaterthan", "Lessthanequal", "Greaterthanequal", "Equal", 
			"Notequal", "Bitand", "Bitxor", "Bitor", "And", "Or", "Assign", "Class", 
			"If", "Else", "While", "For", "Return", "Break", "Continue", "This", 
			"True", "False", "Null", "New", "Bool", "Int", "Void", "String", "Number", 
			"Identifier", "Str"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "JvavParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public JvavParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ProgramContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(JvavParser.EOF, 0); }
		public List<Func_defContext> func_def() {
			return getRuleContexts(Func_defContext.class);
		}
		public Func_defContext func_def(int i) {
			return getRuleContext(Func_defContext.class,i);
		}
		public List<Class_defContext> class_def() {
			return getRuleContexts(Class_defContext.class);
		}
		public Class_defContext class_def(int i) {
			return getRuleContext(Class_defContext.class,i);
		}
		public List<Var_defContext> var_def() {
			return getRuleContexts(Var_defContext.class);
		}
		public Var_defContext var_def(int i) {
			return getRuleContext(Var_defContext.class,i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(61);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 423339464484454400L) != 0)) {
				{
				setState(59);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
				case 1:
					{
					setState(56);
					func_def();
					}
					break;
				case 2:
					{
					setState(57);
					class_def();
					}
					break;
				case 3:
					{
					setState(58);
					var_def();
					}
					break;
				}
				}
				setState(63);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(64);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_defContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(JvavParser.Identifier, 0); }
		public TerminalNode Lparenthesis() { return getToken(JvavParser.Lparenthesis, 0); }
		public TerminalNode Rparenthesis() { return getToken(JvavParser.Rparenthesis, 0); }
		public SuiteContext suite() {
			return getRuleContext(SuiteContext.class,0);
		}
		public TypenameContext typename() {
			return getRuleContext(TypenameContext.class,0);
		}
		public TerminalNode Void() { return getToken(JvavParser.Void, 0); }
		public TypedargslistContext typedargslist() {
			return getRuleContext(TypedargslistContext.class,0);
		}
		public Func_defContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_def; }
	}

	public final Func_defContext func_def() throws RecognitionException {
		Func_defContext _localctx = new Func_defContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_func_def);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(68);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Bool:
			case Int:
			case String:
			case Identifier:
				{
				setState(66);
				typename();
				}
				break;
			case Void:
				{
				setState(67);
				match(Void);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(70);
			match(Identifier);
			setState(71);
			match(Lparenthesis);
			setState(73);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 387309567953862656L) != 0)) {
				{
				setState(72);
				typedargslist();
				}
			}

			setState(75);
			match(Rparenthesis);
			setState(76);
			suite();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TypedargslistContext extends ParserRuleContext {
		public List<TypenameContext> typename() {
			return getRuleContexts(TypenameContext.class);
		}
		public TypenameContext typename(int i) {
			return getRuleContext(TypenameContext.class,i);
		}
		public List<TerminalNode> Identifier() { return getTokens(JvavParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(JvavParser.Identifier, i);
		}
		public List<TerminalNode> Comma() { return getTokens(JvavParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(JvavParser.Comma, i);
		}
		public TypedargslistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typedargslist; }
	}

	public final TypedargslistContext typedargslist() throws RecognitionException {
		TypedargslistContext _localctx = new TypedargslistContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_typedargslist);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(78);
			typename();
			setState(79);
			match(Identifier);
			setState(86);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(80);
				match(Comma);
				setState(81);
				typename();
				setState(82);
				match(Identifier);
				}
				}
				setState(88);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ArgslistContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(JvavParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(JvavParser.Comma, i);
		}
		public ArgslistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_argslist; }
	}

	public final ArgslistContext argslist() throws RecognitionException {
		ArgslistContext _localctx = new ArgslistContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_argslist);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(89);
			expression(0);
			setState(94);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(90);
				match(Comma);
				setState(91);
				expression(0);
				}
				}
				setState(96);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Class_defContext extends ParserRuleContext {
		public TerminalNode Class() { return getToken(JvavParser.Class, 0); }
		public TerminalNode Identifier() { return getToken(JvavParser.Identifier, 0); }
		public Class_suiteContext class_suite() {
			return getRuleContext(Class_suiteContext.class,0);
		}
		public TerminalNode Semicolon() { return getToken(JvavParser.Semicolon, 0); }
		public Class_defContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_class_def; }
	}

	public final Class_defContext class_def() throws RecognitionException {
		Class_defContext _localctx = new Class_defContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_class_def);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(97);
			match(Class);
			setState(98);
			match(Identifier);
			setState(99);
			class_suite();
			setState(100);
			match(Semicolon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Class_suiteContext extends ParserRuleContext {
		public TerminalNode Lbrace() { return getToken(JvavParser.Lbrace, 0); }
		public TerminalNode Rbrace() { return getToken(JvavParser.Rbrace, 0); }
		public List<Var_defContext> var_def() {
			return getRuleContexts(Var_defContext.class);
		}
		public Var_defContext var_def(int i) {
			return getRuleContext(Var_defContext.class,i);
		}
		public List<Func_defContext> func_def() {
			return getRuleContexts(Func_defContext.class);
		}
		public Func_defContext func_def(int i) {
			return getRuleContext(Func_defContext.class,i);
		}
		public List<Construct_stmtContext> construct_stmt() {
			return getRuleContexts(Construct_stmtContext.class);
		}
		public Construct_stmtContext construct_stmt(int i) {
			return getRuleContext(Construct_stmtContext.class,i);
		}
		public Class_suiteContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_class_suite; }
	}

	public final Class_suiteContext class_suite() throws RecognitionException {
		Class_suiteContext _localctx = new Class_suiteContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_class_suite);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(102);
			match(Lbrace);
			setState(108);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 423338364972826624L) != 0)) {
				{
				setState(106);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
				case 1:
					{
					setState(103);
					var_def();
					}
					break;
				case 2:
					{
					setState(104);
					func_def();
					}
					break;
				case 3:
					{
					setState(105);
					construct_stmt();
					}
					break;
				}
				}
				setState(110);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(111);
			match(Rbrace);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Construct_stmtContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(JvavParser.Identifier, 0); }
		public TerminalNode Lparenthesis() { return getToken(JvavParser.Lparenthesis, 0); }
		public TerminalNode Rparenthesis() { return getToken(JvavParser.Rparenthesis, 0); }
		public SuiteContext suite() {
			return getRuleContext(SuiteContext.class,0);
		}
		public Construct_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_construct_stmt; }
	}

	public final Construct_stmtContext construct_stmt() throws RecognitionException {
		Construct_stmtContext _localctx = new Construct_stmtContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_construct_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(113);
			match(Identifier);
			setState(114);
			match(Lparenthesis);
			setState(115);
			match(Rparenthesis);
			setState(116);
			suite();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Var_defContext extends ParserRuleContext {
		public TypenameContext typename() {
			return getRuleContext(TypenameContext.class,0);
		}
		public List<Var_stmtContext> var_stmt() {
			return getRuleContexts(Var_stmtContext.class);
		}
		public Var_stmtContext var_stmt(int i) {
			return getRuleContext(Var_stmtContext.class,i);
		}
		public TerminalNode Semicolon() { return getToken(JvavParser.Semicolon, 0); }
		public List<TerminalNode> Comma() { return getTokens(JvavParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(JvavParser.Comma, i);
		}
		public Var_defContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var_def; }
	}

	public final Var_defContext var_def() throws RecognitionException {
		Var_defContext _localctx = new Var_defContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_var_def);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(118);
			typename();
			setState(119);
			var_stmt();
			setState(124);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(120);
				match(Comma);
				setState(121);
				var_stmt();
				}
				}
				setState(126);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(127);
			match(Semicolon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Var_stmtContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(JvavParser.Identifier, 0); }
		public TerminalNode Assign() { return getToken(JvavParser.Assign, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Var_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var_stmt; }
	}

	public final Var_stmtContext var_stmt() throws RecognitionException {
		Var_stmtContext _localctx = new Var_stmtContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_var_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(129);
			match(Identifier);
			setState(132);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Assign) {
				{
				setState(130);
				match(Assign);
				setState(131);
				expression(0);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class SuiteContext extends ParserRuleContext {
		public TerminalNode Lbrace() { return getToken(JvavParser.Lbrace, 0); }
		public TerminalNode Rbrace() { return getToken(JvavParser.Rbrace, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public SuiteContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_suite; }
	}

	public final SuiteContext suite() throws RecognitionException {
		SuiteContext _localctx = new SuiteContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_suite);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(134);
			match(Lbrace);
			setState(138);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 1116886110553654336L) != 0)) {
				{
				{
				setState(135);
				stmt();
				}
				}
				setState(140);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(141);
			match(Rbrace);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StmtContext extends ParserRuleContext {
		public StmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt; }
	 
		public StmtContext() { }
		public void copyFrom(StmtContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FlowStmtContext extends StmtContext {
		public Flow_stmtContext flow_stmt() {
			return getRuleContext(Flow_stmtContext.class,0);
		}
		public FlowStmtContext(StmtContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VarDefStmtContext extends StmtContext {
		public Var_defContext var_def() {
			return getRuleContext(Var_defContext.class,0);
		}
		public VarDefStmtContext(StmtContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class LoopStmtContext extends StmtContext {
		public Loop_stmtContext loop_stmt() {
			return getRuleContext(Loop_stmtContext.class,0);
		}
		public LoopStmtContext(StmtContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ExprStmtContext extends StmtContext {
		public Expr_stmtContext expr_stmt() {
			return getRuleContext(Expr_stmtContext.class,0);
		}
		public ExprStmtContext(StmtContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BlockContext extends StmtContext {
		public SuiteContext suite() {
			return getRuleContext(SuiteContext.class,0);
		}
		public BlockContext(StmtContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BranchStmtContext extends StmtContext {
		public Branch_stmtContext branch_stmt() {
			return getRuleContext(Branch_stmtContext.class,0);
		}
		public BranchStmtContext(StmtContext ctx) { copyFrom(ctx); }
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_stmt);
		try {
			setState(149);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				_localctx = new BlockContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(143);
				suite();
				}
				break;
			case 2:
				_localctx = new VarDefStmtContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(144);
				var_def();
				}
				break;
			case 3:
				_localctx = new BranchStmtContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(145);
				branch_stmt();
				}
				break;
			case 4:
				_localctx = new LoopStmtContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(146);
				loop_stmt();
				}
				break;
			case 5:
				_localctx = new FlowStmtContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(147);
				flow_stmt();
				}
				break;
			case 6:
				_localctx = new ExprStmtContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(148);
				expr_stmt();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Branch_stmtContext extends ParserRuleContext {
		public List<TerminalNode> If() { return getTokens(JvavParser.If); }
		public TerminalNode If(int i) {
			return getToken(JvavParser.If, i);
		}
		public List<TerminalNode> Lparenthesis() { return getTokens(JvavParser.Lparenthesis); }
		public TerminalNode Lparenthesis(int i) {
			return getToken(JvavParser.Lparenthesis, i);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> Rparenthesis() { return getTokens(JvavParser.Rparenthesis); }
		public TerminalNode Rparenthesis(int i) {
			return getToken(JvavParser.Rparenthesis, i);
		}
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public List<TerminalNode> Else() { return getTokens(JvavParser.Else); }
		public TerminalNode Else(int i) {
			return getToken(JvavParser.Else, i);
		}
		public Branch_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_branch_stmt; }
	}

	public final Branch_stmtContext branch_stmt() throws RecognitionException {
		Branch_stmtContext _localctx = new Branch_stmtContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_branch_stmt);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(151);
			match(If);
			setState(152);
			match(Lparenthesis);
			setState(153);
			expression(0);
			setState(154);
			match(Rparenthesis);
			setState(155);
			stmt();
			setState(165);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(156);
					match(Else);
					setState(157);
					match(If);
					setState(158);
					match(Lparenthesis);
					setState(159);
					expression(0);
					setState(160);
					match(Rparenthesis);
					setState(161);
					stmt();
					}
					} 
				}
				setState(167);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			}
			setState(170);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				{
				setState(168);
				match(Else);
				setState(169);
				stmt();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Loop_stmtContext extends ParserRuleContext {
		public While_stmtContext while_stmt() {
			return getRuleContext(While_stmtContext.class,0);
		}
		public For_stmtContext for_stmt() {
			return getRuleContext(For_stmtContext.class,0);
		}
		public Loop_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_loop_stmt; }
	}

	public final Loop_stmtContext loop_stmt() throws RecognitionException {
		Loop_stmtContext _localctx = new Loop_stmtContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_loop_stmt);
		try {
			setState(174);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case While:
				enterOuterAlt(_localctx, 1);
				{
				setState(172);
				while_stmt();
				}
				break;
			case For:
				enterOuterAlt(_localctx, 2);
				{
				setState(173);
				for_stmt();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class While_stmtContext extends ParserRuleContext {
		public TerminalNode While() { return getToken(JvavParser.While, 0); }
		public TerminalNode Lparenthesis() { return getToken(JvavParser.Lparenthesis, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode Rparenthesis() { return getToken(JvavParser.Rparenthesis, 0); }
		public StmtContext stmt() {
			return getRuleContext(StmtContext.class,0);
		}
		public While_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_while_stmt; }
	}

	public final While_stmtContext while_stmt() throws RecognitionException {
		While_stmtContext _localctx = new While_stmtContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_while_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(176);
			match(While);
			setState(177);
			match(Lparenthesis);
			setState(178);
			expression(0);
			setState(179);
			match(Rparenthesis);
			setState(180);
			stmt();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class For_stmtContext extends ParserRuleContext {
		public ExpressionContext init;
		public ExpressionContext cond;
		public ExpressionContext step;
		public TerminalNode For() { return getToken(JvavParser.For, 0); }
		public TerminalNode Lparenthesis() { return getToken(JvavParser.Lparenthesis, 0); }
		public List<TerminalNode> Semicolon() { return getTokens(JvavParser.Semicolon); }
		public TerminalNode Semicolon(int i) {
			return getToken(JvavParser.Semicolon, i);
		}
		public TerminalNode Rparenthesis() { return getToken(JvavParser.Rparenthesis, 0); }
		public StmtContext stmt() {
			return getRuleContext(StmtContext.class,0);
		}
		public Var_defContext var_def() {
			return getRuleContext(Var_defContext.class,0);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public For_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_for_stmt; }
	}

	public final For_stmtContext for_stmt() throws RecognitionException {
		For_stmtContext _localctx = new For_stmtContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_for_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(182);
			match(For);
			setState(183);
			match(Lparenthesis);
			setState(189);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				{
				{
				setState(185);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 1017532040844542016L) != 0)) {
					{
					setState(184);
					((For_stmtContext)_localctx).init = expression(0);
					}
				}

				setState(187);
				match(Semicolon);
				}
				}
				break;
			case 2:
				{
				setState(188);
				var_def();
				}
				break;
			}
			setState(192);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 1017532040844542016L) != 0)) {
				{
				setState(191);
				((For_stmtContext)_localctx).cond = expression(0);
				}
			}

			setState(194);
			match(Semicolon);
			setState(196);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 1017532040844542016L) != 0)) {
				{
				setState(195);
				((For_stmtContext)_localctx).step = expression(0);
				}
			}

			setState(198);
			match(Rparenthesis);
			setState(199);
			stmt();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Flow_stmtContext extends ParserRuleContext {
		public Return_stmtContext return_stmt() {
			return getRuleContext(Return_stmtContext.class,0);
		}
		public Break_stmtContext break_stmt() {
			return getRuleContext(Break_stmtContext.class,0);
		}
		public Continue_stmtContext continue_stmt() {
			return getRuleContext(Continue_stmtContext.class,0);
		}
		public Flow_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_flow_stmt; }
	}

	public final Flow_stmtContext flow_stmt() throws RecognitionException {
		Flow_stmtContext _localctx = new Flow_stmtContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_flow_stmt);
		try {
			setState(204);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Return:
				enterOuterAlt(_localctx, 1);
				{
				setState(201);
				return_stmt();
				}
				break;
			case Break:
				enterOuterAlt(_localctx, 2);
				{
				setState(202);
				break_stmt();
				}
				break;
			case Continue:
				enterOuterAlt(_localctx, 3);
				{
				setState(203);
				continue_stmt();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Return_stmtContext extends ParserRuleContext {
		public TerminalNode Return() { return getToken(JvavParser.Return, 0); }
		public TerminalNode Semicolon() { return getToken(JvavParser.Semicolon, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public Return_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_return_stmt; }
	}

	public final Return_stmtContext return_stmt() throws RecognitionException {
		Return_stmtContext _localctx = new Return_stmtContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_return_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(206);
			match(Return);
			setState(208);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 1017532040844542016L) != 0)) {
				{
				setState(207);
				expression(0);
				}
			}

			setState(210);
			match(Semicolon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Break_stmtContext extends ParserRuleContext {
		public TerminalNode Break() { return getToken(JvavParser.Break, 0); }
		public TerminalNode Semicolon() { return getToken(JvavParser.Semicolon, 0); }
		public Break_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_break_stmt; }
	}

	public final Break_stmtContext break_stmt() throws RecognitionException {
		Break_stmtContext _localctx = new Break_stmtContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_break_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(212);
			match(Break);
			setState(213);
			match(Semicolon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Continue_stmtContext extends ParserRuleContext {
		public TerminalNode Continue() { return getToken(JvavParser.Continue, 0); }
		public TerminalNode Semicolon() { return getToken(JvavParser.Semicolon, 0); }
		public Continue_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_continue_stmt; }
	}

	public final Continue_stmtContext continue_stmt() throws RecognitionException {
		Continue_stmtContext _localctx = new Continue_stmtContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_continue_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(215);
			match(Continue);
			setState(216);
			match(Semicolon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Expr_stmtContext extends ParserRuleContext {
		public TerminalNode Semicolon() { return getToken(JvavParser.Semicolon, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(JvavParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(JvavParser.Comma, i);
		}
		public Expr_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr_stmt; }
	}

	public final Expr_stmtContext expr_stmt() throws RecognitionException {
		Expr_stmtContext _localctx = new Expr_stmtContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_expr_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(226);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 1017532040844542016L) != 0)) {
				{
				setState(218);
				expression(0);
				setState(223);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==Comma) {
					{
					{
					setState(219);
					match(Comma);
					setState(220);
					expression(0);
					}
					}
					setState(225);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(228);
			match(Semicolon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExpressionContext extends ParserRuleContext {
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	 
		public ExpressionContext() { }
		public void copyFrom(ExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class NewExprContext extends ExpressionContext {
		public New_exprContext new_expr() {
			return getRuleContext(New_exprContext.class,0);
		}
		public NewExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ThisExprContext extends ExpressionContext {
		public TerminalNode This() { return getToken(JvavParser.This, 0); }
		public ThisExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FuncExprContext extends ExpressionContext {
		public Func_exprContext func_expr() {
			return getRuleContext(Func_exprContext.class,0);
		}
		public FuncExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ArrayExprContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode Lbracket() { return getToken(JvavParser.Lbracket, 0); }
		public TerminalNode Rbracket() { return getToken(JvavParser.Rbracket, 0); }
		public ArrayExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class MemberExprContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode Dot() { return getToken(JvavParser.Dot, 0); }
		public MemberExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class BinaryExprContext extends ExpressionContext {
		public Token op;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode Mul() { return getToken(JvavParser.Mul, 0); }
		public TerminalNode Div() { return getToken(JvavParser.Div, 0); }
		public TerminalNode Mod() { return getToken(JvavParser.Mod, 0); }
		public TerminalNode Add() { return getToken(JvavParser.Add, 0); }
		public TerminalNode Sub() { return getToken(JvavParser.Sub, 0); }
		public TerminalNode Lshift() { return getToken(JvavParser.Lshift, 0); }
		public TerminalNode Rshift() { return getToken(JvavParser.Rshift, 0); }
		public TerminalNode Lessthan() { return getToken(JvavParser.Lessthan, 0); }
		public TerminalNode Greaterthan() { return getToken(JvavParser.Greaterthan, 0); }
		public TerminalNode Lessthanequal() { return getToken(JvavParser.Lessthanequal, 0); }
		public TerminalNode Greaterthanequal() { return getToken(JvavParser.Greaterthanequal, 0); }
		public TerminalNode Equal() { return getToken(JvavParser.Equal, 0); }
		public TerminalNode Notequal() { return getToken(JvavParser.Notequal, 0); }
		public TerminalNode Bitand() { return getToken(JvavParser.Bitand, 0); }
		public TerminalNode Bitxor() { return getToken(JvavParser.Bitxor, 0); }
		public TerminalNode Bitor() { return getToken(JvavParser.Bitor, 0); }
		public TerminalNode And() { return getToken(JvavParser.And, 0); }
		public TerminalNode Or() { return getToken(JvavParser.Or, 0); }
		public BinaryExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PrefixUnaryExprContext extends ExpressionContext {
		public Token op;
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode Increment() { return getToken(JvavParser.Increment, 0); }
		public TerminalNode Decrement() { return getToken(JvavParser.Decrement, 0); }
		public TerminalNode Not() { return getToken(JvavParser.Not, 0); }
		public TerminalNode Inv() { return getToken(JvavParser.Inv, 0); }
		public TerminalNode Sub() { return getToken(JvavParser.Sub, 0); }
		public PrefixUnaryExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VarExprContext extends ExpressionContext {
		public TerminalNode Identifier() { return getToken(JvavParser.Identifier, 0); }
		public VarExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TernaryExprContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode Question() { return getToken(JvavParser.Question, 0); }
		public TerminalNode Colon() { return getToken(JvavParser.Colon, 0); }
		public TernaryExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PureExprContext extends ExpressionContext {
		public TerminalNode Lparenthesis() { return getToken(JvavParser.Lparenthesis, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode Rparenthesis() { return getToken(JvavParser.Rparenthesis, 0); }
		public PureExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class AssignExprContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode Assign() { return getToken(JvavParser.Assign, 0); }
		public AssignExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SuffixUnaryExprContext extends ExpressionContext {
		public Token op;
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode Increment() { return getToken(JvavParser.Increment, 0); }
		public TerminalNode Decrement() { return getToken(JvavParser.Decrement, 0); }
		public SuffixUnaryExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConstExprContext extends ExpressionContext {
		public Const_exprContext const_expr() {
			return getRuleContext(Const_exprContext.class,0);
		}
		public ConstExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 40;
		enterRecursionRule(_localctx, 40, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(244);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,23,_ctx) ) {
			case 1:
				{
				_localctx = new PureExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(231);
				match(Lparenthesis);
				setState(232);
				expression(0);
				setState(233);
				match(Rparenthesis);
				}
				break;
			case 2:
				{
				_localctx = new ConstExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(235);
				const_expr();
				}
				break;
			case 3:
				{
				_localctx = new VarExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(236);
				match(Identifier);
				}
				break;
			case 4:
				{
				_localctx = new ThisExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(237);
				match(This);
				}
				break;
			case 5:
				{
				_localctx = new FuncExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(238);
				func_expr();
				}
				break;
			case 6:
				{
				_localctx = new NewExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(239);
				new_expr();
				}
				break;
			case 7:
				{
				_localctx = new PrefixUnaryExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(240);
				((PrefixUnaryExprContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==Increment || _la==Decrement) ) {
					((PrefixUnaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(241);
				expression(14);
				}
				break;
			case 8:
				{
				_localctx = new PrefixUnaryExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(242);
				((PrefixUnaryExprContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 35127296L) != 0)) ) {
					((PrefixUnaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(243);
				expression(13);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(297);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(295);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,24,_ctx) ) {
					case 1:
						{
						_localctx = new MemberExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(246);
						if (!(precpred(_ctx, 19))) throw new FailedPredicateException(this, "precpred(_ctx, 19)");
						setState(247);
						match(Dot);
						setState(248);
						expression(20);
						}
						break;
					case 2:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(249);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(250);
						((BinaryExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 14680064L) != 0)) ) {
							((BinaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(251);
						expression(13);
						}
						break;
					case 3:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(252);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(253);
						((BinaryExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==Add || _la==Sub) ) {
							((BinaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(254);
						expression(12);
						}
						break;
					case 4:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(255);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(256);
						((BinaryExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==Lshift || _la==Rshift) ) {
							((BinaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(257);
						expression(11);
						}
						break;
					case 5:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(258);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(259);
						((BinaryExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 4026531840L) != 0)) ) {
							((BinaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(260);
						expression(10);
						}
						break;
					case 6:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(261);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(262);
						((BinaryExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==Equal || _la==Notequal) ) {
							((BinaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(263);
						expression(9);
						}
						break;
					case 7:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(264);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(265);
						((BinaryExprContext)_localctx).op = match(Bitand);
						setState(266);
						expression(8);
						}
						break;
					case 8:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(267);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(268);
						((BinaryExprContext)_localctx).op = match(Bitxor);
						setState(269);
						expression(7);
						}
						break;
					case 9:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(270);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(271);
						((BinaryExprContext)_localctx).op = match(Bitor);
						setState(272);
						expression(6);
						}
						break;
					case 10:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(273);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(274);
						((BinaryExprContext)_localctx).op = match(And);
						setState(275);
						expression(5);
						}
						break;
					case 11:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(276);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(277);
						((BinaryExprContext)_localctx).op = match(Or);
						setState(278);
						expression(4);
						}
						break;
					case 12:
						{
						_localctx = new TernaryExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(279);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(280);
						match(Question);
						setState(281);
						expression(0);
						setState(282);
						match(Colon);
						setState(283);
						expression(2);
						}
						break;
					case 13:
						{
						_localctx = new AssignExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(285);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(286);
						match(Assign);
						setState(287);
						expression(1);
						}
						break;
					case 14:
						{
						_localctx = new ArrayExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(288);
						if (!(precpred(_ctx, 17))) throw new FailedPredicateException(this, "precpred(_ctx, 17)");
						setState(289);
						match(Lbracket);
						setState(290);
						expression(0);
						setState(291);
						match(Rbracket);
						}
						break;
					case 15:
						{
						_localctx = new SuffixUnaryExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(293);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(294);
						((SuffixUnaryExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==Increment || _la==Decrement) ) {
							((SuffixUnaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						}
						break;
					}
					} 
				}
				setState(299);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,25,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Const_exprContext extends ParserRuleContext {
		public TerminalNode True() { return getToken(JvavParser.True, 0); }
		public TerminalNode False() { return getToken(JvavParser.False, 0); }
		public TerminalNode Number() { return getToken(JvavParser.Number, 0); }
		public TerminalNode Str() { return getToken(JvavParser.Str, 0); }
		public TerminalNode Null() { return getToken(JvavParser.Null, 0); }
		public Const_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_const_expr; }
	}

	public final Const_exprContext const_expr() throws RecognitionException {
		Const_exprContext _localctx = new Const_exprContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_const_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(300);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 724516590053228544L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Func_exprContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(JvavParser.Identifier, 0); }
		public TerminalNode Lparenthesis() { return getToken(JvavParser.Lparenthesis, 0); }
		public TerminalNode Rparenthesis() { return getToken(JvavParser.Rparenthesis, 0); }
		public ArgslistContext argslist() {
			return getRuleContext(ArgslistContext.class,0);
		}
		public Func_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_expr; }
	}

	public final Func_exprContext func_expr() throws RecognitionException {
		Func_exprContext _localctx = new Func_exprContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_func_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(302);
			match(Identifier);
			setState(303);
			match(Lparenthesis);
			setState(305);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 1017532040844542016L) != 0)) {
				{
				setState(304);
				argslist();
				}
			}

			setState(307);
			match(Rparenthesis);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class New_exprContext extends ParserRuleContext {
		public Newerror_exprContext newerror_expr() {
			return getRuleContext(Newerror_exprContext.class,0);
		}
		public Newvar_exprContext newvar_expr() {
			return getRuleContext(Newvar_exprContext.class,0);
		}
		public New_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_new_expr; }
	}

	public final New_exprContext new_expr() throws RecognitionException {
		New_exprContext _localctx = new New_exprContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_new_expr);
		try {
			setState(311);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,27,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(309);
				newerror_expr();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(310);
				newvar_expr();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Newerror_exprContext extends ParserRuleContext {
		public TerminalNode New() { return getToken(JvavParser.New, 0); }
		public Basic_typeContext basic_type() {
			return getRuleContext(Basic_typeContext.class,0);
		}
		public List<TerminalNode> Lbracket() { return getTokens(JvavParser.Lbracket); }
		public TerminalNode Lbracket(int i) {
			return getToken(JvavParser.Lbracket, i);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> Rbracket() { return getTokens(JvavParser.Rbracket); }
		public TerminalNode Rbracket(int i) {
			return getToken(JvavParser.Rbracket, i);
		}
		public TerminalNode Lparenthesis() { return getToken(JvavParser.Lparenthesis, 0); }
		public TerminalNode Rparenthesis() { return getToken(JvavParser.Rparenthesis, 0); }
		public Newerror_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_newerror_expr; }
	}

	public final Newerror_exprContext newerror_expr() throws RecognitionException {
		Newerror_exprContext _localctx = new Newerror_exprContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_newerror_expr);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(313);
			match(New);
			setState(314);
			basic_type();
			setState(321);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(315);
					match(Lbracket);
					setState(316);
					expression(0);
					setState(317);
					match(Rbracket);
					}
					} 
				}
				setState(323);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
			}
			setState(326); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(324);
					match(Lbracket);
					setState(325);
					match(Rbracket);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(328); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			setState(334); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(330);
					match(Lbracket);
					setState(331);
					expression(0);
					setState(332);
					match(Rbracket);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(336); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,30,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			setState(340);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,31,_ctx) ) {
			case 1:
				{
				setState(338);
				match(Lparenthesis);
				setState(339);
				match(Rparenthesis);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Newvar_exprContext extends ParserRuleContext {
		public TerminalNode New() { return getToken(JvavParser.New, 0); }
		public Basic_typeContext basic_type() {
			return getRuleContext(Basic_typeContext.class,0);
		}
		public List<TerminalNode> Lbracket() { return getTokens(JvavParser.Lbracket); }
		public TerminalNode Lbracket(int i) {
			return getToken(JvavParser.Lbracket, i);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> Rbracket() { return getTokens(JvavParser.Rbracket); }
		public TerminalNode Rbracket(int i) {
			return getToken(JvavParser.Rbracket, i);
		}
		public TerminalNode Lparenthesis() { return getToken(JvavParser.Lparenthesis, 0); }
		public TerminalNode Rparenthesis() { return getToken(JvavParser.Rparenthesis, 0); }
		public Newvar_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_newvar_expr; }
	}

	public final Newvar_exprContext newvar_expr() throws RecognitionException {
		Newvar_exprContext _localctx = new Newvar_exprContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_newvar_expr);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(342);
			match(New);
			setState(343);
			basic_type();
			setState(350);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,32,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(344);
					match(Lbracket);
					setState(345);
					expression(0);
					setState(346);
					match(Rbracket);
					}
					} 
				}
				setState(352);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,32,_ctx);
			}
			setState(357);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,33,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(353);
					match(Lbracket);
					setState(354);
					match(Rbracket);
					}
					} 
				}
				setState(359);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,33,_ctx);
			}
			setState(362);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,34,_ctx) ) {
			case 1:
				{
				setState(360);
				match(Lparenthesis);
				setState(361);
				match(Rparenthesis);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TypenameContext extends ParserRuleContext {
		public Basic_typeContext basic_type() {
			return getRuleContext(Basic_typeContext.class,0);
		}
		public List<TerminalNode> Lbracket() { return getTokens(JvavParser.Lbracket); }
		public TerminalNode Lbracket(int i) {
			return getToken(JvavParser.Lbracket, i);
		}
		public List<TerminalNode> Rbracket() { return getTokens(JvavParser.Rbracket); }
		public TerminalNode Rbracket(int i) {
			return getToken(JvavParser.Rbracket, i);
		}
		public TypenameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typename; }
	}

	public final TypenameContext typename() throws RecognitionException {
		TypenameContext _localctx = new TypenameContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_typename);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(364);
			basic_type();
			setState(369);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Lbracket) {
				{
				{
				setState(365);
				match(Lbracket);
				setState(366);
				match(Rbracket);
				}
				}
				setState(371);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Basic_typeContext extends ParserRuleContext {
		public TerminalNode Bool() { return getToken(JvavParser.Bool, 0); }
		public TerminalNode Int() { return getToken(JvavParser.Int, 0); }
		public TerminalNode String() { return getToken(JvavParser.String, 0); }
		public TerminalNode Identifier() { return getToken(JvavParser.Identifier, 0); }
		public Basic_typeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_basic_type; }
	}

	public final Basic_typeContext basic_type() throws RecognitionException {
		Basic_typeContext _localctx = new Basic_typeContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_basic_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(372);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 387309567953862656L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 20:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 19);
		case 1:
			return precpred(_ctx, 12);
		case 2:
			return precpred(_ctx, 11);
		case 3:
			return precpred(_ctx, 10);
		case 4:
			return precpred(_ctx, 9);
		case 5:
			return precpred(_ctx, 8);
		case 6:
			return precpred(_ctx, 7);
		case 7:
			return precpred(_ctx, 6);
		case 8:
			return precpred(_ctx, 5);
		case 9:
			return precpred(_ctx, 4);
		case 10:
			return precpred(_ctx, 3);
		case 11:
			return precpred(_ctx, 2);
		case 12:
			return precpred(_ctx, 1);
		case 13:
			return precpred(_ctx, 17);
		case 14:
			return precpred(_ctx, 15);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001;\u0177\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002\u0015\u0007\u0015"+
		"\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002\u0018\u0007\u0018"+
		"\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002\u001b\u0007\u001b"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0005\u0000<\b\u0000\n\u0000\f\u0000"+
		"?\t\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0003\u0001"+
		"E\b\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0003\u0001J\b\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0005\u0002U\b\u0002\n\u0002\f\u0002X\t"+
		"\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0005\u0003]\b\u0003\n\u0003"+
		"\f\u0003`\t\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0005\u0005k\b"+
		"\u0005\n\u0005\f\u0005n\t\u0005\u0001\u0005\u0001\u0005\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0005\u0007{\b\u0007\n\u0007\f\u0007~\t\u0007\u0001"+
		"\u0007\u0001\u0007\u0001\b\u0001\b\u0001\b\u0003\b\u0085\b\b\u0001\t\u0001"+
		"\t\u0005\t\u0089\b\t\n\t\f\t\u008c\t\t\u0001\t\u0001\t\u0001\n\u0001\n"+
		"\u0001\n\u0001\n\u0001\n\u0001\n\u0003\n\u0096\b\n\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0005\u000b\u00a4\b\u000b"+
		"\n\u000b\f\u000b\u00a7\t\u000b\u0001\u000b\u0001\u000b\u0003\u000b\u00ab"+
		"\b\u000b\u0001\f\u0001\f\u0003\f\u00af\b\f\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u00ba"+
		"\b\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u00be\b\u000e\u0001\u000e"+
		"\u0003\u000e\u00c1\b\u000e\u0001\u000e\u0001\u000e\u0003\u000e\u00c5\b"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0003\u000f\u00cd\b\u000f\u0001\u0010\u0001\u0010\u0003\u0010\u00d1"+
		"\b\u0010\u0001\u0010\u0001\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001"+
		"\u0012\u0001\u0012\u0001\u0012\u0001\u0013\u0001\u0013\u0001\u0013\u0005"+
		"\u0013\u00de\b\u0013\n\u0013\f\u0013\u00e1\t\u0013\u0003\u0013\u00e3\b"+
		"\u0013\u0001\u0013\u0001\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0003\u0014\u00f5"+
		"\b\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001\u0014\u0001"+
		"\u0014\u0001\u0014\u0005\u0014\u0128\b\u0014\n\u0014\f\u0014\u012b\t\u0014"+
		"\u0001\u0015\u0001\u0015\u0001\u0016\u0001\u0016\u0001\u0016\u0003\u0016"+
		"\u0132\b\u0016\u0001\u0016\u0001\u0016\u0001\u0017\u0001\u0017\u0003\u0017"+
		"\u0138\b\u0017\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018"+
		"\u0001\u0018\u0005\u0018\u0140\b\u0018\n\u0018\f\u0018\u0143\t\u0018\u0001"+
		"\u0018\u0001\u0018\u0004\u0018\u0147\b\u0018\u000b\u0018\f\u0018\u0148"+
		"\u0001\u0018\u0001\u0018\u0001\u0018\u0001\u0018\u0004\u0018\u014f\b\u0018"+
		"\u000b\u0018\f\u0018\u0150\u0001\u0018\u0001\u0018\u0003\u0018\u0155\b"+
		"\u0018\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001\u0019\u0001"+
		"\u0019\u0005\u0019\u015d\b\u0019\n\u0019\f\u0019\u0160\t\u0019\u0001\u0019"+
		"\u0001\u0019\u0005\u0019\u0164\b\u0019\n\u0019\f\u0019\u0167\t\u0019\u0001"+
		"\u0019\u0001\u0019\u0003\u0019\u016b\b\u0019\u0001\u001a\u0001\u001a\u0001"+
		"\u001a\u0005\u001a\u0170\b\u001a\n\u001a\f\u001a\u0173\t\u001a\u0001\u001b"+
		"\u0001\u001b\u0001\u001b\u0000\u0001(\u001c\u0000\u0002\u0004\u0006\b"+
		"\n\f\u000e\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"$&(*,.02"+
		"46\u0000\t\u0001\u0000\u0011\u0012\u0002\u0000\u0013\u0014\u0019\u0019"+
		"\u0001\u0000\u0015\u0017\u0001\u0000\u0018\u0019\u0001\u0000\u001a\u001b"+
		"\u0001\u0000\u001c\u001f\u0001\u0000 !\u0003\u00001399;;\u0003\u00005"+
		"688::\u0198\u0000=\u0001\u0000\u0000\u0000\u0002D\u0001\u0000\u0000\u0000"+
		"\u0004N\u0001\u0000\u0000\u0000\u0006Y\u0001\u0000\u0000\u0000\ba\u0001"+
		"\u0000\u0000\u0000\nf\u0001\u0000\u0000\u0000\fq\u0001\u0000\u0000\u0000"+
		"\u000ev\u0001\u0000\u0000\u0000\u0010\u0081\u0001\u0000\u0000\u0000\u0012"+
		"\u0086\u0001\u0000\u0000\u0000\u0014\u0095\u0001\u0000\u0000\u0000\u0016"+
		"\u0097\u0001\u0000\u0000\u0000\u0018\u00ae\u0001\u0000\u0000\u0000\u001a"+
		"\u00b0\u0001\u0000\u0000\u0000\u001c\u00b6\u0001\u0000\u0000\u0000\u001e"+
		"\u00cc\u0001\u0000\u0000\u0000 \u00ce\u0001\u0000\u0000\u0000\"\u00d4"+
		"\u0001\u0000\u0000\u0000$\u00d7\u0001\u0000\u0000\u0000&\u00e2\u0001\u0000"+
		"\u0000\u0000(\u00f4\u0001\u0000\u0000\u0000*\u012c\u0001\u0000\u0000\u0000"+
		",\u012e\u0001\u0000\u0000\u0000.\u0137\u0001\u0000\u0000\u00000\u0139"+
		"\u0001\u0000\u0000\u00002\u0156\u0001\u0000\u0000\u00004\u016c\u0001\u0000"+
		"\u0000\u00006\u0174\u0001\u0000\u0000\u00008<\u0003\u0002\u0001\u0000"+
		"9<\u0003\b\u0004\u0000:<\u0003\u000e\u0007\u0000;8\u0001\u0000\u0000\u0000"+
		";9\u0001\u0000\u0000\u0000;:\u0001\u0000\u0000\u0000<?\u0001\u0000\u0000"+
		"\u0000=;\u0001\u0000\u0000\u0000=>\u0001\u0000\u0000\u0000>@\u0001\u0000"+
		"\u0000\u0000?=\u0001\u0000\u0000\u0000@A\u0005\u0000\u0000\u0001A\u0001"+
		"\u0001\u0000\u0000\u0000BE\u00034\u001a\u0000CE\u00057\u0000\u0000DB\u0001"+
		"\u0000\u0000\u0000DC\u0001\u0000\u0000\u0000EF\u0001\u0000\u0000\u0000"+
		"FG\u0005:\u0000\u0000GI\u0005\u0006\u0000\u0000HJ\u0003\u0004\u0002\u0000"+
		"IH\u0001\u0000\u0000\u0000IJ\u0001\u0000\u0000\u0000JK\u0001\u0000\u0000"+
		"\u0000KL\u0005\u0007\u0000\u0000LM\u0003\u0012\t\u0000M\u0003\u0001\u0000"+
		"\u0000\u0000NO\u00034\u001a\u0000OV\u0005:\u0000\u0000PQ\u0005\r\u0000"+
		"\u0000QR\u00034\u001a\u0000RS\u0005:\u0000\u0000SU\u0001\u0000\u0000\u0000"+
		"TP\u0001\u0000\u0000\u0000UX\u0001\u0000\u0000\u0000VT\u0001\u0000\u0000"+
		"\u0000VW\u0001\u0000\u0000\u0000W\u0005\u0001\u0000\u0000\u0000XV\u0001"+
		"\u0000\u0000\u0000Y^\u0003(\u0014\u0000Z[\u0005\r\u0000\u0000[]\u0003"+
		"(\u0014\u0000\\Z\u0001\u0000\u0000\u0000]`\u0001\u0000\u0000\u0000^\\"+
		"\u0001\u0000\u0000\u0000^_\u0001\u0000\u0000\u0000_\u0007\u0001\u0000"+
		"\u0000\u0000`^\u0001\u0000\u0000\u0000ab\u0005(\u0000\u0000bc\u0005:\u0000"+
		"\u0000cd\u0003\n\u0005\u0000de\u0005\u000e\u0000\u0000e\t\u0001\u0000"+
		"\u0000\u0000fl\u0005\n\u0000\u0000gk\u0003\u000e\u0007\u0000hk\u0003\u0002"+
		"\u0001\u0000ik\u0003\f\u0006\u0000jg\u0001\u0000\u0000\u0000jh\u0001\u0000"+
		"\u0000\u0000ji\u0001\u0000\u0000\u0000kn\u0001\u0000\u0000\u0000lj\u0001"+
		"\u0000\u0000\u0000lm\u0001\u0000\u0000\u0000mo\u0001\u0000\u0000\u0000"+
		"nl\u0001\u0000\u0000\u0000op\u0005\u000b\u0000\u0000p\u000b\u0001\u0000"+
		"\u0000\u0000qr\u0005:\u0000\u0000rs\u0005\u0006\u0000\u0000st\u0005\u0007"+
		"\u0000\u0000tu\u0003\u0012\t\u0000u\r\u0001\u0000\u0000\u0000vw\u0003"+
		"4\u001a\u0000w|\u0003\u0010\b\u0000xy\u0005\r\u0000\u0000y{\u0003\u0010"+
		"\b\u0000zx\u0001\u0000\u0000\u0000{~\u0001\u0000\u0000\u0000|z\u0001\u0000"+
		"\u0000\u0000|}\u0001\u0000\u0000\u0000}\u007f\u0001\u0000\u0000\u0000"+
		"~|\u0001\u0000\u0000\u0000\u007f\u0080\u0005\u000e\u0000\u0000\u0080\u000f"+
		"\u0001\u0000\u0000\u0000\u0081\u0084\u0005:\u0000\u0000\u0082\u0083\u0005"+
		"\'\u0000\u0000\u0083\u0085\u0003(\u0014\u0000\u0084\u0082\u0001\u0000"+
		"\u0000\u0000\u0084\u0085\u0001\u0000\u0000\u0000\u0085\u0011\u0001\u0000"+
		"\u0000\u0000\u0086\u008a\u0005\n\u0000\u0000\u0087\u0089\u0003\u0014\n"+
		"\u0000\u0088\u0087\u0001\u0000\u0000\u0000\u0089\u008c\u0001\u0000\u0000"+
		"\u0000\u008a\u0088\u0001\u0000\u0000\u0000\u008a\u008b\u0001\u0000\u0000"+
		"\u0000\u008b\u008d\u0001\u0000\u0000\u0000\u008c\u008a\u0001\u0000\u0000"+
		"\u0000\u008d\u008e\u0005\u000b\u0000\u0000\u008e\u0013\u0001\u0000\u0000"+
		"\u0000\u008f\u0096\u0003\u0012\t\u0000\u0090\u0096\u0003\u000e\u0007\u0000"+
		"\u0091\u0096\u0003\u0016\u000b\u0000\u0092\u0096\u0003\u0018\f\u0000\u0093"+
		"\u0096\u0003\u001e\u000f\u0000\u0094\u0096\u0003&\u0013\u0000\u0095\u008f"+
		"\u0001\u0000\u0000\u0000\u0095\u0090\u0001\u0000\u0000\u0000\u0095\u0091"+
		"\u0001\u0000\u0000\u0000\u0095\u0092\u0001\u0000\u0000\u0000\u0095\u0093"+
		"\u0001\u0000\u0000\u0000\u0095\u0094\u0001\u0000\u0000\u0000\u0096\u0015"+
		"\u0001\u0000\u0000\u0000\u0097\u0098\u0005)\u0000\u0000\u0098\u0099\u0005"+
		"\u0006\u0000\u0000\u0099\u009a\u0003(\u0014\u0000\u009a\u009b\u0005\u0007"+
		"\u0000\u0000\u009b\u00a5\u0003\u0014\n\u0000\u009c\u009d\u0005*\u0000"+
		"\u0000\u009d\u009e\u0005)\u0000\u0000\u009e\u009f\u0005\u0006\u0000\u0000"+
		"\u009f\u00a0\u0003(\u0014\u0000\u00a0\u00a1\u0005\u0007\u0000\u0000\u00a1"+
		"\u00a2\u0003\u0014\n\u0000\u00a2\u00a4\u0001\u0000\u0000\u0000\u00a3\u009c"+
		"\u0001\u0000\u0000\u0000\u00a4\u00a7\u0001\u0000\u0000\u0000\u00a5\u00a3"+
		"\u0001\u0000\u0000\u0000\u00a5\u00a6\u0001\u0000\u0000\u0000\u00a6\u00aa"+
		"\u0001\u0000\u0000\u0000\u00a7\u00a5\u0001\u0000\u0000\u0000\u00a8\u00a9"+
		"\u0005*\u0000\u0000\u00a9\u00ab\u0003\u0014\n\u0000\u00aa\u00a8\u0001"+
		"\u0000\u0000\u0000\u00aa\u00ab\u0001\u0000\u0000\u0000\u00ab\u0017\u0001"+
		"\u0000\u0000\u0000\u00ac\u00af\u0003\u001a\r\u0000\u00ad\u00af\u0003\u001c"+
		"\u000e\u0000\u00ae\u00ac\u0001\u0000\u0000\u0000\u00ae\u00ad\u0001\u0000"+
		"\u0000\u0000\u00af\u0019\u0001\u0000\u0000\u0000\u00b0\u00b1\u0005+\u0000"+
		"\u0000\u00b1\u00b2\u0005\u0006\u0000\u0000\u00b2\u00b3\u0003(\u0014\u0000"+
		"\u00b3\u00b4\u0005\u0007\u0000\u0000\u00b4\u00b5\u0003\u0014\n\u0000\u00b5"+
		"\u001b\u0001\u0000\u0000\u0000\u00b6\u00b7\u0005,\u0000\u0000\u00b7\u00bd"+
		"\u0005\u0006\u0000\u0000\u00b8\u00ba\u0003(\u0014\u0000\u00b9\u00b8\u0001"+
		"\u0000\u0000\u0000\u00b9\u00ba\u0001\u0000\u0000\u0000\u00ba\u00bb\u0001"+
		"\u0000\u0000\u0000\u00bb\u00be\u0005\u000e\u0000\u0000\u00bc\u00be\u0003"+
		"\u000e\u0007\u0000\u00bd\u00b9\u0001\u0000\u0000\u0000\u00bd\u00bc\u0001"+
		"\u0000\u0000\u0000\u00be\u00c0\u0001\u0000\u0000\u0000\u00bf\u00c1\u0003"+
		"(\u0014\u0000\u00c0\u00bf\u0001\u0000\u0000\u0000\u00c0\u00c1\u0001\u0000"+
		"\u0000\u0000\u00c1\u00c2\u0001\u0000\u0000\u0000\u00c2\u00c4\u0005\u000e"+
		"\u0000\u0000\u00c3\u00c5\u0003(\u0014\u0000\u00c4\u00c3\u0001\u0000\u0000"+
		"\u0000\u00c4\u00c5\u0001\u0000\u0000\u0000\u00c5\u00c6\u0001\u0000\u0000"+
		"\u0000\u00c6\u00c7\u0005\u0007\u0000\u0000\u00c7\u00c8\u0003\u0014\n\u0000"+
		"\u00c8\u001d\u0001\u0000\u0000\u0000\u00c9\u00cd\u0003 \u0010\u0000\u00ca"+
		"\u00cd\u0003\"\u0011\u0000\u00cb\u00cd\u0003$\u0012\u0000\u00cc\u00c9"+
		"\u0001\u0000\u0000\u0000\u00cc\u00ca\u0001\u0000\u0000\u0000\u00cc\u00cb"+
		"\u0001\u0000\u0000\u0000\u00cd\u001f\u0001\u0000\u0000\u0000\u00ce\u00d0"+
		"\u0005-\u0000\u0000\u00cf\u00d1\u0003(\u0014\u0000\u00d0\u00cf\u0001\u0000"+
		"\u0000\u0000\u00d0\u00d1\u0001\u0000\u0000\u0000\u00d1\u00d2\u0001\u0000"+
		"\u0000\u0000\u00d2\u00d3\u0005\u000e\u0000\u0000\u00d3!\u0001\u0000\u0000"+
		"\u0000\u00d4\u00d5\u0005.\u0000\u0000\u00d5\u00d6\u0005\u000e\u0000\u0000"+
		"\u00d6#\u0001\u0000\u0000\u0000\u00d7\u00d8\u0005/\u0000\u0000\u00d8\u00d9"+
		"\u0005\u000e\u0000\u0000\u00d9%\u0001\u0000\u0000\u0000\u00da\u00df\u0003"+
		"(\u0014\u0000\u00db\u00dc\u0005\r\u0000\u0000\u00dc\u00de\u0003(\u0014"+
		"\u0000\u00dd\u00db\u0001\u0000\u0000\u0000\u00de\u00e1\u0001\u0000\u0000"+
		"\u0000\u00df\u00dd\u0001\u0000\u0000\u0000\u00df\u00e0\u0001\u0000\u0000"+
		"\u0000\u00e0\u00e3\u0001\u0000\u0000\u0000\u00e1\u00df\u0001\u0000\u0000"+
		"\u0000\u00e2\u00da\u0001\u0000\u0000\u0000\u00e2\u00e3\u0001\u0000\u0000"+
		"\u0000\u00e3\u00e4\u0001\u0000\u0000\u0000\u00e4\u00e5\u0005\u000e\u0000"+
		"\u0000\u00e5\'\u0001\u0000\u0000\u0000\u00e6\u00e7\u0006\u0014\uffff\uffff"+
		"\u0000\u00e7\u00e8\u0005\u0006\u0000\u0000\u00e8\u00e9\u0003(\u0014\u0000"+
		"\u00e9\u00ea\u0005\u0007\u0000\u0000\u00ea\u00f5\u0001\u0000\u0000\u0000"+
		"\u00eb\u00f5\u0003*\u0015\u0000\u00ec\u00f5\u0005:\u0000\u0000\u00ed\u00f5"+
		"\u00050\u0000\u0000\u00ee\u00f5\u0003,\u0016\u0000\u00ef\u00f5\u0003."+
		"\u0017\u0000\u00f0\u00f1\u0007\u0000\u0000\u0000\u00f1\u00f5\u0003(\u0014"+
		"\u000e\u00f2\u00f3\u0007\u0001\u0000\u0000\u00f3\u00f5\u0003(\u0014\r"+
		"\u00f4\u00e6\u0001\u0000\u0000\u0000\u00f4\u00eb\u0001\u0000\u0000\u0000"+
		"\u00f4\u00ec\u0001\u0000\u0000\u0000\u00f4\u00ed\u0001\u0000\u0000\u0000"+
		"\u00f4\u00ee\u0001\u0000\u0000\u0000\u00f4\u00ef\u0001\u0000\u0000\u0000"+
		"\u00f4\u00f0\u0001\u0000\u0000\u0000\u00f4\u00f2\u0001\u0000\u0000\u0000"+
		"\u00f5\u0129\u0001\u0000\u0000\u0000\u00f6\u00f7\n\u0013\u0000\u0000\u00f7"+
		"\u00f8\u0005\f\u0000\u0000\u00f8\u0128\u0003(\u0014\u0014\u00f9\u00fa"+
		"\n\f\u0000\u0000\u00fa\u00fb\u0007\u0002\u0000\u0000\u00fb\u0128\u0003"+
		"(\u0014\r\u00fc\u00fd\n\u000b\u0000\u0000\u00fd\u00fe\u0007\u0003\u0000"+
		"\u0000\u00fe\u0128\u0003(\u0014\f\u00ff\u0100\n\n\u0000\u0000\u0100\u0101"+
		"\u0007\u0004\u0000\u0000\u0101\u0128\u0003(\u0014\u000b\u0102\u0103\n"+
		"\t\u0000\u0000\u0103\u0104\u0007\u0005\u0000\u0000\u0104\u0128\u0003("+
		"\u0014\n\u0105\u0106\n\b\u0000\u0000\u0106\u0107\u0007\u0006\u0000\u0000"+
		"\u0107\u0128\u0003(\u0014\t\u0108\u0109\n\u0007\u0000\u0000\u0109\u010a"+
		"\u0005\"\u0000\u0000\u010a\u0128\u0003(\u0014\b\u010b\u010c\n\u0006\u0000"+
		"\u0000\u010c\u010d\u0005#\u0000\u0000\u010d\u0128\u0003(\u0014\u0007\u010e"+
		"\u010f\n\u0005\u0000\u0000\u010f\u0110\u0005$\u0000\u0000\u0110\u0128"+
		"\u0003(\u0014\u0006\u0111\u0112\n\u0004\u0000\u0000\u0112\u0113\u0005"+
		"%\u0000\u0000\u0113\u0128\u0003(\u0014\u0005\u0114\u0115\n\u0003\u0000"+
		"\u0000\u0115\u0116\u0005&\u0000\u0000\u0116\u0128\u0003(\u0014\u0004\u0117"+
		"\u0118\n\u0002\u0000\u0000\u0118\u0119\u0005\u000f\u0000\u0000\u0119\u011a"+
		"\u0003(\u0014\u0000\u011a\u011b\u0005\u0010\u0000\u0000\u011b\u011c\u0003"+
		"(\u0014\u0002\u011c\u0128\u0001\u0000\u0000\u0000\u011d\u011e\n\u0001"+
		"\u0000\u0000\u011e\u011f\u0005\'\u0000\u0000\u011f\u0128\u0003(\u0014"+
		"\u0001\u0120\u0121\n\u0011\u0000\u0000\u0121\u0122\u0005\b\u0000\u0000"+
		"\u0122\u0123\u0003(\u0014\u0000\u0123\u0124\u0005\t\u0000\u0000\u0124"+
		"\u0128\u0001\u0000\u0000\u0000\u0125\u0126\n\u000f\u0000\u0000\u0126\u0128"+
		"\u0007\u0000\u0000\u0000\u0127\u00f6\u0001\u0000\u0000\u0000\u0127\u00f9"+
		"\u0001\u0000\u0000\u0000\u0127\u00fc\u0001\u0000\u0000\u0000\u0127\u00ff"+
		"\u0001\u0000\u0000\u0000\u0127\u0102\u0001\u0000\u0000\u0000\u0127\u0105"+
		"\u0001\u0000\u0000\u0000\u0127\u0108\u0001\u0000\u0000\u0000\u0127\u010b"+
		"\u0001\u0000\u0000\u0000\u0127\u010e\u0001\u0000\u0000\u0000\u0127\u0111"+
		"\u0001\u0000\u0000\u0000\u0127\u0114\u0001\u0000\u0000\u0000\u0127\u0117"+
		"\u0001\u0000\u0000\u0000\u0127\u011d\u0001\u0000\u0000\u0000\u0127\u0120"+
		"\u0001\u0000\u0000\u0000\u0127\u0125\u0001\u0000\u0000\u0000\u0128\u012b"+
		"\u0001\u0000\u0000\u0000\u0129\u0127\u0001\u0000\u0000\u0000\u0129\u012a"+
		"\u0001\u0000\u0000\u0000\u012a)\u0001\u0000\u0000\u0000\u012b\u0129\u0001"+
		"\u0000\u0000\u0000\u012c\u012d\u0007\u0007\u0000\u0000\u012d+\u0001\u0000"+
		"\u0000\u0000\u012e\u012f\u0005:\u0000\u0000\u012f\u0131\u0005\u0006\u0000"+
		"\u0000\u0130\u0132\u0003\u0006\u0003\u0000\u0131\u0130\u0001\u0000\u0000"+
		"\u0000\u0131\u0132\u0001\u0000\u0000\u0000\u0132\u0133\u0001\u0000\u0000"+
		"\u0000\u0133\u0134\u0005\u0007\u0000\u0000\u0134-\u0001\u0000\u0000\u0000"+
		"\u0135\u0138\u00030\u0018\u0000\u0136\u0138\u00032\u0019\u0000\u0137\u0135"+
		"\u0001\u0000\u0000\u0000\u0137\u0136\u0001\u0000\u0000\u0000\u0138/\u0001"+
		"\u0000\u0000\u0000\u0139\u013a\u00054\u0000\u0000\u013a\u0141\u00036\u001b"+
		"\u0000\u013b\u013c\u0005\b\u0000\u0000\u013c\u013d\u0003(\u0014\u0000"+
		"\u013d\u013e\u0005\t\u0000\u0000\u013e\u0140\u0001\u0000\u0000\u0000\u013f"+
		"\u013b\u0001\u0000\u0000\u0000\u0140\u0143\u0001\u0000\u0000\u0000\u0141"+
		"\u013f\u0001\u0000\u0000\u0000\u0141\u0142\u0001\u0000\u0000\u0000\u0142"+
		"\u0146\u0001\u0000\u0000\u0000\u0143\u0141\u0001\u0000\u0000\u0000\u0144"+
		"\u0145\u0005\b\u0000\u0000\u0145\u0147\u0005\t\u0000\u0000\u0146\u0144"+
		"\u0001\u0000\u0000\u0000\u0147\u0148\u0001\u0000\u0000\u0000\u0148\u0146"+
		"\u0001\u0000\u0000\u0000\u0148\u0149\u0001\u0000\u0000\u0000\u0149\u014e"+
		"\u0001\u0000\u0000\u0000\u014a\u014b\u0005\b\u0000\u0000\u014b\u014c\u0003"+
		"(\u0014\u0000\u014c\u014d\u0005\t\u0000\u0000\u014d\u014f\u0001\u0000"+
		"\u0000\u0000\u014e\u014a\u0001\u0000\u0000\u0000\u014f\u0150\u0001\u0000"+
		"\u0000\u0000\u0150\u014e\u0001\u0000\u0000\u0000\u0150\u0151\u0001\u0000"+
		"\u0000\u0000\u0151\u0154\u0001\u0000\u0000\u0000\u0152\u0153\u0005\u0006"+
		"\u0000\u0000\u0153\u0155\u0005\u0007\u0000\u0000\u0154\u0152\u0001\u0000"+
		"\u0000\u0000\u0154\u0155\u0001\u0000\u0000\u0000\u01551\u0001\u0000\u0000"+
		"\u0000\u0156\u0157\u00054\u0000\u0000\u0157\u015e\u00036\u001b\u0000\u0158"+
		"\u0159\u0005\b\u0000\u0000\u0159\u015a\u0003(\u0014\u0000\u015a\u015b"+
		"\u0005\t\u0000\u0000\u015b\u015d\u0001\u0000\u0000\u0000\u015c\u0158\u0001"+
		"\u0000\u0000\u0000\u015d\u0160\u0001\u0000\u0000\u0000\u015e\u015c\u0001"+
		"\u0000\u0000\u0000\u015e\u015f\u0001\u0000\u0000\u0000\u015f\u0165\u0001"+
		"\u0000\u0000\u0000\u0160\u015e\u0001\u0000\u0000\u0000\u0161\u0162\u0005"+
		"\b\u0000\u0000\u0162\u0164\u0005\t\u0000\u0000\u0163\u0161\u0001\u0000"+
		"\u0000\u0000\u0164\u0167\u0001\u0000\u0000\u0000\u0165\u0163\u0001\u0000"+
		"\u0000\u0000\u0165\u0166\u0001\u0000\u0000\u0000\u0166\u016a\u0001\u0000"+
		"\u0000\u0000\u0167\u0165\u0001\u0000\u0000\u0000\u0168\u0169\u0005\u0006"+
		"\u0000\u0000\u0169\u016b\u0005\u0007\u0000\u0000\u016a\u0168\u0001\u0000"+
		"\u0000\u0000\u016a\u016b\u0001\u0000\u0000\u0000\u016b3\u0001\u0000\u0000"+
		"\u0000\u016c\u0171\u00036\u001b\u0000\u016d\u016e\u0005\b\u0000\u0000"+
		"\u016e\u0170\u0005\t\u0000\u0000\u016f\u016d\u0001\u0000\u0000\u0000\u0170"+
		"\u0173\u0001\u0000\u0000\u0000\u0171\u016f\u0001\u0000\u0000\u0000\u0171"+
		"\u0172\u0001\u0000\u0000\u0000\u01725\u0001\u0000\u0000\u0000\u0173\u0171"+
		"\u0001\u0000\u0000\u0000\u0174\u0175\u0007\b\u0000\u0000\u01757\u0001"+
		"\u0000\u0000\u0000$;=DIV^jl|\u0084\u008a\u0095\u00a5\u00aa\u00ae\u00b9"+
		"\u00bd\u00c0\u00c4\u00cc\u00d0\u00df\u00e2\u00f4\u0127\u0129\u0131\u0137"+
		"\u0141\u0148\u0150\u0154\u015e\u0165\u016a\u0171";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}