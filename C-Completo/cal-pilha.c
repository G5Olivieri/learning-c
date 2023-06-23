#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int *p, *tos, *bos;
void push(int);
int pop();

int main(int argc, char *argv[])
{		
	char str[90];
	int a, b;
	if(!(p = (int*)malloc(MAX*sizeof(int)))){
		puts("Erro na memoria\n");
		exit(EXIT_FAILURE);
	}
	tos = p;
	bos = p+MAX-1;
	puts("Calculadora simples (s para sair)");
	do{
		putchar(':');
		gets(str);
		switch(*str){
			case '+':
				a = pop();
				b = pop();
				printf("=%d\n", b+a);
				push(b+a);
				break;
			case '-':
				a = pop();
				b = pop();
				printf("=%d\n", b-a);
				push(b-a);
				break;
			case '*':
				a = pop();
				b = pop();
				printf("=%d\n", b*a);
				push(b*a);
				break;
			case '/':
				a = pop();
				b = pop();
				if(!a){
					puts("Divisao por zero\n");
					break;
				}
				printf("=%d\n", b/a);
				push(b/a);
				break;
			case '.':
				a = pop();
				push(a);
				printf("%d\n", a);
				break;
			default:
				push(atoi(str));	
		}
	}while(tolower(*str) != 's');
	putchar('\n');
	exit(EXIT_SUCCESS);
}

void push(int n)
{
	if(p>bos){
		puts("Pilha cheia\n");
		return;	
	}
	*p = n;
	p++;
}

int pop()
{
	p--;
	if(p<tos){
		puts("Pilha vazia\n");
		return 0;
	}
	return *p;
}

