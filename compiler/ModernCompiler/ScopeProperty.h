#ifndef _SCOPE_PROPERTY_H
#define _SCOPE_PROPERTY_H

#include "llvm/IR/DerivedTypes.h"

class ScopeProperty
{
private:
	llvm::Value *_value;
	llvm::Type::TypeID _typeId;
	bool _isArgument;

public:
	ScopeProperty(llvm::Value *value, bool isArgument, llvm::Type::TypeID typeId)
		: _value(value), _isArgument(isArgument), _typeId(typeId) {}

	llvm::Value *GetValue() const { return _value; }
	llvm::Type::TypeID GetTypeID() const { return _typeId; }
	bool IsArgument() const { return _isArgument; }
};

#endif