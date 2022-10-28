#include "pilha.h"
#include <stdio.h>


// Constrói a árvore da expressão em notação posfixa exp. Devolve a raiz dessa árvore.
arvore arvoreposf (char *exp);

// Devolve o valor de uma expressão na notação posfixa exp.
int valorposf (char *exp);

// Converte a expressão(exp) na notação posfixa para uma nova string representando a mesma expressão na notação infixa
char *posfinf (char *exp);

// Converte a expressão(exp) na notação posfixa para uma nova string representando a mesma expressão na notação prefixa.
char *posfpref (char *exp);

// Recebe a raiz de uma árvore representando uma expressão aritmética contendo pelo menos um operador.
// Transforma essa árvore da seguinte forma: todo nó que é pai de duas folhas é substituído por uma folha, contendo
// o resultado da operação representada por esse nó.
// Devolve a expressão na notação posfixa da árvore reduzida.
char *reduz (noh *r);

char *REDUZ (noh *r);

//Recebe um arquivo f e salva nele a impressão da árvore v, contendo
//um nó por linha, e evidencia o níverl de cada nó com quantidade //apartir de t e acrecentando t+2 a para cada filho;
void salva_arvore (char * arq, arvore v);

void saida(arvore r,int t,FILE *f);
