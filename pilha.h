/*
Rafael Freitas da Silva NUSP 6480585

pilha.h

Arquivo cabeçalho correspondente à biblioteca pilha.c
*/

#include <stdio.h>
#ifndef H_PILHA
#define H_PILHA
#define MAX 100
typedef int TipoDoElemento;

typedef struct _Pilha {
    int topo;                      /* topo = -1, se a pilha está vazia */
    TipoDoElemento elementos[MAX];
} Pilha;

//Função que indica que ocorreu underflow
void underflow();

//Função que indica que ocorreu overflow
void overflow();

//Empilha o elemento p na pilha s
void empilha(TipoDoElemento p, Pilha *s);

//Remove o elemento do topo da pilha s e o devolve em p
void desempilha(TipoDoElemento *p, Pilha *s);

//Retorna 1 se a pilha s está vazia ou 0 caso contrário.
int ehvazia(Pilha *s);

//Faz com que a pilha fique vazia (topo = -1, no caso de implementação com vetores)
void limpa(Pilha *s);

#endif // H_PILHA
