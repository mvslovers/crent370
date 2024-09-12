/* FGETS.C */
#include "clibio.h"
#include "cliblock.h"

char *
fgets(char *s, int n, FILE *fp)
{
    lock(fp, 0);

    s = __fgets(s,n,fp);

    unlock(fp, 0);

    return s;
}
