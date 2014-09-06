#include "ConstAssignmentNode.h"

std::string ConstAssignmentNode::GetNodeSummary() const
{
	std::ostringstream stream;
	stream << "VariableDeclarationNode { left: " << _left->GetName() << ", right: " << _right << " }";

	return stream.str();
}