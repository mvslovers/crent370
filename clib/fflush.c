/* FFLUSH.C */
#include "clibio.h"
#include "cliblock.h"

int
fflush(FILE *fp)
{
    int             err     = 0;

    lock(fp,0);

    err = __fflush(fp);

    unlock(fp,0);

    return err;
}
