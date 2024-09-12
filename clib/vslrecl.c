#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"
#include "cliblock.h"

unsigned
vslrecl(VSFILE *vs)
{
    unsigned    lrecl   = 0;

    lock(vs,0);

    lrecl = __vslrec(vs);

    unlock(vs,0);

    return lrecl;
}
