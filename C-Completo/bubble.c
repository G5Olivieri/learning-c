#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble(char *item, size_t size);
void shaker(char *item, size_t size);

int main(int argc, char* argv[])
{
	char str[] = "meu nome nao eh Jonny";
	puts(str);
	bubble(str, strlen(str));
	puts(str);
	putchar('\n');
	exit(EXIT_SUCCESS);
}

void bubble(char* item, size_t size)
{
	register int a, b;
	register char t;
	for(a = 0; a < size-1; a++)
		for(b = size; b > a; b--)
			if(item[b-1] > item[b] && item[b] != ' '){
				t = item[b];
				item[b] = item[b-1];
				item[b-1] = t;
			}
}

void shaker(char* item, size_t size) /*bubble melhorada, porem ainda continua lento*/
{
	register int a;
	int exchange;
	register char t;
	do{
		exchange = 0;
		for(a = size-1; a > 0; a--)
			if(item[a-1] > item[a]){
				t = item[a];
				item[a] = item[a-1];
				item[a-1] = t;
				exchange = 1;
			}
		for(a = 1; a< size; a++)
			if(item[a-1] > item[a]){
				t = item[a];
				item[a] = item[a-1];
				item[a-1] = t;
				exchange = 1;
			}
	}while(exchange);
}
