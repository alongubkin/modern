grammar Modern;

options 
{
    output			= AST;
    language		= C;
	ASTLabelType	= pANTLR3_BASE_TREE;
}

tokens 
{
    VAR_DEF;
    ARG_DEF;
    FUNC_HDR;
    FUNC_DECL;
    FUNC_DEF;
    BLOCK;
    ASSIGNMENT;
    COND;
    MULTIPLY;
    ADDITION;
}

@header
{
   #define _empty NULL
}

program
    :   declaration+
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
            variable*
            cstat*
        '}'
        -> ^(BLOCK[$lc, "BLOCK"] variable* cstat*)
    ;

statement
	: forStat
    | expr ';'!
    | block
    | assignStat ';'!
    | ';'!
    ;

forStat
    :   'for' '(' start=assignStat ';' e=expr ';' next=assignStat ')' block
        -> ^('for' $start $e $next block)
    ;

assignStat
    :   ID EQ expr -> ^(ASSIGNMENT ID expr)
    ;

expr:   condExpr
    ;

condExpr
    :   aexpr (logicOperator aexpr)?  -> ^(COND aexpr (logicOperator aexpr)?)
    ;

    
aexpr
    :   mexpr  ('+' mexpr)*  -> ^(ADDITION mexpr  ('+' mexpr)*)
    ;

mexpr
    :   atom ('*' atom)* -> ^(MULTIPLY atom ('*' atom)*)
    ;
    
atom
    : ID      
    | INT      
    | '(' expr ')' -> expr
    ; 
    
logicOperator
	:	OPLT | EQEQ 
    |	{false}? NeverUsedRule	
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