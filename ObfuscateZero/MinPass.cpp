#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

namespace 
{
    class myPass : public BasicBlockPass {
        public:
            static char ID;

            MyPass() : BasicBlockPass(ID) {}

            bool runOnBasicBlock(BasicBlock &BB) override 
            {
                errs() << "Block runner now, what i m in :p...\n";
                return false;
            }
    };
}

char MyPass::ID = 0;
static RegisterPass<MyPass> X("MyPass", "Obfuscates zeroes", false, false);

// register pass for clang use
static void registerMyPassPass(const PassManagerBuilder &, PassManagerBase &PM)
{
    PM.add(new MyPass());
}

static RegisterStandardPasses RegisterMBAPass(PassManagerBuilder::EP_EarlyAsPossible, registerMyPassPass);


