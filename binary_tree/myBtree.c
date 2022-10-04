# include <stdio.h>
# include <stdlib.h>
# include <conio.h>

typedef struct No{
	int chave;
	struct No* esq;
	struct No* dir;
} Arvore;

Arvore *initialize(){
    return NULL; //Inicializando árvore -> Definindo raiz como nula
}

Arvore *insert(Arvore *raiz,int cont){
     if(raiz == NULL) {
        Arvore *aux = (Arvore*)malloc(sizeof(Arvore));
        aux->chave = cont;
        aux->esq = NULL;
        aux->dir = NULL;
        return aux;
     }
}

int main(){
    Arvore *raiz = initialize();
    return 0;
}