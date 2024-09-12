/* @@ARGET.C
** Dynamic array
*/
#include "clibary.h"

__asm__("\n&FUNC    SETC 'arrayget'");
void *
arrayget( void * varray, unsigned index )
{
    void  *vitem    = NULL;
    char  ***carray = varray;
    ARRAY *array;

    if (carray) {
        if (*carray) {
            array = (ARRAY *)(((char *)*carray) - sizeof(ARRAY));
            if (memcmp(array->eye, ARRAY_EYE, 4) == 0) {
                if ((index > 0) && (index <= array->count)) {
                    vitem = (*carray)[index - 1];
                }
            }
        }
    }

quit:
    return vitem;
}
