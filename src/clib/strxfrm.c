/* STRXFRM.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifdef strxfrm
#undef strxfrm
#endif
__PDPCLIB_API__ size_t strxfrm(char *s1, const char *s2, size_t n)
{
    size_t oldlen;

    oldlen = strlen(s2);
    if (oldlen < n) {
        memcpy(s1, s2, oldlen);
        s1[oldlen] = '\0';
    }
    return (oldlen);
}
