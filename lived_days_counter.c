#include <stdio.h>
/*Faça um programa que leia a idade de uma pessoa expressa em dias
e mostre-a expressa apenas em anos, meses e dias. Assuma, neste
programa, que um ano tem 365 dias e que um mês tem 30 dias.
Exemplo: Se a pessoa digitar que viveu 10260 dias significa que ela
tem 28 anos, 1 mês e 10 dias. */

int main(){
    int days_lived, days, months, years;
    printf("Digite a quantidade de dias vividos: "),scanf("%i",&days_lived);
    years = days_lived / 365, months = (days_lived - (years * 365)) / 30, days = days_lived - ((years * 365) + (months * 30));
    printf("%i anos, %i meses, %i dias.", years, months, days);

}