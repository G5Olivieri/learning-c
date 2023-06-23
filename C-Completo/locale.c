#include <stdio.h>
#include <time.h>
#include <locale.h>

int main(int argc, char* argv[])
{
	struct lconv ls;
	ls = *localeconv();
	putchar(ls.p_sign_posn);
	putchar('\n');
	return 0;
}

int calen()
{
	setlocale(LC_ALL, "");
	time_t lc = time(NULL);
	struct tm *ptr = localtime(&lc);
	char str[101];

	strftime(str, 100, "Hoje é dia %d (%A-feira), mês %m, ano %Y\nAgora são %H:%M", ptr);
	puts(str);

	putchar('\n');
	return 0;
}
