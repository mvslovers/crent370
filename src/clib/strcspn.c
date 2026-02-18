/* STRCSPN.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifdef strcspn
#undef strcspn
#endif
__PDPCLIB_API__ size_t strcspn(const char *s1, const char *s2)
{
    const char *p1;
    const char *p2;

    p1 = s1;
    while (*p1 != '\0') {
        p2 = s2;
        while (*p2 != '\0') {
            if (*p1 == *p2) return ((size_t)(p1 - s1));
            p2++;
        }
        p1++;
    }

    return ((size_t)(p1 - s1));
}
