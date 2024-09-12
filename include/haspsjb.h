#ifndef HASPSJB_H
#define HASPSJB_H

/* HASP SUBSYSTEM JOB BLOCK (SJB) DSECT */

typedef struct __sjb        __SJB;

/*
         L     R2,PSATOLD-PSA          OUR TCB ADDRESS                  00281000
         L     R2,TCBJSCB-TCB(,R2)     JSCB ADDRESS                     00282000
         USING IEZJSCB,R2                                               00283000
         L     R2,JSCBACT              ACTIVE JSCB ADDRESS              00284000
         L     R2,JSCBSSIB             SSIB ADDRESS                     00285000
         L     R2,SSIBSUSE-SSIB(,R2)   SJB ADDRESS                      00286000
*/

struct __sjb {
    unsigned        SJBSAVE[2];     /* 00 18F (reduced to 2 words to fudge alignment) */
/*
*        TSO CANCEL/STATUS SERVICE FIELDS
*/
/*       ORG   SJBSAVE+8                                                        */
/* SJBTCMND DS    0D                  FIRST OF CANCEL COMMAND                   */
    unsigned        SJBTAREA;       /* 08 WORK AREA GOTTEN                      */
    unsigned        SJBTCCE;        /* 0C ADDRESS OF CCE                        */
    unsigned char   SJBTJOBN[8];    /* 10 JOB NAME                              */
    unsigned        SJBTJOBI;       /* 18 JOB ID OR ZERO ( BINARY FORM )        */
    unsigned short  SJBTDIMP;       /* 1C SIZE OF EXTENTION                     */
    unsigned short  SJBTDIMR;       /* 1E SIZE USED OR REQUIRED                 */
    unsigned short  SJBTFUNC;       /* 20 REQUESTED FUNCTION                    */
    unsigned short  SJBTRETB;       /* 22 SSOBRETN CODE                         */
    unsigned short  SJBTRETR;       /* 24 R15 RETURN CODE                       */
    unsigned char   SJBTF;          /* 26 FLAGS                                 */
#define SJBTFCAN    0x80            /* ... SVC 34 REQUIRED TO CANCEL            */

    unsigned char   SJBTFLGS;       /* 27 FLAGS FROM SSOB                       */
    unsigned char   SJBTULEN;       /* 28 USER ID LENGTH                        */
/*         ORG                                                                  */
    unsigned char   __1[31];        /* 29 alignment                             */
    unsigned char   SJBID[4];       /* 48 CL4'SJB'            SJB IDENTIFIER    */
    unsigned short  SJBLENG;        /* 4C CONTROL BLOCK LENGTH                  */
    unsigned char   SJBFLG1;        /* 4E FIRST FLAG BYTE ---                   */
#define SJB1XBMC    0x80            /* ... XBM CONTINUATION                     */
#define SJB1SJID    0x40            /* ... SELECT JOB BY ID - SJBJOBID          */
#define SJB1NORE    0x20            /* ... DISALLOW JOB RE-ENQUEUE              */
#define SJB1XBM     0x10            /* ... XEQ BATCH MONITOR OPERATING          */
#define SJB1XBWT    0x08            /* ... BATCH MONITOR AWAITS JOB             */
#define SJB1EJOB    0x04            /* ... HASP-RESTART JOB ($E JOB)            */
#define SJB1XBMR    0x02            /* ... XBM TERMINATING                      */
#define SJB1XBMJ    0x01            /* ... NORMAL JOB CAUSED XBM TERMINATION    */

    unsigned char   SJBFLG2;        /* 4F SECOND FLAG BYTE ---                  */
#define SJB2PNIT    0x80            /* ... STOP THE INITIATOR                   */
#define SJB2JNFD    0x40            /* ... JOB-BY NUMBER NOT FOUND              */
#define SJB2EOM     0x20            /* ... END-OF-MEMORY DETECTED               */
#define SJB2CNCL    0x10            /* ... CANCEL AFTER SWA CREATE              */
#define SJB2CONV    0x08            /* ... SJB CREATED FOR CONVERTER            */
#define SJB2HOLD    0x04            /* ... HOLD JOB AFTER RE-QUEUE              */
#define SJB2JNL     0x02            /* ... JOB IS JOURNALLED                    */
#define SJB2INIT    0x01            /* ... INITIATOR FLAG                       */

    void            *SJBSSIB;       /* 50 POINTER TO SSIB                       */
    void            *SJBSJB;        /* 54 SJB CHAIN FROM $SVHAVT                */
    void            *SJBSDB;        /* 58 POINTER TO CHAIN OF SDBS              */
    unsigned        SJBJKEY;        /* 5C HDBDSKEY FOR THIS JOB                 */
    void            *SJBJCT;        /* 60 ADDRESS OF JCT FOR JOB                */
    unsigned        SJBJCTRK;       /* 64 JCT TRACK ADDRESS                     */
    void            *SJBTCBP;       /* 68 ADDRESS OF INIT OR STC TCB            */
    unsigned        SJBJQOFF;       /* 6C OFFSET OF JQE WITHIN JOB QUEUE        */
    unsigned char   SJBSSNM[4];     /* 70 SUBSYSTEM ID OF OWNER                 */
    void            *SJBIOT;        /* 74 ADR OF FIRST REGULAR IOT              */
    void            *SJBSPIOT;      /* 78 ADR OF FIRST SPIN IOT                 */
    void            *SJBOCT;        /* 7C ADR OF OUTPUT CONTROL TABLE           */
    /* SJBSECB  DS    0A                  STOP-ECB ADR FOR CREATED-ID JOB       */
    void            *SJBPIT;        /* 80 ADDRESS OF PIT IN HASP                */
    unsigned        SJBSTQE[3];     /* 84 EXECUTION TIMER QUEUE ELEMENT         */
    unsigned        SJBXSTIM;       /* 90 TIME ESTIMATE EXCESSION AMOUNT        */
    unsigned        SJBESTLN;       /* 94 PRINT EXCESSION LIMIT                 */
    unsigned        SJBESTPU;       /* 98 PUNCH EXCESSION LIMIT                 */
    void            *SJBXBSDB;      /* 9C ADDRESS OF XBM INPUT SDB              */
    unsigned char   SJBXBJNM[8];    /* A0 NAME OF BATCH DRIVER JOB              */
    void            SJBCSCB;        /* A8 ADDRESS OF CSCB                       */
    unsigned        SJBECB;         /* AC ECB FOR SJBIOB & JOB SELECT           */
    void            *SJBECBP;       /* B0 POINTER TO SJB'S ECB                  */
    void            *SJBASCBP;      /* B4 POINTER TO RELATED ASCB               */
    void            *SJBERRET;      /* B8 POINTER TO ERROR RETURN               */
    unsigned short  SJBPATID;       /* BC EBCDIC PIT ID                         */
    unsigned char   SJBPRIO;        /* BE HASP EXECUTION SELECTION PRTY         */
    unsigned char   __2;            /* BF RESERVED FOR FUTURE USE               */
    unsigned short  SJBXQFN1;       /* C0 HASPXEQ FUNCTION INDICATOR            */
    unsigned char   SJBFLG3;        /* C2 TERMINATION FLAG ONE ---              */
#define SJB3CLS     0x80            /* ... CLOSE ALL SUBSYSTEM DATA SETS        */
#define SJB3FSDB    0x40            /* ... FREE ALL SDBS                        */
#define SJB3TERM    0x20            /* ... TERMINATE THE JOB                    */
#define SJB3PPOU    0x10            /* ... PURGE PARTIAL OUTPUT                 */
#define SJB3RSV4    0x08            /* ... RESERVED                             */
#define SJB3CKPT    0x04            /* ... WRITE IOTS, JCT                      */
#define SJB3FIOT    0x02            /* ... FREE ALL IOTS                        */
#define SJB3FJCT    0x01            /* ... FREE JCT                             */

    unsigned char   SJBFLG4;        /* C3 TERMINATION FLAG TWO ---              */
#define SJB4MEND    0x80            /* ... MSG 'ENDED'                          */
#define SJB4MTRM    0x40            /* ... MSG 'TERMINATED'                     */
#define SJB4MREQ    0x20            /* ... MSG 'RE-ENQUEUED'                    */
#define SJB4MREX    0x10            /* ... MSG 'QUEUED FOR RE-EXECUTION'        */
#define SJB4FSJB    0x08            /* ... FREE THE SJB                         */
#define SJB4MRQH    0x04            /* ... MSG 'RE-ENQUEUED AND HELD'           */
#define SJB4RSV6    0x02            /* ... RESERVED                             */
#define SJB4TERM    0x01            /* ... BATCH JOB HAS TERMINATED             */

    void            *SJBQUEUE;      /* C4 ADDRESS OF $SVJ QUEUE HEADER          */
    unsigned        SJBXQCHN;       /* C8 HASPXEQ CHAINING WORD                 */
    unsigned        __3;            /* CC RESERVED                              */
    /* SJBLOCKH DS    0D                  SJB LOCKING DOUBLEWORD                */
    void            *SJBTCB;        /* D0 LOCK-HOLDING TCB ADDRESS              */
    int             SJBNEXTL;       /* D4 0 - SJB IS UNLOCKED
                                          - - SJB LOCKED, NO WAIT CHAIN
                                          + - SJB LOCKED, ADR OF WAITER         */
    void            *SJBLOGQ;       /* D8 HASP JOB LOG MESSAGE QUEUE            */
    void            *SJBPSOP;       /* DC PROCESS SYSOUT CONTROL BLOCK          */
    unsigned char   SJBJCLAS;       /* E0 HASP JOB CLASS                        */
    unsigned char   SJBLKFG;        /* E1 SERIALIZATION FLAG                    */
#define SJBFIRST    0x80            /* ... FIRST $SVJPCLS REQUEST               */
#define SJBDRAIN    0x40            /* ... PIT HAS BEEN DRAINED                 */
#define SJBPRIM     0x20            /* ... PRIMARY INITIATOR SJB                */

    unsigned short  SJBASID;        /* E2 USERS ASID                            */
    unsigned char   SJBJOBID[8];    /* E4 JOB IDENTIFIER - EBCDIC, NUMERIC      */
    unsigned char   SJBJOBNM[8];    /* EC JOBNAME FROM JOB CARD                 */
    /* SJBFLOW  DS    0F                  FLOW BYTES FOR ABNORMAL PROCESSING    */
    unsigned char   SJBTFLOW;       /* F4 SJB HAS BEEN ON QUEUE INDICATOR       */
    unsigned char   SJBTFFG;        /* F5 TSO PROCESSING FLOW                   */
#define SJBTFFGM    0x80            /* ... ECB STATUS MEANINGFULL               */
#define SJBTFFGG    0x40            /* ... PSO GOTTEN THIS ENTRY TO PSO         */
#define SJBTFFGP    0x20            /* ... PSO PURGE REQUESTED                  */
#define SJBTFFGC    0x10            /* ... CANCEL/STATUS EOT FUNCTION GOING     */
    unsigned char   __4;            /* F6 RESERVED                              */
    unsigned char   __5;            /* F7 RESERVED                              */
    void            *SJBTCHN;       /* F8 TSU CHAIN FIELD                       */
    unsigned        SJBFWORD;       /* FC WORK AREA FOR HCBIO RTNS              */
    /*        SJBFWORD MUST NEVER BE SEPARATED FROM SJBDBLWK                    */
    unsigned        SJBDBLWK[2];    /* 100 DOUBLEWORD WORKAREA                  */
/*
*              INPUT/OUTPUT BLOCK IN SJB
*/
    /*     DS    0D                  DOUBLE WORD ALIGNMENT                      */
    /* SJBIOB   DS    0XL(40+4*8)         IOB FOR JOB CONTROL BLOCKS            */
    unsigned char   SJBIFLG1;       /* 108 IOB - FLAG BYTE                      */
    unsigned char   __6;            /* 109                                      */
    unsigned char   SJBISNS0;       /* 10A IOB - FIRST SENSE BYTE               */
    unsigned char   SJBISNS1;       /* 10B IOB - SECOND SENSE BYTE              */
    /* SJBIECB  DS    0A                  IOB - EVENT CONTROL BLOCK ADR         */
    unsigned char   SJBICMP;        /* 10C IOB - COMPLETION CODE                */
    unsigned char   __7[3];         /* 10D AL3(SJBECB)         IOB - ECB POINTER*/
    unsigned char   SJBISIO;        /* 110 IOB - SIO CONDITION CODE             */
    /* SJBICSW  DS    0XL7                IOB - CHANNEL STATUS WORD             */
    unsigned char   SJBICSWA[3];    /* 111 IOB - CSW ADDRESS PORTION            */
    unsigned char   SJBIST0;        /* 114 IOB - FIRST STATUS BYTE              */
    unsigned char   SJBIST1;        /* 115 IOB - SECOND STATUS BYTE             */
    unsigned short  SJBILEN;        /* 116 IOB - RESIDUAL LENGTH                */
    void            *SJBIST;        /* 118 IOB - CHANNEL PROGRAN ADDRESS        */
    void            *SJBIDCB;       /* 11C IOB - DCB ADDRESS                    */
    void            *SJBIRS;        /* 120 IOB - RESTART CHANNEL PROGRAM ADR    */
    unsigned        __8;            /* 124                                      */
    unsigned char   SJBIFDAD[8];    /* 128 IOB - FULL DISK ADDRESS              */
    unsigned char   SJBCCW1[8];     /* 130 CCW   X'03',*+5,X'60',1   SET SECTOR/NO-OP       */
    unsigned char   SJBCCW2[8];     /* 138 CCW   X'31',SJBIFDAD+3,X'60',5  SEARCH ID EQUAL  */
    unsigned char   SJBCCW3[8];     /* 140 CCW   X'08',*-8,0,1       TIC *-8                */
    unsigned char   SJBCCW4[8];     /* 148 CCW   X'05',0,0,*-*       WRITE/READ DATA        */
/*
*              ACB FOR HASP JOB LOG DATASET
*/
    unsigned char   SJBLACB[76];    /* 150 ACB   MACRF=(ADR,SEQ,OUT)            */
/*
*              DEB FOR HASP JOB LOG DATASET
*/
    unsigned char   SJBLDEB[32];    /* 19C DC    7A(0),A(SJBLACB)               */
/*
*              RPL FOR HASP JOB LOG DATASET
*/
    unsigned char   SJBLRPL[76];    /* 1BC RPL   ACB=SJBLACB                    */
/*
*              ACB FOR INTERNAL TEXT DATASET
*/
    unsigned char   SJBIACB[76];    /* 208 ACB   MACRF=(ADR,SEQ,IN)             */
/*
*              DEB FOR INTERNAL TEXT DATASET
*/
    unsigned char   SJBIDEB[32];    /* 254 DC    7A(0),A(SJBIACB)               */
/*
*              ACB FOR SYSTEM MESSAGES DATASET
*/
    unsigned char   SJBMACB[76];    /* 274 ACB   MACRF=(ADR,SEQ,OUT)            */
/*
*              DEB FOR SYSTEM MESSAGES DATASET
*/
    unsigned char   SJBMDEB[32];    /* 2C0 DC    7A(0),A(SJBMACB)               */
/*
*              ACB FOR JOURNAL DATASET
*/
    unsigned char   SJBJACB[76];    /* 2E0 ACB   MACRF=(ADR,SEQ,DIR,IN,OUT)     */
/*
*              DEB FOR JOURNAL DATASET
*/
    unsigned char   SJBJDEB[32];    /* 32C DC    7A(0),A(SJBJACB)               */
/*
*              DCB FOR SPOOL DATASET
*
         ORG   *-40
SJBDCB   DS    0F                  SYS1.HASPACE DATA CONTROL BLOCK
         ORG   *+40
*/
    unsigned        __9[3];         /* 34C DS    3A                             */
/*
*              DEB FOR SPOOL DATASET
*
SJBDEB   EQU   *                   SYS1.HASPACE DATA EXTENT BLOCK    R4
*/
};                                  /* 358 (856 bytes)                          */

#endif
