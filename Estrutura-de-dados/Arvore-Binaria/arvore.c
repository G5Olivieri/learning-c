#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct arvore
{
	int valor;
	struct arvore* direita;
	struct arvore* esquerda;
}no, *pno;

pno inserir(int num)
{
	pno ptr = (pno)malloc(sizeof(no));
	ptr->valor = num;
	ptr->direita = NULL;
	ptr->esquerda = NULL;
	return ptr;
}

void insere(pno a, int num)
{
	if(a)
	{
		if(num < a->valor)
		{
			if(!a->esquerda)
				a->esquerda = inserir(num);
			
			else
				insere(a->esquerda, num);
		}
		
		else if(num > a-> valor)
		{
			if(!a->direita)
				a->direita = inserir(num);
			else
				insere(a->direita, num);
		}
	}
}

void imprime(pno a)
{
	if(a)
	{
		imprime(a->esquerda);
		printf("%d ", a->valor);		
		imprime(a->direita);
	}
}

void limpa(pno a, pno ant)
{
	if(a)
	{
		limpa(a->esquerda, a);		
		if((!a->direita) && (!a->esquerda))
			if(a->valor < ant->valor)
			{
				ant->esquerda = NULL;
				free(a);
				limpa(ant->direita, ant);
			}
			else if(a->valor > ant->valor)
			{
				ant->direita = NULL;
				free(a);
			}
		limpa(a->direita, a);
	}
}

int main()
{
	pno root = inserir(10);
	long int i;
	time_t inicia = time(NULL);
	for(i = 0; i < 1000001; i++) insere(root, rand()%1000001);
	printf("%d\n", time(NULL) - inicia);
	scanf("%d", &inicia);
	inicia = time(NULL);	
	imprime(root);
	printf("\n%d\n", time(NULL) - inicia);
	scanf("%d", &inicia);
	limpa(root, root);
	printf("\n\n");
	free(root);
	return 0;
}
