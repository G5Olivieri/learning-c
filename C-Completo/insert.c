#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion(char *item, size_t size);

int main(int argc, char* argv[])
{
	char str[] = "zyxwvutsrqponmlkjihgfedcba";
	puts(str);
	insertion(str, strlen(str));
	puts(str);
	putchar('\n');
	exit(EXIT_SUCCESS);
}

void insertion(char* item, size_t size)
{
	register int a, b;
	register char t;
	for(a = 1; a < size; ++a){
		t = item[a];
		for(b = a-1; b >= 0 && t<item[b]; b--)
			item[b+1] = item[b];
		item[b+1] = t;	
	}
}
