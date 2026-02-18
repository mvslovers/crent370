/* PUTCHAR.C */
#include <stdio.h>

#undef getchar
#undef putchar
#undef getc
#undef putc
#undef feof
#undef ferror

int
putchar(int c)
{
    return (putc(c, stdout));
}
