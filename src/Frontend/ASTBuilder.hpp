#include "AST/ASTCollection.h"
#include "JvavParserBaseVisitor.h"
#include "JvavParser.h"

#include<vector>

template <typename T>
T safeAnyCast(const std::any &a) {
    ASTNode* ptr;
    try {
        ptr = std::any_cast<ASTNode*>(a);
    }
    catch(...) {
        std::cout << "Bad cast of " << typeid(T).name() << std::endl;
    }
    return dynamic_cast<T>(ptr);
}

class ASTBuilder : public JvavParserBaseVisitor {
    AST::Type *IntType = new AST::intType();
    AST::Type *BoolType = new AST::boolType();
    AST::Type *StringType = new AST::stringType();
    AST::Type *VoidType = new AST::voidType();
    AST::Type *NullType = new AST::nullType();

    std::any visitProgram(JvavParser::ProgramContext *ctx) override {
        std::vector<defNode*> DefNodes;

        for (auto Def : ctx->children) {
            if (auto varDef = dynamic_cast<JvavParser::Var_defContext*>(Def)) {
                DefNodes.push_back(safeAnyCast<varDefNode*>(visit(varDef)));
            } 
            else if (auto funcDef = dynamic_cast<JvavParser::Func_defContext*>(Def)) {
                DefNodes.push_back(safeAnyCast<funcDefNode*>(visit(funcDef)));
            } 
            else if (auto classDef = dynamic_cast<JvavParser::Class_defContext*>(Def)) {
                DefNodes.push_back(safeAnyCast<classDefNode*>(visit(classDef)));
            }
        }

        return dynamic_cast<ASTNode*>(new rootNode(DefNodes));
    }

    std::any visitFunc_def(JvavParser::Func_defContext *ctx) override {
        typeNode *type;
        if (ctx->typename_() != nullptr) {
            type = safeAnyCast<typeNode*>(visit(ctx->typename_()));
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
                auto paramType = safeAnyCast<typeNode*>(visit(params->typename_(i)));
                std::string paramName = params->Identifier(i)->getText();

                paramNodes.push_back(new paramNode(paramType, paramName));
            }
        }

        auto suite = safeAnyCast<blockStmtNode*>(visit(ctx->suite()));

        return dynamic_cast<ASTNode*>(new funcDefNode(type, name, paramNodes, suite));
    }

    std::any visitClass_def(JvavParser::Class_defContext *ctx) override {
        std::string name = ctx->Identifier()->getText();
        auto classStmts = ctx->class_suite();
        std::vector<funcDefNode*> funcDefNodes;
        for (auto funcDef : classStmts->func_def()) {
            if (funcDef != nullptr) {
                funcDefNodes.push_back(safeAnyCast<funcDefNode*>(visit(funcDef)));
            }
        }
        std::vector<varDefNode*> varDefNodes;
        for (auto varDef : classStmts->var_def()) {
            if (varDef != nullptr) {
                varDefNodes.push_back(safeAnyCast<varDefNode*>(visit(varDef)));
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
            funcDefNodes.push_back(safeAnyCast<funcDefNode*>(visit(constructStmt)));
        }
        return dynamic_cast<ASTNode*>(new classDefNode(name, varDefNodes, funcDefNodes));
    }

    std::any visitConstruct_stmt(JvavParser::Construct_stmtContext *ctx) override {
        typeNode *type = new typeNode(NullType);
        std::string name = ctx->Identifier()->getText();
        blockStmtNode *suite = safeAnyCast<blockStmtNode*>(visit(ctx->suite()));
        return dynamic_cast<ASTNode*>(new funcDefNode(type, name, {}, suite));
    }

    std::any visitVar_def(JvavParser::Var_defContext *ctx) override {
        typeNode *type = safeAnyCast<typeNode*>(visit(ctx->typename_()));
        std::vector<varNode*> vars;
        for (auto varStmt : ctx->var_stmt()) {
            if (varStmt != nullptr) {
                vars.push_back(safeAnyCast<varNode*>(visit(varStmt)));
            }
        }
        return dynamic_cast<ASTNode*>(new varDefNode(type, vars));
    }

    std::any visitVar_stmt(JvavParser::Var_stmtContext *ctx) override {
        std::string name = ctx->Identifier()->getText();
        ExprNode *init = nullptr;
        if (ctx->expression() != nullptr) {
            init = safeAnyCast<ExprNode*>(visit(ctx->expression()));
        }
        return dynamic_cast<ASTNode*>(new varNode(name, init));
    }

    std::any visitSuite(JvavParser::SuiteContext *ctx) override {
        std::vector<StmtNode*> stmts;
        for (auto stmt : ctx->stmt()) {
            if (stmt != nullptr) {
                stmts.push_back(safeAnyCast<StmtNode*>(visit(stmt)));
            }
        }
        return dynamic_cast<ASTNode*>(new blockStmtNode(stmts));
    }

    std::any visitBranch_stmt(JvavParser::Branch_stmtContext *ctx) override {
        std::vector<ExprNode*> exprs;
        for (auto expr : ctx->expression()) {
            if (expr != nullptr) {
                exprs.push_back(safeAnyCast<ExprNode*>(visit(expr)));
            }
        }
        std::vector<StmtNode*> stmts;
        for (auto stmt : ctx->stmt()) {
            if (stmt != nullptr) {
                stmts.push_back(safeAnyCast<StmtNode*>(visit(stmt)));
            }
        }
        return dynamic_cast<ASTNode*>(new branchStmtNode(exprs, stmts));
    }

    std::any visitBlock(JvavParser::BlockContext *ctx) override {
        return visit(ctx->suite());
    }

    std::any visitVarDefStmt(JvavParser::VarDefStmtContext *ctx) override {
        varDefNode *varDef = safeAnyCast<varDefNode*>(visit(ctx->var_def()));
        return dynamic_cast<ASTNode*>(new varDefStmtNode(varDef->typeName, varDef->var));
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
        ExprNode *cond = safeAnyCast<ExprNode*>(visit(ctx->expression()));
        StmtNode *stmt = safeAnyCast<StmtNode*>(visit(ctx->stmt()));
        return dynamic_cast<ASTNode*>(new whileStmtNode(cond, stmt));
    }

    std::any visitFor_stmt(JvavParser::For_stmtContext *ctx) override {
        ExprNode *cond = nullptr;
        if (ctx->cond != nullptr) {
            cond = safeAnyCast<ExprNode*>(visit(ctx->cond));
        }
        ExprNode *step = nullptr;
        if (ctx->step != nullptr) {
            step = safeAnyCast<ExprNode*>(visit(ctx->step));
        }
        StmtNode *stmt = safeAnyCast<StmtNode*>(visit(ctx->stmt()));
        if (ctx->var_def() != nullptr) {
            varDefStmtNode *init = new varDefStmtNode(safeAnyCast<varDefNode*>(visit(ctx->var_def())));
            return dynamic_cast<ASTNode*>(new forDefStmtNode(init, cond, step, stmt));
        } 
        else {
            ExprNode *init = nullptr;
            if (ctx->init != nullptr) {
                init = safeAnyCast<ExprNode*>(visit(ctx->init));
            }
            return dynamic_cast<ASTNode*>(new forExprStmtNode(init, cond, step, stmt));
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

    std::any visitReturn_stmt(JvavParser::Return_stmtContext *ctx) override {
        ExprNode *ret = nullptr;
        if (ctx->expression() != nullptr) {
            ret = safeAnyCast<ExprNode*>(visit(ctx->expression()));
        }
        return dynamic_cast<ASTNode*>(new returnStmtNode(ret));
    }

    std::any visitBreak_stmt(JvavParser::Break_stmtContext *ctx) override {
        return dynamic_cast<ASTNode*>(new breakStmtNode());
    }

    std::any visitContinue_stmt(JvavParser::Continue_stmtContext *ctx) override {
        return dynamic_cast<ASTNode*>(new continueStmtNode());
    }

    std::any visitFlowStmt(JvavParser::FlowStmtContext *ctx) override {
        return visit(ctx->flow_stmt());
    }

    std::any visitExpr_stmt(JvavParser::Expr_stmtContext *ctx) override {
        std::vector<ExprNode*> exprs;
        for (auto Expr : ctx->expression()) {
            if (Expr != nullptr) {
                exprs.push_back(safeAnyCast<ExprNode*>(visit(Expr)));
            }
        }
        return dynamic_cast<ASTNode*>(new exprStmtNode(exprs));
    }

    std::any visitExprStmt(JvavParser::ExprStmtContext *ctx) override {
        return visit(ctx->expr_stmt());
    }

    std::any visitPureExpr(JvavParser::PureExprContext *ctx) override {
        return visit(ctx->expression());
    }

    std::any visitConst_expr(JvavParser::Const_exprContext *ctx) override {
        if (ctx->True() != nullptr) {
            return dynamic_cast<ASTNode*>(new boolNode(true));
        } 
        else if (ctx->False() != nullptr) {
            return dynamic_cast<ASTNode*>(new boolNode(false));
        } 
        else if (ctx->Number() != nullptr) {
            return dynamic_cast<ASTNode*>(new numberNode(stoll(ctx->Number()->getText())));
        } 
        else if (ctx->Str() != nullptr) {
            std::string str = ctx->Str()->getText().substr(1, ctx->Str()->getText().length() - 2);
            return dynamic_cast<ASTNode*>(new strNode(str));
        } 
        else {
            return dynamic_cast<ASTNode*>(new nullNode());
        }
    }

    std::any visitConstExpr(JvavParser::ConstExprContext *ctx) override {
        return visit(ctx->const_expr());
    }

    std::any visitVarExpr(JvavParser::VarExprContext *ctx) override {
        std::string name = ctx->Identifier()->getText();
        return dynamic_cast<ASTNode*>(new varExprNode(name));
    }

    std::any visitThisExpr(JvavParser::ThisExprContext *ctx) override {
        return dynamic_cast<ASTNode*>(new thisExprNode());
    }

    std::any visitFunc_expr(JvavParser::Func_exprContext *ctx) override {
        std::string name = ctx->Identifier()->getText();
        std::vector<ExprNode*> args;
        if (ctx->argslist() != nullptr) {
            auto Args = ctx->argslist();
            for (auto expr : Args->expression()) {
                if (expr != nullptr) {
                    args.push_back(safeAnyCast<ExprNode*>(visit(expr)));
                }
            }
        }
        return dynamic_cast<ASTNode*>(new funcExprNode(args, name));
    }

    std::any visitFuncExpr(JvavParser::FuncExprContext *ctx) override {
        return visit(ctx->func_expr());
    }

    std::any visitMemberExpr(JvavParser::MemberExprContext *ctx) override {
        ExprNode *expr = safeAnyCast<ExprNode*>(visit(ctx->expression(0)));
        ASTNode *member = safeAnyCast<ASTNode*>(visit(ctx->expression(1)));
        if (auto func = dynamic_cast<funcExprNode*>(member)) {
            return dynamic_cast<ASTNode*>(new memberFuncExprNode(expr, func));
        } 
        else if (auto var = dynamic_cast<varExprNode*>(member)) {
            std::string name = var->name;
            return dynamic_cast<ASTNode*>(new memberVarExprNode(expr, name));
        } 
        else {
            throw std::runtime_error("Member type wrong");
        }
    }

    std::any visitArrayExpr(JvavParser::ArrayExprContext *ctx) override {
        ExprNode *name = safeAnyCast<ExprNode*>(visit(ctx->expression(0)));
        ExprNode *index = safeAnyCast<ExprNode*>(visit(ctx->expression(1)));
        return dynamic_cast<ASTNode*>(new arrayExprNode(name, index));
    }

    std::any visitNewvar_expr(JvavParser::Newvar_exprContext *ctx) override {
        AST::Type *type = (safeAnyCast<typeNode*>(visit(ctx->basic_type())))->type;
        std::vector<ExprNode*> exprs;
        for (auto Expr : ctx->expression()) {
            if (Expr != nullptr) {
                exprs.push_back(safeAnyCast<ExprNode*>(visit(Expr)));
            }
        }
        int dim = ctx->Lbracket().size();
        return dynamic_cast<ASTNode*>(new newExprNode(type, exprs, dim));
    }

    std::any visitNew_expr(JvavParser::New_exprContext *ctx) override {
        if (ctx->newerror_expr() != nullptr) {
            throw std::runtime_error("New array expression wrong");
        } 
        else {
            return visit(ctx->newvar_expr());
        }
    }

    std::any visitNewExpr(JvavParser::NewExprContext *ctx) override {
        return visit(ctx->new_expr());
    }

    std::any visitSuffixUnaryExpr(JvavParser::SuffixUnaryExprContext *ctx) override {
        ExprNode *expr = safeAnyCast<ExprNode*>(visit(ctx->expression()));
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
        return dynamic_cast<ASTNode*>(new suffixUnaryExprNode(expr, opCode));
    }

    std::any visitPrefixUnaryExpr(JvavParser::PrefixUnaryExprContext *ctx) override {
        ExprNode *expr = safeAnyCast<ExprNode*>(visit(ctx->expression()));
        prefixUnaryExprNode::prefixOpType opCode;
        auto Op = ctx->op->getText();

        if(Op == "++") opCode = prefixUnaryExprNode::prefixOpType::Inc;
        else if(Op == "--") opCode = prefixUnaryExprNode::prefixOpType::Dec;
        else if(Op == "!") opCode = prefixUnaryExprNode::prefixOpType::Not;
        else if(Op == "~") opCode = prefixUnaryExprNode::prefixOpType::Inv;
        else if(Op == "-") opCode = prefixUnaryExprNode::prefixOpType::Sub;
        else throw std::runtime_error("Wrong Prefix Unary Opcode");

        return dynamic_cast<ASTNode*>(new prefixUnaryExprNode(expr, opCode));
    }

    std::any visitBinaryExpr(JvavParser::BinaryExprContext *ctx) override {
        ExprNode *lhs = safeAnyCast<ExprNode*>(visit(ctx->expression(0)));
        ExprNode *rhs = safeAnyCast<ExprNode*>(visit(ctx->expression(1)));
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

        return dynamic_cast<ASTNode*>(new binaryExprNode(lhs, rhs, opCode));
    }

    std::any visitTernaryExpr(JvavParser::TernaryExprContext *ctx) override {
        ExprNode *cond = safeAnyCast<ExprNode*>(visit(ctx->expression(0)));
        ExprNode *thenExpr = safeAnyCast<ExprNode*>(visit(ctx->expression(1)));
        ExprNode *elseExpr = safeAnyCast<ExprNode*>(visit(ctx->expression(2)));
        return dynamic_cast<ASTNode*>(new ternaryExprNode(cond, thenExpr, elseExpr));
    }

    std::any visitAssignExpr(JvavParser::AssignExprContext *ctx) override {
        ExprNode *lhs = safeAnyCast<ExprNode*>(visit(ctx->expression(0)));
        ExprNode *rhs = safeAnyCast<ExprNode*>(visit(ctx->expression(1)));
        return dynamic_cast<ASTNode*>(new assignExprNode(lhs, rhs));
    }

    std::any visitTypename(JvavParser::TypenameContext *ctx) override {
        if (!ctx->Lbracket().size()) {
            return visit(ctx->basic_type());
        } 
        else {
            auto elemType = (safeAnyCast<typeNode*>(visit(ctx->basic_type())))->type;
            int dim = ctx->Lbracket().size();
            AST::arrayType *ArrayType = new AST::arrayType(elemType, dim);
            return dynamic_cast<ASTNode*>(new typeNode(ArrayType));
        }
    }

    std::any visitBasic_type(JvavParser::Basic_typeContext *ctx) override {
        if (ctx->Bool() != nullptr) {
            return dynamic_cast<ASTNode*>(new typeNode(BoolType));
        } 
        else if (ctx->Int() != nullptr) {
            return dynamic_cast<ASTNode*>(new typeNode(IntType));
        } 
        else if (ctx->String() != nullptr) {
            return dynamic_cast<ASTNode*>(new typeNode(StringType));
        } 
        else {
            auto ClassType = new AST::classType(ctx->Identifier()->getText());
            return dynamic_cast<ASTNode*>(new typeNode(ClassType));
        }
    }

};

