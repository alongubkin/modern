#ifndef _REFERENCE_H
#define _REFERENCE_H

#include "Node.h"

class Reference
{
private:
	std::string _name;
	const Node *_scope;

public:
	void SetName(const std::string name) { _name = name; }
	std::string GetName() const { return _name; }

	void SetScope(const Node const *scope) { _scope = scope; }
	const Node const *GetScope() const { return _scope; }
};

#endif