/* REMOVE.C */
#include <stdio.h>
#include <ctype.h>
#include <mvssupa.h>
#include "cliblock.h"

int
remove(const char *filename)
{
    int ret;
    char buf[FILENAME_MAX + 50];
    char *p;

    sprintf(buf, " DELETE %s", filename);
    p = buf;
    while (*p != '\0') {
       *p = toupper((unsigned char)*p);
       p++;
    }

#if 0
    lock(__idcams,0);
    ret = __idcams(strlen(buf), buf);
    unlock(__idcams,0);
#else
    lock(idcams,0);
    ret = idcams(buf);
    unlock(idcams,0);
#endif
    return (ret);
}
