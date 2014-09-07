#ifndef _FUNCTION_NODE_H
#define _FUNCTION_NODE_H

#include "Node.h"

class Argument
{
private:
	std::string _name;
	std::string _type;

public:
	void SetName(const std::string name) { _name = name; }
	std::string GetName() const { return _name; }

	void SetType(const std::string type) { _type = type; }
	std::string GetType() const { return _type; }
};

class FunctionNode :
	public Node
{
private:
	std::string _name;
	std::string _returnType;
	std::vector<const Argument const*> _args;

public:
	void SetName(const std::string name) { _name = name; }
	std::string GetName() const { return _name;  }

	void SetReturnType(const std::string returnType) { _returnType = returnType; }
	std::string GetReturnType() const { return _returnType; }

	const std::vector<const Argument const*> & GetArguments() const { return _args; }
	void AddArgument(const Argument * const arg) { _args.push_back(arg); }

	virtual std::string GetNodeSummary() const;

	void Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function);
};

#endif