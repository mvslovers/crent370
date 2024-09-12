#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"
#include "cliblock.h"

int
vserror(VSFILE *vs)
{
    int     rc;

    lock(vs,0);

    rc = __vserr(vs);

    unlock(vs,0);

    return rc;
}
