/* IEFTXTFT.H Internal Text */
#ifndef IEFTXTFT_H
#define IEFTXTFT_H

typedef struct __txtpre     __TXTPRE;   /* Common to all text string types  */
typedef struct __jobstr     __JOBSTR;   /* for JOBSTR statement type        */
typedef struct __execstr    __EXECSTR;  /* for EXECSTR or PROCSTR statement type */
typedef struct __ddstr      __DDSTR;    /* for DDSTR statement type         */

struct __txtpre {
/*
 *  THE FOLLOWING FIELDS ARE COMMON TO ALL TEXT STRING TYPES.
 */
    unsigned short  STRLTH;     /* 00 LENGTH OF TEXT STRING.                */
    unsigned char   STRINDCS;   /* 02 STATEMENT TYPE AND MISCELLANEOUS INDICATORS */
#define JOBSTR      0x01        /* ... JOB STATEMENT TEXT STRING            */
#define EXECSTR     0x02        /* ... EXEC STATEMENT TEXT STRING           */
#define DDSTR       0x04        /* ... DD STATEMENT TEXT STRING             */
#define PROCSTR     0x08        /* ... PROC STATEMENT TEXT STRING           */
#define LASTSTMT    0x10        /* ... LAST STMT FOR THIS STEP.             */
};

/*  FORMAT FOR JOB TEXT STRINGS */
/*******************************************************************/
/*              2*        1*        1*        1*        1*        1*/
/*     STRLTH    *STRINDCS *STRJINDC *STRJIND2 *STRJLABD *STRJKEY  */
/*              2*        1*        1*        1*        1*        1*/
/*******************************************************************/
struct __jobstr {
    unsigned short  STRLTH;     /* 00 LENGTH OF TEXT STRING.                */
    unsigned char   STRINDCS;   /* 02 STATEMENT TYPE AND MISCELLANEOUS INDICATORS */
    unsigned char   STRJINDC;   /* 03 JOB INDICATORS                        */
#define JTXACCTN    0x01        /* ... ACCT NO. REQUIRED.                   */
#define JTXPROGN    0x02        /* ... PROGRAMMER NAME REQUIRED.            */
#define JTXJOBFL    0x04        /* ... JOB HAS BEEN FAILED.                 */
#define JTXSYSCK    0x08        /* ... JOB HAS SYSCHK DD.                   */
#define JTXCPSTF    0x10        /* ... C/R - FLUSH TO RESTART STEPNAME.     */
#define JTXMHEDR    0x20        /* ... MESSAGE HEADER HAS BEEN WRITTEN.     */
#define JTXREGDF    0x40        /* ... REGION VALUE IS A DEFAULT.           */

    unsigned char   STRJIND2;   /* 04 BYTE 2 OF JOB TEXT INDICATORS.        */
    unsigned char   STRJLABD;   /* 05 BYPASS LABEL PROCESSING DEFAULT.      */
/* ENTIRE BYTE IS USED, AS IEFVDA OR'S BYTE DIRECTLY INTO JFCB. */
#define JTXLABNL    0x01        /* ... DEFAULT IS NO LABEL.                 */
#define JTXLABLP    0x10        /* ... DEFAULT IS BYPASS LABEL PROCESSING.  */
    unsigned char   STRJKEY[0]; /* 06 VERB KEY FOR JOB TEXT STRING          */
};                              /* END OF JOB TEXT STRING PREFIX            */
#define STRJPFXL sizeof(__TXTJOB) /* LENGTH OF JOB TEXT STRING PREFIX       */

/*  FORMAT FOR EXEC/PROC TEXT STRINGS */
/***************************************************/
/*                  2*         1*       1*        1*/
/*     STRLTH        *STRINDCS *STREINDC *STREKEY  */
/*                   *         *         *         */
/***************************************************/
struct __execstr {
    unsigned short  STRLTH;     /* 00 LENGTH OF TEXT STRING.                */
    unsigned char   STRINDCS;   /* 02 STATEMENT TYPE AND MISCELLANEOUS INDICATORS */
    unsigned char   STREINDC;   /* 03 EXEC INDICATORS.                      */
#define ETXCPFLG    0x01        /* ... CHECKPT/RESTART EXEC STMT.           */
#define ETXSTPCT    0x02        /* ... STEP HAS A STEPCAT DD.               */
#define ETXSTPLB    0x04        /* ... STEP HAS A STEPLIB DD.               */
#define ETXPROC     0x08        /* ... STATEMENT IS FROM A PROC.            */
#define ETXNODD     0x10        /* ... STEP HAS NO DD STATEMENTS.           */
#define ETXPRCV     0x20        /* ... STATEMENT INVOKES A PROCEDURE.       */
/*  END OF EXEC/PROC TEXT STRING PREFIX */
    unsigned char   STREKEY[0]; /* 04 VERB KEY FOR EXEC/PROC TEXT STRING    */
};
#define STREPFXL sizeof(__EXEC) /* LENGTH OF EXEC/PROC TEXT STRING PFX      */


/*  FORMAT FOR DD TEXT STRINGS */
/***************************************************/
/*                  2*         1*       1*        1*/
/*     STRLTH        *STRINDCS *STRDINDC *STRDKEY  */
/*                   *         *         *         */
/***************************************************/
struct __ddstr {
    unsigned short  STRLTH;     /* 00 LENGTH OF TEXT STRING.                */
    unsigned char   STRINDCS;   /* 02 STATEMENT TYPE AND MISCELLANEOUS INDICATORS */
    unsigned char   STRDINDC;   /* 03 DD TEXT STRING INDICATORS.            */
#define DTXDUMMY    0x01        /* ... DUMMY SPECIFIED ON STATEMENT.        */
#define DTXDDNM     0x02        /* ... DDNAME= SPECIFIED ON STATEMENT.      */
#define DTXDSNLT    0x04        /* ... DSNAME SPECIFIED AS A LITERAL.       */
#define DTXDYNAM    0x08        /* ... DYNAM SPECIFIED ON STATEMENT.        */
#define DTXSYSIN    0x10        /* ... TEXT IS FOR A SPOOLED DATA SET.      */
#define DTXSYOUT    0x20        /* ... TEXT IS FOR A SYSOUT DATA SET        */
#define DTXSUBSK    0x40        /* ... SUBSYS= SPECIFIED ON STMT            */
#define DTXPROC     0x80        /* ... STATEMENT IS FROM A PROC.            */
/*  END OF DD TEXT STRING PREFIX */
    unsigned char   STRDKEY[0]; /* 04 VERB KEY FOR DD TEXT STRING           */
};
#define STRDPFXL sizeof(__DDSTR) /* LENGTH OF DD TEXT STRING PREFIX         */


#endif
