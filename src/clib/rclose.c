/* RCLOSE.C - close dataset opened by ropen() */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <mvssupa.h>
#include "rfile.h"

extern int      __fildef(char *fdddname, char *fnm, int mymode, int type);
extern int      __fdclr(char *fdddname);
extern char *   __getpfx(void);

int
rclose(RFILE *fp)
{
    int     err = 0;

    if (!fp) goto quit;

    if (fp->hfile) __aclose(fp->hfile);

    free(fp);

quit:
    return err;
}
