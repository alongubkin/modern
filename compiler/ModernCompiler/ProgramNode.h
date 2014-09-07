#ifndef _PROGRAM_NODE_H
#define _PROGRAM_NODE_H

#include "Node.h"

class ProgramNode :
	public Node
{
public:
	std::string GetNodeSummary() const { return "ProgramNode"; }
	void Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function);
};

#endif