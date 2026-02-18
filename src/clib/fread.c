/* FREAD.C */
#include "clibio.h"
#include "cliblock.h"

size_t
fread(void *ptr, size_t size, size_t nmemb, FILE *fp)
{
    size_t rc;

    lock(fp,0);

    rc = __fread(ptr,size,nmemb,fp);

    unlock(fp,0);

    return rc;
}
