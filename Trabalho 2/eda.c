#include "eda.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

List* criaLista (char *id){
	List *ret = (struct List*)malloc(sizeof(struct List));

	if (ret != NULL){
		memcpy(ret->id, id, 11);
		ret->proximo = NULL;
	}
	return ret;
}

void insereLista (struct List *head, char *id){
	if(head->proximo == NULL){
		head->proximo = (struct List*)malloc(sizeof(struct List));
		if (head->proximo != NULL){
			memcpy(head->proximo->id, id, 11);
			head->proximo->proximo = NULL;
		}
	} else {
		insereLista(head->proximo, id);
	}
}

void printaLista (struct List *l){
	if(l == NULL) {
		printf("\n");
		return;
	};
	printf("%s ",(char*)l->id);
	printaLista(l->proximo);
}



struct arvore* criarArvore(){
	struct arvore* ret = (struct arvore*)malloc(sizeof(struct arvore));
	ret->root = NULL;
	return ret;
}

void insereArvore(struct arvore* arv, char* valor){
	if(arv->root == NULL){
		arv->root = criaNo(valor);
		return;
	} else {
		insereArvoreInternal(arv->root, valor);
		return;
	}

}

void insereArvoreInternal(struct no* node, char* valor){

	int ret = strcmp(node->valor, valor);
	if(ret == 0){
		printf("Simbolo %s já existe\n", valor);
		exit(-1);
	}

	if(ret >0 && node->maior == NULL){
		node->maior = criaNo(valor);
		return;
	}

	if(ret <0 && node->menor == NULL){
		node->menor = criaNo(valor);
		return;
	}

	if(ret < 0){
		insereArvoreInternal(node->menor, valor);
	} else {
		insereArvoreInternal(node->maior, valor);
	}

}

struct no* criaNo(char* valor){
	struct no* ret = (struct no*)malloc(sizeof(struct no));
	ret->valor = valor;
	ret->maior = NULL;
	ret->menor = NULL;
	return ret;
}

void printArvore (struct arvore* arv){
	printNodes(arv->root, 0);
}


void printNodes (struct no* node, int nivel){
	if(node == NULL) return;

	int n = 0;
	for(n = 0; n < nivel; n ++){
		printf("\t");
	}
	printf("N: %s\n", node->valor);

	printNodes(node->maior, nivel +1);
	printNodes(node->menor, nivel +1);
}

void insereListaNaArvore(List* lista, struct arvore* arv){
	if (lista == NULL) return;
	if (arv == NULL) return;

	insereArvore(arv, (char*)lista->id);
	insereListaNaArvore((List*)lista->proximo, arv);
}