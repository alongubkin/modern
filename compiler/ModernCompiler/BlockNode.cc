#include "BlockNode.h"

void BlockNode::Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function)
{
	llvm::BasicBlock *block = llvm::BasicBlock::Create(llvm::getGlobalContext(), "entry", function);
	builder.SetInsertPoint(block);

	Node::Codegen(module, builder, function);
}