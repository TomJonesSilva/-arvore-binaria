#include "arvores.h"

struct struct_pilha {
  int N;
  int t;
  arvore *v;
};

typedef struct struct_pilha *pilha;

pilha criapilha(int);
void empilha(pilha p, noh *x);
noh *desempilha(pilha);
noh *topo(pilha);
int cheio (pilha);
int vazio (pilha);
void imprimepilha (pilha);