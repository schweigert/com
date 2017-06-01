#ifndef _CMD_N_DEF_
#define _CMD_N_DEF_

#define MAX_COMMAND 10000

typedef struct {
  int label;
  int command;
  int arg1;
  int arg2;
} CMD;


// Commands

#define CMD_ISTORE 0x0000
#define CMD_IPUSH 0x0001

void cmdGenerate(int, int, int);

#endif
