#include <stdio.h>
#include <stdlib.h>

int comp(const void*, const void*);

int main(int argc, char* argv[])
{
	
	putchar('\n');
	exit(EXIT_SUCCESS);
}

comp(const int *i, const int *j){
	return *(int*)i - *(int *)j;
}
