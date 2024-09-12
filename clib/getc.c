/* GETC.C */
#include <stdio.h>

#undef getchar
#undef putchar
#undef getc
#undef putc
#undef feof
#undef ferror

int
getc(FILE *stream)
{
    return (fgetc(stream));
}
