#include <stdio.h>
#include <stdlib.h>

int binary(int*, int, int);
int sequential_search(int*, int, int);

int main(int argc, char *argv[])
{
	
	putchar('\n');
	exit(EXIT_SUCCESS);
}

int binary(int *item, int count, int key)
{
	int low, high, mid;
	low 0; high = count-1;
	while(low <= high){
		mid = (low +  high)/2;
		if(key < item[mid]) high = mid-1;
		else if(key>item[mid]) low = mid+1;
		else return mid;
	}
	return -1;
}

int sequential_search(char *item, int count, int key)
{
	register int i;
	for(i = 0; i < count; i++)
		if(key = item[i]) return i;
	return -1;
}
