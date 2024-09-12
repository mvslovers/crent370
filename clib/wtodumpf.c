/* WTODUMPF.C */
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void
wtodumpf(void *buf, int len, const char *fmt, ...)
{
    int     rc  = 0;
    va_list list;
    char    title[80];

    va_start(list, fmt);
    vsprintf(title, fmt, list);
    va_end(list);

    wtodump(title, buf, len, 16);

    return;
}
