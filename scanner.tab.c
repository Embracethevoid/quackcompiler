/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "scanner.y" /* yacc.c:339  */

#include <cstdio>
#include <iostream>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <memory>
//#include "expr.h"
#include "AST.h"
#include "codegen.h"
//#include "./src/expr.h"
//#include "./src/method_class.h"
//#include "./src/stmt.h"
//#include "./src/node.h"
using namespace std;
// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int yylineno;
extern char* yytext;
extern basic_class* Obj ;
void yyerror(const char *s);
program* root;

#line 92 "scanner.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "scanner.tab.h".  */
#ifndef YY_YY_SCANNER_TAB_H_INCLUDED
# define YY_YY_SCANNER_TAB_H_INCLUDED
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
    EXTENDS = 258,
    CLASS = 259,
    WHILE = 260,
    IF = 261,
    ELSE = 262,
    ELIF = 263,
    RETURN = 264,
    DEF = 265,
    ENDL = 266,
    COLON = 267,
    SEMICOLON = 268,
    LP = 269,
    RP = 270,
    LB = 271,
    RB = 272,
    DOT = 273,
    COMMA = 274,
    GETS = 275,
    MISS = 276,
    ILLEGAL = 277,
    AND = 278,
    OR = 279,
    NOT = 280,
    ATMOST = 281,
    MORE = 282,
    ATLEAST = 283,
    LESS = 284,
    PLUS = 285,
    MINUS = 286,
    TIMES = 287,
    DIVIDE = 288,
    EQUALS = 289,
    NEG = 290,
    INT_LIT = 291,
    FLOAT = 292,
    STRING_LIT = 293,
    Ident = 294,
    QUACKTRUE = 295,
    QUACKFALSE = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "scanner.y" /* yacc.c:355  */

	int ival;
	float fval;
	char* sval;
	char* identval;
	char* qtrue;
	char* qflase;
	//struct expr_val* expval;
    program* prog;
    //std::shared_ptr<program> pro;
	//std::vector<program> v;
	basic_classes* b_classes;
	basic_class* b_class;
	class_sig* class_sign;
	extend* ex;
	statements* ss;
	methods* ms;
	class_body* cb;
	statement* stmt;
	method* mtd;
	r_expr* r_exp;
	make_ident* mk_ident;
	formal_args* f_args;
	formal_args_first* f_args_f;
	formal_args_idents* f_args_is;
	formal_args_ident* f_args_i;
	elifs*          ElIfs;
	elif*        ElIf;
	actual_args* a_args;
	r_exprs* r_exps;


#line 207 "scanner.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SCANNER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 224 "scanner.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   307

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

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
static const yytype_uint8 yyrline[] =
{
       0,   115,   115,   118,   118,   121,   124,   125,   130,   130,
     133,   137,   137,   142,   146,   150,   157,   157,   161,   165,
     166,   167,   168,   169,   170,   171,   172,   176,   176,   181,
     186,   186,   193,   197,   210,   211,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   239,   239,   243,
     243
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EXTENDS", "CLASS", "WHILE", "IF",
  "ELSE", "ELIF", "RETURN", "DEF", "ENDL", "COLON", "SEMICOLON", "LP",
  "RP", "LB", "RB", "DOT", "COMMA", "GETS", "MISS", "ILLEGAL", "AND", "OR",
  "NOT", "ATMOST", "MORE", "ATLEAST", "LESS", "PLUS", "MINUS", "TIMES",
  "DIVIDE", "EQUALS", "NEG", "INT_LIT", "FLOAT", "STRING_LIT", "Ident",
  "QUACKTRUE", "QUACKFALSE", "$accept", "Program", "Classes", "Class",
  "Class_Signature", "Formal_Args", "Formal_Args_First",
  "Formal_Args_Idents", "Formal_Args_Ident", "Extends_Ident", "Class_Body",
  "Statements", "Statement_Block", "Statement", "Elifs", "Elif", "Methods",
  "Method", "L_Expr", "R_Expr", "Actual_Args", "R_Exprs", YY_NULLPTR
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
     295,   296
};
# endif

#define YYPACT_NINF -24

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-24)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,    14,    15,   -24,   -21,   -24,     4,    84,     7,   -24,
     -24,   115,   115,   103,   115,   115,   115,   -24,   -24,     8,
     -24,   -24,   -24,    -4,   134,   -16,    84,   -24,   239,   239,
     -24,   156,   220,    74,    29,   115,   -14,   115,   -24,    11,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,    36,    37,   -24,     0,   -24,   -24,   -24,   -24,   -24,
     256,    43,    31,   178,    41,    74,    74,   273,   273,   273,
     273,     9,     9,    22,    22,    26,    20,    58,    44,    23,
     -24,   -24,    40,     5,    45,   -24,   115,   -24,   115,   -24,
      27,   -24,    28,   -24,    54,   -24,    53,   115,   -24,   115,
     200,    55,   -24,    60,   -16,   -24,   239,   256,   -24,   -24,
      35,    67,   -24,   -24,    -1,    46,   -24,    53,   -24
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,    16,     1,     0,     4,     0,     2,     0,    16,
       5,     0,     0,     0,     0,     0,     0,    37,    36,    34,
      38,    39,    17,    40,     0,     8,    30,    40,     0,     0,
      26,     0,     0,    54,    45,    57,     0,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,    16,    21,    27,    25,    46,
      59,     0,     0,     0,    35,    52,    53,    48,    51,    50,
      49,    41,    42,    43,    44,    47,     0,     7,     9,     0,
      15,    31,     0,    20,    58,    56,     0,    23,    57,    10,
       0,     6,     0,    12,     0,    18,     0,     0,    28,     0,
       0,     0,    14,     0,     8,    19,     0,    60,    22,    55,
       0,     0,    29,    13,     0,     0,    33,     0,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -24,   -24,   -24,   -24,   -24,   -17,   -24,   -24,   -24,   -24,
     -24,    -2,   -23,   -24,   -24,   -24,   -24,   -24,     2,   -11,
      24,   -24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     5,     6,    52,    53,    78,    93,    91,
      10,     7,    56,    22,    83,    98,    54,    81,    27,    24,
      61,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      28,    29,    31,    32,    33,    34,    57,    26,    36,    23,
      79,   115,    96,    97,     3,    55,    37,    80,     8,     4,
       9,    25,    35,    51,    60,    62,    63,    39,    23,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      39,    48,    49,    50,    39,    11,    12,    39,    76,    13,
      64,    86,    77,    82,    14,    88,    50,    95,    85,    89,
      -1,    90,    94,    92,    99,    15,   102,   103,   104,    55,
     109,    16,   110,   105,   113,   100,    17,    60,    18,    19,
      20,    21,   114,   112,    23,   117,   106,   111,   107,    11,
      12,   116,    39,    13,   118,     0,     0,     0,    14,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    15,
       0,     0,   101,     0,     0,    16,    30,    14,     0,     0,
      17,     0,    18,    19,    20,    21,     0,     0,    15,    14,
       0,     0,     0,     0,    16,     0,     0,     0,     0,    17,
      15,    18,    19,    20,    21,     0,    16,    38,     0,     0,
       0,    17,    39,    18,    19,    20,    21,    40,    41,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    58,
       0,     0,     0,     0,    39,     0,     0,     0,     0,    40,
      41,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    87,     0,     0,     0,     0,    39,     0,     0,     0,
       0,    40,    41,     0,    42,    43,    44,    45,    46,    47,
      48,    49,    50,   108,     0,     0,     0,     0,    39,     0,
       0,     0,     0,    40,    41,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    59,     0,     0,    39,     0,
       0,     0,     0,    40,    41,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    55,     0,    39,     0,     0,
       0,     0,    40,    41,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    39,     0,     0,     0,     0,    40,
      41,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    39,     0,     0,     0,     0,     0,     0,     0,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50
};

static const yytype_int8 yycheck[] =
{
      11,    12,    13,    14,    15,    16,    29,     9,    12,     7,
      10,    12,     7,     8,     0,    16,    20,    17,    39,     4,
      16,    14,    14,    39,    35,    39,    37,    18,    26,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      18,    32,    33,    34,    18,     5,     6,    18,    12,     9,
      39,    20,    15,    55,    14,    14,    34,    17,    15,    39,
      34,     3,    39,    19,    19,    25,    39,    39,    14,    16,
      15,    31,    12,    96,    39,    86,    36,    88,    38,    39,
      40,    41,    15,   106,    82,    39,    97,   104,    99,     5,
       6,   114,    18,     9,   117,    -1,    -1,    -1,    14,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    25,
      -1,    -1,    88,    -1,    -1,    31,    13,    14,    -1,    -1,
      36,    -1,    38,    39,    40,    41,    -1,    -1,    25,    14,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    36,
      25,    38,    39,    40,    41,    -1,    31,    13,    -1,    -1,
      -1,    36,    18,    38,    39,    40,    41,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    13,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    13,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    13,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    15,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    16,    -1,    18,    -1,    -1,
      -1,    -1,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    18,    -1,    -1,    -1,    -1,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,    44,     0,     4,    45,    46,    53,    39,    16,
      52,     5,     6,     9,    14,    25,    31,    36,    38,    39,
      40,    41,    55,    60,    61,    14,    53,    60,    61,    61,
      13,    61,    61,    61,    61,    14,    12,    20,    13,    18,
      23,    24,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    39,    47,    48,    58,    16,    54,    54,    13,    15,
      61,    62,    39,    61,    39,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    12,    15,    49,    10,
      17,    59,    53,    56,    63,    15,    20,    13,    14,    39,
       3,    51,    19,    50,    39,    17,     7,     8,    57,    19,
      61,    62,    39,    39,    14,    54,    61,    61,    13,    15,
      12,    47,    54,    39,    15,    12,    54,    39,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    46,    46,    47,    47,
      48,    49,    49,    50,    51,    52,    53,    53,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    63,
      63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     6,     5,     0,     2,
       3,     0,     2,     4,     2,     4,     0,     2,     3,     6,
       4,     3,     6,     4,     2,     3,     2,     0,     2,     3,
       0,     2,     8,     6,     1,     3,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     6,     4,     0,     2,     0,
       3
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
#line 115 "scanner.y" /* yacc.c:1646  */
    {(yyval.prog) = new program((yyvsp[-1].b_classes),(yyvsp[0].ss));root = (yyval.prog);}
#line 1420 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 118 "scanner.y" /* yacc.c:1646  */
    {(yyval.b_classes) = new basic_classes();}
#line 1426 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 118 "scanner.y" /* yacc.c:1646  */
    {(yyval.b_classes) = new basic_classes((yyvsp[-1].b_classes),(yyvsp[0].b_class));}
#line 1432 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 121 "scanner.y" /* yacc.c:1646  */
    {(yyval.b_class) = new basic_class((yyvsp[-1].class_sign),(yyvsp[0].cb));}
#line 1438 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 124 "scanner.y" /* yacc.c:1646  */
    {(yyval.class_sign) = new class_sig((yyvsp[-4].identval),(yyvsp[-2].f_args),(yyvsp[0].ex));}
#line 1444 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 125 "scanner.y" /* yacc.c:1646  */
    {(yyval.class_sign) = new class_sig((yyvsp[-3].identval),(yyvsp[-1].f_args));}
#line 1450 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 130 "scanner.y" /* yacc.c:1646  */
    {(yyval.f_args) = new formal_args();}
#line 1456 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 130 "scanner.y" /* yacc.c:1646  */
    {(yyval.f_args) = new formal_args((yyvsp[-1].f_args_f),(yyvsp[0].f_args_is));}
#line 1462 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 133 "scanner.y" /* yacc.c:1646  */
    {(yyval.f_args_f) = new formal_args_first((yyvsp[-2].identval),(yyvsp[0].identval));}
#line 1468 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 137 "scanner.y" /* yacc.c:1646  */
    {(yyval.f_args_is) = new formal_args_idents();}
#line 1474 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 137 "scanner.y" /* yacc.c:1646  */
    {(yyval.f_args_is) = new formal_args_idents((yyvsp[-1].f_args_is),(yyvsp[0].f_args_i));}
#line 1480 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 142 "scanner.y" /* yacc.c:1646  */
    {(yyval.f_args_i) = new formal_args_ident((yyvsp[-2].identval),(yyvsp[0].identval));}
#line 1486 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 146 "scanner.y" /* yacc.c:1646  */
    {(yyval.ex) = new extend((yyvsp[0].identval));}
#line 1492 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 150 "scanner.y" /* yacc.c:1646  */
    {(yyval.cb) = new class_body((yyvsp[-2].ss),(yyvsp[-1].ms));}
#line 1498 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 157 "scanner.y" /* yacc.c:1646  */
    {(yyval.ss) = new statements();}
#line 1504 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 157 "scanner.y" /* yacc.c:1646  */
    {(yyval.ss) = new statements((yyvsp[-1].ss),(yyvsp[0].stmt));}
#line 1510 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 161 "scanner.y" /* yacc.c:1646  */
    {(yyval.ss) = (yyvsp[-1].ss);}
#line 1516 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 165 "scanner.y" /* yacc.c:1646  */
    {(yyval.stmt) = new ifstmt((yyvsp[-4].r_exp),(yyvsp[-3].ss),(yyvsp[-2].ElIfs), (yyvsp[0].ss));}
#line 1522 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 166 "scanner.y" /* yacc.c:1646  */
    {(yyval.stmt) = new ifstmt((yyvsp[-2].r_exp),(yyvsp[-1].ss),(yyvsp[0].ElIfs));}
#line 1528 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 167 "scanner.y" /* yacc.c:1646  */
    {(yyval.stmt) = new whilestmt((yyvsp[-1].r_exp),(yyvsp[0].ss));}
#line 1534 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 168 "scanner.y" /* yacc.c:1646  */
    {(yyval.stmt) = new expstmt((yyvsp[-5].r_exp),(yyvsp[-3].identval),(yyvsp[-1].r_exp));}
#line 1540 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 169 "scanner.y" /* yacc.c:1646  */
    {(yyval.stmt) = new expstmt((yyvsp[-3].r_exp),(yyvsp[-1].r_exp));}
#line 1546 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 170 "scanner.y" /* yacc.c:1646  */
    {(yyval.stmt) = new expstmt((yyvsp[-1].r_exp));}
#line 1552 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 171 "scanner.y" /* yacc.c:1646  */
    {(yyval.stmt) = new returnstmt((yyvsp[-1].r_exp));}
#line 1558 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 172 "scanner.y" /* yacc.c:1646  */
    {(yyval.stmt) = new returnstmt();}
#line 1564 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 176 "scanner.y" /* yacc.c:1646  */
    {(yyval.ElIfs) = new elifs();}
#line 1570 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 176 "scanner.y" /* yacc.c:1646  */
    {(yyval.ElIfs) = new elifs((yyvsp[-1].ElIfs),(yyvsp[0].ElIf));}
#line 1576 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 181 "scanner.y" /* yacc.c:1646  */
    {(yyval.ElIf) = new elif((yyvsp[-1].r_exp),(yyvsp[0].ss));}
#line 1582 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 186 "scanner.y" /* yacc.c:1646  */
    {(yyval.ms) = new methods();}
#line 1588 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 186 "scanner.y" /* yacc.c:1646  */
    {(yyval.ms) = new methods((yyvsp[-1].ms),(yyvsp[0].mtd));}
#line 1594 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 194 "scanner.y" /* yacc.c:1646  */
    {(yyval.mtd) = new method((yyvsp[-6].identval),(yyvsp[-4].f_args),(yyvsp[-1].identval),(yyvsp[0].ss));}
#line 1600 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 199 "scanner.y" /* yacc.c:1646  */
    {(yyval.mtd) = new method((yyvsp[-4].identval),(yyvsp[-2].f_args),(yyvsp[0].ss));}
#line 1606 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 210 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new make_ident((yyvsp[0].identval));}
#line 1612 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 211 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new make_ident((yyvsp[-2].r_exp),(yyvsp[0].identval));}
#line 1618 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 215 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp)  = new make_str((yyvsp[0].sval));}
#line 1624 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 216 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new make_int((yyvsp[0].ival));}
#line 1630 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 217 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp)  = new make_boolean((yyvsp[0].qtrue));}
#line 1636 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 218 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp)  = new make_boolean((yyvsp[0].qflase));}
#line 1642 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 219 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = (yyvsp[0].r_exp);}
#line 1648 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 220 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new bin_operator((yyvsp[-2].r_exp),"PLUS",(yyvsp[0].r_exp));}
#line 1654 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 221 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new bin_operator((yyvsp[-2].r_exp),"MINUS",(yyvsp[0].r_exp));}
#line 1660 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 222 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new bin_operator((yyvsp[-2].r_exp),"TIMES",(yyvsp[0].r_exp));}
#line 1666 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 223 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new bin_operator((yyvsp[-2].r_exp),"DIVIDE",(yyvsp[0].r_exp));}
#line 1672 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 224 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new negative_operator((yyvsp[0].r_exp));}
#line 1678 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 225 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = (yyvsp[-1].r_exp);}
#line 1684 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 226 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new bin_operator((yyvsp[-2].r_exp),"EQUALS",(yyvsp[0].r_exp));}
#line 1690 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 227 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new bin_operator((yyvsp[-2].r_exp),"ATMOST",(yyvsp[0].r_exp));}
#line 1696 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 228 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new bin_operator((yyvsp[-2].r_exp),"LESS",(yyvsp[0].r_exp));}
#line 1702 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 229 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new bin_operator((yyvsp[-2].r_exp),"ATLEAST",(yyvsp[0].r_exp));}
#line 1708 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 230 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new bin_operator((yyvsp[-2].r_exp),"MORE",(yyvsp[0].r_exp));}
#line 1714 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 231 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new bin_operator((yyvsp[-2].r_exp),"AND",(yyvsp[0].r_exp));}
#line 1720 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 232 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new bin_operator((yyvsp[-2].r_exp),"OR",(yyvsp[0].r_exp));}
#line 1726 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 233 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new not_operator((yyvsp[0].r_exp));}
#line 1732 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 234 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp) = new function_call((yyvsp[-5].r_exp),(yyvsp[-3].identval),(yyvsp[-1].a_args));}
#line 1738 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 235 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exp)  = new function_call((yyvsp[-3].identval),(yyvsp[-1].a_args));}
#line 1744 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 239 "scanner.y" /* yacc.c:1646  */
    {(yyval.a_args) = new actual_args();}
#line 1750 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 239 "scanner.y" /* yacc.c:1646  */
    {(yyval.a_args) = new actual_args((yyvsp[-1].r_exp),(yyvsp[0].r_exps));}
#line 1756 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 243 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exps) = new r_exprs();}
#line 1762 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 243 "scanner.y" /* yacc.c:1646  */
    {(yyval.r_exps) = new r_exprs((yyvsp[-2].r_exps),(yyvsp[0].r_exp));}
#line 1768 "scanner.tab.c" /* yacc.c:1646  */
    break;


#line 1772 "scanner.tab.c" /* yacc.c:1646  */
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
#line 256 "scanner.y" /* yacc.c:1906  */




extern unordered_map<string,basic_class*> classtable;
unordered_map<string,string> classparenttable;
extern basic_class* Obj;
extern basic_class* quack_int;
extern basic_class* quack_str;
extern basic_class* quack_boolean;
extern basic_class* quack_nothing;

void init()
{
	
	initbuildinclass();
	classparenttable.insert({"Int","Obj"});
	classparenttable.insert({"Boolean","Obj"});
	classparenttable.insert({"String","Obj"});
	classparenttable.insert({"NOTHING","Obj"});
	classtable["Obj"] = Obj;
	classtable["Int"] = quack_int;
	classtable["String"] = quack_str;
	classtable["Boolean"] = quack_boolean;
	classtable["NOTHING"] = quack_nothing;

}


bool issubtype(string s1,string s2)
{
	if(s2 == "Obj")
	{
		return true;
	}
	else
	{
		while(s1 != "Obj")
		{
			if (s1 != s2)
			{
				s1 = classparenttable[s1];
			}
			else
			{
				return true;
			}
		}
		return false;
	}
}


bool validpara(vector<r_expr*> p1,vector<Para> p2) //p1 is the overwrite , and p2 is the origin
{
	if(p1.size()!= p2.size())
	{
		return false;
	}
	else
	{
		for(int i = 0;i<p1.size(); ++i)
		{
			if(!issubtype(p1[i]->m_type,p2[i].type))
			{
				return false;
			}
		}
		return true;
	}

}



string LCA(string s1,string s2)
{
	if(s1 == s2)
	{
		return s1;
	}
	else if(s1 == "Bottom")
	{
		return s2;
	}
	else if(s2 == "Bottom")
	{
		return s1;
	}
	else
	{
		auto temp1 = s1;
		auto temp2 = s2;
		while(temp1 != "Obj")
		{
			while(temp2 != "Obj")
			{
				if(temp2 == temp1)
				{
					return temp1;
				}
				temp2 = classparenttable[temp2];
			}
			temp2 = s2;
			temp1 = classparenttable[temp1];
		}
		return "Obj";
	}


}

string LCA(vector<string> v)
{
	auto temp = string("Bottom");
	for(auto e:v)
	{
		if (e == "no return ")
		{
			return e;
		}
		else
		{
			temp = LCA(temp,e);
		}
	}
}

void getinitializedidentformethod(r_expr* e,statement* s,method* m,basic_class* c)
{

	if(e->tag == string("IDENT"))
	{
	
		if(e->identname == "this")
		{
			e->m_type = c->name();
		}
		else if(m->m_variables.find(e->identname) == m->m_variables.end())
		{
			cerr<<"uninitialized ident "<< e->identname<< " in method :"<< m->name()<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = "Bottom";
		}
		// }
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		//getinitializedidentformethod(e->identparent,s,m,c);
		//
		//cout<<e->identparent->identname<<endl;
		// if(e->identparent->m_type != c->name())
		// {
		// 	cerr<< "not allowed to use other class's variable "<< e->identname<<" "<<e->identparent->m_type<<" "<<e->identparent->identname<<m->name()<<endl;
		// 	exit(-1);
		// }
		// else
		// {

			if(e->identparent->identname != "this" || c->m_variables.find(e->identname) == c->m_variables.end())
			{
				cout<<e->identname<<endl;
				cerr<< "unknown variable"<<endl;
				exit(-1);
			}
			else
			{
				e->m_type = "Bottom";
			}
		//}
	}
	else if(e->tag == string("bin_oper"))
	{
		getinitializedidentformethod(e->b.l,s,m,c);
		getinitializedidentformethod(e->b.r,s,m,c);
	}
	else if(e->tag == string("single_oper"))
	{
		getinitializedidentformethod(e->s.e,s,m,c);
	}
	else if(e->tag == string("function_call"))
	{
		getinitializedidentformethod(e->f.e,s,m,c);
		for(auto i:e->f.p->m_value)
		{
			getinitializedidentformethod(i,s,m,c);
		}
		// auto temp = e->f.e->m_type;
		// if(classtable.find(e->f.e->m_type) == classtable.end())
		// {
		// 	cerr<< e->f.e->m_type<<" is unknown class "<<c->name()<<" "<<m->name()<<endl;
		// 	exit(-1);
		// }
		// else if(classtable[temp]->methodtable.find(e->f.s) == classtable[temp]->methodtable.end())
		// {
		// 	cerr<<"unknown function "<<endl;
		// 	exit(-1);
		// }
		// else
		// {
		// 	for(auto j: e->f.p->m_value)
		// 	{
		// 		getinitializedidentformethod(j,s,m,c);
		// 	}
		// }
		// else if(e->f.e->tag == "IDENT" && e->f.e->identname == "this")
		// {
		// 	if(c.methodtable)
		// }

	}
	else if(e->tag == string("class_call"))
	{
		bool flag = 0;
		if( classtable.find(e->c.s) == classtable.end() && c->methodtable.find(e->c.s) == c->methodtable.end())
		{
			cerr<<"uninitialized class or function"<<endl;
			exit(-1);
		}
		else
		{
			// if(!validpara(e->c.p->m_value,classtable[e->c.s]->para()))
			// {
			// 	cerr<<"wrong parameters"<<endl;
			// 	exit(-1);
			// }
			// else
			// {
				for(auto j: e->c.p->m_value)
				{
					getinitializedidentformethod(j,s,m,c);
				}
			// }
		}

	}
}





void getinitializedidentforclass(r_expr* e,statement* s,basic_class* c)
{
	if(e->tag == string("IDENT"))
	{	
		if(e->identname == "this")
		{
			cerr<< "not allowd to use this individually"<<endl;
			exit(-1);
		}
		else if(c->m_variables.find(e->identname) == c->m_variables.end() &&
			c->m_variables_temp.find(e->identname) == c->m_variables_temp.end())
		{
			cerr<<"uninitialized ident "<<" "<<e->identname<< " in class :"<< c->name()<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = "Bottom";
		}
		// }
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		if (e->identparent->identname != "this")
		{
			//cerr<<e->identparent->identname<<endl;
			cerr<<"cannot use that"<<endl;
			exit(-1);
		}
		else if(c->m_variables.find(e->identname) == c->m_variables.end() &&
			c->m_variables_temp.find(e->identname) == c->m_variables_temp.end())
		{
			cerr<<"uninitialized ident "<<e->identparent->identname<<" "<< e->identname<< " in class :"<< c->name()<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = "Bottom";
		}
	}
	else if(e->tag == string("bin_oper"))
	{
		getinitializedidentforclass(e->b.l,s,c);
		getinitializedidentforclass(e->b.r,s,c);
	}
	else if(e->tag == string("single_oper"))
	{
		getinitializedidentforclass(e->s.e,s,c);
	}
	else if(e->tag == string("function_call"))
	{
		//check if there is function
		//s->m_variable[e->f.s] = "Bottom";
		//getinitializedidentformethod(e,s,m);
		// if(classtable.find(e->f.e->m_type) == classtable.end() )
		// {
		// 	cerr<<e->f.e->m_type<<e->f.s<<endl;
		// 	cerr<<e->f.e->identname<<endl;
		// 	cerr<<"Invalid class call"<<endl;
		// 	exit(-1);
		// }
		// else if(classtable[e->f.e->m_type]->methodtable.find(e->f.s) == classtable[e->f.e->m_type]->methodtable.end())
		// {
		// 	cerr<<"Invalid function call"<<endl;
		// }
		// else
		// {

		/*


		i ll do this in typebuilding

		*/



		getinitializedidentforclass(e->f.e,s,c);
		for(auto j: e->f.p->m_value)
		{
			getinitializedidentforclass(j,s,c);
		}
		// }
	}
	else if(e->tag == string("class_call"))
	{
		if(c->methodtable.find(e->c.s) == c->methodtable.end() && classtable.find(e->c.s) == classtable.end())
		{
			cerr<< "undefined function or class"<<endl;
			exit(-1);
		}
		else
		{
			for(auto j: e->c.p->m_value)
			{
				getinitializedidentforclass(j,s,c);
			}
		}
	}
}








void getinitializedidentforstmt(r_expr* e,statement* s,program* p)
{
	//cout<<e->tag<<" "<<m->name()<<endl;
	if(e->tag == string("IDENT"))
	{
	
		if(p->m_variables.find(e->identname) == p->m_variables.end())
		{
			cerr<<"uninitialized ident "<< e->identname<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = p->m_variables[e->identname];
		}
		// }
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		//getinitializedidentformethod(e->identparent,s,m,c);
		//
		//cout<<e->identparent->identname<<endl;
		// if(e->identparent->m_type != c->name())
		// {
			cerr<< "not allowed to use other class's variable "<< e->identname<<" "<<e->identparent->identname<<endl;
			exit(-1);
		// }
		// else
		// {
		// 	if(c->m_variables.find(e->identname) == c->m_variables.end())
		// 	{
		// 		cerr<< "unknown variable"<<endl;
		// 		exit(-1);
		// 	}
		// }
	}
	else if(e->tag == string("bin_oper"))
	{
		getinitializedidentforstmt(e->b.l,s,p);
		getinitializedidentforstmt(e->b.r,s,p);
	}
	else if(e->tag == string("single_oper"))
	{
		getinitializedidentforstmt(e->s.e,s,p);
	}
	else if(e->tag == string("function_call"))
	{
		getinitializedidentforstmt(e->f.e,s,p);
		// the function part should be done in type check part




		// if(p->m_variables.find(e->f.e->name() == p -> m_variables.end())
		// {
		// 	cerr<< "not found "<<endl;
		// 	exit(-1);
		// }
		// else if(classtable[p->m_variables[e->f.e->name()]]->m_variables.find(e->f.s) == classtable[p->m_variables[e->f.e->name()]]->m_variables.end())
		// {
		// 	cerr<< "not found"<<endl;
		// 	exit(-1);
		// }
		// else
		// {
		// 	getinitializedidentforstmt(e->f.p,s,p);
		// }
	}
	else if(e->tag == string("class_call"))
	{
		bool flag = 0;
		if( classtable.find(e->c.s) == classtable.end())
		{
			cerr<<"uninitialized class"<<endl;
			exit(-1);
		}
		else
		{
			// if(!validpara(e->c.p->m_value,classtable[e->c.s]->para()))
			// {
			// 	cerr<<"wrong parameters"<<endl;
			// 	exit(-1);
			// }
			// else
			// {
				for(auto j: e->c.p->m_value)
				{
					getinitializedidentforstmt(j,s,p);
				}
			// }
		}

	}
}























void buildvariableformethodinstmt(statement* s,statement* s2,method* m,basic_class* c)
{
	if(s->tag == string("IFELSE"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentformethod(i.condition,s,m,c);
			for(auto j: i.execution->value())
			{
				buildvariableformethodinstmt(j,s2,m,c);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		for(auto j: s->elsestatements->value())
		{
			buildvariableformethodinstmt(j,s2,m,c);
		}
		unordered_map<string,string> temp1;
		for(auto j: s->elsestatements->value())
		{
			temp1.insert(j->m_variables.begin(),j->m_variables.end());
		}
		temp.push_back(temp1);
		if(temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}

	}
	else if(s->tag == string("IF"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentformethod(i.condition,s,m,c);
			for(auto j: i.execution->value())
			{
				buildvariableformethodinstmt(j,s2,m,c);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		if(temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}
		
	}
	else if(s->tag == string("WHILE"))
	{
		for(auto i: s->whilestatement.execution->value())
		{
			buildvariableformethodinstmt(i,s2,m,c);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		getinitializedidentformethod(s->exp,s,m,c);
	}
	else if (s->tag == string("GETVALUE"))
	{
		getinitializedidentformethod(s->g_value.right,s,m,c);
		if(s->g_value.left->tag == string("IDENT"))
		{
			s->m_variables[s->g_value.left->identname] = string("Bottom");
			s->g_value.left->m_type = "Bottom";
		}
		else if(s->g_value.left->tag == string("IDENTINMEMBER"))
		{
			s->m_variables_class[s->g_value.left->identname] = string("Bottom");
			s->g_value.left->m_type = "Bottom";
		}

		
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{

	}			
	else
	{

	}
	
	//m->m_variables.insert(s->m_variables.begin(),s->m_variables.end());
}


void buildvariableformethod(statement* s,method* m,basic_class* c)
{
	//cout<<s->tag<<endl;
	if(s->tag == string("IFELSE"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			unordered_map<string,string> tempc;
			getinitializedidentformethod(i.condition,s,m,c);
			for(auto j: i.execution->value())
			{
				buildvariableformethodinstmt(j,s,m,c);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
				tempc.insert(j->m_variables_class.begin(),j->m_variables_class.end());
			}
			temp.push_back(temp1);
		}
		for(auto j: s->elsestatements->value())
		{
			buildvariableformethodinstmt(j,s,m,c);
		}
		unordered_map<string,string> temp1;
		for(auto j: s->elsestatements->value())
		{
			temp1.insert(j->m_variables.begin(),j->m_variables.end());
		}
		temp.push_back(temp1);

		if(temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f.clear();
				f.insert(tempm.begin(),tempm.end());
				
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}

	}
	else if(s->tag == string("IF"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			//unordered_map<string,string> temp1;
			getinitializedidentformethod(i.condition,s,m,c);
			for(auto j: i.execution->value())
			{
				buildvariableformethodinstmt(j,s,m,c);
			}
		// 	for(auto j: i.execution->value())
		// 	{
		// 		temp1.insert(j->m_variables.begin(),j->m_variables.end());
		// 	}
		// 	temp.push_back(temp1);
		// }
		// if(temp.size())
		// {
		// 	auto f = temp[0];
		// 	unordered_map<string,string> tempm;
		// 	for(auto j:temp)
		// 	{
		// 		for(auto v: f)
		// 		{
		// 			if(j.find(v.first)!= j.end())
		// 			{
		// 				tempm[v.first] = string("Bottom");
		// 			}
		// 		}
		// 		f = tempm;
		// 		tempm.clear();
		// 	}
		// 	s->m_variables.insert(f.begin(),f.end());
		}
		
	}
	else if(s->tag == string("WHILE"))
	{
		for(auto i: s->whilestatement.execution->value())
		{
			buildvariableformethodinstmt(i,s,m,c);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		getinitializedidentformethod(s->exp,s,m,c);
	}
	else if (s->tag == string("GETVALUE"))
	{
		
		if(s->g_value.left->tag == string("IDENT"))
		{
			
			s->m_variables[s->g_value.left->identname] = string("Bottom");
			s->g_value.left->m_type = "Bottom";			
		}
		else if(s->g_value.left->tag == "IDENTINMEMBER" && s->g_value.left->identparent->identname == "this")
		{
			c->m_variables[s->g_value.left->identname] = string("Bottom");
			s->g_value.left->m_type = "Bottom";
		}
		getinitializedidentformethod(s->g_value.right,s,m,c);
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{
		//if(s->g_value_m.left->tag == )
	}			
	else
	{

	}
	if(s->tag != "IF" && s->tag != "WHILE")
	{
		m->m_variables.insert(s->m_variables.begin(),s->m_variables.end());
	}
}



void buildvariableforstmtinstmt(statement* s,statement* s2,program* p)
{
	if(s->tag == string("IFELSE"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforstmt(i.condition,s,p);
			for(auto j: i.execution->value())
			{
				buildvariableforstmtinstmt(j,s2,p);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		for(auto j: s->elsestatements->value())
		{
			buildvariableforstmtinstmt(j,s2,p);
		}
		unordered_map<string,string> temp1;
		for(auto j: s->elsestatements->value())
		{
			temp1.insert(j->m_variables.begin(),j->m_variables.end());
		}
		temp.push_back(temp1);
		if(temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}

	}
	else if(s->tag == string("IF"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforstmt(i.condition,s,p);
			for(auto j: i.execution->value())
			{
				buildvariableforstmtinstmt(j,s2,p);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		if(temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}
		
	}
	else if(s->tag == string("WHILE"))
	{
		for(auto i: s->whilestatement.execution->value())
		{
			buildvariableforstmtinstmt(i,s2,p);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		getinitializedidentforstmt(s->exp,s,p);
	}
	else if (s->tag == string("GETVALUE"))
	{
		
		if(s->g_value.left->tag == string("IDENT"))
		{
			s->m_variables[s->g_value.left->identname] = string("Bottom");
		}

		getinitializedidentforstmt(s->g_value.right,s,p);
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{

	}			
	else
	{

	}
	
	//m->m_variables.insert(s->m_variables.begin(),s->m_variables.end());
}
















void buildvariableforstmt(statement* s,program* p)
{
	//cout<<s->tag<<endl;
	if(s->tag == string("IFELSE"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforstmt(i.condition,s,p);
			for(auto j: i.execution->value())
			{
				buildvariableforstmtinstmt(j,s,p);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		for(auto j: s->elsestatements->value())
		{
			buildvariableforstmtinstmt(j,s,p);
		}
		unordered_map<string,string> temp1;
		for(auto j: s->elsestatements->value())
		{
			temp1.insert(j->m_variables.begin(),j->m_variables.end());
		}
		temp.push_back(temp1);
		if(temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f.clear();
				f.insert(tempm.begin(),tempm.end());
				
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());

		}

	}
	else if(s->tag == string("IF"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforstmt(i.condition,s,p);
			for(auto j: i.execution->value())
			{
				buildvariableforstmtinstmt(j,s,p);
			}
			for(auto j: i.execution->value())
		 	{
		 		temp1.insert(j->m_variables.begin(),j->m_variables.end());
		 	}
		 	temp.push_back(temp1);
		 }
		 if(temp.size())
		 {
		 	auto f = temp[0];
		 	unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}
		
	}
	else if(s->tag == string("WHILE"))
	{
		unordered_map<string,string> temp;
		for(auto i: s->whilestatement.execution->value())
		{
			buildvariableforstmtinstmt(i,s,p);
			temp.insert(i->m_variables.begin(),i->m_variables.end());
		}
		s->m_variables.insert(temp.begin(),temp.end());
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		getinitializedidentforstmt(s->exp,s,p);
	}
	else if (s->tag == string("GETVALUE"))
	{
		
		if(s->g_value.left->tag == string("IDENT"))
		{
			s->m_variables[s->g_value.left->identname] = string("Bottom");
		}

		getinitializedidentforstmt(s->g_value.right,s,p);
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{
		//if(s->g_value_m.left->tag == )
		cerr<<"not allowd to call private member"<<endl;
		exit(-1);
	}			
	else
	{

	}
	if(s->tag != "IF" && s->tag != "WHILE")
	{
		p->m_variables.insert(s->m_variables.begin(),s->m_variables.end());
	}
}


void class_inherit_issue()
{
	
	for(auto c: root->cs)
	{
		if(c->name() == "Obj" ||c->name() == "Int" ||c->name() == "String" ||c->name() == "NOTHING" ||c->name() == "Boolean")
		{
			cerr<<"Illegal definition"<<endl;
			exit(-1);
		}
		classparenttable[c->name()] = c->parent();
		//cout<<c.name()<<" "<<c.parent()<<endl;
	}
	for(auto c:root->cs)
	{
		auto temp = c->name();
		unordered_set<string> temptype;
		while(temp != string("Obj"))
		{
			temptype.insert(temp);
			temp = classparenttable[temp];
			if( classparenttable.find(temp) == classparenttable.end() && temp != "Obj")
			{
				cerr<<"illegal inherit from "<<temp<<endl;
				return;
			}
			if (temptype.find(temp) != temptype.end())
			{
				
				cerr<< "circle in class inherit:";
				auto mark = classparenttable[temp];
				cout<<temp<<"->";
				while (mark != temp)
				{
					cout<<mark<<"->";
					mark = classparenttable[mark];
				}
				cout<<mark<<endl;
				exit(-1);
				//return;
			}
			
			
		}
		if(c->parent() == "Obj")
		{
			c->reference  = Obj;
		}
		else if(c->parent() == "Int")
		{
			c->reference = quack_int;
		}
		else if(c->parent() == "String")
		{
			c->reference = quack_str;
		}
		else if(c->parent() == "Boolean")
		{
			c->reference = quack_boolean;
		}
		else if(c->parent() == "NOTHING")
		{
			c->reference = quack_nothing;
		}
		else
		{
			for(auto p:root->cs)
			{
				if(p->name() == c->parent())
				{
					c->reference = p;
				}
			}
		}
		classtable[c->name()] = c;

	}
	
}

unordered_set<string> inherited_class;
void buildclassinherit(basic_class* c)
{
	if(inherited_class.find(c->name()) == inherited_class.end())
	{
		if(c->name() == "Obj" ||c->name() == "Int" ||c->name() == "String" ||c->name() == "NOTHING" ||c->name() == "Boolean"  )
		{
			// for(auto m:c->m_methods)
			// {
			// 	c->methodtable[m->name()] = m;
			// }
			inherited_class.insert(c->name());
		}
		else
		{
			buildclassinherit(c->reference);
			for(auto m:c->m_methods)
			{
				if(c->reference->methodtable.find(m->name()) != c->reference->methodtable.end() )
				{
					//overwrite
					cout<< c->reference->methodtable[m->name()]->m_returntype<<" "<<m->m_returntype<<" "<<m->name()<<
					endl;
					if(issubtype( c->reference->methodtable[m->name()]->m_returntype,m->m_returntype) )
					{

						if(m->para().size() != c->reference->methodtable[m->name()]->para().size())
						{
							cerr<<"wront para"<<endl;
							exit(-1);
						}
						else
						{
							for(int i = 0; i < m->para().size();++i)
							{
								if(!issubtype(m->para()[i].type,c->reference->methodtable[m->name()]->para()[i].type))
								{
									cerr<<"wrong para"<<endl;
									exit(-1);
								}
							}
							c->methodtable[m->name()] = m;
							m->origin_class = c->name();
						}

					}
					else
					{
						cerr<< "not allowed to overwrite with wrong tyoe"<<endl;
						exit(-1);
					}
				}
				else if(c->methodtable.find(m->name()) == c->methodtable.end())
				{
					if(classtable.find(m->m_returntype) == classtable.end())
					{
						cerr<<"invalid return type of "<<m->name()<<" of type "<<m->m_returntype<<endl;
						exit(-1);
					}
					c->methodtable[m->name()] = m;
					c->methodtable[m->name()]->origin_class = c->name();
				}
				else
				{
					if(classtable.find(m->m_returntype) == classtable.end())
					{
						cerr<<"invalid return type of "<<m->name()<<endl<<m->m_returntype<<endl;
						exit(-1);
					}
					// overwrite to do;
					c->methodtable[m->name()]->origin_class = c->name();
				}
			}
			for(auto m_refer:c->reference->methodtable)
			{
				if(c->methodtable.find(m_refer.first) == c->methodtable.end())
				{
					c->methodtable[m_refer.first] = m_refer.second;
				}
			}
		}
		inherited_class.insert(c->name());
	}
	
}

void class_method_inherit()
{
	for(auto c:root->cs)
	{
		buildclassinherit(c);
	}

}







void buildvariableforclassinstmt(statement* s,statement* s2,basic_class* c)
{
	if(s->tag == string("IFELSE"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforclass(i.condition,s,c);
			for(auto j: i.execution->value())
			{
				buildvariableforclassinstmt(j,s2,c);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		for(auto j: s->elsestatements->value())
		{
			buildvariableforclassinstmt(j,s2,c);
		}
		unordered_map<string,string> temp1;
		for(auto j: s->elsestatements->value())
		{
			temp1.insert(j->m_variables.begin(),j->m_variables.end());
		}
		temp.push_back(temp1);
		if(!temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}

	}
	else if(s->tag == string("IF"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforclass(i.condition,s,c);
			for(auto j: i.execution->value())
			{
				buildvariableforclassinstmt(j,s2,c);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		if(!temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}
		
	}
	else if(s->tag == string("WHILE"))
	{
		for(auto i: s->whilestatement.execution->value())
		{
			buildvariableforclassinstmt(i,s2,c);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
 			cerr<<" not allowed return in class"<<endl;
		exit(-1);
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		getinitializedidentforclass(s->exp,s,c);
		cerr<<" not allowed return in class"<<endl;
		exit(-1);
	}
	else if (s->tag == string("GETVALUE"))
	{
		
		if(s->g_value.left->tag == string("IDENT"))
		{
			s->m_variables[s->g_value.left->identname] = string("Bottom");
		}

		getinitializedidentforclass(s->g_value.right,s,c);
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{

	}			
	else
	{

	}
	
	//m->m_variables.insert(s->m_variables.begin(),s->m_variables.end());
}

void addvariableforclass(r_expr* e, basic_class* c)
{
	if(e->tag == string("IDENT"))
	{	
		if(e->identname == "this")
		{
			cerr<<"not allowed in use this in class individually"<<endl;
			exit(-1);
		}
		else
		{
			c->m_variables_temp[e->identname] = "Bottom";
			e->m_type = "Bottom";
		}
		// }
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		//addvariableforclass(e->identparent,c);
		if(e->identparent->identname == "this")
		{
			c->m_variables[e->identname] = "Bottom";
			e->m_type = "Bottom";
		}
	}
}

void buildvariableforclass(statement* s,basic_class* c)
{
	if(s->tag == string("IFELSE"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforclass(i.condition,s,c);
			for(auto j: i.execution->value())
			{
				buildvariableforclassinstmt(j,s,c);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		for(auto j: s->elsestatements->value())
		{
			buildvariableforclassinstmt(j,s,c);
		}
		unordered_map<string,string> temp1;
		for(auto j: s->elsestatements->value())
		{
			temp1.insert(j->m_variables.begin(),j->m_variables.end());
		}
		temp.push_back(temp1);
		if(!temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}


	}
	else if(s->tag == string("IF"))
	{
		vector<unordered_map<string,string>> temp;
		for(auto i:s->branches)
		{
			unordered_map<string,string> temp1;
			getinitializedidentforclass(i.condition,s,c);
			for(auto j: i.execution->value())
			{
				buildvariableforclassinstmt(j,s,c);
			}
			for(auto j: i.execution->value())
			{
				temp1.insert(j->m_variables.begin(),j->m_variables.end());
			}
			temp.push_back(temp1);
		}
		if(!temp.size())
		{
			auto f = temp[0];
			unordered_map<string,string> tempm;
			for(auto j:temp)
			{
				for(auto v: f)
				{
					if(j.find(v.first)!= j.end())
					{
						tempm[v.first] = string("Bottom");
					}
				}
				f = tempm;
				tempm.clear();
			}
			s->m_variables.insert(f.begin(),f.end());
		}
		
	}
	else if(s->tag == string("WHILE"))
	{
		for(auto i: s->whilestatement.execution->value())
		{
			buildvariableforclassinstmt(i,s,c);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;	cerr<<" not allowed return in class"<<endl;
		exit(-1);
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		cerr<<" not allowed return in class"<<endl;
		exit(-1);
	}
	else if (s->tag == string("GETVALUE"))
	{
		getinitializedidentforclass(s->g_value.right,s,c);
		if(s->g_value.left->tag == string("IDENT"))
		{
			s->m_variables[s->g_value.left->identname] = string("Bottom");
		}
		else if(s->g_value.left->tag == string("IDENTINMEMBER") && s->g_value.left->identparent->identname == "this")
		{
			s->m_variables[s->g_value.left->identname] = string("Bottom");
		}
		
		
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{
		if(s->g_value.left->tag == string("IDENT"))
		{
			s->m_variables[s->g_value_m.left->identname] = string("Bottom");
		}
		getinitializedidentforclass(s->g_value_m.right,s,c);
		//getinitializedidentforclass(s->g_value_m.right,s,c);
	}			
	else
	{
		getinitializedidentforclass(s->exp,s,c);
	}
	if(s->tag != "IF" && s->tag != "WHILE")
	{		
		c->m_variables.insert(s->m_variables.begin(),s->m_variables.end());
	}
	
}


// getinitializedidentforpgm(r_expr* e,statement* s,program* r)
// {
// 	if(e->tag == string("IDENT"))
// 	{
	
// 		if(p->m_variables.find(e->identname) == p->m_variables.end())
// 		{
// 			cerr<<"uninitialized ident "<< e->identname<<endl;
// 			exit(-1);
// 		}
// 		else
// 		{
// 			e->m_type = p->m_variables[e->identname];
// 		}
// 	}
// 	else if (e->tag == string("IDENTINMEMBER"))
// 	{
// 		//getinitializedidentformethod(e->identparent,s,m,c);
// 		//
// 		//cout<<e->identparent->identname<<endl;
// 		// if(e->identparent->m_type != c->name())
// 		// {
// 			cerr<< "not allowed to use private variable "<< e->identname<<" "<<e->identparent->identname<<endl;
// 			exit(-1);
// 		// }
// 		// else
// 		// {
// 		// 	if(c->m_variables.find(e->identname) == c->m_variables.end())
// 		// 	{
// 		// 		cerr<< "unknown variable"<<endl;
// 		// 		exit(-1);
// 		// 	}
// 		// }
// 	}
// 	else if(e->tag == string("bin_oper"))
// 	{
// 		getinitializedidentforpgm(e->b.l,s,p);
// 		getinitializedidentforpgm(e->b.r,s,p);
// 	}
// 	else if(e->tag == string("single_oper"))
// 	{
// 		getinitializedidentforpgm(e->s.e,s,p);
// 	}
// 	else if(e->tag == string("function_call"))
// 	{
// 		// auto temp = e->f.e->m_type;
// 		// if(classtable.find(e->f.e->m_type) == classtable.end())
// 		// {
// 		// 	cerr<< e->f.e->m_type<<" is unknown class "<<c->name()<<" "<<m->name()<<endl;
// 		// 	exit(-1);
// 		// }
// 		// else if(classtable[temp]->methodtable.find(e->f.s) == classtable[temp]->methodtable.end())
// 		// {
// 		// 	cerr<<"unknown function "<<endl;
// 		// 	exit(-1);
// 		// }
// 		// else
// 		// {
// 		// 	for(auto j: e->f.p->m_value)
// 		// 	{
// 		// 		getinitializedidentformethod(j,s,m,c);
// 		// 	}
// 		// }
// 		// else if(e->f.e->tag == "IDENT" && e->f.e->identname == "this")
// 		// {
// 		// 	if(c.methodtable)
// 		// }

// 	}
// 	else if(e->tag == string("class_call"))
// 	{
// 		bool flag = 0;
// 		if( classtable.find(e->c.s) == classtable.end())
// 		{
// 			cerr<<"uninitialized class"<<endl;
// 			exit(-1);
// 		}
// 		else
// 		{
// 			// if(!validpara(e->c.p->m_value,classtable[e->c.s]->para()))
// 			// {
// 			// 	cerr<<"wrong parameters"<<endl;
// 			// 	exit(-1);
// 			// }
// 			// else
// 			// {
// 				for(auto j: e->c.p->m_value)
// 				{
// 					getinitializedidentforstmt(j,s,p);
// 				}
// 			// }
// 		}

// 	}
// }


























































void classsvariable(basic_class* c)
{
	//unordered_map<string,string> temp;
	for(auto i:c->m_para)
	{
		c->m_variables_temp[i.name] = i.type;
	}

}





string checkmethodreturntype(vector<statement*> s)
{
	string res = "no return";
	for(auto i:s)
	{
		if(i->tag == "IFELSE")
		{	
			
		}
		else if(i->tag == "IF")
		{
			
		}
		else if(i->tag == "WHILE")
		{

		}
		else if(i->tag == "RETURNNULL")
		{
			return string("NULL");
		}
		else if (i->tag == "RETURN")
		{
			return i->returntype;
		}
	}
	return res;
}


void methodstmt(method* m,basic_class* c)
{
	for(auto p : m->para())
	{
		m->m_variables[p.name] = p.type;
	}
	for(auto s : m->methodstatements)
	{
		buildvariableformethod(s,m,c);
	}
}



/*
build type for class

*/


void buildtypeforexprinclass(r_expr* e,basic_class* c)
{
	cout<<e->tag<<" "<<c->name()<<endl;
	if(e->tag == string("IDENT"))
	{
		if(e->identname != "this")
		{
			e->m_type = LCA(e->m_type,c->m_variables_temp[e->identname]);
			c->m_variables_temp[e->identname] = e->m_type;
		}
		else
		{
			cerr<<"not allowed to use this individually"<<endl;
			exit(-1);
		}
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		//e->m_type = c->m_variables[e->identname];
		if(e->identparent->identname  == "this")
		{
			e->m_type = LCA(e->m_type,c->m_variables[e->identname]);
			c->m_variables[e->identname] = e->m_type;
		}
		else
		{
			cerr<< "not allowed to use it"<<endl;
			exit(-1);
		}
	}
	else if(e->tag == string("bin_oper"))
	{
		buildtypeforexprinclass(e->b.l,c);
		buildtypeforexprinclass(e->b.r,c);
		auto oper = e->b.s;
		if(classtable[e->b.l->m_type]->methodtable.find(oper) == classtable[e->b.l->m_type]->methodtable.end())
		{
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			auto p = classtable[e->b.l->m_type]->methodtable[oper]->para()[0].type;
			if(!issubtype(e->b.r->m_type,p))
			{
				cerr<< "wrong type got"<<endl;
				exit(-1);
			}
			else
			{
				e->m_type = classtable[e->b.l->m_type]->methodtable[oper]->m_returntype;
			}
		}
	}
	else if(e->tag == string("single_oper"))
	{
		buildtypeforexprinclass(e->s.e,c);
		auto oper = e->s.s;
		if(classtable[e->s.e->m_type]->methodtable.find(oper) == classtable[e->s.e->m_type]->methodtable.end())
		{
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = classtable[e->s.e->m_type]->methodtable[oper]->m_returntype;
		}
	}
	else if(e->tag == string("function_call"))
	{
		//check if there is function
		//s->m_variable[e->f.s] = "Bottom";
		//getinitializedidentformethod(e,s,m);
		buildtypeforexprinclass(e->f.e,c);
		auto temp = e->f.e->m_type;
		cout<<temp<<endl;
		if(classtable[temp]->methodtable.find(e->f.s) == classtable[temp]->methodtable.end())
		{
			cerr<< temp<<endl;
			cerr<<"unknown function "<<e->f.s<<endl;
			exit(-1);
		}
		e->m_type = classtable[temp]->methodtable[e->f.s]->m_returntype;
		cout<<e->m_type<<" "<<e->f.e->identname<<" "<<c->name()<<endl;
	}
	else if(e->tag == string("class_call"))
	{
		if(classtable.find(e->c.s) != classtable.end())
		{
			e->m_type = classtable[e->c.s]->name();
			for(int i = 0;i<e->c.p->m_value.size();++i)
			{
				auto p = e->c.p->m_value[i];
				buildtypeforexprinclass(p,c);
				if(!issubtype(p->m_type,classtable[e->c.s]->para()[i].type))
				{
					cerr<<"wrong para type"<<endl;
					exit(-1);
				}
			}
		}
		else if(c->methodtable.find(e->c.s) != c->methodtable.end())
		{
			e->m_type = c->methodtable[e->c.s]->m_returntype;
			for(int i = 0;i<e->c.p->m_value.size();++i)
			{
				auto p = e->c.p->m_value[i];
				buildtypeforexprinclass(p,c);
				if(!issubtype(p->m_type,c->methodtable[e->f.s]->para()[i].type))
				{
					cerr<<"wrong para type"<<endl;
					exit(-1);
				}
			}
		}
		else
		{
			cerr<<"unknown function or class call"<<endl;
			exit(-1);
		}
	}
}





void buildtypeforstmtinclass(statement* s,basic_class* c)
{
	cout<<s->tag<<endl;
	if(s->tag == string("IFELSE"))         // there is no problem about the not initialed
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinclass(i.condition,c);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmtinclass(j,c);
			}
		}
		for(auto j: s->elsestatements->value())
		{
			buildtypeforstmtinclass(j,c);
		}

	

	}
	else if(s->tag == string("IF"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinclass(i.condition,c);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmtinclass(j,c);
			}		
		}
	}
	else if(s->tag == string("WHILE"))
	{
		buildtypeforexprinclass(s->whilestatement.condition,c);
		if(!issubtype(s->whilestatement.condition->m_type,"Boolean"))
		{
			cerr<< "Invalid condition expression"<<endl;
			exit(-1);
		}
		for(auto i: s->whilestatement.execution->value())
		{
			buildtypeforstmtinclass(i,c);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
 		cerr<<" can not return in construction func"<<endl;
 		exit(-1);
	}
	else if (s->tag == string("RETURN"))
	{
		cerr<<" can not return in construction func"<<endl;
 		exit(-1);
	}
	else if (s->tag == string("GETVALUE"))
	{
		if(s->g_value.left->tag == string("IDENT"))
		{
			c->m_variables_temp[s->g_value.left->identname] = LCA(c->m_variables_temp[s->g_value.left->identname],s->g_value.right->m_type);
			s->g_value.left->m_type = c->m_variables_temp[s->g_value.left->identname];
		}
		else if (s->g_value.left->tag == string("IDENTINMEMBER"))
		{
			//cout<< s->g_value.right->m_type<<endl<<s->g_value.right->identname<<endl;
			buildtypeforexprinclass(s->g_value.right,c);
			auto tag = s->g_value.right->tag;
			// if(tag == "IDENT")
			// {
			// 	c->m_variables[s->g_value.left->identname] = LCA(s->g_value.left->m_type,c->m_variables_temp[s->g_value.right->identname]);
			// 	s->g_value.left->m_type = c->m_variables[s->g_value.left->identname];
			// }
			// else if (tag == "IDENTINMEMBER")
			// {
			// 	c->m_variables[s->g_value.left->identname] = LCA(s->g_value.left->m_type,c->m_variables[s->g_value.right->identname]);
			// 	s->g_value.left->m_type = c->m_variables[s->g_value.left->identname];
			// }
			// else
			// {
			c->m_variables[s->g_value.left->identname] = LCA(c->m_variables[s->g_value.left->identname],s->g_value.right->m_type);
			s->g_value.left->m_type = c->m_variables[s->g_value.left->identname];
			//}
		}
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{

	}			
	else if(s->tag == "EXP")
	{
		buildtypeforexprinclass(s->exp,c);
	}
}
/*

build type for method

*/

void buildtypeforexprinmethod(r_expr* e, method* m, basic_class* c)
{
	if(e->tag == string("IDENT"))
	{
		if(e->identname != "this")
		{
			e->m_type = m->m_variables[e->identname];
		}
		else
		{
			cerr<< "this must come with class variable definition"<<endl;
			exit(-1);
		}
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		if(e->identparent->identname  == "this")
		{
			e->m_type = c->m_variables[e->identname];

		}
		else
		{
			cerr<< "not allowed to use it"<<endl;
			exit(-1);
		}
	}
	else if(e->tag == string("bin_oper"))
	{
		buildtypeforexprinmethod(e->b.l,m,c);
		buildtypeforexprinmethod(e->b.r,m,c);
		auto oper = e->b.s;
		if(classtable[e->b.l->m_type]->methodtable.find(oper) == classtable[e->b.l->m_type]->methodtable.end())
		{
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			auto p = classtable[e->b.l->m_type]->methodtable[oper]->para()[0].type;
			if(!issubtype(e->b.r->m_type,p))
			{
				cerr<< "wrong type got"<<endl;
				exit(-1);
			}
			else
			{
				e->m_type = classtable[e->b.l->m_type]->methodtable[oper]->m_returntype;
			}
		}
	}
	else if(e->tag == string("single_oper"))
	{
		buildtypeforexprinmethod(e->s.e,m,c);
		auto oper = e->s.s;
		if(classtable[e->s.e->m_type]->methodtable.find(oper) == classtable[e->s.e->m_type]->methodtable.end())
		{
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = classtable[e->s.e->m_type]->methodtable[oper]->m_returntype;
		}
	}
	else if(e->tag == string("function_call"))
	{

		buildtypeforexprinmethod(e->f.e,m,c);
		auto temp = e->f.e->m_type;
		if(classtable[temp]->methodtable.find(e->f.s) == classtable[temp]->methodtable.end())
		{
			cerr<< temp<<endl;
			cerr<<"unknown function "<<e->f.s<<endl;
			exit(-1);
		}
		else
		{
			for(int i = 0;i < e->f.p->m_value.size();++i)
			{
				cout<<i<<endl;
				if(!issubtype(e->f.p->m_value[i]->m_type,classtable[temp]->methodtable[e->f.s]->para()[i].type))
				{
					cerr<<"invalid para"<<endl;
					exit(-1);
				}
			}
			e->m_type = classtable[temp]->methodtable[e->f.s]->m_returntype;
		}
	}
	else if(e->tag == string("class_call"))
	{
		if(classtable.find(e->c.s) != classtable.end())
		{
			e->m_type = classtable[e->c.s]->name();
			auto temp = e->m_type;
			for(int i = 0;i < e->c.p->m_value.size();++i)
			{
				buildtypeforexprinmethod(e->c.p->m_value[i],m,c);
				cout<<e->c.p->m_value[i]->m_type<<" "<<classtable[temp]->para()[i].type<<endl;
				if(!issubtype(e->c.p->m_value[i]->m_type,classtable[temp]->para()[i].type))
				{
					cerr<<"invalid para"<<endl;
					exit(-1);
				}
			}
		}
		else if(c->methodtable.find(e->c.s) != c->methodtable.end())
		{
			e->m_type = c->methodtable[e->c.s]->m_returntype;
			auto temp = e->m_type;
			for(int i = 0;i < e->c.p->m_value.size();++i)
			{
				if(!issubtype(e->c.p->m_value[i]->m_type,classtable[temp]->methodtable[e->c.s]->para()[i].type))
				{
					cerr<<"invalid para in "<< e->c.s<<endl;
					exit(-1);
				}
			}
		}
		else
		{
			cerr<<"unknown function or class call"<<endl;
			exit(-1);
		}
	}
	else
	{
		cout<< e->m_type<<"laalala"<<endl;
	}

}

void buildtypeforstmtinmethod(statement* s,method* m,basic_class* c)
{
	if(s->tag == string("IFELSE"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinmethod(i.condition,m,c);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmtinmethod(j,m,c);
			}
		}
		for(auto j: s->elsestatements->value())
		{
			buildtypeforstmtinmethod(j,m,c);
		}

	}
	else if(s->tag == string("IF"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinmethod(i.condition,m,c);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmtinmethod(j,m,c);
			}		
		}
	}
	else if(s->tag == string("WHILE"))
	{
		buildtypeforexprinmethod(s->whilestatement.condition,m,c);
		if(!issubtype(s->whilestatement.condition->m_type,"Boolean"))
		{
			cerr<< "Invalid condition expression"<<endl;
			exit(-1);
		}
		for(auto i: s->whilestatement.execution->value())
		{
			buildtypeforstmtinmethod(i,m,c);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		//pass;
	}
	else if (s->tag == string("RETURN"))
	{
		buildtypeforexprinmethod(s->exp,m,c);
		if(!issubtype(s->exp->m_type,m->m_returntype))
		{
			cerr<<"Wrong return type"<<endl;
			exit(-1);
		}
		cout<<"Finished return building in "<<m->name()<<endl;
		//getinitializedidentformethod(s->exp,s,m);
	}
	else if (s->tag == string("GETVALUE"))
	{
		buildtypeforexprinmethod(s->g_value.right,m,c);
		if(s->g_value.left->tag == string("IDENT"))
		{
			m->m_variables[s->g_value.left->identname] = LCA(s->g_value.left->m_type,s->g_value.right->m_type);
			s->g_value.left->m_type = m->m_variables[s->g_value.left->identname];
		}
		else if(s->g_value.left->tag == "IDENTINMEMBER")
		{
			c->m_variables[s->g_value.left->identname] = LCA(s->g_value.left->m_type,s->g_value.right->m_type);
			s->g_value.left->m_type = c->m_variables[s->g_value.left->identname];
		}
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{

	}			
	else if(s->tag == "EXP")
	{
		buildtypeforexprinmethod(s->exp,m,c);
	}
	
	//m->m_variables.insert(s->m_variables.begin(),s->m_variables.end());
}




/*
build type for expr in program stmt
*/

// void buildtypeforparainclass(basic_class* c)
// {
// 	for(auto p:c->para())
// 	{
// 		c->m_variables_temp[c.name] = c.type;
// 	}
// }

void buildtypeforexprinstmt(r_expr* e,statement* s,program* r)
{
	cout<<e->tag<<endl;
if(e->tag == string("IDENT"))
	{
		if(e->identname != "this")
		{
			if(r->m_variables.find(e->identname) != r->m_variables.end())
			{e->m_type =r->m_variables[e->identname];
			}
			else
			{
				e->m_type = s->m_variables[e->identname];
			}
		}
		else
		{
			cerr<<"illegal calling this"<<endl;
			exit(-1);
		}
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		//e->m_type = c->m_variables[e->identname];
		cerr<<"not allowed to call private member"<<endl;
		exit(-1);
	}
	else if(e->tag == string("bin_oper"))
	{
		buildtypeforexprinstmt(e->b.l,s,r);
		buildtypeforexprinstmt(e->b.r,s,r);
		auto oper = e->b.s;
		if(classtable[e->b.l->m_type]->methodtable.find(oper) == classtable[e->b.l->m_type]->methodtable.end())
		{
			cout<<oper<<endl;
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			auto p = classtable[e->b.l->m_type]->methodtable[oper]->para()[0].type;
			if(!issubtype(e->b.r->m_type,p))
			{
				cerr<< "wrong type got"<<endl;
				exit(-1);
			}
			else
			{
				e->m_type = classtable[e->b.l->m_type]->methodtable[oper]->m_returntype;
			}
		}
	}
	else if(e->tag == string("single_oper"))
	{
		buildtypeforexprinstmt(e->s.e,s,r);
		auto oper = e->s.s;
		if(classtable[e->s.e->m_type]->methodtable.find(oper) == classtable[e->s.e->m_type]->methodtable.end())
		{
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = classtable[e->s.e->m_type]->methodtable[oper]->m_returntype;
		}
	}
	else if(e->tag == string("function_call"))
	{
		//check if there is function
		//s->m_variable[e->f.s] = "Bottom";
		//getinitializedidentformethod(e,s,m);
		buildtypeforexprinstmt(e->f.e,s,r);
		auto temp = e->f.e->m_type;
		cout<<temp<<endl;
		if(classtable[temp]->methodtable.find(e->f.s) == classtable[temp]->methodtable.end())
		{
			cerr<<"unknown function "<< e->f.s<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = classtable[temp]->methodtable[e->f.s]->m_returntype;
			for(auto i: e->f.p->m_value)
			{
				buildtypeforexprinstmt(i,s,r);
			}
		}
	}
	else if(e->tag == string("class_call"))
	{
		if(classtable.find(e->c.s) != classtable.end())
		{
			e->m_type = classtable[e->c.s]->name();
			for(auto i : e->c.p->m_value)
			{
				buildtypeforexprinstmt(i,s,r);
			}
		}
		else
		{
			cerr<<"unknown function or class call"<<endl;
			exit(-1);
		}
	}
	else
	{
		cout<<" other expr"<<endl;
	}


}



void buildtypeforexprinstmt(r_expr* e,program* r)
{
if(e->tag == string("IDENT"))
	{
		if(e->identname != "this")
		{
			e->m_type =r->m_variables[e->identname];
		}
		else
		{
			cerr<<"illegal calling this"<<endl;
			exit(-1);
		}
	}
	else if (e->tag == string("IDENTINMEMBER"))
	{
		//e->m_type = c->m_variables[e->identname];
		cerr<<"not allowed to call private member"<<endl;
		exit(-1);
	}
	else if(e->tag == string("bin_oper"))
	{
		buildtypeforexprinstmt(e->b.l,r);
		buildtypeforexprinstmt(e->b.r,r);
		auto oper = e->b.s;
		if(classtable[e->b.l->m_type]->methodtable.find(oper) == classtable[e->b.l->m_type]->methodtable.end())
		{
			cout<<oper<<endl;
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			auto p = classtable[e->b.l->m_type]->methodtable[oper]->para()[0].type;
			if(!issubtype(e->b.r->m_type,p))
			{
				cerr<< "wrong type got"<<endl;
				exit(-1);
			}
			else
			{
				e->m_type = classtable[e->b.l->m_type]->methodtable[oper]->m_returntype;
			}
		}
	}
	else if(e->tag == string("single_oper"))
	{
		buildtypeforexprinstmt(e->s.e,r);
		auto oper = e->s.s;
		if(classtable[e->s.e->m_type]->methodtable.find(oper) == classtable[e->s.e->m_type]->methodtable.end())
		{
			cerr<< "wrong kind of oper"<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = classtable[e->s.e->m_type]->methodtable[oper]->m_returntype;
		}
	}
	else if(e->tag == string("function_call"))
	{
		//check if there is function
		//s->m_variable[e->f.s] = "Bottom";
		//getinitializedidentformethod(e,s,m);
		buildtypeforexprinstmt(e->f.e,r);
		auto temp = e->f.e->m_type;
		cout<<temp<<endl;
		if(classtable[temp]->methodtable.find(e->f.s) == classtable[temp]->methodtable.end())
		{
			cerr<<"unknown function "<<endl;
			exit(-1);
		}
		else
		{
			e->m_type = classtable[temp]->methodtable[e->f.s]->m_returntype;
			for(auto i: e->f.p->m_value)
			{
				buildtypeforexprinstmt(i,r);
			}
		}
	}
	else if(e->tag == string("class_call"))
	{
		if(classtable.find(e->c.s) != classtable.end())
		{
			e->m_type = classtable[e->c.s]->name();
			for(auto i : e->c.p->m_value)
			{
				buildtypeforexprinstmt(i,r);
			}
		}
		else
		{
			cerr<<"unknown function or class call"<<endl;
			exit(-1);
		}
	}
	else
	{
	}
}





void buildtypeforstmtinstmt(statement* s, statement* s2, program* r)
{
	if(s->tag == string("IFELSE"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinstmt(i.condition,r);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmtinstmt(j,s2,r);
			}
		}
		for(auto j: s->elsestatements->value())
		{
			buildtypeforstmtinstmt(j,s2,r);
		}

	}
	else if(s->tag == string("IF"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinstmt(i.condition,r);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmtinstmt(j,s2,r);
			}		
		}
	}
	else if(s->tag == string("WHILE"))
	{
		buildtypeforexprinstmt(s->whilestatement.condition,r);
		if(!issubtype(s->whilestatement.condition->m_type,"Boolean"))
		{
			cerr<< "Invalid condition expression"<<endl;
			exit(-1);
		}
		for(auto i: s->whilestatement.execution->value())
		{
			buildtypeforstmtinstmt(i,s2,r);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		cerr<<"not allowd to return in program"<<endl;
		exit(-1);
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		// if(!issubtype(s->exp->m_type,m->m_returntype))
		// {
		// 	cerr<<"Wrong return type"<<endl;
		// 	exit(-1);
		// }
		cerr<<"not allowd to return in program"<<endl;
		exit(-1);
		//getinitializedidentformethod(s->exp,s,m);
	}
	else if (s->tag == string("GETVALUE"))
	{
		buildtypeforexprinstmt(s->g_value.right,r);
		if(s->g_value.left->tag == string("IDENT"))
		{
			s2->m_variables[s->g_value.left->identname] = LCA(s->g_value.left->m_type,s->g_value.right->m_type);
			s->g_value.left->m_type = r->m_variables[s->g_value.left->identname];
		}
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{
		cerr<<"not allowd here"<<endl;
		exit(-1);
	}			
	else
	{

	}
}



void buildtypeforstmt(statement* s,statement* s2,program* r)
{
	cout<<s->tag<<endl;
	if(s->tag == string("IFELSE"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinstmt(i.condition,s2,r);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmt(j,s2,r);
			}
		}
		for(auto j: s->elsestatements->value())
		{
			buildtypeforstmt(j,s2,r);
		}

	}
	else if(s->tag == string("IF"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinstmt(i.condition,s2,r);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmt(j,s2,r);
			}		
		}
	}
	else if(s->tag == string("WHILE"))
	{
		buildtypeforexprinstmt(s->whilestatement.condition,s2,r);
		if(!issubtype(s->whilestatement.condition->m_type,"Boolean"))
		{
			cerr<< "Invalid condition expression"<<endl;
			exit(-1);
		}
		for(auto i: s->whilestatement.execution->value())
		{
			buildtypeforstmt(i,s2,r);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		cerr<<"not allowd to return in program"<<endl;
		exit(-1);
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		// if(!issubtype(s->exp->m_type,m->m_returntype))
		// {
		// 	cerr<<"Wrong return type"<<endl;
		// 	exit(-1);
		// }
		cerr<<"not allowd to return in program"<<endl;
		exit(-1);
		//getinitializedidentformethod(s->exp,s,m);
	}
	else if (s->tag == string("GETVALUE"))
	{
		buildtypeforexprinstmt(s->g_value.right,s2,r);
		if(s->g_value.left->tag == string("IDENT"))
		{
			auto name = s->g_value.left->identname;
			if(r->m_variables.find(name) != r->m_variables.end())
			{
				cout<<1<<endl;
				r->m_variables[s->g_value.left->identname] = LCA(r->m_variables[s->g_value.left->identname],s->g_value.right->m_type);
				s->g_value.left->m_type = r->m_variables[s->g_value.left->identname];
			}
			else
			{
				cout<<2<<endl;
				cout<<s2->m_variables[s->g_value.left->identname]<<" "<<s->g_value.right->m_type<<endl;
				s2->m_variables[s->g_value.left->identname] = LCA(s2->m_variables[s->g_value.left->identname],s->g_value.right->m_type);
				s->g_value.left->m_type = s2->m_variables[s->g_value.left->identname];
			}
			
		}
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{
		cerr<<"not allowd here"<<endl;
		exit(-1);
	}			
	else if(s->tag == "EXP")
	{
		buildtypeforexprinstmt(s->exp,s2,r);
	}
}



void buildtypeforstmt(statement* s,program* r)
{
	cout<<s->tag<<endl;
	if(s->tag == string("IFELSE"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinstmt(i.condition,r);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmt(j,r);
			}
		}
		for(auto j: s->elsestatements->value())
		{
			buildtypeforstmt(j,r);
		}

	}
	else if(s->tag == string("IF"))
	{
		for(auto i:s->branches)
		{
			buildtypeforexprinstmt(i.condition,r);
			if(!issubtype(i.condition->m_type,"Boolean"))
			{
				cerr<< "Invalid condition expression"<<endl;
				exit(-1);
			}
			for(auto j: i.execution->value())
			{
				buildtypeforstmt(j,s,r);
			}		
		}
	}
	else if(s->tag == string("WHILE"))
	{
		buildtypeforexprinstmt(s->whilestatement.condition,r);
		if(!issubtype(s->whilestatement.condition->m_type,"Boolean"))
		{
			cerr<< "Invalid condition expression"<<endl;
			exit(-1);
		}
		for(auto i: s->whilestatement.execution->value())
		{
			buildtypeforstmt(i,s,r);
		}
	}
	else if(s->tag == string("RETURNNULL"))
	{
 		cerr<<"not allowd to return in program"<<endl;
		exit(-1);
	}
	else if (s->tag == string("RETURN"))
	{
		//cout<<" i am in return";
		// if(!issubtype(s->exp->m_type,m->m_returntype))
		// {
		// 	cerr<<"Wrong return type"<<endl;
		// 	exit(-1);
		// }
		cerr<<"not allowd to return in program"<<endl;
		exit(-1);
		//getinitializedidentformethod(s->exp,s,m);
	}
	else if (s->tag == string("GETVALUE"))
	{
		buildtypeforexprinstmt(s->g_value.right,r);
		if(s->g_value.left->tag == string("IDENT"))
		{
			r->m_variables[s->g_value.left->identname] = LCA(r->m_variables[s->g_value.left->identname],s->g_value.right->m_type);
			s->g_value.left->m_type = r->m_variables[s->g_value.left->identname];
		}
	}
	else if(s->tag == string("GETVALUEMEMBER"))
	{
		cerr<<"not allowd here"<<endl;
		exit(-1);
	}			
	else if(s->tag == "EXP")
	{
		buildtypeforexprinstmt(s->exp,r);
	}
}

















































int main(int argv, char** argc) {
	// open a file handle to a particular file:
	FILE *myfile = fopen(argc[1], "r");
	// make sure it's valid:
	if (!myfile) {
		cout << "I can't open the input file!" << endl;
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	cout<<"Being parsing"<<endl;
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	cout<<"Finished parsing with 0 errors"<<endl;
	//cout<<root<<endl;
	init();
	class_inherit_issue();
	class_method_inherit();
	auto c = classtable["Int"];
	for(auto i: c->methodtable)
	{
		cout<<i.first<<" "<<i.second->origin_class<<endl;
	}
	



	for(auto i: root->cs)
	{	
		for(auto j:i->para())
		{
			i->m_variables_temp[j.name] = j.type;
		}
		for(auto j:i->m_statements)
		{
			buildvariableforclass(j,i);
		}
		for(auto j: i->m_methods)
		{	
			methodstmt(j,i);
		}

	}
	for (auto i:root->ss)
	{
		buildvariableforstmt(i,root);
	}
	cout<<"Finished build variables"<<endl;
	for(auto c:root->cs)
	{
		for(auto s:c->m_statements)
		{
			buildtypeforstmtinclass(s,c);
		}
		cout<<"Finished build types for in class for "<<c->name()<<endl;
		for(auto m:c->methodtable)
		{
			cout<<"Begin build types for method "<<m.first<<" in "<<c->name()<<endl;
			for(auto s:m.second->methodstatements)
			{
				buildtypeforstmtinmethod(s,m.second,c);
			}
			cout<<"Finished build types for in method for "<<m.first<<" in "<<c->name()<<endl;
		}

	}
	for(auto i:root->ss)
	{
		buildtypeforstmt(i,root);
	}
	cout<<"Finished build type"<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"******************************************************************************"<<endl;
	codegenpgm(root);
	cout<<"********************************************************************************"<<endl;
}




void yyerror(const char *s) {
	
	cout << yylineno << ": " << s <<"(at '"<<yytext<<"')"<< endl;
	// might as well halt now:
	exit(-1);
}


