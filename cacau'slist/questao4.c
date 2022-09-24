#include<stdio.h>
#include<stdlib.h>
/*Escreva uma função que receba duas listas encadeadas de inteiros L1 e L2e
concatene-as. Ao final desse processo, L1 conterá os elementos das duas listas e
L2 estará vazia.*/
typedef struct cel { 
			int conteudo; 
			struct cel *proximo; 
} celula;

int concatenar_listas(celula *, celula*);
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
		nova->proximo = p;
		p = nova;
	}
	// Lista 2
	for (i = 1; i<=5; i++)	
	{
		printf("Digite um elemento a ser inserido na lista:");
		scanf("%d", &x);
		nova2 = (celula *) malloc(sizeof (celula));
		nova2->conteudo = x; 
		nova2->proximo = p;
		p2 = nova2;
	}

	concatenar_listas(p, p2);

	
}

void imprimir_lista(celula *ptr){
	while (ptr){
		printf("%i", ptr->conteudo);
		ptr = ptr->proximo;
	}
}

void concatenar_lista(celula *ptr, celula *ptr2) {
	celula *aux;

	while (ptr) {
		aux = ptr->proximo;
		if (aux == NULL) {
			ptr->proximo = ptr2;
		} 
		else {
			ptr = ptr->proximo;
		}
		
	}

}
