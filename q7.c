/*
Rafael Freitas da Silva 6480585

Prova final, quest�o 7.
Fun��o que recebe a raiz de uma �rvore 1, a raiz de uma �rvore 2 vazia
e copia a �rvore 1 na �rvore 2; .
*/

#include <stdio.h>
#include "arvores.h"

void copiaarvore(No** arvore1, No** arvore2){
    int elem;
    if(*arvore1 != NULL){
        elem = (*arvore1)->info;
        insere(arvore2, elem);
        copiaarvore(&((*arvore1)->esq), arvore2);
        copiaarvore(&((*arvore1)->dir), arvore2);
    }
}

