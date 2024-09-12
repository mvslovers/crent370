/* @@ARADD.C
** Dynamic array
*/
#include "clibary.h"

__asm__("\n&FUNC    SETC 'arrayeach'");
int
arrayeach(void * varray, int (*fn)(unsigned index, void *item, void *udata), void *udata)
{
    int         rc          = 0;
    char        ***carray   = varray;
    unsigned    count       = arraycount(varray);
    unsigned    n;

    for(n=0; n < count; n++) {
        rc = fn(n, (*carray)[n], udata);
        if (rc) break;
    }

    return rc;
}

