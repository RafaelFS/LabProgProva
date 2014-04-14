/*
Rafael Freitas da Silva NUSP 6480585

fila.h

Arquivo cabe�alho correspondente � biblioteca fila.c
*/

#include <stdio.h>
#ifndef H_FILA
#define H_FILA
#define MAX 100
typedef int TipoDoElemento;

typedef struct _Fila {
  int inicio; /* primeira posi��o cheia */
  int fim;    /* �ltima posi��o cheia */
  int vazia;  /* vazia = 1 se Fila vazia */
  TipoDoElemento elementos[MAX];
} Fila;

//Faz F uma fila vazia.
void InicializaFila(Fila *F);

//Insere o elemento x no fim da fila F.
void InsereFila(TipoDoElemento x, Fila *F);

//Remove o primeiro elemento da fila F.
void RemoveFila(Fila *F);

// Retorna o elemento que est� no inicio da fila F, sem remov�-lo.
TipoDoElemento BuscaInicio(Fila *F);

//Retorna verdadeiro (1) se a fila F est� vazia, ou falso (0) caso contr�rio.
int ehFilaVazia(Fila *F);

//Escreve na tela uma mensagem de erro avisando que houve Overflow.
void Overflow();

//Escreve na tela uma mensagem de erro avisando que houve Underflow.
void Underflow();

#endif // H_FILA
