#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula,idade;
    char nome, estado_civil;
    float valor;

} Cliente;


void single_func(Cliente *,int, float *, char *, char *, int *);
// void single_func(Cliente *,int, float *, float *, float *);


int main(void) {
    int n_clients,i;
    int  percent;
    float salary_med;
    char name, estado;
    Cliente * ptr;

    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &n_clients);

    ptr = (Cliente *) malloc(n_clients * sizeof(Cliente));

    for (i = 0; i < n_clients; i++) {
        printf("Nome: ");
        scanf("%c", &ptr[i].nome);

        printf("Idade: ");
        scanf("%i", &ptr[i].idade);

        printf("Matricula: ");
        scanf("%i", &ptr[i].matricula);

        printf("Valor apolice: ");
        scanf("%f", &ptr[i].valor);

        printf("Estado civil: ");
        scanf("%c", &ptr[i].estado_civil);
        while (&ptr[i].estado_civil != 'S' || &ptr[i].estado_civil != 'C' || &ptr[i].estado_civil || 'D') {
            printf("Estado civil incorreto ");
            scanf("%c", &ptr[i].estado_civil);
        }
    }

    single_func(ptr, n_clients, &salary_med,&name, &estado, &percent);
    printf("média de valores de apólice dos clientes casados>: %2f", salary_med);
    printf("Nome do cliente com o maior valor de apólice>: %c", name);
    printf("Estado Civil do cliente com o maior valor de apólice>: %c", estado);
    printf(" porcentagem de clientes com menos de 40 anos: %i", percent*100); 


    return 0;
}

void single_func(Cliente * ptr, int n_clients,float * ptr_media, char * nome, char * estado, int * porcentagem) {
    float sum = 0,maior,maior_aux, apolice,age;
    int soma_percent, percent, i;
    char estado,nome;

    for (i = 0; i < n_clients; i++) {
        estado = (ptr +i)->estado_civil;
        if (estado == 'C'){
          sum += (ptr + i)->valor;  
        }
        
    }

    *ptr_media = sum / n_clients;

    maior = (ptr)->valor;
    for (i = 0; i < n_clients; i++) {

        maior_aux = (ptr + i)->valor;

        if (maior_aux > maior) {
            maior = maior_aux;
        }

    }

    for (i = 0; i < n_clients; i++) {
        apolice = (ptr + i)->valor;
        if (apolice == maior) {
            *nome = (ptr + i)->nome;
            *estado = (ptr + i)->estado_civil;
        }

    }

    for (int i = 0; i < n_clients; i++) {
        age = (ptr +i)->idade;
        if (age < 40) {
            soma_percent += 1;
        }

    }
    percent = (soma_percent / 100) * n_clients;
    
    *porcentagem = percent;
    

}
