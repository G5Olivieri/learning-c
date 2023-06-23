#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE* arq;
	if(!(arq = fopen("qulauq", "r"))){
		perror("Deixa de ser idiota");
		exit(1);
	}
	putchar('\n');
	return 0;
}
