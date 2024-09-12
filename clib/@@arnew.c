/* @@ARNEW.C
** Dynamic array
*/
#include "clibary.h"

__asm__("\n&FUNC    SETC 'arraynew'");
void *
arraynew(unsigned size)
{
    ARRAY * array;
    void  * vnew;

    if (!size) size = ARRAY_DEFAULT;

    vnew  = calloc( size + ARRAY_SIZE, sizeof(void *));
    if (vnew) {
        array = (ARRAY *)vnew;
        memcpy( array->eye, ARRAY_EYE, 4 );
        array->size = size;
        array->count = 0;
        vnew = (void *)((char *)vnew + sizeof(ARRAY));
    }

quit:
    return vnew;
}
