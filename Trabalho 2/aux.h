
#ifndef _AUX_H_
#define _AUX_H_

#define INT 1
#define DOUBLE 2
#define STRING 3


typedef struct List{
  	char id[11];
	struct List *proximo;
}List;

#endif