#include<stdio.h>
#include<stdlib.h>

typedef struct cel { 
            int conteudo; 
            struct cel *proximo; 
} Celula;

void inserir(Celula **fila, int num){
    Celula *aux, *nova = malloc(sizeof(Celula));
    if (nova){
        nova->conteudo = num;
        nova->proximo = NULL;//POSTO NO FINAL
        if (*fila == NULL){
            *fila == nova;
        }
        else {
            aux = *fila;
            while(aux->proximo != NULL){
                aux = aux->proximo;
            }
            aux->proximo = nova;

        }
    }
    else {
        printf("Não foi possível alocar");
    }
}

Celula *remover(Celula **fila){
    Celula *remover = NULL;
    if (*fila){
        remover = *fila;
        *fila = remover->proximo;
    }
    else 
    printf("fila vazia");
}
