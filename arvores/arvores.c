#include "arvores.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

noh *cria_noh(int conteudo) {

  noh *x = (noh *)malloc(sizeof(struct reg));
  x->esq = NULL;
  x->dir = NULL;
  x->conteudo = conteudo;

  return x;
}

void imprime_arvore(arvore r, int t) {

  // if (t >= P)
  //  return;
  if (r != NULL) {
    for (int k = 0; k < t; k++)
      printf("_");
    if (r->conteudo == '*' || r->conteudo == '/' || r->conteudo == '-' ||
        r->conteudo == '+') {
      printf("%c\n", r->conteudo);
    } else
      printf("%d\n", r->conteudo);

    imprime_arvore(r->esq, t + 2);
    imprime_arvore(r->dir, t + 2);
  }
}

void altura_nos(arvore r) {

  if (r->dir == NULL && r->esq == NULL)
    r->aux = 0;

  else if (r->dir != NULL && r->esq == NULL) {
    altura_nos(r->dir);
    r->aux = r->dir->aux + 1;
  } else if (r->dir == NULL && r->esq != NULL) {
    altura_nos(r->esq);
    r->aux = r->esq->aux + 1;
  } else {
    altura_nos(r->dir);
    altura_nos(r->esq);
    if (r->esq->aux > r->dir->aux)
      r->aux = r->esq->aux + 1;
    else
      r->aux = r->dir->aux + 1;
  }
}

int qtnos(arvore r) {

  if (r == NULL)
    return 0;

  return qtnos(r->esq) + qtnos(r->dir) + 1;
}

// Recebe a raiz r de uma árvore binária e
// imprime os conteúdos dos seus nós
// em ordem e-r-d.
char *erd(arvore r) {
  int n = qtnos(r);
  char *exp = (char *)malloc(sizeof(char) * n + 1);
  exp[0] = '\0';
  if (r != NULL) {

    if (r->esq == NULL && r->dir == NULL) {

      char s[2];

      if (r->conteudo == '*' || r->conteudo == '/' || r->conteudo == '-' ||
          r->conteudo == '+') {
        sprintf(s, "%c", r->conteudo);

        strcat(exp, s);

      } else {
        sprintf(s, "%d", r->conteudo);

        strcat(exp, s);
      }

    } else {
      char s[2];

      strcat(exp, "(");

      char *eexp = erd(r->esq);
      strcat(exp, eexp);
      sprintf(s, "%c", r->conteudo);

      strcat(exp, s);

      char *dexp = erd(r->dir);
      strcat(exp, dexp);
      strcat(exp, ")");
    }
  }

  return exp;
}

// Recebe a raiz r de uma árvore binária e
// imprime os conteúdos dos seus nós
// em ordem r-e-d.
char *red(arvore r) {
  int n = qtnos(r);
  char *exp = (char *)malloc(sizeof(char) * n + 1);
  char s[2];

  exp[0] = '\0';

  if (r != NULL) {
    if (r->conteudo == '*' || r->conteudo == '/' || r->conteudo == '-' ||
        r->conteudo == '+') {

      sprintf(s, "%c", r->conteudo);

    } else {

      sprintf(s, "%d", r->conteudo);
    }
    
    strcat(exp, s);

    char *expe = red(r->esq);
    char *expd = red(r->dir);
    strcat(exp, expe);
    strcat(exp, expd);
  }
  return exp;
}

// Recebe a raiz r de uma árvore binária e
// imprime os conteúdos dos seus nós
// em ordem e-d-r.
char *edr(arvore r) {
  int n = qtnos(r);

  char *exp = (char *)malloc(sizeof(char) * n + 1);
  char s[2];
  exp[0] = '\0';
  if (r != NULL) {

    if (r->conteudo == '*' || r->conteudo == '/' || r->conteudo == '-' ||
        r->conteudo == '+') {

      char *eexp = edr(r->esq);
      char *dexp = edr(r->dir);
      strcat(exp, eexp);
      strcat(exp, dexp);
      sprintf(s, "%c", r->conteudo);

    } else {

      sprintf(s, "%d", r->conteudo);
    }
    strcat(exp, s);
  }

  return exp;
}
