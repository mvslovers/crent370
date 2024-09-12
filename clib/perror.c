/* PERROR.C */
#include <stdio.h>
#include <errno.h>
#include <string.h>

void
perror(const char *s)
{
    const char *str = strerror(errno);
    static char err[24];

    if ((s != NULL) && (*s != '\0')) {
        fprintf(stderr, "%s: ", s);
    }

    if (!str) {
        str = err;
        sprintf(err, "unknown error:%d", errno);
    }

    fprintf(stderr, "%s\n", str);

    return;
}
