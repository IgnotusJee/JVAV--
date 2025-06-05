#include "llvm/IR/Module.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/CodeGen/CommandFlags.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/IR/LegacyPassManager.h"

static llvm::codegen::RegisterCodeGenFlags CGF;

void emitRISCV32Assembly(llvm::Module *Module, const std::string &OutputFilename) {
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmPrinters();

    std::string Triple = "riscv32-unknown-elf";
    Module->setTargetTriple(Triple);

    std::string Error;
    const auto *Target = llvm::TargetRegistry::lookupTarget(Triple, Error);
    if (!Target) {
        llvm::errs() << "ERROR: " << Error << "\n";
        return;
    }

    llvm::TargetOptions Options = llvm::codegen::InitTargetOptionsFromCodeGenFlags(llvm::Triple(Triple));
    std::optional<llvm::Reloc::Model> RM = llvm::codegen::getExplicitRelocModel();
    llvm::TargetMachine *TM = Target->createTargetMachine(
        Triple,
        llvm::codegen::getCPUStr(),
        llvm::codegen::getFeaturesStr(),
        Options,
        RM
    );

    Module->setDataLayout(TM->createDataLayout());

    std::error_code EC;
    llvm::raw_fd_ostream Dest(OutputFilename, EC);
    if (EC) {
        llvm::errs() << "Could not open file: " << EC.message() << "\n";
        return;
    }

    llvm::legacy::PassManager PM;
    llvm::LLVMTargetMachine &LLVMTM = static_cast<llvm::LLVMTargetMachine&>(*TM);
    if (LLVMTM.addPassesToEmitFile(
            PM, Dest, nullptr, llvm::CodeGenFileType::AssemblyFile)) {
        llvm::errs() << "Failed to generate assembly!\n";
        return;
    }

    PM.run(*Module);
    Dest.flush();
    llvm::outs() << "Successfully generated RISC-V assembly to: " << OutputFilename << "\n";
}