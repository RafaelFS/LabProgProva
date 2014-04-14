/* Rafael Freitas da Silva NUSP 6480585 */
/* Biblioteca com fun��es b�sicas que s�o utilizadas para  */

//Definindo a estrutura de uma lista
#define FIM -1
#define MAX 100
typedef int TipoDoElemento;
typedef int TipoDaPosicao;

typedef struct _Lista {
  int comp; /* comp = 0, quando a lista est� vazia. */
  TipoDoElemento elementos[MAX];
} Lista;

// Faz com que a lista L seja uma lista vazia (n = 0)
void inicializa(Lista *l) {
  l->comp = 0;
}

//Adiciona o elemento x no final da lista L.
int adiciona(TipoDoElemento x, Lista *l) {
    if (l->comp < MAX) {
        l->elementos[l->comp] = x;
        l->comp++;
        /* Deu tudo certo, retorna 0 */
        return(0) ;
    }
    else {
        /* Deu problema pois a lista est� cheia, retorna -1 */
        return(-1) ;
    }
}

/*  Retorna o elemento na posi��o p da lista L. Caso a L
    n�o contenha o elemento na posi��o p, o resultado � indefinido. */
TipoDoElemento acessa(TipoDaPosicao p, Lista *l) {
  if (p <= l->comp)
    return(l->elementos[p - 1]);
  else
    /* Aqui temos que tomar um certo cuidado com este retorno pois
	   ele deveria ser compat�vel com um TipoDoElemento */
    return 0;
}

//Retorna a posi��o do primeiro elemento da lista L ou FIM caso a lista esteja vazia.
TipoDaPosicao primeiro(Lista *l){
    if(l->comp == 0){
        return FIM;
    }
    else{
        return 1;
    }
}
//Retorna a posi��o da primeira ocorr�ncia do elemento x na lista L. Se x n�o pertence a L ent�o retorna -1.
TipoDaPosicao localiza(TipoDoElemento x, Lista *l){
    int i;
    TipoDaPosicao local=-1;
    for(i = 0; i < l->comp;i++){
        if(local == -1 && l->elementos[i] == x){
            local = i+1;
        }
    }
    return local;

}

/*  Devolve a posi��o seguinte a p na lista. Se p � a
    �ltima posi��o da lista, devolve FIM. Caso  L n�o contenha o
    elemento na posi��o p, o resultado � indefinido. Note que "p" deve
    ser obtido a partir de uma das duas rotinas acima. */
TipoDaPosicao proximo(TipoDaPosicao p, Lista *l){
    if (p >= l->comp){
        return FIM;
    }
    else{
        return p+1;
    }
}
/*  Insere x na posi��o p da lista L, movendo os elementos
    nas posi��es a partir de p, para a pr�xima posi��o. Isto �, se
    L := a1, a2, ... , an , ap�s a inser��o temos
    L := a1, a2, ... , a(p-1), x, ap, ... , an.
    Se na lista L n�o existe a posi��o p o resultado � indefinido */
void insere(TipoDoElemento x, TipoDaPosicao p, Lista *l){
    TipoDaPosicao i;
    TipoDoElemento atual;
    TipoDoElemento prox;
    atual = x;
    prox = l->elementos[p-1];
    for(i = p-1; i <= l->comp; i++){
        l->elementos[i] = atual;
        atual = prox;
        prox = l->elementos[i+1];
    }
    l->comp++;
}

/*  Remove o elemento na posi��o p da lista. Isto �, se
    L := a1, a2, ... , an , ap�s a remo��o temos
    L := a1, a2, ... , a(p-1), a(p+1), ... , an;
    Caso a L n�o contenha o elemento na posi��o p, o resultado � indefinido. */

void remova(TipoDaPosicao p, Lista *l){
    TipoDaPosicao i;
    TipoDoElemento subst;
    subst = l->elementos[p];
    for(i = p-1; i <= l->comp; i++){
        l->elementos[i] = subst;
        subst = l->elementos[i+2];
    }
    l->comp--;
}

// Retorna 1 se a lista L est� vazia, 0 caso contr�rio.
int vazia(Lista *l){
    if (l->comp == 0){
        return 1;
    }
    else {
        return 0;
    }
}

// Retorna o n�mero de elementos de L.
int comprimento(Lista *l){
    return l->comp;
}


// Imprime em ordem os elementos de L.
void imprime(Lista *l){
    int i;

    for(i = 1; i <= l->comp; i++){
        printf("%d ", acessa(i, l));
    }

}

int main(){
    //Crio uma lista inicial com 10 elementos
    int i;
    TipoDaPosicao p, q, aux;
    Lista L;
    Lista * Lp;
    Lp = &L;

    inicializa(Lp);
    adiciona(5, Lp);
    adiciona(5, Lp);
    adiciona(5, Lp);
    adiciona(6, Lp);
    adiciona(6, Lp);
    adiciona(77, Lp);
    adiciona(77, Lp);
    adiciona(77, Lp);
    adiciona(13, Lp);
    adiciona(13, Lp);
    adiciona(5, Lp);
    adiciona(5, Lp);
    adiciona(77, Lp);
    adiciona(123, Lp);
    adiciona(75, Lp);
    adiciona(54, Lp);
    adiciona(32, Lp);
    adiciona(6522, Lp);
    printf("\n original: ");
    imprime(Lp);
    /*
    Exemplo de c�digo cliente (veja como ele � constru�do usando somente as
    rotinas descritas acima): eliminar duplicatas de uma lista com as opera��es
    acima
    */
    p = primeiro(Lp);
    while(p != FIM){
        q = proximo(p, Lp);
        while(q != FIM){
            if(acessa(p, Lp) == acessa(q, Lp)){
                aux = proximo(q, Lp);

                remova(q, Lp);
                if(aux == FIM){
                     q = FIM;
                }
            }
            else{
                q = proximo(q, Lp);
            }
        }
        p = proximo(p, Lp);
    }
    printf("\n duplicadas eliminadas: ");
    imprime(Lp);


    /*Desafio: c�digo do cliente que imprime uma lista invertida.*/
    TipoDoElemento elemfinal, eleminicial;
    int tamanho;
    p = primeiro(Lp);
    q = proximo(p, Lp);
    if(q != FIM){
        while(proximo(q, Lp) != FIM){
            q++;
        }
    }
    tamanho = q;
    for(i=p; i<=tamanho/2;  i++){
        eleminicial = acessa(p, Lp);
        elemfinal =  acessa(q, Lp);
        remova(p, Lp);
        insere(elemfinal, p, Lp);
        remova(q, Lp);
        insere(eleminicial, q, Lp);
        p++;
        q--;
    }

    printf("\n invertida: ");
    imprime(Lp);
    return 0;
}
