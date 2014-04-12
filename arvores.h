/*
Rafael Freitas da Silva NUSP 6480585

arvores.h

Arquivo cabe�alho correspondente � biblioteca arvores.c

*/

#include <stdio.h>
#ifndef H_ARVORES
#define H_ARVORES
#define Tipo int
#define TRUE 1
#define FALSE 0

//Declara��o da struct correspondente � um n� da �rvore bin�ria
typedef struct _No {
        Tipo info;
        struct _No *esq, *dir;
} No;

//Fun��o que recebe a raiz de um �rvore e a inicializa valores nulos para informa��o e n�s filhos.
void inicializa(No** T);

//Recebe a �rvore T e devolve sua raiz.
No raiz(No *T);

//Recebe a �rvore T e uma nova informa��o x e insere o elemento com aquela informa��o na �rvore

void insere(No **T, Tipo x);

//Recebe a �rvore o T e o elemento n e devolve o n� que � pai de n na �rvore T.
No* pai(No *T, Tipo n);

//Devolve o endere�o do n� que � o filho mais � esquerda de n.
No* filho_esquerdo(No *T, Tipo n);

//Devolve o endere�o do n� que tem o mesmo pai que n e que vem logo em seguida a n. Se n�o existir irm�o direito, devolve NULL.
No* irmao_direito(No* T, Tipo n);

//Imprime a arvore na forma pr�-ordem
void preordem(No* T);

//Imprime a arvore na forma em-ordem
void emordem(No* T);

//Imprime a arvore na forma pos-ordem
void posordem(No* T);

#endif // H_ARVORES
