#ifndef _STRING_H_
#define _STRING_H_

int str_len(const char*);
char *str_concat(char*, const char*);
char *str_sub(char *, int, int);
int str_contains(const char*, const char*);
int str_comp(const char*, const char*);
char *getLine(const char*);
int sizeLine(const char*);
char *str_toLowerCase(char *);
char *str_toUpperCase(char *);
char *str_copy(char*);
char *trim(char *);

#endif // _STRING_H