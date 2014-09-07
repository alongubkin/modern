#ifndef _ASTGENERATOR_H
#define _ASTGENERATOR_H

#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/ManagedStatic.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"

#include <iostream>

#include "output/ModernLexer.h"
#include "output/ModernParser.h"

#include "ParseException.h"
#include "Node.h"
#include "FunctionNode.h"
#include "VariableDeclarationNode.h"
#include "ExpressionNode.h"
#include "LiteralNode.h"
#include "IdentifierNode.h"
#include "AssignmentNode.h"
#include "ReturnNode.h"

class ASTGenerator
{
private:
	std::string _fileName;
	pANTLR3_INPUT_STREAM _inputStream;
	pModernLexer _lexer;
	pANTLR3_COMMON_TOKEN_STREAM _tokenStream;
	pModernParser _parser;

	void Visit(const pANTLR3_BASE_TREE tree, Node *currentNode);
	void VisitProgram(const pANTLR3_BASE_TREE tree, Node *currentNode);
	void VisitBlock(const pANTLR3_BASE_TREE tree, Node *currentNode);
	void VisitFunctionDefinition(const pANTLR3_BASE_TREE tree, Node *currentNode);
	void VisitFunctionHeader(const pANTLR3_BASE_TREE tree, FunctionNode *currentNode);
	void VisitArgumentDefinition(const pANTLR3_BASE_TREE tree, FunctionNode *currentNode);
	void VisitVariableDeclaration(const pANTLR3_BASE_TREE tree, Node *currentNode);
	void VisitAssignment(const pANTLR3_BASE_TREE tree, Node *currentNode);
	void VisitExpression(const pANTLR3_BASE_TREE tree, Node *currentNode);
	void VisitComparasionExpression(const pANTLR3_BASE_TREE tree, Node *currentNode);
	void VisitArithmeticExpression(const pANTLR3_BASE_TREE tree, Node *currentNode);
	void VisitIntegerLiteral(const pANTLR3_BASE_TREE tree, Node *currentNode);
	void VisitFloatLiteral(const pANTLR3_BASE_TREE tree, Node *currentNode);
	void VisitIdentifier(const pANTLR3_BASE_TREE tree, Node *currentNode);
	void VisitReturn(const pANTLR3_BASE_TREE tree, Node *currentNode);

	pANTLR3_BASE_TREE GetChild(const pANTLR3_BASE_TREE tree, const ANTLR3_UINT32 index) const;
	std::string GetChildText(const pANTLR3_BASE_TREE tree, const ANTLR3_UINT32 index) const;
	std::string GetTreeToken(const pANTLR3_BASE_TREE tree) const;

public:
	ASTGenerator(const std::string fileName);
	~ASTGenerator();

	void Initialize();
	Node *Generate();
};

#endif