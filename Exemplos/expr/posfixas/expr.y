%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
%}

%token TADD TMUL TSUB TDIV TAPAR TFPAR TNUM TFIM

%%
Linha :Expr TFIM {printf("Resultado:%lf\n", $1);exit(0);}
	;
Expr: Expr Expr TADD {$$ = $1 + $2;}
	| Expr Expr TSUB {$$ = $1 - $2;}
	| Expr Expr TMUL {$$ = $1 - $2;}
	| Expr Expr TDIV {$$ = $1 - $2;}
	| TNUM
	;
%%
#include "lex.yy.c"

int yyerror (char *str)
{
	printf("%s - antes %s\n", str, yytext);

}

int yywrap()
{
	return 1;
}
