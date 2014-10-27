/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2013 Free Software Foundation, Inc.

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
    LPAREN = 271,
    RPAREN = 272,
    RBRAK = 273,
    LBRAK = 274,
    LBRACE = 275,
    RBRACE = 276,
    COMMA = 277,
    SCOLON = 278,
    COLON = 279,
    ASSIGN = 280,
    ASN_ADD = 281,
    ASN_SUB = 282,
    ASN_MUL = 283,
    ASN_DIV = 284,
    ASN_MOD = 285,
    ASN_AND = 286,
    ASN_OR = 287,
    ASN_XOR = 288,
    ASN_LSH = 289,
    ASN_RSH = 290,
    ASN_EQ = 291,
    ASN_NQ = 292,
    ASN_GT = 293,
    ASN_LT = 294,
    ASN_GTE = 295,
    ASN_LTE = 296,
    MAT_ADD = 297,
    MAT_DIV = 298,
    MAT_MOD = 299,
    UN_INC = 300,
    UN_DEC = 301,
    LOG_OR = 302,
    LOG_AND = 303,
    LOG_NOT = 304,
    LOG_EQ = 305,
    LOG_NQ = 306,
    LOG_LT = 307,
    LOG_GT = 308,
    LOG_LTE = 309,
    LOG_GTE = 310,
    LOG_TERNARY = 311,
    BIT_OR = 312,
    BIT_XOR = 313,
    BIT_LSH = 314,
    BIT_RSH = 315,
    BIT_NOT = 316,
    BIT_AND = 317,
    MAT_MUL = 318,
    MAT_SUB = 319,
    LOG_TCONDITIONAL = 320,
    UN_PREINC = 321,
    UN_PREDEC = 322,
    UN_ADDR = 323,
    UN_DREF = 324,
    UN_NEG = 325,
    PARENS_FCALL = 326,
    VEC_BRAK = 327,
    UN_POSTINC = 328,
    UN_POSTDEC = 329,
    DECL_COMMA = 330
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 21 "blang.y" /* glr.c:2555  */

    int tval;
    int token;
    std::string* str;

    NDefinition*    definition;
    NName*          name;

#line 140 "blang.tab.hpp" /* glr.c:2555  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BLANG_TAB_HPP_INCLUDED  */
