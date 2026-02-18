/* ABS.C */
#include <stdlib.h>
#include <stddef.h>

#ifdef abs
#undef abs
#endif
__PDPCLIB_API__ int abs(int j)
{
    if (j < 0)
    {
        j = -j;
    }
    return (j);
}
