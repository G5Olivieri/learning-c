#include <stdio.h>
#include <stdlib.h>

#define min(a, b) a < b ? a : b

#define MAX 4096

void merge(double *arr, int l, int m, int r)
{
	int i, j, k, n1 = m - l + 1, n2 = r - m;
	double *L = (double*)malloc(n1 * sizeof(double));
	double *R = (double*)malloc(n2 * sizeof(double));

	for (i = 0; i < n1; i++) L[i] = arr[l + i];
	for (i = 0; i < n2; i++) R[i] = arr[m + i + 1];

	i = j = k = 0;
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];
	free(L); free(R);
}

int main() 
{
	double *array = (double*)malloc(MAX * sizeof(double)), input;
	int size = 0, i, j;
	FILE *f;
	if ((f = fopen("values.txt", "r")) == NULL) {
		perror("could not open file");
		return 0;
	}

	while(fscanf(f, "%lf", &input) != EOF) {
		array[size++] = input;
		if (size % MAX == 0) {
			array = (double*)realloc(array, ((size / MAX) + 1) * MAX * sizeof(double));
		}
	}
	fclose(f);
	for (i = 1; i < size; i = 2 * i) 
	{
		for (j = 0; j < size - 1; j+= 2*i) 
		{
			merge(array, j, min(j+i-1, size-1), min(j+(2*i)-1, size - 1));
		}
	}

	printf("[%lf, ", array[0]);
	for (i = 1; i < size - 1; i++) printf("%lf, ", array[i]);
	printf("%lf]\n", array[size-1]);
	free(array);
	return 0;
}
