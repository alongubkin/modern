#include "ProgramNode.h"
#include "FunctionNode.h"

void ProgramNode::Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function)
{
	std::vector<Node*> children = this->GetChildren();
	std::vector<llvm::Function *> functions;

	for (std::vector<Node*>::iterator it = children.begin(); it != children.end(); ++it)
	{
		FunctionNode *func = dynamic_cast<FunctionNode*>(*it);
		functions.push_back(func->Codegen(module, builder));
	}

	std::vector<Node*>::iterator childIterator = children.begin();
	std::vector<llvm::Function*>::iterator functionIterator = functions.begin();

	for (; childIterator != children.end() && functionIterator != functions.end(); ++childIterator, ++functionIterator)
	{
		FunctionNode *node = dynamic_cast<FunctionNode*>(*childIterator);
		llvm::Function *func = dynamic_cast<llvm::Function*>(*functionIterator);
		node->Codegen(module, builder, func);
	}
}