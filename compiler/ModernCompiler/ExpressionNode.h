#ifndef _EXPRESSION_NODE_H
#define _EXPRESSION_NODE_H

#include "Node.h"

class ExpressionNode
	: public Node
{
public:
	virtual std::string GetNodeSummary() const = 0;
};

enum COMPARISON_OPERATOR
{
	LARGER = 1,
	LARGER_OR_EQUAL,
	SMALLER,
	SMALLER_OR_EQUAL,
	EQUALS
};

enum ARITHMETIC_OPERATOR
{
	PLUS_ = 1,
	MULTIPLY_,
	MINUS,
	DIVISION
};

class ComparisonExpressionNode :
	public ExpressionNode
{
private:
	COMPARISON_OPERATOR _op;

public:
	void SetOperator(const COMPARISON_OPERATOR op) { _op = op; }
	COMPARISON_OPERATOR GetOperator() const { return _op; }

	virtual std::string GetNodeSummary() const;
};

class ArithmeticExpressionNode :
	public ExpressionNode
{
private:
	ARITHMETIC_OPERATOR _op;

public:
	void SetOperator(const ARITHMETIC_OPERATOR op) { _op = op; }
	ARITHMETIC_OPERATOR GetOperator() const { return _op; }

	virtual std::string GetNodeSummary() const;
};


#endif