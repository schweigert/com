#include <stdio.h>
#include "eda.h"
#include "cmd.h"
#include "expr.tab.h"
extern FILE *yyin;
extern struct arvore* tabelaSimbolosGlobais;
extern struct arvore* tabelaSimbolosFuncoes;

int main(int c, char *argv[])
{
  FILE * file;
  file = fopen (argv[1], "r");
  printf("Source: %s\n\n", argv[1]);
  if (file == NULL){
  	printf("FILE NOT FOUND\n");
  	return -1;
  }

  writeJasminInit(argv[1]);
  writeJasminBody();
  tabelaSimbolosGlobais = criarArvore();
  tabelaSimbolosFuncoes = criarArvore();

	yyin = file;
	yyparse();
  printf("\n\tFunctional Tree:\n");
  printArvore(tabelaSimbolosFuncoes);
  printf("\n\tMain Tree:\n");
  printArvore(tabelaSimbolosGlobais);
  showFunctionTable();
  showCmd();
  showLiteralTable();
  ShowCmdAscii();
  writeJasminExit();

  callJasmin();

  return 0;
}
