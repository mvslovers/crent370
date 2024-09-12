/* WTORF.C */
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
wtorf(char *reply, unsigned replymax, const char *text, ...)
{
    va_list tList;

    va_start(tList, text);
    vwtorf(reply, replymax, text, tList);
    va_end(tList);
}
