#ifndef _ASSIGNMENT_NODE_H
#define _ASSIGNMENT_NODE_H

#include "Node.h"

class AssignmentNode
	: public Node
{
public:
	virtual std::string GetNodeSummary() const { return "AssignmentNode"; }
	void Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function);
};

#endif