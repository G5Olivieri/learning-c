#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
	char *end, *start = "100.00 alicates 200.00 martelos";
	end = start;
	while(*start){
		printf("%.0f, ", strtod(start, &end));
		printf("Restante: %s\n", end);
		start = end;
		while(!isdigit(*start) && *start) start++;
	}
	putchar('\n');
	exit(EXIT_SUCCESS);
}

