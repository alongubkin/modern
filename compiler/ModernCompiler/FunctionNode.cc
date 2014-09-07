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
	std::vector<const Argument const*> args = GetArguments();
	std::vector<llvm::Type*> &argTypes = std::vector<llvm::Type*>();

	for (std::vector<const Argument const*>::iterator it = args.begin(); it != args.end(); ++it)
	{
		// (*it)->GetType()
		argTypes.push_back(llvm::Type::getInt32Ty(llvm::getGlobalContext()));
		
	}
	
	llvm::FunctionType *type = llvm::FunctionType::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()),
		argTypes, false);

	llvm::Function *func = 
		llvm::Function::Create(type, llvm::Function::ExternalLinkage, this->GetName(), &module);

	unsigned argIndex = 0;
	for (llvm::Function::arg_iterator it = func->arg_begin(); argIndex != args.size();
		++it, ++argIndex) {
		std::string argName = args.at(argIndex)->GetName();

		it->setName(argName);
		this->SetScopeProperty(argName, it);
	}

	Node::Codegen(module, builder, func);
}