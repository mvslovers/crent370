#ifndef HASPJCT_H
#define HASPJCT_H

#include "hasptgm.h"

typedef struct __jct        __JCT;      /* JES Job Control Table            */

struct __jct {
/* JCTDSECT DSECT                     JOB CONTROL TABLE DSECT
         USING JCTDSECT,JCT        ESTABLISH JCT ADDRESSABILITY
         DS    (BUFSTART-BUFDSECT)X     BUFFER CONTROL INFORMATION
JCTSTART EQU   *                   START OF DATA WRITTEN TO SPOOL
*/
    unsigned char   JCTID[4];   /* 00 CL4'JCT'            JCT IDENTIFIER    */
    unsigned short  JCTLENG;    /* 04 LENGTH OF JCT INCLUDING PREFIX        */
    unsigned char   JCTFLAG1;   /* 06 FLAGS 1 ---                           */
#define JCT1CKPT    0x80        /* ... REWRITE THIS JCT                     */
#define JCTBURST    0x40        /* ... JOB OUTPUT BURST OPTION              */

    unsigned char   JCTJTFLG;   /* 07 JOB TERM FLAGS                        */
#define JCTJTJF     0x80        /* ... JOB FAILED                           */
#define JCTJTCF     0x40        /* ... JOB FAILED DUE TO CC                 */
#define JCTJTABD    0x20        /* ... JCTABEND WAS ON                      */

    unsigned int    JCTJBKEY;   /* 08 JOB IDENTIFIER KEY                    */
    unsigned int    JCTSPIOT;   /* 0C TRACK ADDRESS OF 1ST SPIN IOT         */
    unsigned int    JCTIOT;     /* 10 TRACK ADDRESS OF 1ST REGULAR IOT      */
    unsigned int    JCTHQT;     /* 14 TRACK ADDRESS OF 1ST HQT              */
    unsigned int    JCTOCTTR;   /* 18 TRACK ADDRESS OF OCR TABLE            */
    unsigned int    JCTJQE;     /* 1C OFFSET OF HASP JOB QUEUE ENTRY        */
    unsigned short  JCTPDDBK;   /* 20 PERIPHERAL DATA SET KEY               */
    unsigned short  JCTPDDBO;   /* 22 DATA SET KEY FOR 1ST OUTPUT PDDB      */
    int             JCTCNVRC;   /* 24 RETURN CODE FROM JCL CONVERTER        */
#define JCTCOK      0           /* ... JCL CONVERTED WITHOUT ERROR          */
#define JCTCJCL     4           /* ... JCL ERROR DETECTED BY CONVERTER      */
#define JCTCIO      8           /* ... I/O ERROR DETECTED BY CONVERTER      */
#define JCTCDUPL    JCTCJCL     /* ... DUPLICATE LOGON EXECUTING            */
#define JCTCABND    36          /* ... UNRECOVERABLE ERROR IN CONVERSION    */

    unsigned int    JCTJLOGC;   /* 28 RESUME TRACK FOR LOG DATA SET         */
    unsigned int    JCTMSGSC;   /* 2C RESUME TRACK FOR MSG DATA SET         */
    unsigned char   __1[2];     /* 30 RESERVED                              */
    unsigned char   JCTPRTY[2]; /* 32 /*PRIORITY OR JOB CARD 'PRTY='        */
    unsigned short  JCTJSSTP;   /* 34 JOB SELECT RESTART STEP (SSRQSTEP)    */
    unsigned short  JCTHQRCT;   /* 36 HOLD QUEUE RECORD COUNT               */
    unsigned char   JCTJSFLG;   /* 38 JOB SELECT FLAGS (SSRQFLG1)           */
    unsigned char   JCTSMFLG;   /* 39 SMF FLAGS                             */
#define JCTSMFL0    0x80        /* ... RESERVED                             */
#define JCTSMFL1    0x40        /* ... RESERVED                             */
#define JCTNOUSO    0x20        /* ... DO NOT TAKE IEFUSO SMF EXIT          */
#define JCTSMFL3    0x10        /* ... RESERVED                             */
#define JCTSMFL4    0x08        /* ... RESERVED                             */
#define JCTNOTY6    0x04        /* ... DO NOT PRODUCE TYPE 6 SMF RECORD     */
#define JCTNOUJP    0x02        /* ... DO NOT TAKE IEFUJP SMF EXIT          */
#define JCTNOT26    0x01        /* ... DO NOT PRODUCE TYPE 26 SMF RECORD    */

    /* KEEP THE FIELDS JCTJOBFL AND JCTJBOPT TOGETHER FOR SMF               */
    unsigned char   JCTJOBFL;   /* 3A HASP JOB FLAGS                        */
#define JCTBATCH    0x80        /* ... BACKGROUND BATCH JOB                 */
#define JCTTSUJB    0x40        /* ... FOREGROUND TIME SHARING USER         */
#define JCTSTCJB    0x20        /* ... SYSTEM TASK                          */
#define JCTNOJNL    0x10        /* ... NO JOURNAL OPTION                    */
#define JCTNOUPT    0x08        /* ... NO OUTPUT OPTION                     */
#define JCTTSCAN    0x04        /* ... TYPRUN=SCAN WAS SPECIFIED            */
#define JCTTCOPY    0x02        /* ... TYPRUN=COPY WAS SPECIFIED            */
#define JCTRSTRT    0x01        /* ... ALLOW WARM START RE-QUEUE TO XEQ     */
#define JCTPURGE    JCTJOBFL    /* 3A START OF SMF PURGE RECORD             */

    unsigned char   JCTJBOPT;   /* 3B HASP JOB OPTIONS                      */
#define JCTPRICD    0x80        /* ... /*PRIORITY CARD OR
                                       JOB CARD 'PRTY=' PRESENT             */
#define JCTSETUP    0x40        /* ... /*SETUP CARD(S) PRESENT              */
#define JCTTHOLD    0x20        /* ... TYPERUN=HOLD WAS SPECIFIED           */
#define JCTNOLOG    0x10        /* ... NO JOB LOG OPTION                    */
#define JCTXBACH    0x08        /* ... EXECUTION BATCHING JOB               */
#define JCTINRDR    0x04        /* ... JOB WAS ENTERED ON INTERNAL READER   */
#define JCTRERUN    0x02        /* ... JOB WAS RE-RUN                       */
#define JCTQHELD    0x01        /* ... RESERVED FOR CAT AND SMF RECORDS     */

    /* KEEP NEXT 108 BYTES INTACT FOR SMF - JCTJOBID THROUGH JCTNUPAS       */
    unsigned char   JCTJOBID[8];/* 3C HASP ASSIGNED JOB IDENTIFICATION      */
    unsigned char   JCTJNAME[8];/* 44 JOB NAME FROM JOB CARD                */
    unsigned char   JCTPNAME[20];/* 4C PROGRAMMER'S NAME FROM JOB CARD      */
    unsigned char   JCTMCLAS;   /* 60 MSGCLASS FROM JOB CARD                */
    unsigned char   JCTJCLAS;   /* 61 JOB CLASS FROM JOB CARD               */
    unsigned char   JCTIPRIO;   /* 62 HASP INITIAL JOB SELECTION PRIORITY   */
    unsigned char   JCTPRIO;    /* 63 HASP EXECUTION SELECTION PRIORITY     */
    unsigned char   JCTIOPRI;   /* 64 HASP INITIAL OUTPUT SELECTION PRIO    */
    unsigned char   JCTOPRIO;   /* 65 HASP OUTPUT SELECTION PRIORITY        */
    unsigned char   JCTROUTE[2];/* 66 INPUT ROUTE CODE                      */
    unsigned char   JCTINDEV[8];/* 68 HASP INPUT DEVICE NAME                */
    unsigned char   JCTACCTN[4];/* 70 JOB ACCOUNTING NUMBER FROM JOB CARD   */
    unsigned char   JCTROOMN[4];/* 74 PROGRAMMER'S ROOM NUMBER              */
    unsigned int    JCTETIME;   /* 78 ESTIMATED EXECUTION TIME              */
    unsigned int    JCTESTLN;   /* 7C ESTIMATED OUTPUT LINES                */
    unsigned int    JCTESTPU;   /* 80 ESTIMATED PUNCHED OUTPUT              */
    unsigned char   JCTFORMS[4];/* 84 JOB OUTPUT FORMS                      */
    unsigned char   __2;        /* 88 RESERVED                              */
    unsigned char   JCTCPYCT;   /* 89 JOB PRINT COPY COUNT                  */
    unsigned char   __3;        /* 8A RESERVED                              */
    unsigned char   JCTLINCT;   /* 8B LINES PER PAGE                        */
    unsigned char   JCTPROUT[2];/* 8C JOB PRINT ROUTE CODE                  */
    unsigned char   JCTPUOUT[2];/* 8E JOB PUNCH ROUTE CODE                  */
    unsigned char   JCTPROCN[8];/* 90 PROCEDURE DDNAME                      */
    unsigned char   JCTPASS[8]; /* 98 CURRENT PASSWORD                      */
    unsigned char   JCTNUPAS[8];/* A0 NEW PASSWORD                          */
    /* KEEP NEXT 48 BYTES INTACT FOR SMF - JCTCNVON THROUGH JCTODTOF        */
    unsigned int    JCTCNVON;   /* A8 TIME ON JCL CONVERSION PROCESSOR      */
    unsigned int    JCTCDTON;   /* AC DATE ON JCL CONVERSION PROCESSOR      */
    unsigned int    JCTCNVOF;   /* B0 TIME OFF JCL CONVERSION PROCESSOR     */
    unsigned int    JCTCDTOF;   /* B4 DATE OFF JCL CONVERSION PROCESSOR     */
    unsigned int    JCTXEQON;   /* B8 TIME ON EXECUTION PROCESSOR           */
    unsigned int    JCTXDTON;   /* BC DATE ON EXECUTION PROCESSOR           */
    unsigned int    JCTXEQOF;   /* C0 TIME OFF EXECUTION PROCESSOR          */
    unsigned int    JCTXDTOF;   /* C4 DATE OFF EXECUTION PROCESSOR          */
    unsigned int    JCTOUTON;   /* C8 TIME ON OUTPUT PROCESSOR              */
    unsigned int    JCTODTON;   /* CC DATE ON OUTPUT PROCESSOR              */
    unsigned int    JCTOUTOF;   /* D0 TIME OFF OUTPUT PROCESSOR             */
    unsigned int    JCTODTOF;   /* D4 DATE OFF OUTPUT PROCESSOR             */
    /* KEEP NEXT 28 BYTES INTACT FOR SMF - JCTCARDS THROUGH JCTOTSID        */
    unsigned int    JCTCARDS;   /* D8 TOTAL NUMBER OF INPUT CARDS           */
    unsigned int    JCTLINES;   /* DC GENERATED OUTPUT LINES                */
    unsigned int    JCTPUNCH;   /* E0 GENERATED PUNCHED OUTPUT              */
    unsigned char   JCTRDSID[4];/* E4 INPUT PROCESSOR SYSTEM ID             */
    unsigned char   JCTCVSID[4];/* E8 CONVERSION PROCESSOR SYSTEM ID        */
    unsigned char   JCTEXSID[4];/* EC EXECUTION PROCESSOR SYSTEM ID         */
    unsigned char   JCTOTSID[4];/* F0 OUTPUT PROCESSOR SYSTEM ID            */
    unsigned int    JCTESOUT;   /* F4 ESTIMATED OUTPUT (LINES+CARDS)        */
    unsigned int    JCTXOUT;    /* F8 GENERATED OUTPUT RECORDS              */
    unsigned char   JCTTSUID[7];/* FC TIME SHARING USERID FOR NOTIFY        */
    unsigned char   JCTTSUAF;   /* 103 INPUT QUESYSAF FOR NOTIFY            */
    unsigned char   JCTPSN1[8]; /* 104 STEP NAME FROM EXEC STEP             */
    unsigned char   JCTPSN2[8]; /* 10C STEP NAME OF CALLING STEP            */
    unsigned char   JCTWORK[144];/* 114 144-BYTE WORK AREA                  */
    unsigned char   JCTJMRST[0];/* 1A4 START OF JMR AREA                    */
    /* KEEP THE FIELDS JCTJMRJN, JCTRDRON, AND JCTRDTON TOGETHER FOR SMF    */
    unsigned char   JCTJMRJN[8];/* 1A4 JMR JOB NAME                         */
    unsigned int    JCTRDRON;   /* 1AC TIME ON INPUT PROCESSOR              */
    unsigned int    JCTRDTON;   /* 1B0 DATE ON INPUT PROCESSOR              */
    unsigned char   JCTCPUID[4];/* 1B4 JMR CPU IDENTIFICATION               */
    unsigned char   JCTUSEID[8];/* 1B8 JMR USER IDENTIFICATION              */
    unsigned char   JCTSTEP;    /* 1C0 CURRENT STEP NUMBER                  */
    unsigned char   JCTINDC;    /* 1C1 JMR SMF OPTIONS                      */
    unsigned char   JCTJTCC;    /* 1C2 CONDITION CODE                       */
    unsigned char   JCTCLASS;   /* 1C3 JOB CLASS                            */
    unsigned int    JCTUCOM;    /* 1C4 JMR USER COMMUNICATION AREA          */
    unsigned int    JCTUJVP;    /* 1C8 JMR ADDRESS OF USER EXIT ROUTINE     */
    /* KEEP THE FIELDS JCTRDROF AND JCTRDTOF TOGETHER FOR SMF               */
    unsigned int    JCTRDROF;   /* 1CC TIME OFF INPUT PROCESSOR             */
    unsigned int    JCTRDTOF;   /* 1D0 DATE OFF INPUT PROCESSOR             */
    unsigned int    JCTJOBIN;   /* 1D4 JMR JOB SYSIN COUNT                  */
    unsigned char   JCTRDR[2];  /* 1D8 READER DEVICE TYPE AND CLASS         */
    unsigned char   JCTJMOPT;   /* 1DA JMR SMF OPTIONS                      */
#define JCTJMRUX    0x20        /* ... IF ON, TAKE USER EXITS FOR SMF       */

    unsigned char   __4;        /* 1DB RESERVED                             */
    unsigned char   JCTJMRND[0];/* 1DC  END OF JMR                          */
/* JCTJMR   EQU   JCTJMRST,*-JCTJMRST REFERENCE FOR ENTIRE JMR AREA         */
    unsigned char   JCTEND[0];  /* 1DC END OF JOB CONTROL TABLE             */
};

#endif
