/* STRNCMPI.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifdef strncmpi
#undef strncmpi
#endif
__PDPCLIB_API__ int strncmpi(const char *s1, const char *s2, size_t n)
{
    const unsigned char *p1;
    const unsigned char *p2;
    size_t x = 0;
    unsigned char   c1;
    unsigned char   c2;

    p1 = (const unsigned char *)s1;
    p2 = (const unsigned char *)s2;
    while (x < n) {
        c1 = tolower(p1[x]);
        c2 = tolower(p2[x]);

        if (c1 < c2) return (-1);
        else if (c1 > c2) return (1);
        else if (c1 == '\0') return (0);
        x++;
    }

    return (0);
}
