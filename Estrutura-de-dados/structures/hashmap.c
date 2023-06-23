#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "types.h"
#include "map.h"

bool mempty(var v)
{
    return (v == NULL);
}

pmap_t new_map()
{
    pmap_t nw = (pmap_t)malloc(sizeof(map_t));
    nw->table = new_vector(INITIAL_CAPACITY);
    return nw;
}

pmap_t new_nmap(uint sz)
{
    pmap_t nw = (pmap_t)malloc(sizeof(map_t));
    nw->table = new_vector(sz);
    return nw;
}

pno_t mnew_node(ulong hash, var k, uint sz, var v, pno_t next)
{
    pno_t nw = (pno_t)malloc(sizeof(no_t));
    nw->hash = hash;
    nw->key = k;
    nw->value = v;
    nw->next = next;
    nw->sz_key = sz;
    return nw;
}

void mput(pmap_t *m, var k, uint sz, var v)
{
    if(mempty(*m)) *m = new_map();
    if(mempty(k) && sz == 0)
    {
        mputNullKey(m, v);
        return;
    }
    ulong h = mhash(mdata_hash(&k, sz));
    uint i = mindex(h, (*m)->table->capacity);
    pno_t it;
    pno_t p;
    if((*m)->table->data[i] == NULL)
    {
        vinsert((*m)->table, mnew_node(h, k, sz, v, NULL), i);
    }
    else
    {
        it = ((pno_t)(*m)->table->data[i]);
        if(it->hash == h)
        {
            vinsert((*m)->table, mnew_node(h, k, sz, v, NULL), i);
            return;
        }
        else {
            p = it;
            while((it=it->next) != NULL)
            {
                if(it->hash == h)
                {
                    it->value = v;
                    return;
                }
                p = it;
            }
            it = mnew_node(h, k, sz, v, NULL);
            p->next = it;
        }
    }
    
    if((*m)->table->size >= (int)((*m)->table->capacity * LOAD_FACTOR))
        mresize(m, (*m)->table->capacity << 1);
}

void mresize(pmap_t *m, uint sz)
{
    pmap_t nw = new_nmap(sz);
    int i;
    pno_t it;
    for(i = 0; i < (*m)->table->capacity; i++)
    {
        it = ((pno_t)(*m)->table->data[i]);
        if(it != NULL)
        {
            mput(&nw, it->key, it->sz_key, it->value);
            it = ((pno_t)(*m)->table->data[i]);
            while((it=it->next) != NULL)
            {
                mput(&nw, it->key, it->sz_key, it->value);
            }
        }
    }
    *m = nw;
}

void mputNullKey(pmap_t *m, var v)
{
    int i;
    pno_t next;
    for(i = 1; i < (*m)->table->size; i++)
    {
        if((*m)->table->data[i] != NULL)
        {
            next = (*m)->table->data[i];
            break;
        }
    }
    vinsert((*m)->table, mnew_node(0, NULL, 0, v, NULL), 0);
}

ulong mdata_hash(var k, ulong sz)
{
    unsigned i;
    byte *key = k;
    int prime = 31, result = 1;
    for(i = 0; i < sz; i++)
    {
        result = prime * result + (key[i]);
    }
    return result;
}

ulong mhash(ulong h)
{
    return h ^ (h >> 16);
}

uint mindex(ulong hash, ulong size)
{
    return hash & (size-1);
}

void mprint(const char *str, pmap_t m)
{
    int i;
    pno_t it;
    uint sz = 0;
    printf("[");
    for(i = 0; i < m->table->capacity; i++)
    {
        if(m->table->data[i] != NULL)
        {
            printf(str, ((pno_t)m->table->data[i])->key, ((pno_t)m->table->data[i])->value);
            sz++;
            it = ((pno_t)m->table->data[i]);
            while((it=it->next) != NULL)
            {
                printf(str, it->key, it->value);
                sz++;
            }
        }
    }
    printf("](%d)\n", sz);
}

int comp(void *a, void *b, uint szmin)
{
    byte *x, *y;
    x = (byte*)a;
    y = (byte*)b;
    int i;
    for(i = 0; i < szmin; i++)
    {
        if(x[i] < y[i])
        {
            return -1;
        }
        else if(x[i] > y[i])
        {
            return 1;
        }
    }
    return 0;
}


var mgetElement(pmap_t m, var k, uint sz)
{
    if(mempty(m)) return NULL;
    int h = mhash(mdata_hash(&k, sz));
    int i = mindex(h, m->table->capacity);
    pno_t it = ((pno_t)m->table->data[i]);
    if(it->hash = h)
    {
        return it->value;
    }
    else {
        while((it=it->next) != NULL)
        {
            if(it->hash == h)
            {
                return it->value;
            }
        }
    }
    return NULL;
}

var mremove(pmap_t *m, var k, uint sz)
{
    if(mempty(m)) return NULL;
    int h = mhash(mdata_hash(&k, sz));
    int i = mindex(h, (*m)->table->capacity);
    pno_t *it;
    pno_t *n;
    var v;
    it = ((pno_t*)&(*m)->table->data[i]);
    n = &(*it)->next;
    if((*it)->hash = h)
    {
        v = (*it)->value;
        (*it) = (*n);
        return v;
    }
    else {
        while(((*it)=(*it)->next) != NULL)
        {
            n = &(*it)->next;
            if((*it)->hash == h)
            {
                v = (*it)->value;
                *it = *n;
                return v;
            }
        }
    }
    return NULL;
}
