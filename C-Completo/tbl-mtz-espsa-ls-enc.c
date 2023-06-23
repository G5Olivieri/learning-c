#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cell{
	char name[9];
	char formula[128];
	struct cell *next;
	struct cell *prior;
};

struct cell *start;
struct cell *last;

void dls_store(struct cell *i, struct cell **start, struct cell **last);
void delete(char *cell_name, struct cell **start, struct cell **last);
struct cell *find(char *cell_name, struct cell *start);


int main(int argc, char *argv[])
{		
	putchar('\n');
	exit(EXIT_SUCCESS);
}

void dls_store(struct cell *i, struct cell **start, struct cell **last)
{
	struct cell *old, *p;
	if(!*last){
		i->next = NULL;
		i->prior = NULL;
		*last = i;
		*start = i;
		return;
	}
	
	p = *start; /* topo da lista */

	old = NULL;

	while(p){
		if(strcmp(p->name, i->name) < 0){
			old = p;
			p = p->next;
		}
		else{
			if(p->prior){ /* elemento intermediario */
				p->prior->next = i;
				i->next = p;
				i->prior = p->prior;
				i->prior = i;
				return;
			}
			i->next = p; /* novo primeiro elemento */
			i->prior = NULL;
			p->prior = i;
			*start = i;
			return;		
		}
	}
	old->next = i; /* poe no final */
	i->next = NULL;
	i->prior = old;
	*last = i;
	return;
}

void delete(char *cell_name, struct cell **start, struct cell **last)
{
	struct cell *info;
	info = find(cell_name, *start);
	if(info){
		if(*start==info){
			*start = info->next;
			if(*start) (*start)->prior = NULL;
			else *last = NULL;
		}
		else{
			if(info->prior) info->prior->next = info->next;
			if(info != *last) info->next->prior = info->prior;
			else *last = info->prior;
		}
		free(info);
	}
}

struct cell *find(char *cell_name, struct cell *start)
{
	struct cell *info;
	info = start;
	while(info){
		if(!strcmp(cell_name, info->name)) return info;
		info = info->next;
	}
	puts("Célula não encontrada\n");
	return NULL;
}
