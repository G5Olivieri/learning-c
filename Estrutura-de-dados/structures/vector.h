#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "types.h"

typedef struct _vector {
    ulong size;
    ulong capacity;
    var *data;
} vector_t, *pvector_t;


pvector_t new_vector();
var vgetElement(pvector_t, uint);
void vinsert(pvector_t, var, uint);
void vpush(pvector_t, var);
void vresize(pvector_t*, uint);
void vfree(pvector_t);
var vremove(pvector_t, uint);
var vpop(pvector_t);

#endif // _VECTOR_H_