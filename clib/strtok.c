/* STRTOK.C */
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "clibcrt.h"

static char     *static_old = NULL;

#ifdef strtok
#undef strtok
#endif
__PDPCLIB_API__ char *strtok(char *s1, const char *s2)
{
    CLIBCRT     *crt    = __crtget();
    char        **old   = crt ? &crt->crtstrtk : &static_old;
    char        *p;
    size_t      len;
    size_t      remain;

    if (s1 != NULL) *old = s1;
    if (*old == NULL) return (NULL);

    p = *old;
    len = strspn(p, s2);
    remain = strlen(p);
    if (remain <= len) {
        *old = NULL;
        return (NULL);
    }

    p += len;
    len = strcspn(p, s2);
    remain = strlen(p);
    if (remain <= len) {
        *old = NULL;
        return (p);
    }

    *(p + len) = '\0';
    *old = p + len + 1;
    return (p);
}
