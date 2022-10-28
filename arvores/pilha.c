#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

// Aloca uma pilha de inteiros
// com capacidade de N itens
pilha criapilha(int N) {

  pilha p = (pilha) malloc (sizeof (struct struct_pilha));
  p->v = (arvore *) malloc (N * sizeof (struct reg));
  p->N = N;
  p->t = 0;
  return p;
  
}

// Empilha x na pilha p
// Interrompe execução se pilha cheia
void empilha(pilha p, noh *x) {

  if (cheio (p)) {
    printf ("Stack overflow.\n");
    exit (1);
  }
// printf("x-->%d\n", &(x));
  //printf("xesq-->%d\n", (&(x))->esq);
  //printf("xdir-->%d\n", (&(x))->dir);

  
  //printf("y-->%d\n", &(y));
  //printf("y-->%d\n", (&y)->esq);
  //printf("y-->%d\n", (&y)->dir);


  p->v[p->t] = x;
   // p->v[p->t].conteudo = x.conteudo;
  //p->v[p->t].esq = x.esq;
  //p->v[p->t].dir = x.dir;
  //printf("x-->%d\n", &(p->v[p->t]));
  //printf("xesq-->%d\n", (&(p->v[p->t]))->esq);
  //printf("xdir-->%d\n", (&(p->v[p->t]))->dir);

  p->t++;


  
}

// Desempilha da pilha p e devolve o item desempilhado.
// Interrompe a execução se pilha vazia.
noh *desempilha(pilha p) {
  if (vazio (p)) {
    printf ("Stack underflow.\n");
    exit (1);
  }
  p->t--;
  return (p->v[p->t]);
}

// Devolve o item no topo da pilha p (sem desempilhar).
// Interrompe a execução se pilha vazia.
noh *topo(pilha p) {
  if (vazio (p)) {
    printf ("Empty stack.\n");
    exit (1);
  }

  /*noh *x = &(p->v[p->t - 1]);
  printf("**** %d\n", x);
  printf("**** %d\n", x->esq);
  printf("**** %d\n", x->dir);
  printf("**** %d\n", x->esq->esq);
  printf("**** %d\n", x->esq->dir);*/

  
  // imprime_arvore(x, 0);

  return (p->v[p->t - 1]);
}

// Testa se a pilha p está cheia (atingiu a capacidade alocada).
int cheio (pilha p) {
  return p->t == p->N;
}

// Testa se a pilha p está vazia.
int vazio (pilha p) {
  return p->t == 0;
}

void imprimepilha (pilha p) {
  int k;

  printf ("N = %d\nt = %d\n", p->N, p->t);
  printf ("base ");
  for (k = 0; k < p->t; k++)
    printf ("%d ", p->v[k]);
  printf ("topo\n");

}