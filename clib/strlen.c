/* STRLEN.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifdef strlen
#undef strlen
#endif
__PDPCLIB_API__ size_t strlen(const char *s)
{
    const char *p;

    p = s;
    while (*p != '\0') p++;
    return ((size_t)(p - s));
}
