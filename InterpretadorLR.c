/*****************************************************************
* Interpretador LR(1)                                            *
* Exemplo p/ Disciplina de Compiladores PUC PR                   *
* Cristiano Damiani Vasconcellos                                 *
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Terminais  Byte mais significativo indica qual o terminal,
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
#define ATRIB 0x00FF

// Limites
#define TAMPILHA 100
#define TAMSTR   100

struct Pilha {
	int topo;
	int dado[TAMPILHA];
	double val[TAMPILHA];
};

struct Lista
{
	double cons;
	struct Lista *prox;
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
								  { 0,  0,  0},
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
const int REDUCAO[8][2] = {{EXPR,  3}, // E -> E + T reducao 1
						   {EXPR,  3}, // E -> E - T reducao 2
						   {EXPR,  1}, // E -> T     reducao 3
						   {TERMO, 3}, // T -> T * F reducao 4
						   {TERMO, 3}, // T -> T / F reducao 5
						   {TERMO, 1}, // T -> F     reducao 6
						   {FATOR, 1}, // F -> const reducao 7
						   {FATOR, 3}};// F -> (E)   reducao 8

// cabeca da lista da tabela de simbolos
struct Lista *cabTab = NULL;


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
* void empilha (struct Pilha *p, int elemento                     *
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
* int desempilha (struct Pilha *p)                               *
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
/******************************************************************
* void acao (struct Pilha *p, int red, int atrib)                 *
* Executa a reducao correspondente a reducao numero red. atrib    *
* contem ultimo token avaliado.                                   *
* Variaveis Locais Consultadas: REDUCAO                           *
*******************************************************************/

void acao(struct Pilha *p, int red, int atrib)
{
	int ntopo = p->topo - REDUCAO[red-1][1] + 1;

	switch (red)
	{
		case 1: // E -> E + T
				//printf("%lf + %lf\n", p->val[p->topo-2], p->val[p->topo]);
				p->val[ntopo] = p->val[p->topo-2] + p->val[p->topo];
				break;
		case 2: // E -> E - T
				//printf("%lf - %lf\n", p->val[p->topo-2], p->val[p->topo]);
				p->val[ntopo] = p->val[p->topo-2] - p->val[p->topo];
				break;
		case 3:
				break;
		case 4: // T -> T * F
				//printf("%lf * %lf\n", p->val[p->topo-2], p->val[p->topo]);
				p->val[ntopo] = p->val[p->topo-2] * p->val[p->topo];
				break;
		case 5: // T -> T / F
				//printf("%lf / %lf\n", p->val[p->topo-2], p->val[p->topo]);
				p->val[ntopo] = p->val[p->topo-2] / p->val[p->topo];
				break;
		case 6:
				break;
		case 7: // T -> const
				p->val[ntopo] = consultaTabela(ATRIB&atrib);
				break;
		case 8: // T -> (E)
				p->val[ntopo] = p->val[p->topo-1];
				break;
		default:
				printf("Reducao invalida");
				exit(1);
	}
}

/*****************************************************************
* reduzir(struct Pilha *p, int a, int atrib)                     *
* Remove da pilha n estados, o valor de n eh o numero de simbolos*
* senteciais que a producao de numero a possui. Este valor esta  *
* armazenado em REDUCOES[NRED&a-1][1], onde NRED e uma mascara   *
* de bits com o bit mais significativo ligado.                   *
* atrib contem o ultimo token avaliado que eh passado para a fun-*
* cao acao para que a tabela de simbolos seja consultada no caso *
* de um token const ser reduzido.                                *
* Retorna o inteiro correspondente ao nao-terminal para o qual   *
* o handle foi reduzido.                                         *
* Variaveis Globais Consultadas: REDUCOES                        *
******************************************************************/

int reduzir(struct Pilha *p, int a, int atrib)
{
	int i, red;

	red = NRED&a;
	acao (p, red, atrib);
	for (i = 0; i < REDUCAO[red-1][1]; i++)
		desempilha(p);
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
	int token, lookahead, s, aux, nter, pos;

	inicializa(&p);
	pos = 0;
	s = 0;
	empilha(&p, 0);
	token = lex(expr, &pos);
	lookahead = token;
	while(1)
	{
		s = consulta(&p);
		if (ACAO[s][(lookahead>>8)-1] == ERRO)
			erro("Erro sintatico", expr, pos);
		if ((RED & ACAO[s][(lookahead>>8)-1]) == 0) //Transicao de estado
		{
			empilha(&p, ACAO[s][(lookahead>>8)-1]);
			token = lookahead;
			lookahead = lex(expr, &pos);
			if (token == ERRO)
				erro("Token invalido", expr, pos);
		}
		else // Reducao
		{
			if (ACAO[s][(lookahead>>8)-1] == ACC)
				break;
			nter = reduzir(&p, ACAO[s][(lookahead>>8)-1], token);
			aux = consulta(&p);
			empilha(&p, DESVIO[aux][nter-1]);
		}
	}
	printf("=%lf\n", p.val[1]);
	liberaTabela();
}

void main()
{
	char expr[100];

	printf("\nDigite uma expressao: ");
	gets(expr);
	parser(expr);
	printf("Expressao sintaticamente correta");
}
