/* FWRITE.C */
#include "clibio.h"
#include "cliblock.h"

size_t
fwrite(const void *vptr, size_t size, size_t nmemb, FILE *fp)
{
    size_t  rc;

    lock(fp,0);

    rc = __fwrite(vptr, size, nmemb, fp);

    unlock(fp,0);

    return rc;
}
