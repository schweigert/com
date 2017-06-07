#include <stdio.h>
#include "eda.h"
#include "cmd.h"
extern FILE *yyin;
extern struct arvore* tabelaSimbolosGlobais;


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
	yyin = file;
	yyparse();

  printArvore(tabelaSimbolosGlobais);
  showCmd();
  ShowCmdAscii();
  writeJasminExit();

  callJasmin();

  return 0;
}
