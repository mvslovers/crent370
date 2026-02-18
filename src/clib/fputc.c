/* FPUTC.C */
#include "clibio.h"
#include "cliblock.h"

int
fputc(int c, FILE *fp)
{
    int     rc;

    lock(fp,0);

    rc = __fputc(c,fp);

    unlock(fp,0);

    return rc;
}
