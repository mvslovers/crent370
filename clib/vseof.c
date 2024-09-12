#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"
#include "cliblock.h"

int
vseof(VSFILE *vs)
{
    int     rc;

    lock(vs,0);

    rc = __vseof(vs);

    unlock(vs,0);

    return rc;
}
