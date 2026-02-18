/* ROPEN.C - open dataset for sequential record access */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <mvssupa.h>
#include "rfile.h"
#include "clibcrt.h"

extern int      __fildef(char *fdddname, char *fnm, int mymode, int type);
extern int      __fdclr(char *fdddname);
extern char *   __getpfx(void);

int
ropen(const char *fnm, int write, RFILE **rfile)
{
    CLIBGRT *grt    = __grtget();
    RFILE   *fp     = (RFILE*)0;
    int     mode    = write ? 1 : 0;
    int     dyn     = 0;
    int     recfm   = 0;
    int     lrecl   = 0;
    int     blksize = 0;
    void    *hfile  = (void*)0;
    void    *asmbuf = (void*)0;
    int     i;
    int     err;
    char    *p;
    char    newfnm[FILENAME_MAX]    = {0};
    char    member[9]               = {0};
    char    tmpdd[9]                = {0};

    while(*fnm==' ') fnm++;

    if (toupper(fnm[0])=='D' && toupper(fnm[1])=='D' && fnm[2]==':') {
        p=(char*)&fnm[3];
        for(i=0;i<8 && p[i];i++) {
            if (p[i]=='(') break;
            tmpdd[i] = toupper(p[i]);
        }
        p=&p[i];
        while(i<8) tmpdd[i++] = ' ';
        tmpdd[i] = 0;
        if (*p=='(') {
            p++;
            for(i=0;i<8 && p[i];i++) {
                if (p[i]==')') break;
                member[i] = toupper(p[i]);
            }
            member[i] = 0;
        }
        goto doopen;
    }

    dyn=1;  /* we need to dynamically allocate the dataset */
    i = 0;  /* new file name character index */

    if (fnm[0]=='\'') {
        /* quoted dataset name */
        fnm++;
    }
    else {
        /* unquoted dataset name */
        if (grt->grtflag1 & GRTFLAG1_TSO) {
            p = __getpfx();
            if (p) {
                for(i=0; i < 8 && p[i]!=' ' && p[i]; i++) {
                    newfnm[i] = p[i];
                }
                newfnm[i++] = '.';
            }
        }
    }

    p = &newfnm[i];
    for(i=0; fnm[i] && fnm[i] != '('; i++) {
        p[i] = toupper(fnm[i]);
    }
    p[i] = 0;

    if (fnm[i]=='(') {
        p = (char*)&fnm[i+1];
        while(*p==' ') p++;
        for(i=0;i<8 && p[i]!=' ' && p[i];i++) {
            if (p[i]==')') break;
            member[i] = toupper(p[i]);
        }
        while(i<8) member[i++] = ' ';
        member[i] = 0;
    }

    /* dynamically allocate dataset */
    err = __fildef(tmpdd, newfnm, mode, 0);
    if (err) goto quit;

doopen:
    recfm   = 1;    /* variable */
    lrecl   = 255;
    blksize = 6233;

    hfile   = __aopen(tmpdd, &mode, &recfm, &lrecl, &blksize, &asmbuf, member);
    /* errors from MVS __aopen are negative numbers */
    if ((int)hfile <= 0) {
        err = 1;
        errno = -(int)hfile;
        goto quit;
    }

    fp = (RFILE*) calloc(1, sizeof(RFILE));
    if (!fp) {
        __aclose(hfile);
        if (dyn) __fdclr(tmpdd);
        err = 1;
        goto quit;
    }

    for(i=0; RFILE_EYE[i]; i++) {
        fp->eye[i] = RFILE_EYE[i];
    }
    fp->dyn     = dyn;
    fp->recfm   = recfm;
    fp->lrecl   = lrecl;
    fp->write   = write;
    fp->hfile   = hfile;
    fp->asmbuf  = asmbuf;
    for(i=0; i < 8 && tmpdd[i]; i++) {
        fp->ddname[i] = tmpdd[i];
    }
    for(i=0; i < 8 && member[i]; i++) {
        fp->member[i] = member[i];
    }
    *rfile      = fp;
    err         = 0;

quit:
    return err;
}
