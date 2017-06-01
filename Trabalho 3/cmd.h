#ifndef _CMD_N_DEF_
#define _CMD_N_DEF_

#define MAX_COMMAND 10000

struct {
  int label;
  int command;
  int arg1;
  int arg2;
} Cmd;

struct Cmd CmdList[MAX_COMMAND];
int CmdIndex = 0;

#endif
