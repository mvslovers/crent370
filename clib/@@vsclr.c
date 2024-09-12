#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"

int
__vsclr(VSFILE *vs)
{
    vs->flags       &= 0xFF - (VSFILE_FLAG_ERROR | VSFILE_FLAG_EOF);
    vs->rc          = 0;
    vs->component   = 0;
    vs->rsn         = 0;

    return 0;
}
