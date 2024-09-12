/* ATOI.C */
#include <stdlib.h>
#include <stddef.h>

__PDPCLIB_API__ int atoi(const char *nptr)
{
    return ((int)strtol(nptr, (char **)NULL, 10));
}
