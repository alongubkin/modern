#include "FunctionNode.h"

#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Function.h"

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

void FunctionNode::Codegen(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function)
{
	if (function == NULL)
	{
		Codegen(module, builder, NULL);
	}
	else 
	{
		Node::Codegen(module, builder, function);

		llvm::Type::TypeID typeId = function->getFunctionType()->getReturnType()->getTypeID();

		if (typeId == llvm::Type::VoidTyID)
		{
			// TODO: If a ReturnNode was at the end of this node,
			// do not create this RetVoid
			builder.CreateRetVoid();
		}
	}
}

llvm::Function *FunctionNode::Codegen(llvm::Module& module, llvm::IRBuilder<>& builder)
{
	std::vector<const Argument const*> args = GetArguments();
	std::vector<llvm::Type*> &argTypes = std::vector<llvm::Type*>();

	for (std::vector<const Argument const*>::iterator it = args.begin(); it != args.end(); ++it)
	{
		argTypes.push_back(GetLLVMType((*it)->GetType()));
	}
	
	llvm::Type *returnType = GetLLVMType(this->GetReturnType());

	llvm::FunctionType *type = llvm::FunctionType::get(returnType,
		argTypes, false);

	llvm::Function *func = 
		llvm::Function::Create(type, llvm::Function::ExternalLinkage, this->GetName(), &module);

	unsigned argIndex = 0;
	for (llvm::Function::arg_iterator it = func->arg_begin(); argIndex != args.size();
		++it, ++argIndex) {
		std::string argName = args.at(argIndex)->GetName();

		it->setName(argName);
		this->SetScopeProperty(argName, new ScopeProperty(it, true, type->getTypeID()));
	}

	return func;
}
