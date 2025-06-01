#include "AST/ASTCollection.h"
#include "JvavParserBaseVisitor.h"
#include "JvavParser.h"

#include<vector>

class ASTBuilder : public JvavParserBaseVisitor {
    Type *IntType = new intType();
    Type *BoolType = new boolType();
    Type *StringType = new stringType();
    Type *VoidType = new voidType();
    Type *NullType = new nullType();

    std::any visitProgram(JvavParser::ProgramContext *ctx) override {
        std::vector<defNode*> DefNodes;

        for (auto Def : ctx->children) {
            if (auto varDef = dynamic_cast<JvavParser::Var_defContext*>(Def)) {
                DefNodes.push_back(std::any_cast<varDefNode*>(visit(varDef)));
            } 
            else if (auto funcDef = dynamic_cast<JvavParser::Func_defContext*>(Def)) {
                DefNodes.push_back(std::any_cast<funcDefNode*>(visit(funcDef)));
            } 
            else if (auto classDef = dynamic_cast<JvavParser::Class_defContext*>(Def)) {
                DefNodes.push_back(std::any_cast<classDefNode*>(visit(classDef)));
            }
        }

        return new rootNode(DefNodes);
    }

    std::any visitFunc_def(JvavParser::Func_defContext *ctx) override {
        typeNode *type;
        if (ctx->typename_() != nullptr) {
            type = std::any_cast<typeNode*>(visit(ctx->typename_()));
        }
        else {
            type = new typeNode(VoidType);
        }

        std::string name = ctx->Identifier()->getText();

        std::vector<paramNode*> paramNodes;

        auto params = ctx->typedargslist();

        if(params != nullptr) {
            int size = params->typename_().size();
            for(int i = 0; i < size; i++) {
                auto paramType = std::any_cast<typeNode*>(visit(params->typename_(i)));
                std::string paramName = params->Identifier(i)->getText();

                paramNodes.push_back(new paramNode(paramType, paramName));
            }
        }

        auto suite = std::any_cast<blockStmtNode*>(visit(ctx->suite()));

        return new funcDefNode(type, name, paramNodes, suite);
    }

    std::any visitClass_def(JvavParser::Class_defContext *ctx) override {
        std::string name = ctx->Identifier()->getText();
        auto classStmts = ctx->class_suite();
        std::vector<funcDefNode*> funcDefNodes;
        for (auto funcDef : classStmts->func_def()) {
            if (funcDef != nullptr) {
                funcDefNodes.push_back(std::any_cast<funcDefNode*>(visit(funcDef)));
            }
        }
        std::vector<varDefNode*> varDefNodes;
        for (auto varDef : classStmts->var_def()) {
            if (varDef != nullptr) {
                varDefNodes.push_back(std::any_cast<varDefNode*>(visit(varDef)));
            }
        }
        if (classStmts->construct_stmt().size() > 1) {
            std::runtime_error("Constructor Number Exceed");
        } 
        else if (classStmts->construct_stmt().size() == 1) {
            auto constructStmt = classStmts->construct_stmt(0);
            if (!(constructStmt->Identifier()->getText() == name)) {
                std::runtime_error("Constructor Name Error");
            }
            funcDefNodes.push_back(std::any_cast<funcDefNode*>(visit(constructStmt)));
        }
        return new classDefNode(name, varDefNodes, funcDefNodes);
    }

    std::any visitConstruct_stmt(JvavParser::Construct_stmtContext *ctx) override {
        typeNode *type = new typeNode(NullType);
        std::string name = ctx->Identifier()->getText();
        blockStmtNode *suite = std::any_cast<blockStmtNode*>(visit(ctx->suite()));
        return new funcDefNode(type, name, {}, suite);
    }

    std::any visitVar_def(JvavParser::Var_defContext *ctx) override {
        typeNode *type = std::any_cast<typeNode*>(visit(ctx->typename_()));
        std::vector<varNode*> vars;
        for (auto varStmt : ctx->var_stmt()) {
            if (varStmt != nullptr) {
                vars.push_back(std::any_cast<varNode*>(visit(varStmt)));
            }
        }
        return new varDefNode(type, vars);
    }

    std::any visitVar_stmt(JvavParser::Var_stmtContext *ctx) override {
        std::string name = ctx->Identifier()->getText();
        ExprNode *init = nullptr;
        if (ctx->expression() != nullptr) {
            init = std::any_cast<ExprNode*>(visit(ctx->expression()));
        }
        return new varNode(name, init);
    }

    std::any visitSuite(JvavParser::SuiteContext *ctx) override {
        std::vector<StmtNode*> stmts;
        for (auto stmt : ctx->stmt()) {
            if (stmt != nullptr) {
                stmts.push_back(std::any_cast<StmtNode*>(visit(stmt)));
            }
        }
        return new blockStmtNode(stmts);
    }

    std::any visitBranch_stmt(JvavParser::Branch_stmtContext *ctx) override {
        std::vector<ExprNode*> exprs;
        for (auto expr : ctx->expression()) {
            if (expr != nullptr) {
                exprs.push_back(std::any_cast<ExprNode*>(visit(expr)));
            }
        }
        std::vector<StmtNode*> stmts;
        for (auto stmt : ctx->stmt()) {
            if (stmt != nullptr) {
                stmts.push_back(std::any_cast<StmtNode*>(visit(stmt)));
            }
        }
        return new branchStmtNode(exprs, stmts);
    }

    std::any visitBlock(JvavParser::BlockContext *ctx) override {
        return visit(ctx->suite());
    }

    std::any visitVarDefStmt(JvavParser::VarDefStmtContext *ctx) override {
        varDefNode *varDef = std::any_cast<varDefNode*>(visit(ctx->var_def()));
        return new varDefStmtNode(varDef->typeName, varDef->var);
    }

    std::any visitBranchStmt(JvavParser::BranchStmtContext *ctx) override {
        return visit(ctx->branch_stmt());
    }

    std::any visitLoop_stmt(JvavParser::Loop_stmtContext *ctx) override {
        if (ctx->while_stmt() != nullptr) {
            return visit(ctx->while_stmt());
        } 
        else {
            return visit(ctx->for_stmt());
        }
    }

    std::any visitWhile_stmt(JvavParser::While_stmtContext *ctx) override {
        ExprNode *cond = std::any_cast<ExprNode*>(visit(ctx->expression()));
        StmtNode *stmt = std::any_cast<StmtNode*>(visit(ctx->stmt()));
        return new whileStmtNode(cond, stmt);
    }

    std::any visitFor_stmt(JvavParser::For_stmtContext *ctx) override {
        ExprNode *cond = nullptr;
        if (ctx->cond != nullptr) {
            cond = std::any_cast<ExprNode*>(visit(ctx->cond));
        }
        ExprNode *step = nullptr;
        if (ctx->step != nullptr) {
            step = std::any_cast<ExprNode*>(visit(ctx->step));
        }
        StmtNode *stmt = std::any_cast<StmtNode*>(visit(ctx->stmt()));
        if (ctx->var_def() != nullptr) {
            varDefStmtNode *init = new varDefStmtNode(std::any_cast<varDefNode*>(visit(ctx->var_def())));
            return new forDefStmtNode(init, cond, step, stmt);
        } 
        else {
            ExprNode *init = nullptr;
            if (ctx->init != nullptr) {
                init = std::any_cast<ExprNode*>(visit(ctx->init));
            }
            return new forExprStmtNode(init, cond, step, stmt);
        }
    }

    std::any visitLoopStmt(JvavParser::LoopStmtContext *ctx) override {
        return visit(ctx->loop_stmt());
    }

    std::any visitFlow_stmt(JvavParser::Flow_stmtContext *ctx) override {
        if (ctx->return_stmt() != nullptr) {
            return visit(ctx->return_stmt());
        } 
        else if (ctx->break_stmt() != nullptr) {
            return visit(ctx->break_stmt());
        } 
        else {
            return visit(ctx->continue_stmt());
        }
    }

    std::any visitReturn_stmt(JvavParser::Return_stmtContext *ctx) {
        ExprNode *ret = nullptr;
        if (ctx->expression() != nullptr) {
            ret = std::any_cast<ExprNode*>(visit(ctx->expression()));
        }
        return new returnStmtNode(ret);
    }

    std::any visitBreak_stmt(JvavParser::Break_stmtContext *ctx) {
        return new breakStmtNode();
    }

    std::any visitContinue_stmt(JvavParser::Continue_stmtContext *ctx) {
        return new continueStmtNode();
    }

    std::any visitFlowStmt(JvavParser::FlowStmtContext *ctx) {
        return visit(ctx->flow_stmt());
    }

    std::any visitExpr_stmt(JvavParser::Expr_stmtContext *ctx) {
        std::vector<ExprNode*> exprs;
        for (auto Expr : ctx->expression()) {
            if (Expr != nullptr) {
                exprs.push_back(std::any_cast<ExprNode*>(visit(Expr)));
            }
        }
        return new exprStmtNode(exprs);
    }

    std::any visitExprStmt(JvavParser::ExprStmtContext *ctx) {
        return visit(ctx->expr_stmt());
    }

    std::any visitPureExpr(JvavParser::PureExprContext *ctx) {
        return visit(ctx->expression());
    }

    std::any visitConst_expr(JvavParser::Const_exprContext *ctx) {
        if (ctx->True() != nullptr) {
            return new boolNode(true);
        } 
        else if (ctx->False() != nullptr) {
            return new boolNode(false);
        } 
        else if (ctx->Number() != nullptr) {
            return new numberNode(stoll(ctx->Number()->getText()));
        } 
        else if (ctx->Str() != nullptr) {
            std::string str = ctx->Str()->getText().substr(1, ctx->Str()->getText().length() - 1);
            return new strNode(str);
        } 
        else {
            return new nullNode();
        }
    }

    std::any visitConstExpr(JvavParser::ConstExprContext *ctx) {
        return visit(ctx->const_expr());
    }

    std::any visitVarExpr(JvavParser::VarExprContext *ctx) {
        std::string name = ctx->Identifier()->getText();
        return new varExprNode(name);
    }

    std::any visitThisExpr(JvavParser::ThisExprContext *ctx) {
        return new thisExprNode();
    }

    std::any visitFunc_expr(JvavParser::Func_exprContext *ctx) {
        std::string name = ctx->Identifier()->getText();
        std::vector<ExprNode*> args;
        if (ctx->argslist() != nullptr) {
            auto Args = ctx->argslist();
            for (auto expr : Args->expression()) {
                if (expr != nullptr) {
                    args.push_back(std::any_cast<ExprNode*>(visit(expr)));
                }
            }
        }
        return new funcExprNode(args, name);
    }

    std::any visitFuncExpr(JvavParser::FuncExprContext *ctx) {
        return visit(ctx->func_expr());
    }

    std::any visitMemberExpr(JvavParser::MemberExprContext *ctx) {
        ExprNode *expr = std::any_cast<ExprNode*>(visit(ctx->expression(0)));
        ASTNode *member = std::any_cast<ASTNode*>(visit(ctx->expression(1)));
        if (auto func = dynamic_cast<funcExprNode*>(member)) {
            return new memberFuncExprNode(expr, func);
        } 
        else if (auto var = dynamic_cast<varExprNode*>(member)) {
            std::string name = var->name;
            return new memberVarExprNode(expr, name);
        } else {
            throw std::runtime_error("Member type wrong");
        }
    }

    std::any visitArrayExpr(JvavParser::ArrayExprContext *ctx) {
        ExprNode *name = std::any_cast<ExprNode*>(visit(ctx->expression(0)));
        ExprNode *index = std::any_cast<ExprNode*>(visit(ctx->expression(1)));
        return new arrayExprNode(name, index);
    }

    std::any visitNewvar_expr(JvavParser::Newvar_exprContext *ctx) {
        Type *type = (std::any_cast<typeNode*>(visit(ctx->basic_type())))->type;
        std::vector<ExprNode*> exprs;
        for (auto Expr : ctx->expression()) {
            if (Expr != nullptr) {
                exprs.push_back(std::any_cast<ExprNode*>(visit(Expr)));
            }
        }
        int dim = ctx->Lbracket().size();
        return new newExprNode(type, exprs, dim);
    }

    std::any visitNew_expr(JvavParser::New_exprContext *ctx) {
        if (ctx->newerror_expr() != nullptr) {
            throw "New array expression wrong";
        } else {
            return visit(ctx->newvar_expr());
        }
    }

    std::any visitNewExpr(JvavParser::NewExprContext *ctx) {
        return visit(ctx->new_expr());
    }

    std::any visitSuffixUnaryExpr(JvavParser::SuffixUnaryExprContext *ctx) {
        ExprNode *expr = std::any_cast<ExprNode*>(visit(ctx->expression()));
        suffixUnaryExprNode::suffixOpType opCode;
        auto Op = ctx->op->getText();
        if (Op == "++") {
            opCode = suffixUnaryExprNode::suffixOpType::Inc;
        } 
        else if (Op == "--") {
            opCode = suffixUnaryExprNode::suffixOpType::Dec;
        } 
        else {
            throw std::runtime_error("Wrong Suffix Unary Opcode");
        }
        return new suffixUnaryExprNode(expr, opCode);
    }

    std::any visitPrefixUnaryExpr(JvavParser::PrefixUnaryExprContext *ctx) {
        ExprNode *expr = std::any_cast<ExprNode*>(visit(ctx->expression()));
        prefixUnaryExprNode::prefixOpType opCode;
        auto Op = ctx->op->getText();

        if(Op == "++") opCode = prefixUnaryExprNode::prefixOpType::Inc;
        else if(Op == "--") opCode = prefixUnaryExprNode::prefixOpType::Dec;
        else if(Op == "!") opCode = prefixUnaryExprNode::prefixOpType::Not;
        else if(Op == "~") opCode = prefixUnaryExprNode::prefixOpType::Inv;
        else if(Op == "-") opCode = prefixUnaryExprNode::prefixOpType::Sub;
        else throw std::runtime_error("Wrong Prefix Unary Opcode");

        return new prefixUnaryExprNode(expr, opCode);
    }

    std::any visitBinaryExpr(JvavParser::BinaryExprContext *ctx) {
        ExprNode *lhs = std::any_cast<ExprNode*>(visit(ctx->expression(0)));
        ExprNode *rhs = std::any_cast<ExprNode*>(visit(ctx->expression(1)));
        binaryExprNode::binaryOpType opCode;
        auto Op = ctx->op->getText();

        if (Op == "*") opCode = binaryExprNode::binaryOpType::Mul;
        else if (Op == "/") opCode = binaryExprNode::binaryOpType::Div;
        else if (Op == "%") opCode = binaryExprNode::binaryOpType::Mod;
        else if (Op == "+") opCode = binaryExprNode::binaryOpType::Add;
        else if (Op == "-") opCode = binaryExprNode::binaryOpType::Sub;
        else if (Op == "<<") opCode = binaryExprNode::binaryOpType::Lshift;
        else if (Op == ">>") opCode = binaryExprNode::binaryOpType::Rshift;
        else if (Op == "<") opCode = binaryExprNode::binaryOpType::Le;
        else if (Op == ">") opCode = binaryExprNode::binaryOpType::Ge;
        else if (Op == "<=") opCode = binaryExprNode::binaryOpType::Leq;
        else if (Op == ">=") opCode = binaryExprNode::binaryOpType::Geq;
        else if (Op == "==") opCode = binaryExprNode::binaryOpType::Eq;
        else if (Op == "!=") opCode = binaryExprNode::binaryOpType::Neq;
        else if (Op == "&") opCode = binaryExprNode::binaryOpType::Bitand;
        else if (Op == "^") opCode = binaryExprNode::binaryOpType::Bitxor;
        else if (Op == "|") opCode = binaryExprNode::binaryOpType::Bitor;
        else if (Op == "&&") opCode = binaryExprNode::binaryOpType::And;
        else if (Op == "||") opCode = binaryExprNode::binaryOpType::Or;
        else throw std::runtime_error("Wrong Binary Unary Opcode");

        return new binaryExprNode(lhs, rhs, opCode);
    }

    std::any visitTernaryExpr(JvavParser::TernaryExprContext *ctx) {
        ExprNode *cond = std::any_cast<ExprNode*>(visit(ctx->expression(0)));
        ExprNode *thenExpr = std::any_cast<ExprNode*>(visit(ctx->expression(1)));
        ExprNode *elseExpr = std::any_cast<ExprNode*>(visit(ctx->expression(2)));
        return new ternaryExprNode(cond, thenExpr, elseExpr);
    }

    std::any visitAssignExpr(JvavParser::AssignExprContext *ctx) {
        ExprNode *lhs = std::any_cast<ExprNode*>(visit(ctx->expression(0)));
        ExprNode *rhs = std::any_cast<ExprNode*>(visit(ctx->expression(1)));
        return new assignExprNode(lhs, rhs);
    }

    std::any visitTypename(JvavParser::TypenameContext *ctx) {
        if (!ctx->Lbracket().size()) {
            return visit(ctx->basic_type());
        } 
        else {
            auto elemType = (std::any_cast<typeNode>(visit(ctx->basic_type()))).type;
            int dim = ctx->Lbracket().size();
            arrayType *ArrayType = new arrayType(elemType, dim);
            return new typeNode(ArrayType);
        }
    }

    std::any visitBasic_type(JvavParser::Basic_typeContext *ctx) {
        if (ctx->Bool() != nullptr) {
            return new typeNode(BoolType);
        } 
        else if (ctx->Int() != nullptr) {
            return new typeNode(IntType);
        } 
        else if (ctx->String() != nullptr) {
            return new typeNode(StringType);
        } 
        else {
            auto ClassType = new classType(ctx->Identifier()->getText());
            return new typeNode(ClassType);
        }
    }

};

