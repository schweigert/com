#define INT 1
#define DOUBLE 2
#define STRING 3

struct Atributo{
    struct Lista *listaId;
    char nomeId[10];
    int tipo;
}

struct TabelaSimbolos{
  char id[11];
  int tipo, pos;
}