/* WTODUMP.C */
#define CLIB_C
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "clib.h"

void
wtodump(const char *title, void *varea, int size, int chunk)
{
    int             indent  = 0;
    int             i, j;
    int             iHex    = 0;
    int             ie      = 0;
    int             x       = (chunk * 2) + ((chunk / 4) - 1);
    unsigned char   *area   = (unsigned char*)varea;
    unsigned char   e;
    char            sHex[80];
    char            eChar[80];

    wtof("%*.*sDump of %08X \"%s\" (%d bytes)\n",
        indent, indent, "",
        area, title, size);

    for (i=0, j=0; size > 0;i++ ) {
        if ( i==chunk ) {
            wtof("%*.*s+%05X %-*.*s :%-*.*s:\n",
                indent, indent, "", j, x, x, sHex, chunk, chunk, eChar);
            j += i;
            ie = iHex = i = 0;
        }
        iHex += sprintf(&sHex[iHex],"%02X",*area);
        if ((i & 3) == 3) iHex += sprintf(&sHex[iHex]," ");

        e = *area;

        ie += sprintf(&eChar[ie],"%c", isgraph(e)?e:e==' '?e:'.');
        area++;
        size--;
    }

    if ( iHex ) {
        wtof("%*.*s+%05X %-*.*s :%-*.*s:\n",
            indent, indent, "", j, x, x, sHex, chunk, chunk, eChar);
    }

quit:
    return;
}
