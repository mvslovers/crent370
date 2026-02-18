/* @@ARCOU.C
** Dynamic array
*/
#include "clibary.h"

__asm__("\n&FUNC    SETC 'arraycount'");
unsigned
arraycount( void * varray )
{
    unsigned    count       = 0;
    char        ***carray   = varray;
    ARRAY       *array;

    if (carray) {
        if (*carray) {
            array = (ARRAY *)(((char *)*carray) - sizeof(ARRAY));
            if (memcmp(array->eye, ARRAY_EYE, 4) == 0) {
                count = array->count;
            }
        }
    }

quit:
    return count;
}
