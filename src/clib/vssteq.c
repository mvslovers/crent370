#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"
#include "cliblock.h"

int
vssteq(VSFILE *vs, void *rec, int reclen, void *key, int keylen)
{
    int     rc      = 0;

    lock(vs,0);

    rc = __vssteq(vs, rec, reclen, key, keylen);

    unlock(vs,0);

    return rc;
}
