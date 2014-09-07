#ifndef _BLOCK_NODE_H
#define _BLOCK_NODE_H

#include "Node.h"

class BlockNode :
	public Node
{
public:
	std::string GetNodeSummary() const { return "BlockNode"; }
	void Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function) const;
};

#endif