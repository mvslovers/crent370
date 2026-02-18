/* MBLEN.C */
#include <stdlib.h>
#include <stddef.h>

__PDPCLIB_API__ int mblen(const char *s, size_t n)
{
    if (s == NULL) {
        return (0);
    }

    if (n == 1) {
        return (1);
    }
    else {
        return (-1);
    }
}
