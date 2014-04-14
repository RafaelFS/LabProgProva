/*
Rafael Freitas da Silva 6480585

Prova final, questão 3.
Função que transfere todos os elementos de uma pilha para uma fila.
*/

#include <stdio.h>
#include "pilha.h"
#include "fila.h"

void tranferepilhaparafila(Pilha* pilha1, Fila* fila1){
    int elem;
    while(pilha1->topo != -1){
        desempilha(&elem, pilha1);
        InsereFila(elem, fila1);
    }
}
