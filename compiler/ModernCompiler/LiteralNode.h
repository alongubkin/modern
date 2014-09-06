#ifndef _LITERAL_NODE_H
#define _LITERAL_NODE_H

#include "Node.h"

template <typename T>
class LiteralNode
	: public Node
{
private:
	T _value;

public:
	T GetValue() const { return _value; }
	void SetValue(const T value) { _value = value; }
	
	virtual std::string GetNodeSummary() const;
};

#endif