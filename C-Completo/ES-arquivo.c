#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 128

int fmt1();
int fmt();
int fc();
void input(char *buf, int fd);
void output(char *buf, int fd);
int fg();
int func();
int qualquer();
int leitor(char* argv);

int main(int argc, char* argv[]) // programa etext - The Glayson Create File Text
{
	FILE* arquivo;
	char ch;
	int i = 1;
	if(argc < 2){
		puts("Digite o nome do arquivo\n");
		exit(1);
	}

	if(!(arquivo = fopen(argv[1], "w"))){
		puts("Erro ao abrir arquivo\n");
		exit(1);
	}
	printf("%d: ", i);
	ch = getchar();
	do{
		putc(ch, arquivo);
		ch = getchar();
		if(ch == '\n')
			printf("%d: ", ++i);

	}while(ch!=	'#');

	fclose(arquivo);
	printf("\n");
	return 0;
}

int leitor(char* argv) // leitor de arquivo
{
	FILE* arquivo;
	char ch;

	if(!(arquivo = fopen(argv[1], "r"))){
		puts("Erro ao abrir arquivo\n");
		exit(1);
	}

	ch = getc(arquivo);

	while(ch != EOF){
		putchar(ch);
		ch = getc(arquivo);
	}

	fclose(arquivo);
	printf("\n");
	return 0;
}

int qualquer()
{
	FILE* arquivo;
	char *str;

	if(!(arquivo = fopen("arquivo.txt", "w"))){
		puts("Erro ao abrir arquivo\n");
		exit(1);
	}

	do{
		puts("Digite uma string (enter para sair): ");
		gets(str);
		strcat(str, "\n");
		fputs(str, arquivo);
	}while(*str != '\n');

	fclose(arquivo);
	printf("\n");
	return 0;
}

int func()
{
	FILE* arquivo;
	int i, r;
	double d, g;
	float f, a;
	char c, x;

	if(!(arquivo = fopen("arquivo.txt", "wb+"))){
		puts("Erro ao abrir arquivo\n");
		exit(1);
	}

	scanf("%d%g%f %c", i, d, f, c);

	fwrite(&i, sizeof(int), 1, arquivo);
	fwrite(&d, sizeof(double), 1, arquivo);
	fwrite(&f, sizeof(float), 1, arquivo);
	fwrite(&c, sizeof(char), 1, arquivo);

	rewind(arquivo);

	fread(&r, sizeof(int), 1, arquivo);
	fread(&g, sizeof(double), 1, arquivo);
	fread(&a, sizeof(float), 1, arquivo);
	fread(&x, sizeof(char), 1, arquivo);

	printf("%d %f %f %c", r,g,a,x);

	fclose(arquivo);
	printf("\n");
	return 0;
}

int fg()
{
	FILE* arquivo;
	char *str;

	if(!(arquivo = fopen("arquivo.txt", "r"))){
		puts("Erro ao abrir arquivo\n");
		exit(1);
	}

	fgets(str, 40, arquivo);
	puts(str);

	fclose(arquivo);
	printf("\n");
	return 0;
}

int fc()
{
	FILE* arquivo;
	char ch;

	if(!(arquivo = fopen("arquivo.txt", "r+"))){
		puts("Erro ao abrir arquivo\n");
		exit(1);
	}

	fseek(arquivo, 5, SEEK_SET);
	ch = getc(arquivo);
	putchar(ch);
	if(ferror(arquivo)) puts("ocorreu um erro");
	fclose(arquivo);

	printf("\n");
	return 0;
}

int fmt()
{
	FILE* arquivo;
	unsigned char ch;

	if(!(arquivo = fopen("arquivo.txt", "w+"))){
		puts("Erro ao abrir arquivo\n");
		exit(1);
	}

	for(ch = 0; ch < 255; ch++)
		fprintf(arquivo, "%d - %c\n", ch, ch);
	fprintf(arquivo, "%d - %c\n", ch, ch);
	rewind(arquivo);

	while(!feof(arquivo)){
		ch = getc(arquivo);
		putchar(ch);
	}

	fclose(arquivo);
	printf("\n");
	return 0;
}

int fmt1()
{
	FILE* arquivo;
	unsigned char ch;

	if(!(arquivo = fopen("arquivo.txt", "w+"))){
		puts("Erro ao abrir arquivo\n");
		exit(1);
	}

	fscanf(stdin, "%c", &ch); // le do teclado
	fprintf(arquivo, "%c\n", ch); // imprime no arquivo
	rewind(arquivo);
	fscanf(arquivo, "%c\n", &ch); // le do arquivo
	fprintf(stdout, "%c\n", ch); // imprime na tela

	fclose(arquivo);
	printf("\n");
	return 0;
}

int unix(int argc, char* argv[])
{
	int file;
	char buf[BUFSIZE];
	if(file = open("unix.txt", O_WRONLY) == -1){
		puts("Erro ao abrir o arquivo\n");
		exit(1);
	}

	input(buf, file);

	close(file);

	if(file = open("unix.txt", O_RDRONLY) == -1){
		puts("Erro ao abrir arquivo\n");
		exit(1);
	}

	output(buf, file);
	close(file);

	return 0;
}

input(char* buf, int fd){
	register int i;
	do{
		for(i = 0; i < BUFSIZE; i++) buf[i] = '\0';

		gets(buf);

		if(write(fd, buf, BUFSIZE) != BUFSIZE){
			puts("Erro ao escrever no arquivo\n");
			exit(1);
		}

	}while(!strcpm(buf, "quit"));
}

output(char* buf, int fd){
	for(;;){
		if(!(read(fd, buf, BUFSIZE)) return;
		puts(buf);
	}
}
