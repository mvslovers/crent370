#ifndef HASPSVT_H
#define HASPSVT_H

typedef struct haspsvt  HASPSVT;/* JES2 subsystem vector table      */

struct haspsvt {
    short       ssvtrsv1;       /* 00 RESERVED                      */
    short       ssvtfnum;       /* 02 NUMBER OF FUNCTIONS SUPPORTED 
                                      BY THIS SUBSYSTEM             */
    char        ssvtfcod[256];  /* 04 FUNCTION MATRIX     0x01..0x13*/

/* Function address table */
    void        *svsout;        /* 104 PROCESS SYSOUT           0x01*/
    void        *svcanc;        /* 108 TSO CANCEL               0x02*/
    void        *svstat;        /* 10C TSO STATUS               0x03*/

    void        *sveot;         /* 110 END OF TASK              0x04*/
    void        *svjbsl;        /* 104 JOB SELECTION            0x05*/
    void        *svaloc;        /* 108 ALLOCATION               0x06*/
    void        *svunal;        /* 10C UNALLOCATION             0x07*/

    void        *sveom;         /* 120 END OF MEMORY            0x08*/
    void        *svwto;         /* 124 WTO                      0x09*/
    void        *svcmnd;        /* 128 COMMAND PROCESSING       0x0A*/
    void        *svuser;        /* 12C USERID VALIDITY CHECK    0x0B*/
    
    void        *svterm;        /* 130 JOB DELETION             0x0C*/
    void        *svrenq;        /* 134 RE-ENQUEUE JOB           0x0D*/
    void        *svopen;        /* 138 OPEN                     0x0E*/
    void        *svclos;        /* 13C CLOSE                    0x0F*/

    void        *svckpt;        /* 140 CHECKPOINT               0x10*/
    void        *svrest;        /* 144 RESTART                  0x11*/
    void        *svreqid;       /* 148 REQUEST JOB ID           0x12*/
    void        *svretid;       /* 14C RETURN JOB ID            0x13*/

/* HASP EXTENSIONS */

    void        *svpost;        /* 150 POST HASP TASK               */
    void        *svdest;        /* 154 VERIFY DESTINATION           */
    void        *svcopn;        /* 158 CONVERTER FAKE OPEN          */
    void        *svccls;        /* 15C CONVERTER FAKE CLOSE         */

    void        *svgcell;       /* 160 GET STORAGE CELL             */
    void        *svgcpol;       /* 164 GET CELL POOL                */
    void        *svfcell;       /* 168 FREE CELL BY STORAGE ADDRESS */
    void        *svfcela;       /* 16C FREE CELL BY SJB/TCB ADDRESS */

    void        *svgcmns;       /* 170 GET MAIN FOR CELLS           */
    void        *svvfl;         /* 174 SIMULATE VFL INSTRUCTION     */
    void        *smpatch;       /* 178 SSSM PATCH SPACE POINTER     */

/* COMMUNICATION CONTROL FIELDS */

    void        *svhct;         /* 17C ADDRESS OF HASP HCT          */
    
    void        *svssct;        /* 180 ADDRESS OF SSCT              */
    void        *svhavt;        /* 184 HASP ADR SPACE VECTOR TABLE  */
    void        *svpidle;       /* 188 NUMBER OF IDLE PITS          */
// $SVOUTOP DC    0X'0'               OUTPUT EXCESSION OPTION FLAGS       
    void        *svoutxs;       /* 18C OUTPUT EXCESSION INCREMENT   */

    int         svhasp;         /* 190 HASP CONDITION               */
#define SVHASP_UP       0       /* ... STILL UP                     */
#define SVHASP_ABEND    (-1)    /* ... ABENDED or ABENDING          */
#define SVHASP_PHASP    (+1)    /* ... $PHASP ACCEPTED              */

    unsigned char svstus;       /* 194 SUBSYSTEM STATUS BYTE        */
#define SVSTUS_SVSTUSP  0x80    /* ... THIS IS THE PRIMARY SUBSYSTEM*/
#define SVSTUS_SVSTUST  0x40    /* ... HASP TERMINATION COMPLETE    */
#define SVSTUS_SVSTUSR  0x20    /* ... HASP IS RESTARTING           */
#define SVSTUS_SVSTXST  0x10    /* ... HASP MONITORING TIME EXCESSIONS*/
#define SVSTUS_SVSTIRV  0x08    /* ... CHKPT DEVICE RESERVED BY INIT*/
#define SVSTUS_SVSTRS5  0x04    /* ... RESERVED FOR FUTURE USE      */
#define SVSTUS_SVSTIDS  0x02    /* ... FULL HASP MESSAGE IDS REQUIRED */
#define SVSTUS_SVSTRPL  0x01    /* ... A RE-IPL IS REQUIRED         */

    char        svvarf;         /* 195 LARGE STORAGE CELL FREED FLAG*/
    char        svtslok;        /* 196 TSU ABEND INTERLOCK FLAG     */
    char        svcomch;        /* 197 HASP COMMAND CHARACTER (OS INPUT) */
    char        svrelno[2];     /* 198 OS/VS2 RELEASE NUMBER        */
    char        svlevel[2];     /* 19A OS/VS2 RELEASE LEVEL         */
    char        svsid[4];       /* 19C ALPHANUMERIC SYSTEM ID       */

// $SVTO    DC    0Y(*-*)             SYSTEM IDENTIFICATION             R4
    char        svtosys;        /* 1A0 SYSTEM                       */
    char        svtoqul;        /* 1A1 QUALIFIER                    */
    short       svnosys;        /* 1A2 MAXIMUM SYSTEMS              */
    short       svnount;        /* 1A4 MAXIMUM UNIT ROUTING         */
    short       svrout;         /* 1A6 MAXIMUM REMOTE NUMBER        */
    char        svroutm[256];   /* 1A8 REMOTE ROUTING MASK BYTES    */
    
    void        *svrdt;         /* 2A8 ADDRESS OF REMOTE DESTINATION TABLE  */
    void        *svrdte;        /* 2AC ADDRESS OF LAST RDT ELEMENT  */

    void        *svirdrs;       /* 2B0 ADDRESS OF FIRST INTRDR DCT  */
    void        *svirwt;        /* 2B4 INTRDR WAIT ELEMENT CHAIN HEADER */
    short       svninrs;        /* 2B8 &NUMINRS+2 (FOR STC & TSU)   */
    char        svmaxcl;        /* 2BA COUNT OF EXECUTION CLASSES   */
    char        _2bb;           /* 2BB RESERVED FOR FUTURE USE      */
    char        svchkpt[6];     /* 2BC CURRENT CHKPT VOLSER         */
    char        _2c2;           /* 2C2 RESERVED FOR FUTURE USE      */
    char        _2c3;           /* 2C3 RESERVED FOR FUTURE USE      */

/* CONSOLE SERVICE ELEMENTS */

    void        *svcmba;        /* 2C4 ADDRESS OF CMB WORK AREA     */
    void        *svcmbac;       /* 2C8 CMB ACTIVITY COUNT           */
    void        *_2cc;          /* 2CC align to double word         */

// svcmbfq appears to by pointer followed by signed int
    void        *svcmbfq0;      /* 2D0 CMB FREE QUEUE               */
    int         svcmbfq1;       /* 2D4 CMD FREE QUEUE               */
    void        *svcmbrq;       /* 2D8 CMB RESERVE QUEUE            */
    void        *svcommq;       /* 2DC COMMAND PROCESSOR QUEUE      */

    unsigned    svcomct;        /* 2E0 CMBS RESERVED FROM COMM      */

/* $$POST ELEMENTS -- REQUESTS FOR PCE SERVICE  */

    void        *svecf;         /* 2E4 $$POST EVENT CONTROL FIELD   */
    void        *svcomm;        /* 2E8 $$POST ELEMENT FOR COMM      */
    void        *svpso;         /* 2EC $$POST ELEMENT FOR PROCESS SYSOUT */

    void        *svjob;         /* 2F0 $$POST ELEMENT FOR JOB FUNCTION */
    void        *svcnv;         /* 2F4 $$POST ELEMENT FOR JCL CONVERSION */
    void        *svasync;       /* 2F8 $$POST ELEMENT FOR ASYNC PCE */
    void        *svxstim;       /* 2FC $$POST ELEMENT FOR TIME EXCESSION */

    void        *svtimer;       /* 300 $$POST ELEMENT FOR TIMER PCE */
    void        *_304;          /* 304 RESERVED                     */
    void        *svmllm;        /* 308 $$POST ELEMENT FOR MLLM PCE  */
// $SVPCENO EQU   (*-$SVCOMM)/4       NUMBER OF $$POST PCE ELEMENTS       
#define SVPCENO 9
    void        *svirdr;        /* 30C $$POST ELEMENT FOR INTRDR DATA */

/* STORAGE CELL CONTROL ELEMENTS */

    char        svcenq[12];     /* 310 ENQ ($SVQNAM,$SVCRNAM,E,4,SYSTEM),MF=L */
    union {
        char    svqnam[8];      /* 31C QNAME FOR ALL HASP ENQS      */
        struct {
            char _31C[4];       /* 31C 'SYSZ'                       */
            char svssnm[4];     /* 320 '****' NAME OF SUBSYSTEM     */
        };
    };
    char        svcrnam[4];     /* 324 'CELL' R NAME FOR WAIT FOR CELLS */
    char        svcpost[12];    /* 328 POST  *-*,ASCB=*-*,ERRET=$SVBR14,MF=L */
    void        *svctreq;       /* 334 CELL TYPE REQUESTED          */
    void        *svcells;       /* 338 CELL CONTROL HEADER          */
    void        *svcellf;       /* 33C FREE CELL CONTROL ELEMENT HEADER */

/* HASP JOB SERVICES QUEUES LOCK ELEMENT */

    char        svqloke[4];     /* 340 'HASP'/'JES2'                */
    int         svqlokc;        /* 344 CHAIN WORD                   */
                                /* ... ZERO MEANS UNLOCKED          */
                                /* ... MINUS MEANS LOCKED, NOBODY WAITING */
                                /* ... PLUS MEANS LOCKED, SOMEONE WAITING */
    void        *_348;          /* 348 ASCB ADDR OF LOCK HOLDER (IF ANY) */
    char        svqlokp[12];    /* 34C POST  *-*,ASCB=*-*,ERRET=$SVBR14,MF=L  EXPAND POST ELEMENT */

/* HASP POST ELEMENT */

    char        svposte[12];    /* 358 POST  *-*,ASCB=*-*,ERRET=*-*,MF=L  EXPAND POST ELEMENT */
#define svhecba svposte         /* ... SVHECBA EQU $SVPOSTE ADDRESS OF MAIN HASP ECB */

#define SVPOSTW 4               /* OFFSET TO $$POST WORK INDICATOR  */
#define SVBLANK 8               /* 48 FIXED BLANKS                  */
#define SVFIXL  4+1+3+48        /* LENGTH OF FIXED CSA SPACE        */
    void        *svpit;         /* 364 PARTITION INFORMATION TABLE ADDRESS */

/* JOB SERVICE QUEUES */

    unsigned    svjlock[2];     /* 368 LOCK HEADER FOR JOB SERVICES QUEUES */

    void        *svjpcls;       /* 370 SJBS PENDING JOB-BY-CLASS    */
    void        *svjpxbm;       /* 374 SJBS PENDING EXECUTION BATCHING  */
    void        *svjpnum;       /* 378 SJBS PENDING JOB-BY-NUMBER   */
    void        *svjxcls;       /* 37C SJBS EXECUTING JOB-BY-CLASS  */

    void        *svjxnum;       /* 380 SJBS EXECUTING JOB-BY-NUMBER */
    void        *svjterm;       /* 384 SJBS WITH JOBS TO TERMINATE  */
    void        *svjrenq;       /* 388 SJBS WITH JOBS TO RE-ENQUEUE */

/* MISCELLANEOUS SERVICE QUEUES */

    void        *svspiot;       /* 38C CHAIN OF IOTS AWAITING SPIN  */

    unsigned    svtscs[2];      /* 390 SJBS FOR CANCEL/STATUS       */
    unsigned    svpsoq[2];      /* 398 SJBS FOR PROCESS SYSOUT      */

    void        *svfifoq;       /* 3A0 FIFO REORDERED SPIN/HOLD REQUESTS */
    void        *svholdq;       /* 3A4 FIFO ORDERED HOLD REQUEST QUEUE */
    void        *svxiotq;       /* 3A8 CONVERTER SPIN/HOLD IOT Q   */
    void        *svprgq;        /* 3AC PURGED PSO QUEUE            */

    void        *_3B0;          /* 3B0 RESERVED FOR FUTURE USE     */

/* SPOOL DATA MANAGEMENT */

    unsigned    svpddb1;        /* 3B4 OFFSET WITHIN IOT OF 1ST PDDB */
    unsigned    svhqrct;        /* 3B8 MAXIMUM HQRS IN HQT          */
    unsigned    svmapl;         /* 3BC DA ALLOCATION MAP LENGTH     */

    unsigned    svxpri[10];     /* 3C0 JOB OUTPUT PRIORITY TABLE    */
    short       svbfsiz;        /* 3E8 SPOOL BUFFER SIZE            */
    char        svnumda;        /* 3EA NUMBER OF DIRECT ACCESS MODULES */
    char        svrincr;        /* 3EB RECORD ALTERNATION PARAMETER */
    char        svtkcel;        /* 3EC TRAKCELL SIZE IN BUFFERS     */
    char        svbaksp;        /* 3ED CONSOLE BACKSPACE CHARACTER  */
    char        svntgbe;        /* 3EE MAXIMUM NUMBER OF TG'S PER TGB */
    char        _3EF;           /* 3EF UNUSED                       */

    unsigned    svtgalc;        /* 3F0 ALLOCATED TRACK GROUPS       */
    unsigned    svtgtot;        /* 3F4 TOTAL TRACK GROUPS           */
    void        *svttgba;       /* 3F8 FIRST TGB ENTRY ADDRESS      */
    unsigned    _3FC;           /* 3FC TGB ENTRY SIZE               */

    void        *_400;          /* 400 LAST TGB ENTRY               */
    void        *_404;          /* 404 align to double word         */
    void        *svtgasc;       /* 408 TGB REQUEST ASCB             */
    unsigned    svtgecb;        /* 40C TGB REQUEST ECB              */

    void        *svrps;         /* 410 ADDRESS OF DASD RPS TABLES   */

/* SYSOUT CLASS ATTRIBUTE TABLE */

// $SVSCAT  EQU   *-3*64              SYSOUT CLASS ATTRIBUTE TABLE        
    char        _414[64];       /* 414 SYSOUT CLASSES A-Z, 0-9      */

/* RETURN CONTROL ELEMENTS AND ROUTINE */

    void        *svsmfso;       /* 454 ADDRESS OF IEFUSO            */
    void        *svsmfjp;       /* 458 ADDRESS OF IEFUJP            */
    short       svretn;         /* 45C SLR   R15,R15  ZERO R15      */
    short       svbr14;         /* 45E BR    R14      RETURN        */

/* SPOOL DATA MANAGEMENT (VARIABLE PORTION) */

// $SVTDATA DS    0F                  FIRST, LAST, NEXT TED PTRS        R4
    void        *svtfrst;       /* 460 ADDRESS OF FIRST TED         */
    void        *svtlast;       /* 464 ADDRESS OF LAST TED          */
    void        *svtnext;       /* 468 ADDRESS OF NEXT TED          */
    void        *svted;         /* 46C ADDRESS OF TRK EXTENT DATA TABLE */
//         ORG   *-40                ORG OVER UNUSED SPACE               
//$SVDCB   EQU   *                   SYS1.HASPACE DCB                    
//         ORG   *+40                ORG OVER UNUSED SPACE               
    void        *_470[3];       /* 470 12-BYTE MEAT OF DCB          */
    void        *svdeb;         /* 47C ADDR OF JES2 DIRECT ACCESS DEB */
};                              /* 480 (1152 bytes)                 */
#define SSVTLEN 0x480           /* 480 (1152 bytes)                 */


#endif  /* HASPSVT_H */
