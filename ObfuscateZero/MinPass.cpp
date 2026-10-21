#include "llvm/Config/llvm-config.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Plugins/PassPlugin.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/Support/raw_ostream.h"


using namespace llvm;

namespace 
{
    struct MyPass : PassInfoMixin<MyPass> {
        PreservedAnalyses run(Function &F, FunctionAnalysisManager &) {
            for (BasicBlock &BB : F) {
            
            }
        return PreservedAnalyses::all();
        }
    };
}

extern "C" ::llvm::PassPluginLibraryInfo llvmGetPassPluginInfo() 
{
    return {
        LLVM_PLUGIN_API_VERSION, "MyPass", LLVM_VERSION_STRING,[](PassBuilder &PB) 
        {
            PB.registerPipelineParsingCallback( [](StringRef Name, FunctionPassManager &FPM, ArrayRef<PassBuilder::PipelineElement>) 
            {
                if (Name == "MyPass")
                {
                    FPM.addPass(MyPass());
                    return true;
                }
                return false;
            });
        }
    };
}
