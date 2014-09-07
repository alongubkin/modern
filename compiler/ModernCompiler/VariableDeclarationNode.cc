#include "VariableDeclarationNode.h"

std::string VariableDeclarationNode::GetNodeSummary() const
{
	std::ostringstream stream;
	stream << "VariableDeclarationNode { name: " << _name << ", type: " << _type << " }";

	return stream.str();
}

void VariableDeclarationNode::Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function)
{
	llvm::Type *type = GetLLVMType(this->GetType());

	llvm::IRBuilder<> tmp(&function->getEntryBlock(),
		function->getEntryBlock().begin());
	llvm::Value *alloc = tmp.CreateAlloca(type, 0, this->GetName().c_str());

	this->GetParent()->SetScopeProperty(this->GetName(),
		new ScopeProperty(alloc, false, type->getTypeID()));

}