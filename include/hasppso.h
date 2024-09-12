#ifndef HASPPSO_H
#define HASPPSO_H
#include "hasppddb.h"
#include "iefssso.h"
/**********************************************************************
*                                                                     *
*    THE PROCESS SYSOUT WORK AREA (PSO) DSECT DESCRIBES A CONTROL     *
*    BLOCK RESIDING IN THE COMMON STORAGE AREA (CSA) WHICH            *
*    CONTAINS INFORMATION REQUIRED FOR THE PROCESSING OF THE          *
*    FIRST AND SUBSEQUENT PROCESS SYSOUT REQUESTS FOR EACH            *
*    REQUEST SERIES.  THE AREA FROM PSOUFLG THROUGH PSOWTRC           *
*    PROVIDES A ONE-FOR-ONE MAPPING OF THOSE FIELDS IN THE SSOB       *
*    EXTENSION FOR PROCESS SYSOUT FOLLOWING THE EXTENSION LENGTH      *
*    FIELD, SSSOLEN.                                                  *
*                                                                     *
*    THE PSO IS OBTAINED BY THE ROUTINE IN HASPSSSM, WHICH FIRST      *
*    HANDLES PROCESS SYSOUT REQUESTS, WHEN IT ENCOUNTERS THE          *
*    INITIAL REQUEST OF A SERIES.  THE PSO IS FREED BY THIS           *
*    ROUTINE WHENEVER THE JES2 PROCESS SYSOUT PROCESSOR POSTS IT      *
*    WITH THE PSOFDONE BIT SET IN PSOFLG2.  THIS ROUTINE WILL         *
*    ALSO FREE THE PSO IF THE RETURN CODE STORED BY THE JES2          *
*    PROCESS SYSOUT PROCESSOR IN PSORETN IS NON-ZERO, UNLESS THE      *
*    HIGH-ORDER BIT IS SET IN THE SJB FIELD SJBPSOP.                  *
*                                                                     *
**********************************************************************/

/*
         L     R2,PSATOLD-PSA          OUR TCB ADDRESS                  00281000
         L     R2,TCBJSCB-TCB(,R2)     JSCB ADDRESS                     00282000
         USING IEZJSCB,R2                                               00283000
         L     R2,JSCBACT              ACTIVE JSCB ADDRESS              00284000
         L     R2,JSCBSSIB             SSIB ADDRESS                     00285000
         L     R2,SSIBSUSE-SSIB(,R2)   SJB ADDRESS                      00286000
         L     R2,SJBPSOP-SJB(,R2)     PSO ADDRESS                      00287000
*/
typedef struct __pso    __PSO;

struct __pso {                      /* PSO PARAMETER LIST DSECT                 */
    union {
        __PSO       *PSONEXT;       /* 00 ADDR OF PSO FOR NEXT $O REQUEST       */
        void        *PSOCCE;        /* 00 ADDRESS OF CCE                        */
    };
    unsigned        PSOCRDT;        /* 04 ELLIGIBILITY CUT-OFF DATE             */
    __PDDB          PSOPDDB;        /* 08 DATA SET PDDB  0x68 (104 bytes)       */
    unsigned char   __0[2];         /* 70 align to middle of next word          */
    unsigned char   PSOUFLG;        /* 72 GROUP REQUEST OPTIONS BYTE            */
#define PSOFSETC    SSSOSETC        /* ... ALTER SYSOUT CLASS TO PSOCLS         */
#define PSOFDELC    SSSODELC        /* ... DELETE SELECTED DATA SETS            */
#define PSOFROUT    SSSOROUT        /* ... ROUTE SELECTED DATA SETS TO PSODEST  */
#define PSOFHOLD    SSSOHOLD        /* ... HOLD SELECTED DATA SETS              */
#define PSOFRLSE    SSSORLSE        /* ... RELEASE SELECTED DATA SETS           */

    unsigned char   __1;            /* 73 RESERVED                              */
    unsigned char   PSOFLG1;        /* 74 DATA SET SELECTION CONTROL FLAGS      */
#define PSOFHLD     SSSOHLD         /* ... SELECT HELD SYSOUT DATA SETS         */
#define PSOFCLAS    SSSOSCLS        /* ... USE CLASS                            */
#define PSOFDEST    SSSODST         /* ... USE REMOTE DESTINATION               */
#define PSOFJOBN    SSSOSJBN        /* ... USE JOB NAME                         */
#define PSOFJOBI    SSSOSJBI        /* ... USE JOB ID                           */
#define PSOFPGM     SSSOSPGM        /* ... USE USER WRITER PROGRAM NAME         */
#define PSOFFORM    SSSOSFRM        /* ... USE FORM NUMBER                      */

    unsigned char   PSOFLG2;        /* 75 DATA SET DISPOSITION AND CTL FLAGS    */
#define PSOFDONE    SSSOCTRL        /* ... PROCESSING COMPLETED                 */
#define PSOFCKPT    SSSOCHKP        /* ... CHECKPOINT USING RBA FIELD           */
#define PSOFPURG    0x02            /* ... PSO PURGED FLAG                      */
#define PSOF_O      0x01            /* ... $O INITIATED GROUP REQUEST           */

    unsigned short  PSOCOPY;        /* 76 NUMBER OF DATA SET COPIES             */
    unsigned char   PSOJOBN[8];     /* 78 JOB NAME                              */
    unsigned char   PSOJOBI[8];     /* 80 HASP JOB ID (JOBNNNNN)                */
    unsigned char   PSOCLS;         /* 88 NEW SYSOUT CLASS (GROUP REQ ONLY)     */
    unsigned char   __2[3];         /* 89 RESERVED                              */
    unsigned char   PSODEST[8];     /* 8C REMOTE USER ID FOR SELECTION          */
    unsigned char   PSOPGMN[8];     /* 94 USER WRITER NAME                      */
    unsigned char   PSORBA[8];      /* 9C RBA OF SYSOUT DATA SET                */
    unsigned char   PSODSN[44];     /* A4 SYSOUT DATA SET NAME                  */
    unsigned char   PSOFORM[4];     /* D0 DATA SET FORM NUMBER                  */
    unsigned char   PSOCLAS[8];     /* D4 CLASS(ES) TO BE PROCESSED             */
    void            *PSOWTRC;       /* DC A(PSOECB) ADDR OF EXTERNAL WTR PARAMETER AREA */
    unsigned char   PSODSID[8];     /* E0 DATA SET IDENT CHAR STRING            */
#define PSOPARML    0x76            /* *-PSOUFLG LENGTH OF SSOB PARAMETER AREA  */
    void            *PSOTCB;        /* E8 TCB ADDRESS OF LAST PSO USER          */
    int             PSORETN;        /* EC SUB-SYSTEM RETURN CODE                */
#define PSOFRTOK    SSSORTOK        /* ... EVERYTHING IS OK                     */
#define PSOFEODS    SSSOEODS        /* ... NO MORE DATASETS TO SELECT           */
#define PSOFNJOB    SSSONJOB        /* ... JOB NOT FOUND                        */
#define PSOFINVA    SSSOINVA        /* ... INVALID SEARCH ARGUMENTS             */
#define PSOFUNAV    SSSOUNAV        /* ... UNABLE TO PROCESS NOW                */
#define PSOFDUPJ    SSSODUPJ        /* ... DUPLICATE JOBNAMES                   */
#define PSOFINVJ    SSSOINVJ        /* ... INVALID JOBNAME/JOBID COMBINATION    */

    unsigned        PSOHQT;         /* F0 TRACK (OR STORAGE) ADDRESS OF HQT     */
    void            *PSOSJB;        /* F4 ADDRESS OF SJB                        */
    /* START OF EXTERNAL WRITER PARAMETER AREA                                  */
    unsigned        PSOECB;         /* F8 ECB FOR EXTERNAL WRITER WAIT ON JOT   */
    /* PSOECBP  DC    0A(PSOECB)          START OF XMPOST PARAMETER LIST        */
    unsigned        PSORDRON;       /* FC TIME ON INPUT PROCESSOR               */
    unsigned        PSORDTON;       /* 100 DATE ON INPUT PROCESSOR              */
    unsigned char   PSOUSEID[8];    /* 104 USER ID                              */
    /* END OF EXTERNAL WRITER PARAMETER AREA                                    */
    unsigned        PSOWKOFF;       /* 10C OFFSET OF WORK JOE                   */
    unsigned        PSOCHOFF;       /* 110 OFFSET OF CHAR JOE                   */
    /* PSOLINK  DS    0A                  SAVE AREA FOR LINK REGISTER           */
    unsigned        PSOCKOFF;       /* 114 OFFSET OF CKPT JOE                   */
    unsigned        PSOJBKEY;       /* 118 JOB IDENTIFIER KEY                   */
    unsigned        PSOJQEP;        /* 11C HASP JQE OFFSET                      */
    unsigned short  PSOJOBNO;       /* 120 HASP JOB NUMBER (BINARY)             */
    unsigned short  PSOROUTE;       /* 122 SELECTION ROUTE CODE (BINARY)        */
    unsigned        PSOIOTTR;       /* 124 IOT TTR OF SELECTED HQR              */
};
#define PSOLNGTH    sizeof(__PSO)   /* 128 *-PSODSECT       LENGTH OF PSO DSECT */

extern __PSO *__getpso(void);

#endif
