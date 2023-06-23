#include <stdio.h>
#include <time.h>
#include <locale.h>

int main(int argc, char* argv[])
{
	register int i;
	clock_t inicio = clock();
	for(i = 0; i >= 0; i++);
	printf("%lds", (clock()-inicio)/CLOCKS_PER_SEC);
    difference();
    calen();
	putchar('\n');
	return 0;
}

void difference()
{
	int i;
	time_t inicio = time(NULL);
	for(i = 0; i >= 0; i++);
	printf("%lfs", difftime(time(NULL), inicio));	;
	putchar('\n');
}

void calen()
{
	setlocale(LC_TIME, "");
	time_t lc = time(NULL);
	struct tm *ptr = localtime(&lc);
	char str[101];

	strftime(str, 100, "Hoje é dia %d (%A-feira), mês %m, ano %Y\nAgora são %H:%M", ptr);
	puts(str);

	putchar('\n');
}
