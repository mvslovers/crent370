/* ATOL.C */
#include <stdlib.h>
#include <stddef.h>

__PDPCLIB_API__ long int atol(const char *nptr)
{
    return (strtol(nptr, (char **)NULL, 10));
}
