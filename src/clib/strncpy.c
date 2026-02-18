/* STRNCPY.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifdef strncpy
#undef strncpy
#endif
__PDPCLIB_API__ char *strncpy(char *s1, const char *s2, size_t n)
{
    char *p = s1;
    size_t x;

    for (x=0; x < n; x++) {
        *p = *s2;
        if (*s2 == '\0') break;
        p++;
        s2++;
    }

    for (; x < n; x++) {
        *p++ = '\0';
    }

    return (s1);
}
