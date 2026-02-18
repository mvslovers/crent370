/* REALLOC.C */
#define STDLIB_C
#include "stdlib.h"
#include "signal.h"
#include "string.h"
#include "ctype.h"
#include "stddef.h"
#include "mvssupa.h"

__PDPCLIB_API__ void *realloc(void *ptr, size_t size)
{
    char *newptr;
    size_t oldsize;

    if (size == 0) {
        free(ptr);
        return (NULL);
    }

#if USE_MEMMGR
    if (memmgrRealloc(&__memmgr, ptr, size) == 0) {
        return (ptr);
    }
#endif

    newptr = malloc(size);
    if (newptr == NULL) {
        return (NULL);
    }

    if (ptr != NULL) {
        oldsize = *((size_t *)ptr - 1);
        if (oldsize < size) {
            size = oldsize;
        }
        memcpy(newptr, ptr, size);
        free(ptr);
    }

    return (newptr);
}
