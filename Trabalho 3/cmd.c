#include <stdio.h>
#include "cmd.h"
#include "eda.h"


CMD CmdList[MAX_COMMAND] = {0};
int CmdIndex = 0;

void showCmd()
{
  int i = 0;
  printf("\n------------------------");
  for(i = 0; i < CmdIndex; i++){
    printf("%d\t%d\t%d\t%d\n",
      CmdList[i].label,
      CmdList[i].command,
      CmdList[i].arg1,
      CmdList[i].arg2);
  }
  printf("------------------------\n");
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
