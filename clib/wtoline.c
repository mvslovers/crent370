/* WTOLINE.C */
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

void
wtoline(const WTOMSG *msg)
{
    __asm__("LA\t1,0(,%0)\n\t"
            "SVC\t35        WTO"
            : /* no output */
            : "r" (msg));
}
