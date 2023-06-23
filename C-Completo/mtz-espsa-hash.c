#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 260

struct htype{
	int index; /* indice real */
	int val; /* valor real do elemento da matriz */
	struct htype *next; /* ponteiro para o proximo valor com mesmo fragmento */
}primary[MAX];

void delete(char *cell_name);
int find(char *cell_name);
void slstore(struct htype *i, struct htype *start);
void store(char *cell_name, int v);
void init();

int main(int argc, char *argv[])
{		
	putchar('\n');
	exit(EXIT_SUCCESS);
}

void init()
{
	register int i;

	for(i = 0; i < MAX; i++){
		primary[i].index = -1;
		primary[i].next = NULL;
		primary[i].val = 0;
	}
}

void store(char *cell_name, int v)
{
	int h, loc;
	struct htype *p;
	/* valor do hash */
	loc = *cell_name - 'A';
	loc += (atoi(&cell_name[1])-1) * 26;
	h = loc/10;

	/* armazena a posição a menos que esteja cheia ou 
	   armazena se os indices sao iguais - p.e., atualiza */

	if(primary[h].index == -1 || primary[h].index == loc){
		primary[h].index = loc;
		primary[h].val = v;
		return;
	}

	/* caso contrario, cria ou adiciona a uma lista de colisao */
	
	p = malloc(sizeof(struct htype));
	if(!p) {
		puts("Sem memoria");
		return;
	}

	p->index = loc;
	p->val = v;
	slstore(p, &primary[h]);
}

void slstore(struct htype *i, struct htype *start)
{
	struct htype *old, *p;
	old = start;
	while(start){ /* encontra o final da lista */
		old = start;
		start = start->next;
	}
	/* une a nova entrada */
	old->next = i;
	i->next = NULL;
}

int find(char *cell_name)
{
	int h, loc;
	struct htype *p;

	/* valor da hash */
	loc = *cell_name - 'A';
	loc = (atoi(&cell_name[1])-1) * 26;
	h = loc/10;

	/* devolve o valor se encontrou */
	if(primary[h].index == loc) return primary[h].val;
	else{ /* procura na lista de colisao */
		p = primary[h].next;
		while(p){
			if(p->next->index == loc) return p->val;
			p = p->next;
		}
		puts("Nao esta na matriz");
		return -1;
	}
}

/* exercicio: feito por Glayson Olivieri */

void delete(char *cell_name)
{
	int h, loc;
	struct htype *p, *e;
	/* valor do hash */
	loc = *cell_name - 'A';
	loc += (atoi(&cell_name[1])-1) * 26;
	h = loc/10;
	
	if(primary[h].index == -1){
		puts("Elemento nao encontrado");
		return;
	}
	if(primary[h].index == loc){
		primary[h].index = -1;
		primary[h].val = 0;
	}
	else {
		p = primary[h].next;
		while(p && (p->next->index != loc))
			p = p->next;
		e = p->next;
		p->next = e->next;
		free(e);
		return;
	}
}
