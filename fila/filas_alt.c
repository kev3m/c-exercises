#include <stdio.h>
#include <stdlib.h>


typedef struct celula {
	int dado;
	struct celula *proximo;
}Celula;

typedef struct {
    Celula *prim;
    Celula *fim;
    int tam;

}Fila;

void criar_fila(Fila *fila){
    fila->prim = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

// Inserção
void inserir_na_fila(Fila *fila, int num){
    Celula *aux, *nova = malloc(sizeof(Celula));
    if (nova) {
        nova->dado = num;
        nova->proximo = NULL; //SEMPRE NULO POIS ESTÁ NO FINAL

        if(fila->prim == NULL){
            fila->prim = nova;
            fila->fim = nova;
        }
        else {
            fila->fim->proximo = nova;
            fila->fim = nova;
        }
        fila->tam++;
    }
    else {
        printf("Erro ao alocar memória");
        }
}

Celula* remover_da_fila(Fila *fila){
    Celula *remover = NULL;

    if(fila ->prim){
        remover = fila->prim;
        fila->prim = remover->proximo; //Evitando perder a referência
        fila->tam--;
    }
    else {
        printf("\tFila vazia\n");
    }
    return remover;

}

void imprimir(Fila *fila){
    Celula *aux = fila->prim;
    
    printf("\t------ FILA ------\n\t");
    while(aux){
        printf("%d ", aux->dado);
        aux = aux->proximo;
    }


    printf("\n\t------ FIM DA FILA ------\n");
}
int main(){
    Celula *r;
    Fila fila; //Nossa fila não pode ser um ponteiro do tipo celula, mas sim um elemento do tipo fila
    int op, valor;


    criar_fila(&fila);
    do {
        printf("\t0 - Sair\n\t1-Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_na_fila(&fila, valor); //ENVIANDO O ENDEREÇO DA FILA
            break;
        case 2:
            r = remover_da_fila(&fila); //ENVIANDO
            if (r) {
                printf("Removido: %d\n", r->dado);
                free(r);
            }
            break;
        case 3:
            imprimir(&fila); //Mandando o conteúdo da variavel fila)
            break;
        
        default:
            if(op != 0){
                printf("Opção invalid");
            }
        }


    }while(op != 0);


    return 0;
}