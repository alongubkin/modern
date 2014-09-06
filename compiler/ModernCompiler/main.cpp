#include "output/ModernLexer.h"
#include "output/ModernParser.h"

void visit(pANTLR3_BASE_TREE node);
void visitFunctionDefinition(pANTLR3_BASE_TREE node);
void visitFunctionHeader(pANTLR3_BASE_TREE node);
char *visitArgumentDefinition(pANTLR3_BASE_TREE node);
void visitBlock(pANTLR3_BASE_TREE node);
void visitVariableDeclaration(pANTLR3_BASE_TREE node);
void *visitExpression(pANTLR3_BASE_TREE node);
void *visitComparison(pANTLR3_BASE_TREE node);
void *visitAddition(pANTLR3_BASE_TREE node);
void *visitMultiply(pANTLR3_BASE_TREE node);
void visitAssignment(pANTLR3_BASE_TREE node);

pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE node, ANTLR3_UINT32 i);
char *getChildText(pANTLR3_BASE_TREE node, ANTLR3_UINT32 i);

int main(int argc, char *argv[]) 
{
	pANTLR3_INPUT_STREAM input =
		antlr3FileStreamNew((pANTLR3_UINT8)argv[1], ANTLR3_ENC_8BIT);

	pModernLexer lex = ModernLexerNew(input);
	
	pANTLR3_COMMON_TOKEN_STREAM tokens = 
		antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lex));

	pModernParser parser = ModernParserNew(tokens);
	
	ModernParser_program_return program = parser->program(parser);
	printf("%s\n\n", program.tree->toStringTree(program.tree)->chars);

	if (parser->pParser->rec->state->errorCount > 0) 
	{
		fprintf(stderr, "The parser returned %d errors, tree walking aborted.\n", parser->pParser->rec->state->errorCount);
	}
	else 
	{
		for (int i = 0, len = program.tree->getChildCount(program.tree); i < len; i++) 
		{
			visit((pANTLR3_BASE_TREE)program.tree->getChild(program.tree, i));
		}

	}
	
	parser->free(parser);
	tokens->free(tokens);
	lex->free(lex);
	input->close(input);

	getchar();

	return 0;	
}

void visit(pANTLR3_BASE_TREE node) 
{
	pANTLR3_COMMON_TOKEN token = node->getToken(node);
	pANTLR3_STRING tokenText = token->getText(token);
	char *tokenName = (char*)tokenText->chars;

	if (strcmp(tokenName, "FUNC_DEF") == 0) 
	{
		visitFunctionDefinition(node);
	}
	else if (strcmp(tokenName, "FUNC_HDR") == 0)
	{
		visitFunctionHeader(node);
	}
	else if (strcmp(tokenName, "BLOCK") == 0)
	{
		visitBlock(node);
	} 
	else if (strcmp(tokenName, "VAR_DEF") == 0)
	{
		visitVariableDeclaration(node);
	}
	else if (strcmp(tokenName, "EXPRESSION") == 0)
	{
		visitExpression(node);
	}
	else if (strcmp(tokenName, "ASSIGNMENT") == 0)
	{
		visitAssignment(node);
	}
}

void visitFunctionDefinition(pANTLR3_BASE_TREE node)
{
	visitFunctionHeader(getChild(node, 0));
	visitBlock(getChild(node, 1));
}

void visitFunctionHeader(pANTLR3_BASE_TREE node)
{
	char *returnType = getChildText(node, 0);
	char *funcName = getChildText(node, 1);

	printf("\n----------------------------\nFunction definition\n\tName: %s\n\tReturn Type: %s\n\n", funcName, returnType);

	for (int i = 2, len = node->getChildCount(node); i < len; i++)
	{
		visitArgumentDefinition(getChild(node, i));
	}
	printf("\n----------------------------\n");
}

char *visitArgumentDefinition(pANTLR3_BASE_TREE node)
{
	char *type = getChildText(node, 0);
	char *name = getChildText(node, 1);

	printf("Argument - Name: %s, Return Type: %s\n", name, type);
	return type;
}

void visitBlock(pANTLR3_BASE_TREE node)
{
	for (int i = 0, len = node->getChildCount(node); i < len; i++)
	{
		visit(getChild(node, i));
	}
}

void visitVariableDeclaration(pANTLR3_BASE_TREE node)
{
	char *type = getChildText(node, 0);
	char *name = getChildText(node, 1);

	printf("DECLARE VARIABLE -- %s %s", type, name);
}

void *visitExpression(pANTLR3_BASE_TREE node)
{
	if (node->getChildCount(node) == 0)
	{
		return node->getText(node)->chars;
	}

	return visitComparison(getChild(node, 0));
}

void *visitComparison(pANTLR3_BASE_TREE node)
{
	if (node->getChildCount(node) == 1)
		return visitAddition(getChild(node, 0));

	void *left = visitAddition(getChild(node, 0));
	char *op = getChildText(node, 1);
	void *right = visitAddition(getChild(node, 2));

	printf("compare %s", op);

	return NULL;
}

void *visitAddition(pANTLR3_BASE_TREE node)
{
	if (node->getChildCount(node) == 1)
		return visitMultiply(getChild(node, 0));

	void *left = visitMultiply(getChild(node, 0));
	char *op = getChildText(node, 1);
	void *right = visitMultiply(getChild(node, 2));

	printf("addition");

	return NULL;
}

void *visitMultiply(pANTLR3_BASE_TREE node)
{
	if (node->getChildCount(node) == 1)
		return visitExpression(getChild(node, 0));

	void *left = visitExpression(getChild(node, 0));
	char *op = getChildText(node, 1);
	void *right = visitExpression(getChild(node, 2));

	printf("multipication");

	return NULL;
}

void visitAssignment(pANTLR3_BASE_TREE node)
{
	char *variableName = getChildText(node, 0);
	void *expression = visitExpression(getChild(node, 1));
	
	printf("assignment");
}

pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE node, ANTLR3_UINT32 i)
{
	return (pANTLR3_BASE_TREE)node->getChild(node, i);
}

char *getChildText(pANTLR3_BASE_TREE node, ANTLR3_UINT32 i)
{
	pANTLR3_BASE_TREE childNode = getChild(node, i);
	return (char*)childNode->getText(childNode)->chars;
}