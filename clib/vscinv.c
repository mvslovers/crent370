#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"
#include "cliblock.h"

unsigned
vscinv(VSFILE *vs)
{
    unsigned    cinv    = 0;

    lock(vs,0);

    cinv = __vscinv(vs);

    unlock(vs,0);

    return cinv;
}
