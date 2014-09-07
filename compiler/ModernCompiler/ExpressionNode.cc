#include "ExpressionNode.h"
#include "LiteralNode.h"

#include "llvm/IR/Constants.h"
#include "llvm/IR/LLVMContext.h"


std::string ComparisonExpressionNode::GetNodeSummary() const
{
	std::ostringstream stream;
	stream << "ComparisonExpressionNode { operator: ";

	if (_op == SMALLER)
		stream << "<";
	else if (_op == SMALLER_OR_EQUAL)
		stream << "<=";
	else if (_op == LARGER)
		stream << ">";
	else if (_op == LARGER_OR_EQUAL)
		stream << ">=";
	else if (_op == EQUALS)
		stream << "==";

	stream << " }";
	return stream.str();
}

llvm::Value *ComparisonExpressionNode::Codegen(llvm::IRBuilder<>& builder) const
{
	std::vector<Node*> children = this->GetChildren();

	llvm::Value *left = dynamic_cast<ExpressionNode*>(children.front())->Codegen(builder);
	llvm::Value *right = dynamic_cast<ExpressionNode*>(children.back())->Codegen(builder);
	
	return builder.CreateFCmpULT(left, right, "cmptmp");
}

std::string ArithmeticExpressionNode::GetNodeSummary() const
{
	std::ostringstream stream;
	stream << "ArithmeticExpressionNode { operator: ";

	if (_op == PLUS_)
		stream << "+";
	else if (_op == MINUS) 
		stream << "-";
	else if (_op == MULTIPLY_)
		stream << "*";
	else if (_op == DIVISION)
		stream << "/";

	stream << " }";
	return stream.str();
}

llvm::Value *ArithmeticExpressionNode::Codegen(llvm::IRBuilder<>& builder) const
{
	std::vector<Node*> children = this->GetChildren();

	llvm::Value *left = dynamic_cast<ExpressionNode*>(children.front())->Codegen(builder);
	llvm::Value *right = dynamic_cast<ExpressionNode*>(children.back())->Codegen(builder);

	switch (this->GetOperator()) 
	{
	case PLUS_:
		return builder.CreateFAdd(left, right, "addtmp");

	case MINUS:
		return builder.CreateFSub(left, right, "subtmp");

	case MULTIPLY_:
		return builder.CreateFMul(left, right, "multmp");

	case DIVISION:
		return builder.CreateFDiv(left, right, "divtmp");
	}
}