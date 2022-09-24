#include <stdio.h>


int main(){
    int vote_list[6] = {0};
    int vote, i;
    int counter = 0;
    
    for (counter = 0; counter < 5; counter++){
        printf("Digite o voto: ");
        scanf("%i", &vote);

        if (vote == 1){
            vote_list[0] ++;
        }
        else if (vote == 2){
            vote_list[1] ++;
        }
        else if (vote == 3){
            vote_list[2] ++;
        }
        else if (vote == 4){
            vote_list[3] ++;
        }
        else if (vote == 5){
            vote_list[4] ++;
        }
        else {
            vote_list[5] ++;
        }

    }
    for (i = 0; i < 4; i++){
        printf("Candidato %i obteve %i votos\n", i+1, vote_list[i]);
    }
    printf("Houve %i votos nulos", vote_list[5])
    
    return 0;


}