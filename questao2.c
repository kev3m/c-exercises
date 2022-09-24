#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int account_number, agency_number;
    float salary;

} Cliente;
void single_func(Cliente *,int, float *, int *, int *, int *, int *, int *);
// void single_func(Cliente *,int, float *, float *, float *);


int main(void) {
    int n_clients,i;
    int high_account_num, high_agency_num, low_account_num, low_agency_num, percent;
    float salary_med, maior_salario,menor_salario;
    Cliente * ptr;

    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &n_clients);

    ptr = (Cliente *) malloc(n_clients * sizeof(Cliente));

    for (i = 0; i < n_clients; i++) {
        printf("Idade: ");
        scanf("%d", &ptr[i].account_number);

        printf("Sexo: ");
        scanf(" %c", &ptr[i].agency_number);

        printf("Salario: ");
        scanf("%f", &ptr[i].salary);
    }

    single_func(ptr, n_clients, &salary_med,&maior_salario, &menor_salario, &high_account_num,&high_agency_num,&low_account_num,&low_agency_num, &percent);
    printf("Media salarial>: %2f", salary_med);
    printf("Maior salario>: %2f", maior_salario);
    printf("Menor salario>: %2f", menor_salario);
    printf("High Account Number>: %i", high_account_num);
    printf("High Agency Number>: %i", high_agency_num);
    printf("Low Account Number>: %i", low_account_num);
    printf("Low Agency Number>: %i", low_agency_num); 
    printf("Porcentagem de clientes com saldo inferior a R$1000,00: %i", percent*100); 




    return 0;
}

void single_func(Cliente * ptr, int n_clients,float * ptr_media,int * ptr_high_account_num, int * ptr_high_agency_num, int * ptr_low_account_num, int * ptr_low_agency_num, int * ptr_poors_percent) {
// void single_func(Cliente * ptr, int n_clients,float * ptr_media,float * maior_salary, float * menor_salary) {
    float sum = 0,maior,menor,maior_aux,menor_aux;
    int soma_percent;
    int high_account_num, high_agency_num, low_account_num, low_agency_num, percent;
    float salario;
    int i;

    for (i = 0; i < n_clients; i++) {
        sum += (ptr + i)->salary;
    }

    *ptr_media = sum / n_clients;


    maior = (ptr)->salary;
    menor = (ptr)->salary;
    for (i = 0; i < n_clients; i++) {

        maior_aux = (ptr + i)->salary;
        menor_aux = (ptr + i)->salary;

        if (maior_aux > maior) {
            maior = maior_aux;
        }

        if (menor_aux < menor) {
            menor = menor_aux;
        }

    }

    for (i = 0; i < n_clients; i++) {
        salario = (ptr + i)->salary;
        if (salario == maior) {
            high_account_num = (ptr +i)->account_number;
            high_agency_num = (ptr +i)->agency_number;
        }
        else if (salario == menor) {
            low_account_num = (ptr +i)->account_number;
            low_agency_num = (ptr +i)->agency_number;
        }

    }

    for (int i = 0; i < n_clients; i++) {
        salario = (ptr +i)->salary;
        if (salario < 1000) {
            soma_percent += 1;
        }

    }
    percent = (soma_percent / 100) * n_clients;
    
    *ptr_poors_percent = percent;
    *ptr_high_account_num = high_account_num;
    *ptr_high_agency_num = high_agency_num;
    *ptr_low_account_num = low_account_num;
    *ptr_low_agency_num = low_agency_num;



    // *maior_salary = maior;
    // *menor_salary = menor;

}
