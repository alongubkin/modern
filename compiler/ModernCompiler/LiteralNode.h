#ifndef _LITERAL_NODE_H
#define _LITERAL_NODE_H

#include "Node.h"
#include "ExpressionNode.h"

#include "llvm/IR/Constants.h"

template <typename T>
class LiteralNode
	: public ExpressionNode 
{
private:
	T _value;

public:
	T GetValue() const { return _value; }
	void SetValue(const T value) { _value = value; }
	
	llvm::Value *Evaluate(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function) const;

	std::string GetNodeSummary() const
	{
		std::ostringstream stream;
		stream << "LiteralNode { value: " << GetValue() << " }";
		return stream.str();
	}
};

#endif