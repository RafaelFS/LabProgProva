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
#include "q3.h"
#include "q4.h"
#include "q6.h"
#include "q7.h"

int main(){
    //Codigo Questão 1
    printf("Questao 1, impressao da arvore: \n \n");
    criaNUSParvore();

    //Codigo Questão 2
    printf("\nQuestao 2, mediana da lista: \n");
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

    //Codigo Questão 3
    Fila fila1;
    Pilha pilha1;
    limpa(&pilha1);
    InicializaFila(&fila1);
    empilha(1, &pilha1);
    empilha(2, &pilha1);
    empilha(3, &pilha1);
    empilha(4, &pilha1);
    empilha(5, &pilha1);
    tranferepilhaparafila(&pilha1, &fila1);
    printf("\nQuestao3, fila resultante: \n");
    int i;
    for(i = 0; i<=fila1.fim; i++){
        printf("%d ", fila1.elementos[i]);
    }

    //Codigo Questão 4
    Pilha pilha2;
    Pilha pilha3;
    int temp;
    limpa(&pilha2);
    limpa(&pilha3);
    empilha(15, &pilha2);
    empilha(14, &pilha2);
    empilha(13, &pilha2);
    empilha(12, &pilha2);
    empilha(11, &pilha2);
    empilha(5, &pilha3);
    empilha(4, &pilha3);
    empilha(3, &pilha3);
    empilha(2, &pilha3);
    empilha(1, &pilha3);
    uniaodepilhas(&pilha2, &pilha3);
    printf("\n\nQuestao 4, pilha resultante: \n");
    while(ehvazia(&pilha3) != 1){
        desempilha(&temp, &pilha3);
        printf("%d ", temp);
    }
    puts("");

    //Codigo Questão 6
    No* arvore1;
    inicializaarvore(&arvore1);
    insere(&arvore1, 10);
    insere(&arvore1, 1);
    insere(&arvore1, 4);
    insere(&arvore1, 5);
    insere(&arvore1, 6);
    insere(&arvore1, 13);
    insere(&arvore1, 16);
    insere(&arvore1, 20);
    insere(&arvore1, 32);
    insere(&arvore1, 14);
    insere(&arvore1, 2);
    insere(&arvore1, 12);
    insere(&arvore1, 36);
    puts("");
    printf("Questao 6, teste com arvore de 13 elementos \n");
    printf("numero de folhas = %d \n", numerodefolhas(arvore1));

    //Codigo Questão 7
    No* arvore2;
    No* arvore3;
    inicializaarvore(&arvore2);
    inicializaarvore(&arvore3);
    insere(&arvore2, 2000);
    insere(&arvore2, 321);
    insere(&arvore2, 321);
    insere(&arvore2, 2131);
    insere(&arvore2, 6132);
    insere(&arvore2, 342);
    insere(&arvore2, 98);
    insere(&arvore2, 76);
    insere(&arvore2, 74);
    insere(&arvore2, 4132);
    insere(&arvore2, 132);
    insere(&arvore2, 1443);
    insere(&arvore2, 3342);
    copiaarvore(&arvore2, &arvore3);
    printf("Questao 7, impressao da arvore original e da copiada para verificar se sao iguais \n");
    puts("Original: ");
    imprime(arvore2, 6);
    puts("");
    puts("Copia: ");
    imprime(arvore3, 6);

    //Codigo Questão 8


    return 0;
}
