#ifndef _NODE_H
#define _NODE_H

#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Function.h"

#include <vector>
#include <sstream>

class Node
{
private:
	std::vector<Node*> _children;
	std::map<std::string, llvm::Value*> _scope;
	Node *_parent = NULL;
	
public:
	void AddChild(Node *node) { _children.push_back(node); node->_parent = this; }
	const std::vector<Node*> & GetChildren() const { return _children; }

	void SetScopeProperty(std::string name, llvm::Value *value) { _scope[name] = value; }
	llvm::Value *GetScopeProperty(const std::string name) const;

	Node *GetParent() const { return _parent; }

	virtual std::string GetNodeSummary() const { return "Node"; }
	std::string ToString() const;

	virtual void Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function);
};
 
#endif