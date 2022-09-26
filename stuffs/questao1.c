// Autor: Pedro - 2022.2 (Letra A)

#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
    int idade;
    char sexo;
    int filhos;
    float salario;
} Pessoa;

void media(Pessoa *, int, float *);
void salarios_altos_e_baixos(Pessoa *, int, char *, char *);
void reqs(Pessoa * ptr, int quantidade, int *);
void mulheres_com_filhos(Pessoa * ptr, int quantidade, int *);

int main (void) {
    int quantidade, i, somador_letraC, porcentagem;
    Pessoa * ponteiro;
    float media_salarios, maior_salario, menor_salario;
    char maior_salarioSexo, menor_salarioSexo;


    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &quantidade);

    ponteiro = (Pessoa *) malloc(quantidade * sizeof(Pessoa));

    for (i = 0; i < quantidade; i++) {
        printf("Idade: ");
        scanf("%d", &ponteiro[i].idade);

        printf("Sexo: ");
        scanf(" %c", &ponteiro[i].sexo);

        printf("Filhos: ");
        scanf("%d", &ponteiro[i].filhos);

        printf("Salario: ");
        scanf("%f", &ponteiro[i].salario);
    }

    media(ponteiro, quantidade, &media_salarios);

    printf("Media salarial: %2f\n", media_salarios);

    salarios_altos_e_baixos(ponteiro, quantidade, &maior_salarioSexo, &menor_salarioSexo);

    printf("O sexo com maior salario: %c\n", maior_salarioSexo);
    printf("O sexo com menor salario: %c", menor_salarioSexo);

	reqs(ponteiro, quantidade, &somador_letraC);

	printf("A quantidade de pessoas com menos de 30 anos, mais de 5 filhos e salário menor que R$ 1.000,00: %i ", somador_letraC);

	mulheres_com_filhos(ponteiro, quantidade, &porcentagem);
	
	printf("a porcentagem de pessoas do sexo feminino que possuem filhos que responderam a pesquisa: %i%", porcentagem*100);

    return 0;
}

void media(Pessoa * ptr, int quantidade, float * ptr_media) {
    float soma = 0;
    int i;

    for (i = 0; i < quantidade; i++) {
        soma += (ptr + i)->salario;
    }

    *ptr_media = soma / quantidade;
}

// Letra B
void salarios_altos_e_baixos(Pessoa * ptr, int quantidade, char * maiorSalarioSexo, char * menorSalarioSexo){

    int i;
    float maior,menor;
    float maior_aux,menor_aux;

    maior = (ptr)->salario;
    menor = (ptr)->salario;
    for (i = 0; i < quantidade; i++) {

        maior_aux = (ptr + i)->salario;
        menor_aux = (ptr + i)->salario;

        if (maior_aux > maior) {
            maior = maior_aux;
        }

        if (menor_aux < menor) {
            menor = menor_aux;
        }

    }
    for (i = 0; i < quantidade; i++) {
        if ((ptr + i)->salario = maior) {
            *maiorSalarioSexo = (ptr + i)->sexo;
        }
        else if ((ptr + i)->salario = menor); {
            *menorSalarioSexo = (ptr + i)->sexo;
        }

    }

    // *ptr_maior_salario = maior;
    // *ptr_menor_salario = menor;


}
// letra C
void reqs(Pessoa * ptr, int quantidade, int *somador) {
	int i,soma;

	for (i = 0; i < quantidade; i++) {
		if((ptr + i)->idade < 30 && (ptr + i)->salario < 1000 && (ptr + i)->filhos >5){
			soma += 1;
		}
	}
	*somador = soma;
}

// letra D
void mulheres_com_filhos(Pessoa * ptr, int quantidade, int * porcentagem){
	int i, soma_filhos;
	for (i = 0; i < quantidade; i++) {
		if ((ptr + i)->filhos > 1 && (ptr + i)->sexo == "F") {
			soma_filhos +=1;
		}
		else if ((ptr + i)->filhos > 1 && (ptr + i)->sexo == "f") {
			soma_filhos +=1;
		}
	*porcentagem = (soma_filhos / 100) * quantidade;
}