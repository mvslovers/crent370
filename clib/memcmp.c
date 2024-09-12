/* MEMCMP.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifdef memcmp
#undef memcmp
#endif
__PDPCLIB_API__ int memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *p1;
    const unsigned char *p2;
    size_t x = 0;

    p1 = (const unsigned char *)s1;
    p2 = (const unsigned char *)s2;
    while (x < n) {
        if (p1[x] < p2[x]) return (-1);
        else if (p1[x] > p2[x]) return (1);
        x++;
    }

    return (0);
}
