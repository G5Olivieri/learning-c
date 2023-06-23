#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10001


void shell(int *item, size_t size);

int main(int argc, char* argv[])
{
	time_t inicio;
	int i;
	int str[MAX];
	for(i = 0; i < MAX; i++) str[i] = rand() % MAX;
	inicio = time(NULL);
	shell(str, MAX);
	printf("%.0fs\n", difftime(time(NULL), inicio));
	getchar();
	exit(EXIT_SUCCESS);
}

void shell(int* item, size_t size)
{
	register int a, b, gap, k;
	int t, ng[] = {/*10999, 8999, 4999, 2499, 999, 899,*/ 499, 299, 149, 99, 89, 49, 25, 11, 9, 5, 3, 2, 1};
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
