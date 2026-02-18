/* UNGETC.C */
#include "clibio.h"
#include "cliblock.h"

int
ungetc(int c, FILE *fp)
{
    lock(fp,0);

    if ((fp->ungetch != -1) || (c == EOF)) {
        c = EOF;
    }
    else {
        fp->ungetch = (unsigned char)c;
    }

    unlock(fp,0);

    return c;
}
