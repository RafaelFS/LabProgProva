/*
Rafael Freitas da Silva 6480585

Implementa o desenho da árvore binária de busca
com cada um dos números do número usp do aluno.
Como o número 6480585 possui números repetidos,
será utilizado o número 6480597
*/

#include <stdio.h>
#include "arvores.h"

void criaNUSParvore(){
    int nusp[7] = {6, 4, 8, 0, 5, 9, 7};
    int i;
    No* arvore;
    inicializa(&arvore);
    for(i=0; i< 7; i++){
        insere(&arvore, nusp[i]);

    }
    imprime(arvore, 2);
}


