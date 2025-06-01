#include <iostream>
#include <thread>
#include <vector>
#include "JvavLexer.h"
#include "JvavParser.h"
#include "Frontend/ASTBuilder.hpp"
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
    rootNode *ASTRoot = std::any_cast<rootNode*>(astBuilder.visit(parseTreeRoot));

    return 0;
}