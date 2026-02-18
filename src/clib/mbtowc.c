/* MBTOWC.C */
#include <stdlib.h>
#include <stddef.h>

__PDPCLIB_API__ int mbtowc(wchar_t *pwc, const char *s, size_t n)
{
    if (s == NULL) {
        return (0);
    }

    if (n == 1) {
        if (pwc != NULL) {
            *pwc = *s;
        }
        return (1);
    }
    else {
        return (-1);
    }
}
