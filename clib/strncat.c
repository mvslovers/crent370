/* STRNCAT.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifdef strncat
#undef strncat
#endif
__PDPCLIB_API__ char *strncat(char *s1, const char *s2, size_t n)
{
    char *p = s1;
    size_t x = 0;

    while (*p != '\0') p++;

    while ((*s2 != '\0') && (x < n)) {
        *p = *s2;
        p++;
        s2++;
        x++;
    }
    *p = '\0';

    return (s1);
}
