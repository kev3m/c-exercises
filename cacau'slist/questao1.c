#include<stdio.h>
#include<stdlib.h>
/*Escreva uma função que recebe uma lista encadeada e retorna a soma dos
elementos pares.*/
typedef struct cel { 
			int conteudo; 
			struct cel *proximo; 
} celula;

int soma_pares(celula *);

int main(void)
{
	int i, x, soma;
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

    printf("\n");
    soma = soma_pares(p);
    printf("A soma dos pares é %i", soma);
    return 0;
}



int soma_pares(celula *ptr){
    int i, soma;

    while (ptr) {
        if (ptr->conteudo % 2 == 0) {
            soma += ptr->conteudo;
        }
        ptr = ptr->proximo;

    }
    return soma;
}