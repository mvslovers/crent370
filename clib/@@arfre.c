/* @@ARFRE.C
** Dynamic array
*/
#include "clibary.h"

__asm__("\n&FUNC    SETC 'arrayfree'");
int
arrayfree( void * varray )
{
    int     rc          = 0;
    char    ***carray   = varray;
    ARRAY   *array;

    if (!carray) {
        rc = -1;
        goto quit;
    }

    if (!*carray) {
        rc = -1;
        goto quit;
    }

    array = (ARRAY *)(((char *)*carray) - sizeof(ARRAY));

    if (memcmp(array->eye, ARRAY_EYE, 4) != 0) {
        rc = -1;
        goto quit;
    }

    free(array);
    *carray = NULL;

quit:
    return rc;
}
