#include "clibenq.h"
#include "cliblock.h"

__asm__("\n&FUNC    SETC 'sysunlock'");
int
sysunlock(void *thing, int read)
{
    unsigned    opts    = ENQ_SYSTEM | ENQ_HAVE;
    char        rname[SYSLOCKRNAMESZ];

    sprintf(rname, SYSLOCKRNAME, thing);

    return DEQ(SYSLOCKQNAME, rname, opts);
}
