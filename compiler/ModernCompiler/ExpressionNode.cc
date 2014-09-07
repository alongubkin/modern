#include "ExpressionNode.h"
#include "LiteralNode.h"

#include "llvm/IR/Constants.h"
#include "llvm/IR/LLVMContext.h"

void ExpressionNode::Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function)
{
	Evaluate(module, builder, function);
}

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

llvm::Value *ComparisonExpressionNode::Evaluate(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function) const
{
	std::vector<Node*> children = this->GetChildren();

	llvm::Value *left = dynamic_cast<ExpressionNode*>(children.front())->Evaluate(module, builder, function);
	llvm::Value *right = dynamic_cast<ExpressionNode*>(children.back())->Evaluate(module, builder, function);
	
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

llvm::Value *ArithmeticExpressionNode::Evaluate(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function) const
{
	std::vector<Node*> children = this->GetChildren();

	llvm::Value *left = dynamic_cast<ExpressionNode*>(children.front())->Evaluate(module, builder, function);
	llvm::Value *right = dynamic_cast<ExpressionNode*>(children.back())->Evaluate(module, builder, function);
	
	bool floatingPoint = false;

	llvm::Type::TypeID leftTypeId = left->getType()->getTypeID();
	llvm::Type::TypeID rightTypeId = right->getType()->getTypeID();

	if (this->GetOperator() == DIVISION 
		|| leftTypeId == llvm::Type::DoubleTyID 
		|| rightTypeId == llvm::Type::DoubleTyID)
	{
		floatingPoint = true;

		if (leftTypeId != llvm::Type::DoubleTyID)
			left = builder.CreateSIToFP(left, llvm::Type::getDoubleTy(llvm::getGlobalContext()), "cast");

		if (rightTypeId != llvm::Type::DoubleTyID)
			right = builder.CreateSIToFP(right, llvm::Type::getDoubleTy(llvm::getGlobalContext()), "cast");
	}

	switch (this->GetOperator()) 
	{
	case PLUS_:
		if (floatingPoint)
			return builder.CreateFAdd(left, right, "addtmp");
		else 
			return builder.CreateAdd(left, right, "addtmp");

	case MINUS:
		if (floatingPoint)
			return builder.CreateFSub(left, right, "subtmp");
		else
			return builder.CreateSub(left, right, "subtmp");

	case MULTIPLY_:
		if (floatingPoint)
			return builder.CreateFMul(left, right, "multmp");
		else
			return builder.CreateMul(left, right, "multmp");

	case DIVISION:
		llvm::Value *div = builder.CreateFDiv(left, right, "divtmp");

		// If the values were originally integer, convert the division result back to integer
		if (leftTypeId == llvm::Type::IntegerTyID && rightTypeId == llvm::Type::IntegerTyID)
			div = builder.CreateFPToSI(div, llvm::Type::getInt32Ty(llvm::getGlobalContext()), "cast");

		return div;
	
	}

	throw; // TODO
}