#include<stdio.h>
#include<stdlib.h>
/*Escreva uma função que recebe uma lista encadeada e retorna a posição, a partir
do início da lista (posição 1), da primeira ocorrência de um valor n, recebido por
parâmetro. Se não houver, retornar o valor –1.*/
typedef struct cel { 
			int conteudo; 
			struct cel *proximo; 
} celula;

int buscar_posicao(celula *, int);

void main(void){
	int i, x,n, posicion;
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

    printf("Digite um elemento a ter sua posição buscada na lista:");
	scanf("%d", &n);

    
    posicion = buscar_posicao(p, n);
    printf("O elemento %i, esta na posicao %i", n, posicion);
    
}

int buscar_posicao(celula *ptr,int n){
    int posicao;

    while(ptr) {
        if (ptr->conteudo != n) {
            posicao += 1;
        }
        else {
            break;
        }
    }

    return posicao;
}