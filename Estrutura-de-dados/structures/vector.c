#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

bool vempty(var v)
{
    return (v == NULL);
}

pvector_t new_vector(uint sz)
{
    pvector_t nw = (pvector_t)malloc(sizeof(vector_t));
    nw->data = malloc(sz);
    int i;
    for(i = 0; i < sz; i++)
    {
        nw->data[i] = NULL;
    }
    nw->size = 0;
    nw->capacity = sz;
    return nw;
}

void vinsert(pvector_t vc, var v, uint i)
{
    if(vempty(vc)) return;
    if(i >= vc->capacity) return;
    if(vc->data[i] == NULL) vc->size++;
    vc->data[i] = v;
}

void vpush(pvector_t vc, var v)
{
    if(vempty(vc)) return;
    if(vc->size >= vc->capacity) 
        vresize(&vc, vc->capacity+1);
    vc->data[vc->size] = v;
    vc->size++;
}

var vpop(pvector_t vc)
{
    if(vempty(vc)) return NULL;
    vc->size--;
    return vc->data[vc->size];
}

var vremove(pvector_t vc, uint i)
{
    if(i >= vc->size) return NULL;
    var tmp = vc->data[i];
    int j;
    for(j = i; j < vc->size-1; j++)
    {
        vc->data[j] = vc->data[j+1];
    }
    vc->size--;
    return tmp;
}

void vresize(pvector_t *vc, uint sz)
{
    pvector_t nw = (pvector_t)malloc(sizeof(vector_t));
    nw->capacity = sz;
    nw->data = malloc(sz);
    int i;
    int m = min(nw->capacity, (*vc)->capacity);
    
    for(i = 0; i < m; i++)
    {
        nw->data[i] = (*vc)->data[i];
    }
    nw->size = min((*vc)->size, nw->capacity);
    for( ; i < sz; i++)
    {
        nw->data[i] = NULL;
    }
    (*vc)->data = nw->data;
    (*vc)->size = nw->size;
    (*vc)->capacity = nw->capacity;
}

var vgetElement(pvector_t vc, uint sz)
{
    if(vempty(vc)) return NULL;
    if(sz >= vc->size) return NULL;
    return vc->data[sz];
}

void vfree(pvector_t vc)
{
    free(vc);
    vc = NULL;
}

void vprint(const char *str, pvector_t vc)
{
    if(vempty(vc))
    {
        printf("(0)[]\n");
        return;
    }
    printf("(%d)[", vc->size);
    int i;
    for(i = 0; i < vc->size; i++)
    {
        printf(str, vc->data[i]);
    }
    puts("]");
}