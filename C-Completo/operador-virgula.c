#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, y;
	a = (y=4, ++y);
	printf("%d ", a);
	printf("\n");
	return 0;
}
