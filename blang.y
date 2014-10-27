%{
#include <cstdio>
#include <iostream>

#include "astnode.h"

using namespace std;

extern "C" int      yylex();
extern "C" int      yyparse();
extern "C" FILE*    yyin;

void yyerror(const char* err);

NProgram* blangProgram;

%}


%union 
{
    int tval;
    int token;
    std::string* str;

    NDefinition*    definition;
    NName*          name;
}

%token <str> WORD
%token <str> IDENT

%token <token> AUTO EXTRN IF ELSE WHILE SWITCH CASE DEFAULT RETURN BREAK GOTO 
%token <token> LPAREN RPAREN RBRAK LBRAK LBRACE RBRACE COMMA SCOLON COLON
%token <token> ASSIGN ASN_ADD ASN_SUB ASN_MUL ASN_DIV ASN_MOD ASN_AND ASN_OR ASN_XOR ASN_LSH ASN_RSH ASN_EQ ASN_NQ ASN_GT ASN_LT ASN_GTE ASN_LTE
%token <token> MAT_ADD MAT_DIV MAT_MOD UN_INC UN_DEC
%token <token> LOG_OR LOG_AND LOG_NOT LOG_EQ LOG_NQ LOG_LT LOG_GT LOG_LTE LOG_GTE LOG_TERNARY
%token <token> BIT_OR BIT_XOR BIT_LSH BIT_RSH BIT_NOT
%token <token> BIT_AND 
%token <token> MAT_MUL 
%token <token> MAT_SUB 

%type <definition>  program
%type <name>        name


//precedence is top down, low to high

%left COMMA

%right ASSIGN ASN_ADD ASN_SUB ASN_MUL ASN_DIV ASN_MOD ASN_AND ASN_OR ASN_XOR ASN_LSH ASN_RSH ASN_EQ ASN_NQ ASN_GT ASN_LT ASN_GTE ASN_LTE

//LOG_TCONDITIONAL is :
%right LOG_TERNARY LOG_TCONDITIONAL

%left LOG_OR
%left LOG_AND

%left BIT_OR
%left BIT_XOR
%left BIT_AND

%left LOG_EQ LOG_NQ
%left LOG_LT LOG_GT LOG_LTE LOG_GTE

%left BIT_LSH BIT_RSH

%left MAT_ADD MAT_SUB 
%left MAT_MUL MAT_DIV MAT_MOD

//operators & * - will need a second context precedence for unary
%right LOG_NOT UN_PREINC UN_PREDEC UN_ADDR UN_DREF UN_NEG BIT_NOT

// () [] high precedence
%left PARENS_FCALL VEC_BRAK UN_POSTINC UN_POSTDEC 

%nonassoc LBRAK RBRAK
%nonassoc LPAREN RPAREN
%nonassoc LBRACE RBRACE
%nonassoc DECL_COMMA SCOLON COLON

%token END 0 "end of file"

%glr-parser

%start program
%%

program : definitions { /*blangProgram = $1;*/ }
        ;

definitions : definition //{ $$ = new NProgram(); $$->m_extrnDefs.push_back($<definition>1); }
            | definitions definition //{ $1->m_extrnDefs.push_back($<definition>2); }
            ;

definition  : extrn_decl SCOLON | func_decl
            ;

extrn_decl  : name 
            | extrn_vector_decl
            ;


extrn_vector_decl : name LBRAK RBRAK
                  | name LBRAK constant RBRAK
                  | extrn_vector_decl vec_init_list
                  ;

vec_init_list   : ival
                | vec_init_list COMMA ival %prec DECL_COMMA
                ;

func_decl   : name LPAREN func_decl_args RPAREN statement
            ;

func_decl_args  : /* empty */ { }
                | name
                | func_decl_args COMMA name %prec DECL_COMMA
                ;


statement   : auto_decl             SCOLON  
            | extrn_decl_local      SCOLON  
            | name                  COLON   
            | case_statement
            | statement_block
            | if_statement
            | while_statement       
            | switch_statement     
            | GOTO      rvalue      SCOLON
            | RETURN    rvalue      SCOLON
            | RETURN                SCOLON
            | rvalue                SCOLON
            | BREAK                 SCOLON
            | SCOLON
            ;

statement_block : LBRACE RBRACE
                | LBRACE statements RBRACE
                ;

statements  : statement
            | statements statement
            ;

auto_decl   : initial_auto
            | auto_decl COMMA auto_list
            ;

initial_auto : AUTO name
             | AUTO name LBRAK RBRAK
             | AUTO name LBRAK constant RBRAK
             ;


next_auto   : name
            | name LBRAK RBRAK
            | name LBRAK constant RBRAK
            ;

auto_list   : next_auto
            | auto_list COMMA next_auto
            ;

extrn_decl_local    : EXTRN name
                    | extrn_decl_local COMMA extrn_decl_loc_list
                    ;

extrn_decl_loc_list : name
                    | extrn_decl_loc_list COMMA name
                    ;


if_statement : IF LPAREN rvalue RPAREN statement
             | IF LPAREN rvalue RPAREN statement ELSE statement
             ;

while_statement : WHILE LPAREN rvalue RPAREN statement
                ;

switch_statement : SWITCH rvalue statement
                 ;

case_statement  : CASE constant COLON statement
                | DEFAULT COLON statement
                ;


rvalue      : LPAREN rvalue RPAREN %prec PARENS_FCALL
            | assignment
            | UN_INC lvalue %prec UN_PREINC 
            | UN_DEC lvalue %prec UN_PREDEC 
            | lvalue UN_INC %prec UN_POSTINC
            | lvalue UN_DEC %prec UN_POSTDEC
            | BIT_AND lvalue %prec UN_ADDR      
            | MAT_SUB rvalue %prec UN_NEG
            | constant 
            | LOG_NOT rvalue
            | BIT_NOT rvalue
            | binary
            | rvalue LOG_TERNARY rvalue COLON rvalue %prec LOG_TCONDITIONAL
            | rvalue LPAREN call_args RPAREN %prec PARENS_FCALL
            | lvalue %dprec 1
            ;

call_args   : /* empty */
            | rvalue
            | call_args COMMA rvalue
            ;

lvalue      : name
            | MAT_MUL rvalue %prec UN_DREF
            | rvalue LBRAK rvalue RBRAK %prec VEC_BRAK
            ;

assignment  : lvalue ASSIGN rvalue | lvalue ASN_ADD rvalue | lvalue ASN_SUB rvalue | lvalue ASN_MUL rvalue | lvalue ASN_DIV rvalue | lvalue ASN_MOD rvalue 
            | lvalue ASN_AND rvalue | lvalue ASN_OR rvalue | lvalue ASN_XOR rvalue | lvalue ASN_LSH rvalue | lvalue ASN_RSH rvalue | lvalue ASN_EQ rvalue
            | lvalue ASN_NQ  rvalue | lvalue ASN_GT rvalue | lvalue ASN_LT rvalue  | lvalue ASN_GTE rvalue | lvalue ASN_LTE rvalue
            ;

binary      : rvalue MAT_ADD rvalue | rvalue MAT_SUB rvalue | rvalue MAT_MUL rvalue | rvalue MAT_DIV rvalue | rvalue MAT_MOD rvalue
            | rvalue BIT_OR rvalue | rvalue BIT_XOR rvalue | rvalue BIT_AND rvalue | rvalue BIT_LSH rvalue | rvalue BIT_RSH rvalue
            | rvalue LOG_LT rvalue | rvalue LOG_LTE rvalue | rvalue LOG_GT rvalue | rvalue LOG_GTE rvalue | rvalue LOG_EQ rvalue 
            | rvalue LOG_NQ rvalue | rvalue LOG_AND rvalue | rvalue LOG_OR rvalue
            ;

ival        : name
            | constant
            ;

name        : IDENT { }
            ;

constant    : WORD { }
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
