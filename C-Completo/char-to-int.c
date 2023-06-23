#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charint(char* num);

int main()
{
	int i = 0;
	char op;
	scanf("%c", &op);
	if((op >= 48) && (op < 59))
	{	
		i = op - 48;
		printf("%d ", i);
	}	

	else printf("%c nao eh numero", op);
	printf("%d ", charint("4245"));	
	printf("\n");
	return 0;
}

charint(char* num)
{
	int tamanho = strlen(num);
	char temp[tamanho];
	int i, numero;	
	for(i = 0; i < tamanho; i++)
		temp[i] = num[tamanho-i-1];

	numero = 0;
	int mult = 1;
	for(i = 0; i < tamanho; i++)
	{
		if((temp[i] >= 48) && (temp[i] < 59)) numero += (temp[i]-48)*mult;
		else
		{
 			printf("%c nao eh numero imbecil\n", temp[i]);
			return 0;		
		}
		mult *= 10;
	}
	return numero;
}

