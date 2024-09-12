/* @@FPOPEN.C */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <mvssupa.h>
#include "osdcb.h"
#include "osjfcb.h"

__asm__("\n&FUNC    SETC '__fpopen'");
int
__fpopen(FILE *fp)
{
    int     err     = 1;
    int     i       = 0;
    int     mode    = 0;    /* 0==read, 1==write */
    int     recfm   = 0;    /* 0==fixed, 1==variable, 2==undefined */
    int     lrecl   = 0;
    int     blksize = 0;
    DCB     *dcb    = 0;
    void    *asmbuf = 0;
    char    *pmember= 0;
    JFCB    *j      = 0;
    char    ddname[8] = {0};
    char    member[8] = {0};
    JFCB    jfcb    = {0};

    if (!fp) goto quit;
    if (!fp->ddname[0]) goto quit;

    for(i=0;i<8 && fp->ddname[i]; i++) {
        ddname[i] = fp->ddname[i];
    }
    for(;i<8; i++) ddname[i] = ' ';

    if (fp->flags & _FILE_FLAG_WRITE) mode = mode + 1;
    if (fp->flags & _FILE_FLAG_BSAM)  mode = mode + 8;

    if (fp->member[0] > ' ') {
        for(i=0;i<8 && fp->member[i];i++) {
            member[i] = fp->member[i];
        }
        for(;i<8;i++) {
            member[i] = ' ';
        }
        pmember = member;
    }

    switch(fp->recfm & _FILE_RECFM_TYPE) {
    case _FILE_RECFM_F:     /* ... FIXED RECORD LENGTH              */
        recfm = 0;
        break;
    case _FILE_RECFM_V:     /* ... VARIABLE RECORD LENGTH           */
        recfm = 1;
        break;
    case _FILE_RECFM_U:     /* ... UNDEFINED RECORD LENGTH          */
        recfm = 2;
        break;
    }

    lrecl = fp->lrecl;
    blksize = fp->blksize;

    /* open dataset */
    fp->dcb = __aopen(ddname, &mode, &recfm, &lrecl,
                &blksize, &asmbuf, pmember);

    if ((int)fp->dcb < 0) goto quit;

    /* success */
    fp->flags   |= _FILE_FLAG_OPEN;
    fp->asmbuf  = asmbuf;
    fp->ungetch = -1;

    /* get the recfm, lrecl, and blksize from the DCB */
    dcb = fp->dcb;
    fp->recfm   = dcb->dcbrecfm;
    fp->lrecl   = dcb->dcblrecl;
    fp->blksize = dcb->dcbblksi;

    if (!(fp->flags & _FILE_FLAG_RECORD)) {
        /* not record oriented i/o */
        /* allocate file handle data buffer */
        switch(fp->recfm & _FILE_RECFM_TYPE) {
        case _FILE_RECFM_F: i = fp->lrecl;      break;
        case _FILE_RECFM_V: i = fp->lrecl - 4;  break;
        case _FILE_RECFM_U: i = fp->blksize;    break;
        }
        fp->buf     = calloc(1, i + 8);
        if (!fp->buf) goto quit;

        if (fp->flags & _FILE_FLAG_WRITE) {
            /* set file handle buffer pointers */
            fp->upto    = fp->buf;
            fp->endbuf  = fp->buf + i;
        }
    }

    /* read JFCB to get the dataset name */
    err = __rdjfcb(fp->dcb, &jfcb);
    if (err) goto quit;
#if 0
	wtodumpf(&jfcb, sizeof(jfcb), "__fpopen:jscb");
#endif
    if (jfcb.jfcbdsnm[0] > ' ') {
        for(i=0; i < 44 && jfcb.jfcbdsnm[i] > ' '; i++) {
            fp->dataset[i] = jfcb.jfcbdsnm[i];
        }
        fp->dataset[i] = 0;
    }
#if 0
	wtof("__fpopen: jfcb.jfcdsrg1=0x%02X dcb->dcbdsrg1=0x%02X",
		jfcb.jfcdsrg1, dcb->dcbdsrg1);
#endif

quit:
    return err;
}
