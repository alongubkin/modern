#include "ASTGenerator.h"

ASTGenerator::ASTGenerator(const std::string fileName)
	: _fileName(fileName)
{
	_inputStream = NULL;
	_lexer = NULL;
	_tokenStream = NULL;
	_parser = NULL;

};

void ASTGenerator::Initialize()
{
	// open the file and initialize a character stream.
	_inputStream = antlr3FileStreamNew((pANTLR3_UINT8)_fileName.c_str(), ANTLR3_ENC_8BIT);

	// initialize a lexer, which is responsible for taking
	// a stream of characters and converting it to a
	// stream of tokens.
	_lexer = ModernLexerNew(_inputStream);

	// get the token stream from the lexer
	_tokenStream = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(_lexer));

	// the parser takes a token stream and generates
	// a syntax tree from it.
	_parser = ModernParserNew(_tokenStream);
}

Node *ASTGenerator::Generate()
{
	// start parsing
	ModernParser_program_return program = _parser->program(_parser);
	
	printf("%s\n\n", program.tree->toStringTree(program.tree)->chars);


	if (_parser->pParser->rec->state->errorCount > 0)
		throw ParseException("The parser returned errors, tree walking aborted.");

	Node *rootNode = new Node();
	Visit(program.tree, rootNode);
	
	return rootNode;
}

void ASTGenerator::Visit(const pANTLR3_BASE_TREE tree, Node *currentNode)
{
	std::string token = GetTreeToken(tree);
	
	if (token == "PROGRAM")
	{
		VisitProgram(tree, currentNode);
	}
	else if (token == "FUNC_DEF") 
	{
		VisitFunctionDefinition(tree, currentNode);
	}
	else if (token == "VAR_DEF")
	{
		VisitVariableDeclaration(tree, currentNode);
	}
	else if (token == "ASSIGNMENT")
	{
		VisitAssignment(tree, currentNode);
	}
}

void ASTGenerator::VisitProgram(const pANTLR3_BASE_TREE tree, Node *currentNode)
{
	for (int i = 0, len = tree->getChildCount(tree); i < len; i++)
	{
		Visit(GetChild(tree, i), currentNode);
	}
}

void ASTGenerator::VisitBlock(const pANTLR3_BASE_TREE tree, Node *currentNode)
{
	Node *node = new Node();
	currentNode->AddChild(node);

	for (int i = 0, len = tree->getChildCount(tree); i < len; i++)
	{
		Visit(GetChild(tree, i), node);
	}
}

void ASTGenerator::VisitFunctionDefinition(const pANTLR3_BASE_TREE tree, Node *currentNode)
{
	FunctionNode *node = new FunctionNode();
	currentNode->AddChild(node);

	VisitFunctionHeader(GetChild(tree, 0), node);
	VisitBlock(GetChild(tree, 1), node);
}

void ASTGenerator::VisitFunctionHeader(const pANTLR3_BASE_TREE tree, FunctionNode *currentNode)
{
	currentNode->SetReturnType(GetChildText(tree, 0));
	currentNode->SetName(GetChildText(tree, 1));

	for (int i = 2, len = tree->getChildCount(tree); i < len; i++)
	{
		VisitArgumentDefinition(GetChild(tree, i), currentNode);
	}
}

void ASTGenerator::VisitArgumentDefinition(const pANTLR3_BASE_TREE tree, FunctionNode *currentNode)
{
	Argument *arg = new Argument();
	arg->SetType(GetChildText(tree, 0));
	arg->SetName(GetChildText(tree, 1));
	
	currentNode->AddArgument(arg);
}

void ASTGenerator::VisitVariableDeclaration(const pANTLR3_BASE_TREE tree, Node *currentNode)
{
	VariableDeclarationNode *node = new VariableDeclarationNode();
	node->SetType(GetChildText(tree, 0));
	node->SetName(GetChildText(tree, 1));

	currentNode->AddChild(node);
}

void ASTGenerator::VisitAssignment(const pANTLR3_BASE_TREE tree, Node *currentNode)
{
	// ConstAssignmentNode
}

pANTLR3_BASE_TREE ASTGenerator::GetChild(const pANTLR3_BASE_TREE tree, const ANTLR3_UINT32 index) const
{
	return (pANTLR3_BASE_TREE)tree->getChild(tree, index);
}

std::string ASTGenerator::GetChildText(const pANTLR3_BASE_TREE tree, const ANTLR3_UINT32 index) const
{
	pANTLR3_BASE_TREE childNode = GetChild(tree, index);
	return std::string((char*)childNode->getText(childNode)->chars);
}

std::string ASTGenerator::GetTreeToken(const pANTLR3_BASE_TREE tree) const
{
	pANTLR3_COMMON_TOKEN token = tree->getToken(tree);
	return std::string((char*)token->getText(token)->chars);
}

ASTGenerator::~ASTGenerator()
{
	if (_parser != NULL)
	{
		_parser->free(_parser);
		_parser = NULL;
	}

	if (_tokenStream != NULL) 
	{
		_tokenStream->free(_tokenStream);
		_tokenStream = NULL;
	}

	if (_lexer != NULL)
	{
		_lexer->free(_lexer);
		_lexer = NULL;
	}

	if (_inputStream != NULL)
	{
		_inputStream->close(_inputStream);
		_inputStream = NULL;
	}
}
