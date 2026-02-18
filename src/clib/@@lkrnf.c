#include <stdarg.h>
#include "clibenq.h"
#include "cliblock.h"
#include "clibio.h"

int
__lkrnf(const char *fmt, int read, ...)
{
    va_list     list;
    char        rname[256];

    va_start(list,read);
    vsprintf(rname, fmt, list);
    va_end(list);

    return __lkrn(rname, read);
}
