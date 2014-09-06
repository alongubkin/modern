#include "VariableDeclarationNode.h"

std::string VariableDeclarationNode::GetNodeSummary() const
{
	std::ostringstream stream;
	stream << "VariableDeclarationNode { name: " << _name << ", type: " << _type << " }";

	return stream.str();
}
