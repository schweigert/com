#include "gen.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
typedef struct List{
	Simbolo *simbolo;
	struct List *proximo;
}
*/

List* criaLista (char *id){
	List *ret = (struct List*)malloc(sizeof(struct List));
	if (ret != NULL){
		memcpy(ret->id, id, 11);
		ret->proximo = NULL;
	}

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
	if(l == NULL) return;
	printf("%s \n",(char*)l->id);
	printaLista(l->proximo);
}
