typedef struct reg {
  int conteudo; // conteúdo
  int aux;
  struct reg *esq;
  struct reg *dir;
} noh; // nó

typedef noh *arvore; // árvore

// Aloca na memória um nó de árvore sem filhos.
noh *cria_noh (int);

//recebe um arvore e o numero de '_' inciais
//imprime em cada linha um no da arvore
//cada novel da arvore e dito pelos '_'
void imprime_arvore (arvore, int);

// recebe uma arvore e adiciona o tamanho dela no aux
void altura_nos (arvore);

int qtnos (arvore);
// Recebe a raiz r de uma árvore binária e
// imprime os conteúdos dos seus nós
// em ordem e-r-d.
 char *erd (arvore r);
// Recebe a raiz r de uma árvore binária e
// imprime os conteúdos dos seus nós
// em ordem r-e-d.
char *red (arvore r);
// Recebe a raiz r de uma árvore binária e
// imprime os conteúdos dos seus nós
// em ordem e-d-r.
char *edr(arvore r);




