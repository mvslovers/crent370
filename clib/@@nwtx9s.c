/* @NWTX9S.C */
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "svc99.h"

TXT99 *
__nwtx9s(int dal, int count, ...)
{
    va_list list;
    int     i;
    int     len;
    int     bytes;
    char    *text;
    TXT99   *txt99;
    struct Next {
        unsigned short size;
        unsigned char  text[1];
    } *next;

    va_start(list, count);
    for(len=0, i=0; i < count; i++) {
        text = va_arg(list, char *);
        if (!text) break;
        len += strlen(text);
    }

    bytes = (count * 2) + len;
    txt99 = calloc(1, sizeof(TXT99) + bytes);

    if (txt99) {
        txt99->dal      = (unsigned short)dal;
        txt99->count    = (unsigned short)count;

        va_start(list, count);
        next = (struct Next *) &txt99->size;

        while (count-- > 0) {
            text = va_arg(list, char *);
            if (!text) break;

            len = strlen(text);
            next->size  = (unsigned short)len;
            memcpy(next->text, text, len);

            next = (struct Next *)&next->text[len];
        }
    }

    return txt99;
}
