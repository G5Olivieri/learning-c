#include <cstdio>
#include <cstdlib>
#include <ctime>

typedef struct Lista
{
	int value, size, position;
	struct Lista* next, *ant;
}lista, *plista;

plista iniciaLista()
{
	plista l = (plista)malloc(sizeof(lista));
	l->value = l->position = l->size = 0;
	l->next = l->ant = NULL;
	return l;
}

bool testEmpty(plista l)
{
	if(!l->next) return true;
	else return false;
}

plista pusher()
{
	plista tempNode = (plista)malloc(sizeof(lista));
	if(!tempNode)
	{
		printf("Sem memoria: ");
		return NULL;
	}
	else
	{
		tempNode->value = rand()%50001;
		tempNode->next = tempNode->ant = NULL;
		return tempNode;
	}
}

void atualiza(plista l)
{
	plista tempNode = l->next;
	int i;	
	for(i = 1; i <= l->size; i++)
	{
		tempNode->position = i;
		tempNode = tempNode->next;
	}
}

plista lastElement(plista l)
{
	if(!l->next) return l;
	else return lastElement(l->next);
}

void pushFirst(plista l, plista newNode)
{
	newNode->position = 1;
	newNode->ant = l;
	l->next = newNode;
	l->size++;
}

void pushBegin(plista l)
{
	plista newNode = pusher();
	if(testEmpty(l))
		pushFirst(l, newNode);
	else
	{
		newNode->ant = l;
		newNode->next = l->next;
		l->next->ant = newNode;
		l->next = newNode;		
		l->size++;
		//atualiza(l);
	}
}

void pushEnd(plista l)
{
	plista newNode = pusher();
	if(testEmpty(l))
		pushFirst(l, newNode);
	else
	{
		plista lastNode = lastElement(l);
		lastNode->next = newNode;
		newNode->ant = lastNode;
		l->size++;
		atualiza(l);
	}
}

void pushPosition(plista l, int p)
{
	plista newNode = pusher();
	if(testEmpty(l))
	{
		pushFirst(l, newNode);
		printf("Lista vazia, elemento colocado na primeira posicao: ");
	}
	else
	{
		plista atualNode = l->next;

		while(atualNode->position != p)
			atualNode = atualNode->next;

		newNode->next = atualNode;
		newNode->ant = atualNode->ant;
		atualNode->ant->next = newNode;
		atualNode->ant = newNode;
		l->size++;
		atualiza(l);
	}
}

void popFirst(plista l)
{
	free(l->next);
	l->next = NULL;
    l->size--;
 	atualiza(l);
}

void popBegin(plista l)
{
	plista atualNode = l->next;
	if(testEmpty(l))
		popFirst(l);
	else
	{
        atualNode = l->next;
        atualNode->next->ant = l;
        l->next = atualNode->next;
        l->size--;
		atualiza(l);
		free(atualNode);
	}
}

void popEnd(plista l)
{
	if(testEmpty(l))
		popFirst(l);
	else
	{
		plista antLastNode = lastElement(l);
		antLastNode = antLastNode->ant;
		free(antLastNode->next);
		antLastNode->next = NULL;
		l->size--;
	}
}

void popPosition(plista l, int p)
{
	plista atual = l->next;
	if(testEmpty(l))
		popFirst(l);
	else
	{
		while(atual->position != p)
			atual = atual->next;
		atual->ant->next = atual->next;
		atual->next->ant = atual->ant;
		free(atual);
		l->size--;
		atualiza(l);
	}
}

lista* show(plista l)
{
	if(!l->next) return l;
	else
	{
		printf("Value: %d\n", l->next->value);
		return show(l->next);
	}
}
	
void clear(plista l)
{
	if(testEmpty(l))
	{
		printf("Lista vazia: ");
	}
	else
	{
		plista tempNode = lastElement(l);
		while(tempNode != l)
		{
			tempNode = tempNode->ant;
			free(tempNode->next);
		}
		printf("Lista vazia: ");
	}
}

void bubbleSort(plista l)
{
	int i, j, temp;
	plista ptr;
	for(i = 0; i < l->size-1; i++)
	{
		ptr = lastElement(l);
		for(j = l->size; j > i; j--)
		{
			if(ptr->ant->value > ptr->value)
			{
				temp = ptr->ant->value;
				ptr->ant->value = ptr->value;	
				ptr->value = temp;
			}
			ptr = ptr->ant;
		}
	}
}

void selectionSort(plista l)
{
	plista ptr = l;
	plista temp;
	int i, j, tempo;
	for(i = 0; i < l->size-1; i++)
	{
		ptr = ptr->next;
		temp = ptr;
		for(j = i+1; j < l->size; j++)
		{
			temp = temp->next;
			if(ptr->value > temp->value)
			{
				tempo = temp->value;
				temp->value = ptr->value;
				ptr->value = tempo;
			}
		}
	}
}

void insertionSort(plista l)
{
	plista ptr;
	plista trc;
	plista pivo = l->next;
	int i, temp;
	for(i = 0; i < l->size-1;i++)
	{
		ptr = pivo;
		trc = ptr;
		ptr = ptr->next;
		while((trc != l) && (trc->value > ptr->value))
		{
			temp = trc->value;
			trc->value = ptr->value;
			ptr->value = temp;
			ptr = trc;
			trc = trc->ant;
		}
		pivo = pivo->next;
	}
}

int main()
{
	time_t inicio = time(NULL);
	int i;
	system("clear");
	plista list = iniciaLista();
	int op, pos;
	do
	{
		printf("1 - Insere Inicio\n"
			   "2 - Insere Final\n"
			   "3 - Insere Posicao\n"
			   "4 - Retira Inicio\n"
			   "5 - Retira Final\n"
			   "6 - Retira Posicao\n"
			   "7 - Imprime Lista\n"
			   "8 - Limpa Lista\n"
			   "9 - Bubble Sort\n"
			   "10 - Selection Sort\n"
			   "11 - Insertion Sort\n"
			   "0 - Sair\n");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
				inicio = time(NULL);
				for(i = 0; i < 50001; i++)pushBegin(list);
				printf("\n%d\n", (time(NULL) - inicio));
				break;
			case 2:
				pushEnd(list);
				break;
			case 3:
				printf("Posicao que deseja inserir: ");
				scanf("%d", &pos);
				pushPosition(list, pos);
				break;
			case 4:
				popBegin(list);
				break;
			case 5:
				popEnd(list);
				break;
			case 6:
				printf("Posicao que deseja retirar: ");
				scanf("%d", &pos);
				popPosition(list, pos);
				break;
			case 7:
				inicio = time(NULL);
				show(list);
				printf("\n%d\n", time(NULL) - inicio);
				break;
			case 8:
				clear(list);
				break;
			case 9:
				inicio = time(NULL);
				bubbleSort(list);
				printf("\n%d\n%f por segundo\n", time(NULL) - inicio, (float)(50001/(time(NULL) - inicio)));
				break;
			case 10:
				inicio = time(NULL);
				selectionSort(list);
				printf("\n%d\n%f por segundo\n", time(NULL) - inicio, (float)(50001/(time(NULL) - inicio)));
				break;
			case 11:
				inicio = time(NULL);				
				insertionSort(list);
				printf("\n%d\n%f por segundo\n", time(NULL) - inicio, (float)(50001/(time(NULL) - inicio)));
				break;
			default:
				printf("Saindo..");
				op = 0;
		}
	}while(op);
	clear(list);
	free(list);
	printf("\n\n");
	return 0;
}
