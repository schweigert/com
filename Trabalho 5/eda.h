#ifndef _EDA_N_DEF_
#define _EDA_N_DEF_

#define TIPO int
#define NDEFINIDO 0
#define INT 1
#define DOUBLE 2
#define STRING 3


typedef struct List{
  	char id[11];
	struct List *proximo;
}List;

struct IntList {

  int valor;
  struct IntList *proximo;

};

struct no {

  char *valor;
  TIPO tipo;
  int num;
  struct no *maior;
  struct no *menor;

};



struct arvore {

  struct no *root;
  int qnt;
};

void printaLista(List*);
List* criaLista (char *id);
void insereLista (struct List *head, char *id);

void printaIntList(struct IntList*);
struct IntList* criaIntList(int valor);
void insereIntList(struct IntList* head, int valor);
struct IntList* juntarIntList(struct IntList* head, struct IntList* bunda);
void juntarIntListInternal(struct IntList* cabeca, struct IntList* bunda);

struct arvore* criarArvore();
void insereArvore(struct arvore* arv, char* valor);
void insereArvoreInternal(struct no* node, char* valor, int);
struct no* criaNo(char* valor, int);
void printArvore (struct arvore* arv);
void printNodes (struct no* node, int nivel);
void insereListaNaArvore(List* lista, struct arvore* arv, TIPO tipo);
void atualizaTipoDaArovre (struct no * root, TIPO tipo);

int buscaPosicao (struct arvore* arv ,char* valor);
int buscaPosicaoInternal (struct no* node, char* valor);
#endif
