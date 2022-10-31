# include <stdio.h>
# include <stdlib.h>
# include <time.h>


typedef struct No{
	int chave;
	struct No* esq;
	struct No* dir;
} arvore;


void Insere (arvore ** , int);
void InOrdem (arvore *);
void PreOrdem (arvore *);
void PosOrdem (arvore *);
int Altura (arvore *);
int MenorElemento (arvore *, int);
arvore* RemoverMenorElemento (arvore *); 


void Imprime (arvore *, int);


void main()
{
	int item, opcao, ab,menor_el, x;
	arvore *raiz = NULL;
	arvore *removed;

	do {
			system("cls");
			printf("\nEscolha um opcao: \n");
			printf(" 1 - Insere um elemento na avore.\n");
			printf(" 2 - Imprime em InOrdem.\n");
			printf(" 3 - Imprime em PreOrdem\n");
			printf(" 4 - Imprime em PosOrdem\n");
			printf(" 5 - Imprime a arvore.\n");
			printf(" 6 - Altura da arvore.\n");
			printf(" 7 - Menor elemento dentre os maiores que x.\n");
			printf(" 8 - Remove o menor elemento.\n");
			printf(" 15 - Sai do Programa.\n");
			printf("Opcao: ");
			scanf("%d", & opcao);
    
			switch(opcao)
			{
				case 1:
					printf("Digite o elemento a ser inserido na arvore: ");
					scanf("%d",&item);
					Insere(&raiz, item);
					break;
								  
				case 2:
					InOrdem(raiz);
					Sleep(2500);
					break;

				case 3:
					PreOrdem(raiz);
					Sleep(2500);
					break;
				
				case 4:
					PosOrdem(raiz);
					Sleep(2500);
					break;
				
				case 5:
					Imprime(raiz,1);
					Sleep(2500);
					break;
					
				case 6:
					printf("A altura da arvore eh %d.\n", Altura(raiz));
					Sleep(2500);
					break;

				case 7:
					printf("Digite o elemento x: ");
					scanf("%d",&x);
					menor_el = MenorElemento(raiz, x);
					printf("Menor elemento dentre os maiores que x: %i", menor_el);
					Sleep(2500);
					break;

				case 8:

					removed = RemoverMenorElemento(raiz);
					printf("O menor elemento: %i foi removido", removed->chave);
					Sleep(2500);
					break;

				case 15:
					printf("\nFim do programa!!!\n");
					break;

				default:  
					printf("\nOpcao invalida!\n"); 
					break;
	}
	
  } while (opcao != 15);
  
  
}

void Insere (arvore **raiz, int x)
{
	arvore *p, *aux, *novo;

	novo = (arvore*) malloc(sizeof(arvore));
	novo->chave = x;
	novo->dir = NULL;
	novo->esq = NULL;

	if(*raiz == NULL)
		*raiz = novo;
	else
	{
		p = (*raiz);
		if(x >= p->chave)
			aux = p->dir;
		else
			aux = p->esq;

		while(aux!= NULL)
		{
			p = aux;
			if(x >= p->chave)
				aux = p->dir;
			else
				aux = p->esq;
		}

		if(x >= p->chave)
			p->dir= novo;
		else
			p->esq= novo;
	}
}

void Imprime(arvore * no, int l) {
	int i; 

	if (no == NULL) 
		return; 

	// Imprime a sub-árvore direita
	Imprime(no->dir, l+1); 

	// Imprime o espacamento do elemento
	for(i = 0; i < l; i++) {
		printf("      ");
	}

	printf("%d\n", no->chave); 

	// Imprime a sub-árvore esquerda
	Imprime(no->esq, l+1);
}

void InOrdem (arvore *raiz)
{
	if(raiz)
	{
		InOrdem(raiz->esq);
		printf("%d ", raiz->chave);
		InOrdem(raiz->dir);
	}
}

void PreOrdem (arvore *raiz)
{
	if(raiz)
	{
		printf("%d ", raiz->chave);
		PreOrdem(raiz->esq);
		PreOrdem(raiz->dir);
	}
}

void PosOrdem (arvore *raiz) //Só pode printar a raiz depois de ter olhado a esquerda e a direita
{
	if(raiz)
	{
		PosOrdem(raiz->esq);
		PosOrdem(raiz->dir);
		printf("%d ", raiz->chave);
	}
}

int Altura (arvore *r)
{
	int hL, hR;
	if (r == NULL)
		return -1;
	else
	{
		hL = Altura(r->esq);
		hR = Altura(r->dir);
		if (hL > hR)
			return hL + 1;
		else
			return hR + 1;
	}
}

int MenorElemento (arvore *r, int x){
	int menor;
	if (r == NULL){
		return -1;
	}
	else {
		if (r->esq == NULL){
			return r->chave;
		}
		else {
			//se x for maior que a raiz, vai pela direita
			if (r->chave < x ){ 
				return MenorElemento(r->dir, x);
			}
			//se x for menor que a raiz, vai pela esquerda
			else if (r->chave > x) {
				return MenorElemento(r->esq, x);
		}	
		}
	
		}	
}


arvore *RemoverMenorElemento(arvore* r) {
	if (r->esq == NULL) {
		arvore* aux = r->dir;
		free(r);
		return aux;
	}
	r->esq = RemoverMenorElemento(r->esq);
	return r;
}