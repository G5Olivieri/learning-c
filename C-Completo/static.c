#include "static.h"
extern int a;
static int porta = 1;

void setPorta(int n)
{
	porta *= n;
}

int getPorta()
{
	return porta;
}

int reg(int base, int exponencial)
{
	register int i;
	int value = 1;
	for(i = 0; i < exponencial; i++)
		value *= base;
	return value;
}
