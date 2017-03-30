/*****************************************************************
* Analisador Sintatico LR(1)                                     *
* Exemplo p/ Disciplina de Compiladores                          *
* Cristiano Damiani Vasconcellos                                 *
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/*Terminais  Byte mais significativo indica qual o terminal,
  byte menos significatico reservado para indicar a ebtrada
  na tabela de simbolos das constantes */
#define ERRO 	0x0000
#define AD     0x0100
#define SUB 	0X0200
#define MUL    0x0300
#define DIV		0x0400
#define CONST  0x0500
#define APAR   0x0600
#define FPAR   0x0700
#define FIM    0x0800


#define ACC	  0xFFFF

// Nao terminais bit mais significativo ligado indica
#define EXPR  1
#define TERMO 2
#define FATOR 3

// Mascaras
#define RED	  0x8000
#define NRED  0x7FFF

#define TAMPILHA 100

struct Pilha {
	int topo;
	int dado[TAMPILHA];
};

// Tabela sintatica

const unsigned int ACAO[16][8] ={{    0,     0,     0,     0,     4,     5,     0,     0},
											{    6,     7,     0,     0,     0,     0,     0,   ACC},
											{RED|3, RED|3,     8,     9,     0,     0, RED|3, RED|3},
											{RED|6, RED|6, RED|6, RED|6,     0,     0, RED|6, RED|6},
											{RED|7, RED|7, RED|7, RED|7,     0,     0, RED|7, RED|7},
											{    0,     0,     0,     0,     4,     5,     0,     0},
											{    0,     0,     0,     0,     4,     5,     0,     0},
											{    0,     0,     0,     0,     4,     5,     0,     0},
											{    0,     0,     0,     0,     4,     5,     0,     0},
											{    0,     0,     0,     0,     4,     5,     0,     0},
											{    6,     7,     0,     0,     0,     0,    15,     0},
											{RED|1, RED|1,     8,     9,     0,     0, RED|1, RED|1},
											{RED|2, RED|2,     8,     9,     0,     0, RED|2, RED|2},
											{RED|4, RED|4, RED|4, RED|4,     0,     0, RED|4, RED|4},
											{RED|5, RED|5, RED|5, RED|5,     0,     0, RED|5, RED|5},
											{RED|8, RED|8, RED|8, RED|8,     0,     0, RED|8, RED|8}};

const unsigned int DESVIO[16][3]={{1, 2, 3},
											{ 0,  0,  0},
											{ 0,  0,  0},
											{ 0  ,  0,  0},
											{ 0,  0,  0},
											{10,  2,  3},
											{ 0, 11,  3},
											{ 0, 12,  3},
											{ 0,  0, 13},
											{ 0,  0, 14},
											{ 0,  0,  0},
											{ 0,  0,  0},
											{ 0,  0,  0},
											{ 0,  0,  0},
											{ 0,  0,  0},
											{ 0,  0,  0}};

// Tabela de reducoes
const int REDUCAO[8][2] = {{EXPR, 3},  // E -> E + T reducao 1
									{EXPR, 3},  // E -> E - T reducao 2
									{EXPR, 1},  // E -> T     reducao 3
									{TERMO, 3}, // T -> T * F reducao 4
									{TERMO, 3}, // T -> T / F reducao 5
									{TERMO, 1}, // T -> F     reducao 6
									{FATOR, 1}, // F -> const reducao 7
									{FATOR, 3}};// F -> (E)   reducao 8


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

/*****************************************************************
* void erro (char *erro, char *expr, int pos)                    *
* imprime a mensagem apontado por erro, a expressao apontada por *
* expr, e uma indicacao de que o erro ocorreu na posicao pos de  *
* expr. Encerra a execucao do programa.                          *
******************************************************************/

void erro (char *erro, char *expr, int pos)
{
	int i;
	printf("%s", erro);
	printf("\n%s\n", expr);
	for (i = 0; i < pos-1; i++)
		putchar(' ');
	putchar('^');
	exit(1);
}
/*****************************************************************
* void inicializa(struct Pilha *p)                               *
* inicializa o topo da pilha em -1, valor que indica que a pilha *
* esta vazia.                                                    *
******************************************************************/

void iniciliza(struct Pilha *p)
{
	p->topo = -1;
}

/*****************************************************************
* void insere (struct Pilha *p, int elemento                     *
* Insere o valor de elemento no topo da pilha apontada por p.    *
******************************************************************/

void insere (struct Pilha *p, int elemento)
{
	if (p->topo < TAMPILHA)
	{
		p->topo++;
		p->dado[p->topo] = elemento;
	}
	else
	{
		printf("estouro de pilha");
		exit (1);
	}
}
/*****************************************************************
* int remover (struct Pilha *p)                                  *
* Remove e retorna o valor armazenado no topo da pilha apontada  *
* por p                                                          *
******************************************************************/

int remover (struct Pilha *p)
{
	int aux;

	if (p->topo >= 0)
	{
		aux = p->dado[p->topo];
		p->topo--;
		return aux;
	}
	else
	{
		printf("Pilha vazia");
		exit(1);
	}
	return 0;
}

/*****************************************************************
* int consulta (struct Pilha *p)                                 *
* Retorna o valor armazenado no topo da pilha apontada por p     *
******************************************************************/


int consulta (struct Pilha *p)
{
	if (p->topo >= 0)
		return p->dado[p->topo];
	printf("Pilha vazia");
	exit(1);
}

/*****************************************************************
* reduzir(struct Pilha *p, int a)                                *
* Remove da pilha n estados, o valor de n e u numero de simbolos *
* senteciais que a producao de numero a possui. Este valor esta  *
* armazenado em REDUCOES[NRED&a-1][1], onde NRED e uma mascara   *
* de bits com o bit mais significativo ligado.                   *
* Retorna o inteiro correspondente ao nao-terminal para o qual   *
* o handle foi reduzido.                                         *
* Variaveis Globais Consultadas: REDUCOES                        *
******************************************************************/

int reduzir(struct Pilha *p, int a)
{
	int i;

	for (i = 0; i < REDUCAO[NRED&a-1][1]; i++)
		remover(p);
	return REDUCAO[NRED&a-1][0];
}

/*****************************************************************
* void parser (char *expr)                                       *
* Verifica se a string apontada por expr esta sintaticamente     *
* correta.                                                       *
* Variaveis Globais Consultadas: ACAO e DESVIO                   *
******************************************************************/

void parser(char *expr)
{
	struct Pilha p;
	int a, s, aux, nter, pos;

	iniciliza(&p);
	pos = 0;
	s = 0;
	insere(&p, 0);
	a = lex(expr, &pos);

	do
	{
		s = consulta(&p);
		if (ACAO[s][(a>>8)-1] == 0)
			erro("Erro sintatico", expr, pos);
		if ((RED & ACAO[s][(a>>8)-1]) == 0)
		{
			insere(&p, ACAO[s][(a>>8)-1]);
			a = lex(expr, &pos);
			if (a == ERRO)
				erro("Token invalido", expr, pos);
		}
		else
		{
			nter = reduzir(&p, ACAO[s][(a>>8)-1]);
			aux = consulta(&p);
			insere(&p, DESVIO[aux][nter-1]);
		}
	} while (ACAO[s][(a>>8)-1] != ACC);
}

void main()
{
	char expr[100];

	printf("\nDigite uma expressao: ");
	gets(expr);
	parser(expr);
	printf("Ok");
}


