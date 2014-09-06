#ifndef _CONST_ASSIGNMENT_NODE_H
#define _CONST_ASSIGNMENT_NODE_H

#include "Node.h"
#include "Reference.h"

class ConstAssignmentNode :
	public Node
{
private:
	const Reference *_left;
	std::string _right;
	
public:
	void SetLeft(const Reference const *left) { _left = left; }
	const Reference * const GetLeft() const { return _left; }

	void SetRight(const std::string right) { _right = right; }
	std::string GetRight() const { return _right; }

	virtual std::string GetNodeSummary() const;
};

#endif