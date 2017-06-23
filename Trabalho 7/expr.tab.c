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
#line 1 "expr.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.tab.h"
#include "eda.h"
#include "cmd.h"

typedef struct {
    struct List *listaId;
    char nomeId[10];
    char* strg;
    TIPO tipo;
    TIPO* listaTipo;
    double double_value;
    struct IntList* listav;
    struct IntList* listaf;
    int label;
}Atributo;

struct arvore* tabelaSimbolosGlobais;
struct arvore* tabelaSimbolosFuncoes;
#define YYSTYPE Atributo
int __linha__ = 1;

int funcNargs = 0;



#line 96 "expr.tab.c" /* yacc.c:339  */

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
    T_BIT_DIREITA = 258,
    T_BIT_ESQUERDA = 259,
    T_ADICAO = 260,
    T_SUBTRACAO = 261,
    T_MULTIPLICACAO = 262,
    T_DIVISAO = 263,
    T_RESTO = 264,
    T_IGUAL = 265,
    T_ABRE_PARENTESES = 266,
    T_FECHA_PARENTESES = 267,
    T_ABRE_CHAVES = 268,
    T_FECHA_CHAVES = 269,
    T_INT = 270,
    T_DOUBLE = 271,
    T_STRING = 272,
    T_VOID = 273,
    T_IF = 274,
    T_WHILE = 275,
    T_ELSE = 276,
    T_PRINT = 277,
    T_READ = 278,
    T_RETURN = 279,
    T_ID = 280,
    T_LITERAL = 281,
    T_FIM = 282,
    T_NUM = 283,
    T_VIRGULA = 284,
    T_PONTO_E_VIRGULA = 285,
    T_AND = 286,
    T_NOT = 287,
    T_OR = 288,
    T_TRUE = 289,
    T_FALSE = 290,
    T_MAIOR_IGUAL = 291,
    T_MENOR_IGUAL = 292,
    T_DIFERENTE = 293,
    T_IGUAL_IGUAL = 294,
    T_MAIOR = 295,
    T_MENOR = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 186 "expr.tab.c" /* yacc.c:358  */

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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   254

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  172

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
       0,    34,    34,    35,    38,    39,    42,    44,    45,    48,
      50,    52,    53,    54,    55,    58,    59,    62,    65,    66,
      69,    70,    73,    77,    78,    79,    82,    83,    86,    89,
      90,    93,    94,    95,    96,    97,    98,    99,   102,   103,
     106,   107,   110,   112,   115,   116,   117,   118,   119,   120,
     123,   124,   130,   134,   137,   140,   141,   144,   145,   146,
     147,   152,   153,   154,   155,   156,   159,   160,   161,   162,
     165,   166,   167,   168,   169,   172,   173,   174,   177,   179,
     180,   181,   182,   183,   184,   185,   186
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_BIT_DIREITA", "T_BIT_ESQUERDA",
  "T_ADICAO", "T_SUBTRACAO", "T_MULTIPLICACAO", "T_DIVISAO", "T_RESTO",
  "T_IGUAL", "T_ABRE_PARENTESES", "T_FECHA_PARENTESES", "T_ABRE_CHAVES",
  "T_FECHA_CHAVES", "T_INT", "T_DOUBLE", "T_STRING", "T_VOID", "T_IF",
  "T_WHILE", "T_ELSE", "T_PRINT", "T_READ", "T_RETURN", "T_ID",
  "T_LITERAL", "T_FIM", "T_NUM", "T_VIRGULA", "T_PONTO_E_VIRGULA", "T_AND",
  "T_NOT", "T_OR", "T_TRUE", "T_FALSE", "T_MAIOR_IGUAL", "T_MENOR_IGUAL",
  "T_DIFERENTE", "T_IGUAL_IGUAL", "T_MAIOR", "T_MENOR", "$accept",
  "Programa", "ListaFuncoes", "MZerador", "Funcao", "EscopoFuncaoVazia",
  "EscopoFuncao", "TipoRetorno", "DeclParametros", "Parametro",
  "BlocoPrincipal", "Declaracoes", "Declaracao", "Tipo", "ListaId",
  "Bloco", "ListaCmd", "Comando", "Retorno", "CmdSe", "NLogico",
  "CmdEnquanto", "CmdAtrib", "CmdEscrita", "CmdEscritaMarcador",
  "CmdLeitura", "ChamadaProc", "ChamadaFuncao", "ListaParametros",
  "ExpressaoAritmetica", "TExpressaoAritmetica", "FExpressaoAritmetica",
  "ExpressaoLogica", "MLogico", "FExpressaoLogica", YY_NULLPTR
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

#define YYPACT_NINF -129

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-129)))

#define YYTABLE_NINF -43

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     217,   183,  -129,  -129,  -129,  -129,    44,     9,  -129,     9,
       9,    20,  -129,  -129,  -129,  -129,    43,  -129,  -129,    58,
     124,   218,   183,  -129,    49,   148,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,    51,  -129,   221,  -129,  -129,  -129,
      71,    97,    75,    84,    62,   112,   112,    85,    94,  -129,
    -129,     7,   245,  -129,    13,    65,   128,   120,  -129,   165,
    -129,   -10,  -129,  -129,  -129,  -129,   104,    97,    97,    74,
      73,  -129,    97,   149,    93,  -129,    56,  -129,   112,   112,
     112,   112,  -129,   112,   112,   112,    98,   112,   103,   112,
     106,    11,  -129,  -129,    24,   237,  -129,   102,  -129,  -129,
      26,  -129,   117,    61,    76,  -129,   112,   112,   112,   112,
     112,   112,  -129,  -129,  -129,   132,   131,   206,   121,  -129,
     245,   245,   245,   245,  -129,  -129,  -129,  -129,    22,  -129,
      27,  -129,  -129,  -129,   155,  -129,  -129,   198,  -129,  -129,
     237,   237,   237,   237,   237,   237,   134,    97,    97,  -129,
     129,   139,  -129,  -129,  -129,  -129,   237,  -129,   197,   137,
    -129,  -129,   134,  -129,  -129,   172,   157,  -129,  -129,  -129,
     134,  -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    12,    13,    14,    11,     0,     6,     5,     0,
       0,     0,     3,    23,    24,    25,     0,    78,    52,     0,
       0,     0,     0,    21,     0,     0,    30,    37,    31,    32,
      33,    34,    35,    36,     0,     1,     0,     2,     8,     7,
       0,     0,     0,     0,     0,     0,     0,    73,     0,    72,
      74,     0,    65,    69,     0,     0,     0,     0,    20,     0,
      27,     0,    19,    29,    54,     4,     0,     0,     0,     0,
       0,    77,     0,     0,     0,    71,     0,    39,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,    60,     0,    59,    18,     0,    22,     9,
       0,    16,     0,     0,     0,    79,     0,     0,     0,     0,
       0,     0,    78,    78,    78,     0,     0,     0,     0,    70,
      63,    64,    61,    62,    66,    67,    68,    48,     0,    49,
       0,    45,    44,    55,     0,    26,    10,     0,    17,    80,
      84,    86,    82,    81,    83,    85,     0,     0,     0,    78,
       0,     0,    53,    46,    47,    58,    57,    15,     0,    40,
      75,    76,     0,    51,    50,     0,     0,    43,    28,    78,
       0,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,  -129,   140,  -129,  -129,  -129,  -129,    45,
     241,  -129,   171,   -61,  -129,  -128,   -20,   -24,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,    -1,  -129,   -17,
     166,   -36,   -21,  -106,   -64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,    36,     8,     9,    10,    11,   100,   101,
      12,    22,    23,    24,    61,   159,    25,    26,    27,    28,
     166,    29,    30,    31,    43,    32,    33,    50,    94,    69,
      52,    53,    70,    42,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    63,    59,    51,   105,   102,   146,   147,   148,    75,
      78,    79,    80,    81,    78,    79,    80,    81,    86,    97,
      98,    34,     1,    87,    34,    78,    79,    80,    81,    76,
      78,    79,    80,    81,   167,    63,   133,    82,   136,    91,
      95,   132,   171,   162,    35,    40,   104,   124,   125,   126,
     103,   115,   153,   134,    41,   137,   117,   154,    34,    78,
      79,    80,    81,   170,    78,    79,    80,    81,   119,    44,
     128,    88,   130,   119,    60,    89,   102,    78,    79,    80,
      81,    64,    66,   160,   161,   112,    72,    74,   139,   140,
     141,   142,   143,   144,   145,    73,    57,   106,   107,   108,
     109,   110,   111,    45,   113,   118,   114,   113,    67,   114,
     106,   107,   108,   109,   110,   111,    99,   156,    45,    13,
      14,    15,    47,    46,    77,    49,    45,   135,   127,    68,
      45,    46,    92,   129,    45,    46,   131,    47,   165,    46,
      49,    63,   138,   150,   149,    47,    93,   158,    49,    47,
      48,   152,    49,    47,    90,    45,    49,    34,   -42,   163,
      46,    45,    62,   113,    34,   114,    46,    16,    17,   164,
      18,    19,    20,    21,    47,   116,    65,    49,   169,    96,
      47,   155,   157,    49,    16,    17,   168,    18,    19,    20,
      21,    16,    17,    58,    18,    19,    20,    21,    13,    14,
      15,     0,    16,    17,     0,    18,    19,    20,    21,    78,
      79,    80,    81,    13,    14,    15,    16,    17,   151,    18,
      19,    20,    21,    54,    55,     0,     0,     0,    56,    57,
       1,     0,     2,     3,     4,     5,     2,     3,     4,     5,
      78,    79,    80,    81,   120,   121,   122,   123,    37,     0,
      38,    39,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
       1,    25,    22,    20,    68,    66,   112,   113,   114,    45,
       3,     4,     5,     6,     3,     4,     5,     6,     5,    29,
      30,    22,    13,    10,    25,     3,     4,     5,     6,    46,
       3,     4,     5,     6,   162,    59,    12,    30,    12,    56,
      57,    30,   170,   149,     0,    25,    67,    83,    84,    85,
      67,    72,    30,    29,    11,    29,    73,    30,    59,     3,
       4,     5,     6,   169,     3,     4,     5,     6,    12,    11,
      87,     6,    89,    12,    25,    10,   137,     3,     4,     5,
       6,    30,    11,   147,   148,    12,    11,    25,    12,   106,
     107,   108,   109,   110,   111,    11,    11,    36,    37,    38,
      39,    40,    41,     6,    31,    12,    33,    31,    11,    33,
      36,    37,    38,    39,    40,    41,    12,   134,     6,    15,
      16,    17,    25,    11,    30,    28,     6,    25,    30,    32,
       6,    11,    12,    30,     6,    11,    30,    25,   158,    11,
      28,   165,    25,    12,    12,    25,    26,    13,    28,    25,
      26,    30,    28,    25,    26,     6,    28,   158,    21,    30,
      11,     6,    14,    31,   165,    33,    11,    19,    20,    30,
      22,    23,    24,    25,    25,    26,    36,    28,    21,    14,
      25,    26,   137,    28,    19,    20,    14,    22,    23,    24,
      25,    19,    20,    22,    22,    23,    24,    25,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,     3,
       4,     5,     6,    15,    16,    17,    19,    20,    12,    22,
      23,    24,    25,     5,     6,    -1,    -1,    -1,    10,    11,
      13,    -1,    15,    16,    17,    18,    15,    16,    17,    18,
       3,     4,     5,     6,    78,    79,    80,    81,     7,    -1,
       9,    10,     7,     8,     9
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    15,    16,    17,    18,    43,    44,    46,    47,
      48,    49,    52,    15,    16,    17,    19,    20,    22,    23,
      24,    25,    53,    54,    55,    58,    59,    60,    61,    63,
      64,    65,    67,    68,    69,     0,    45,    52,    52,    52,
      25,    11,    75,    66,    11,     6,    11,    25,    26,    28,
      69,    71,    72,    73,     5,     6,    10,    11,    54,    58,
      25,    56,    14,    59,    30,    46,    11,    11,    32,    71,
      74,    76,    11,    11,    25,    73,    71,    30,     3,     4,
       5,     6,    30,     7,     8,     9,     5,    10,     6,    10,
      26,    71,    12,    26,    70,    71,    14,    29,    30,    12,
      50,    51,    55,    71,    74,    76,    36,    37,    38,    39,
      40,    41,    12,    31,    33,    74,    26,    71,    12,    12,
      72,    72,    72,    72,    73,    73,    73,    30,    71,    30,
      71,    30,    30,    12,    29,    25,    12,    29,    25,    12,
      71,    71,    71,    71,    71,    71,    75,    75,    75,    12,
      12,    12,    30,    30,    30,    26,    71,    51,    13,    57,
      76,    76,    75,    30,    30,    58,    62,    57,    14,    21,
      75,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    46,    46,    47,
      48,    49,    49,    49,    49,    50,    50,    51,    52,    52,
      53,    53,    54,    55,    55,    55,    56,    56,    57,    58,
      58,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    62,    63,    64,    64,    64,    64,    64,    64,
      65,    65,    66,    67,    68,    69,    69,    70,    70,    70,
      70,    71,    71,    71,    71,    71,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    74,    74,    74,    75,    76,
      76,    76,    76,    76,    76,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     1,     0,     2,     2,     4,
       5,     1,     1,     1,     1,     3,     1,     2,     4,     3,
       2,     1,     3,     1,     1,     1,     3,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       6,    10,     0,     7,     4,     4,     5,     5,     4,     4,
       6,     6,     0,     5,     2,     4,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     2,     1,     1,     1,     4,     4,     1,     0,     2,
       3,     3,     3,     3,     3,     3,     3
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
#line 34 "expr.y" /* yacc.c:1646  */
    {writeJasminMain();clearJasmin();}
#line 1404 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 35 "expr.y" /* yacc.c:1646  */
    {writeJasminMain();clearJasmin();}
#line 1410 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 38 "expr.y" /* yacc.c:1646  */
    {writeJasminFunc((yyvsp[0]).tipo,(yyvsp[0]).nomeId, (yyvsp[0]).listaTipo);ShowCmdAscii();clearJasmin();tabelaSimbolosGlobais = criarArvore();}
#line 1416 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 39 "expr.y" /* yacc.c:1646  */
    {writeJasminFunc((yyvsp[0]).tipo,(yyvsp[0]).nomeId, (yyvsp[0]).listaTipo);ShowCmdAscii();clearJasmin();tabelaSimbolosGlobais = criarArvore();}
#line 1422 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 42 "expr.y" /* yacc.c:1646  */
    {funcNargs = 0;}
#line 1428 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 48 "expr.y" /* yacc.c:1646  */
    {createFunction(tabelaSimbolosFuncoes, (yyvsp[-2]).nomeId, (yyvsp[-3]).tipo,funcNargs, NULL);funcNargs = 0;}
#line 1434 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 50 "expr.y" /* yacc.c:1646  */
    {(yyval).tipo = (yyvsp[-4]).tipo; strcpy((yyval).nomeId,(yyvsp[-3]).nomeId); (yyval).listaTipo = createListaTipoIntNVezes(funcNargs);createFunction(tabelaSimbolosFuncoes, (yyvsp[-3]).nomeId, (yyvsp[-4]).tipo,funcNargs,createListaTipoIntNVezes(funcNargs)); funcNargs = 0; }
#line 1440 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 53 "expr.y" /* yacc.c:1646  */
    {(yyval).tipo = INT; }
#line 1446 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 58 "expr.y" /* yacc.c:1646  */
    {  }
#line 1452 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 59 "expr.y" /* yacc.c:1646  */
    { }
#line 1458 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 62 "expr.y" /* yacc.c:1646  */
    {insereArvore(tabelaSimbolosGlobais,(yyvsp[0]).nomeId); funcNargs++;}
#line 1464 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 65 "expr.y" /* yacc.c:1646  */
    {}
#line 1470 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 66 "expr.y" /* yacc.c:1646  */
    {}
#line 1476 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 73 "expr.y" /* yacc.c:1646  */
    {insereListaNaArvore((yyvsp[-1]).listaId, tabelaSimbolosGlobais, (yyvsp[-2]).tipo);}
#line 1482 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 77 "expr.y" /* yacc.c:1646  */
    {(yyval).tipo = INT;}
#line 1488 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 78 "expr.y" /* yacc.c:1646  */
    {(yyval).tipo = DOUBLE;}
#line 1494 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 79 "expr.y" /* yacc.c:1646  */
    {(yyval).tipo = STRING;}
#line 1500 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 82 "expr.y" /* yacc.c:1646  */
    {insereLista((yyvsp[-2]).listaId, (yyvsp[0]).nomeId); (yyval).listaId = (yyvsp[-2]).listaId;}
#line 1506 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 83 "expr.y" /* yacc.c:1646  */
    {(yyval).listaId = criaLista((yyvsp[0]).nomeId);}
#line 1512 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 102 "expr.y" /* yacc.c:1646  */
    {CmdIreturn();}
#line 1518 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 106 "expr.y" /* yacc.c:1646  */
    { LabelUpdate((yyvsp[-3]).listav, (yyvsp[-1]).label); LabelUpdate((yyvsp[-3]).listaf, LabelCreate());  }
#line 1524 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 107 "expr.y" /* yacc.c:1646  */
    {LabelUpdate((yyvsp[-7]).listav, (yyvsp[-5]).label); LabelUpdate((yyvsp[-7]).listaf, (yyvsp[-1]).label); LabelUpdate((yyvsp[-3]).listav, LabelCreate());}
#line 1530 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 110 "expr.y" /* yacc.c:1646  */
    {(yyval).listav = criaIntList(GetIndexPosition()); CmdGOTO();}
#line 1536 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 112 "expr.y" /* yacc.c:1646  */
    {LabelUpdate((yyvsp[-3]).listav, (yyvsp[-1]).label); CmdGOTOLabel((yyvsp[-5]).label); LabelUpdate((yyvsp[-3]).listaf, LabelCreate()); CmdEndWhile();}
#line 1542 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 115 "expr.y" /* yacc.c:1646  */
    {CmdIstore(tabelaSimbolosGlobais, (yyvsp[-3]).nomeId);}
#line 1548 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 117 "expr.y" /* yacc.c:1646  */
    {CmdIload(tabelaSimbolosGlobais, (yyvsp[-4]).nomeId); CmdIadd(); CmdIstore(tabelaSimbolosGlobais, (yyvsp[-4]).nomeId); }
#line 1554 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 118 "expr.y" /* yacc.c:1646  */
    {CmdIload(tabelaSimbolosGlobais, (yyvsp[-4]).nomeId); CmdIneg(); CmdIadd(); CmdIneg(); CmdIstore(tabelaSimbolosGlobais, (yyvsp[-4]).nomeId); }
#line 1560 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 119 "expr.y" /* yacc.c:1646  */
    { CmdIload(tabelaSimbolosGlobais, (yyvsp[-3]).nomeId); CmdBipush(1); CmdIadd(); CmdIstore(tabelaSimbolosGlobais, (yyvsp[-3]).nomeId); }
#line 1566 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 120 "expr.y" /* yacc.c:1646  */
    { CmdIload(tabelaSimbolosGlobais, (yyvsp[-3]).nomeId);  CmdBipush(1); CmdIsub(); CmdIstore(tabelaSimbolosGlobais, (yyvsp[-3]).nomeId); }
#line 1572 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 123 "expr.y" /* yacc.c:1646  */
    {CmdInvokeOutInt();}
#line 1578 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 124 "expr.y" /* yacc.c:1646  */
    {
                                                        CmdLdc((yyvsp[-2]).strg);
                                                        CmdInvokeOutLiteral();
							}
#line 1587 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 130 "expr.y" /* yacc.c:1646  */
    {CmdGetStaticOut();}
#line 1593 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 134 "expr.y" /* yacc.c:1646  */
    { CmdReadInt(tabelaSimbolosGlobais, (yyvsp[-2]).nomeId); }
#line 1599 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 140 "expr.y" /* yacc.c:1646  */
    {CmdInvokeFunction((yyvsp[-3]).nomeId);}
#line 1605 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 152 "expr.y" /* yacc.c:1646  */
    {CmdIadd();}
#line 1611 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 153 "expr.y" /* yacc.c:1646  */
    {CmdIsub();}
#line 1617 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 154 "expr.y" /* yacc.c:1646  */
    {CmdIshr();}
#line 1623 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 155 "expr.y" /* yacc.c:1646  */
    {CmdIshl();}
#line 1629 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 159 "expr.y" /* yacc.c:1646  */
    {CmdImull();}
#line 1635 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 160 "expr.y" /* yacc.c:1646  */
    {CmdIdiv();}
#line 1641 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 161 "expr.y" /* yacc.c:1646  */
    {CmdIrem();}
#line 1647 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 166 "expr.y" /* yacc.c:1646  */
    {CmdIneg();}
#line 1653 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 167 "expr.y" /* yacc.c:1646  */
    {CmdBipush((int)(yyvsp[0]).double_value);}
#line 1659 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 168 "expr.y" /* yacc.c:1646  */
    {CmdIload(tabelaSimbolosGlobais, (yyvsp[0]).nomeId);}
#line 1665 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 172 "expr.y" /* yacc.c:1646  */
    { LabelUpdate((yyvsp[-3]).listav, (yyvsp[-1]).label); (yyval).listaf =  juntarIntList((yyvsp[-3]).listaf, (yyvsp[0]).listaf);  (yyval).listav = (yyvsp[0]).listav;}
#line 1671 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 173 "expr.y" /* yacc.c:1646  */
    { LabelUpdate((yyvsp[-3]).listaf, (yyvsp[-1]).label); (yyval).listav = juntarIntList((yyvsp[-3]).listav, (yyvsp[0]).listav); (yyval).listaf = (yyvsp[0]).listaf; }
#line 1677 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 174 "expr.y" /* yacc.c:1646  */
    { (yyval).listav = (yyvsp[0]).listav; (yyval).listaf = (yyvsp[0]).listaf;}
#line 1683 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 177 "expr.y" /* yacc.c:1646  */
    {(yyval).label = LabelCreate();}
#line 1689 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 179 "expr.y" /* yacc.c:1646  */
    { (yyval).listav = (yyvsp[0]).listaf; (yyval).listaf = (yyvsp[0]).listav; }
#line 1695 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 180 "expr.y" /* yacc.c:1646  */
    { (yyval).listav = (yyvsp[-1]).listav; (yyval).listaf = (yyvsp[-1]).listaf; }
#line 1701 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 181 "expr.y" /* yacc.c:1646  */
    { (yyval).listav =  criaIntList(GetIndexPosition()); (yyval).listaf = criaIntList(GetIndexPosition()+1); CmdIfEQ(); CmdGOTO();}
#line 1707 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 182 "expr.y" /* yacc.c:1646  */
    { (yyval).listav =  criaIntList(GetIndexPosition()); (yyval).listaf = criaIntList(GetIndexPosition()+1); CmdIfNE(); CmdGOTO();}
#line 1713 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 183 "expr.y" /* yacc.c:1646  */
    { (yyval).listav =  criaIntList(GetIndexPosition()); (yyval).listaf = criaIntList(GetIndexPosition()+1); CmdIfGT(); CmdGOTO();}
#line 1719 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 184 "expr.y" /* yacc.c:1646  */
    { (yyval).listav =  criaIntList(GetIndexPosition()); (yyval).listaf = criaIntList(GetIndexPosition()+1); CmdIfGE(); CmdGOTO();}
#line 1725 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 185 "expr.y" /* yacc.c:1646  */
    { (yyval).listav =  criaIntList(GetIndexPosition()); (yyval).listaf = criaIntList(GetIndexPosition()+1); CmdIfLT(); CmdGOTO();}
#line 1731 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 186 "expr.y" /* yacc.c:1646  */
    { (yyval).listav =  criaIntList(GetIndexPosition()); (yyval).listaf = criaIntList(GetIndexPosition()+1); CmdIfLE(); CmdGOTO();}
#line 1737 "expr.tab.c" /* yacc.c:1646  */
    break;


#line 1741 "expr.tab.c" /* yacc.c:1646  */
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
#line 194 "expr.y" /* yacc.c:1906  */

#include "lex.yy.c"

int yyerror (char *str)
{
	printf("[Linha%d] - %s - antes %s\n", __linha__,str, yytext);

}

int yywrap()
{
	return 1;
}
