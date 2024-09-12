#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include "clibvsam.h"
int
vsopen(const char *ddname, VSTYPE t, VSACCESS a, VSMODE m, VSFILE **vsfile)
{
    int         rc      = 0;

    rc = __vsopen(ddname, t, a, m, vsfile);

    return rc;
}
