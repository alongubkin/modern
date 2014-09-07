#ifndef _CALL_EXPRESSION_NODE_H
#define _CALL_EXPRESSION_NODE_H

#include "ExpressionNode.h"

class CallExpressionNode :
	public ExpressionNode
{
private:
	std::string _functionName;

public:
	void SetFunctionName(const std::string functionName) { _functionName = functionName; }
	std::string GetFunctionName() const { return _functionName; }

	virtual std::string GetNodeSummary() const;
	virtual llvm::Value *Evaluate(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function) const;
};

#endif
