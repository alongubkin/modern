#ifndef _NODE_H
#define _NODE_H

#include <vector>
#include <sstream>

class Node
{
private:
	std::vector<Node*> _children;

public:
	void AddChild(Node *node) { _children.push_back(node); }
	const std::vector<Node*> & GetChildren() const { return _children; }

	virtual std::string GetNodeSummary() const { return "Node"; }
	std::string ToString();

};

#endif