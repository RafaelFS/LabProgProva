/*
Rafael Freitas da Silva NUSP 6480585

fila.c

Biblioteca que implementa as operações báscias sobre uma fila.
*/

#include <stdio.h>
#include "fila.h"

//Faz F uma fila vazia.
void InicializaFila(Fila *pF){
    pF->inicio = 0;
    pF->fim = -1;
    pF->vazia = 1;
}

//Retorna verdadeiro (1) se a fila F está vazia, ou falso (0) caso contrário.
int ehFilaVazia(Fila *pF){
    return(pF->vazia);
}

//Insere o elemento x no fim da fila F.
void InsereFila(TipoDoElemento x, Fila *pF){
    //Se em seu proximo indicie, fim está na mesma posição que inicio e a fila não está vazia, deu overflow
    if(((pF->fim + 1) % MAX) == pF->inicio && pF->vazia == 0) {
        Overflow();
        exit(1);
    }

    else
        //Sem overflow, atualizo o indice de fim e adiciono o elemento. Se a fila estava vazia, indico que não está mais vazia agora.
        pF->fim = (pF->fim + 1) % MAX;
        pF->elementos[pF->fim] = x;
        if (ehFilaVazia(pF) == 1) pF->vazia = 0;
}

//Remove o primeiro elemento da fila F.
void RemoveFila(Fila *pF){
    if(pF->vazia == 1 ) {
        Underflow();
     //   exit(1) ;
    }
    else {
        pF->inicio = (pF->inicio + 1) % MAX;
        /* O novo inicio passou do fim? */
        if (pF->inicio == (pF->fim + 1) % MAX)
            pF->vazia = 1;
    }
}


// Retorna o elemento que está no inicio da fila F, sem removê-lo. Retorna -1 caso a fila esteja vazia.
TipoDoElemento BuscaInicio(Fila *pF){
    TipoDoElemento saida;

    if(ehFilaVazia(pF) == 0){
        saida = pF->elementos[pF->inicio];
    }
    else saida = -1;

    return saida;
}



//Escreve na tela uma mensagem de erro avisando que houve Overflow.
void Overflow(){
    printf("Overflow! A fila estah cheia, nao eh possivel inserir mais elementos\n");
}

//Escreve na tela uma mensagem de erro avisando que houve Underflow.
void Underflow(){
    printf("Underflow! A fila estah vazia,  nao eh possivel remover elementos\n");
}
