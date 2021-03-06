%{
#include <cstdio>
#include <iostream>

#include "SizeType.h"
#include "astnode.h"

using namespace std;

extern "C" int      yylex();
extern "C" int      yyparse();
extern "C" FILE*    yyin;

void yyerror(const char* err);


bool g_isBoolean = false;

Blang::ProgramAST* blangProgram;
%}


%union 
{
	std::string* str;
    
    
    Blang::SizeType 		word;
	Blang::AssignOp_t		assign;
	Blang::UnaryOp_t		unary;
	
	Blang::ProgramAST*		program;
	
    Blang::ExtrnDefAST*		definition;
    Blang::AutoDeclAST*		adecl;
    Blang::DeclAST*			decl;

    Blang::ConstExprAST*    constant, *ival;

    Blang::StatementAST*	statement;
    Blang::ExpressionAST*	expression;
    Blang::NameAST*   		name;
    
    Blang::StatementASTList*	statement_list;
    Blang::AutoDeclASTList*		auto_decl_list;
    Blang::ExpressionASTList*	expression_list;
    Blang::NameASTList*			name_list;
    Blang::ConstExprASTList*	ival_list;
   
}

%token <word> WORD
%token <str> STRING
%token <str> CHAR
%token <str> IDENT

%token AUTO EXTRN IF ELSE WHILE SWITCH CASE DEFAULT RETURN BREAK GOTO 
%token ASN_ADD ASN_SUB ASN_MUL ASN_DIV ASN_MOD ASN_AND ASN_OR ASN_XOR 
%token ASN_LSH ASN_RSH ASN_EQ ASN_NQ ASN_GT ASN_LT ASN_GTE ASN_LTE
%token UN_INC UN_DEC LOG_LTE LOG_GTE BIT_LSH BIT_RSH LOG_EQ LOG_NQ

%type <program> extrn_definition_list

%type <definition> extrn_definition func_decl extrn_decl
%type <decl> decl
%type <adecl> adecl
%type <name> name

%type <statement> statement local_decl if_statement while_statement switch_statement 
%type <statement> expression_statement jump_statement statement_block labeled_statement selection_statement

%type <assign>		assignment_operator
%type <unary>  		unary_operator

%type <expression>  assignment_expression unary_expression if_expr_statement
%type <expression>  conditional_expression bitwise_or_expression bitwise_xor_expression bitwise_and_expression  postfix_expression primary_expression ival
%type <expression>  equality_expression relational_expression shift_expression additive_expression multiplicative_expression expression constant

%type <ival_list>       ival_list
%type <name_list>       name_list func_decl_parms extrn_decl_local
%type <statement_list>  local_decl_list statement_list
%type <auto_decl_list>  auto_decl_list auto_decl
%type <expression_list> arg_expression_list



%token END 0 "end of file"


%define parse.error verbose

%start blang_program
%%



blang_program
    : extrn_definition_list						{ blangProgram = $1; } 
    ;

extrn_definition_list
	: extrn_definition							{ $$ = new Blang::ProgramAST(); $$->m_extrnDefs.push_back($<definition>1); }
	| extrn_definition_list extrn_definition	{ $1->m_extrnDefs.push_back($<definition>2); }
	;
	
extrn_definition  
    : extrn_decl ';'					{ $$ = $<definition>1; }
    | func_decl							{ $$ = $<definition>1; }
    ;

extrn_decl  
    : decl								{ $$ = new Blang::ExtrnDeclAST($<decl>1, NULL); 			$<decl>1->m_storage = Blang::kExtrn; }			
    | decl ival_list					{ $$ = new Blang::ExtrnDeclAST($<decl>1, $<ival_list>2);  	$<decl>1->m_storage = Blang::kExtrn; }
    ;

func_decl   
    : name func_decl_parms statement	{ $$ = new Blang::FuncDeclAST($<name>1, $<ival_list>2, $<statement>3); /*funcs are always extrn*/ }
    ;

func_decl_parms  
    : '('               ')'	{ $$ = NULL; }
    | '('   ival_list   ')'	{ $$ = new Blang::NameASTList(*$<ival_list>2); }
    ;

name_list
    : name					{ $$ = new Blang::NameASTList(); $$->push_back($<name>1); }
    | name_list ',' name	{ $$->push_back($<name>3); }
    ;

ival_list
    : ival					{ $$ = new Blang::ConstExprASTList(); $$->push_back($<ival>1); }
    | ival_list ',' ival	{ $$->push_back($<ival>3); }
    ;

decl
    : name					{ $$ = new Blang::DeclAST($<name>1); }	
    | name '['          ']' { $$ = new Blang::VectorDeclAST($<name>1, NULL); }
    | name '[' constant ']' { $$ = new Blang::VectorDeclAST($<name>1, $<constant>3); }
    ;

statement   
    : labeled_statement  
    | statement_block
    | selection_statement
    | while_statement          
    | jump_statement
    | expression_statement
    ;

labeled_statement
    : name          ':' statement				{ $$ = new Blang::LabelStatementAST( $<name>1, $<statement>3 ); /*labels are always internal storage*/ }
    | CASE constant ':' statement				{ $$ = new Blang::CaseStatementAST ( $<constant>2, $<statement>4 ); }
    | DEFAULT       ':' statement				{ $$ = new Blang::CaseStatementAST ( $<statement>3 ); }
    ;

statement_block 
    : '{'                   '}'					{ $$ = new Blang::StatementBlockAST( NULL ); 	}
    | '{' local_decl_list   '}'					{ $$ = new Blang::StatementBlockAST( $<statement_list>2 );		}
    | '{' statement_list    '}'					{ $$ = new Blang::StatementBlockAST( $<statement_list>2 );		} 
    | '{' local_decl_list statement_list '}'	{ $$ = new Blang::StatementBlockAST( $<statement_list>2 ); $<statement_list>2->insert( $<statement_list>2->end(), 
                                                                                                                 $<statement_list>3->begin(), 
                                                                                                                 $<statement_list>3->end() ); delete $3; }
    ;

local_decl
    : auto_decl         ';'			{ $$ = new Blang::AutoDeclStatementAST( $<auto_decl_list>1 ); }
    | extrn_decl_local  ';'			{ $$ = new Blang::ExtrnDeclLocalStatementAST( $<name_list>1 ); }
    ;

local_decl_list
    : local_decl					{ $$ = new Blang::StatementASTList(); $$->push_back( $<statement>1 ); }
    | local_decl_list local_decl	{ $1->push_back( $<statement>2 ); }
    ;

auto_decl   
    : AUTO auto_decl_list			{ $$ = $<auto_decl_list>2; }
    ;

auto_decl_list
    : adecl							{ $$ = new Blang::AutoDeclASTList(); $$->push_back( $<adecl>1 ); }
    | auto_decl_list ',' adecl		{ $1->push_back( $<adecl>3 ); }
    ;
    
adecl
	: name							{ $$ = new Blang::AutoDeclAST( $<name>1, NULL ); }
	| name '[' constant ']'			{ $$ = new Blang::AutoDeclAST( $<name>1, $<constant>3 ); }
	;

extrn_decl_local    
    : EXTRN name_list				{ $$ = $<name_list>2; }
    ;

statement_list  
    : statement						{ $$ = new Blang::StatementASTList(); $$->push_back( $<statement>1 ); }
    | statement_list statement		{ $1->push_back( $<statement>2 ); }
    ;

selection_statement
    : if_statement
    | switch_statement
    ;

if_statement 
    : if_expr_statement statement                       { $$ = new Blang::IfStatementAST($<expression>1, $<statement>2, NULL); }
    | if_expr_statement statement ELSE statement    	{ $$ = new Blang::IfStatementAST($<expression>1, $<statement>2, $<statement>4); }
    ;

if_expr_statement
    : IF '('                                            { g_isBoolean = true;  } 
        expression ')'                                  { $$ = $<expression>4; g_isBoolean = false; }
    ;

switch_statement 
    : SWITCH '(' expression ')' statement				{ $$ = new Blang::SwitchStatementAST($<expression>3, $<statement>5); }
    ;

while_statement 
    : WHILE '('                                 { g_isBoolean = true; } 
        expression ')' statement				{ $$ = new Blang::WhileStatementAST($<expression>4, $<statement>5); g_isBoolean = false; }
    ;

jump_statement
    : GOTO name ';'						{ $$ = new Blang::GotoStatementAST( $<name>2 ); }
    | BREAK     ';'						{ $$ = new Blang::BreakStatementAST(); }
    | RETURN    ';'						{ $$ = new Blang::ReturnStatementAST( NULL ); }
    | RETURN 	'(' expression ')' ';'	{ $$ = new Blang::ReturnStatementAST( $<expression>3 ); }
    ;

expression_statement
    : ';'								{ $$ = new Blang::ExpressionStatementAST( NULL ); }
    | expression ';'					{ $$ = new Blang::ExpressionStatementAST($<expression>1); }
    ;

primary_expression
    : ival
    | '(' expression ')'				{ $$ = $<expression>2; }
    ;

postfix_expression
    : primary_expression
    | postfix_expression '[' expression ']'				{ $$ = new Blang::VectorExprAST( $<expression>1, $<expression>3 ); }
    | postfix_expression '('            ')'				{ $$ = new Blang::FuncCallExprAST( $<expression>1, NULL );	}
    | postfix_expression '(' arg_expression_list ')'	{ $$ = new Blang::FuncCallExprAST( $<expression>1, $<expression_list>2 );	}
    | postfix_expression UN_INC							{ $$ = new Blang::UnaryExpressionAST(Blang::kIncr, $<expression>2, true); 		}
    | postfix_expression UN_DEC							{ $$ = new Blang::UnaryExpressionAST(Blang::kDecr, $<expression>2, true); 		}
    ;

arg_expression_list
    : assignment_expression							{ $$ = new Blang::ExpressionASTList(); $$->push_back( $<expression>1 ); }
    | arg_expression_list ',' assignment_expression	{ $1->push_back( $<expression>3 ); }
    ;

unary_expression
    : postfix_expression
    | UN_INC unary_expression					{ $$ = new Blang::UnaryExpressionAST(Blang::kIncr, $<expression>2, false); }
    | UN_DEC unary_expression					{ $$ = new Blang::UnaryExpressionAST(Blang::kDecr, $<expression>2, false); }
    | unary_operator multiplicative_expression	{ $$ = new Blang::UnaryExpressionAST($<unary>1, $<expression>2, false); }
    ;

unary_operator
    : '&'			{ $$ = Blang::kAddrOf; }
    | '*'			{ $$ = Blang::kDeRef;  }
    | '-'			{ $$ = Blang::kNegate; }
    | '!'			{ $$ = Blang::kLogNot; }
    | '~'			{ $$ = Blang::kBitNot; }
    ;

multiplicative_expression
    : unary_expression
    | multiplicative_expression '*' unary_expression		{ $$ = new Blang::BinaryExpressionAST( $<expression>1, Blang::kMul, $<expression>3); }
    | multiplicative_expression '/' unary_expression		{ $$ = new Blang::BinaryExpressionAST( $<expression>1, Blang::kDiv, $<expression>3); }
    | multiplicative_expression '%' unary_expression		{ $$ = new Blang::BinaryExpressionAST( $<expression>1, Blang::kMod, $<expression>3); }
    ;

additive_expression
    : multiplicative_expression
    | additive_expression '+' multiplicative_expression		{ $$ = new Blang::BinaryExpressionAST( $<expression>1, Blang::kAdd, $<expression>3); }
    | additive_expression '-' multiplicative_expression		{ $$ = new Blang::BinaryExpressionAST( $<expression>1, Blang::kSub, $<expression>3); }
    ;

shift_expression
    : additive_expression
    | shift_expression BIT_LSH additive_expression			{ $$ = new Blang::BinaryExpressionAST( $<expression>1, Blang::kLshift, $<expression>3); }
    | shift_expression BIT_RSH additive_expression			{ $$ = new Blang::BinaryExpressionAST( $<expression>1, Blang::kRshift, $<expression>3); }
    ;

relational_expression
    : shift_expression
    | relational_expression '<' shift_expression			{ $$ = new Blang::BinaryExpressionAST( $<expression>1, Blang::kLess, $<expression>3); }
    | relational_expression '>' shift_expression			{ $$ = new Blang::BinaryExpressionAST( $<expression>1, Blang::kGreater, $<expression>3); }
    | relational_expression LOG_LTE shift_expression		{ $$ = new Blang::BinaryExpressionAST( $<expression>1, Blang::kLessEq, $<expression>3); }
    | relational_expression LOG_GTE shift_expression		{ $$ = new Blang::BinaryExpressionAST( $<expression>1, Blang::kGreaterEq, $<expression>3); }
    ;

equality_expression
    : relational_expression
    | equality_expression LOG_EQ relational_expression		{ $$ = new Blang::BinaryExpressionAST( $<expression>1, Blang::kEqual, $<expression>3); }
    | equality_expression LOG_NQ relational_expression		{ $$ = new Blang::BinaryExpressionAST( $<expression>1, Blang::kNotEqual, $<expression>3); }
    ;

bitwise_and_expression
    : equality_expression
    | bitwise_and_expression '&' equality_expression		{ $$ = new Blang::BinaryExpressionAST( $<expression>1, g_isBoolean ? Blang::kLogAnd : Blang::kAnd, $<expression>3); }
    ;

bitwise_xor_expression
    : bitwise_and_expression
    | bitwise_xor_expression '^' bitwise_and_expression		{ $$ = new Blang::BinaryExpressionAST( $<expression>1, Blang::kXor, $<expression>3); }
    ;

bitwise_or_expression
    : bitwise_xor_expression
    | bitwise_or_expression '|' bitwise_xor_expression		{ $$ = new Blang::BinaryExpressionAST( $<expression>1, g_isBoolean ? Blang::kLogOr : Blang::kOr, $<expression>3); }
    ;

conditional_expression
    : bitwise_or_expression
    | bitwise_or_expression '?' expression ':' conditional_expression	{ $$ = new Blang::ConditionalExpressionAST( $<expression>1, $<expression>3, $<expression>5 ); }
    ;

assignment_expression
    : conditional_expression
    | unary_expression assignment_operator assignment_expression		{ $$ = new Blang::AssignmentAST($<expression>1, $2, $<expression>3); }
    ;

assignment_operator
    : '='				{ $$ = Blang::kAssign; }
    | ASN_ADD			{ $$ = Blang::kAddAssign; }
    | ASN_SUB			{ $$ = Blang::kSubAssign; }
    | ASN_MUL			{ $$ = Blang::kMulAssign; }
    | ASN_DIV			{ $$ = Blang::kDivAssign; }
    | ASN_MOD 			{ $$ = Blang::kModAssign; }
    | ASN_AND			{ $$ = Blang::kAndAssign; }
    | ASN_OR			{ $$ = Blang::kOrAssign; }
    | ASN_XOR			{ $$ = Blang::kXorAssign; }
    | ASN_LSH			{ $$ = Blang::kLshAssign; }
    | ASN_RSH			{ $$ = Blang::kRshAssign; }
    | ASN_EQ			{ $$ = Blang::kEqAssign; }
    | ASN_NQ			{ $$ = Blang::kNqAssign; }
    | ASN_GT			{ $$ = Blang::kGtAssign; }
    | ASN_LT			{ $$ = Blang::kLtAssign; }
    | ASN_GTE			{ $$ = Blang::kGteAssign; }
    | ASN_LTE			{ $$ = Blang::kLteAssign; }
    ;

expression
    : assignment_expression
    ;


ival        
    : name		{ $$ = $<expression>1; }
    | constant	{ $$ = $<expression>1; }
    ;

name        
    : IDENT 	{ $$ = new Blang::NameAST(*$1); delete $1; }
    ;

constant    
    : WORD      { $$ = new Blang::WordConstantAST($1); printf("WORD: %ld\n", $1); }
    | STRING    { $$ = new Blang::StringConstantAST(*$1); delete $1; }
    | CHAR      { $$ = new Blang::CharConstantAST(*$1);   delete $1; }
    ;

%%


void
yyerror(const char* err)
{
    cout << "PARSE ERROR: " << err << endl;
    exit(-1);
}
