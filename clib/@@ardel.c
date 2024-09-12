/* @@ARDEL.C
** Dynamic array
*/
#include "clibary.h"

__asm__("\n&FUNC    SETC 'arraydel'");
void *
arraydel( void * varray, unsigned index )
{
    void  *vitem    = NULL;
    char  ***carray = varray;
    ARRAY *array;

    if (carray) {
        if (*carray) {
            array = (ARRAY *)(((char *)*carray) - sizeof(ARRAY));
            if (memcmp(array->eye, ARRAY_EYE, 4) == 0) {
                if ((index > 0) && (index <= array->count)) {
                    index--;
                    vitem = (*carray)[index];
                    /* now shift everything left */
                    for( ; index < array->count; index++ ) {
                        (*carray)[index] = (*carray)[index+1];
                    }
                    array->count--;
                    (*carray)[array->count] = NULL;
                }
            }
        }
    }

quit:
    return vitem;
}
