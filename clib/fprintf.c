/* FPRINTF.C */
#include <stdio.h>

int
fprintf(FILE *stream, const char *format, ...)
{
    va_list arg;
    int ret;
#if 1
    int     len;
    char    buf[8192];
#endif

    va_start(arg, format);
#if 1
    len = vsnprintf(buf, sizeof(buf), format, arg);
    if (len > sizeof(buf)) len = sizeof(buf);
    ret = fwrite(buf, 1, len, stream);
#else
    ret = vfprintf(stream, format, arg);
#endif
    va_end(arg);
    return (ret);
}
