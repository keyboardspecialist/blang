/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "blang.y" /* yacc.c:339  */

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

#line 87 "blang.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "blang.tab.hpp".  */
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
#line 24 "blang.y" /* yacc.c:355  */

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
   

#line 198 "blang.tab.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BLANG_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 213 "blang.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   526

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,     2,     2,    57,    51,     2,
      43,    44,    52,    58,    45,    53,     2,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    42,
      59,    64,    60,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    62,    50,    55,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,   102,   103,   107,   108,   112,   113,   117,
     121,   122,   126,   127,   131,   132,   136,   137,   138,   142,
     143,   144,   145,   146,   147,   151,   152,   153,   157,   158,
     159,   160,   166,   167,   171,   172,   176,   180,   181,   185,
     186,   190,   194,   195,   199,   200,   204,   205,   209,   209,
     214,   218,   218,   223,   224,   225,   226,   230,   231,   235,
     236,   240,   241,   242,   243,   244,   245,   249,   250,   254,
     255,   256,   257,   261,   262,   263,   264,   265,   269,   270,
     271,   272,   276,   277,   278,   282,   283,   284,   288,   289,
     290,   291,   292,   296,   297,   298,   302,   303,   307,   308,
     312,   313,   317,   318,   322,   323,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   347,   352,   353,   357,   361,   362,   363
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "WORD", "STRING", "CHAR",
  "IDENT", "AUTO", "EXTRN", "IF", "ELSE", "WHILE", "SWITCH", "CASE",
  "DEFAULT", "RETURN", "BREAK", "GOTO", "ASN_ADD", "ASN_SUB", "ASN_MUL",
  "ASN_DIV", "ASN_MOD", "ASN_AND", "ASN_OR", "ASN_XOR", "ASN_LSH",
  "ASN_RSH", "ASN_EQ", "ASN_NQ", "ASN_GT", "ASN_LT", "ASN_GTE", "ASN_LTE",
  "UN_INC", "UN_DEC", "LOG_LTE", "LOG_GTE", "BIT_LSH", "BIT_RSH", "LOG_EQ",
  "LOG_NQ", "';'", "'('", "')'", "','", "'['", "']'", "':'", "'{'", "'}'",
  "'&'", "'*'", "'-'", "'!'", "'~'", "'/'", "'%'", "'+'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "'='", "$accept", "blang_program",
  "extrn_definition_list", "extrn_definition", "extrn_decl", "func_decl",
  "func_decl_parms", "name_list", "ival_list", "decl", "statement",
  "labeled_statement", "statement_block", "local_decl", "local_decl_list",
  "auto_decl", "auto_decl_list", "adecl", "extrn_decl_local",
  "statement_list", "selection_statement", "if_statement",
  "if_expr_statement", "$@1", "switch_statement", "while_statement", "$@2",
  "jump_statement", "expression_statement", "primary_expression",
  "postfix_expression", "arg_expression_list", "unary_expression",
  "unary_operator", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "bitwise_and_expression", "bitwise_xor_expression",
  "bitwise_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression", "ival",
  "name", "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    59,    40,    41,    44,    91,    93,    58,   123,
     125,    38,    42,    45,    33,   126,    47,    37,    43,    60,
      62,    94,   124,    63,    61
};
# endif

#define YYPACT_NINF -80

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-80)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -80,    16,     4,   -80,   -16,   -80,    59,   -29,   -80,
     -80,   -80,   -80,   -80,   -80,   -27,   -80,   -80,   -80,     3,
       2,   402,    59,   -80,    25,   -80,   -80,   -19,   -10,     5,
       7,    39,     8,    31,    18,     4,    33,    33,   -80,    33,
     190,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   402,   -80,   -80,   -80,   -80,   -80,    11,   462,    33,
     -32,   -26,    41,    -7,    42,    15,    -3,    29,   -80,   -80,
      72,   -80,    45,   -80,   -80,     4,   -80,   -80,   -80,    33,
      68,   402,   -80,    33,   -80,    76,   -80,   -80,    87,     4,
       4,   -80,   -80,   -80,   243,    90,    91,   296,   124,   -80,
     -80,   424,    33,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
      33,   -80,   -32,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
     -80,   402,   -80,    33,    33,    92,   402,   -80,    94,   -80,
     -80,    95,   -80,    89,    98,   -80,   -80,   349,   -80,   -80,
     -80,   -80,   402,   -80,    51,   -80,    97,   -80,   -80,   -80,
     -80,   -32,   -32,   -26,   -26,    41,    41,    41,    41,    -7,
      -7,    42,    15,    -3,    99,   -80,   101,   104,   402,   -80,
     107,     4,    39,   -80,   -80,   -80,    33,   -80,    33,   -80,
     402,   -80,   -80,   -80,   103,   -80,   -80,   -80,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   126,     0,     2,     3,     0,     6,     7,    16,     1,
       4,     5,   127,   128,   129,     8,    14,   124,   125,     0,
       0,     0,     0,    10,     0,    12,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
       0,    73,    74,    75,    76,    77,     9,    19,    20,    21,
      44,     0,    45,    22,    23,    24,    61,    69,    78,     0,
      82,    85,    88,    93,    96,    98,   100,   102,   104,   123,
       0,    59,   124,    15,    11,     0,    18,    48,    51,     0,
       0,     0,    55,     0,    54,     0,    70,    71,     0,     0,
       0,    28,    42,    34,     0,     0,     0,     0,    46,    65,
      66,     0,     0,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   106,
       0,    78,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,    13,     0,     0,     0,     0,    27,     0,    53,
      60,    36,    37,    39,    41,    29,    35,     0,    32,    33,
      30,    43,     0,    63,     0,    67,     0,   105,    79,    80,
      81,    84,    83,    86,    87,    91,    92,    89,    90,    94,
      95,    97,    99,   101,     0,    25,     0,     0,     0,    26,
       0,     0,     0,    31,    47,    64,     0,    62,     0,    49,
       0,    50,    56,    38,     0,    68,   103,    52,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   136,   -80,   -80,   -80,    61,   -80,   -80,
     -20,   -80,   -80,    58,   -80,   -80,   -80,   -38,   -80,    60,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -25,   -80,   -55,    -1,    -8,    -5,    19,    21,
      22,   -80,   -42,   -79,   -80,   -24,     1,     0,   -18
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,    21,    24,    15,     7,
      92,    47,    48,    93,    94,    95,   151,   152,    96,    97,
      49,    50,    51,   143,    52,    53,   144,    54,    55,    56,
      57,   164,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,   120,    70,    71,    17,    18
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       8,    46,    27,     8,   122,    12,    13,    14,    16,     1,
       1,    86,    87,    80,    19,    88,     9,    20,    22,    25,
     123,    72,   165,    73,   124,   125,    11,   126,    76,   130,
     131,    98,   127,    77,   121,    85,    12,    13,    14,     1,
      72,   167,    12,    13,    14,    99,   100,    23,    78,    26,
      79,    72,   132,   133,   101,   145,    81,   102,   137,   148,
      84,   147,    12,    13,    14,     1,   136,    36,    37,    74,
      75,   171,   172,    82,    83,   142,    39,   161,   166,   128,
     129,    72,   134,   135,    41,    42,    43,    44,    45,   153,
      25,   138,   139,   141,    72,   195,   196,    72,   168,   169,
     170,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   140,   184,   146,   205,   149,   186,
     187,   185,   175,   176,   177,   178,   189,   173,   174,   179,
     180,   150,   158,   159,   162,   192,   188,   161,   190,    10,
     191,    72,   194,    75,   197,   199,    72,   198,   200,   202,
     208,   154,   156,   203,   157,   181,   206,    72,   182,     0,
     183,     0,    72,     0,     0,     0,     0,     0,   201,     0,
       0,     0,     0,   121,   204,     0,     0,     0,     0,     0,
     207,     0,     0,     0,     0,     0,     0,     0,    72,     0,
       0,   153,     0,    12,    13,    14,     1,    89,    90,    28,
      72,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,     0,     0,     0,     0,
       0,     0,    38,    39,     0,     0,     0,     0,     0,    40,
      91,    41,    42,    43,    44,    45,    12,    13,    14,     1,
      89,    90,    28,     0,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    37,     0,
       0,     0,     0,     0,     0,    38,    39,     0,     0,     0,
       0,     0,    40,   155,    41,    42,    43,    44,    45,    12,
      13,    14,     1,     0,     0,    28,     0,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    37,     0,     0,     0,     0,     0,     0,    38,    39,
       0,     0,     0,     0,     0,    40,   160,    41,    42,    43,
      44,    45,    12,    13,    14,     1,     0,     0,    28,     0,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    37,     0,     0,     0,     0,     0,
       0,    38,    39,     0,     0,     0,     0,     0,    40,   193,
      41,    42,    43,    44,    45,    12,    13,    14,     1,     0,
       0,    28,     0,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,     0,    12,    13,    14,
       1,     0,     0,     0,     0,     0,    36,    37,     0,     0,
       0,     0,     0,     0,    38,    39,     0,     0,     0,     0,
       0,    40,     0,    41,    42,    43,    44,    45,    36,    37,
       0,     0,     0,     0,     0,     0,     0,    39,   163,     0,
       0,     0,     0,     0,     0,    41,    42,    43,    44,    45,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   119
};

static const yytype_int16 yycheck[] =
{
       0,    21,    20,     3,    59,     3,     4,     5,     7,     6,
       6,    36,    37,    31,    43,    39,     0,    46,    45,    19,
      52,    21,   101,    22,    56,    57,    42,    53,    47,    36,
      37,    51,    58,    43,    59,    35,     3,     4,     5,     6,
      40,   120,     3,     4,     5,    34,    35,    44,    43,    47,
      43,    51,    59,    60,    43,    79,    48,    46,    61,    83,
      42,    81,     3,     4,     5,     6,    51,    34,    35,    44,
      45,   126,   127,    42,    43,    75,    43,    97,   102,    38,
      39,    81,    40,    41,    51,    52,    53,    54,    55,    89,
      90,    62,    63,    48,    94,    44,    45,    97,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,    42,   139,    48,   196,    42,   143,
     144,   141,   130,   131,   132,   133,   146,   128,   129,   134,
     135,    44,    42,    42,    10,    46,    44,   157,    44,     3,
      45,   141,   162,    45,    47,    44,   146,    48,    44,    42,
      47,    90,    94,   191,    94,   136,   198,   157,   137,    -1,
     138,    -1,   162,    -1,    -1,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,   198,   192,    -1,    -1,    -1,    -1,    -1,
     200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,
      -1,   191,    -1,     3,     4,     5,     6,     7,     8,     9,
     200,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    54,    55,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    66,    67,    68,    69,    70,    74,   112,     0,
      68,    42,     3,     4,     5,    73,   111,   112,   113,    43,
      46,    71,    45,    44,    72,   112,    47,   113,     9,    11,
      12,    13,    14,    15,    16,    17,    34,    35,    42,    43,
      49,    51,    52,    53,    54,    55,    75,    76,    77,    85,
      86,    87,    89,    90,    92,    93,    94,    95,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     110,   111,   112,   111,    44,    45,    47,    43,    43,    43,
     113,    48,    42,    43,    42,   112,    97,    97,   110,     7,
       8,    50,    75,    78,    79,    80,    83,    84,    75,    34,
      35,    43,    46,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    64,
     109,    97,    99,    52,    56,    57,    53,    58,    38,    39,
      36,    37,    59,    60,    40,    41,    51,    61,    62,    63,
      42,    48,   112,    88,    91,   110,    48,    75,   110,    42,
      44,    81,    82,   112,    72,    50,    78,    84,    42,    42,
      50,    75,    10,    44,    96,   108,   110,   108,    97,    97,
      97,    99,    99,   100,   100,   101,   101,   101,   101,   102,
     102,   103,   104,   105,   110,    75,   110,   110,    44,    75,
      44,    45,    46,    50,    75,    44,    45,    47,    48,    44,
      44,    75,    42,    82,   113,   108,   107,    75,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    69,    69,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    74,    75,
      75,    75,    75,    75,    75,    76,    76,    76,    77,    77,
      77,    77,    78,    78,    79,    79,    80,    81,    81,    82,
      82,    83,    84,    84,    85,    85,    86,    86,    88,    87,
      89,    91,    90,    92,    92,    92,    92,    93,    93,    94,
      94,    95,    95,    95,    95,    95,    95,    96,    96,    97,
      97,    97,    97,    98,    98,    98,    98,    98,    99,    99,
      99,    99,   100,   100,   100,   101,   101,   101,   102,   102,
     102,   102,   102,   103,   103,   103,   104,   104,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   110,   111,   111,   112,   113,   113,   113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     2,     3,
       2,     3,     1,     3,     1,     3,     1,     3,     4,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     3,
       3,     4,     2,     2,     1,     2,     2,     1,     3,     1,
       4,     2,     1,     2,     1,     1,     2,     4,     0,     5,
       5,     0,     6,     3,     2,     2,     5,     1,     2,     1,
       3,     1,     4,     3,     4,     2,     2,     1,     3,     1,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 98 "blang.y" /* yacc.c:1646  */
    { blangProgram = (yyvsp[0].program); }
#line 1517 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 102 "blang.y" /* yacc.c:1646  */
    { (yyval.program) = new Blang::ProgramAST(); (yyval.program)->m_extrnDefs.push_back((yyvsp[0].definition)); }
#line 1523 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 103 "blang.y" /* yacc.c:1646  */
    { (yyvsp[-1].program)->m_extrnDefs.push_back((yyvsp[0].definition)); }
#line 1529 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 107 "blang.y" /* yacc.c:1646  */
    { (yyval.definition) = (yyvsp[-1].definition); }
#line 1535 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 108 "blang.y" /* yacc.c:1646  */
    { (yyval.definition) = (yyvsp[0].definition); }
#line 1541 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 112 "blang.y" /* yacc.c:1646  */
    { (yyval.definition) = new Blang::ExtrnDeclAST((yyvsp[0].decl), NULL); 			(yyvsp[0].decl)->m_storage = Blang::kExtrn; }
#line 1547 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 113 "blang.y" /* yacc.c:1646  */
    { (yyval.definition) = new Blang::ExtrnDeclAST((yyvsp[-1].decl), (yyvsp[0].ival_list));  	(yyvsp[-1].decl)->m_storage = Blang::kExtrn; }
#line 1553 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "blang.y" /* yacc.c:1646  */
    { (yyval.definition) = new Blang::FuncDeclAST((yyvsp[-2].name), (yyvsp[-1].name_list), (yyvsp[0].statement)); /*funcs are always extrn*/ }
#line 1559 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 121 "blang.y" /* yacc.c:1646  */
    { (yyval.name_list) = NULL; }
#line 1565 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 122 "blang.y" /* yacc.c:1646  */
    { (yyval.name_list) = new Blang::NameASTList(*(yyvsp[-1].name_list)); }
#line 1571 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 126 "blang.y" /* yacc.c:1646  */
    { (yyval.name_list) = new Blang::NameASTList(); (yyval.name_list)->push_back((yyvsp[0].name)); }
#line 1577 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 127 "blang.y" /* yacc.c:1646  */
    { (yyval.name_list)->push_back((yyvsp[0].name)); }
#line 1583 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 131 "blang.y" /* yacc.c:1646  */
    { (yyval.ival_list) = new Blang::ConstExprASTList(); (yyval.ival_list)->push_back((yyvsp[0].ival)); }
#line 1589 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 132 "blang.y" /* yacc.c:1646  */
    { (yyval.ival_list)->push_back((yyvsp[0].ival)); }
#line 1595 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 136 "blang.y" /* yacc.c:1646  */
    { (yyval.decl) = new Blang::DeclAST((yyvsp[0].name)); }
#line 1601 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 137 "blang.y" /* yacc.c:1646  */
    { (yyval.decl) = new Blang::VectorDeclAST((yyvsp[-2].name), NULL); }
#line 1607 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 138 "blang.y" /* yacc.c:1646  */
    { (yyval.decl) = new Blang::VectorDeclAST((yyvsp[-3].name), (yyvsp[-2].constant)); }
#line 1613 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 151 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::LabelStatementAST( (yyvsp[-2].name), (yyvsp[0].statement) ); /*labels are always internal storage*/ }
#line 1619 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 152 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::CaseStatementAST ( (yyvsp[-2].constant), (yyvsp[0].statement) ); }
#line 1625 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 153 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::CaseStatementAST ( (yyvsp[0].statement) ); }
#line 1631 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 157 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::StatementBlockAST( NULL ); 	}
#line 1637 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 158 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::StatementBlockAST( (yyvsp[-1].statement_list) );		}
#line 1643 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 159 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::StatementBlockAST( (yyvsp[-1].statement_list) );		}
#line 1649 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 160 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::StatementBlockAST( (yyvsp[-2].statement_list) ); (yyvsp[-2].statement_list)->insert( (yyvsp[-2].statement_list)->end(), 
                                                                                                                 (yyvsp[-1].statement_list)->begin(), 
                                                                                                                 (yyvsp[-1].statement_list)->end() ); delete (yyvsp[-1].statement_list); }
#line 1657 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 166 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::AutoDeclStatementAST( (yyvsp[-1].auto_decl_list) ); }
#line 1663 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 167 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::ExtrnDeclLocalStatementAST( (yyvsp[-1].name_list) ); }
#line 1669 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 171 "blang.y" /* yacc.c:1646  */
    { (yyval.statement_list) = new Blang::StatementASTList(); (yyval.statement_list)->push_back( (yyvsp[0].statement) ); }
#line 1675 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 172 "blang.y" /* yacc.c:1646  */
    { (yyvsp[-1].statement_list)->push_back( (yyvsp[0].statement) ); }
#line 1681 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 176 "blang.y" /* yacc.c:1646  */
    { (yyval.auto_decl_list) = (yyvsp[0].auto_decl_list); }
#line 1687 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 180 "blang.y" /* yacc.c:1646  */
    { (yyval.auto_decl_list) = new Blang::AutoDeclASTList(); (yyval.auto_decl_list)->push_back( (yyvsp[0].adecl) ); }
#line 1693 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 181 "blang.y" /* yacc.c:1646  */
    { (yyvsp[-2].auto_decl_list)->push_back( (yyvsp[0].adecl) ); }
#line 1699 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 185 "blang.y" /* yacc.c:1646  */
    { (yyval.adecl) = new Blang::AutoDeclAST( (yyvsp[0].name), NULL ); }
#line 1705 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 186 "blang.y" /* yacc.c:1646  */
    { (yyval.adecl) = new Blang::AutoDeclAST( (yyvsp[-3].name), (yyvsp[-1].constant) ); }
#line 1711 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 190 "blang.y" /* yacc.c:1646  */
    { (yyval.name_list) = (yyvsp[0].name_list); }
#line 1717 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 194 "blang.y" /* yacc.c:1646  */
    { (yyval.statement_list) = new Blang::StatementASTList(); (yyval.statement_list)->push_back( (yyvsp[0].statement) ); }
#line 1723 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 195 "blang.y" /* yacc.c:1646  */
    { (yyvsp[-1].statement_list)->push_back( (yyvsp[0].statement) ); }
#line 1729 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 204 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::IfStatementAST((yyvsp[-1].expression), (yyvsp[0].statement), NULL); }
#line 1735 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 205 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::IfStatementAST((yyvsp[-3].expression), (yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1741 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 209 "blang.y" /* yacc.c:1646  */
    { g_isBoolean = true;  }
#line 1747 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 210 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[-1].expression); g_isBoolean = false; }
#line 1753 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 214 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::SwitchStatementAST((yyvsp[-2].expression), (yyvsp[0].statement)); }
#line 1759 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 218 "blang.y" /* yacc.c:1646  */
    { g_isBoolean = true; }
#line 1765 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 219 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::WhileStatementAST((yyvsp[-2].expression), (yyvsp[-1].statement)); g_isBoolean = false; }
#line 1771 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 223 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::GotoStatementAST( (yyvsp[-1].name) ); }
#line 1777 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 224 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::BreakStatementAST(); }
#line 1783 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 225 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::ReturnStatementAST( NULL ); }
#line 1789 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 226 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::ReturnStatementAST( (yyvsp[-2].expression) ); }
#line 1795 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 230 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::ExpressionStatementAST( NULL ); }
#line 1801 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 231 "blang.y" /* yacc.c:1646  */
    { (yyval.statement) = new Blang::ExpressionStatementAST((yyvsp[-1].expression)); }
#line 1807 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 236 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[-1].expression); }
#line 1813 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 241 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::VectorExprAST( (yyvsp[-3].expression), (yyvsp[-1].expression) ); }
#line 1819 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 242 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::FuncCallExprAST( (yyvsp[-2].expression), NULL );	}
#line 1825 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 243 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::FuncCallExprAST( (yyvsp[-3].expression), (yyvsp[-2].expression_list) );	}
#line 1831 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 244 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::UnaryExpressionAST(Blang::kIncr, (yyvsp[0].expression), true); 		}
#line 1837 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 245 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::UnaryExpressionAST(Blang::kDecr, (yyvsp[0].expression), true); 		}
#line 1843 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 249 "blang.y" /* yacc.c:1646  */
    { (yyval.expression_list) = new Blang::ExpressionASTList(); (yyval.expression_list)->push_back( (yyvsp[0].expression) ); }
#line 1849 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 250 "blang.y" /* yacc.c:1646  */
    { (yyvsp[-2].expression_list)->push_back( (yyvsp[0].expression) ); }
#line 1855 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 255 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::UnaryExpressionAST(Blang::kIncr, (yyvsp[0].expression), false); }
#line 1861 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 256 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::UnaryExpressionAST(Blang::kDecr, (yyvsp[0].expression), false); }
#line 1867 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 257 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::UnaryExpressionAST((yyvsp[-1].unary), (yyvsp[0].expression), false); }
#line 1873 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 261 "blang.y" /* yacc.c:1646  */
    { (yyval.unary) = Blang::kAddrOf; }
#line 1879 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 262 "blang.y" /* yacc.c:1646  */
    { (yyval.unary) = Blang::kDeRef;  }
#line 1885 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 263 "blang.y" /* yacc.c:1646  */
    { (yyval.unary) = Blang::kNegate; }
#line 1891 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 264 "blang.y" /* yacc.c:1646  */
    { (yyval.unary) = Blang::kLogNot; }
#line 1897 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 265 "blang.y" /* yacc.c:1646  */
    { (yyval.unary) = Blang::kBitNot; }
#line 1903 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 270 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), Blang::kMul, (yyvsp[0].expression)); }
#line 1909 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 271 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), Blang::kDiv, (yyvsp[0].expression)); }
#line 1915 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 272 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), Blang::kMod, (yyvsp[0].expression)); }
#line 1921 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 277 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), Blang::kAdd, (yyvsp[0].expression)); }
#line 1927 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 278 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), Blang::kSub, (yyvsp[0].expression)); }
#line 1933 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 283 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), Blang::kLshift, (yyvsp[0].expression)); }
#line 1939 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 284 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), Blang::kRshift, (yyvsp[0].expression)); }
#line 1945 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 289 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), Blang::kLess, (yyvsp[0].expression)); }
#line 1951 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 290 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), Blang::kGreater, (yyvsp[0].expression)); }
#line 1957 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 291 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), Blang::kLessEq, (yyvsp[0].expression)); }
#line 1963 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 292 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), Blang::kGreaterEq, (yyvsp[0].expression)); }
#line 1969 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 297 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), Blang::kEqual, (yyvsp[0].expression)); }
#line 1975 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 298 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), Blang::kNotEqual, (yyvsp[0].expression)); }
#line 1981 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 303 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), g_isBoolean ? Blang::kLogAnd : Blang::kAnd, (yyvsp[0].expression)); }
#line 1987 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 308 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), Blang::kXor, (yyvsp[0].expression)); }
#line 1993 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 313 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::BinaryExpressionAST( (yyvsp[-2].expression), g_isBoolean ? Blang::kLogOr : Blang::kOr, (yyvsp[0].expression)); }
#line 1999 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 318 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::ConditionalExpressionAST( (yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].expression) ); }
#line 2005 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 323 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::AssignmentAST((yyvsp[-2].expression), (yyvsp[-1].assign), (yyvsp[0].expression)); }
#line 2011 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 327 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kAssign; }
#line 2017 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 328 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kAddAssign; }
#line 2023 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 329 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kSubAssign; }
#line 2029 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 330 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kMulAssign; }
#line 2035 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 331 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kDivAssign; }
#line 2041 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 332 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kModAssign; }
#line 2047 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 333 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kAndAssign; }
#line 2053 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 334 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kOrAssign; }
#line 2059 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 335 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kXorAssign; }
#line 2065 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 336 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kLshAssign; }
#line 2071 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 337 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kRshAssign; }
#line 2077 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 338 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kEqAssign; }
#line 2083 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 339 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kNqAssign; }
#line 2089 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 340 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kGtAssign; }
#line 2095 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 341 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kLtAssign; }
#line 2101 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 342 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kGteAssign; }
#line 2107 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 343 "blang.y" /* yacc.c:1646  */
    { (yyval.assign) = Blang::kLteAssign; }
#line 2113 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 352 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2119 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 353 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2125 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 357 "blang.y" /* yacc.c:1646  */
    { (yyval.name) = new Blang::NameAST(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 2131 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 361 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::WordConstantAST((yyvsp[0].word)); printf("WORD: %ld\n", (yyvsp[0].word)); }
#line 2137 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 362 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::StringConstantAST(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 2143 "blang.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 363 "blang.y" /* yacc.c:1646  */
    { (yyval.expression) = new Blang::CharConstantAST(*(yyvsp[0].str));   delete (yyvsp[0].str); }
#line 2149 "blang.tab.cpp" /* yacc.c:1646  */
    break;


#line 2153 "blang.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 366 "blang.y" /* yacc.c:1906  */


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
