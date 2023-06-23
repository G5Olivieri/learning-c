#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define __g(type, data) *(type*)data
#define __s(value) (pvoid)&value;
#define to_str(x) #x

typedef char* string;
typedef void* pvoid;
typedef enum e_bool {false, true} bool;

typedef enum e_types
{
    BOOL,
    CHAR,
    STRING,
    INT,
    FLOAT,
    DOUBLE
} e_type;

typedef struct no
{
    e_type type;
    pvoid data;
}no_t, *pno_t;

void imprime(pno_t);
void getConsole(pno_t, string);

e_type type(string);
e_type getType(string);

string getLine(string, size_t);
bool is_int(string);
bool is_float(string);
bool is_double(string);
bool is_bool(string);
bool is_char(string);

pvoid cast(string);

e_type type(string type)
{
    if(!strcmp(type, "char"))
    {
        return CHAR;
    }

    if(!strcmp(type, "string"))
    {
        return STRING;
    }
    if(!strcmp(type, "int"))
    {
        return INT;
    }
    if(!strcmp(type, "float"))
    {
        return FLOAT;
    }
    if(!strcmp(type, "double"))
    {
        return DOUBLE;
    }
    return -1;
}

void imprime(pno_t no)
{
    switch(no->type)
    {
    case BOOL:
        printf("%s\n", __g(int, no->data) == 0 ? "false": "true");
        break;
    case CHAR:
        printf("%c\n", __g(char, no->data));
        break;
    case INT:
        printf("%d\n", __g(int, no->data));
        break;
    case STRING:
        printf("%s\n", (string)no->data);
        break;
    case FLOAT:
        printf("%f\n", __g(float, no->data));
        break;
    case DOUBLE:
        printf("%lf\n", __g(double, no->data));
        break;
    }
}

void getConsole(pno_t no, string value)
{
    no->data = cast(value);
    no->type = getType(value);
}

pvoid cast(string value)
{
    bool a;
    char b;
    int c;
    float d;
    double e;
    switch(getType(value))
    {
    case BOOL:
        sscanf(value, "%d", &a);
        return __s(a);
        break;
    case CHAR:
        sscanf(value, "%c", &b);
        return __s(b);
        break;
    case INT:
        sscanf(value, "%d", &c);
        return __s(c);
        break;
    case STRING:
        return value;
        break;
    case FLOAT:
        sscanf(value, "%f", &d);
        return __s(d);
        break;
    case DOUBLE:
        sscanf(value, "%lf", &e);
        return &e;
        break;
    }
}

e_type getType(string in)
{
    if(is_bool(in))
    {
        return BOOL;
    }
    if(is_int(in))
    {
        return INT;
    }
    if(is_float(in))
    {
        return FLOAT;
    }
    if(is_double(in))
    {
        return DOUBLE;
    }
    if(is_char(in))
    {
        return CHAR;
    }

    return STRING;
}

bool is_bool(string str)
{
    if(*str != '1' && *str != '0')
    {
        return false;
    }
    return true;
}

bool is_int(string str)
{
    while(*str != '\0')
    {
        if(!isdigit(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}

bool is_float(string str)
{
    int cont = 0;
    while(*str != '\0')
    {
        if(!isdigit(*str))
            if((*str) != '.')
            {
                return false;
            } else {
                str++;
                break;
            }
        str++;
    }
    while(*str != '\0')
    {
        if(!isdigit(*str))
            return false;
        cont++;
        str++;
    }

    return (cont <= 4) ? true : false;
}

bool is_double(string str)
{
    int cont = 0;
    while(*str != '\0')
    {
        if(!isdigit(*str))
            if((*str) != '.')
            {
                return false;
            } else {
                str++;
                break;
            }
        str++;
    }
    while(*str != '\0')
    {
        if(!isdigit(*str))
            return false;
        cont++;
        str++;
    }

    return (cont <= 8) ? true : false;
}


bool is_char(string str)
{
    if(strlen(str) == 1)
    {
        return true;
    }
    return false;
}

string getLine(string prompt, size_t sz)
{
    int ch, extra;
    string buff = (string)malloc(sz);
    if(prompt != NULL)
    {
        printf("%s: ", prompt);
        fflush(stdout);
    }
    if(fgets(buff, sz, stdin) == NULL)
       return NULL;

    if(buff[strlen(buff)-1] != '\n')
    {
        extra = 0;
        while(((ch = getchar()) != '\n') && (ch != EOF))
            extra = 1;
        return (extra == 1) ? NULL : buff;
    }
    buff[strlen(buff)-1] = '\0';
    return buff;
}

int main()
{
    no_t no;
    getConsole(&no, getLine("Digite o valor", 50));
    imprime(&no);
    return 0;
}
