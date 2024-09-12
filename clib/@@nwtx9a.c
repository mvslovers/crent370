/* @@NWTX9A.C */
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "svc99.h"

TXT99 *
__nwtx9a(int dal, int count, char **array)
{
    int     i;
    int     len = 0;
    int     bytes;
    TXT99   *txt99;
    struct Next {
        unsigned short size;
        unsigned char  text[1];
    } *next;

    for(i=0; i < count; i++) {
        if (array[i]) {
            len += strlen(array[i]);
        }
    }

    bytes = (count * 2) + len;
    txt99 = calloc(1, sizeof(TXT99) + bytes);

    if (txt99) {
        txt99->dal      = (unsigned short)dal;
        txt99->count    = (unsigned short)count;

        next = (struct Next *) &txt99->size;

        for(i=0; i < count; i++) {
            if (array[i]) {
                len = strlen(array[i]);
                next->size  = (unsigned short)len;
                memcpy(next->text, array[i], len);
            }
            else {
                len = 0;
            }
            next = (struct Next *)&next->text[len];
        }
    }

    return txt99;
}
