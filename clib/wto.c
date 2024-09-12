/* WTO.C */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct wtomsg {
    short   len;
    short   mcsflags;
    char    buf[128];
} WTOMSG;

extern void wtoline(const WTOMSG *msg);

void
wto(char *buf)
{
    int     len = strlen(buf);
    WTOMSG  msg;

    do {
        if (len <= 124) {
            msg.len = len + 4;
            msg.mcsflags = 0;
            if (len > 0) memcpy(msg.buf, buf, len);
            len = 0;
        }
        else {
            char *p = &buf[124];

            while(*p != ' ' && p > buf) p--;

            if (p==buf) {
                p = &buf[124];  /* no spaces, use 124 characters */
            }
            else if (*p==' ') {
                p++; /* include last space */
            }

            msg.len = (int)(p-buf);     /* length of message segment */
            msg.mcsflags = 0;
            memcpy(msg.buf, buf, msg.len);
            msg.buf[msg.len] = 0;
            /* shift the buffer left and adjust length */
            len -= msg.len;
            if (len > 0) memcpy(buf, p, len);
            buf[len] = 0;
            msg.len += 4;
        }
        wtoline(&msg);
    } while(len > 0);
}
