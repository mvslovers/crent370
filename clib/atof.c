/* ATOF.C */
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <float.h>

__PDPCLIB_API__ double atof(const char *nptr)
{
    return (strtod(nptr, (char **)NULL));
}
