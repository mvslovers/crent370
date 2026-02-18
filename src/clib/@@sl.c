#include "clibenq.h"
#include "cliblock.h"
#include "clibio.h"

__asm__("\n&FUNC    SETC 'syslock'");
int
syslock(void *thing, int read)
{
    unsigned    opts    = ENQ_SYSTEM | ENQ_HAVE;
    char        rname[SYSLOCKRNAMESZ];
#if 0
    wtof("Function \"%s\" called lock() with %08X pointer",
        __caller(0), thing);
#endif
    if (read) opts |= ENQ_SHR;

    sprintf(rname, SYSLOCKRNAME, thing);

    return ENQ(SYSLOCKQNAME, rname, opts);
}
