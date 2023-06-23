#include <stdio.h>
#include <stdlib.h>

#define MAX 3000000

void quick(int *item, size_t size);
void cq(int *item, int left, int right);

int main(int argc, char* argv[])
{
	int i;
	int matriz[MAX];
	for(i = 0; i < MAX; i++) matriz[i] = rand()%MAX;
	quick(matriz, MAX);
	exit(EXIT_SUCCESS);
}
void quick(int *item, size_t size)
{
	cq(item, 0, size);
}

void cq(int *item, int left, int right)
{
	register int l, r;
	int medio, temp;
	l = left;
	r = right;
	medio = item[(left+right)/2]; // recebe o termo medio
	do{
		while(item[a] < medio && right > l) l++; // encontra os menores que o medio
		while(item[b] > medio && left < r) r--; // encontra os maiores que o medio
		if(l <= r){ /* passa o menor para a esquerda e maior para a direita */
			temp = item[l];
			item[l] = item[r];
			item[r] = y;
			l++; r--;
		}
	}while(a <= b); // faz até todos os menores para esquerda e maiores para direita
	if(left < b) cq(item, left, b); // faz o processo com todos da esquerda até b seja o mesmo valor que left
	if(right > a) cq(item, a, right);
}
