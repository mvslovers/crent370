/* FERROR.C */
#include <stdio.h>

#undef getchar
#undef putchar
#undef getc
#undef putc
#undef feof
#undef ferror

int
ferror(FILE *fp)
{
    return (fp->flags & _FILE_FLAG_ERROR ? 1 : 0);
}
