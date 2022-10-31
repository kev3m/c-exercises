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
int QtdNos (arvore *);
int QtdNosInternos (arvore *);
int QtdNosFilhoUnico (arvore *);

void Imprime (arvore *, int);


void main()
{
	int item, opcao;
	arvore *raiz = NULL;

	do {
			system("cls");
			printf("\nEscolha um opcao: \n");
			printf(" 1 - Insere um elemento na avore.\n");
			printf(" 2 - Imprime em InOrdem.\n");
			printf(" 3 - Imprime em PreOrdem\n");
			printf(" 4 - Imprime em PosOrdem\n");
			printf(" 5 - Imprime a arvore.\n");
			printf(" 6 - Altura da arvore.\n");
			printf(" 7 - Quantidade de nos.\n");
			printf(" 8 - Quantidade de nos internos.\n");
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
					printf("A quantidade de nos da arvore eh %d.\n", QtdNos(raiz));
					Sleep(2500);
					break;

				case 8:
					printf("A quantidade de nos internos da arvore eh %d.\n", QtdNosInternos(raiz));
					Sleep(2500);
					break;
				case 9:
					printf("A quantidade de nos da arvore que possuem apenas 1 filho. %d.\n", QtdNosFilhoUnico(raiz));
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

void PosOrdem (arvore *raiz)
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

int QtdNos (arvore * r)
{
	if (r == NULL)
		return 0;
	else
		return 1 + QtdNos(r->esq) + QtdNos(r->dir);
}

int QtdNosInternos(arvore * r) {

	if (r == NULL)
		return 0;
	else if (r->esq == NULL && r->dir == NULL)
		return 0;
	else
		return 1 + QtdNosInternos(r->esq) + QtdNosInternos(r->dir);
}

int QtdNosFilhoUnico(arvore * r) {

	if (r == NULL)
		return 0;
	else if (r->esq == NULL && r->dir != NULL || r->esq != NULL && r->dir == NULL)
		return 1 + QtdNosFilhoUnico(r->esq) + QtdNosFilhoUnico(r->dir);
}
