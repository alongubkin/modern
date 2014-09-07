#include "AssignmentNode.h"
#include "IdentifierNode.h"

void AssignmentNode::Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function)
{
	std::vector<Node*> children = this->GetChildren();
	
	IdentifierNode *identifier = dynamic_cast<IdentifierNode*>(children.front());
	ExpressionNode *expression = dynamic_cast<ExpressionNode*>(children.back());

	ScopeProperty *prop = this->GetParent()->GetScopeProperty(identifier->GetName());
	
	if (prop->IsArgument())
		throw; // TODO

	llvm::Value *variable = prop->GetValue();
	llvm::Value *value = expression->Evaluate(module, builder, function);

	if (prop->GetTypeID() != value->getType()->getTypeID())
	{
		switch (prop->GetTypeID())
		{
		case llvm::Type::DoubleTyID:
			value = builder.CreateSIToFP(value, llvm::Type::getDoubleTy(llvm::getGlobalContext()), "cast");
			break;

		case llvm::Type::IntegerTyID:
			value = builder.CreateFPToSI(value, llvm::Type::getInt32Ty(llvm::getGlobalContext()), "cast");
			break;
		}		
	}

	builder.CreateStore(value, prop->GetValue());
}