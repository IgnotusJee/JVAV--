parser grammar JvavParser;

options {
    tokenVocab = JvavLexer;
}

program: (func_def | class_def | var_def)* EOF;

func_def: (typename | Void) Identifier Lparenthesis typedargslist? Rparenthesis suite;
typedargslist: typename Identifier (Comma typename Identifier)*;
argslist: expression (Comma expression)*;

class_def: Class Identifier class_suite Semicolon;
class_suite: Lbrace (var_def | func_def | construct_stmt)* Rbrace;
construct_stmt: Identifier Lparenthesis Rparenthesis suite;
    
var_def: typename var_stmt (Comma var_stmt)* Semicolon;
var_stmt: Identifier (Assign expression)?;

suite: Lbrace stmt* Rbrace;

stmt
    : suite             #block
    | var_def           #varDefStmt
    | branch_stmt       #branchStmt
    | loop_stmt         #loopStmt
    | flow_stmt         #flowStmt
    | expr_stmt         #exprStmt
    ;

branch_stmt: If Lparenthesis expression Rparenthesis stmt
            (Else If Lparenthesis expression Rparenthesis stmt)* (Else stmt)?;

loop_stmt: while_stmt | for_stmt;
while_stmt: While Lparenthesis expression Rparenthesis stmt;
for_stmt: For Lparenthesis ((init=expression? Semicolon) | var_def)
          cond=expression? Semicolon step=expression? Rparenthesis stmt;

flow_stmt: return_stmt | break_stmt | continue_stmt;
return_stmt: Return expression? Semicolon;
break_stmt: Break Semicolon;
continue_stmt: Continue Semicolon;

expr_stmt: (expression (Comma expression)*)? Semicolon;

expression
    : Lparenthesis expression Rparenthesis              #pureExpr      
    | const_expr                                        #constExpr
    | Identifier                                        #varExpr
    | This                                              #thisExpr
    | expression Dot expression                         #memberExpr
    | func_expr                                         #funcExpr
    | expression Lbracket expression Rbracket           #arrayExpr
    | new_expr                                          #newExpr
    | expression op = (Increment | Decrement)           #suffixUnaryExpr
    | <assoc=right> op = (Increment |
                          Decrement) expression         #prefixUnaryExpr
    | <assoc=right> op = (Not | Inv | Sub) expression   #prefixUnaryExpr
    | expression op = (Mul | Div | Mod) expression      #binaryExpr
    | expression op = (Add | Sub) expression            #binaryExpr
    | expression op = (Lshift | Rshift) expression      #binaryExpr
    | expression op = (Lessthan | Greaterthan |
      Lessthanequal | Greaterthanequal) expression      #binaryExpr
    | expression op = (Equal | Notequal) expression     #binaryExpr
    | expression op = Bitand expression                 #binaryExpr
    | expression op = Bitxor expression                 #binaryExpr
    | expression op = Bitor  expression                 #binaryExpr
    | expression op = And    expression                 #binaryExpr
    | expression op = Or     expression                 #binaryExpr
    | <assoc=right> expression Question
      expression Colon expression                       #ternaryExpr
    | <assoc=right> expression Assign expression        #assignExpr
    ;

const_expr: True | False | Number | Str | Null;
func_expr: Identifier Lparenthesis argslist? Rparenthesis;
new_expr: newerror_expr | newvar_expr;
newerror_expr : New basic_type (Lbracket expression Rbracket)*
          (Lbracket Rbracket)+ (Lbracket expression Rbracket)+ (Lparenthesis Rparenthesis)?;
newvar_expr : New basic_type (Lbracket expression Rbracket)*
          (Lbracket Rbracket)* (Lparenthesis Rparenthesis)?;

typename: basic_type (Lbracket Rbracket)*;
basic_type: Bool | Int | String | Identifier;


