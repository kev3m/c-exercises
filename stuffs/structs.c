#include <stdio.h>
 struct horario
    {
        int hours;
        int minutes;
        int seconds;

    };


int main(void) {

    //Receber uma struct de uma função
    

   

    struct horario agora;
    agora.hours = 15;
    agora.minutes = 30;
    agora.seconds = 50;

    printf("%i:%i:%i\n", agora.hours, agora.minutes, agora.seconds);

    return 0;

}

struct horario teste(struct horario x){

    return x;
}