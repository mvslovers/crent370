/* VWTOF.C */
#define CLIB_C
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "clib.h"

void
vwtorf(char *reply, unsigned replymax, const char *text, va_list tList)
{
    int     len;
    char    *p;
    char    buf[4096];

    len = vsnprintf(buf, sizeof(buf), text, tList);
    if (len >= sizeof(buf)) len = sizeof(buf) - 1;
    buf[len] = 0;

    /* if the buffer is formatted with newlines */
    p = strchr(buf, '\n');
    if (p) {
        while(p) {
            /* truncate at the newline */
            *p++ = 0;
            /* write out the buffer */
            wto(buf);
            /* shift everything left */
            strcpy(buf, p);
            /* look for next newline */
            p = strchr(buf, '\n');
        }
        /* done */
        len = strlen(buf);
        if (len==0) return;
    }

    /* no newlines, do normal wto processing */
    buf[len] = 0;
    wtor(reply, replymax, buf);
}
