/* LDIV.C */
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

__PDPCLIB_API__ ldiv_t ldiv(long int numer, long int denom)
{
    ldiv_t x;

    x.quot = numer / denom;
    x.rem = numer % denom;
    return (x);
}
