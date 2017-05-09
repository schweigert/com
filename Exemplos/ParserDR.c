/* Analisador sintatico descendente recusivo para expressoes infixas.
Gramatica:
S  ->E#
E  ->TE'
E' ->+TE'
     |-TE'
     |vazio
T  ->FT'
T' ->*FT'
     |/FT'
     |vazio
F  ->(E)
     |CONST */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

#define ERRO 	0x0000
#define CONST 	0x0100
#define AD	0x0200
#define SUB	0x0300
#define MUL 	0x0400
#define DIV 	0x0500
#define APAR	0x0600
#define FPAR	0x0700
#define FIM	0x0800


void expr();
void exprl();
void termo();
void termol();
void fator();
void reconhecer(int);
void erro();

char str[50];
int  pos = 0;
int lookahead;

void partida()
{
	expr();
	reconhecer(FIM);
}

void expr()
{
	termo();
	exprl();
}
void exprl()
{
	if (lookahead == AD)
	{
		reconhecer(AD);
		termo();
		exprl();
	}
	else
		if(lookahead == SUB)
		{
			reconhecer(SUB);
			termo();
			exprl();
		}
}
void termo()
{
	fator();
	termol();
}
void termol()
{
	if (lookahead == MUL)
	{
		reconhecer(MUL);
		fator();
		termol();
	}
	else
		if (lookahead == DIV)
		{
			reconhecer(DIV);
			fator();
			termol();
		}
}
void fator()
{
	if (lookahead == APAR)
	{
		reconhecer(APAR);
		expr();
		reconhecer(FPAR);
	}
	else
		if (lookahead == CONST)
			reconhecer(CONST);
		else
			erro();
}
void reconhecer(int token)
{
	if (lookahead == token)
		lookahead = lex(str, &pos);
	else
		erro();
}

void erro()
{
	int i;

	puts(str);
	for (i = 0; i < pos; i++)
		putch(' ');
	putch('^');
	exit(1);
}

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
								return AD;
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
	printf("Expressao:");
	gets(str);
	lookahead = lex(str, &pos);
	partida();
	printf("Expressao Correta");

}