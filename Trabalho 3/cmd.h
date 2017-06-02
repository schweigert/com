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

#define CMD_ISTORE    0x0000 // Posi    --
#define CMD_BIPUSH    0x0001 // Number  --
#define CMD_IADD      0x0002 // --      --
#define CMD_IMULL     0x0003 // --      --
#define CMD_ILOAD     0x0004 // Posi    --
#define CMD_ICONST_1  0x0005 // --      --
#define CMD_ICONST_2  0x0006 // --      --
#define CMD_ICONST_3  0x0007 // --      --
#define CMD_ICONST_4  0x0008 // --      --
#define CMD_ICONST_5  0x0009 // --      --
#define CMD_IDIV      0x000A // --      --
#define CMD_INEG      0x000B // --      --
#define CMD_IREM      0x000C // --      --

void showCmd();
void ShowCmdAscii();

void cmdGenerate(int, int, int);

#include "eda.h"

// Lista de Comandos em Pilha para a JVM
void CmdIstore (struct arvore* arv, char* var);
void CmdIadd ();
void CmdImull ();
void CmdBipush (int value);
void CmdIload (struct arvore* arv, char* var);
void CmdIdiv ();
void CmdIneg ();
void CmdIrem ();
#endif
