/* PUTENV.C */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "clibenv.h"

/*
 * putenv() places a "name=value" into the environment variables.
 */
int
putenv(const char *str)
{
    int         err;
    char        *p;
    const char  *name;
    const char  *value;

    name = str;
    p = strchr(str, '=');
    if (p) {
        *p = 0;
        value = p+1;
    }
    else {
        value = "";
    }

    err = setenv(name, value, 1);
    if (p) *p = '=';

quit:
    return err;
}
