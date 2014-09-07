#include "IdentifierNode.h"

std::string IdentifierNode::GetNodeSummary() const
{
	std::ostringstream stream;
	stream << "IdentifierNode { name: " << GetName() << " }";
	return stream.str();
}

llvm::Value *IdentifierNode::Evaluate(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function) const
{
	const Node *node = this;
	do {
		llvm::Value *value = node->GetScopeProperty(GetName());
		if (value != NULL)
			return value;

		node = node->GetParent();
	} while (node != NULL);

	throw; // TODO
}