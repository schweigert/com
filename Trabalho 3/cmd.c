#include "cmd.h"

CMD CmdList[MAX_COMMAND] = {0};
int CmdIndex = 0;

void cmdGenerate(int command, int arg1, int arg2)
{
  CmdList[CmdIndex].label = -1;
  CmdList[CmdIndex].command = command;
  CmdList[CmdIndex].arg1 = arg1;
  CmdList[CmdIndex].arg2 = arg2;
}
