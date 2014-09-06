#include "Node.h"

std::string Node::ToString()
{
	std::ostringstream stream;
	stream << "- " << this->GetNodeSummary() << std::endl;
	
	std::vector<Node*> vec = this->GetChildren();

	for (std::vector<Node*>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::istringstream child((*it)->ToString());
		std::string line;
		
		while (std::getline(child, line))
		{
			stream << "  " << line << std::endl;
		}
	}

	return stream.str();
}