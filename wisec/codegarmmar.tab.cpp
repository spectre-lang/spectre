
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "codegarmmar.y"

/*
* Author: Chuanwise
* lastest update date: 2021 / 03 / 16
*/
#include "codegarmmar.tab.h"
#include <stdio.h>
#include <string>

extern int yylineno;

extern wisec::ClassFile* wisec::current_class_file() noexcept;
extern wisec::Expression* wisec::current_object_class() noexcept;

int yywrap() {
    return 1;
}
void yyerror(const char* str) {
    current_class_file()->append_error("at " + std::to_string(yylineno), str);
}

extern int yylex();
#define YYDEBUG 1
#define YY_SKIP_YYWRAP


/* Line 189 of yacc.c  */
#line 103 "codegarmmar.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOL_IVAL = 258,
     CHAR_IVAL = 259,
     BYTE_IVAL = 260,
     SHORT_IVAL = 261,
     INT_IVAL = 262,
     LONG_IVAL = 263,
     FLOAT_IVAL = 264,
     DOUBLE_IVAL = 265,
     STRING_IVAL = 266,
     VAR = 267,
     VOID = 268,
     BOOL = 269,
     CHAR = 270,
     BYTE = 271,
     SHORT = 272,
     INT = 273,
     LONG = 274,
     FLOAT = 275,
     DOUBLE = 276,
     NEW = 277,
     CLASS = 278,
     EXTENDS = 279,
     IMPLEMENTS = 280,
     PROPERTY = 281,
     TRIPLE_DOT = 282,
     DOT = 283,
     COMMA = 284,
     SEMI = 285,
     LPARENT = 286,
     RPARENT = 287,
     LBRACKET = 288,
     RBRACKET = 289,
     LBRACE = 290,
     RBRACE = 291,
     PLUS = 292,
     MINUS = 293,
     MOD = 294,
     TRANS = 295,
     DIV = 296,
     MULTI = 297,
     NOT_EQ = 298,
     SMALLER_EQ = 299,
     BIGGER_EQ = 300,
     ASSIGN = 301,
     EQUALS = 302,
     INSTANCEOF = 303,
     SMALLER = 304,
     BIGGER = 305,
     THROWS = 306,
     THROW = 307,
     PACKAGE = 308,
     IMPORT = 309,
     PUBLIC = 310,
     PROTECTED = 311,
     PRIVATE = 312,
     STATIC = 313,
     CONST = 314,
     FINAL = 315,
     ABSTRACT = 316,
     MANUAL = 317,
     IDENTIFY = 318
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 30 "codegarmmar.y"

    bool bool_ival;
    wchar_t char_ival;

    char byte_ival;
    short short_ival;
    int int_ival;
    long long long_ival;
    float float_ival;
    double double_ival;

    const char* string_ival;

    vector<Expression*>* expression_list;
    vector<const char*>* package_name;

    const char* identify;

    Expression* expression;
    Modifiers* modifiers;
    Modifiers::PermissionType permission_type;
    bool has_modifier;

    vector<ClassPart*>* class_parts;
    ClassPart* class_part;

    vector<MethodParameter*>* parameter_list;

    Statement* statement;



/* Line 214 of yacc.c  */
#line 235 "codegarmmar.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 247 "codegarmmar.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   295

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    20,
      24,    28,    34,    38,    40,    42,    44,    46,    48,    50,
      52,    54,    56,    58,    60,    62,    64,    66,    68,    70,
      72,    74,    76,    78,    81,    85,    90,    94,    96,   100,
     102,   107,   113,   115,   120,   124,   128,   132,   134,   136,
     143,   145,   149,   153,   157,   161,   165,   169,   173,   177,
     181,   185,   189,   193,   197,   199,   203,   205,   207,   209,
     211,   212,   214,   215,   217,   218,   222,   228,   235,   237,
     240,   242,   245,   250,   253,   254,   262,   271,   274,   278,
     280,   283,   286,   289,   294,   298,   300,   304,   306
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      65,     0,    -1,    66,    -1,    65,    66,    -1,    68,    -1,
      69,    -1,    84,    -1,    63,    -1,    67,    28,    63,    -1,
      54,    42,    30,    -1,    54,    67,    30,    -1,    54,    67,
      28,    42,    30,    -1,    53,    67,    30,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,     7,    -1,     8,    -1,
       9,    -1,    10,    -1,    11,    -1,    14,    -1,    15,    -1,
      16,    -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    13,    -1,    63,    -1,    71,    -1,    72,    27,
      -1,    72,    33,    34,    -1,    72,    33,    73,    34,    -1,
      72,    28,    63,    -1,    72,    -1,    73,    29,    72,    -1,
      72,    -1,    22,    72,    31,    32,    -1,    22,    72,    31,
      78,    32,    -1,    74,    -1,    75,    31,    78,    32,    -1,
      75,    31,    32,    -1,    75,    28,    63,    -1,    75,    28,
      23,    -1,    75,    -1,    70,    -1,    31,    72,    32,    31,
      76,    32,    -1,    76,    -1,    77,    37,    76,    -1,    77,
      38,    76,    -1,    77,    42,    76,    -1,    77,    41,    76,
      -1,    77,    39,    76,    -1,    77,    40,    76,    -1,    77,
      50,    76,    -1,    77,    49,    76,    -1,    77,    45,    76,
      -1,    77,    44,    76,    -1,    77,    47,    76,    -1,    77,
      43,    76,    -1,    77,    46,    76,    -1,    79,    -1,    78,
      29,    79,    -1,    77,    -1,    55,    -1,    57,    -1,    56,
      -1,    -1,    58,    -1,    -1,    59,    -1,    -1,    80,    81,
      82,    -1,    83,    23,    63,    35,    36,    -1,    83,    23,
      63,    35,    85,    36,    -1,    86,    -1,    86,    85,    -1,
      89,    -1,    72,    63,    -1,    87,    29,    72,    63,    -1,
      51,    73,    -1,    -1,    83,    72,    63,    31,    32,    88,
      90,    -1,    83,    72,    63,    31,    87,    32,    88,    90,
      -1,    35,    36,    -1,    35,    91,    36,    -1,    92,    -1,
      91,    92,    -1,    93,    30,    -1,    79,    30,    -1,    59,
      72,    95,    30,    -1,    72,    95,    30,    -1,    63,    -1,
      63,    46,    79,    -1,    94,    -1,    95,    29,    94,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   123,   126,   127,   128,   132,   133,   136,
     137,   138,   141,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   166,   167,   168,   169,   170,   171,   174,   175,   178,
     179,   180,   183,   184,   185,   186,   187,   190,   191,   192,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   211,   212,   215,   218,   219,   220,
     221,   224,   225,   228,   229,   236,   239,   240,   243,   244,
     247,   252,   253,   256,   257,   260,   261,   264,   265,   268,
     269,   272,   273,   276,   277,   280,   281,   284,   285
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL_IVAL", "CHAR_IVAL", "BYTE_IVAL",
  "SHORT_IVAL", "INT_IVAL", "LONG_IVAL", "FLOAT_IVAL", "DOUBLE_IVAL",
  "STRING_IVAL", "VAR", "VOID", "BOOL", "CHAR", "BYTE", "SHORT", "INT",
  "LONG", "FLOAT", "DOUBLE", "NEW", "CLASS", "EXTENDS", "IMPLEMENTS",
  "PROPERTY", "TRIPLE_DOT", "DOT", "COMMA", "SEMI", "LPARENT", "RPARENT",
  "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "PLUS", "MINUS", "MOD",
  "TRANS", "DIV", "MULTI", "NOT_EQ", "SMALLER_EQ", "BIGGER_EQ", "ASSIGN",
  "EQUALS", "INSTANCEOF", "SMALLER", "BIGGER", "THROWS", "THROW",
  "PACKAGE", "IMPORT", "PUBLIC", "PROTECTED", "PRIVATE", "STATIC", "CONST",
  "FINAL", "ABSTRACT", "MANUAL", "IDENTIFY", "$accept", "program",
  "program_part", "package_name", "import_propart", "package_statement",
  "ival", "basic_type", "type_expression", "type_expression_list",
  "construct_expression", "call_expression", "simple_expression",
  "calc_expression", "expression_list", "expression",
  "permission_modifier", "static_modifier", "const_modifier", "modifiers",
  "class_declaration", "class_member_list", "class_member",
  "parameter_list", "throws_exceptions", "method_declaration",
  "compound_statement", "statement_list", "statement",
  "variable_declaration_statement", "declarator", "declarator_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    65,    66,    66,    66,    67,    67,    68,
      68,    68,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    73,    73,    74,
      74,    74,    75,    75,    75,    75,    75,    76,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    79,    80,    80,    80,
      80,    81,    81,    82,    82,    83,    84,    84,    85,    85,
      86,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     3,
       3,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     4,     3,     1,     3,     1,
       4,     5,     1,     4,     3,     3,     3,     1,     1,     6,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     1,     1,     1,     1,
       0,     1,     0,     1,     0,     3,     5,     6,     1,     2,
       1,     2,     4,     2,     0,     7,     8,     2,     3,     1,
       2,     2,     2,     4,     3,     1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      70,     0,     0,    67,    69,    68,    70,     2,     4,     5,
      72,     0,     6,     7,     0,     0,     0,     1,     3,    71,
      74,     0,     0,    12,     9,     0,    10,    73,    75,     0,
       8,     0,    70,    11,    76,     0,     0,    70,    80,    30,
      22,    23,    24,    25,    26,    27,    28,    29,    31,    32,
       0,    77,    79,    33,     0,     0,     0,    36,    34,    37,
       0,     0,     0,    35,    84,     0,     0,    38,     0,     0,
      81,     0,    84,    83,     0,    85,     0,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,    87,
       0,    48,    39,    42,    47,    50,    66,     0,     0,    89,
       0,    82,    86,     0,     0,     0,    95,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,    88,    90,    91,     0,     0,
       0,     0,     0,    94,    46,    45,    44,    39,     0,    64,
      51,    52,    55,    56,    54,    53,    62,    60,    59,    63,
      61,    58,    57,    40,     0,     0,    93,    96,    98,     0,
      43,    41,     0,    65,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,    14,     8,     9,    91,    49,   137,    60,
      93,    94,    95,    96,   138,    97,    10,    20,    28,    11,
      12,    36,    37,    66,    69,    38,    75,    98,    99,   100,
     107,   108
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -38
static const yytype_int16 yypact[] =
{
      31,   -21,   -29,   -38,   -38,   -38,     3,   -38,   -38,   -38,
      38,     6,   -38,   -38,     0,    77,    10,   -38,   -38,   -38,
       2,    56,    58,   -38,   -38,   -28,   -38,   -38,   -38,    93,
     -38,   111,   -34,   -38,   -38,   210,   135,   211,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
      62,   -38,   -38,   -38,    66,    -9,   126,   -38,   -38,     4,
     -10,    30,   210,   -38,   108,   155,   -14,     4,   210,   149,
     -38,   210,   108,   158,    61,   -38,   186,   149,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   210,   210,   -38,
     210,   -38,   218,   -38,    99,   -38,   245,   172,    95,   -38,
     185,   -38,   -38,   227,   229,   218,   143,   -38,   -13,   -22,
     129,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   -38,   -38,   -38,   -38,   159,   189,
     156,   190,   153,   -38,   -38,   -38,   -38,     4,   123,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   124,   190,   -38,   -38,   -38,   190,
     -38,   -38,   216,   -38,   -38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -38,   -38,   244,   215,   -38,   -38,   -38,   -38,   -35,   184,
     -38,   -38,   121,   -38,   131,   -37,   -38,   -38,   -38,    86,
     -38,   226,   -38,   -38,   192,   -38,   188,   -38,   171,   -38,
     138,   166
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -79
static const yytype_int16 yytable[] =
{
      50,   134,    34,    17,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    15,    31,    71,   132,   133,    72,    62,
      59,     3,     4,     5,    63,    58,    65,    67,    22,    21,
      23,    53,    54,    59,    13,    30,    76,    55,    25,    92,
      26,   135,    13,    39,    40,    41,    42,    43,    44,    45,
      46,    47,   103,   104,    48,   105,     1,     2,     3,     4,
       5,    27,    64,    92,    78,    79,    80,    81,    82,    83,
      84,    85,    86,   139,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    87,     1,     2,     3,     4,     5,    53,
      54,   139,    88,    48,   157,    55,    19,    89,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    24,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    87,    35,    29,
      90,    30,   163,    35,    48,    56,    88,   109,    32,    57,
     110,   125,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    33,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    87,   159,   159,    90,   160,   161,    61,    48,    68,
      88,   136,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    51,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    87,    53,    54,    74,   132,   156,    62,    55,   131,
      88,   153,    48,    78,    79,    80,    81,    82,    83,    84,
      85,    86,   124,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    87,    53,    54,   127,   106,    16,    70,    55,
     155,    88,    48,    39,    40,    41,    42,    43,    44,    45,
      46,    47,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    53,    54,   -78,   164,   101,
      18,    55,    73,    48,    53,    54,    53,    54,   128,   154,
      55,   129,    55,    52,    77,   102,     3,     4,     5,   126,
     158,   130,     0,    48,     0,     0,   162,     0,     0,     0,
       0,   106,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,   123
};

static const yytype_int16 yycheck[] =
{
      35,    23,    36,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    42,    42,    29,    29,    30,    32,    29,
      55,    55,    56,    57,    34,    34,    61,    62,    28,    23,
      30,    27,    28,    68,    63,    63,    71,    33,    28,    74,
      30,    63,    63,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    87,    88,    63,    90,    53,    54,    55,    56,
      57,    59,    32,    98,     3,     4,     5,     6,     7,     8,
       9,    10,    11,   110,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    53,    54,    55,    56,    57,    27,
      28,   128,    31,    63,   131,    33,    58,    36,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    30,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    32,    63,
      59,    63,   159,    37,    63,    63,    31,    28,    35,    63,
      31,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    30,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    29,    29,    59,    32,    32,    31,    63,    51,
      31,    32,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    36,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    27,    28,    35,    29,    30,    29,    33,    46,
      31,    32,    63,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    30,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    27,    28,    30,    63,     2,    63,    33,
      31,    31,    63,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    27,    28,    36,    32,    63,
       6,    33,    68,    63,    27,    28,    27,    28,    31,   128,
      33,    32,    33,    37,    72,    77,    55,    56,    57,    98,
     132,   105,    -1,    63,    -1,    -1,   155,    -1,    -1,    -1,
      -1,    63,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    54,    55,    56,    57,    65,    66,    68,    69,
      80,    83,    84,    63,    67,    42,    67,     0,    66,    58,
      81,    23,    28,    30,    30,    28,    30,    59,    82,    63,
      63,    42,    35,    30,    36,    83,    85,    86,    89,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    63,    71,
      72,    36,    85,    27,    28,    33,    63,    63,    34,    72,
      73,    31,    29,    34,    32,    72,    87,    72,    51,    88,
      63,    29,    32,    73,    35,    90,    72,    88,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    22,    31,    36,
      59,    70,    72,    74,    75,    76,    77,    79,    91,    92,
      93,    63,    90,    72,    72,    72,    63,    94,    95,    28,
      31,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    49,    50,    30,    36,    92,    30,    31,    32,
      95,    46,    29,    30,    23,    63,    32,    72,    78,    79,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    32,    78,    31,    30,    79,    94,    29,
      32,    32,    76,    79,    32
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 122 "codegarmmar.y"
    { current_class_file()->append_part((yyvsp[(1) - (1)].class_part)); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 123 "codegarmmar.y"
    { current_class_file()->append_part((yyvsp[(2) - (2)].class_part)); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 126 "codegarmmar.y"
    { (yyval.class_part) = (yyvsp[(1) - (1)].class_part); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 127 "codegarmmar.y"
    { (yyval.class_part) = (yyvsp[(1) - (1)].class_part); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 128 "codegarmmar.y"
    { (yyval.class_part) = (yyvsp[(1) - (1)].class_part); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 132 "codegarmmar.y"
    { (yyval.package_name) = new_identify_list((yyvsp[(1) - (1)].identify)); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 133 "codegarmmar.y"
    { (yyvsp[(1) - (3)].package_name)->emplace_back((yyvsp[(3) - (3)].identify)); (yyval.package_name) = (yyvsp[(1) - (3)].package_name); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 136 "codegarmmar.y"
    { (yyval.class_part) = import_class_part(nullptr, true); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 137 "codegarmmar.y"
    { (yyval.class_part) = import_class_part((yyvsp[(2) - (3)].package_name), false); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 138 "codegarmmar.y"
    { (yyval.class_part) = import_class_part((yyvsp[(2) - (5)].package_name), true); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 141 "codegarmmar.y"
    { (yyval.class_part) = package_class_part((yyvsp[(2) - (3)].package_name)); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 144 "codegarmmar.y"
    { (yyval.expression) = bool_ival_expression((yyvsp[(1) - (1)].bool_ival)); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 145 "codegarmmar.y"
    { (yyval.expression) = char_ival_expression((yyvsp[(1) - (1)].char_ival)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 146 "codegarmmar.y"
    { (yyval.expression) = byte_ival_expression((yyvsp[(1) - (1)].byte_ival)); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 147 "codegarmmar.y"
    { (yyval.expression) = short_ival_expression((yyvsp[(1) - (1)].short_ival)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 148 "codegarmmar.y"
    { (yyval.expression) = int_ival_expression((yyvsp[(1) - (1)].int_ival)); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 149 "codegarmmar.y"
    { (yyval.expression) = long_ival_expression((yyvsp[(1) - (1)].long_ival)); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 150 "codegarmmar.y"
    { (yyval.expression) = float_ival_expression((yyvsp[(1) - (1)].float_ival)); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 151 "codegarmmar.y"
    { (yyval.expression) = double_ival_expression((yyvsp[(1) - (1)].double_ival)); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 152 "codegarmmar.y"
    { (yyval.expression) = string_ival_expression((yyvsp[(1) - (1)].string_ival)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 155 "codegarmmar.y"
    { (yyval.expression) = bool_expression(); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 156 "codegarmmar.y"
    { (yyval.expression) = char_expression(); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 157 "codegarmmar.y"
    { (yyval.expression) = byte_expression(); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 158 "codegarmmar.y"
    { (yyval.expression) = short_expression(); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 159 "codegarmmar.y"
    { (yyval.expression) = int_expression(); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 160 "codegarmmar.y"
    { (yyval.expression) = long_expression(); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 161 "codegarmmar.y"
    { (yyval.expression) = float_expression(); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 162 "codegarmmar.y"
    { (yyval.expression) = double_expression(); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 163 "codegarmmar.y"
    { (yyval.expression) = void_expression(); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 166 "codegarmmar.y"
    { (yyval.expression) = identify_expression((yyvsp[(1) - (1)].identify)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 167 "codegarmmar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 168 "codegarmmar.y"
    { (yyval.expression) = to_auto_length_type_expression((yyvsp[(1) - (2)].expression)); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 169 "codegarmmar.y"
    { (yyval.expression) = to_array_type_expression((yyvsp[(1) - (3)].expression)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 170 "codegarmmar.y"
    { (yyval.expression) = to_template_type_expresion((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression_list)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 171 "codegarmmar.y"
    { (yyval.expression) = dot_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identify)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 174 "codegarmmar.y"
    { (yyval.expression_list) = new_expression_list((yyvsp[(1) - (1)].expression)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 175 "codegarmmar.y"
    { (yyvsp[(1) - (3)].expression_list)->emplace_back();  (yyval.expression_list) = (yyvsp[(1) - (3)].expression_list); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 178 "codegarmmar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 179 "codegarmmar.y"
    { (yyval.expression) = constructor_call_expression((yyvsp[(2) - (4)].expression), new_expression_list()); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 180 "codegarmmar.y"
    { (yyval.expression) = constructor_call_expression((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].expression_list)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 183 "codegarmmar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 184 "codegarmmar.y"
    { (yyval.expression) = method_call_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression_list)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 185 "codegarmmar.y"
    { (yyval.expression) = method_call_expression((yyvsp[(1) - (3)].expression), new_expression_list()); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 186 "codegarmmar.y"
    { (yyval.expression) = dot_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].identify)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 187 "codegarmmar.y"
    { (yyval.expression) = dot_expression((yyvsp[(1) - (3)].expression), "class"); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 190 "codegarmmar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 191 "codegarmmar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 192 "codegarmmar.y"
    { (yyval.expression) = cast_expression((yyvsp[(2) - (6)].expression), (yyvsp[(5) - (6)].expression)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 195 "codegarmmar.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 196 "codegarmmar.y"
    { (yyval.expression) = plus_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 197 "codegarmmar.y"
    { (yyval.expression) = minus_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 198 "codegarmmar.y"
    { (yyval.expression) = multi_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 199 "codegarmmar.y"
    { (yyval.expression) = div_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 200 "codegarmmar.y"
    { (yyval.expression) = mod_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 201 "codegarmmar.y"
    { (yyval.expression) = trans_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 202 "codegarmmar.y"
    { (yyval.expression) = bigger_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 203 "codegarmmar.y"
    { (yyval.expression) = smaller_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 204 "codegarmmar.y"
    { (yyval.expression) = biggereq_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 205 "codegarmmar.y"
    { (yyval.expression) = smallereq_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 206 "codegarmmar.y"
    { (yyval.expression) = equals_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 207 "codegarmmar.y"
    { (yyval.expression) = noteq_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 208 "codegarmmar.y"
    { (yyval.expression) = assign_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 211 "codegarmmar.y"
    { (yyval.expression_list) = new_expression_list((yyvsp[(1) - (1)].expression)); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 212 "codegarmmar.y"
    { (yyvsp[(1) - (3)].expression_list)->emplace_back((yyvsp[(3) - (3)].expression)); (yyval.expression_list) = (yyvsp[(1) - (3)].expression_list); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 215 "codegarmmar.y"
    { (yyval.expression)  = (yyvsp[(1) - (1)].expression); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 218 "codegarmmar.y"
    { (yyval.permission_type) = Modifiers::PermissionType::PUBLIC; ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 219 "codegarmmar.y"
    { (yyval.permission_type) = Modifiers::PermissionType::PRIVATE; ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 220 "codegarmmar.y"
    { (yyval.permission_type) = Modifiers::PermissionType::PROTECTED; ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 221 "codegarmmar.y"
    { (yyval.permission_type) = Modifiers::PermissionType::DEFAULT; ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 224 "codegarmmar.y"
    { (yyval.has_modifier) = true; ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 225 "codegarmmar.y"
    { (yyval.has_modifier) = false; ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 228 "codegarmmar.y"
    { (yyval.has_modifier) = true; ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 229 "codegarmmar.y"
    { (yyval.has_modifier) = false; ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 236 "codegarmmar.y"
    { (yyval.modifiers) = new_modifiers(); (yyval.modifiers)->permission = (yyvsp[(1) - (3)].permission_type); (yyval.modifiers)->is_static = (yyvsp[(2) - (3)].has_modifier);  (yyval.modifiers)->is_const = (yyvsp[(3) - (3)].has_modifier); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 239 "codegarmmar.y"
    { (yyval.class_part) = new_class((yyvsp[(1) - (5)].modifiers), (yyvsp[(3) - (5)].identify), new_class_parts(), current_object_class(), new_expression_list()); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 240 "codegarmmar.y"
    { (yyval.class_part) = new_class((yyvsp[(1) - (6)].modifiers), (yyvsp[(3) - (6)].identify), (yyvsp[(5) - (6)].class_parts), current_object_class(), new_expression_list()); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 243 "codegarmmar.y"
    { (yyval.class_parts) = new_class_parts((yyvsp[(1) - (1)].class_part)); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 244 "codegarmmar.y"
    { (yyvsp[(2) - (2)].class_parts)->emplace_back((yyvsp[(1) - (2)].class_part)); (yyval.class_parts) = (yyvsp[(2) - (2)].class_parts); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 247 "codegarmmar.y"
    { (yyval.class_part) = (yyvsp[(1) - (1)].class_part); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 252 "codegarmmar.y"
    { (yyval.parameter_list) = new_method_parameters(new_method_parameter((yyvsp[(1) - (2)].expression), (yyvsp[(2) - (2)].identify), nullptr)); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 253 "codegarmmar.y"
    { (yyval.parameter_list)->emplace_back(new_method_parameter((yyvsp[(3) - (4)].expression), (yyvsp[(4) - (4)].identify), nullptr)); (yyval.parameter_list) = (yyvsp[(1) - (4)].parameter_list); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 260 "codegarmmar.y"
    { (yyval.class_part) = new_method((yyvsp[(1) - (7)].modifiers), (yyvsp[(2) - (7)].expression), (yyvsp[(3) - (7)].identify), new_method_parameters(), (yyvsp[(7) - (7)].statement)); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 261 "codegarmmar.y"
    { (yyval.class_part) = new_method((yyvsp[(1) - (8)].modifiers), (yyvsp[(2) - (8)].expression), (yyvsp[(3) - (8)].identify), (yyvsp[(5) - (8)].parameter_list), (yyvsp[(8) - (8)].statement)); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 264 "codegarmmar.y"
    { (yyval.statement) = compound_statement(); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 265 "codegarmmar.y"
    { (yyval.statement) = (yyvsp[(2) - (3)].statement); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 268 "codegarmmar.y"
    { (yyval.statement) = compound_statement((yyvsp[(1) - (1)].statement)); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 269 "codegarmmar.y"
    { (yyval.statement) = compound_statement((yyvsp[(1) - (2)].statement), (yyvsp[(2) - (2)].statement)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2240 "codegarmmar.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



