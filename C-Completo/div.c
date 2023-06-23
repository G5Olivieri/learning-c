#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	div_t n;
	n = div(10, 3);
	printf("quociente = %d, resto = %d", n.quot, n.rem);
	putchar('\n');
	exit(EXIT_SUCCESS);
}
