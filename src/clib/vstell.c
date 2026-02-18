#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"
#include "cliblock.h"

unsigned
vstell(VSFILE *vs)
{
    unsigned    rba     = 0;

    lock(vs,0);

    rba = __vstell(vs);

    unlock(vs,0);

quit:
    return rba;
}
