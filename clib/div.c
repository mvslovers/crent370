/* DIV.C */
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

__PDPCLIB_API__ div_t div(int numer, int denom)
{
    div_t x;

    x.quot = numer / denom;
    x.rem = numer % denom;
    return (x);
}
