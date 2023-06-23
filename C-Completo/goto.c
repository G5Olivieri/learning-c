#include <stdio.h>

int main()
{
	int i = 0;
	loop1:
		i++;
		printf("%d ", i);
		if(i < 10) goto loop1;
	return 0;
}
