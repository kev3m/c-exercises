#include <stdio.h>

 
/*
Calculadora IMC
int main(){
    float imc,peso,altura;

    printf("Digite a altura:");
    scanf(" %f", &altura);

    printf("Digite o peso:");
    scanf(" %f", &peso);

    imc = peso/(altura *altura);
    printf("IMC = %.2f", imc);
    return 0;
}
*/

/* Um grupo de amigos pretende alugar um carro por um único
dia. Consultadas duas agências, a primeira cobra R$62,00 pela
diária e R$1,40 por quilômetro rodado. A segunda cobra diária
de R$80,00 e mais R$1,20 por quilômetro rodado. Escreva um
programa que leia a quantidade de quilômetros a serem
rodados e calcule e imprima na tela o preço a ser pago em cada
uma das agências. 

int main(){
    int km;
    float primeira_agencia_valor,segunda_agencia_valor;

    printf("Digite a quantidade de KMs rodados: ");
    scanf("%i",&km);
    primeira_agencia_valor = 62 + (1.4 * km);
    segunda_agencia_valor = 80 + (1.2 * km);
    printf("Na primeira agencia o valor cobrado sera R$ %.2f.\nNa segunda agencia o valor cobrado sera R$ %.2f",primeira_agencia_valor, segunda_agencia_valor);
    return 0;

}
*/

/* Escreva um programa que calcule o valor do desconto de uma
mercadoria paga a vista e o valor total a ser pago. O programa deve
ler o valor da mercadoria e a porcentagem do desconto. Depois o
programa deve calcular e imprimir na tela o valor do desconto e o
novo valor da mercadoria com o desconto. 

int main(){
    float valor_mercadoria,valor_mercadoria_disconto;
    int percent_discount;

    printf("Digite o valor da mercadoria: ");
    scanf("%f", &valor_mercadoria);
    printf("Digite o valor do desconto: ");
    scanf("%i", &percent_discount);

    valor_mercadoria_disconto = valor_mercadoria - (valor_mercadoria * percent_discount/100);
    printf("O valor da mercadoria com desconto: R$ %.2f", valor_mercadoria_disconto);
    return 0;

}
*/

/* Escreva um programa para ajudar a calcular a quantidade de gotas de
um remédio que uma determinada criança precisa tomar. A bula
desse remédio pediátrico recomenda a seguinte dosagem: 5 gotas
para cada 2 kg do peso da criança. Você deve fazer um programa que
leia o peso desta criança, calcule e imprima na tela a quantidade de
gotas a ser tomada.

int main(){
    int peso, gotas;
    printf("Digite o peso desta criança: ");
    scanf("%i", &peso);

    gotas = (peso / 2) * 5;
    printf("A crianca devera tomar: %i gotas", gotas);
    return 0;

}

*/