// Struct Data File

#ifndef _EDA_N_DEF_
#define _EDA_N_DEF_


typedef struct Node {

	char name[12];

	struct Node* left;
	struct Node* right;

} BNode;

typedef struct Tree {

	BNode* root;

} BTree;

#endif