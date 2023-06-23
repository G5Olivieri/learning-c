#ifndef _LIST_H_
#define _LIST_H_

#include "types.h"

typedef struct _node {
    var data;
    struct _node *p, *n;
}*pno_t, no_t;

typedef struct _list {
    unsigned int sz;
    pno_t f, l;
}*plist_t, list_t;

bool lempty(var);
void lappend(plist_t*, var);
void lremove(plist_t*, int);
pno_t new_no(pno_t, pno_t, var);
var lgetElement(plist_t, int);
pno_t lgetNode(plist_t, int);
pno_t llast(plist_t);
pno_t lfirst(plist_t);
void lprint(const char*, plist_t);
void lfree(plist_t*);
int lindexOf(plist_t, var);
void lforEach(plist_t, void (*)(var));

#endif // _LIST_H_