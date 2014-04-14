/*
Rafael Freitas da Silva 6480585

Prova final, questão 4.
Função que transfere todos os elementos de uma pilha para o topo de outra pilha,
com a mesma ordem inicial.
*/

#include <stdio.h>
#include "pilha.h"

//Empilha a pilha um em cima da pilha2
void uniaodepilhas(Pilha* pilha1, Pilha* pilha2){
    Pilha aux;
    int elem;
    limpa(&aux);
    while(ehvazia(pilha1) != 1){
        desempilha(&elem, pilha1);
        empilha(elem, &aux);
    }
    while(ehvazia(&aux)!= 1){
        desempilha(&elem, &aux);
        empilha(elem, pilha2);
    }
}
