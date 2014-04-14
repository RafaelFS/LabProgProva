/*
Rafael Freitas da Silva NUSP 6480585

arvores.c

Biblioteca que implementa as operações básicas sobre uma árvore binária.
*/

#include <stdio.h>
#include <malloc.h>
#include "arvores.h"

//Função que recebe a raiz de um árvore e a inicializa valores nulos para informação e nós filhos.
void inicializaarvore(No** T){
    *T = NULL;
}

//Recebe a árvore T e devolve sua raiz.
No raiz(No *T){
    return(*T);
}

// Recebe uma nova informação x e a árvore T  e insere o elemento com aquela informação na árvore.
// Retirada de Arvores - Aula 1, Paulo José da Silva e Silva
void insere(No **T, Tipo x) {
    /* Se a arvore esta vazia insere. */
    if (*T == NULL) {
        *T = (No *) malloc(sizeof(No));
        (*T)->info = x;
        (*T)->dir = (*T)->esq = NULL;
    }
    else {
        if (x < (*T)->info) insere(&(*T)->esq, x);
        else if (x > (*T)->info) insere(&(*T)->dir, x);
    }
}

//Recebe a árvore o T e o elemento n e devolve o endereço do nó que é pai de n na árvore T.
No* pai(No* T, Tipo n){
    No* saida = NULL;
    //Função de recursão

    if(T->esq != NULL){
        if(T->esq->info == n){
            saida = T;
        }
        else{
          if(pai(T->esq, n) != NULL)
            saida = pai(T->esq, n);
        }
    }

    if(T->dir != NULL){
        if(T->dir->info == n){
            saida = T;
        }

        else{
           if(pai(T->dir, n) != NULL){
                saida = pai(T->dir, n);
           }
        }
    }
    return saida;
}

//Devolve o endereço do nó que é o filho mais à esquerda de n.
No* filho_esquerdo(No *T, Tipo n){
    No* saida = NULL;
    No* aux = NULL;
    //Função de recursão
    if(T->info == n){
        puts("caso base");
        saida = T->esq;
        printf("filho esquerdo de 20: %d \n", (saida->info));
    }
    else{
        if(T->esq != NULL){
            puts("caso esq");
            aux = filho_esquerdo(T->esq, n);
            if(aux != NULL) saida = aux;
        }
        if(T->dir != NULL){
            puts("caso dir");
            aux = filho_esquerdo(T->dir, n);
            if(aux != NULL) saida = aux;
        }
    }
    return saida;
}

//Devolve o endereço do nó que tem o mesmo pai que n e que vem logo em seguida a n. Se não existir irmão direito, devolve NULL.
No* irmao_direito(No* T, Tipo n){
    No* saida = NULL;
    No* aux = NULL;
    aux = pai(T, n)->dir;
    if(aux != T){
        saida = aux;
    }
    return saida;
}

//Imprime a arvore na forma pré-ordem
void preordem(No* T){
    if(T->info != NULL) printf("%d ", T->info);
    if(T->esq != NULL){
            preordem(T->esq);
    }
    if(T->dir != NULL) preordem(T->dir);
}

//Imprime a arvore na forma em-ordem
void emordem(No* T){
    if(T->esq != NULL){
            emordem(T->esq);
    }
    if(T->info != NULL) printf("%d ", T->info);

    if(T->dir != NULL) emordem(T->dir);
}

//Imprime a arvore na forma pós-ordem
void posordem(No* T){
    if(T->esq != NULL){
            posordem(T->esq);
    }
    if(T->dir != NULL) posordem(T->dir);
    if(T->info != NULL) printf("%d ", T->info);
}

void imprime(No *raiz, int nivel) {
    /* Esta rotina e adequada para imprimir arvores com chaves de */
    /* comprimento maximo igual a 6. */
    int i;
    if (raiz == NULL) return;
    imprime(raiz->dir, nivel + 1);
    for(i = 0; i < nivel; i++) printf(" ");
        printf("%6d\n", raiz->info);
        imprime(raiz->esq, nivel + 1);
}
