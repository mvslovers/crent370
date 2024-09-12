#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"
#include "cliblock.h"

int
vsdelete(VSFILE *vs, void *rec, int reclen)
{
    int     rc;

    lock(vs,0);

    rc = __vsdel(vs, rec, reclen);

    unlock(vs,0);

    return rc;
}
