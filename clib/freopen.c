/* FREOPEN.C */
#include "clibio.h"
#include "cliblock.h"

FILE *
freopen(const char *fn, const char *mode, FILE *fp)
{
    FILE    *f;

    lock(fp,0);

    f = __reopen(fn,mode,fp);

    unlock(fp,0);

    return f;
}
