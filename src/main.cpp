#include <iostream>
#include <thread>
#include <vector>
#include "JvavLexer.h"
#include "JvavParser.h"
#include "Frontend/ASTBuilder.hpp"
#include "Frontend/IRGenerator.hpp"
#include "Backend/ASMBuilder.hpp"
using namespace antlr4;
using namespace std;

void initThreads() {
    std::thread([]{}).join(); 
}

int main(int argc, const char* argv[]) {

    initThreads();

    const char* filepath = argv[1];
    std::ifstream ifs;
    ifs.open(filepath);
    ANTLRInputStream input(ifs);
    JvavLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    JvavParser parser(&tokens);
    tree::ParseTree* parseTreeRoot = parser.program();
    cout << parseTreeRoot->toStringTree(&parser) << endl;
    ASTBuilder astBuilder;
    rootNode *ASTRoot = dynamic_cast<rootNode*>(std::any_cast<ASTNode*>(astBuilder.visit(parseTreeRoot)));
	Module* jvavmodule;
    string outpath(filepath);
    jvavmodule = generateIR(ASTRoot, outpath.replace(outpath.length() - 5, 5, ".ll"));
    emitRISCV32Assembly(jvavmodule, outpath.replace(outpath.length() - 3, 3, ".s"));

    return 0;
}