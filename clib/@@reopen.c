/* @@REOPEN.C */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "clibcrt.h"
#include "cliblock.h"
#include "clibary.h"

FILE *
__reopen(const char *fn, const char *mode, FILE *fp)
{
    CLIBGRT *grt    = __grtget();
    int     err     = 1;
    int     dynamic = 0;
    unsigned count;
    FILE    *f;

    if (!fp) goto quit;
    if (!(fp->flags & _FILE_FLAG_OPEN)) goto quit;

    if (fp->flags & _FILE_FLAG_OPEN) {
        /* flush any pending data to disk */
        fflush(fp);
    }

    /* open "new" file handle */
    f = fopen(fn, mode);
    if (!f) {
        /* set error indicator, keep file open */
        fp->flags |= _FILE_FLAG_ERROR;
        fp = NULL;  /* indicate failure */
        goto quit;
    }

    /* success, copy "new" file handle into "old" file handle */
    if (fp->flags & _FILE_FLAG_OPEN) __aclose(fp->dcb);
    fp->dcb     = f->dcb;
    f->dcb      = 0;
    fp->asmbuf  = f->asmbuf;
    f->asmbuf   = 0;
    fp->lrecl   = f->lrecl;
    fp->blksize = f->blksize;
    fp->filepos = f->filepos;

    if (fp->buf) free(fp->buf);
    fp->buf     = f->buf;
    f->buf      = 0;
    fp->upto    = f->upto;
    f->upto     = 0;
    fp->endbuf  = f->endbuf;
    f->endbuf   = 0;

    if (fp->flags & _FILE_FLAG_DYNAMIC) {
        /* if same DDNAME, then don't free the old dd allocation */
        if (strcmp(fp->ddname, f->ddname)!=0) {
            /* different DDNAME */
            /* deallocate dd for the old file handle */
            __fpfree(fp);
        }
        else {
            dynamic = 1;    /* same DD, so force dynamic flag on */
        }
    }

    fp->flags   = f->flags;
    if (dynamic)    fp->flags |= _FILE_FLAG_DYNAMIC;
    f->flags    = 0;
    fp->recfm   = f->recfm;
    memcpy(fp->ddname, f->ddname, sizeof(fp->ddname));
    memcpy(fp->member, f->member, sizeof(fp->member));
    memcpy(fp->dataset, f->dataset, sizeof(fp->dataset));
    memcpy(fp->mode, f->mode, sizeof(fp->mode));

    /* remove "new" file handle from array of open file handles */
    lock(&grt->grtfile,0);
    count = arraycount(&grt->grtfile);
    while(count > 0) {
        count--;
        if (grt->grtfile[count]==f) {
            arraydel(&grt->grtfile, count+1);
            break;
        }
    }
    unlock(&grt->grtfile,0);

    /* free "new" file handle (f) storage */
    free(f);

quit:
    return (fp);
}
