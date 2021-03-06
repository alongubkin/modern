#include "Node.h"

// TODO: move this to another place
llvm::Type *GetLLVMType(std::string type)
{
	if (type == "int")
		return llvm::Type::getInt32Ty(llvm::getGlobalContext());
	else if (type == "double")
		return llvm::Type::getDoubleTy(llvm::getGlobalContext());
	else if (type == "void")
		return llvm::Type::getVoidTy(llvm::getGlobalContext());
	
	throw;
}

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

void Node::Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function)
{
	std::vector<Node*> children = this->GetChildren();
	for (std::vector<Node*>::iterator it = children.begin(); it != children.end(); ++it)
	{
		(*it)->Codegen(module, builder, function);
	}
}

ScopeProperty *Node::GetScopeProperty(const std::string name) const
{
	std::map<std::string, ScopeProperty*>::const_iterator pair = _scope.find(name);
	if (pair == _scope.end())
		return NULL;

	return pair->second;
}