#include "list.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

bool lempty(var p)
{
    return (p == NULL);
}

pno_t lnew_no(pno_t p, pno_t n, var v)
{
    pno_t nw = (pno_t)malloc(sizeof(no_t));
    nw->p = p;
    nw->n = n;
    nw->data = v;
    return nw;
}

void lappend(plist_t *l, var v)
{
    pno_t nw = new(NULL, NULL, v);
    if(lempty(*l))
    {
        (*l) = (plist_t)malloc(sizeof(list_t));
        
        (*l)->f = new_no(NULL, nw, (void*)0);
        (*l)->l = new_no(nw, NULL, (void*)0);
        
        (*l)->sz = 1;
    }
    else
    {
        nw->p = (*l)->l->p;
        (*l)->l->p->n = nw;
        (*l)->l->p = nw;
        (*l)->sz++;
    }
}

void lremove(plist_t *l, int i)
{
    if(lempty(l)) return;
    if(i < 0 || i > (*l)->sz-1) return;
    pno_t *it;
    if(i == 0)
    {
        it = &(*l)->f->n;
        free((*l)->f->n);
        it = &(*it)->n;
        (*l)->f->n = *it;
        (*l)->sz--;
        return;
    }
    if(i == (*l)->sz-1)
    {
        it = &(*l)->l->p;
        free((*l)->l->p);
        it = &(*it)->p;
        (*l)->l->p = *it;
        (*l)->sz--;
        return;
    }
    int j;
    it = &(*l)->f->n;
    for(j = 0; j < i; j++)
    {
        it = &(*it)->n;
    }
    pno_t *p;
    p = &(*it)->p;
    pno_t fr = *it;
    it = &(*it)->n;
    (*p)->n = (*it);
    (*it)->p = *p;
    free(fr);
    (*l)->sz--;
}

void lprint(const char *str, plist_t l)
{
    if(lempty(l)){
        printf("LISTA VAZIA!\n");
        return;
    }
    pno_t it = lfirst(l);
    printf("\n(%d)[", l->sz);
    int i;
    for(i = 0; i < l->sz; i++)
    {
        printf(str, it->data);
        it = it->n;
    }
    puts("]");
}

void lfree(plist_t *l)
{
    if(lempty(l)) return;
    pno_t *it;
    it = &(*l)->f->n;
    pno_t fr;
    while(*it != NULL)
    {
        fr = *it;
        it = &(*it)->n;
        free(fr);
    }
    free((*l)->f);
    free((*l)->l);
    free(*l);
    *l = NULL;
    l = NULL;
}

var lgetElement(plist_t l, int i)
{
    if(lempty(l)) return NULL;
    if(i < 0 || i > l->sz) return NULL;
    if(i == 0) return lfirst(l)->data;
    if(i == l->sz) return llast(l)->data;
    int j;
    pno_t it = lfirst(l);
    for(j = 0; j < i; j++)
    {
        it = it->n;
    }
    return it->data;
}

pno_t lgetNode(plist_t l, int i)
{
    if(lempty(l)) return NULL;
    if(i < 0 || i > l->sz) return NULL;
    if(i == 0) return lfirst(l);
    if(i == l->sz) return llast(l);
    int j;
    pno_t it = lfirst(l);
    for(j = 0; j < i; j++)
    {
        it = it->n;
    }
    return it;
}

pno_t lfirst(plist_t l)
{
    if(lempty(l)) return NULL;
    return l->f->n;
}

pno_t llast(plist_t l)
{
    if(lempty(l)) return NULL;
    return l->l->p;
}

int lindexOf(plist_t l, var data)
{
    int i;
    pno_t it = lfirst(l);
    for(i = 0; i < l->sz; i++)
    {
        if(!str_comp((char*)&it->data, (char*)&data))
        {
            return i;
        }
        it = it->n;
    }
    return -1;
}

void lforEach(plist_t l, void (*f)(var))
{
    int i;
    pno_t it = lfirst(l);
    for(i = 0; i < l->sz; i++)
    {
        f(it->data);
        it=it->n;
    }
}