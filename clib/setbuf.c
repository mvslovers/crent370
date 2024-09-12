/* SETBUF.C */
#include <stdio.h>

int
setbuf(FILE *stream, char *buf)
{
    int ret;

    if (buf == NULL) {
        ret = setvbuf(stream, NULL, _IONBF, 0);
    }
    else {
        ret = setvbuf(stream, buf, _IOFBF, BUFSIZ);
    }
    return (ret);
}
