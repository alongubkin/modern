#ifndef _NODE_H
#define _NODE_H

#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Function.h"

#include <vector>
#include <sstream>
#include <string>

#include "ScopeProperty.h"

// TODO: move this to another place
llvm::Type *GetLLVMType(std::string type);

class Node
{
private:
	std::vector<Node*> _children;
	std::map<std::string, ScopeProperty*> _scope;
	Node *_parent = NULL;
	
public:
	void AddChild(Node *node) { _children.push_back(node); node->_parent = this; }
	const std::vector<Node*> & GetChildren() const { return _children; }

	void SetScopeProperty(std::string name, ScopeProperty *value) { _scope[name] = value; }
	ScopeProperty *GetScopeProperty(const std::string name) const;

	Node *GetParent() const { return _parent; }

	virtual std::string GetNodeSummary() const { return "Node"; }
	std::string ToString() const;

	virtual void Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function);
};
 
#endif