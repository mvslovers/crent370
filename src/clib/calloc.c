/* CALLOC.C */
#define STDLIB_C
#include "stdlib.h"
#include "signal.h"
#include "string.h"
#include "ctype.h"
#include "stddef.h"
#include "mvssupa.h"

__PDPCLIB_API__ void *calloc(size_t nmemb, size_t size)
{
    size_t total    = ((nmemb * size) + 7) & 0x00FFFFF8;
    void *ptr;

    ptr = malloc(total);
    if (ptr) {
        /* clear allocated memory [memset(ptr, 0, total)] */
        __asm__("\n"
"* Clear allocated memory\n"
"         LR    14,%0   => ptr\n"
"         LR    15,%1   == total size\n"
"         SLR   0,0\n"
"         LR    1,0\n"
"         MVCL  14,0\n" : : "r"(ptr), "r"(total) : "0", "1", "14", "15");
    }

    return (ptr);
}
