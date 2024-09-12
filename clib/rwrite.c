/* RWRITE.C - write dataset record */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <mvssupa.h>
#include "rfile.h"

int
rwrite(RFILE *fp, const void *ptr, size_t size)
{
    int             err     = 0;
    unsigned char   *dptr   = fp->asmbuf;

    if (!size) size = fp->lrecl;

    memcpy(dptr, ptr, size);
    if (__awrite(fp->hfile, &dptr, &size)) {
        err = 1;
    }

    return err;
}
