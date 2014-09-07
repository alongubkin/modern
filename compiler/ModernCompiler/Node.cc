#include "Node.h"

std::string Node::ToString() const
{
	std::ostringstream stream;
	stream << "- " << this->GetNodeSummary() << std::endl;
	
	std::vector<Node*> children = this->GetChildren();
	for (std::vector<Node*>::iterator it = children.begin(); it != children.end(); ++it)
	{
		std::istringstream child((*it)->ToString());
		std::string line;
		
		while (std::getline(child, line))
		{
			stream << "  " << line << std::endl;
		}
	}

	return stream.str();
}

void Node::Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function) const
{
	std::vector<Node*> children = this->GetChildren();
	for (std::vector<Node*>::iterator it = children.begin(); it != children.end(); ++it)
	{
		(*it)->Codegen(module, builder, function);
	}
}