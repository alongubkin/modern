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
    FLOAT_LITERAL;
	DECLARATOR;  
	CALL;  
}

program
    :   declaration+ -> ^(PROGRAM declaration+)
    ;

declaration
    :   variableDeclaration
    |   functionHeader block -> ^(FUNC_DEF functionHeader block)
    ;

variableDeclaration
    :   type declarator (',' declarator)* ';'	
    		-> ^(VAR_DEF type declarator (declarator)*)
    ;

declarator
    :   ID initialiser?
    		-> ^(DECLARATOR ID initialiser?)
    ;

initialiser
	:	EQ expression -> expression
	;
	
functionHeader
    :   type ID '(' ( formalParameter ( ',' formalParameter )* )? ')'

				-> ^(FUNC_HDR type ID ( formalParameter ( formalParameter )* )?)
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
            statement*
        '}'
        -> ^(BLOCK[$lc, "BLOCK"] statement*)
    ;

statement
	: forStatement
    | expression ';'
    | block
    | assignStatement ';'
    | returnStatement ';'
    | variableDeclaration
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
	:	'<' 
	|	'<='
	|	'>'
	| 	'>='
	|	'=='
	|	{false}? NeverUsedRule	
	;

additionExpression
    :   multiplicationExpression (ADDITION_OP multiplicationExpression)*  
    		-> ^(ADDITION multiplicationExpression  (ADDITION_OP multiplicationExpression)*)
    ;

multiplicationExpression
    :   literal (MULTIPLY_OP literal)* 
    		-> ^(MULTIPLY literal (MULTIPLY_OP literal)*)
    ;
	
literal
    : ID -> ^(IDENTIFIER ID)
    | INT -> ^(INTEGER INT)
    | FLOAT -> ^(FLOAT_LITERAL FLOAT)
    | '(' expression ')' -> expression
    | call
    ; 
    
call
	: ID '(' (expression (',' expression)*)? ')'
		-> ^(CALL ID (expression (expression)*)?) 
	;
    

NeverUsedRule: /* don't care*/ ;

FOR : 'for' ;
INT_TYPE : 'int' ;
CHAR_TYPE: 'char';
VOID_TYPE: 'void';

ADDITION_OP
	:	 '+' | '-'
	;

MULTIPLY_OP
	: 	'*' | '/'
	;
	
ID  :   ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
    ;

INT :	('0'..'9')+
    ;

FLOAT
	:	('0'..'9')+ '.' ('0'..'9')*
	| 	'.' ('0'..'9')+
	;
	
EQ   : '=' ;

WS  :   (   ' '
        |   '\t'
        |   '\r'
        |   '\n'
        )+
        { $channel=HIDDEN; }
    ; 