#ifndef _EDA_N_DEF_
#define _EDA_N_DEF_

struct no {

  char* valor;

  struct no* maior;
  struct no* menor;

};

struct arvore {

  struct no root;

};

#endif
