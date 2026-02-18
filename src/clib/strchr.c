/* STRCHR.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifdef strchr
#undef strchr
#endif
__PDPCLIB_API__ char *strchr(const char *s, int c)
{
    while (*s != '\0') {
        if (*s == (char)c) return ((char *)s);
        s++;
    }

    if (c == '\0') return ((char *)s);
    return (NULL);
}
