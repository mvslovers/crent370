#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"
#include "cliblock.h"

int
vsupdate(VSFILE *vs, void *rec, int reclen)
{
    int     rc      = 0;

    lock(vs,0);

    rc = __vsupdt(vs, rec, reclen);

    unlock(vs,0);

quit:
    return rc;
}
