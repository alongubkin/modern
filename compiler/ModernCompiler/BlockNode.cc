#include "BlockNode.h"

void BlockNode::Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function) const
{
	llvm::BasicBlock *block = llvm::BasicBlock::Create(llvm::getGlobalContext(), "entry", function);
	builder.SetInsertPoint(block);

	Node::Codegen(module, builder, function);
}