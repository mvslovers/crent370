/* @@SODEL.C */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "clibcrt.h"
#include "clibary.h"
#include "clibsock.h"
#include "cliblock.h"

int
__sodel(int ss)
{
    int         rc      = 0;
    CLIBGRT     *grt    = __grtget();
    unsigned    count;
    unsigned    n;

    lock(&grt->grtsock,0);
    count = arraycount(&grt->grtsock);
    for(n=0; n < count; n++) {
        CLIBSOCK *p = grt->grtsock[n];
        if (!p) continue;
        if (p->socket==ss) {
            arraydel(&grt->grtsock, n+1);
            free(p);
            break;
        }
    }
    unlock(&grt->grtsock,0);

quit:
    return rc;
}
