#include "output/ModernLexer.h"
#include "output/ModernParser.h"


void visit(pANTLR3_BASE_TREE node);
void visitFunctionDefinition(pANTLR3_BASE_TREE node);
void visitFunctionHeader(pANTLR3_BASE_TREE node);
char *visitArgumentDefinition(pANTLR3_BASE_TREE node);
void visitBlock(pANTLR3_BASE_TREE node);
void visitVariableDeclaration(pANTLR3_BASE_TREE node);

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
}

void visitFunctionDefinition(pANTLR3_BASE_TREE node)
{
	visitFunctionHeader((pANTLR3_BASE_TREE)node->getChild(node, 0));
	visitBlock((pANTLR3_BASE_TREE)node->getChild(node, 1));
}

void visitFunctionHeader(pANTLR3_BASE_TREE node)
{
	pANTLR3_BASE_TREE returnTypeNode = (pANTLR3_BASE_TREE)node->getChild(node, 0);
	char *returnType = (char*)returnTypeNode->getText(returnTypeNode)->chars;

	pANTLR3_BASE_TREE funcNameNode = (pANTLR3_BASE_TREE)node->getChild(node, 1);
	char *funcName = (char*)funcNameNode->getText(funcNameNode)->chars;

	printf("\n----------------------------\nFunction definition\n\tName: %s\n\tReturn Type: %s\n\n", funcName, returnType);

	for (int i = 2, len = node->getChildCount(node); i < len; i++)
	{
		visitArgumentDefinition((pANTLR3_BASE_TREE)node->getChild(node, i));
	}
	printf("\n----------------------------\n");
}

char *visitArgumentDefinition(pANTLR3_BASE_TREE node)
{
	pANTLR3_BASE_TREE typeNode = (pANTLR3_BASE_TREE)node->getChild(node, 0);
	char *type = (char*)typeNode->getText(typeNode)->chars;

	pANTLR3_BASE_TREE nameNode = (pANTLR3_BASE_TREE)node->getChild(node, 1);
	char *name = (char*)nameNode->getText(nameNode)->chars;

	printf("Argument - Name: %s, Return Type: %s\n", name, type);
	return type;
}

void visitBlock(pANTLR3_BASE_TREE node)
{
	for (int i = 0, len = node->getChildCount(node); i < len; i++)
	{
		visit((pANTLR3_BASE_TREE)node->getChild(node, i));
	}
}

void visitVariableDeclaration(pANTLR3_BASE_TREE node)
{
	pANTLR3_BASE_TREE typeNode = (pANTLR3_BASE_TREE)node->getChild(node, 0);
	char *type = (char*)typeNode->getText(typeNode)->chars;

	pANTLR3_BASE_TREE nameNode = (pANTLR3_BASE_TREE)node->getChild(node, 1);
	char *name = (char*)nameNode->getText(nameNode)->chars;

	printf("DECLARE VARIABLE -- %s %s", type, name);
}