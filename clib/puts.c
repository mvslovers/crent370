/* PUTS.C */
#include <stdio.h>

int
puts(const char *s)
{
    int ret;

    ret = fputs(s, stdout);
    if (ret == EOF) {
        return (ret);
    }

    return (putc('\n', stdout));
}
