/* @@SOFIND.C - returns index of found socket or 0 if not found */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "clibcrt.h"
#include "clibary.h"
#include "clibsock.h"
#include "cliblock.h"

int
__sofind(int ss, CLIBSOCK **s)
{
    int         rc      = 0;
    CLIBGRT     *grt    = __grtget();
    unsigned    count;
    unsigned    n;

    lock(&grt->grtsock,1);
    count = arraycount(&grt->grtsock);
    for(n=0; n < count; n++) {
        CLIBSOCK *p = grt->grtsock[n];
        if (!p) continue;
        if (p->socket==ss) {
            if (s) *s = p;
            rc = (int) n+1;
            break;
        }
    }
    unlock(&grt->grtsock,1);

quit:
    return rc;
}
