#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Tokens
#define ERRO 	0x0000
#define ADD    0x0100
#define SUB		0x0200
#define MUL 	0x0300
#define DIV 	0x0400
#define CONST  0x0500
#define APAR	0x0600
#define FPAR	0x0700
#define FIM		0x0800

/*****************************************************************
* int lex (char *str, int *pos)                                  *
* procura o proximo token dentro de str a partir de *pos,incre-  *
* menta o valor de *pos a medida que faz alguma tranzicao de     *
* estados.                                                       *
* Retorna o inteiro que identifica o token encontrado.           *
******************************************************************/

int lex (char *str, int *pos)
{
	int estado = 0;
	char c;

	while (1)
	{
		c =  str[*pos];

		switch(estado)
		{
			case 0:
				if (isdigit(c))
				{
					(*pos)++;
					estado = 1;
				}
				else
					switch (c)
					{
						case ' ':
							(*pos)++;
							break;
						case '.':
								(*pos)++;
								estado = 2;
								break;
						case '+':
								(*pos)++;
								return ADD;
						case '-':
								(*pos)++;
								return SUB;
						case '*':
								(*pos)++;
								return MUL;
						case '/':
								(*pos)++;
								return DIV;
						case '(':
								(*pos)++;
								return APAR;
						case ')':
								(*pos)++;
								return FPAR;
						case '\0':
								return FIM;
						default:
								(*pos)++;
								return ERRO;
					}
					break;
			case 1:
				if(isdigit(c))
					(*pos)++;
				else
					if (c == '.')
					{
						estado = 3;
						(*pos)++;
					}
					else
					{
						//Adicionar constante na tabela de simbolos.
						return CONST;
					}
					break;
			case 2:
				if (isdigit(c))
				{
					(*pos)++;
					estado = 3;
				}
				else
				{
					(*pos)++;
					return ERRO;
				}
				break;
			case 3:
				if (isdigit(c))
					(*pos)++;
				else
				{
					//Adicionar a constante na tabela de simbolos.
					return CONST;
				}
				break;
			default:
					printf("Lex:Estado indefinido");
					exit(1);
		}
	}
}

int main()
{
	char str[50];
	int token, pos = 0;


	printf("\nDigite uma expressao:");
	gets(str);
	do
	{
		token = lex(str, &pos);
		switch (token)
		{
			case CONST:
					printf("const");
					break;
			case ADD:
					printf("+");
					break;
			case SUB:
					printf("-");
					break;
			case MUL:
					printf("*");
					break;
			case DIV:
					printf("/");
					break;
			case APAR:
					printf("(");
					break;
			case FPAR:
					printf(")");
					break;
			case ERRO:
					printf("Erro");
					break;
		}
	} while (token != FIM);
	
	return 0;
}










