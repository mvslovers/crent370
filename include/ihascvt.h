
#ifndef IHASCVT_H
#define IHASCVT_H

typedef struct scvtsect     SCVTSECT;   /* cvt->cvtabend points here    */
typedef struct scvtsect     SCVT;       /* cvt->cvtabend points here    */
typedef struct svcentry     SVCENTRY;   /* a SVCTABLE entry             */
typedef struct svctable     SVCTABLE;   /* scvt->scvtsvct points here   */

/*                                                                  */
/*      OS/VS2 RELEASE 3, 05/22/74, LEVEL=1                         */
/*                                                                  */
/*  METHOD OF ACCESS                                                */
/*      BAL  - DSECT IS PRODUCED UNLESS DSECT=NO IS SPECIFIED.      */
/*             USING ON SCVTSECT GIVES ADDRESSABILITY FOR ALL       */
/*             SYMBOLS.                                             */
/*      PL/S - DCL SCVTSPTR PTR                                     */
/*                                                                  */
/*  F.E.'S                                                          */
/*      MICROFICHE LISTING - IHASCVT                                */
/*                                                                  */
/*  DEVELOPERS                                                      */
/*      BAL LISTING  - SPECIFY LIST=YES ON MACRO CALL               */
/*                                                                  */
/*      FOR INTEGRATION, A LISTING MUST NOT BE REQUESTED UNLESS     */
/*      YOUR MODULE CREATES THE CSECT.                              */

struct scvtsect {
    void            *scvtpgtm;      /* 00 ADDR OF EOT TIMER PURGE ROUTINE       */
    void            *scvtpgwr;      /* 04 ADDRESS OF WTO/WTOR RESOURCE          */
                                    /*    MANAGER.  INITIALLY CONTAINS ADDRESS  */
                                    /*    OF BR 14.  CHANGED TO IEECVPRG        */
                                    /*    (MODULE IEAVMED2) BY COMMUNICATIONS   */
                                    /*    TASK INITIALIZATION (IEAVVINT).       */
    void            *scvtspet;      /* 08 ADDR OF EOT SUBPOOL RELEASE           */
    unsigned char   scvtbr14[2];    /* 0C BR 14 RETURN TO CALLER                */
    unsigned char   reserved1[2];   /* 0E RESERVED                              */
    void            *scvteras;      /* 10 ** SCVTERAS FIELD UNUSED IN OS/VS2 ** */
    void            *scvtqcbo;      /* 14 ** SCVTQCBO FIELD UNUSED IN OS/VS2 ** */
    void            *scvtpgeq;      /* 18 ** SCVTPGEQ FIELD UNUSED IN OS/VS2 ** */
    void            *scvtrmbr;      /* 1C ADDR OF REGMAIN BRANCH ENTRY          */
    void            *scvtpgio;      /* 20 ** SCVTPGIO FIELD UNUSED IN OS/VS2 ** */
    void            *scvtrace;      /* 24 ADDR OF POINTER TO TRACE ROUTINE      */
    void            *scvttasw;      /* 28 ** SCVTTASW FIELD UNUSED IN OS/VS2 ** */
    void            *scvtcdcl;      /* 2C ADDR OF CDCONTROL IN LINK             */
    void            *scvtlfrm;      /* 30 LIST FORMAT FREEMAIN BRANCH ENT PT    */
    void            *scvtpabl;      /* 34 ** SCVTPABL FIELD UNUSED IN OS/VS2 ** */
    void            *scvtdqtc;      /* 38 ** SCVTDQTC FIELD UNUSED IN OS/VS2 ** */
    void            *scvthskp;      /* 3C ADDR OF CDHKEEP IN EOT                */
    void            *scvtrptr;      /* 40 ADDR OF TRACE TABLE POINTERS          */
    void            *scvtgmbr;      /* 44 LIST FORMAT GETMAIN BRANCH ENTRY PT   */
    void            *scvtauct;      /* 48 ** SCVTAUCT FIELD UNUSED IN VS2 **    */
    void            *scvtroct;      /* 4C ** SCVTROCT FIELD UNUSED IN VS2 **    */
    void            *scvtroq;       /* 50 ** SCVTROQ  FIELD UNUSED IN VS2 **    */
    void            *scvtrirb;      /* 54 ** SCVTRIRB FIELD UNUSED IN VS2 **    */
    void            *scvtrtcb;      /* 58 ** SCVTRTCB FIELD UNUSED IN VS2 **    */
    void            *scvtcomm;      /* 5C ADDR OF COMM TASK ROUTINE             */
    void            *scvtablk;      /* 60 ** SCVTABLK FIELD UNUSED IN VS2 **    */
    void            *scvtnfnd;      /* 64 ** SCVTNFND FIELD UNUSED IN VS2 **    */
    void            *scvtrmtc;      /* 68 ** SCVTRMTC FIELD UNUSED IN OS/VS2 ** */
    void            *scvtmssq;      /* 6C ** SCVTMSSQ FIELD UNUSED IN OS/VS2 ** */
    void            *scvtctcb;      /* 70 ADDR OF COMM TASK TCB                 */
    void            *scvtetcb;      /* 74 ** SCVTETCB FIELD UNUSED IN OS/VS2 ** */
    void            *scvtrxlq;      /* 78 ADDR OF RECOVERY EXTENT LIST          */
    void            *scvtrqnd;      /* 7C ** SCVTRQND FIELD UNUSED IN OS/VS2 ** */
    void            *scvttar;       /* 80 ** SCVTTAR  FIELD UNUSED IN VS2 **    */
    void            *scvtsvct;      /* 84 ORIGIN OF SVC TABLE                   */
    void            *scvtstxp;      /* 88 ** SCVTSTXP FIELD UNUSED IN OS/VS2 ** */
    void            *scvttqe;       /* 8C ADDR OF TSO SUBSYSTEM'S TQE           */
    void            *scvtrmsv;      /* 90 ** SCVTRMSV FIELD UNUSED IN OS/VS2 ** */
    void            *scvtstat;      /* 94 ADDR OF SVC STATUS ROUTINE            */
    void            *scvtqcbr;      /* 98 BRANCH ENTRY POINT TO GETMAIN/FREEMAIN*/
                                    /*    QUICKCELL ROUTINE                     */
    void            *scvtabbr;      /* 9C ** SCVTABBR FIELD UNUSED IN OS/VS2 ** */
    void            *scvtapio;      /* A0 ** SCVTAPIO FIELD UNUSED IN OS/VS2 ** */
    void            *scvtptrm;      /* A4 ADDRESS OF REAL STORAGE MANAGER       */
                                    /*    (RSM) TERMINATION RESOURCE MANAGER    */
                                    /*    ROUTINE THAT QUIESCES PAGING I/O      */
                                    /*    AND PGFIX REQUESTS                    */
    void            *scvthook;      /* A8 ** SCVTHOOK FIELD UNUSED IN OS/VS2 ** */
    void            *scvtpiqe;      /* AC ADDR OF RESIDENT SUBROUTINE IN EOT    */
                                    /*    TO REMOVE IQE'S FROM ASYNCHRONOUS     */
                                    /*    EXIT QUEUE                            */
    void            *scvttmbr;      /* B0 ** SCVTTMBR FIELD UNUSED IN OS/VS2 ** */
    void            *scvtfomg;      /* B4 ** SCVTFOMG FIELD UNUSED IN OS/VS2 ** */
};                                  /* B8 (184 bytes)                           */

struct svcentry {
    void            *svcepa;        /* 00 SVC entry point address               */
    unsigned char   svctype : 3;    /* 04 svc type code                         */
#define SVCTYPE1    0               /* ... svc type 1                           */
#define SVCTYPE2    4               /* ... svc type 2                           */
#define SVCTYPE3    6               /* ... svc type 3 or 4                      */
#define SVCTYPE4    6               /* ... svc type 3 or 4                      */
#define SVCTYPE6    1               /* ... svc type 6                           */
    unsigned char   unused : 1;     /* 04 unused bit                            */
    unsigned char   svcapf : 1;     /* 04 1=APF YES                             */
    unsigned char   svcesr : 1;     /* 04 1=ESR YES                             */
    unsigned char   svcnonpreempt:1;/* 04 1=svc is non-preemptive               */
    unsigned char   svcassist : 1;  /* 04 1=svc can be assisted                 */
    unsigned char   svcattribute;   /* 05 attribute (not used is OS/VS2)        */
    unsigned char   svclock;        /* 06 svc locks                             */
#define SVCLOCK_LOCAL   0x80        /* ... LOCAL lock.                          */
#define SVCLOCK_CMS     0x40        /* ... CMS lock.                            */
#define SVCLOCK_SRM     0x20        /* ... SRM lock.                            */
#define SVCLOCK_SALLOC  0x10        /* ... SALLOC lock.                         */
#define SVCLOCK_DISP    0x08        /* ... DISP lock.                           */
    unsigned char   unused2;        /* 07 unused                                */
} __attribute__((packed));          /* 08 (8 bytes)                             */

struct svctable {
    SVCENTRY        svcentry[256];  /* 00 array of SVCENTRY, 0-255              */
};                                  /* 800 (2048 bytes)                         */

#endif /* IHASCVT_H */
