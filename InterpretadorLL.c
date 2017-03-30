/*****************************************************************
* Interpretador de expressoes LL(1)                              *
* Exemplo p/ Disciplina de Compiladores                          *
* Cristiano Damiani Vasconcellos,                                *
******************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

/* Nao terminais o bit mais significativo ligado indica que se trata de um nao
terminal */
#define EXPR   0x8001
#define EXPRL  0x8002
#define TERMO  0x8003
#define TERMOL 0x8004
#define FATOR  0x8005

/* Terminais */
#define ERRO 	0x0000
#define AD     0x0100
#define SUB 	0X0200
#define MUL    0x0300
#define DIV		0x0400
#define CONST  0x0500
#define APAR   0x0600
#define FPAR   0x0700
#define FIM    0x0800

/* Regras semanticas, o segundo bit mais significativo ligado indica
que se  trata de uma regra semantica*/
#define R_ET    0x4001
#define R_EEL   0x4002
#define R_ELAT  0x4003
#define R_ELST  0x4004
#define R_ELV   0x4005
#define R_TF    0x4006
#define R_TTL   0x4007
#define R_TLMF  0x4008
#define R_TLDF  0x4009
#define R_TLV   0x400A
#define R_FC    0x400B
#define R_FAP   0x400C
#define R_FFP   0x400D
#define R_CMD 	 0x400E

//Mascaras
#define TERM     0xC000
#define NTER     0x8000
#define NNTER    0x7FFF
#define ATRIB    0x00FF
#define REGRA    0x4000

//Limites
#define TAMPILHA 100
#define TAMSTR   100

struct Pilha
{
	int topo;
	int dado[TAMPILHA];
};

struct PilhaDouble
{
	int topo;
	double dado[TAMPILHA];
};

struct Lista
{
	double cons;
	struct Lista *prox;
};

// cabeca da lista da tabela de simbolos
struct Lista *cabTab = NULL;

/* Producoes a primeira posicao do vetor indica quantos simbolos
gramaticais a producao possui em seu lado direito */

const int PROD1[] = {4, TERMO, R_ET, EXPRL, R_EEL};      // E  -> TE'
const int PROD2[] = {4, AD, TERMO, R_ELAT, EXPRL};       // E' -> +TE'
const int PROD3[] = {4, SUB, TERMO, R_ELST, EXPRL};      // E' -> -TE'
const int PROD4[] = {1, R_ELV};                          // E' -> vazio
const int PROD5[] = {4, FATOR, R_TF, TERMOL, R_TTL};     // T  -> FT'
const int PROD6[] = {4, MUL, FATOR, R_TLMF, TERMOL};     // T' -> *FT'
const int PROD7[] = {4, DIV, FATOR, R_TLDF, TERMOL};     // T' -> /FT'
const int PROD8[] = {1, R_TLV};                          // T' -> vazio
const int PROD9[] = {2, CONST, R_FC};                    // F  -> const
const int PROD10[]= {5, APAR, R_FAP, EXPR, FPAR, R_FFP}; // F  -> (E)

// vetor utilizado para mapear um numero e uma producao.
const int *PROD[] = {NULL, PROD1, PROD2, PROD3, PROD4, PROD5, PROD6, PROD7, PROD8, PROD9, PROD10};

// Tabela sintatica LL(1). Os numeros correspondem as producoes acima.
const int STAB[5][8] = {{0, 0, 0, 0, 1, 1, 0, 0},
								{ 2, 3, 0, 0, 0, 0, 4, 4},
								{ 0, 0, 0, 0, 5, 5, 0, 0},
								{ 8, 8, 6, 7, 0, 0, 8, 8},
								{ 0, 0, 0, 0, 9,10, 0, 0}};


/*****************************************************************
* int insereTabela(double cons)                                  *
* insere a constante cons na tabela de simbolos, retorna a posi- *
* cao onde a constante foi adicionada. Se a constante ja esta ar *
* mazenada apenas retorna a posicao.                             *  					  *
* Variaveis Globais que altera: cabTab                           *
******************************************************************/

int insereTabela(double cons)
{
	struct Lista *p;
	int pos = 1;

	if (cabTab == NULL)
	{
		cabTab = (struct Lista*) malloc(sizeof(struct Lista));
		if (cabTab == NULL)
		{
			printf("Memoria insuficiente");
			exit(1);
		}
		cabTab->cons = cons;
		cabTab->prox = NULL;
		return 1;
	}
	p = cabTab;
	while (p->prox)
	{
		if (p->cons == cons)
			return pos;
		pos++;
		p = p->prox;
	}
	p->prox = (struct Lista *) malloc(sizeof(struct Lista));
	if (cabTab == NULL)
	{
		printf("Memoria insuficiente");
		exit(1);
	}
	pos++;
	p = p->prox;
	p->cons = cons;
	p->prox = NULL;
	return pos;
}

/*****************************************************************
* double consultaTabela(int pos)                                 *
* retorna ao valor armazenado na posicao pos da tabela de simbo- *
* los.                                                           *
* Variaveis Globais que consulta: cabTab                         *
******************************************************************/
double consultaTabela(int pos)
{
	struct Lista *p = cabTab;
	int i = 1;

	while (p != NULL)
	{
		if (i == pos)
			return p->cons;
		i++;
		p = p->prox;
	}
	printf ("Erro na tabela de simbolos");
	exit(1);
}

/*****************************************************************
* void liberaTabela()                                            *
* Libera area de memoria alocada para tabela de simbolos         *
* Variaveis Globais que altera: cabTab                           *
******************************************************************/

void liberaTabela()
{
	struct Lista *p1, *p2;

	p1 = cabTab;
	while (p1)
	{
		p2 = p1->prox;
		free (p1);
		p1 = p2;
	}
	cabTab = NULL;
}



/*****************************************************************
* int lex (char *str, int *pos)                                  *
* procura o proximo token dentro de str a partir de *pos,incre-  *
* menta o valor de *pos a medida que faz alguma tranzicao de     *
* estados.                                                       *
* Retorna o inteiro que identifica o token encontrado.           *
******************************************************************/

int lex (char *str, int *pos)
{
	int estado = 0, pos_t = 0;
	char c;
	char token[TAMSTR];

	while (1)
	{
		token[pos_t] = c = str[*pos];
		pos_t++;
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
						token[pos_t] = '\0';
						return CONST+insereTabela(atof(token));
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
					token[pos_t] = '\0';
					return CONST+insereTabela(atof(token));
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

void inicializa(struct Pilha *p)
{
	p->topo = -1;
}

/*****************************************************************
* void empilha (struct PilhaDouble *p, double elemento)          *
* Insere o valor de elemento no topo da pilha apontada por p.    *
******************************************************************/

void empilha (struct Pilha *p, int elemento)
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
* void empilha (struct PilhaDouble *p, double elemento           *
* Insere o valor de elemento no topo da pilha apontada por p.    *
******************************************************************/

void empilhaDouble (struct PilhaDouble *p, double elemento)
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
* int desempilha (struct Pilha *p)                                  *
* Remove e retorna o valor armazenado no topo da pilha apontada  *
* por p                                                          *
******************************************************************/

int desempilha (struct Pilha *p)
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
* double desempilhaDouble (struct PilhaDouble *p)                *
* Remove e retorna o valor armazenado no topo da pilha apontada  *
* por p                                                          *
******************************************************************/

double desempilhaDouble (struct PilhaDouble *p)
{
	double aux;

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
* void acao (int regra, int atrib)                               *
* Executa a regra semantica identificada por regra, atrib identi-*
* fica a entrada na tabela de simbolos do token analisado, quando*
* eh o caso.                                                     *
* Variaveis Globais Consultadas:                                 *
******************************************************************/


void acao (int regra, int atrib)
{
	static double E, T, F, Elh, Els, Tlh, Tls;
	static struct PilhaDouble Parent = {-1};

	switch (regra)
	{
		case R_ET:
				Elh = T;
				break;
		case R_EEL:
				E = Els;
				break;
		case R_ELAT:
				//printf("\n%lf + %lf", Elh, T);
				Elh = Elh + T;
				break;
		case R_ELST:
				//printf("\n%lf - %lf", Elh, T);
				Elh = Elh - T;
				break;
		case R_ELV:
				Els = Elh;
				break;
		case R_TF:
				Tlh = F;
				break;
		case R_TTL:
				T = Tls;
				break;
		case R_TLMF:
				//printf("\n%lf * %lf", Tlh, F);
				Tlh = Tlh * F;
				break;
		case R_TLDF:
				//printf("\n%lf / %lf", Tlh, F);
				Tlh = Tlh / F;
				break;
		case R_TLV:
				Tls = Tlh;
				break;
		case R_FAP:
				empilhaDouble(&Parent, Tlh);
				empilhaDouble(&Parent, Elh);
				break;
		case R_FFP:
				Elh = desempilhaDouble(&Parent);
				Tlh = desempilhaDouble(&Parent);
				F = E;
				break;
		case R_FC:
				F = consultaTabela(atrib);
				break;
		case R_CMD:
				printf("=%lf\n", E);
				break;
		default:
				printf ("acao: Acao invalida");
				exit (1);
	}
}



/*****************************************************************
* void parser (char *expr)                                       *
* Verifica se a string apontada por expr esta sintaticamente     *
* correta.                                                       *
* Variaveis Globais Consultadas: STAB e PROD                     *
******************************************************************/


void parser(char *expr)
{
	struct Pilha pilha;
	int x, a, atrib, nProd, i, *producao;
	int pos = 0;

	inicializa(&pilha);
	empilha(&pilha, FIM);
	empilha(&pilha, EXPR);
	if ((a = lex(expr, &pos)) == ERRO)
		erro("Erro lexico", expr, pos);
	do
	{
		x = consulta(&pilha);
		if (x&REGRA) //Regra semantica
		{
			desempilha(&pilha);
			acao (x, atrib);
		}
		if ((x&TERM) == 0) //Terminal
		{
			if (x == (a&~ATRIB))
			{
				desempilha (&pilha);
				atrib = a&ATRIB;
				if ((a = lex(expr, &pos)) == ERRO)
					erro("Erro lexico", expr, pos);
			}
			else
				erro("Erro sintatico",expr, pos);
		}
		if (x&NTER) //Nao terminal
		{
			nProd = STAB[(x&NNTER)-1][(a>>8) - 1];
			if (nProd)
			{
				desempilha (&pilha);
				producao = PROD[nProd];
				for (i = producao[0]; i > 0; i--)
					empilha (&pilha, producao[i]);
			}
			else
				erro ("Erro sintatico", expr, pos);
		}
	} while (x != FIM);
	acao(R_CMD, 0);
}

void main()
{
	char expr[TAMSTR];

	printf("\nDigite uma expressao: ");
	gets(expr);
	parser(expr);
	liberaTabela();
}
