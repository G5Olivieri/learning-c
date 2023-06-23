#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[61];
	char str2[] = "Glayson Picadilha";
	strcpy(str, str2);
	if(!strcmp(str, str2)) printf("%s == %s\n", str, str2);
	if(strchr(str, 'h')) printf("%s contem h\n", str);
	if(strlen(str) < 60) printf("Ainda tem espaco\n");
	strcat(str, " Moleque Zika");
	if(strstr(str, "Zika")) printf("%s contem Zika\n", str);
	printf("\n");
	return 0;
}

