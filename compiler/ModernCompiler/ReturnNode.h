#ifndef _RETURN_NODE_H
#define _RETURN_NODE_H

#include "Node.h"

class ReturnNode
	: public Node
{
public:
	virtual std::string GetNodeSummary() const { return "ReturnNode"; }
	void Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function) const;
};

#endif