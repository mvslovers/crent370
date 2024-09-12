/* PRINTF.C */
#include "stdio.h"

int
printf(const char *format, ...)
{
    va_list arg;
    int ret;

    va_start(arg, format);
    ret = vfprintf(stdout, format, arg);
    va_end(arg);
    return (ret);
}
