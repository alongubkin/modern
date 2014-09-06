#ifndef _IDENTIFIER_NODE_H
#define _IDENTIFIER_NODE_H

#include <string>
#include "Node.h"

class IdentifierNode :
	public Node
{
private:
	std::string _name;

public:
	std::string GetName() const { return _name; }
	void SetName(const std::string name) { _name = name; }

	virtual std::string GetNodeSummary() const;
};

#endif