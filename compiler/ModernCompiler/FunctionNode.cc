#include "FunctionNode.h"

std::string FunctionNode::GetNodeSummary() const
{
	std::ostringstream stream;
	stream << "FunctionNode { name: " << _name << ", returnType: " << _returnType << ", arguments: [";

	std::vector<const Argument const*> args = GetArguments();
	for (std::vector<const Argument const*>::iterator it = args.begin(); it != args.end(); ++it)
	{
		const Argument *arg = (*it);
		stream << arg->GetType() << " " << arg->GetName();

		if (!(it != args.end()) || !(it + 1 == args.end()))
		{
			stream << ", ";
		}
	}

	stream << "] }";
	return stream.str();
}
