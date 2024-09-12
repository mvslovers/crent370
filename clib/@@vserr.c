#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"

int
__vserr(VSFILE *vs)
{
    if (vs->flags & VSFILE_FLAG_ERROR) {
        return 1;
    }

    return 0;
}
