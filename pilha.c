/*
Rafael Freitas da Silva NUSP 6480585

pilha.c

Biblioteca contendo as operações sobre pilha
*/
#include <stdio.h>
#include "pilha.h"

//Função que indica que ocorreu underflow
void underflow(){
    printf("\n Underflow! A pilha estah vazia.");
}

//Função que indica que ocorreu overflow
void overflow(){
    printf("\n Overflow! A pilha estah cheia. O elemento nao foi adicionado");
}

/* Procedimento para inserir um elemento x na pilha S */
void empilha(TipoDoElemento p, Pilha *s)
{
  //s->topo++;
  if( s->topo + 1 >= MAX )
     overflow(); /* a pilha já está cheia*/
  else{
     s->topo++;
     s->elementos[s->topo] = p;
     }
}

/* Procedimento para remover um elemento na pilha S */
void desempilha(TipoDoElemento *p, Pilha *s)
{
  if( s->topo == -1 )
     underflow(); /* a pilha está vazia*/
  else {
     *p = s->elementos[s->topo];
     s->topo--;
  }
}



//Retorna 1 se a pilha s está vazia ou 0 caso contrário.
int ehvazia(Pilha *s){
    //se topo = -1, pilha é vazia
    int saida;
    if(s->topo == -1) saida = 1;
    else saida = 0;
    return saida;
}

//Faz com que a pilha fique vazia (topo = -1, no caso de implementação com vetores)
void limpa(Pilha *s){
    //coloco topo = -1
    s->topo = -1;
}

