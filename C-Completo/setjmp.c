#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf ebuf;
void f2();

int main(int argc, char* argv[])
{
	char first = 1;
	int i;
	printf("1 ");
	i = setjmp(ebuf);
	if(first){
		first = !first;		
		f2();
		puts("Isso nao sera escrito");
	}
	printf("%d ", i);
	putchar('\n');
	exit(EXIT_SUCCESS);
}

void f2(){
	printf("2 ");
	longjmp(ebuf, 3);
}
