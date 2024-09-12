/* GETCHAR.C */
#include <stdio.h>

#undef getchar
#undef putchar
#undef getc
#undef putc
#undef feof
#undef ferror

int
getchar(void)
{
    return (getc(stdin));
}
