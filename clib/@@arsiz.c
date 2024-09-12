/* @@ARSIZ.C
** Dynamic array
*/
#include "clibary.h"

__asm__("\n&FUNC    SETC 'arraysize'");
unsigned
arraysize( void * varray )
{
    unsigned    size        = 0;
    char        ***carray   = varray;
    ARRAY       *array;

    if (carray) {
        if (*carray) {
            array = (ARRAY *)(((char *)*carray) - sizeof(ARRAY));
            if (memcmp(array->eye, ARRAY_EYE, 4) == 0) {
                size = array->size;
            }
        }
    }

quit:
    return size;
}
