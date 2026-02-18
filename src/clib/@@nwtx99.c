/* @@NWTX99.C */
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "svc99.h"

TXT99 *
__nwtx99(int dal, int count, int size, const char *text)
{
    int     bytes   = count * size;
    TXT99   *txt99  = calloc(1, sizeof(TXT99) + bytes);

    if (txt99) {
        txt99->dal        = (unsigned short)dal;
        txt99->count      = (unsigned short)count;
        txt99->size       = (unsigned short)size;
        if (text) {
            memcpy(txt99->text, text, bytes);
        }
    }

    return txt99;
}
