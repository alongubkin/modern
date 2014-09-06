#include "ExpressionNode.h"

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