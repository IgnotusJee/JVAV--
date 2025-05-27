#include <iostream>
#include <thread>
#include <vector>
#include "JvavLexer.h"
#include "JvavParser.h"
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
    // for (auto t : tokens.getTokens()) {
    //     cout<<t->toString()<<endl;
    // }
    // ifs.close();

    tree::ParseTree* tree = parser.program();
    std::cout << tree->toStringTree(&parser) << std::endl;

    return 0;
}