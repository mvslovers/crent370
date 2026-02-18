/* WCTOMB.C */
#include <stdlib.h>
#include <stddef.h>

__PDPCLIB_API__ int wctomb(char *s, wchar_t wchar)
{
    if (s != NULL) {
        *s = wchar;
        return (1);
    }
    else {
        return (0);
    }
}
