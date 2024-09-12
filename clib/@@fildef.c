/* @@FILDEF.C - dynamic allocation */
#include <stdio.h>
#include <errno.h>

/*
   filedef dynamically allocates a file (via SVC 99) on MVS-like
   environments.
*/

struct rb {
    char    len; /* length of request block, always 20 */
    char    verb; /* dynamic allocation function requested */
    char    flag1;
    char    flag2;
    short   error_reason; /* returned */
    short   info_reason; /* returned */
    void    *tu_list; /* list of pointers to text units */
    int     reserved;
    char    moreflags[4]; /* extraflags */
};

struct tu {
    short   key; /* key defining what this text unit is */
    short   numparms; /* number of parms that follow */
    short   parm1_len;
    char    parm1[98];
    /* parm2_len etc would theoretically follow, but we
    /* can't define them, because the length of 98 is probably
       not correct in the first place */
};

int
__fildef(char *fdddname, char *fnm, int mymode, int modeType)
{
    int         err     = 0;
    void        *tu_list[10];
    struct rb   rb;
    struct tu   tu[10];

    memset(&rb, 0x00, sizeof rb);
    rb.len          = 20;
    rb.verb         = 0x01; /* allocate */
    rb.flag1        = 0x40; /* S99NOCNV */
    rb.tu_list      = tu_list;

    if (fdddname[0]) {
        tu_list[0]      = &tu[0];
        tu[0].key       = 0x0001; /* ddname */
        tu[0].numparms  = 1;
        tu[0].parm1_len = strlen(fdddname);
        strcpy(tu[0].parm1, fdddname);
    }
    else {
        tu_list[0]      = &tu[0];
        tu[0].key       = 0x0055; /* DALRTDDN */
        tu[0].numparms  = 1;
        tu[0].parm1_len = 8;
        memset(tu[0].parm1, 0, 8);
    }

    tu_list[1]      = &tu[1];
    tu[1].key       = 0x0002; /* dsname */
    tu[1].numparms  = 1;
    tu[1].parm1_len = strlen(fnm);
    strcpy(tu[1].parm1, fnm);

    tu_list[2]      = &tu[2];
    tu[2].key       = 0x0004; /* disp */
    tu[2].numparms  = 1;
    tu[2].parm1_len = 1;
    tu[2].parm1[0]  = 0x08; /* SHR */

    tu_list[3]      = 0;
    tu_list[4]      = 0;
    tu_list[5]      = (void *)0x80000000;

    err = __svc99(&rb);

    /* if we had an error, then for datasets open for write,
       try allocating a new dataset (this will be the normal
       situation - it is abnormal to find the dataset already
       pre-allocated */
    if (err) {
        /* if open for write */
        if ( mymode ) {
            tu[2].parm1[0] = 0x04; /* NEW */
            /* Note that the operating system, e.g. PDOS,
               may override the RECFM, e.g. to make everything
               RECFM=U
            */

            /* if binary */
            if (modeType == 5) {
                /* F80, which is default */
                /* That seems like a strange default. Regardless,
                   we should be using RECFM=U, BLKSIZE=6233 for
                   output binary files */
            }
            else {
                /* V255 */
                tu_list[3]      = &tu[3];
                tu[3].key       = 0x49; /* RECFM */
                tu[3].numparms  = 1;
                tu[3].parm1_len = 1;
                tu[3].parm1[0]  = 0x40; /* V */

                tu_list[4]      = &tu[4];
                tu[4].key       = 0x42; /* LRECL */
                tu[4].numparms  = 1;
                tu[4].parm1_len = 2;
                tu[4].parm1[0]  = 0; /* LRECL = 255 */
                tu[4].parm1[1]  = 255;
            }
        }
        err = __svc99(&rb);
    }

    if (err) {
        if (rb.error_reason != 0) {
            errno = rb.error_reason;
        }
    }

quit:
    if (fdddname[0]==0 && err==0 && tu[0].key == 0x0055) {
        /* return DDNAME to caller */
        memcpy(fdddname, tu[0].parm1, 8);
        fdddname[8] = 0;
    }

    return err;
}
