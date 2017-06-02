#include <stdio.h>
#include "cmd.h"
#include "eda.h"


CMD CmdList[MAX_COMMAND] = {0};
int CmdIndex = 0;

void showCmd()
{
  int i = 0;
  printf("\n\tBinary Commands:\nID\tL\tC\tA1\tA2\n");
  for(i = 0; i < CmdIndex; i++){
    printf("%d.\t%d\t%d\t%d\t%d\n",i,
      CmdList[i].label,
      CmdList[i].command,
      CmdList[i].arg1,
      CmdList[i].arg2);
  }
  printf("\n\n");
}

void ShowCmdAscii()
{
  int i = 0;
  printf("\n\tAscii Commands:\nID\tL\tC\t\tA1\tA2\n");

  for(i = 0; i < CmdIndex; i++)
  {
    // ISTORE PRINT
    if(CmdList[i].command == CMD_ISTORE)
      printf("%d.\t%d\tISTORE\t\t%d\n", i,
      CmdList[i].label,
      CmdList[i].arg1
    );

    // BIPUSH
    if(CmdList[i].command == CMD_BIPUSH)
      printf("%d.\t%d\tBIPUSH\t\t%d\n", i,
      CmdList[i].label,
      CmdList[i].arg1
    );

    // IADD
    if(CmdList[i].command == CMD_BIPUSH)
      printf("%d.\t%d\tIADD\n", i,
      CmdList[i].label
    );

    // IMULL
    if(CmdList[i].command == CMD_IMULL)
      printf("%d.\t%d\tIMULL\n", i,
      CmdList[i].label
    );

    // BIPUSH
    if(CmdList[i].command == CMD_ILOAD)
      printf("%d.\t%d\tILOAD\t\t%d\n", i,
      CmdList[i].label,
      CmdList[i].arg1
    );

    // I_CONST_[12345]
    if(CmdList[i].command == CMD_ICONST_1)
      printf("%d.\t%d\tICONST_1\n", i,
      CmdList[i].label
    );
    if(CmdList[i].command == CMD_ICONST_2)
      printf("%d.\t%d\tICONST_2\n", i,
      CmdList[i].label
    );
    if(CmdList[i].command == CMD_ICONST_3)
      printf("%d.\t%d\tICONST_3\n", i,
      CmdList[i].label
    );
    if(CmdList[i].command == CMD_ICONST_4)
      printf("%d.\t%d\tICONST_4\n", i,
      CmdList[i].label
    );
    if(CmdList[i].command == CMD_ICONST_5)
      printf("%d.\t%d\tICONST_5\n", i,
      CmdList[i].label
    );
  }
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
