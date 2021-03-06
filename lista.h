//Define guard
#ifndef LISTA_H
#define LISTA_H

#define FIM -1
#define MAX 100
typedef int TipoDoElemento;
typedef int TipoDaPosicao;

typedef struct _Lista {
  int comp; /* comp = 0, quando a lista est� vazia. */
  TipoDoElemento elementos[MAX];
} Lista;

void inicializalista(Lista *l);
TipoDoElemento acessa(TipoDaPosicao p, Lista *l);
int adiciona(TipoDoElemento x, Lista *l);
void imprimelista(Lista *l);

#endif /** LISTA_H */
