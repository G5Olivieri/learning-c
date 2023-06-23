#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double sum_series(int num, ...);

int main(int argc, char* argv[])
{
	double d;
	d = sum_series(5, 0.5, 0.25, 0.125, 0.0625, 0.03125);
	printf("A soma da série: %f.\n", d);	
	putchar('\n');
	exit(EXIT_SUCCESS);
}

double sum_series(int num, ...)
{
	double sum = 0.0, t;
	va_list argptr;

	va_start(argptr, num);

	for(;num;num--){
		t = va_arg(argptr, double);
		sum += t;
	}

	va_end(argptr);
	return sum;
}

