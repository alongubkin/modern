#include "VariableDeclarationNode.h"
#include "ExpressionNode.h"

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

	if (GetChildren().size() > 0)
	{
		ExpressionNode *expression = dynamic_cast<ExpressionNode*>(GetChildren().front());
		llvm::Value *value = expression->Evaluate(module, builder, function);

		// TODO: one truth casting
		if (type->getTypeID() != value->getType()->getTypeID())
		{
			switch (type->getTypeID())
			{
			case llvm::Type::DoubleTyID:
				value = builder.CreateSIToFP(value, llvm::Type::getDoubleTy(llvm::getGlobalContext()), "cast");
				break;

			case llvm::Type::IntegerTyID:
				value = builder.CreateFPToSI(value, llvm::Type::getInt32Ty(llvm::getGlobalContext()), "cast");
				break;
			}
		}

		builder.CreateStore(value, alloc);
	}

}