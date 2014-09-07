#include "LiteralNode.h"

#include "llvm/IR/Constants.h"
#include "llvm/IR/LLVMContext.h"

llvm::Value *LiteralNode<long>::Codegen(llvm::IRBuilder<>& builder) const
{
	long value = this->GetValue();
	return llvm::ConstantInt::getSigned(
		llvm::IntegerType::get(llvm::getGlobalContext(), 32),
		value);
}

llvm::Value *LiteralNode<double>::Codegen(llvm::IRBuilder<>& builder) const
{
	double value = this->GetValue();
	return llvm::ConstantFP::get(llvm::getGlobalContext(), llvm::APFloat(value));
}