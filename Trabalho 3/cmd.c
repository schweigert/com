#include <stdio.h>
#include "cmd.h"
#include "eda.h"


CMD CmdList[MAX_COMMAND] = {0};
int CmdIndex = 0;

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
  cmdGenerate()
}
