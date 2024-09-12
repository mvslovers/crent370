/* @@ARADD.C
** Dynamic array
*/
#include "clibary.h"
#include "errno.h"

__asm__("\n&FUNC    SETC 'arrayadd'");
int
arrayadd(void * varray, void *vitem)
{
    int         rc          = 0;
    char        ***carray   = varray;
    ARRAY       *array;

    if (!carray) {
        errno = EINVAL;
        rc = -1;
        goto quit;
    }

    if (!*carray) {
        /* wtof("%s arraynew(%u)", __func__, ARRAY_DEFAULT); */
        *carray = arraynew( ARRAY_DEFAULT );
        /* wtof("%s ptr=%08X", __func__, *carray); */
    }

    if (!*carray) {
        errno = ENOMEM;
        rc = -1;
        goto quit;
    }

    array = (ARRAY *)(((char *)*carray) - sizeof(ARRAY));

    if (memcmp(array->eye, ARRAY_EYE, 4) != 0) {
        errno = EINVAL;
        rc = -1;
        goto quit;
    }

    if (array->size <= array->count) {
        unsigned oldbytes = (ARRAY_SIZE + array->size) * sizeof(void *);
        unsigned newbytes =
            (ARRAY_SIZE + ARRAY_DEFAULT + array->size) * sizeof(void *);

        void *vnew = calloc(1, newbytes);
        /* wtof("%s calloc(1,%u) = %08X, oldbytes=%u", __func__, newbytes, vnew, oldbytes); */
        if (!vnew) {
            errno = ENOMEM;
            rc = -1;
            goto quit;
        }

        memcpy(vnew, array, oldbytes);

        free(array);

        array = vnew;
        array->size += ARRAY_DEFAULT;

        vnew = (void *)((char *)vnew + sizeof(ARRAY));
        *carray = vnew;
    }

    (*carray)[array->count++] = vitem;

quit:
    return rc;
}
