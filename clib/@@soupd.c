/* @@SOUPD.C */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "clibary.h"
#include "clibsock.h"
#include "cliblock.h"

int
__soupd(int ss, void *name, void *peer)
{
    int         rc      = 0;
    CLIBSOCK    *s      = 0;

    if (!__sofind(ss,&s)) {
        /* not found, convert to add */
        rc = __soadd(ss, name, peer);
        goto quit;
    }
#if 0
    wtodumpf(s, sizeof(CLIBSOCK), "__soupd()");
#endif
    if (name)   memcpy(s->name, name, sizeof(s->name));
    if (peer)   memcpy(s->peer, peer, sizeof(s->peer));

quit:
    return rc;
}
