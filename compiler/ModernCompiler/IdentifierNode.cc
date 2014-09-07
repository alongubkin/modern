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
		ScopeProperty *prop = node->GetScopeProperty(GetName());
		
		if (prop != NULL)
		{
			if (prop->IsArgument())
				return prop->GetValue();

			return builder.CreateLoad(prop->GetValue(), GetName());
		}

		node = node->GetParent();
	} while (node != NULL);
	
	throw; // TODO
}