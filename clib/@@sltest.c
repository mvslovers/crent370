#include "clibenq.h"
#include "cliblock.h"

__asm__("\n&FUNC    SETC 'systestlock'");
int
systestlock(void *thing, int read)
{
    unsigned    opts    = ENQ_SYSTEM | ENQ_TEST;
    char        rname[SYSLOCKRNAMESZ];

    if (read) opts |= ENQ_SHR;

    sprintf(rname, SYSLOCKRNAME, thing);

    return ENQ(SYSLOCKQNAME, rname, opts);
    /* 0==resource is not locked */
}
