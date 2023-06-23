#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum tipo{
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
  STRING,
  ARRAY_INT,
  ARRAY_FLOAT,
  ARRAY_DOUBLE,
  LIST
};

struct no{
void *data;
int size_no;
int tipo_no;
struct no *next;
struct no *prev;
};

struct list{
struct no *start;
struct no *end;
size_t size_list;
};

struct list *list_init()
{
struct list *list;
list = (struct list*)malloc(sizeof(struct list));
if(list == NULL)
  return NULL;
  list->start = NULL;
  list->end = NULL;
  list->size_list = 0;
  return list;
}

struct no *newno(void *data, size_t size_data, int tipo)
{
struct no *temp = (struct no*)malloc(sizeof(struct no));
  temp->next = NULL;
  temp->prev = NULL;
  
  if(temp == NULL)
    {
      printf("alocar temp");
      return NULL;
    }
  
  temp->data = (void*)malloc(size_data);
  
  if(temp->data == NULL)
    {
      printf("nao alocou data\n");
      return NULL;
    }

  memcpy(temp->data, data, size_data);

  temp->size_no = size_data;
  temp->tipo_no = tipo;
  return temp;
}

int list_add(struct list *list, void *data, size_t size_data, int tipo)
{ 
  if(list->size_list == 0)
    {
      if(!(list->end = newno(data, size_data, tipo)))
	return -1;
      
      list->start = list->end;
    }

  else
    {
      if(!(list->end->next = newno(data, size_data, tipo)))
	return -1;
      list->end->next->prev = list->end;
      list->end = list->end->next;
    }
  
  list->size_list++;
  return 0;
}

int list_add_back(struct list *list, void *data, size_t size_data, int tipo)
{
  if(list->size_list == 0)
    {
      if(!(list->end = newno(data, size_data, tipo)))
	return -1;
      
      list->start = list->end;
    }

  else
    {
      if(!(list->start->prev = newno(data, size_data, tipo)))
	return -1;
      list->start->prev->next = list->start;
      list->start = list->start->prev;
    }
  
  list->size_list++;
  return 0;
}
void imprime(struct list *list)
{
  int i, j;
  struct no *temp = list->start;
  for(i = 0; i < list->size_list; i++)
    {
      switch(temp->tipo_no)
	{
	case INT:
	  printf(" '%d'", *((int*)temp->data));
	  break;

	case CHAR:
	  printf(" '%c'", *((char*)temp->data));
	  break;

	case STRING:
	  printf(" '%s'", (char*)temp->data);
	  break;

	case FLOAT:
	  printf(" '%f'", *((float*)temp->data));
	  break;

	case DOUBLE:
	  printf(" '%lf'", *((double*)temp->data));
	  break;

	case ARRAY_INT:
	  printf(" '");
	  for(j = 0; j < (temp->size_no/4)-1; j++)
	    printf("%d ", *((int *)temp->data+j));
	  printf("%d'", *((int*)temp->data+j));
	  break;

	case ARRAY_FLOAT:
	  printf(" '");
	  for(j = 0; j < (temp->size_no/4)-1; j++)
	    printf("%g ", *((float *)temp->data+j));
	  printf("%g'", *((float*)temp->data+j));
	  break;
	
	case ARRAY_DOUBLE:
	  printf(" '");
	  for(j = 0; j < (temp->size_no/8)-1; j++)
	    printf("%g ", *((double*)temp->data+j));
	  printf("%g'", *((double*)temp->data+j));
	  break;

	case LIST:
	  printf(" \"");
	  imprime((struct list*)temp->data);
	  printf(" \"");
	  break;
	}
      
      temp = temp->next;
    }
}

int delete(struct list *list)
{
  if(list->size_list == 0)
    {
      return -1;
    }
  struct no *temp = list->end;
  list->end = list->end->prev;
  list->end->next = NULL;
  list->size_list--;
  free(temp);
  return 0;
}

int delete_back(struct list *list)
{
  if(list->size_list == 0)
    return -1;
  struct no *temp = list->start;
  list->start = list->start->next;
  list->start->prev = NULL;
  list->size_list--;
  free(temp);
  return 0;
}

int main()
{
  struct list *list = list_init();
  struct list *list1 = list_init();
  char *str = "String e uma coisa meio maluca";
  int value[] = {1, 3, 4, 5, 6, 6, 7};
  double money = 4.2;
  char a = 'a';
  int b = 3213;
  float vetor[] = {12.3, 43.4, 431.34, 454.13, 51.3};
  char *str1 = "Essa string marca o inicio";
  
  list_add(list1, &value, sizeof(value), ARRAY_INT);
  list_add(list1, (void*)str, strlen(str)+1, STRING);
  list_add(list, &money, sizeof(money), DOUBLE);
  list_add(list, &a, sizeof(char), CHAR);
  list_add(list, &b, sizeof(int), INT);
  list_add(list, &vetor, sizeof(vetor), ARRAY_FLOAT);
  list_add(list, (void*)list1, sizeof(struct list), LIST);

  list_add_back(list, (void*)str1, strlen(str1), STRING);

  delete_back(list);
  imprime(list);
  puts("");
  free(list);
  return 0;
}
