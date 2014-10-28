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
    STRING = 259,
    CHAR = 260,
    IDENT = 261,
    AUTO = 262,
    EXTRN = 263,
    IF = 264,
    ELSE = 265,
    WHILE = 266,
    SWITCH = 267,
    CASE = 268,
    DEFAULT = 269,
    RETURN = 270,
    BREAK = 271,
    GOTO = 272,
    ASN_ADD = 273,
    ASN_SUB = 274,
    ASN_MUL = 275,
    ASN_DIV = 276,
    ASN_MOD = 277,
    ASN_AND = 278,
    ASN_OR = 279,
    ASN_XOR = 280,
    ASN_LSH = 281,
    ASN_RSH = 282,
    ASN_EQ = 283,
    ASN_NQ = 284,
    ASN_GT = 285,
    ASN_LT = 286,
    ASN_GTE = 287,
    ASN_LTE = 288,
    UN_INC = 289,
    UN_DEC = 290,
    LOG_LTE = 291,
    LOG_GTE = 292,
    BIT_LSH = 293,
    BIT_RSH = 294,
    LOG_EQ = 295,
    LOG_NQ = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 22 "blang.y" /* yacc.c:1909  */

    Blang::SizeType word;
    std::string* str;

    Blang::NDefinition*    definition;
    Blang::NName*          name;

#line 105 "blang.tab.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BLANG_TAB_HPP_INCLUDED  */
