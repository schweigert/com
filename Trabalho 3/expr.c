#include <stdio.h>
#include "eda.h"
#include "cmd.h"
extern FILE *yyin;
extern struct arvore* tabelaSimbolosGlobais;


int main(int c, char *argv[])
{
  	FILE * file;
  	file = fopen (argv[1], "r");
  	if (file == NULL){
  		printf("FILE NOT FOUND\n");
  		return 0;
  	}
  tabelaSimbolosGlobais = criarArvore();
	yyin = file;
	yyparse();
  printArvore(tabelaSimbolosGlobais);
  showCmd();
  ShowCmdAscii();
	return 0;
}
