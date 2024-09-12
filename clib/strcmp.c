/* STRCMP.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifdef strcmp
#undef strcmp
#endif
__PDPCLIB_API__ int strcmp(const char *s1, const char *s2)
{
    const unsigned char *p1;
    const unsigned char *p2;

    p1 = (const unsigned char *)s1;
    p2 = (const unsigned char *)s2;
    while (*p1 != '\0') {
        if (*p1 < *p2) return (-1);
        else if (*p1 > *p2) return (1);
        p1++;
        p2++;
    }

    if (*p2 == '\0') return (0);
    else return (-1);
}
