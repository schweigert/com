#include <stdio.h>
#include "cmd.h"
#include "eda.h"


CMD CmdList[MAX_COMMAND] = {0};
int CmdIndex = 0;

void showCmd()
{
  int i = 0;
  printf("\n------------------------\n");
  for(i = 0; i < CmdIndex; i++){
    printf("%d\t%d\t%d\t%d\n",
      CmdList[i].label,
      CmdList[i].command,
      CmdList[i].arg1,
      CmdList[i].arg2);
  }
  printf("\n------------------------\n");
}

void cmdGenerate(int command, int arg1, int arg2)
{
  CmdList[CmdIndex].label = -1;
  CmdList[CmdIndex].command = command;
  CmdList[CmdIndex].arg1 = arg1;
  CmdList[CmdIndex].arg2 = arg2;
  CmdIndex++;
}

void CmdIstore (struct arvore* arv, char* var)
{
  int posicao = buscaPosicao(arv, var);
  cmdGenerate(CMD_ISTORE, posicao, -1);
}

void CmdIadd()
{
  cmdGenerate(CMD_IADD, -1, -1);
}

void CmdImull()
{
  cmdGenerate(CMD_IMULL, -1, -1);
}

void CmdBipush(int value)
{
  if(value == 1) cmdGenerate(CMD_ICONST_1, -1,-1);
  else if(value == 2) cmdGenerate(CMD_ICONST_2, -1,-1);
  else if(value == 3) cmdGenerate(CMD_ICONST_3, -1,-1);
  else if(value == 4) cmdGenerate(CMD_ICONST_4, -1,-1);
  else if(value == 5) cmdGenerate(CMD_ICONST_5, -1,-1);
  else cmdGenerate(CMD_BIPUSH, value, -1);
}


void CmdIload (struct arvore* arv, char* var)
{
  int posicao = buscaPosicao(arv, var);
  cmdGenerate (CMD_ILOAD, posicao, -1);
}
