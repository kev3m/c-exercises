#include <stdio.h>
#include <stdlib.h>


// Primo mais próximo = 2 * 15 = 29 ou 31
#define TAM 31 // Constante cujo valor não pode ser alterado

void inicializar_Tabela(int t[]){
    int i;

    for(i = 0; i < TAM; i++)
        t[i] = 0;	//Insere zero em todos os espaços alocados na lista
}

int funcao_Hash(int chave){
    return chave % TAM;	//Função de espalhamento
}

void inserir(int t[],int valor){
    int id = funcao_Hash(valor); //Criando o ID
    
    while(t[id] != 0){
        id = funcao_Hash(id + 1); //Percorrendo até encontrar um espaço vazio
    }
    t[id] = valor;
}

int busca(int t[], int chave){
    int id = funcao_Hash(chave);
    while(t[id] != 0){
        if(t[id] == chave)
            return t[id];
        else 
            id = funcao_Hash(id + 1);

    }
    return 0;
}

void imprimir(int t[]){
    int i;
    for (i = 0; i < TAM; i++ ){
        printf("%d = %d\n",i ,t[i]);
    }
}

int main(){

    int opcao, valor,retorno, tabela[TAM];

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