/* CLEARERR.C */
#include <stdio.h>

void
clearerr(FILE *fp)
{
    fp->flags &= 0xFFFF - (_FILE_FLAG_ERROR + _FILE_FLAG_EOF);
    return;
}
