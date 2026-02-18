/* @@ARADF.C
** Dynamic array
*/
#include "clibary.h"

__asm__("\n&FUNC    SETC 'arrayaddf'");
int
arrayaddf( void * varray, const char *fmt, ... )
{
    int     rc      = -1;
    va_list tlist;
    int     len;
    char    *ptr;
    char    buf[1024];

    if (varray) {
        va_start(tlist, fmt);
        len = vsprintf(buf, fmt, tlist);
        va_end(tlist);

        ptr = calloc(1, len + 1);
        if (!ptr) {
            rc = -1;
        }
        else {
            strcpy(ptr, buf);
            rc = arrayadd(varray, ptr);
        }
    }

quit:
    return rc;
}
