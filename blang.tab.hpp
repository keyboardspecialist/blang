/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_BLANG_TAB_HPP_INCLUDED
# define YY_YY_BLANG_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END = 0,
    WORD = 258,
    IDENT = 259,
    AUTO = 260,
    EXTRN = 261,
    IF = 262,
    ELSE = 263,
    WHILE = 264,
    SWITCH = 265,
    CASE = 266,
    DEFAULT = 267,
    RETURN = 268,
    BREAK = 269,
    GOTO = 270,
    ASN_ADD = 271,
    ASN_SUB = 272,
    ASN_MUL = 273,
    ASN_DIV = 274,
    ASN_MOD = 275,
    ASN_AND = 276,
    ASN_OR = 277,
    ASN_XOR = 278,
    ASN_LSH = 279,
    ASN_RSH = 280,
    ASN_EQ = 281,
    ASN_NQ = 282,
    ASN_GT = 283,
    ASN_LT = 284,
    ASN_GTE = 285,
    ASN_LTE = 286,
    UN_INC = 287,
    UN_DEC = 288,
    LOG_LTE = 289,
    LOG_GTE = 290,
    BIT_LSH = 291,
    BIT_RSH = 292,
    LOG_EQ = 293,
    LOG_NQ = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 21 "blang2.y" /* yacc.c:1909  */

    int tval;
    std::string* str;

    NDefinition*    definition;
    NName*          name;

#line 103 "blang.tab.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BLANG_TAB_HPP_INCLUDED  */
