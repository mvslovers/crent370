/* FEOF.C */
#include <stdio.h>

#undef getchar
#undef putchar
#undef getc
#undef putc
#undef feof
#undef ferror

int
feof(FILE *fp)
{
    return (fp->flags & _FILE_FLAG_EOF ? 1 : 0);
}
