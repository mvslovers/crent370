#include "clibenq.h"
#include "cliblock.h"

__asm__("\n&FUNC    SETC 'unlock'");
int
unlock(void *thing, int read)
{
    unsigned    opts    = ENQ_HAVE;
    char        rname[LOCKRNAMESZ];

    sprintf(rname, LOCKRNAME, thing);

    return DEQ(LOCKQNAME, rname, opts);
}
