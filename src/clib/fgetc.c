/* FGETC.C */
#include "clibio.h"
#include "cliblock.h"

int
fgetc(FILE *fp)
{
    int             c;

    lock(fp, 0);

    c = __fgetc(fp);

    unlock(fp, 0);

    return c;
}
