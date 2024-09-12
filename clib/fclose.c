/* FCLOSE.C */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <mvssupa.h>
#include "clibcrt.h"
#include "cliblock.h"
#include "clibary.h"

extern int  __fpfree(FILE *fp);

int
fclose(FILE *fp)
{
    CLIBGRT *grt    = __grtget();
    unsigned count;
    if (!fp) goto quit;
    if (strcmp(fp->eye, _FILE_EYE)!=0) goto quit;

    if (fp->flags & _FILE_FLAG_OPEN) {
        /* flush any pending data to disk */
        fflush(fp);

        /* close the dataset */
        __aclose(fp->dcb);
        fp->dcb     = 0;
        fp->asmbuf  = 0;
    }

    if (fp->buf) {
        free(fp->buf);
        fp->buf     = 0;
        fp->upto    = 0;
        fp->endbuf  = 0;
    }

    if (fp->flags & _FILE_FLAG_DYNAMIC) {
        /* deallocate the dataset */
        __fpfree(fp);
    }

    /* remove file handle from array of open file handles */
    lock(&grt->grtfile,0);
    count = arraycount(&grt->grtfile);
    while(count > 0) {
        count--;
        if (grt->grtfile[count]==fp) {
            arraydel(&grt->grtfile, count+1);
            break;
        }
    }
    unlock(&grt->grtfile,0);

    free(fp);

quit:
    return 0;
}
