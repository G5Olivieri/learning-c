#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define DELIMITADOR 1
#define VARIAVEL 2
#define NUMERO 3

char *prog;
char token[80];
char tok_type;

void 
eval_exp(double *answer),
eval_exp2(double *answer),
eval_exp3(double *answer),
eval_exp4(double *answer),
eval_exp5(double *answer),
eval_exp6(double *answer),
atom(double *answer), 
serror(int erro),
get_token(), 
putback();
int isdelim(char c);

int main(int argc, char *argv[])
{		
	double answer;
	char *p;
	if(!(p=(char*)malloc(100*sizeof(char)))){
		puts("Erro na alocacao");
		exit(EXIT_FAILURE);
	}
	do{
		prog = p;
		printf("Digite a expressão: ");
		gets(prog);
		if(!*prog) break;
		eval_exp(&answer);
		printf("Resposta é %.2f\n", answer);
	}while(*p);
	putchar('\n');
	exit(EXIT_SUCCESS);
}

/* Ponto de entrada do analisador */
void eval_exp(double *answer)
{
	get_token();
	if(!*token) {
		serror(2);
		return;
	}
	eval_exp2(answer);
	if(*token) serror(0); /* ultimo token dever ser NULL */
}

/* Soma ou subtrai dois termos */
void eval_exp2(double *answer)
{
	register char op;
	double temp;

	eval_exp3(answer);
	while((op = *token) == '+' || op =='-') {
		get_token();
		eval_exp3(&temp);
		switch(op){
			case '-':
				*answer = *answer - temp;
				break;
			case '+':
				*answer = *answer + temp;
				break;
		}
	}
}

/* Multiplica ou divide dois fatores */
void eval_exp3(double *answer)
{
	register char op;
	double temp;

	eval_exp4(answer);
	while((op = *token) == '*' || op == '/' || op == '%'){
		get_token();
		eval_exp4(&temp);
		switch(op){
			case '*':
				*answer = *answer * temp;
				break;
			case '/':
				*answer = *answer / temp;
				break;
			case '%':
				*answer = (int) *answer % (int) temp;
				break;
		}
	}
}

/* Processa o expoente */
void eval_exp4(double *answer)
{
	double temp, ex;
	register int t;

	eval_exp5(answer);
	if(*token == '^') {
		get_token();
		eval_exp4(&temp); /* duvida se nao é a 5*/
		ex = *answer;
		if(temp == 0.0) {
			*answer = 1.0;
			return;
		}
		for(t = temp-1; t>0; --t) *answer  = (*answer) * (double)ex;
	}
}

/* Avalia um + ou - unário */
void eval_exp5(double *answer)
{
	register char op;
	op = 0;
	if((tok_type == DELIMITADOR) && *token == '+' || *token == '-'){
		op = *token;
		get_token();
	}
	eval_exp6(answer);
	if(op=='-') *answer = -(*answer);
}

/* processa uma expressão entre parenteses */
void eval_exp6(double *answer)
{
	if((*token == '(')) {
		get_token();
		eval_exp2(answer);
		if(*token != ')')
			serror(1);
		get_token();
	}
	else
		atom(answer);
}

/* Obtem o valor real de um numero */
void atom(double *answer)
{
	if(tok_type == NUMERO){
		*answer = atof(token);
		get_token();
		return;
	}
	serror(0); /* caso contrario, erro de sintaxe na expressao */
}

/* devolve um token a stream de entrada */
void putback()
{
	char *t;
	t = token;
	for(;*t;t++) prog--;
}

/* apresenta um erro de sintaxe */
void serror(int error)
{
	static char *e[] = {
		"Erro de sintaxe",
		"Falta parênteses",
		"Nenhuma expressão presente",
	};
	puts(e[error]);
}

/* devolve o proximo token */
void get_token()
{
	register char *temp;

	tok_type = 0;
	temp = token;
	*temp = '\0';

	if(!*prog) return; /* final da expressão */
	while(isspace(*prog)) prog++; /* ignora espacos e tabulações */
	if(strchr("+-*/%^=()", *prog)){
		tok_type = DELIMITADOR;
		*temp++ = *prog++;
	}
	else if(isalpha(*prog)){
		while(!isdelim(*prog)) *temp++ = *prog++;
		tok_type = VARIAVEL;
	}
	else if(isdigit(*prog)) {
		while(!isdelim(*prog)) *temp++ = *prog++;
		tok_type = NUMERO;
	}
	*temp = '\0';
}

/* Devolve verdadeiro se c é um delimitador */
int isdelim(char c)
{
	if(strchr(" +-/*%^=()", c) || c==9 || c=='\r' || c==0)
		return 1;
	return 0;
}
