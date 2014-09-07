#ifndef _VARIABLE_DECLARATION_NODE_H
#define _VARIABLE_DECLARATION_NODE_H

#include "Node.h"

class VariableDeclarationNode :
	public Node
{
private:
	std::string _name;
	std::string _type;

public:
	void SetName(const std::string name) { _name = name; }
	std::string GetName() const { return _name; }

	void SetType(const std::string type) { _type = type; }
	std::string GetType() const { return _type; }

	virtual std::string GetNodeSummary() const;
	virtual void Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function);
};

#endif