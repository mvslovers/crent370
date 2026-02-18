#define LIB_STDIO
#define STDIO_C
#include "stdio.h"

#undef getchar
#undef putchar
#undef getc
#undef putc

static STDIO    lib = {
    __gtin,
    __gtout,
    __gterr,
    printf,
    fopen,
    fclose,
    fread,
    fwrite,
    fputc,
    fputs,
    fprintf,
    vfprintf,
    remove,
    rename,
    sprintf,
    vsprintf,
    fgets,
    ungetc,
    fgetc,
    fseek,
    ftell,
    fsetpos,
    fgetpos,
    rewind,
    clearerr,
    perror,
    setvbuf,
    setbuf,
    freopen,
    fflush,
    tmpnam,
    tmpfile,
    fscanf,
    scanf,
    sscanf,
    gets,
    puts,
    getchar,
    putchar,
    getc,
    putc,
    vsnprintf,
};

STDIO   *stdio = &lib;
