#include <stdarg.h>
#include <stdio.h>
#include "clibenq.h"
#include "cliblock.h"

int
__lkuntf(const char *fmt, int read, ...)
{
    va_list list;
    char    rname[256];

    va_start(list, read);
    vsprintf(rname, fmt, list);
    va_end(list);

    return trylock_res(rname, read);
}
