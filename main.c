/*
Rafael Freitas da Silva 6480585
Prova de MAC2014 - Laboratório de Programação
Programa que implementa as funções referentes
às questões da prova.
*/
#include <stdio.h>
#include "arvores.h"
#include "q1.h"
#include "q2.h"

int main(){
    printf("Questao 1, impressao da arvore: \n \n");
    criaNUSParvore();


    printf("\nQuestao 2, mediana da lista: \n \n");
    Lista L1, L2;
    inicializalista(&L1);
    inicializalista(&L2);
    adiciona(1, &L1);
    adiciona(6, &L1);
    adiciona(4, &L2);
    adiciona(5, &L2);
    adiciona(9, &L1);
    adiciona(11, &L2);
    adiciona(12, &L2);
    adiciona(13, &L2);
    printf("mediana: %f \n", devolvemediana(L1, L2));


    return 0;
}
