#include "clibenq.h"
#include "cliblock.h"

int
__lkrnun(const char *rname, int read)
{
    unsigned    opts    = ENQ_HAVE;

    return DEQ(LOCKQNAME, rname, opts);
}
