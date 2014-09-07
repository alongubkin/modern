#ifndef _RETURN_NODE_H
#define _RETURN_NODE_H

#include "Node.h"

class ReturnNode
	: public Node
{
public:
	virtual std::string GetNodeSummary() const { return "ReturnNode"; }
};

#endif