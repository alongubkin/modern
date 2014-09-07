/** \file
 *  This C header file was generated by $ANTLR version 3.5.1
 *
 *     -  From the grammar source file : C:\\Users\\Alon\\Documents\\GitHub\\modern\\compiler\\ModernCompiler\\Modern.g
 *     -                            On : 2014-09-07 23:18:16
 *     -                for the parser : ModernParserParser
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The parser 
ModernParser

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pModernParser, which is returned from a call to ModernParserNew().
 *
 * The methods in pModernParser are  as follows:
 *
 *  - 
 ModernParser_program_return
      pModernParser->program(pModernParser)
 *  - 
 ModernParser_declaration_return
      pModernParser->declaration(pModernParser)
 *  - 
 ModernParser_variableDeclaration_return
      pModernParser->variableDeclaration(pModernParser)
 *  - 
 ModernParser_declarator_return
      pModernParser->declarator(pModernParser)
 *  - 
 ModernParser_functionHeader_return
      pModernParser->functionHeader(pModernParser)
 *  - 
 ModernParser_formalParameter_return
      pModernParser->formalParameter(pModernParser)
 *  - 
 ModernParser_type_return
      pModernParser->type(pModernParser)
 *  - 
 ModernParser_block_return
      pModernParser->block(pModernParser)
 *  - 
 ModernParser_statement_return
      pModernParser->statement(pModernParser)
 *  - 
 ModernParser_forStatement_return
      pModernParser->forStatement(pModernParser)
 *  - 
 ModernParser_returnStatement_return
      pModernParser->returnStatement(pModernParser)
 *  - 
 ModernParser_assignStatement_return
      pModernParser->assignStatement(pModernParser)
 *  - 
 ModernParser_expression_return
      pModernParser->expression(pModernParser)
 *  - 
 ModernParser_comparisonExpression_return
      pModernParser->comparisonExpression(pModernParser)
 *  - 
 ModernParser_comparisonOperator_return
      pModernParser->comparisonOperator(pModernParser)
 *  - 
 ModernParser_additionExpression_return
      pModernParser->additionExpression(pModernParser)
 *  - 
 ModernParser_multiplicationExpression_return
      pModernParser->multiplicationExpression(pModernParser)
 *  - 
 ModernParser_literal_return
      pModernParser->literal(pModernParser)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_ModernParser_H
#define _ModernParser_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct ModernParser_Ctx_struct ModernParser, * pModernParser;



#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif
typedef struct ModernParser_program_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_program_return;



typedef struct ModernParser_declaration_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_declaration_return;



typedef struct ModernParser_variableDeclaration_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_variableDeclaration_return;



typedef struct ModernParser_declarator_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_declarator_return;



typedef struct ModernParser_functionHeader_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_functionHeader_return;



typedef struct ModernParser_formalParameter_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_formalParameter_return;



typedef struct ModernParser_type_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_type_return;



typedef struct ModernParser_block_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_block_return;



typedef struct ModernParser_statement_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_statement_return;



typedef struct ModernParser_forStatement_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_forStatement_return;



typedef struct ModernParser_returnStatement_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_returnStatement_return;



typedef struct ModernParser_assignStatement_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_assignStatement_return;



typedef struct ModernParser_expression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_expression_return;



typedef struct ModernParser_comparisonExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_comparisonExpression_return;



typedef struct ModernParser_comparisonOperator_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_comparisonOperator_return;



typedef struct ModernParser_additionExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_additionExpression_return;



typedef struct ModernParser_multiplicationExpression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_multiplicationExpression_return;



typedef struct ModernParser_literal_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    ModernParser_literal_return;




/** Context tracking structure for 
ModernParser

 */
struct ModernParser_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_PARSER   pParser;

     ModernParser_program_return
     (*program)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_declaration_return
     (*declaration)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_variableDeclaration_return
     (*variableDeclaration)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_declarator_return
     (*declarator)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_functionHeader_return
     (*functionHeader)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_formalParameter_return
     (*formalParameter)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_type_return
     (*type)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_block_return
     (*block)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_statement_return
     (*statement)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_forStatement_return
     (*forStatement)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_returnStatement_return
     (*returnStatement)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_assignStatement_return
     (*assignStatement)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_expression_return
     (*expression)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_comparisonExpression_return
     (*comparisonExpression)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_comparisonOperator_return
     (*comparisonOperator)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_additionExpression_return
     (*additionExpression)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_multiplicationExpression_return
     (*multiplicationExpression)	(struct ModernParser_Ctx_struct * ctx);

     ModernParser_literal_return
     (*literal)	(struct ModernParser_Ctx_struct * ctx);
    // Delegated rules

    const char * (*getGrammarFileName)();
    void            (*reset)  (struct ModernParser_Ctx_struct * ctx);
    void	    (*free)   (struct ModernParser_Ctx_struct * ctx);
/* @headerFile.members() */
pANTLR3_BASE_TREE_ADAPTOR	adaptor;
pANTLR3_VECTOR_FACTORY		vectors;
/* End @headerFile.members() */
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pModernParser ModernParserNew         (
pANTLR3_COMMON_TOKEN_STREAM
 instream);
ANTLR3_API pModernParser ModernParserNewSSD      (
pANTLR3_COMMON_TOKEN_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
parser
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define T__32      32
#define T__33      33
#define T__34      34
#define T__35      35
#define T__36      36
#define T__37      37
#define T__38      38
#define T__39      39
#define T__40      40
#define T__41      41
#define T__42      42
#define T__43      43
#define ADDITION      4
#define ADDITION_OP      5
#define ARG_DEF      6
#define ASSIGNMENT      7
#define BLOCK      8
#define CHAR_TYPE      9
#define COMPARISON      10
#define EQ      11
#define EXPRESSION      12
#define FLOAT      13
#define FLOAT_LITERAL      14
#define FOR      15
#define FUNC_DECL      16
#define FUNC_DEF      17
#define FUNC_HDR      18
#define ID      19
#define IDENTIFIER      20
#define INT      21
#define INTEGER      22
#define INT_TYPE      23
#define MULTIPLY      24
#define MULTIPLY_OP      25
#define NeverUsedRule      26
#define PROGRAM      27
#define RETURN      28
#define VAR_DEF      29
#define VOID_TYPE      30
#define WS      31
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for ModernParser
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
