#include <iostream>
#include <thread>
#include <cstdlib>
#include "JvavLexer.h"
#include "JvavParser.h"
#include "Frontend/ASTBuilder.hpp"
#include "Frontend/IRGenerator.hpp"
#include "Backend/ASMBuilder.hpp"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/Program.h"
using namespace antlr4;
using namespace std;

void initThreads() {
    std::thread([]{}).join();
}

int main(int argc, const char* argv[]) {

    initThreads();

    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <source.jvav> [runtime.o]" << endl;
        return 1;
    }

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
    string outpath(filepath);

    // 生成LLVM IR
    IRGenerator irGenerator;
    ASTRoot->accept((ASTVisitor &) irGenerator);
    irGenerator.outputIR(outpath.replace(outpath.length() - 5, 5, ".ll"));

    // 生成RISC-V汇编
    ASMBuilder asmBuilder(irGenerator.getModule());
    asmBuilder.generate(outpath.replace(outpath.length() - 3, 3, ".s"));
    string assembly_file = outpath; // 保存汇编文件路径

    // RISC-V汇编编译为对象文件

    string object_file = assembly_file;
    size_t last_dot = object_file.find_last_of('.');
    if (last_dot != string::npos) {
        object_file = object_file.substr(0, last_dot) + ".o";
    } else {
        object_file += ".o";
    }

	string asmer_path = "/opt/riscv64-linux/bin/riscv64-unknown-linux-gnu-as";

	string asmer_command = asmer_path + " -mabi=lp64 -o " + object_file + " " + " " + assembly_file;

	if (system(asmer_command.c_str()) != 0) {
        cerr << "Asm failed: " << asmer_command << endl;
        return 1;
    }

    // 链接对象文件生成可执行文件
    string executable = assembly_file.substr(0, last_dot);
    string runtime_obj = (argc > 2) ? argv[2] : "jvav";  // 指定运行时库

	string linker_path = "/opt/riscv64-linux/bin/riscv64-unknown-linux-gnu-gcc";

	string link_command = linker_path + " -L. -static -o " + executable + " " + object_file + " " + "-l" + runtime_obj;

    if (system(link_command.c_str()) != 0) {
        cerr << "Linker failed: " << link_command << endl;
        return 1;
    }

    cout << "Generated executable: " << executable << endl;

    return 0;
}
