/* SETENVI.C */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "clibenv.h"

int
setenvi(const char *name, int value, int rewrite)
{
    char        buf[40];

    sprintf(buf, "%d", value);

    return setenv(name, buf, rewrite);
}
