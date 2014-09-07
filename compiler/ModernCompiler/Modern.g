grammar Modern;

options 
{
    output			= AST;
    language		= C;
	ASTLabelType	= pANTLR3_BASE_TREE;
}

tokens 
{
	PROGRAM;
    VAR_DEF;
    ARG_DEF;
    FUNC_HDR;
    FUNC_DECL;
    FUNC_DEF;
    BLOCK;
    EXPRESSION;
    ASSIGNMENT;
    COMPARISON;
    MULTIPLY;
    ADDITION;
    IDENTIFIER;
    INTEGER;
    RETURN;
}

@header
{
   #define _empty NULL
}

program
    :   declaration+ -> ^(PROGRAM declaration+)
    ;

declaration
    :   variableDeclaration
    |   functionHeader block -> ^(FUNC_DEF functionHeader block)
    ;

variableDeclaration
    :   type declarator ';'	-> ^(VAR_DEF type declarator)
    ;

declarator
    :   ID 
    ;

functionHeader
    :   type ID '(' ( formalParameter ( ',' formalParameter )* )? ')'

				-> ^(FUNC_HDR type ID formalParameter+)
    ;

formalParameter
    :   type declarator 
				-> ^(ARG_DEF type declarator)
    ;

type
    :   'int'   
    |   'char'  
    |   'void'
    |   ID
    |	{false}? NeverUsedRule
    ;

block
    :   lc='{'
            variableDeclaration*
            statement*
        '}'
        -> ^(BLOCK[$lc, "BLOCK"] variableDeclaration* statement*)
    ;

statement
	: forStatement
    | expression ';'
    | block
    | assignStatement ';'
    | returnStatement ';'
    | ';'
    ;

forStatement
    :   'for' '(' start=assignStatement ';' e=expression ';' next=assignStatement ')' block
        -> ^('for' $start $e $next block)
    ;

returnStatement 
	: 'return' expression?
		-> ^(RETURN expression?)
	;
	
assignStatement
    :	ID EQ expression -> ^(ASSIGNMENT ^(IDENTIFIER ID) expression)
    ;

expression
	:	comparisonExpression -> ^(EXPRESSION comparisonExpression)
    ;

comparisonExpression
    :   additionExpression (comparisonOperator additionExpression)?  
			-> ^(COMPARISON additionExpression (comparisonOperator additionExpression)?)
    ;

comparisonOperator
	:	OPLT 
	|	EQEQ 
    |	{false}? NeverUsedRule	
	;

additionExpression
    :   multiplicationExpression ('+' multiplicationExpression)*  
    		-> ^(ADDITION multiplicationExpression  ('+' multiplicationExpression)*)
    ;

multiplicationExpression
    :   literal ('*' literal)* -> ^(MULTIPLY literal ('*' literal)*)
    ;

	
literal
    : ID -> ^(IDENTIFIER ID)
    | INT -> ^(INTEGER INT)
    | '(' expression ')' -> expression
    ; 
    

NeverUsedRule: /* don't care*/ ;

FOR : 'for' ;
INT_TYPE : 'int' ;
CHAR_TYPE: 'char';
VOID_TYPE: 'void';

ID  :   ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
    ;

INT :	('0'..'9')+
    ;

EQ   : '=' ;
EQEQ : '==' ;
OPLT   : '<' ;
PLUS : '+' ;

WS  :   (   ' '
        |   '\t'
        |   '\r'
        |   '\n'
        )+
        { $channel=HIDDEN; }
    ; 