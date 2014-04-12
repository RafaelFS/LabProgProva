/*
Rafael Freitas da Silva NUSP 6480585

arvores.h

Arquivo cabeçalho correspondente à biblioteca arvores.c

*/

#include <stdio.h>
#ifndef H_ARVORES
#define H_ARVORES
#define Tipo int
#define TRUE 1
#define FALSE 0

//Declaração da struct correspondente à um nó da árvore binária
typedef struct _No {
        Tipo info;
        struct _No *esq, *dir;
} No;

//Função que recebe a raiz de um árvore e a inicializa valores nulos para informação e nós filhos.
void inicializa(No** T);

//Recebe a árvore T e devolve sua raiz.
No raiz(No *T);

//Recebe a árvore T e uma nova informação x e insere o elemento com aquela informação na árvore

void insere(No **T, Tipo x);

//Recebe a árvore o T e o elemento n e devolve o nó que é pai de n na árvore T.
No* pai(No *T, Tipo n);

//Devolve o endereço do nó que é o filho mais à esquerda de n.
No* filho_esquerdo(No *T, Tipo n);

//Devolve o endereço do nó que tem o mesmo pai que n e que vem logo em seguida a n. Se não existir irmão direito, devolve NULL.
No* irmao_direito(No* T, Tipo n);

//Imprime a arvore na forma pré-ordem
void preordem(No* T);

//Imprime a arvore na forma em-ordem
void emordem(No* T);

//Imprime a arvore na forma pos-ordem
void posordem(No* T);

#endif // H_ARVORES
