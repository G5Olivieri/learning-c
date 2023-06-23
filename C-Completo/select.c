#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selection(char *item, size_t size);

int main(int argc, char* argv[])
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";
	puts(str);
	selection(str, strlen(str));
	puts(str);
	putchar('\n');
	exit(EXIT_SUCCESS);
}

void selection(char* item, size_t size)
{
	register int a, b, c;
	int exchange;
	register char t;
	for(a = 0; a < size-1; ++a){
		exchange = 0;
		c = a;
		t = item[a];
		for(b = a+1; b < size; b++)
			if(item[b] < t){
				c = b;
				t = item[b];
				exchange = 1;
			}
		if(exchange){
			item[c] = item[a];
			item[a] = t;
		}
	}
}
