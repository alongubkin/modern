#ifndef _IDENTIFIER_NODE_H
#define _IDENTIFIER_NODE_H

#include <string>
#include "ExpressionNode.h"

class IdentifierNode :
	public ExpressionNode
{
private:
	std::string _name;

public:
	std::string GetName() const { return _name; }
	void SetName(const std::string name) { _name = name; }

	virtual std::string GetNodeSummary() const;
	virtual llvm::Value *Evaluate(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function) const;
};

#endif