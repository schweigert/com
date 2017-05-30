#include <stdio.h>

extern FILE *yyin;



int main(int c, char *argv[])
{
  	FILE * file;
  	file = fopen (argv[1], "r");
  	if (file == NULL){
  		printf("FILE NOT FOUND\n");
  		return 0;
  	}
	yyin = file;
	yyparse();
	return 0;
}
