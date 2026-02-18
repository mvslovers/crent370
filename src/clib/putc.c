/* PUTC.C */
#include <stdio.h>

#undef getchar
#undef putchar
#undef getc
#undef putc
#undef feof
#undef ferror

int
putc(int c, FILE *stream)
{
    return (fputc(c, stream));
}
