#include <stdio.h>
#include <stdlib.h>


// Primo mais próximo = 2 * 15 = 29 ou 31
#define TAM 31 // Constante cujo valor não pode ser alterado

typedef struct no{
    int chave;
    struct no *proximo;

}No;

typedef struct {
    No *inicio;
    int tam;
}Lista;


void inicializar_Lista(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}

void inserir_na_Lista(Lista *l, int valor){
    No *novo = malloc(sizeof(No));
    if (novo){
        novo->chave = valor;
        novo->proximo = l->inicio;
        l->inicio = novo;
        l->tam++;
    }
    else 
        printf("Erro ao alocar memoria");
}

int buscar_na_Lista(Lista *l, int valor){
    No *aux = l->inicio;

    while(aux && aux->chave != valor)
        aux = aux->proximo;
    if (aux) // Descobrindo o que quebrou o while
        return aux->chave; //Encotnramos o elemento e estamos retornando o mesmo
    return 0; //Indica que o elemeneto não foi encontrado
}

void imprimir_lista(Lista *l){
    No *aux = l->inicio;
    printf("Tam: %d ", l->tam);
    while(aux){
        printf("%d", aux->chave);
        aux = aux->proximo;
    }

}

void inicializar_Tabela(Lista t[]){
    int i;

    for(i = 0; i < TAM; i++)
        inicializar_Lista(&t[i]); //Pega o endereço dos vetores
}

int funcao_Hash(int chave){
    return chave % TAM;	//Função de espalhamento
}

void inserir(Lista t[],int valor){
    int id = funcao_Hash(valor); //Criando o ID
    //Não trata colisões
    inserir_na_Lista(&t[id],valor); //Insere um endereço no vetor de lista
  
}
int busca(int t[], int chave){
    int id = funcao_Hash(chave);
    printf("\n Indice gerada: %d\n", id);
    return buscar_na_Lista(&t[id], chave);
}

void imprimir(Lista t[]){
    int i;
    for (i = 0; i < TAM; i++ ){
        printf("%2d = ", i);
        imprimir_lista(&t[i]);
        printf("\n");

    }
}

int main(){

    int opcao, valor,retorno;
    Lista tabela[TAM];

    inicializar_Tabela(tabela);

    do{
        printf("\n\t0 - Sair\n\t1-Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        scanf("%d",&opcao);
        
        switch (opcao)
        {
        case 1:
        printf("\tQual valor deseja inserir?");
        scanf("%d",&valor);
        inserir(tabela, valor);
            break;
        case 2:
        printf("\tQual valor deseja buscar?");
        scanf("%d",&valor);
        retorno = busca(tabela, valor);
        if(retorno != 0)  {
            printf("\tValor encontrado: %d\n", retorno);
            
            }
        else {
            printf("\tValor nao encontrado.");
        }
        break;
        case 3:
        imprimir(tabela);
            break;
        
        default:
            printf("Opcao invalida");
        }
    }while(opcao != 0);

    return 0;
}