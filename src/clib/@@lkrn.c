#include "clibenq.h"
#include "cliblock.h"
#include "clibio.h"

int
__lkrn(const char *rname, int read)
{
    unsigned    opts    = ENQ_HAVE;

    if (read) opts |= ENQ_SHR;

    return ENQ(LOCKQNAME, rname, opts);
}
