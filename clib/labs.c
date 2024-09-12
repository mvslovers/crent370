/* LABS.C */
#include <stdlib.h>
#include <stddef.h>

#ifdef labs
#undef labs
#endif
__PDPCLIB_API__ long int labs(long int j)
{
    if (j < 0)
    {
        j = -j;
    }
    return (j);
}
