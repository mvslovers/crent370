/* LOADENV.C */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "clibenv.h"

static int numbered(const char *buf, int *len);

int
loadenv(const char *fn)
{
    int     err     = 1;
    FILE    *fp     = fopen(fn,"r");
    char    *p;
    int     len;
    char    buf[1024];

    if (!fp) goto quit;

    while(fgets(buf, sizeof(buf), fp)) {
        p = strrchr(buf, '\n');     /* get last newline character in buf    */

        if (p) *p = 0;              /* remove the trailing newline          */
        if (buf[0]=='*') continue;  /* skip MVS style "* comments"          */
        if (buf[0]=='#') continue;  /* skip Unix style "# comments"         */
        if (numbered(buf, &len)) {
            /* remove sequence numbers from end of buf */
            buf[len-8] = 0;
            len -= 8;
        }
        /* remove any trailing spaces */
        for(len--; len > 0 && buf[len]==' '; len--) buf[len] = 0;

        if (strchr(buf, '=')) {     /* do we have "name = value"?           */
            putenv(buf);            /* yes, set environment variable        */
        }
    }

    err = 0;

quit:
    if (fp) fclose(fp);
    return err;
}

__asm__("\n&FUNC    SETC 'numbered'");
static int
numbered(const char *buf, int *len)
{
    int         rc  = 0;
    const char  *p;

    *len = strlen(buf);
    if (*len <= 8) goto quit;

    /* examine last 8 character of buf for sequnence number */
    for(p = &buf[(*len)-8]; *p; p++) {
        if (*p >= '0' && *p <= '9') continue;   /* sequence number  */
        goto quit;                              /* no sequence      */
    }

    rc = 1; /* buf looks like it has sequence numbers in last 8 characters */

quit:
    return rc;
}
