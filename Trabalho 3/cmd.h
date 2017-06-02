#ifndef _CMD_N_DEF_
#define _CMD_N_DEF_

#define MAX_COMMAND 10000

typedef struct {
  int label;
  int command;
  int arg1;
  int arg2;
} CMD;


// Commands         #Bin ID   #Arg1   #Arg2

#define CMD_ISTORE  0x0000 // Posi    --
#define CMD_BIPUSH  0x0001 // Number  --
#define CMD_IADD    0x0002 // --      --
#define CMD_IMULL   0x0003 // --      --
#define CMD_ILOAD   0x0004 // Posi    --

void showCmd();

void cmdGenerate(int, int, int);

#include "eda.h"

// Lista de Comandos em Pilha para a JVM
void CmdIstore (struct arvore* arv, char* var);

#endif
