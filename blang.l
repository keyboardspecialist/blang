%{
#include <string>
#include <iostream>

#include "SizeType.h"
#include "astnode.h"
#include "blang.tab.hpp"

using namespace std;

#define YY_DECL extern "C" int yylex()

#define SAVE_STRING  yylval.str = new string(yytext, yyleng);
#define TOKEN(t)    t


Blang::SizeType numToST(const char* tok);

char* stripChar(const char* tok);
char* stripStr(const char* tok );

unsigned int _line = 0;

%}

%option stack

%x IN_COMMENT

%%

[ \t]                   ;

"if"                    {   return TOKEN(IF);       }
"else"                  {   return TOKEN(ELSE);     }
"while"                 {   return TOKEN(WHILE);    }
"switch"                {   return TOKEN(SWITCH);   }
"case"                  {   return TOKEN(CASE);     }
"break"                 {   return TOKEN(BREAK);    }
"default"               {   return TOKEN(DEFAULT);  }
"auto"                  {   return TOKEN(AUTO);     }
"extrn"                 {   return TOKEN(EXTRN);    }
"goto"                  {   return TOKEN(GOTO);     }
"return"                {   return TOKEN(RETURN);   }

[a-zA-Z_][a-zA-Z0-9_.]* {   SAVE_STRING; return IDENT; }

[0-9]+                  {   yylval.word = numToST(yytext);  
                            return WORD;  }

\"(\\.|[^\\"])*\"       {   SAVE_STRING; puts(yylval.str->c_str()); return STRING; }

\'(\\.|[^\\']){1,8}\'   {   SAVE_STRING; printf("CHAR: %s\n", yylval.str->c_str()); return CHAR;   }

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
"++"                    {   return TOKEN(UN_INC);  }
"--"                    {   return TOKEN(UN_DEC);  }
">="                    {   return TOKEN(LOG_GTE); }
"<<"                    {   return TOKEN(BIT_LSH); }
">>"                    {   return TOKEN(BIT_RSH); }
"<="                    {   return TOKEN(LOG_LTE); }
"=="                    {   return TOKEN(LOG_EQ);  }
"!="                    {   return TOKEN(LOG_NQ);  }

"="                     {   return TOKEN('=');   }
"-"                     {   return TOKEN('-');   }
"!"                     {   return TOKEN('!');   }
"|"                     {   return TOKEN('|');   }
"&"                     {   return TOKEN('&');   }
"^"                     {   return TOKEN('^');   }
"~"                     {   return TOKEN('~');   }
"<"                     {   return TOKEN('<');   }
">"                     {   return TOKEN('>');   }
"+"                     {   return TOKEN('+');   }
"%"                     {   return TOKEN('%');   }
"*"                     {   return TOKEN('*');   }
"/"                     {   return TOKEN('/');   }
"?"                     {   return TOKEN('?');   }
":"                     {   return TOKEN(':');   }
"{"                     {   return TOKEN('{');   }
"}"                     {   return TOKEN('}');   }
"["                     {   return TOKEN('[');   }
"]"                     {   return TOKEN(']');   }
"("                     {   return TOKEN('(');   }
")"                     {   return TOKEN(')');   }
";"                     {   return TOKEN(';');   }
","                     {   return TOKEN(',');   }


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

Blang::SizeType
numToST(const char* tok)
{
    char* p;
    Blang::SizeType out;

    int base = tok[0] == '0' ? 8 : 10; 

#ifdef BLANG_BUILD_64BIT
    
    out = strtoll(tok, &p, base);

#else
    
    out = strtol(tok, &p, base);

#endif

    return out;
}


char*
stripChar(const char* tok)
{
    char* out;
    int i = 1;

    out = (char*)malloc(strlen(tok) - 1);

    for(; i < strlen(tok)-1; i++)
    {
        switch(tok[i])
        {
            case '*':
                i++;
                switch(tok[i])
                {
                    case 'n':
                        out[i-2] = '\n';
                        break;

                    case 'e':
                        out[i-2] = -1;
                        break;

                    case '0':
                        out[i-2] = 0;
                        break;

                    case '{':
                    case '}':
                    case '\'':
                    case '"':
                    case '*':
                        out[i-2] = tok[i];
                        break;
                }
                break;

            case '\'':  //ignore closing '
                continue;

            default: out[i-1] = tok[i];
            break;
        }
    }

    out[i] = -1;

    return out;
}

char*
stripStr(const char* tok)
{
    return NULL;
}
