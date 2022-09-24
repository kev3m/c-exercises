#include<stdio.h>
#include<stdlib.h>
/*Escreva uma função que receba duas listas encadeadas de inteiros L1 e L2e
concatene-as. Ao final desse processo, L1 conterá os elementos das duas listas e
L2 estará vazia.*/
typedef struct cel { 
			int conteudo; 
			struct cel *proximo; 
} celula;

void imprimir_lista(celula *);

void main(void){
	int i, x,n, posicion;
	celula *p = NULL, *nova;
	celula *p2 = NULL, *nova2;


	// Lista 1
	for (i = 1; i<=5; i++)	
	{
		printf("Digite um elemento a ser inserido na lista:");
		scanf("%d", &x);
		nova = (celula *) malloc(sizeof (celula));
		nova->conteudo = x; 
		nova->proximo = NULL;
        while (p) {
            p = p->proximo;
        }
        p->proximo = nova;
    }

    imprimir_lista(p);
	
}

void imprimir_lista(celula *ptr){
	while (ptr){
		printf("%i", ptr->conteudo);
		ptr = ptr->proximo;
	}
}

void inserir_final(celula *ptr, int x) {
    celula *nova;
    nova = (celula *) malloc(sizeof (celula));
    nova->conteudo = x; 
    nova->proximo = NULL;
    while (ptr) {
        ptr = ptr->proximo;
    }
    ptr->proximo = nova;
}
