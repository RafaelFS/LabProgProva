/*
Rafael Freitas da Silva 6480585

Prova final, questão 2.
Função que recebe duas listas L1 e L2, as combina numa lista L3
e devolve a mediana da lista L3.
*/

#include <stdio.h>
#include "lista.h"


float devolvemediana(Lista L1, Lista L2){
    Lista L3;
    inicializalista(&L3);
    int n1, n2, n3;
    int i, j, k;
    float mediana = -1.0;
    n1 = L1.comp;
    n2 = L2.comp;
    n3 = n1 + n2;
    j = 1;
    k = 1;
    /*
    Dado L1 e L2 ordenados, seleciona a mediana da lista combinada L3 através do
    passo do algoritmo de busca binária, selecionando o elemento localizado
    na metade do comprimento se n ímpar ou, se n par, somando os dois elementos do meio
    e dividindo por 2.
    */
    for(i = 0; i < n3; i++){
        if((acessa(j, &L1) <= acessa(k, &L2)) && j <= n1){
            adiciona((acessa(j, &L1)), &L3);
            j++;
        }
        else{
            adiciona((acessa(k, &L2)), &L3);
            k++;
        }
    }
    //imprimelista(&L3);
    if(n3%2 == 0){
        mediana = ((float)(acessa(n3/2, &L3) + acessa(n3/2+1, &L3)))/2.0;
    }
    else mediana = (float)acessa(n3/2+1, &L3);
    return mediana;
}
