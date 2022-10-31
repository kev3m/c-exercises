#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no* esq;
    struct no* dir;

}arvore;

void insere (arvore **raiz, int cont){
    arvore *p, *aux, *novo;


    if (*raiz == NULL){
        *raiz = malloc(sizeof(arvore));
    }

}

int main() {

    arvore *raiz = NULL;
    return 0;
}