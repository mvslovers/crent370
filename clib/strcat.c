/* STRCAT.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifdef strcat
#undef strcat
#endif
__PDPCLIB_API__ char *strcat(char *s1, const char *s2)
{
    char *p = s1;

    while (*p != '\0') p++;

    while ((*p = *s2) != '\0') {
        p++;
        s2++;
    }

    return (s1);
}
