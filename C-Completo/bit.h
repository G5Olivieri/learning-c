#ifndef BIT_H
#define BIT_H
#include <stdio.h>

void teste()
{
	unsigned int a = 1;
	a = a<<1;
	a = a|1;
	printf("%d ", a);
	printf("\n");	
}

int par()
{
	unsigned int a;
	scanf("%d", &a);
	if(a&1) printf("impar %d ", a);
	else printf("par %d ", a);
	printf("\n");	
	return a;
}

#endif // BIT_H
