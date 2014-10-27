%{
#include <string>
#include <iostream>

#include "astnode.h"
#include "blang.tab.hpp"

using namespace std;

#define YY_DECL extern "C" int yylex()

#define SAVE_TOKEN  yylval.str = new string(yytext, yyleng);
#define TOKEN(t)    (yylval.token = t)

unsigned int _line = 0;
%}

%option stack

%x IN_COMMENT
%x STR

%%

[ \t]                   ;

"if"                    {   return TOKEN(IF);   }
"else"                  {   return TOKEN(ELSE);   }
"while"                 {   return TOKEN(WHILE);   }
"switch"                {   return TOKEN(SWITCH);   }
"case"                  {   return TOKEN(CASE);   }
"break"                 {   return TOKEN(BREAK);   }
"default"               {   return TOKEN(DEFAULT);   }
"auto"                  {   return TOKEN(AUTO);   }
"extrn"                 {   return TOKEN(EXTRN);   }
"goto"                  {   return TOKEN(GOTO);   }
"return"                {   return TOKEN(RETURN);   }

[a-zA-Z_][a-zA-Z0-9_]*  {   SAVE_TOKEN; return IDENT;   }
[0-9]+                  {   SAVE_TOKEN; return WORD;  }
                        
"="                     {   return TOKEN(ASSIGN);  }
"=|"                    {   return TOKEN(ASN_OR);  }
"=&"                    {   return TOKEN(ASN_AND); }
"=^"                    {   return TOKEN(ASN_XOR); }
"==="                   {   return TOKEN(ASN_EQ);  }
"=!="                   {   return TOKEN(ASN_NQ);  }
"=<"                    {   return TOKEN(ASN_LT);  }
"=<="                   {   return TOKEN(ASN_LTE); }
"=>"                    {   return TOKEN(ASN_GT);  }
"=>="                   {   return TOKEN(ASN_GTE); }
"=<<"                   {   return TOKEN(ASN_LSH); }
"=>>"                   {   return TOKEN(ASN_RSH); }
"=+"                    {   return TOKEN(ASN_ADD); }
"=-"                    {   return TOKEN(ASN_SUB); }
"=*"                    {   return TOKEN(ASN_MUL); }
"=/"                    {   return TOKEN(ASN_DIV); }
"=%"                    {   return TOKEN(ASN_MOD); }


"++"                    {   return TOKEN(UN_INC);   }
"--"                    {   return TOKEN(UN_DEC);   }

"-"                     {   return TOKEN(MAT_SUB);   }
"!"                     {   return TOKEN(LOG_NOT);   }

"|"                     {   return TOKEN(BIT_OR);   }
"&"                     {   return TOKEN(BIT_AND);   }
"^"                     {   return TOKEN(BIT_XOR);   }
"~"                     {   return TOKEN(BIT_NOT);  }
"=="                    {   return TOKEN(LOG_EQ);   }
"!="                    {   return TOKEN(LOG_NQ);   }
"<"                     {   return TOKEN(LOG_LT);   }
"<="                    {   return TOKEN(LOG_LTE);   }
">"                     {   return TOKEN(LOG_GT);   }
">="                    {   return TOKEN(LOG_GTE);   }
"<<"                    {   return TOKEN(BIT_LSH);   }
">>"                    {   return TOKEN(BIT_RSH);   }

"&&"                    {   return TOKEN(LOG_AND); }
"||"                    {   return TOKEN(LOG_OR);  }

"+"                     {   return TOKEN(MAT_ADD);   }
"%"                     {   return TOKEN(MAT_MOD);   }
"*"                     {   return TOKEN(MAT_MUL);   }
"/"                     {   return TOKEN(MAT_DIV);   }

"?"                     {   return TOKEN(LOG_TERNARY);   }
":"                     {   return TOKEN(COLON);   }

"{"                     {   return TOKEN(LBRACE);   }
"}"                     {   return TOKEN(RBRACE);   }

"["                     {   return TOKEN(LBRAK);   }
"]"                     {   return TOKEN(RBRAK);   }

"("                     {   return TOKEN(LPAREN);   }
")"                     {   return TOKEN(RPAREN);   }

";"                     {   return TOKEN(SCOLON);   }
","                     {   return TOKEN(COMMA);   }


\n                      {   _line++;   }

"/*"                    {   yy_push_state(IN_COMMENT); }
<IN_COMMENT>
{    
     [^/*\n]+             ;// eat comment in chunks
     "/*"               { yy_push_state(IN_COMMENT); }
     "*/"               { yy_pop_state(); }
     [*/]               ;
     \n                {_line++;}
}
%%