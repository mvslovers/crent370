/* STRRCHR.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifdef strrchr
#undef strrchr
#endif
__PDPCLIB_API__ char *strrchr(const char *s, int c)
{
    const char *p;

    p = s + strlen(s);
    while (p >= s) {
        if (*p == (char)c) return ((char *)p);
        p--;
    }

    return (NULL);
}
