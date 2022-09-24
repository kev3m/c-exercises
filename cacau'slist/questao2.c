#include<stdio.h>
#include<stdlib.h>
// Escreva uma função que recebe uma lista encadeada como parâmetro e remove o
// último elemento da lista.
typedef struct cel { 
			int conteudo; 
			struct cel *proximo; 
} celula;

void remover_ultimo(celula *);

int main(void){
	int i, x;
	celula *p = NULL, *nova;
	
	for (i = 1; i<=5; i++)	
	{
		printf("Digite um elemento a ser inserido na lista:");
		scanf("%d", &x);
		nova = (celula *) malloc(sizeof (celula));
		nova->conteudo = x; 
		nova->proximo = p;
		p = nova;
	}

    while (p) {
        printf("%i\n", p->conteudo);
        p = p->proximo;
    }
    printf("\n");
    
    remover_ultimo(p);

    while (p) {
        printf("%i\n", p->conteudo);
        p = p->proximo;
    }
    return 0;
}

void remover_ultimo(celula *ptr){
    celula *aux;

    while(ptr){
        aux = ptr->proximo;
        if (aux == NULL){
            free(ptr);
        }
        ptr = ptr->proximo;
    }


}