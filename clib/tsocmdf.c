#include <clibtso.h>
#include <clib.h>

int tsocmdf(const char *pgm, const char *format, ...)
{
    va_list arg;
    int 	rc;
    char    buf[1024];

    va_start(arg, format);
    vsnprintf(buf, sizeof(buf), format, arg);
    va_end(arg);

    rc = tsocmd(pgm, buf);

    return rc;
}
