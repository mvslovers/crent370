/* FSEEK.C */
#include "clibio.h"
#include "cliblock.h"

int
fseek(FILE *fp, long int offset, int whence)
{
    int     rc;

    lock(fp,0);

    rc = __fseek(fp,offset,whence);

    unlock(fp,0);

    return rc;
}
