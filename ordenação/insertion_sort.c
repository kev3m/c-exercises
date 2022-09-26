// Similar a ordenação de cartas de baralho com as mãos
//Pega-se uma carta de cada vez e a coloca em seu devido lugar, sempre deixando as cartas da mão em ordem
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main() {

    int i, vetor[20];

    srand(time(NULL));
    for (i = 0; i < 20; i++){
        vetor[i] = rand() % 20;
    }

    printf("Antes da ordenacao: \n");
    for(i = 0; i < 20; i++) {
        printf("%3d", vetor[i]);
    }
    
    printf("\nApos a ordenacao: Contador %d\n", contador);
    for(i = 0; i < 20; i++) {
        printf("%3d", vetor[i]);
    }

    return 0;
}