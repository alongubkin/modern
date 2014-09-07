#include "LiteralNode.h"

#include "llvm/IR/Constants.h"
#include "llvm/IR/LLVMContext.h"

llvm::Value *LiteralNode<long>::Evaluate(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function) const
{
	long value = this->GetValue();
	return llvm::ConstantInt::get(llvm::getGlobalContext(), llvm::APInt(32, value, true));
}

llvm::Value *LiteralNode<double>::Evaluate(llvm::Module& module, llvm::IRBuilder<>& builder, llvm::Function *function) const
{
	double value = this->GetValue();
	return llvm::ConstantFP::get(llvm::getGlobalContext(), llvm::APFloat(value));
}