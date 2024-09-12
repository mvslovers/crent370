/* FTELL.C */
#include <stdio.h>

long int
ftell(FILE *fp)
{
    return fp->filepos;
}
