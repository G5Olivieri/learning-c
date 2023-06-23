#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define FERRO -12345

int fila[MAX];
int spos, rpos;

void push(int n)
{
	if(spos+1 == rpos || (spos+1 == MAX && !rpos)){
		puts("Erro pilha cheia");
		return;
	}
	fila[spos] = n;
	spos++;	
	if(spos == MAX) spos = 0;
}

int pop()
{
	if(rpos == MAX) rpos = 0;
	if(rpos == spos){
		puts("Nao ha mais elementos\n");
		return FERRO;
	}
	rpos++;
	return fila[rpos-1];
}

#endif
