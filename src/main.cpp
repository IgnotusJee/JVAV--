#include <iostream>
#include <thread>
#include <vector>
#include "JvavLexer.h"
#include "JvavParser.h"
using namespace antlr4;
using namespace std;

int main(int argc, const char* argv[]) {

    std::vector<std::thread> threads;
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back([] {
            std::cout << "Thread running!\n";
        });
    }
    for (auto& t : threads) t.join();


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