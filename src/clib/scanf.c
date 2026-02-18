/* SCANF.C */
#include <stdio.h>
#include <stdarg.h>

int
scanf(const char *format, ...)
{
    va_list arg;
    int ret;

    va_start(arg, format);
    ret = vvscanf(format, arg, stdin, NULL);
    va_end(arg);
    return (ret);
}
