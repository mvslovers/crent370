#include "clibenq.h"
#include "cliblock.h"

int
__lkuntr(const char *rname, int read)
{
    unsigned    opts    = ENQ_USE;

    if (read) opts |= ENQ_SHR;

    return ENQ(LOCKQNAME, rname, opts);
}
