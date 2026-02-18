/* STRICMP.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

#ifdef stricmp
#undef stricmp
#endif
__PDPCLIB_API__ int stricmp(const char *s1, const char *s2)
{
    const unsigned char *p1;
    const unsigned char *p2;
    unsigned char c1;
    unsigned char c2;

    p1 = (const unsigned char *)s1;
    p2 = (const unsigned char *)s2;
    while (*p1 != '\0') {
        c1 = tolower(*p1);
        c2 = tolower(*p2);
        if (c1 < c2) return (-1);
        else if (c1 > c2) return (1);
        p1++;
        p2++;
    }

    if (*p2 == '\0') return (0);
    else return (-1);
}
