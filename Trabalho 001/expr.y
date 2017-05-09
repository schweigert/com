%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
%}

%token T_ADICAO T_SUBTRACAO T_MULTIPLICACAO T_DIVISAO T_IGUAL T_ABRE_PARENTESES T_FECHA_PARENTESES T_ABRE_CHAVES T_FECHA_CHAVES T_INT T_STRING T_VOID T_IF T_ELSE T_PRINT T_READ T_RETURN T_ID T_LITERAL T_FIM T_NUM T_VIRGULA T_PONTO_E_VIRGULA

%%
Programa : ListaFuncoes BlocoPrincipal TFIM
	| BlocoPrincipal TFIM
	;

ListaFuncoes : ListaFuncoes Funcao
	| Funcao
	;

Funcao : TipoRetorno T_ID T_ABRE_PARENTESES DeclParametros T_FECHA_PARENTESES BlocoPrincipal
	| TipoRetorno T_ID T_ABRE_PARENTESES T_FECHA_PARENTESES BlocoPrincipal
	;

TipoRetorno : T_VOID
	| T_INT
	| T_STRING
	;

DclParametros : DclParametros T_VIRGULA Parametro
	| Parametro
	;

Parametro : Tipo T_ID
	;

BlocoPrincipal : T_ABRE_CHAVES Declaracoes ListaCmd T_FECHA_CHAVES
	| T_ABRE_CHAVES ListaCmd T_FECHA_CHAVES
	;

Declaracoes : Declaracoes Declaracao
	| Declaracao
	;

Declaracao : Tipo ListaId T_PONTO_E_VIRGULA
	;

Tipo : T_INT
	| T_STRING
	;

ListaId : ListaId T_VIRGULA T_ID
	| ID
	;

Bloco : T_ABRE_CHAVES ListaCmd T_FECHA_CHAVES
	;

ListaCmd : ListaCmd Comando
	| Comando
	;

Comando : CmdSe
	| CmdEnquanto
	| CmdAtrib
	| CmdEscrita
	| CmdLeitura
	| ChamadaProc
	| Retorno
	;

Retorno : T_RETURN ExpressaoAritmetica T_PONTO_E_VIRGULA
	| T_RETURN T_LITERAL T_PONTO_E_VIRGULA
	;

CmdSe : T_IF T_ABRE_PARENTESES ExpressaoLogica T_FECHA_PARENTESES Bloco
	| T_IF T_ABRE_PARENTESES ExpressaoLogica T_FECHA_PARENTESES Bloco T_ELSE Bloco
	;

CmdEnquanto : T_WHILE T_ABRE_PARENTESES ExpressaoLogica T_FECHA_PARENTESES Bloco
	;

CmdAtrib : T_ID T_IGUAL ExpressaoAritmetica T_PONTO_E_VIRGULA
	| T_ID T_IGUAL T_LITERAL T_PONTO_E_VIRGULA
	;

CmdEscrita : T_PRINT T_ABRE_PARENTESES ExpressaoAritmetica T_FECHA_PARENTESES T_PONTO_E_VIRGULA
	| T_PRINT T_ABRE_PARENTESES T_LITERAL T_FECHA_PARENTESES T_PONTO_E_VIRGULA
	;

CmdLeitura : T_READ T_ABRE_PARENTESES T_ID T_FECHA_PARENTESES T_PONTO_E_VIRGULA
	;

ChamadaProc :  ChamadaFuncao T_PONTO_E_VIRGULA
	;

ChamadaFuncao : T_ID T_ABRE_PARENTESES ListaParametros T_FECHA_PARENTESES
	| T_ID T_ABRE_PARENTESES T_FECHA_PARENTESES
	;

ListaParametros : ListaParametros T_VIRGULA ExpressaoAritmetica
	| ListaParametros T_VIRGULA T_LITERAL
	| ExpressaoAritmetica
	| T_LITERAL


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