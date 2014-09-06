#include "LiteralNode.h"

std::string LiteralNode<long>::GetNodeSummary() const
{
	std::ostringstream stream;
	stream << "LiteralNode { value: " << GetValue() << " }";
	return stream.str();
}