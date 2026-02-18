#include "clibenq.h"
#include "cliblock.h"

__asm__("\n&FUNC    SETC 'testlock'");
int
testlock(void *thing, int read)
{
    unsigned    opts    = ENQ_TEST;
    char        rname[LOCKRNAMESZ];

    if (read) opts |= ENQ_SHR;

    sprintf(rname, LOCKRNAME, thing);

    return ENQ(LOCKQNAME, rname, opts);
    /* 0==resource is not locked */
}
