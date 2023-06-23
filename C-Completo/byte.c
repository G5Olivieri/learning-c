#include <stdio.h>
#include <stdlib.h>

struct byte{
	unsigned primeiro: 1;
	unsigned segundo: 1;
	unsigned terceiro: 1;
	unsigned quarto: 1;
	unsigned quinto: 1;
	unsigned sexto: 1;
	unsigned setimo: 1;
	unsigned oitavo: 1;
	
}teste;

typedef struct byte Byte;

int main()
{	
	teste.oitavo = 1;
	printf("%d ", teste);	
	printf("\n");
	return 0;
}
