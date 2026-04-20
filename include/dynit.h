/* DYNIT.H - Dynamic Allocation Interface (z/OS compatible) */
#ifndef DYNIT_H
#define DYNIT_H

#include <string.h>

typedef struct __DYNstruct __dyn_t;

struct __DYNstruct {
    char           *__ddname;       /* DDNAME                       */
    char           *__dsname;       /* DSNAME, dataset name         */
    char            __sysout;       /* system output class           */
    char           *__sysoutname;   /* program name for sysout       */
    char           *__member;       /* member of a PDS               */
    char            __status;       /* dataset status                */
    char            __normdisp;     /* dataset normal disposition    */
    char            __conddisp;     /* dataset conditional disp      */
    char           *__unit;         /* unit name                     */
    char           *__volser;       /* volume serial number          */
    short           __dsorg;        /* dataset organization          */
    char            __alcunit;      /* space allocation unit         */
    int             __primary;      /* primary space allocation      */
    int             __secondary;    /* secondary space allocation    */
    short           __recfm;        /* record format                 */
    unsigned short  __blksize;      /* block size                    */
    unsigned short  __lrecl;        /* record length                 */
    char           *__volrefds;     /* volume ref dsname             */
    char           *__dcbrefds;     /* DCB ref dsname                */
    char           *__dcbrefdd;     /* DCB ref ddname                */
    unsigned char   __misc_flags;   /* attribute flags               */
    char           *__password;     /* password                      */
    char          **__miscitems;    /* remaining text units           */
    short           __infocode;     /* SVC 99 info code              */
    short           __errcode;      /* SVC 99 error code             */
    int             __dirblk;       /* directory blocks              */
    int             __avgblk;       /* average block length          */
    unsigned char   __recorg;       /* VSAM organization             */
    short           __keylength;    /* VSAM key length               */
    short           __keyoffset;    /* VSAM key offset               */
    char           *__refdd;        /* copy attributes of ref dd     */
    char           *__like;         /* copy attributes of like dsn   */
    unsigned char   __dsntype;      /* PDS or PDSE type              */
    char            __retddn[9];    /* returned DDNAME               */
    char            __retdsn[44];   /* returned DSNAME               */
    void           *__rbx;          /* request block extension       */
    void           *__emsgparmlist;  /* error message parms          */
};

/* dyninit - zero-initialize dynamic allocation parameters */
#define dyninit(__dynp) \
    (memset((char *)(__dynp), '\0', sizeof(__dyn_t)), 0)

extern int dynalloc(__dyn_t *dyn_parms)                        asm("DYNALLOC");
extern int dynfree(__dyn_t *dyn_parms)                         asm("DYNFREE");

/* ALCUNIT */
#define __CYL               '\x01'
#define __TRK               '\x02'

/* STATUS */
#define __DISP_OLD          0x01
#define __DISP_MOD          0x02
#define __DISP_NEW          0x04
#define __DISP_SHR          0x08

/* NORMDISP, CONDDISP */
#define __DISP_UNCATLG      0x01
#define __DISP_CATLG        0x02
#define __DISP_DELETE       0x04
#define __DISP_KEEP         0x08

/* DSORG */
#define __DSORG_unknown     0x0000
#define __DSORG_VSAM        0x0008
#define __DSORG_GS          0x0080
#define __DSORG_PO          0x0200
#define __DSORG_POU         0x0300
#define __DSORG_DA          0x2000
#define __DSORG_DAU         0x2100
#define __DSORG_PS          0x4000
#define __DSORG_PSU         0x4100
#define __DSORG_IS          0x8000
#define __DSORG_ISU         0x8100

/* RECFM */
#define _M_                 0x02
#define _A_                 0x04
#define _S_                 0x08
#define _B_                 0x10
#define _D_                 0x20
#define _V_                 0x40
#define _F_                 0x80
#define _U_                 0xc0
#define _FB_                0x90
#define _VB_                0x50
#define _FBS_               0x98
#define _VBS_               0x58
#define _VS_                0x48

/* MISCFLAGS */
#define __CLOSE             0x01
#define __RELEASE           0x02
#define __PERM              0x04
#define __CONTIG            0x08
#define __ROUND             0x10
#define __TERM              0x20
#define __DUMMY_DSN         0x40
#define __HOLDQ             0x80

/* VSAM TYPE */
#define __KS                0x80
#define __ES                0x40
#define __RR                0x20
#define __LS                0x10

/* PDS TYPE */
#define __DSNT_PDS          0x40

#endif /* DYNIT_H */
