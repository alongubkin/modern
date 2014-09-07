#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/ManagedStatic.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"

#include <string>
#include <iostream>

#include "ASTGenerator.h"
#include "Node.h"

int main(int argc, char *argv[]) 
{
	ASTGenerator generator(argv[1]);
	generator.Initialize();
	
	Node *node = generator.Generate();
	std::cout << node->ToString() << "\n";

	llvm::InitializeNativeTarget();

	llvm::Module module("test", llvm::getGlobalContext());
	llvm::IRBuilder<> builder(llvm::getGlobalContext());

	node->Codegen(module, builder, NULL);
	
	llvm::outs() << module;

	getchar();

}