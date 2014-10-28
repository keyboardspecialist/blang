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

Blang::NProgram* blangProgram;

%}


%union 
{
    Blang::SizeType word;
    std::string* str;

    Blang::NDefinition*    definition;
    Blang::NName*          name;
}

%token <word> WORD
%token <str> STRING
%token <str> CHAR

%token <str> IDENT


%token AUTO EXTRN IF ELSE WHILE SWITCH CASE DEFAULT RETURN BREAK GOTO 
%token ASN_ADD ASN_SUB ASN_MUL ASN_DIV ASN_MOD ASN_AND ASN_OR ASN_XOR 
%token ASN_LSH ASN_RSH ASN_EQ ASN_NQ ASN_GT ASN_LT ASN_GTE ASN_LTE
%token UN_INC UN_DEC LOG_LTE LOG_GTE BIT_LSH BIT_RSH LOG_EQ LOG_NQ

%token END 0 "end of file"

%start blang_program
%%

blang_program
    : extrn_definition
    | blang_program extrn_definition
    ;

extrn_definition  
    : extrn_decl ';'
    | func_decl
    ;

extrn_decl  
    : decl
    | decl ival_list
    ;

func_decl   
    : name func_decl_args statement
    ;

func_decl_args  
    : '('               ')'
    | '('   name_list   ')'
    ;

name_list
    : name
    | name_list ',' name
    ;

ival_list
    : ival
    | ival_list ',' ival
    ;

decl
    : name
    | name '['          ']'
    | name '[' constant ']'
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
    : name          ':' statement
    | CASE constant ':' statement
    | DEFAULT       ':' statement
    ;

statement_block 
    : '{'                   '}'
    | '{' local_decl_list   '}'
    | '{' statement_list    '}'
    | '{' local_decl_list statement_list '}'
    ;

local_decl
    : auto_decl         ';'
    | extrn_decl_local  ';'
    ;

local_decl_list
    : local_decl
    | local_decl_list local_decl
    ;

auto_decl   
    : AUTO auto_decl_list
    ;

auto_decl_list
    : decl
    | auto_decl_list ',' decl
    ;

extrn_decl_local    
    : EXTRN name_list
    ;

statement_list  
    : statement
    | statement_list statement
    ;

selection_statement
    : if_statement
    | switch_statement
    ;

if_statement 
    : IF '(' expression ')' statement
    | IF '(' expression ')' statement ELSE statement
    ;

switch_statement 
    : SWITCH expression statement
    ;

while_statement 
    : WHILE '(' expression ')' statement
    ;

jump_statement
    : GOTO name ';'
    | BREAK     ';'
    | RETURN    ';'
    | RETURN expression ';'
    ;

expression_statement
    : ';'
    | expression ';'
    ;

primary_expression
    : ival
    | '(' expression ')'
    ;

postfix_expression
    : primary_expression
    | postfix_expression '[' expression ']'
    | postfix_expression '('            ')'
    | postfix_expression '(' arg_expression_list ')'
    | postfix_expression UN_INC
    | postfix_expression UN_DEC
    ;

arg_expression_list
    : assignment_expression
    | arg_expression_list ',' assignment_expression
    ;

unary_expression
    : postfix_expression
    | UN_INC unary_expression
    | UN_DEC unary_expression
    | unary_operator multiplicative_expression
    ;

unary_operator
    : '&'
    | '*'
    | '-'
    | '!'
    | '~'
    ;

multiplicative_expression
    : unary_expression
    | multiplicative_expression '*' unary_expression
    | multiplicative_expression '/' unary_expression
    | multiplicative_expression '%' unary_expression
    ;

additive_expression
    : multiplicative_expression
    | additive_expression '+' multiplicative_expression
    | additive_expression '-' multiplicative_expression
    ;

shift_expression
    : additive_expression
    | shift_expression BIT_LSH additive_expression
    | shift_expression BIT_RSH additive_expression
    ;

relational_expression
    : shift_expression
    | relational_expression '<' shift_expression
    | relational_expression '>' shift_expression
    | relational_expression LOG_LTE shift_expression
    | relational_expression LOG_GTE shift_expression
    ;

equality_expression
    : relational_expression
    | equality_expression LOG_EQ relational_expression
    | equality_expression LOG_NQ relational_expression
    ;

bitwise_and_expression
    : equality_expression
    | bitwise_and_expression '&' equality_expression
    ;

bitwise_xor_expression
    : bitwise_and_expression
    | bitwise_xor_expression '^' bitwise_and_expression
    ;

bitwise_or_expression
    : bitwise_xor_expression
    | bitwise_or_expression '|' bitwise_xor_expression
    ;

conditional_expression
    : bitwise_or_expression
    | bitwise_or_expression '?' expression ':' conditional_expression
    ;

assignment_expression
    : conditional_expression
    | unary_expression assignment_operator assignment_expression
    ;

assignment_operator
    : '='
    | ASN_ADD
    | ASN_SUB
    | ASN_MUL
    | ASN_DIV
    | ASN_MOD 
    | ASN_AND
    | ASN_OR
    | ASN_XOR
    | ASN_LSH
    | ASN_RSH
    | ASN_EQ
    | ASN_NQ
    | ASN_GT
    | ASN_LT
    | ASN_GTE
    | ASN_LTE
    ;

expression
    : assignment_expression
    ;


ival        
    : name
    | constant
    ;

name        
    : IDENT { }
    ;

constant    
    : WORD      { cout << $1 << endl; }
    | STRING    { cout << *$1 << endl; }
    | CHAR      { cout << *$1 << endl; }
    ;

%%

int
main(int argc, char* argv[])
{
    if(argc == 1)
    {
        cout << "Missing input file" << endl;
        return 0;
    }

    FILE* fp;
    if((fp = fopen(argv[1], "r")))
    {
        yyin = fp;
        while(!feof(yyin))
            yyparse();
    }
    else
    {
        cout << "Couldn't open file[" << argv[1] << "]" << endl;
    }
    
    return 0;
}

void
yyerror(const char* err)
{
    cout << "PARSE ERROR: " << err << endl;
    exit(-1);
}
