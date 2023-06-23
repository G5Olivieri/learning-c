#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cell{
	char name[9];
	char formula[128];
};
struct cell *sheet[2600];

struct cell *find(char *cell_name);
void delete(struct cell *i);
void store(struct cell *i);
void init_sheet();

int main(int argc, char *argv[])
{		
	putchar('\n');
	exit(EXIT_SUCCESS);
}

void init_sheet()
{
	register int i;
	for(i =0; i<2600;i++) sheet[i] = NULL;
}

void store(struct cell *i)
{
	int loc;
	char *p;
	/* calculando a posição do ponto, exemplo A15 */
	loc = *(i->name) - 'A';
	p = &(i->name[1]);
	loc += (atoi(p)-1) * 26; /* linhas * colunas */

	if(loc >= 2600) {
		puts("Celula fora dos limites");
		return;
	}
	sheet[loc] = i;
}

void delete(struct cell *i)
{
	int loc;
	char *p;
	loc = *(i->name) - 'A';
	p = &(i->name[1]);
	loc += (atoi(p)-1) * 26;
	
	if(loc >= 2600) {
		puts("Celula fora dos limites");
		return;
	}

	if(!sheet[loc]) return;

	free(sheet[loc]);
	sheet[loc] = NULL;
}

struct cell *find(char *cell_name)
{
	int loc;
	char *p;

	loc = *(cell_name) - 'A';
	p = &(cell_name[1]);
	loc += (atoi(p)-1) * 26;
	
	if(loc >= 2600 || !sheet[loc]) { /* nenhuma entrada na celula */
		puts("Celula nao encontrada");
		return NULL;
	}
	else return sheet[loc];	
}
