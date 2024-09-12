/* SNPRINTF.C */
#include "stdarg.h"
#include "stddef.h"

int
snprintf(char *s, int n, const char *format, ...)
{
    va_list arg;
    int ret;

    va_start(arg, format);
    ret = vsnprintf(s, n, format, arg);
    va_end(arg);

    return (ret);
}
