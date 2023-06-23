#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned int *code;

code encode(char* ch)
{
	srand((unsigned)time(NULL));
	int i;
	code en = (code)malloc(strlen(ch)*sizeof(int));
	for(i = 0; i < strlen(ch); i++)
	{
		en[i] = ch[i]<<10;
		en[i] = ~(en[i]);
		ch[i] = (rand()%27)+97;
	}
	return en;
}

void descode(code en, char* ch)
{
	int i;
	for(i = 0; i < strlen(ch); i++)
	{
		en[i] = ~(en[i]);
		ch[i] = en[i]>>10;
	}
}


int main()
{
	char a[] = "Meu nome nao eh Jhonny";
	code en = encode(a);
	int i;
	printf("Encripty %s\n", a);
	descode(en, a);
	printf("Descripty %s", a);
	printf("\n");
	free(en);
	return 0;
}
