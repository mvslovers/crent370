/* @@SOADD.C */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "clibcrt.h"
#include "clibary.h"
#include "clibsock.h"
#include "cliblock.h"

int
__soadd(int ss, void *name, void *peer)
{
    int         rc      = -1;
    CLIBGRT     *grt    = __grtget();
    CLIBSOCK    *s      = calloc(1, sizeof(CLIBSOCK));

    if (!s) goto quit;

    strcpy(s->eye, CLIBSOCK_EYE);
    s->socket   = ss;
    if (name)   memcpy(s->name, name, sizeof(s->name));
    if (peer)   memcpy(s->peer, peer, sizeof(s->peer));
#if 0
    wtodumpf(s, sizeof(CLIBSOCK), "__soadd()");
#endif
    lock(&grt->grtsock,0);
    arrayadd(&grt->grtsock, s);
    unlock(&grt->grtsock,0);

quit:
    return rc;
}
