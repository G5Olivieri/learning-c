#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 2094288

void bubble(int *item, size_t size);
void shaker(int *item, size_t size);
void insertion(int *item, size_t size);
void selection(int *item, size_t size);
void shell(int *item, size_t size);
void sort(const char* str, int *item, size_t size, void (*sorte)(int *, size_t));
void cq(int *item, int left, int right);
void quick(int *item, size_t size);

int main(int argc, char* argv[])
{
	int matriz[MAX];		
	sort("Quick", matriz, MAX, &quick);
	sort("Shell", matriz, MAX, &shell);		
	sort("Insert", matriz, MAX, &insertion);
	sort("Select", matriz, MAX, &selection);
	sort("Bubble", matriz, MAX, &bubble);
	sort("Shaker", matriz, MAX, &shaker);
	exit(EXIT_SUCCESS);
}

void sort(const char* str, int *item, size_t size, void (*sorte)(int*, size_t))
{
	register int i;
	time_t inicio;
	for(i = 0; i < size; i++) item[i] = rand() % MAX;	
	inicio = time(NULL);
	sorte(item, size);
	printf("%s %.0fs\n", str, difftime(time(NULL), inicio));	
}

void shell(int* item, size_t size)
{
	register int a, b, gap, k;
	int t, ng[] = {10999, 8999, 4999, 2499, 999, 899, 499, 299, 149, 99, 89, 49, 25, 11, 9, 5, 3, 2, 1};
	for(k=0; k< sizeof(ng)/sizeof(int); k++){
		gap = ng[k];
		for(a = gap; a<size; ++a) {
			t = item[a];
			for(b = a-gap; t<item[b] && b >= 0; b -= gap)
				item[b+gap] = item[b];
			item[b+gap] = t;
		}
	}

}

void selection(int *item, size_t size)
{
	register int a, b, c;
	int exchange, t;
	for(a = 0; a < size-1; ++a){
		exchange = 0;
		c = a;
		t = item[a];
		for(b = a+1; b < size; b++)
			if(item[b] < t){
				c = b;
				t = item[b];
				exchange = 1;
			}
		if(exchange){
			item[c] = item[a];
			item[a] = t;
		}
	}
}

void insertion(int *item, size_t size)
{
	register int a, b;
	register char t;
	for(a = 1; a < size; ++a){
		t = item[a];
		for(b = a-1; b >= 0 && t<item[b]; b--)
			item[b+1] = item[b];
		item[b+1] = t;	
	}
}

void bubble(int *item, size_t size)
{
	register int a, b;
	register char t;
	for(a = 0; a < size-1; a++)
		for(b = size; b > a; b--)
			if(item[b-1] > item[b] && item[b] != ' '){
				t = item[b];
				item[b] = item[b-1];
				item[b-1] = t;
			}
}

void shaker(int *item, size_t size) /*bubble melhorada, porem ainda continua lento*/
{
	register int a;
	int exchange;
	register char t;
	do{
		exchange = 0;
		for(a = size-1; a > 0; a--)
			if(item[a-1] > item[a]){
				t = item[a];
				item[a] = item[a-1];
				item[a-1] = t;
				exchange = 1;
			}
		for(a = 1; a< size; a++)
			if(item[a-1] > item[a]){
				t = item[a];
				item[a] = item[a-1];
				item[a-1] = t;
				exchange = 1;
			}
	}while(exchange);
}

void quick(int *item, size_t size)
{
	cq(item, 0, size);
}

void cq(int *item, int left, int right)
{
	register int a, b;
	int x, y;
	a = left;
	b = right;
	x = item[(left+right)/2];
	do{
		while(item[a]<x && a < right) a++;
		while(x<item[b] && left < b) b--;
		if(a <= b){
			y = item[a];
			item[a] = item[b];
			item[b] = y;
			a++; b--;
		}
	}while(a <= b);
	if(left < b) cq(item, left, b);
	if(right > a) cq(item, a, right);

}
