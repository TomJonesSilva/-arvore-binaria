#include "posfixa.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

arvore arvoreposf(char *exp) {

  int n = strlen(exp);
  pilha p = criapilha(n);

  for (int i = 0; i < n; i++) {
    char s;
    switch (exp[i]) {

    case '+':
    case '-':
    case '*':
    case '/':
      s = exp[i];
      noh *novo = cria_noh(s);
      // printf("#***%d\n", novo);

      noh *x1 = desempilha(p);
      // imprime_arvore(x1, 0);
      // printf("#***%d\n", x1);

      noh *x2 = desempilha(p);
      // imprime_arvore(x2, 0);
      // printf("#***%d\n", x2);

      novo->esq = x2; // desempilha(p);
      novo->dir = x1; // desempilha(p);

      // printf("@***%d\n", novo);
      // printf("@***%d\n", novo->esq);
      // printf("@***%d\n", novo->dir);

      // printf("Empilhando %c\n", s);
      // imprime_arvore_end(novo, 0);

      empilha(p, novo);

      break;

    default:
      s = exp[i];
      int n = s - '0';
      noh *no = cria_noh(n);
      empilha(p, no);
      // printf("Empilhando %c\n", s);
      // imprime_arvore_end(no, 0);
      break;
    }
  }
  arvore posfixa = topo(p);
  // printf("-->%d\n", posfixa);
  // printf("-->%d\n", posfixa->esq);
  // printf("-->%d\n", posfixa->dir);

  return posfixa;
}

int valorposf(char *exp) {
  int n = strlen(exp);
  pilha p = criapilha(n);
  int valor;

  for (int i = 0; i < n; i++) {
    char s;
    switch (exp[i]) {

    case '+':
    case '-':
    case '*':
    case '/':
      s = exp[i];
      noh *novo = desempilha(p);
      int calc1 = novo->conteudo;
      novo = desempilha(p);
      int calc2 = novo->conteudo;

      if (s == '+')
        novo->conteudo = calc2 + calc1;

      if (s == '-')
        novo->conteudo = calc2 - calc1;

      if (s == '*')
        novo->conteudo = calc2 * calc1;

      if (s == '/')
        novo->conteudo = (int)calc2 / calc1;

      empilha(p, novo);
      valor = novo->conteudo;
      break;

    default:
      s = exp[i];
      int n = s - '0';
      noh *no = cria_noh(n);
      empilha(p, no);
      break;
    }
  }
  return valor;
}

char *posfinf(char *exp) {

  arvore nova = arvoreposf(exp);

  return erd(nova);
}

char *posfpref(char *exp) {
  arvore nova = arvoreposf(exp);
  return red(nova);
}

char *reduz(noh *r) {
  noh *novo = r;

  // se a raiz da arvore possuir 2 filhos
  if (novo->esq != NULL && novo->dir != NULL) {
    // se esses dois filhos forem folhas

    if ((novo->esq->esq == NULL && novo->esq->dir == NULL) &&
        (novo->dir->esq == NULL && novo->dir->dir == NULL)) {
      printf("entra");
      char *exp;
      exp = edr(novo);
      // printf("%c %c %c",exp[0],exp[1],exp[2]);
      int x = valorposf(exp);
      novo->conteudo = x;

      free(novo->esq);
      free(novo->dir);

      novo->esq = NULL;
      novo->dir = NULL;

    }
    // verifica quais não são folhas e faz recursão
    else {
      if (novo->esq->esq != NULL)
        REDUZ(novo->esq->esq);

      if (novo->esq->dir != NULL)
        REDUZ(novo->esq->dir);

      if (novo->dir->esq != NULL)
        REDUZ(novo->dir->esq);

      if (novo->dir->dir != NULL)
        REDUZ(novo->dir->dir);
    }

  }
  // se não possuir dois filhos
  else {
    if (novo->esq != NULL && novo->dir == NULL)
      REDUZ(novo->esq);
    if (novo->dir != NULL && novo->esq == NULL)
      REDUZ(novo->dir);
    if (novo->esq != NULL && novo->dir != NULL) {
      REDUZ(novo->esq);
      REDUZ(novo->dir);
    }
  }

  return edr(novo);
}

void arquivo(arvore r, int t, FILE *f) {
  if (r != NULL) {
    for (int k = 0; k < t; k++) {
      char s = '_';
      fprintf(f, "%c", s);
    }
    if (r->conteudo == '*' || r->conteudo == '/' || r->conteudo == '-' ||
        r->conteudo == '+') {
      fprintf(f, "%c\n", r->conteudo);
    } else
      fprintf(f, "%d\n", r->conteudo);
    arquivo(r->esq, t + 2, f);
    arquivo(r->dir, t + 2, f);
  }
}

void salva_arvore(char *arq, arvore v) {
  FILE *saida;
  saida = fopen(arq, "w");
  arquivo(v, 0, saida);
}
