#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ptr[54];
	scanf("%[^\n]", ptr);
	printf("%s\n", ptr);
	scanf(" %[a-z A-Z0-9]", ptr);
	printf(ptr);
	printf("\n");
	return 0;
}

int decimalvir()
{
	int av, dv;
	printf("Digite um valor decimal (utilize ,): ");
	scanf("%d%*c%d", &av, &dv);
	printf("O valor eh = %d,%d", av, dv);
	printf("\n");
	return 0;
}
