/* FOPEN.C */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "cliblock.h"
#include "clibary.h"
#include "clibcrt.h"
#include "clibtry.h"

extern char *__getpfx(void);

extern int  __fpmode(FILE *fp, const char *mode);
extern int  __fpopen(FILE *fp);
extern int  __fpstar(FILE *fp);
extern int  __fpshr(FILE *fp);
extern int  __fpold(FILE *fp);
extern int  __fpnew(FILE *fp);

FILE *
fopen(const char *fn, const char *mode)
{
    CLIBGRT *grt    = __grtget();
    int     err     = 1;
    FILE    *fp     = 0;
    int     i;

    if (!fn)    goto quit;
    if (!mode)  goto quit;

    fp = calloc(1, sizeof(_FILE)); 
    if (!fp) goto quit;

    for(i=0; _FILE_EYE[i]; i++) {
        fp->eye[i] = _FILE_EYE[i];
    }
    err = __fpmode(fp, mode);
    if (err) goto quit;

    if (fp->flags & _FILE_FLAG_WRITE) {
        /* These values are used as a suggestion to __fpopen() and __aopen()
           when opening a dataset that does not have DCB values */
        fp->recfm = _FILE_RECFM_V;  /* __aopen() will try to open as variable length records */
        fp->lrecl = 136;            /* this will be the block size, the lrecl will be 4 bytes less */
    }

    if (tolower(fn[0])=='d' && tolower(fn[1])=='d' && fn[2]==':') {
        /* "DD:ddname[(member)]" */
        fn+=3;
        for(i=0; i < 8 && *fn && *fn!='('; i++,fn++) {
            fp->ddname[i] = toupper(*fn);
        }
        if (*fn=='(') {
            /* extract member name */
            for(i=0, fn++; i < 8 && *fn && *fn!=')'; i++, fn++) {
                fp->member[i] = toupper(*fn);
            }
        }
        goto doopen;
    }

    if (fn[0]=='*') {
        /* SYSOUT request "*[ddname]" */
        /* copy ddname name */
        for(i=0, fn++;i < 8 && *fn && *fn !='('; i++, fn++) {
            fp->ddname[i] = toupper(*fn);
        }
        if (fp->ddname[0]) {
            /* try to open DDNAME */
            err = __fpopen(fp);
            if (!err) goto quit;    /* success, we're done */
        }

        /* allocate SYSOUT dataset */
        err = __fpstar(fp);
        if (err) goto quit;

        /* open SYSOUT dataset */
        goto doopen;
    }

    /* fn *should* be a dataset name */
    i = 0;
    if (fn[0]=='\'') {
        /* quoted dataset name */
        fn++;       /* skip the single quote */
    }
    else {
        /* unquoted dataset name */
        if (fn[0]!='&') {
            /* not a &temp dataset name */
            if (grt->grtflag1 & GRTFLAG1_TSO) {
                /* running under TSO environment */
                char *gp = __getpfx();
                if (gp) {
                    /* prepend prefix */
                    for(;i < 8 && *gp; i++,gp++) {
                        fp->dataset[i] = toupper(*gp);
                    }
                    fp->dataset[i++]='.';
                }
            }
        }
    }

    /* copy dataset name */
    for(;i < 44 && *fn && *fn !='(' && *fn!='\''; i++, fn++) {
        fp->dataset[i] = toupper(*fn);
    }
    if (*fn=='(') {
        /* copy member name */
        fn++;
        for(i=0; i < 8 && *fn && *fn!=')'; i++, fn++) {
            fp->member[i] = toupper(*fn);
        }
    }

    if (fp->flags & _FILE_FLAG_READ) {
        /* READ, allocate dataset DISP=SHR */
        err = __fpshr(fp);
    }
    else {
        /* WRITE, allocate dataset */
        if (fp->dataset[0]=='&') {
            /* temp dataset being allocated, try alloc DISP=NEW on VIO */
            err = __fptmp(fp);
            if (!err) goto doopen;
        }
        if (fp->member[0]) {
            /* allocate PDS member DISP=SHR */
            err = __fpshr(fp);
            if (!err) goto doopen;
        }
        /* allocate dataset DISP=OLD */
        err = __fpold(fp);
        if (!err) goto doopen;

        /* try allocating dataset DISP=NEW */
        err = __fpnew(fp);
    }
    if (err) goto quit;

doopen:
    err = __fpopen(fp);

quit:
    if (err) {
        /* an error occured, return NULL */
        if (fp) {
            /* close the file handle */
            fclose(fp);
            fp = 0;
        }
    }

    if (fp) {
        lock(&grt->grtfile,0);
        arrayadd(&grt->grtfile, fp);
        unlock(&grt->grtfile,0);
    }

    return fp;
}
