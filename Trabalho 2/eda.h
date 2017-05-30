#ifndef _EDA_N_DEF_
#define _EDA_N_DEF_

#define INT 1
#define DOUBLE 2
#define STRING 3


typedef struct List{
  	char id[11];
	struct List *proximo;
}List;

struct no {

  char *valor;

  struct no *maior;
  struct no *menor;

};

struct arvore {

  struct no *root;

};


struct arvore* criarArvore();
void insereArvore(struct arvore* arv, char* valor);
void insereArvoreInternal(struct no* node, char* valor);
struct no* criaNo(char* valor);
void printArvore (struct arvore* arv);
void printNodes (struct no* node, int nivel);
void insereListaNaArvore(List* lista, struct arvore* arv);

#endif
