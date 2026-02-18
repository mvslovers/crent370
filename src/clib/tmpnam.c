#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "cliblock.h"
#include "clibcrt.h"

__PDPCLIB_API__ char *tmpnam(char *s)
{
    CLIBCRT     *crt    = __crtget();
    CLIBGRT     *grt    = crt ? crt->crtgrt : 0;
    unsigned    *cnt;
    char        *buf;

    if (!grt) return NULL;

    cnt    = &grt->grttmpnm;    /* => counter in CLIBGRT    (process)   */
    buf    = crt->crttmpnm;     /* => buffer in CLIBCRT     (task)      */

    if (!s) s = buf;

    lock(cnt, 0);
    if (*cnt >= 99999) *cnt = 0;
    *cnt = (*cnt + 1);
    sprintf(s, "&&TMP%05u", *cnt);
    unlock(cnt, 0);

    return (s);
}
