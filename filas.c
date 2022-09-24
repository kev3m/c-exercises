#include <stdio.h>
#include <stdlib.h>


typedef struct celula {
	int dado;
	struct celula *proximo;
}Celula;

// Inserção
void inserir_na_fila(Celula **fila, int num){
    Celula *aux, *nova = malloc(sizeof(Celula));
    if (nova) {
        nova->dado = num;
        nova->proximo = NULL; //SEMPRE NULO POIS ESTÁ NO FINAL

        if(*fila == NULL){
            *fila = nova;

        }
        else {
            aux = *fila; //Não pode utilizar *fila pois se não a referência será perdida
            while(aux->proximo != NULL){
                aux = aux->proximo;
            
            }
            aux->proximo = nova;
        }
    }
    else {
        printf("Erro ao alocar memória");
        }
}
Celula* remover_da_fila(Celula **fila){
    Celula *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }
    else {
        printf("\tFila vazia\n");
    }
    return remover;

}
void imprimir(Celula *fila){
    printf("\t------ FILA ------\n\t");
    while(fila){
        printf("%d ", fila->dado);
        fila = fila->proximo;
    }


    printf("\n\t------ FIM DA FILA ------\n");
}

int main(){
    Celula *r, *fila = NULL; //Nossa fila é um ponteiro pro tipo celula -> Passamos o endereço dessa região para as funções
    
    int op, valor;

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
            imprimir(fila); //Mandando o conteúdo da variavel fila)
            break;
        
        default:
            if(op != 0){
                printf("Opção invalid");
            }
        }


    }while(op != 0);


    return 0;
}