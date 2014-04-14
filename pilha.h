/*
Rafael Freitas da Silva NUSP 6480585

pilha.h

Arquivo cabe�alho correspondente � biblioteca pilha.c
*/

#include <stdio.h>
#ifndef H_PILHA
#define H_PILHA
#define MAX 100
typedef int TipoDoElemento;

typedef struct _Pilha {
    int topo;                      /* topo = -1, se a pilha est� vazia */
    TipoDoElemento elementos[MAX];
} Pilha;

//Fun��o que indica que ocorreu underflow
void underflow();

//Fun��o que indica que ocorreu overflow
void overflow();

//Empilha o elemento p na pilha s
void empilha(TipoDoElemento p, Pilha *s);

//Remove o elemento do topo da pilha s e o devolve em p
void desempilha(TipoDoElemento *p, Pilha *s);

//Retorna 1 se a pilha s est� vazia ou 0 caso contr�rio.
int ehvazia(Pilha *s);

//Faz com que a pilha fique vazia (topo = -1, no caso de implementa��o com vetores)
void limpa(Pilha *s);

#endif // H_PILHA
