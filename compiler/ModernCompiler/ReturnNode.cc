#include "ReturnNode.h"
#include "ExpressionNode.h"

void ReturnNode::Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function)
{
	if (this->GetChildren().size() == 0)
	{
		builder.CreateRetVoid();
	}
	else
	{
		// TODO: Cast to return type

		ExpressionNode *expression = dynamic_cast<ExpressionNode*>(this->GetChildren().front());
		builder.CreateRet(expression->Evaluate(module, builder, function));
	}
}