#include <stdio.h>
#include <stdlib.h>
#include "cmd.h"
#include "eda.h"

CMD CmdList[MAX_COMMAND] = {0};
int NumVars = 1;
int CmdIndex = 0;

char* LiteralTable[1000];
int   LiteralTableIndex = 0;

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
    if(CmdList[i].command == CMD_IADD)
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

    // IDIV
    if(CmdList[i].command == CMD_IDIV)
      printf("%d.\t%d\tIDIV\n", i,
      CmdList[i].label
    );

    // INEG
    if(CmdList[i].command == CMD_INEG)
      printf("%d.\t%d\tINEG\n", i,
      CmdList[i].label
    );

    // IREM
    if(CmdList[i].command == CMD_IREM)
      printf("%d.\t%d\tIREM\n", i,
      CmdList[i].label
    );

    // ISH[LR]
    if(CmdList[i].command == CMD_ISHR)
      printf("%d.\t%d\tISHR\n", i,
      CmdList[i].label
    );
    if(CmdList[i].command == CMD_ISHL)
      printf("%d.\t%d\tISHL\n", i,
      CmdList[i].label
    );

    // ISUB
    if(CmdList[i].command == CMD_ISUB)
      printf("%d.\t%d\tISUB\n", i,
      CmdList[i].label
    );

    // CMD_GSOUT
    if(CmdList[i].command == CMD_GSOUT)
      printf("%d.\t%d\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n", i,
      CmdList[i].label
    );

    // CMD_GSOUT
    if(CmdList[i].command == CMD_INVKOUTI)
      printf("%d.\t%d\tinvokevirtual java/io/PrintStream/println(I)V\n", i,
      CmdList[i].label
    );

    // CMD_GSOUT
    if(CmdList[i].command == CMD_INVKOUTL)
      printf("%d.\t%d\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n", i,
      CmdList[i].label
    );

    // CMD_LDC
    if(CmdList[i].command == CMD_LDC)
      printf("%d.\t%d\tLDC %i(\"%s\")\n", i,
      CmdList[i].label, CmdList[i].arg1, LiteralTable[CmdList[i].arg1]
    );

  }
}

void cmdGenerate(int command, int arg1, int arg2)
{
  if(command == CMD_ISTORE) printf("bug");
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
  NumVars = arv->qnt + 1;
  cmdGenerate (CMD_ILOAD, posicao, -1);
}

void CmdIdiv ()
{
  cmdGenerate(CMD_IDIV, -1, -1);
}

void CmdIneg ()
{
  cmdGenerate(CMD_INEG, -1, -1);
}

void CmdIrem ()
{
  cmdGenerate(CMD_IREM, -1, -1);
}

void CmdIshl ()
{
  cmdGenerate(CMD_ISHL, -1, -1);
}

void CmdIshr ()
{
  cmdGenerate(CMD_ISHR, -1, -1);
}

void CmdIsub ()
{
  cmdGenerate(CMD_ISUB, -1, -1);
}

void CmdGetStaticOut ()
{
  cmdGenerate(CMD_GSOUT, -1, -1);
}

void CmdInvokeOutInt() {
  cmdGenerate (CMD_INVKOUTI, -1, -1);
}

void CmdInvokeOutLiteral ()
{
  cmdGenerate (CMD_INVKOUTL, -1, -1);
}



char* removeAsps(char* string){

  char* i = string;
  char* j = malloc(sizeof(256));
  char* ret = j;

  i++;

  while(1){

    if(*i == '\"'){
      *j = '\0';
      break;
    }

   *j = *i;

   i++;j++;

  }

  return ret;

}

void CmdLdc (char* literal)
{
  cmdGenerate (CMD_LDC, LiteralTableIndex, -1);
  LiteralTable[LiteralTableIndex] = removeAsps(literal);
  LiteralTableIndex++;
}

void showLiteralTable()
{
  printf("\tLiteral table:\n");
  int x;
  for(x = 0; x < LiteralTableIndex; x++){
    printf("%i.\t%s\n", x,LiteralTable[x]);
  }
}

// Operações do Assembler

FILE *jasminFile = NULL;
char jasminName[256] = {0};

void writeJasminInit(char* filename)
{
  char outname[256];
  int i = 0;
  for( ; filename[i] != '.'; i++){
    outname[i] = filename[i];
    jasminName[i] = filename[i];
    jasminName[i+1] = '\0';
  }

  outname[i] = '.';
  outname[i+1] = 'j';
  outname[i+2] = '-';
  outname[i+3] = '-';
  outname[i+4] = '\0';
  jasminFile = fopen(outname, "w");

  if(jasminFile == NULL)
  {
    printf("Erro ao iniciar arquivo Assembler\n");
    exit(-1);
  }
}

void writeJasminBody()
{
  fprintf(jasminFile,".class public %s\n", jasminName);
  fprintf(jasminFile,".super java/lang/Object\n\n");
  fprintf(jasminFile,".method public <init>()V\n");
  fprintf(jasminFile,"\taload_0\n");
  fprintf(jasminFile,"\tinvokenonvirtual java/lang/Object/<init>()V\n");
  fprintf(jasminFile,"\treturn\n");
  fprintf(jasminFile,".end method\n");
}

void writeJasminMain()
{
  fprintf(jasminFile, "\n\n.method public static main([Ljava/lang/String;)V\n");
  fprintf(jasminFile, "\t.limit stack 8\n");
  fprintf(jasminFile, "\t.limit locals %d\n", NumVars);

  writeCmds();

  fprintf(jasminFile, "\treturn\n");
  fprintf(jasminFile, ".end method\n");
}

void writeCmds()
{
  int i;
  for(i = 0; i < CmdIndex; i++)
  {

    if(CmdList[i].command == CMD_ISTORE)
      fprintf(jasminFile, "\tistore %d\n",CmdList[i].arg1);

    if(CmdList[i].command == CMD_BIPUSH)
      fprintf(jasminFile, "\tbipush %d\n",CmdList[i].arg1);

    if(CmdList[i].command == CMD_ILOAD)
      fprintf(jasminFile, "\tiload %d\n",CmdList[i].arg1);

    if(CmdList[i].command == CMD_IADD)
      fprintf(jasminFile, "\tiadd\n");

    if(CmdList[i].command == CMD_IMULL)
      fprintf(jasminFile, "\timul\n");

    if(CmdList[i].command == CMD_ICONST_1)
      fprintf(jasminFile, "\ticonst_1\n");

    if(CmdList[i].command == CMD_ICONST_2)
      fprintf(jasminFile, "\ticonst_2\n");

    if(CmdList[i].command == CMD_ICONST_3)
      fprintf(jasminFile, "\ticonst_3\n");

    if(CmdList[i].command == CMD_ICONST_4)
      fprintf(jasminFile, "\ticonst_4\n");

    if(CmdList[i].command == CMD_ICONST_5)
      fprintf(jasminFile, "\ticonst_5\n");

    if(CmdList[i].command == CMD_IDIV)
      fprintf(jasminFile, "\tidiv\n");

    if(CmdList[i].command == CMD_INEG)
      fprintf(jasminFile, "\tineg\n");

    if(CmdList[i].command == CMD_IREM)
      fprintf(jasminFile, "\tirem\n");

    if(CmdList[i].command == CMD_ISHL)
      fprintf(jasminFile, "\tishl\n");

    if(CmdList[i].command == CMD_ISHR)
      fprintf(jasminFile, "\tishr\n");

    if(CmdList[i].command == CMD_ISUB)
      fprintf(jasminFile, "\tisub\n");

    if(CmdList[i].command == CMD_GSOUT)
      fprintf(jasminFile, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");

    if(CmdList[i].command == CMD_INVKOUTI)
      fprintf(jasminFile, "\tinvokevirtual java/io/PrintStream/println(I)V\n");

    if(CmdList[i].command == CMD_INVKOUTL)
      fprintf(jasminFile, "\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");

    if(CmdList[i].command == CMD_LDC)
      fprintf(jasminFile, "\tldc \"%s\"\n", LiteralTable[CmdList[i].arg1]);
  }
}

void writeJasminExit()
{
  fclose(jasminFile);
}

void callJasmin()
{

  char command[2048] = "java -jar jasmin-2.4/jasmin.jar  ";

  char* i = &jasminName[0];
  char* b = &command[32];

  while(*i != '\0')
  {

    *b = *i;

    b++;
    i++;
  }

  *b = '.';b++;
  *b = 'j';b++;
  *b = '-';b++;
  *b = '-';b++;

  *b = '\0';b++;

  int r = system(command);
}
