/* RREAD.C - read dataset record */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <mvssupa.h>
#include "rfile.h"

int
rread(RFILE *fp, void *ptr, size_t *read)
{
    int             err     = 0;
    size_t          len     = 0;
    unsigned char   *dptr   = fp->asmbuf;

    if (__aread(fp->hfile, &dptr, &len) != 0) {
        err = 1;
        goto quit;
    }

    memcpy(ptr, dptr, len);
    if (read) *read = len;

quit:
    return err;
}
