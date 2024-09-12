/* FPUTS.C */
#include "clibio.h"
#include "cliblock.h"

int
fputs(const char *s, FILE *fp)
{
    int rc;

    lock(fp,0);

    rc = __fputs(s,fp);

    unlock(fp,0);

    return rc;
}
