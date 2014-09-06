#include "IdentifierNode.h"

std::string IdentifierNode::GetNodeSummary() const
{
	std::ostringstream stream;
	stream << "IdentifierNode { name: " << GetName() << " }";
	return stream.str();
}