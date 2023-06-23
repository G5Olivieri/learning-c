#ifndef _MAP_H_
#define _MAP_H_

#define INITIAL_CAPACITY 16
#define LOAD_FACTOR 0.75
#define MAXIMUM_CAPACITY 1<<30

#include "types.h"
#include "vector.h"

typedef struct _node {
    var key;
    var value;
    struct _node *next;
    ulong hash;
    uint sz_key;
}no_t, *pno_t;

typedef struct _map {
    pvector_t table;
    //uint size;
}map_t, *pmap_t;

bool mempty(var);
pmap_t new_map();
pmap_t new_nmap(uint);
pno_t mnew_node(ulong, var, uint, var, pno_t);
void mput(pmap_t *, var, uint, var);
void mputNullKey(pmap_t *, var);
void mresize(pmap_t*, uint);
void mtransfer(pmap_t *, pno_t *);
ulong mdata_hash(var, ulong);
ulong mhash(ulong);
uint mindex(ulong, ulong);
int comp(var, var, uint);
var mremove(pmap_t *, var, uint);
var mgetElement(pmap_t, var, uint);
int comp(var, var, uint);
void mprint(const char *, pmap_t);

#endif // _MAP_H_