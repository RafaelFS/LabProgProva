/*
Rafael Freitas da Silva 6480585

Prova final, questão 6.
Função que recebe a raiz de uma árvore e conta o número de filhos nela.
*/

#include <stdio.h>
#include "arvores.h"


void contanos(No* arvore1, int *numerodenos){
    if(arvore1 != NULL){
        *numerodenos = *numerodenos + 1;
        contanos(arvore1->dir, numerodenos);
        contanos(arvore1->esq, numerodenos);
    }
}

int numerodefolhas(No* arvore1){
    int folhas = 0;
    if(arvore1 != NULL) contanos(arvore1, &folhas);
    return folhas - 1;

}
