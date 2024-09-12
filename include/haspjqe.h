#ifndef HASPJQE_H
#define HASPJQE_H

typedef struct __jqe    __JQE;

/* JES Job Queue Element */
struct __jqe {
    unsigned char   JQEPRIO;    /* 00 JOB PRIORITY                          */
    unsigned char   JQETYPE;    /* 01 LOGICAL QUEUE TYPE                    */
#define QUECLASS    0x7F        /* ... CLASS OF JOB QUEUED FOR EXECUTION    */
#define _DUMMY      0x80        /* ... RESERVED QUEUE                       */
#define _XEQ        0x40        /* ... OS EXECUTION QUEUE                   */
#define _INPUT      0x20        /* ... INPUT QUEUE                          */
#define _XMIT       0x10        /* ... TRANSMISSION QUEUE                   */
#define _SETUP      0x08        /* ... SETUP QUEUE                          */
#define _RECEIVE    0x04        /* ... SYSOUT RECEIVER QUEUE                */
#define _OUTPUT     0x02        /* ... OUTPUT QUEUE                         */
#define _HARDCPY    0x01        /* ... OUTPUT IN-PROGRESS QUEUE             */
#define _PURGE      0x00        /* ... PURGE QUEUE                          */
#define _FREE       0xFF        /* ... FREE QUEUE                           */

    unsigned short  JQEJOBNO;   /* 02 HASP JOB NUMBER                       */
    unsigned char   JQEFLAGS;   /* 04 JOB QUEUE FLAGS                       */
#define QUEHOLDA    0x80        /* ... HOLD ALL JOBS                        */
#define QUEHOLD1    0x40        /* ... HOLD SINGLE JOB                      */
#define QUEHOLD2    0x20        /* ... HOLD FOR DUPLICATE JOB NAME          */
#define QUEPURGE    0x10        /* ... JOB IS TO BE PURGED                  */
#define QUEOPCAN    0x08        /* ... OPERATOR ISSUED $C OR $P JOB         */
#define QUEBUSY     0x07        /* ... JQE BUSY SYSTEM ID                   */

    unsigned char   JQEFLAG2;   /* 05 MORE JOB QUEUE FLAGS                  */
#define QUEINIT     0x80        /* ... JOB IS INITIATOR OR SYSTEM LOG       */
#define QUEINDAF    0x80        /* ... JOB HAS INDEPENDENT MODE AFFINITY    */
#define QUESYSAF    0x7F        /* ... SYSTEM AFFINITY OF JOB               */

    unsigned short  JQECHAIN;   /* 06 OFFSET/4 OF NEXT JOB QUE ELEMENT      */
    unsigned int    JQETRAK;    /* 08 TRACK ADDRESS OF JOB CONTROL TABLE    */
    unsigned short  JQEDEVID;   /* 0C DEVICE IDENTITY (SEE DCTDEVID)        */
#define JQEPRTRT    JQEDEVID    /* 0C PRINT ROUTE                           */
    unsigned short  JQEPUNRT;   /* 0E PUNCH ROUTE                           */
    unsigned short  JQEJOE;     /* 10 OFFSET/4 OF 1ST WORK-JOE              */
    unsigned short  JQEHLDCT;   /* 12 HELD DATA SET COUNT (BITS 0-11)
                                      HOLD QUEUE LOCK (BITS 12-15)          */
    unsigned char   JQEJNAME[8];/* 14 JOB NAME FROM JOB CARD                */
};
#define JQELNGTH sizeof(__JQE)  /* 1C  LENGTH OF JOB QUEUE ENTRY            */

#endif
