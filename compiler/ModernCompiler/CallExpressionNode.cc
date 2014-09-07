#include "CallExpressionNode.h"
#include "llvm/IR/Module.h"

std::string CallExpressionNode::GetNodeSummary() const
{
	std::ostringstream stream;
	stream << "CallExpressionNode { name: " << GetFunctionName() << " }";
	return stream.str();
}

llvm::Value *CallExpressionNode::Evaluate(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function) const
{
	// TODO: check args size
	std::vector<Node*> children = GetChildren();
	std::vector<llvm::Value*> args;

	for (std::vector<Node*>::iterator it = children.begin(); it != children.end(); ++it)
	{
		ExpressionNode *expression = dynamic_cast<ExpressionNode*>(*it);
		args.push_back(expression->Evaluate(module, builder, function));
	}

	return builder.CreateCall(module.getFunction(this->GetFunctionName()), args);
}