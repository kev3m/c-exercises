#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

    int i,troca,contador = 0, copy, vetor[100];

    srand(time(NULL));
    for (i = 0; i < 100; i++){
        vetor[i] = rand() % 100;
    }

    printf("Antes da ordenacao: \n");
    for(i = 0; i < 100; i++) {
        printf("%3d", vetor[i]);
    }

    do{
        troca = 0;
        contador++;
        for(i = 0; i < 99; i++){
                if(vetor[i] > vetor[i +1]){
                    copy = vetor[i];
                    vetor[i] = vetor[i + 1];
                    vetor[i + 1] = copy;
                    troca = 1; //troquei ao menos um elemento do vetor
                }
            }

    }while(troca);
    
    printf("\nApos a ordenacao: Contador %d\n", contador);
    for(i = 0; i < 100; i++) {
        printf("%3d", vetor[i]);
    }

    return 0;
}