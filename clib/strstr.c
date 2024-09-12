/* STRSTR.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

/* strstr by Frank Adam */
/* modified by Paul Edwards */

#ifdef strstr
#undef strstr
#endif
__PDPCLIB_API__ char *strstr(const char *s1, const char *s2)
{
    const char *p = s1, *p1, *p2 = s2;

    while (*p) {
        if (*p == *s2) {
            p1 = p;
            p2 = s2;
            while ((*p2 != '\0') && (*p1 == *p2)) {
                p1++;
                p2++;
            }

            if (*p2 == '\0') {
                return (char *)p;
            }
        }
        p++;
    }

    return NULL;
}
