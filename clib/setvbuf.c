/* SETVBUF.C */
#include <stdio.h>

int
setvbuf(FILE *stream, char *buf, int mode, size_t size)
{
    /* don't allow mucking around with buffers on MVS or CMS */
    return (0);
}
