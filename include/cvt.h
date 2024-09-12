#ifndef CVT_H
#define CVT_H

/* CVT for OS/VS2 (MVS38J) */

typedef struct cvt      CVT;
typedef struct cvtxtnt1 CVTXTNT1;
typedef struct cvtxtnt2 CVTXTNT2;
typedef struct cvtfix   CVTFIX;

#define CVTPTR      (*(CVT**)16)

struct cvtfix { /* 256 byte area that precedes the CVT address */
    unsigned char   reserved[250];  /* 00                                           */
    unsigned char   cvtmdl[2];      /* FA CPU MODEL NUMBER IN SIGNLESS PACKED       */
                                    /*    DECIMAL, I.E., A MODEL 145 WOULD BE       */
                                    /*    REPRESENTED AS 0145 HEX                   */
    unsigned char   cvtnumb[2];     /* FC RELEASE NUMBER                            */
    unsigned char   cvtlevl[2];     /* FE LEVEL NUMBER OF THIS RELEASE              */
};                                  /* 100 (256 bytes)                              */

struct cvt {
    void            *cvttcbp;       /* 00 ADDRESS OF A DOUBLE WORD, THE FIRST       */
                                    /*    CONTAINING THE NEXT-TO-BE-DISPATCHED TCB  */
                                    /*    ADDRESS, THE SECOND CONTAINING THE LAST   */
                                    /*    (CURRENT) TCB ADDRESS.  BOTH WORDS ARE    */
                                    /*    IDENTICAL UNLESS THE TASK GOES INTO A     */
                                    /*    WAIT STATE.  WHEN IN A WAIT STATE, THE    */
                                    /*    FIRST WORD IS SET TO ZERO UNTIL THE       */
                                    /*    WAITING IS OVER AND THEN BOTH WORDS ARE   */
                                    /*    ONCE AGAIN IDENTICAL.  (OS/VS1)           */
                                    /*    ADDRESS OF 4-WORD LIST OF ADDRESSES -     */
                                    /*    THE NEXT TCB, THE CURRENT TCB, THE NEXT   */
                                    /*    ASCB AND THE CURRENT ASCB, IN THAT        */
                                    /*    ORDER (OS/VS2)                            */
    void            *cvt0ef00;      /* 04 ADDRESS OF ROUTINE TO SCHEDULE            */
                                    /*    ASYNCHRONOUS EXITS                        */
    void            *cvtlink;       /* 08 ADDRESS OF DCB FOR SYS1.LINKLIB DATA SET  */
    void            *cvtjob;        /* 0C ** CVTJOB FIELD UNUSED IN MVS **          */
    void            *cvtbuf;        /* 10 ADDRESS OF THE BUFFER OF THE RESIDENT     */
                                    /*    CONSOLE INTERRUPT ROUTINE                 */
    void            *cvtxapg;       /* 14 ADDRESS OF I/O SUPERVISOR APPENDAGE VECTOR*/
                                    /*    TABLE                                     */
    void            *cvt0vl00;      /* 18 ADDRESS OF ENTRY POINT OF THE TASK        */
                                    /*    SUPERVISOR'S ADDRESS VALIDITY CHECKING    */
                                    /*    ROUTINE                                   */
    void            *cvtpcnvt;      /* 1C ADDRESS OF ENTRY POINT OF THE ROUTINE     */
                                    /*    WHICH CONVERTS A RELATIVE TRACK ADDRESS   */
                                    /*    (TTR) TO AN ABSOLUTE TRACK ADDRESS        */
                                    /*    (MBBCCHHR)                                */
    void            *cvtprltv;      /* 20 ADDRESS OF ENTRY POINT OF THE ROUTINE     */
                                    /*    WHICH CONVERTS AN ABSOLUTE TRACK ADDRESS  */
                                    /*    (MBBCCHHR) TO A RELATIVE TRACK ADDRESS    */
                                    /*    (TTR)                                     */
    void            *cvtilk1;       /* 24 ADDRESS OF THE CHANNEL AND CONTROL UNIT   */
                                    /*    PORTION OF THE UCB LOOKUP TABLE           */
    void            *cvtilk2;       /* 28 ADDRESS OF THE UCB HALFWORD ADDRESS LIST  */
                                    /*    PORTION OF THE UCB LOOKUP TABLE           */
    void            *cvtxtler;      /* 2C ADDRESS OF ERROR RECOVERY PROCEDURE (ERP) */
                                    /*    LOADER (IECVERPL) ENTRY POINT IECXTLER    */
    void            *cvtsysad;      /* 30 ADDRESS OF THE SYSTEM RESIDENCE VOLUME    */
                                    /*    ENTRY IN THE UCB LOOKUP TABLE             */
    void            *cvtbterm;      /* 34 ADDRESS OF ENTRY POINT OF THE ABTERM      */
                                    /*    ROUTINE                                   */
    unsigned        cvtdate;        /* 38 CURRENT DATE IN PACKED DECIMAL            */
    void            *cvtmslt;       /* 3C ADDRESS OF THE MASTER COMMON AREA IN      */
                                    /*    MASTER SCHEDULER RESIDENT DATA AREA.      */
                                    /*    NOTE - USE CVTMSER INSTEAD TO ADDRESS     */
                                    /*    MASTER SCHEDULER RESIDENT DATA AREA       */
    void            *cvtzdtab;      /* 40 ADDRESS OF I/O DEVICE CHARACTERISTIC TABLE*/
    void            *cvtxitp;       /* 44 ADDRESS OF ERROR INTERPRETER ROUTINE      */
    void            *cvtdar;        /* 48 ** CVTDAR FIELD UNUSED IN MVS **          */
    void            *cvt0fn00;      /* 4C RESERVED (OS/VS2)                         */
    unsigned char   cvtexit[2];     /* 50 SVC  3  - X'0A03' EXIT TO DISPATCHER      */
    unsigned char   cvtbret[2];     /* 52 BR   14 - X'07FE' RETURN TO CALLER        */
                                    /*    (USED BY DATA MANAGEMENT ROUTINES)        */
    void            *cvtsvdcb;      /* 54 ADDRESS OF THE DCB FOR THE SYS1.SVCLIB    */
                                    /*    DATA SET                                  */
    void            *cvttpc;        /* 58 ADDRESS OF THE TIMER SUPERVISOR WORK AREA */
    unsigned short  cvtnipsv;       /* 5C RESERVED MVS                              */
    unsigned short  cvticpid;       /* 5E IPL'ED CPU PHYSICAL ID                    */
    void            *cvtsjq;        /* 60 RESERVED (OS/VS2)                         */
    void            *cvtcucb;       /* 64 ADDRESS OF THE TABLE THAT CONTAINS THE    */
                                    /*    CURRENT CONSOLE UCB ADDRESSES             */
    void            *cvtqte00;      /* 68 ADDRESS OF THE TIMER ENQUEUE ROUTINE FOR  */
                                    /*    INTERVAL TIMER                            */
    void            *cvtqtd00;      /* 6C ADDRESS OF THE TIMER DEQUEUE ROUTINE FOR  */
                                    /*    INTERVAL TIMER                            */
    void            *cvtstb;        /* 70 ADDRESS OF THE I/O DEVICE STATISTICS TABLE*/
    unsigned char   cvtdcb;         /* 74 XL1'13' -     OPERATING SYSTEM            */
#define CVTRSV08    0x80            /* ... RESERVED                                 */
#define CVT1SSS     0x40            /* ... OPTION 1 (PCP) SSS                       */
#define CVT2SPS     0x20            /* ... OPTION 2 (MFT) SPS, OS/VS1               */
#define CVT4MS1     0x10            /* ... OPTION 4 (MVT) MS1, OS/VS2               */
#define CVTRSV09    0x08            /* ... RESERVED                                 */
#define CVT4MPS     0x04            /* ... MODEL 65 MULTIPROCESSING                 */
#define CVT6DAT     0x02            /* ... DYNAMIC ADDRESS TRANSLATION BY CPU       */
                                    /*     (OS/VS1, OS/VS2)                         */
#define CVTMVS2     0x01            /* ... MULTIPLE MEMORY OPTION OF OS/VS2 IS      */
                                    /*     PRESENT                                  */
#define CVT8AOS2    CVT4MS1+CVT6DAT /* ... OS/VS2 SYSTEM                            */

    unsigned char   cvtdcba[3];     /* 75 ADDRESS OF THE DCB FOR THE SYS1.LOGREC    */
                                    /*    (OUTBOARD RECORDER) DATA SET FOR SYSTEM   */
                                    /*    ENVIRONMENT RECORDING (SER)               */
    unsigned        cvtsv76m;       /* 78 SVC 76 MESSAGE COUNT FIELD (OS/VS2)       */

    void            *cvtixavl;      /* 7C ADDRESS OF THE I/O SUPERVISOR'S FREELIST  */
                                    /*    POINTER WHICH CONTAINS THE ADDRESS OF THE */
                                    /*    NEXT REQUEST ELEMENT  (OS/VS1)            */
                                    /*    ADDRESS OF THE I/O SUPERVISOR'S           */
                                    /*    COMMUNICATION AREA (IOCOM)  (OS/VS2)      */
    void            *cvtnucb;       /* 80 LOWEST ADDRESS NOT IN THE NUCLEUS         */
                                    /*    (ON PAGE BOUNDARY FOR OS/VS1)             */
                                    /*    (ON SEGMENT BOUNDARY FOR OS/VS2)          */
    void            *cvtfbosv;      /* 84 ADDRESS OF PROGRAM FETCH ROUTINE          */

    void            *cvt0ds;        /* 88 ADDRESS OF ENTRY POINT OF THE DISPATCHER  */
    void            *cvtilch;       /* 8C ADDRESS OF THE LOGICAL CHANNEL WORD TABLE */

    void            *cvtrv516;      /* 90 ** CVTIERLC FIELD UNUSED IN MVS **        */
    void            *cvtmser;       /* 94 ADDRESS OF DATA AREA OF MASTER SCHEDULER  */
                                    /*    RESIDENT DATA AREA                        */
    void            *cvt0pt01;      /* 98 ADDRESS OF BRANCH ENTRY POINT OF POST     */
                                    /*    ROUTINE                                   */
    void            *cvtrsv11;      /* 9C ** CVTTRMTB FIELD UNUSED IN OS/VS **      */
    unsigned        cvtsv76c;       /* A0 SVC 76 MESSAGE CONTROL FIELD.  HIGH-ORDER */
                                    /*    BIT IS DEFINED, AND ALL OTHER BITS ARE    */
                                    /*    ZERO.  (OS/VS2)                           */
#define CVTSV76Q    0x80            /* ... SVC 76 ENQUEUE SWITCH.  THIS IS THE      */
                                    /*     HIGH-ORDER BIT OF CVTSV76C.  (OS/VS2)    */

    void            *cvtmz00;       /* A4 HIGHEST ADDRESS IN VIRTUAL STORAGE FOR    */
                                    /*    THIS MACHINE (void*)0x00FFFFFF            */
    void            *cvt1ef00;      /* A8 ADDRESS OF ROUTINE WHICH CREATES IRB'S    */
                                    /*    FOR EXITS                                 */
    void            *cvtqocr;       /* AC GRAPHICS INTERFACE TASK (GFX) FIELD.      */
                                    /*    ADDRESS OF SEVENTH WORD OF GFX PARAMETER  */
                                    /*    LIST, IF GFX IS ACTIVE.  ZERO IF GFX IS   */
                                    /*    NOT ACTIVE                                */
    void            *cvtqmwr;       /* B0 ADDRESS OF QUEUE MANAGER'S SYSTEM OUTPUT  */
                                    /*    COMMUNICATIONS-DATA-AREA (CDA), WHICH IS  */
                                    /*    STORED ON AN EXTERNAL DEVICE              */
    unsigned short  cvtsnctr;       /* B4 SERIAL NUMBER COUNTER FOR ASSIGNING SERIAL*/
                                    /*    NUMBERS TO NON-SPECIFIC, UNLABELED        */
                                    /*    MAGNETIC TAPE VOLUMES                     */
    unsigned char   cvtopta;        /* B6 OPTION INDICATORS                         */
#define CVTCCH      0x80            /* ... CHANNEL CHECK HANDLER (CCH) OPTION       */
                                    /*     PRESENT RECOVERY MANAGEMENT SUPPORT (RMS)*/
#define CVTAPR      0x40            /* ... ALTERNATE PATH RETRY (APR) OPTION PRESENT*/
                                    /*     RECOVERY MANAGEMENT SUPPORT (RMS)        */
#define CVTDDR      0x20            /* ... DYNAMIC DEVICE RECONFIGURATION (DDR)     */
                                    /*     OPTION PRESENT - RECOVERY MANAGEMENT     */
                                    /*     SUPPORT (RMS)  (OS/VS1)                  */
                                    /*     DDR SYSTEM-INITIATED SWAP ACTIVE (OS/VS2)*/
#define CVTNIP      0x10            /* ... NIP IS EXECUTING                         */
#define CVTRSV12    0x08            /* ... RESERVED                                 */
#define CVT121TR    0x04            /* ... DO NOT TRANSLATE EXCP V=R                */
#define CVTASCII    0x02            /* ... ASCII TAPE PROCESSING IS GENERATED IN    */
                                    /*     THIS SYSTEM                              */
#define CVTXPFP     0x01            /* ... CPU HAS EXTENDED PRECISION FLOATING POINT*/
                                    /*     FEATURE                                  */

    unsigned char   cvtoptb;        /* B7 MISCELLANEOUS FLAGS                       */
#define CVTPROT     0x80            /* ... CPU HAS STORE PROTECTION FEATURE (OS/VS1)*/
#define CVTCTIMS    0x40            /* ... IF ON, HARDWARE HAS THE CLOCK COMPARATOR */
                                    /*     AND CPU TIMER FEATURE INSTALLED, AND     */
                                    /*     OS/VS1 SYSGEN HAS SPECIFIED THIS FEATURE */
                                    /*     (OS/VS1)                                 */
#define CVTTOD      0x20            /* ... CPU HAS TIME-OF-DAY CLOCK FEATURE        */
#define CVTNLOG     0x10            /* ... SYS1.LOGREC IS UNAVAILABLE FOR ERROR     */
                                    /*     RECORDING.  ALWAYS SET TO ZERO FOR       */
                                    /*     OS/VS1.                                  */
#define CVTAPTHR    0x08            /* ... NIP SETS THIS BIT TO 1 WHEN DEVICE TESTING */
                                    /*     IS COMPLETE.  IF 1, I/O SUPERVISOR USES  */
                                    /*     AN ALTERNATE PATH TO A DEVICE WHEN A     */
                                    /*     CONDITION CODE OF 3 EXISTS.  THIS BIT IS */
                                    /*     RESET TO 0 BY NIP AFTER THE LINK PACK    */
                                    /*     AREA IS INITIALIZED.                     */
#define CVTFP       0x04            /* ... CPU HAS FETCH PROTECTION FEATURE (OS/VS1)*/
#define CVTVS1A     0x02            /* ... VS1 ASSIST IS AVAILABLE FOR USE (OS/VS1) */
#define CVTVS1B     0x01            /* ... VS1 ASSIST SUBSET IS AVAILABLE FOR USE   */
                                    /*     (OS/VS1)                                 */
    void            *cvtqcdsr;      /* B8 CDE SEARCH ROUTINE ADDRESS  (OS/VS2)      */
    void            *cvtqlpaq;      /* BC ADDRESS OF POINTER TO MOST RECENT ENTRY   */
                                    /*    ON LINK PACK AREA CDE QUEUE  (OS/VS2)     */

    void            *cvtrsv18;      /* C0 ** CVTMPCVT FIELD UNUSED IN OS/VS **      */
    void            *cvtsmca;       /* C4 ADDRESS OF THE SYSTEM MANAGEMENT CONTROL  */
                                    /*    AREA (SMCA) IF THE SYSTEM MANAGEMENT      */
                                    /*    FACILITIES (SMF) OPTION IS PRESENT IN THE */
                                    /*    SYSTEM.  OTHERWISE, ZERO.                 */
    void            *cvtabend;      /* C8 ADDRESS OF SECONDARY CVT FOR ABEND IN EOT */
                                    /*    (OS/VS2)                                  */
    void            *cvtuser;       /* CC A WORD AVAILABLE TO THE USER              */

    void            *cvtmdlds;      /* D0 RESERVED FOR MODEL-DEPENDENT SUPPORT      */
    unsigned char   cvtqabst[2];    /* D4 SVC 13 - AN ABEND INVOCATION (OS/VS2)     */
    unsigned char   cvtlnksc[2];    /* D6 SVC  6 - A LINK INVOCATION                */
    void            *cvttsce;       /* D8 ADDRESS OF THE FIRST TIME SLICE CONTROL   */
                                    /*    ELEMENT (TSCE)                            */
    void            *cvtpatch;      /* DC ADDRESS OF A 200-BYTE FE PATCH AREA       */

    void            *cvtrms;        /* E0 RECOVERY MANAGEMENT SUPPORT (RMS)         */
                                    /*    COMMUNICATIONS VECTOR.  ADDRESS OF A      */
                                    /*    MACHINE STATUS BLOCK.                     */
    void            *cvtrv515;      /* E4 ** CVTTSCVT FIELD UNUSED IN MVS **        */
    void            *cvt0scr1;      /* E8 ADDRESS OF THE SECTOR CALCULATION ROUTINE */
                                    /*    FOR ROTATIONAL POSITION SENSING (RPS)     */
    /* CVTGTF   DS    0A -          GENERALIZED TRACE FACILITY (GTF) CONTROL WORD   */
    unsigned char   cvtgtfst;       /* EC GTF FLAG BYTES                            */
#define CVTGTFAV    0x80            /* ... IF ZERO, GTF NOT ACTIVE.  IF ONE, GTF    */
                                    /*     ACTIVE.  (OS/VS2)                        */
#define CVTRV315    0x40            /* ... RESERVED (OS/VS2)                        */
#define CVTRV316    0x20            /* ... RESERVED (OS/VS2)                        */
#define CVTRV317    0x10            /* ... RESERVED (OS/VS2)                        */
#define CVTRV318    0x08            /* ... RESERVED (OS/VS2)                        */
#define CVTUSR      0x04            /* ... TRACE=USR SPECIFIED.  USER-REQUESTED TRACE*/
                                    /*     DATA IS TO BE INCLUDED IN THE TRACE DATA */
                                    /*     SET.                                     */
#define CVTRNIO     0x02            /* ... GTF IS ACTIVE AND TRACING RNIO EVENTS    */
#define CVTRSV27    0x              /* ... RESERVED                                 */

    unsigned char   cvtgtfa[3];     /* ED ADDRESS OF MAIN MONITOR CALL ROUTING      */
                                    /*    TABLE, MCHEAD  (OS/VS2)                   */

    /* CVTAQAVT DS    0A -          /* F0 ADDRESS OF THE FIRST WORD OF THE TCAM     */
                                    /*    DISPATCHER WHICH CONTAINS THE ADDRESS OF  */
                                    /*    THE ADDRESS VECTOR TABLE (AVT).  IF ZERO, */
                                    /*    TCAM IS NOT STARTED.                      */
    unsigned char   cvttcmfg;       /* F0 TCAM FLAGS                                */
#define CVTTCRDY    0x80            /* ... TCAM IS READY TO ACCEPT USERS            */
#define CVTLDEV     0x40            /* ... LOCAL DEVICE ATTACHED TO TCAM            */
#define CVTRSV29    0x20            /* ... RESERVED                                 */
#define CVTRSV30    0x10            /* ... RESERVED                                 */
#define CVTRSV31    0x08            /* ... RESERVED                                 */
#define CVTRSV32    0x04            /* ... RESERVED                                 */
#define CVTRSV33    0x02            /* ... RESERVED                                 */
#define CVTRSV34    0x01            /* ... RESERVED                                 */
    unsigned char   cvtaqavb[3];    /* F1 SAME AS CVTAQAVT ABOVE                    */

    /* CVTVOLM2 DS    0A -          ADDRESS OF TABLE FOR POWER WARNING FEATURE      */
                                    /* (PWF)  (OS/VS2)  (MDC308)                    */
    unsigned char   cvtvolf2;       /* F4 PWF FLAG BYTE.  THIS BYTE IS OVERLAID BY  */
                                    /*    CVTVOLM2 AFTER PWF INITIALIZATION.        */
#define CVTVOLI2    0x80            /* ... PWF INITIALIZATION HAS NOT OCCURRED      */
    unsigned char   cvtvolt2[3];    /* F5 PWF RECHECK TIME DELAY.  THIS VALUE IS    */
                                    /*    OVERLAID BY CVTVOLM2 AFTER PWF            */
                                    /*    INITIALIZATION. (OS/VS2)                  */
    unsigned        reserved;       /* F8 RESERVED  (OS/VS2)                        */

    CVTXTNT1        *cvtext1;       /* FC ADDRESS OF OS - OS/VS COMMON EXTENSION    */

    void            *cvtcbsp;       /* 100 ADDRESS OF ACCESS METHOD CONTROL BLOCK   */
                                    /*     STRUCTURE                                */

    void            *cvtpurg;       /* 104 ADDRESS OF SUBSYSTEM PURGE ROUTINE       */
    unsigned        cvtamff;        /* 108 RESERVED FOR ACCESS METHOD FLAGS         */
    void            *cvtqmsg;       /* 10C ADDRESS OF INFORMATION TO BE PRINTED     */
                                    /*     BY ABEND                                 */

    /* CVTDMSR  DS    0A -          SAME AS CVTDMSRA BELOW                          */
    unsigned char   cvtdmsrf;       /* 110 OPEN/CLOSE/EOV FLAG BYTE.  SETTING BOTH  */
                                    /*     BIT 0 AND BIT 1 ON WILL CAUSE BOTH KINDS */
                                    /*     OF DUMPS TO BE TAKEN.  THESE BITS ARE USED */
                                    /*     DURING TESTING AND DEBUGGING WHEN OTHER  */
                                    /*     DEBUG METHODS ARE INEFFECTIVE.  (OS/VS2) */
#define CVTSDUMP    0x80            /* ... SET BY COREZAP.  WILL CAUSE AN SDUMP TO BE */
                                    /*     TAKEN AND IEC999I MESSAGE ISSUED FOR EVERY */
                                    /*     ABEND ISSUED WITHIN AN OPEN/CLOSE/EOV OR */
                                    /*     DADSM FUNCTION. (OS/VS2)                 */
#define CVTUDUMP    0x40            /* ... SET BY COREZAP.  WILL CAUSE AN ABEND DUMP */
                                    /*     TO BE TAKEN FOR EVERY ABEND ISSUED WITHIN */
                                    /*     AN OPEN/CLOSE/EOV OR DADSM FUNCTION.     */
#define CVTRV629    0x20            /* ... RESERVED (OS/VS2)                        */
#define CVTRV630    0x10            /* ... RESERVED (OS/VS2)                        */
#define CVTRV631    0x08            /* ... RESERVED (OS/VS2)                        */
#define CVTRV632    0x04            /* ... RESERVED (OS/VS2)                        */
#define CVTRV633    0x02            /* ... RESERVED (OS/VS2)                        */
#define CVTRV634    0x01            /* ... RESERVED (OS/VS2)                        */
    unsigned char   cvtdmsra[3];    /* 111 ADDRESS OF THE OPEN/CLOSE/EOV SUPERVISORY*/
                                    /*     ROUTINE IN THE NUCLEUS.  THIS ROUTINE    */
                                    /*     HANDLES THE ROUTING OF CONTROL AMONG THE */
                                    /*     I/O SUPPORT ROUTINES.                    */

    unsigned        cvtrsv38;       /* 114 RESERVED                                 */
    unsigned        cvtrsv39;       /* 118 RESERVED                                 */

    /*              OS/VS1 - OS/VS2 COMMON SECTION                                  */

    void            *cvtreal;       /* 11C ADDRESS OF THE VIRTUAL STORAGE BYTE      */
                                    /*     FOLLOWING THE HIGHEST VIRTUAL=REAL       */
                                    /*     STORAGE ADDRESS                          */
    void            *cvtptrv;       /* 120 ADDRESS OF PAGING SUPERVISOR GENERAL     */
                                    /*     ROUTINE TO TRANSLATE REAL ADDRESSES TO   */
                                    /*     VIRTUAL ADDRESSES                        */
    unsigned        reserved2;      /* 124 RESERVED (WAS CVTMODE) (OS/VS2)          */
    void            *cvtjesct;      /* 128 ADDRESS OF JOB ENTRY SUBSYSTEM (JES)     */
                                    /*     CONTROL TABLE                            */
    unsigned        reserved3;      /* 12C RESERVED (WAS CVTJEPS) (OS/VS2)          */

    int             cvttz;          /* 130 DIFFERENCE BETWEEN LOCAL TIME AND        */
                                    /*     GREENWICH MEAN TIME IN BINARY UNITS OF   */
                                    /*     1.048576 SECONDS                         */
    void            *cvtmchpr;      /* 134 ADDRESS OF MACHINE CHECK PARAMETER LIST  */
    void            *cvteorm;       /* 138 POTENTIAL REAL HIGH STORAGE ADDRESS (OS/VS2) */
    void            *cvtrv517;      /* 13C ** CVTERPV FIELD UNUSED IN MVS **        */
    void            *cvtrv518;      /* 140 ** CVTINTLA FIELD UNUSED IN MVS **       */

    void            *cvtapf;        /* 144 ADDRESS OF BRANCH ENTRY POINT IN         */
                                    /*     AUTHORIZED PROGRAM FACILITY (APF) ROUTINE*/
    CVTXTNT2        *cvtext2;       /* 148 ADDRESS OF OS/VS1 - OS/VS2 COMMON        */
                                    /*     EXTENSION                                */

    void            *cvthjes;       /* 14C ADDRESS OF OPTIONAL JOB ENTRY SUBSYSTEM  */
                                    /*     (JES) COMMUNICATION VECTOR TABLE         */
    unsigned short  cvtrsv43;       /* 150 RESERVED                                 */
    unsigned short  cvtrsv44;       /* 152 RESERVED                                 */
    unsigned        cvtrsv45;       /* 154 RESERVED                                 */
    unsigned        cvtrsv46;       /* 158 RESERVED                                 */

    /*              OS/VS2 OVERLAY                                                  */

    void            *cvtgetl;       /* 15C ADDRESS OF IKJGETL, TSO GET LINE ROUTINE */
    void            *cvtlpdsr;      /* 160 ADDRESS OF LINK PACK AREA (LPA) DIRECTORY*/
                                    /*     SEARCH ROUTINE                           */
    void            *cvtpvtp;       /* 164 ADDRESS OF PAGE VECTOR TABLE             */
    void            *cvtlpdia;      /* 168 ADDRESS OF LINK PACK AREA (LPA) DIRECTORY*/
                                    /*     (ON PAGE BOUNDARY)                       */
    void            *cvtpsad0;      /* 16C PSA PROTECT DISABLE                      */
    void            *cvtpsae0;      /* 170 PSA PROTECT ENABLE                       */
    /* CVTSLIDA DS    0CL4 -        IDENTITY OF TCB CAUSING SUPERVISOR LOCK         */
    /*                              BYTE (CVTSYLK) TO BE SET OR IDENTITY OF         */
    /*                              TCB THAT SECOND EXIT PROCESSING IS FOR          */
    /*                               WHEN CVTSEIC=1                                 */
    unsigned char   cvtsylk;        /* 174 SUPERVISOR LOCK.  ONLY ENABLED TASKS MAY */
                                    /*     BE DISPATCHED                            */
#define CVTSYLKS    0xFF            /* ... SET LOCK BYTE                            */
#define CVTSYLKR    0x00            /* ... RESET LOCK BYTE                          */
    unsigned char   cvtslid[3];     /* 175 SAME AS CVTSLIDA ABOVE                   */

    unsigned        cvtrv322;       /* 178 RESERVED FOR FUTURE USE                  */
    unsigned        cvtrv328;       /* 17C ** CVTSEG AND CVTSEGA FIELDS UNUSED IN   */
                                    /*     MVS **                                   */
    void            *cvtvldwt;      /* 180 ADDRESS OF STOP/RESTART INTERFACE ROUTINE*/
    unsigned        cvtexslf;       /* 184 F'20000000' EXCESSIVE SPIN LENGTH FACTOR */
    void            *cvtexsnr;      /* 188 ADDRESS OF EXCESSIVE SPIN NOTIFICATION   */
                                    /*     ROUTINE                                  */
    unsigned char   cvtexsnl;       /* 18C SERIALIZATION BYTE FOR EXCESSIVE SPIN    */
                                    /*     NOTIFICATION ROUTINE                     */
    unsigned char   cvtspvlk;       /* 18D NUMBER OF TASKS WHICH HAVE TERMINATED    */
                                    /*     WHILE OWNING SUPERVISOR LOCK WITHOUT     */
                                    /*     OPERATOR HAVING YET BEEN NOTIFIED        */
    unsigned char   cvtctlfg;       /* 18E SYSTEM CONTROL FLAGS                     */
#define CVTRV323    0x80            /* ... ** CVTPSIC BIT UNUSED IN MVS **          */
#define CVTRV333    0x40            /* ... ** CVTAPGB BIT UNUSED IN MVS **          */
#define CVTRSV78    0x20            /* ... RESERVED                                 */
#define CVTDSTAT    0x10            /* ... DEVSTAT OPTION IN EFFECT.  DEVICE ADDRESS*/
                                    /*     FOR 2319, 3330, 2314, 3330-1, 3340 CAN   */
                                    /*     VARY ACROSS SYSTEMS                      */
#define CVTRSV79    0x08            /* ... RESERVED                                 */
#define CVTNOMP     0x04            /* ... MULTIPROCESSING CODE IS NOT IN THE SYSTEM*/
#define CVTGTRCE    0x02            /* ... GENERALIZED TRACE FACILITY (GTF) HAS     */
                                    /*     SUPPRESSED SUPERVISOR TRACE              */
#define CVTSDTRC    0x01            /* ... SVC DUMP HAS SUPPRESSED SUPERVISOR TRACE */

    unsigned char   cvtapg;         /* 18F DISPATCHING PRIORITY OF AUTOMATIC PRIORITY */
                                    /*     GROUP (APG)                              */
    unsigned short  cvttrace;       /* 190 BR 11 BRANCH ON REGISTER INSTRUCTION.  SET BY */
                                    /*     NIP.  REGISTER TEN FOR TRACE.  REGISTER  */
                                    /*     ELEVEN FOR NO TRACE.                     */
    unsigned short  cvttrac2;       /* 192 BR 11 THIS ALLOWS FOR SUPPRESSING TRACE  */
                                    /*     DYNAMICALLY BY SETTING CONDITION CODE    */
                                    /*     MASK TO ZERO IN FIRST INSTRUCTION        */
                                    /*     (CVTTRACE)                               */
    void            *cvtrscn;       /* 194 ADDRESS OF ROUTINE TO SCAN TCB TREE      */
    void            *cvttas;        /* 198 ADDRESS OF ROUTINE TO TRANSFER ADDRESS   */
                                    /*     SPACE                                    */
    void            *cvtrv332;      /* 19C ** CVTPVALD FIELD UNUSED IN MVS **       */

    void            *cvtshrvm;      /* 1A0 LOWEST ADDRESS OF SHARED VIRTUAL STORAGE */
                                    /*     AREA.  THIS ADDRESS WILL BE THE BEGINNING*/
                                    /*     OF THE COMMON SERVICE AREA (CSA)         */
    void            *cvt0vl01;      /* 1A4 ENTRY POINT ADDRESS OF VALIDITY CHECK    */
                                    /*     ROUTINE (IEA0VL01) USED TO COMPARE       */
                                    /*     PROTECT KEY OF AN ADDRESS WITH TCB       */
                                    /*     PROTECT KEY                              */
    void            *cvtppgmx;      /* 1A8 ADDRESS OF A BRANCH ENTRY POINT          */
                                    /*     TO PROGRAM MANAGER RESOURCE              */
                                    /*     MANAGEMENT ROUTINES                      */
    void            *cvtrv325;      /* 1AC ** CVTPFIXR FIELD UNUSED IN MVS **       */
    void            *cvtrv326;      /* 1B0 ** CVTPFIXP FIELD UNUSED IN MVS **       */
    void            *cvtascrf;      /* 1B4 CREATED ASCB QUEUE HEADER                */
    void            *cvtascrl;      /* 1B8 CREATED ASCB QUEUE TRAILER               */
    void            *cvtputl;       /* 1BC ADDRESS OF IKJPUTL, TSO PUT LINE ROUTINE */
    void            *cvtsrbrt;      /* 1C0 DISPATCHER RETURN ADDRESS FOR SRB ROUTINES */
    void            *cvtolt0a;      /* 1C4 BRANCH ENTRY TO OLTEP MEMORY TERMINATION */
                                    /*     RESOURCE MANAGER                         */
    void            *cvtsmfex;      /* 1C8 BRANCH ENTRY TO SYSTEM MANAGEMENT        */
                                    /*     FACILITIES (SMF) EXCP COUNTING ROUTINE   */
                                    /*     FOR VAM WINDOW INTERCEPT                 */
    void            *cvtcspie;      /* 1CC FOR CHECKPOINT/RESTART, BRANCH ENTRY TO  */
                                    /*     SPIE                                     */
    void            *cvtptgt;       /* 1D0 ADDRESS OF IKJPTGT, TSO PUTGET ROUTINE   */
    unsigned char   cvtiospl;       /* 1D4 PRIORITY LEVEL OF I/O SUPERVISOR CHANNEL */
                                    /*     SCHEDULER                                */
    unsigned char   cvtrv513;       /* 1D5 RESERVED                                 */
    unsigned char   cvtdssac;       /* 1D6 DYNAMIC SUPPORT SYSTEM (DSS) ACTIVATED   */
                                    /*     FLAG - USED BY RESTART FLIH.  IF X'00',  */
                                    /*     DSS NOT INITIALIZED.  IF X'FF', DSS HAS  */
                                    /*     BEEN INITIALIZED.                        */
    unsigned char   cvtrv139;       /* 1D7 RESERVED                                 */
    void            *cvtstck;       /* 1D8 ADDRESS OF IKJSTCK, TSO STACK ROUTINE    */
    unsigned short  cvtmaxmp;       /* 1DC FOR MEASUREMENT FACILITY (MF/1), MAXIMUM */
                                    /*     PHYSICAL CPU ADDRESS SUPPORTED BY THIS   */
                                    /*     RELEASE                                  */
    unsigned short  cvtrv144;       /* 1DE RESERVED                                 */
    void            *cvtscan;       /* 1E0 ADDRESS OF IKJSCAN, TSO SCAN ROUTINE     */
    void            *cvtauthl;      /* 1E4 POINTER TO AUTHORIZED LIBRARY TABLE      */
    void            *cvtbldcp;      /* 1E8 BRANCH ENTRY TO BUILD POOL               */
    void            *cvtgetcl;      /* 1EC BRANCH ENTRY TO GET CELL                 */
    void            *cvtfrecl;      /* 1F0 BRANCH ENTRY TO FREE CELL                */
    void            *cvtdelcp;      /* 1F4 BRANCH ENTRY TO DELETE POOL              */
    void            *cvtcrmn;       /* 1F8 BRANCH ENTRY TO SVC 120 (GETMAIN/FREEMAIN*/
                                    /*     CRBRANCH)                                */
    void            *cvtcras;       /* 1FC BRANCH ENTRY TO 'CREATE ADDRESS SPACE'   */
    void            *cvtqsas;       /* 200 BRANCH ENTRY TO TASK TERMINATION         */
    void            *cvtfras;       /* 204 BRANCH ENTRY TO 'FREE ADDRESS SPACE'     */
    void            *cvts1ee;       /* 208 BRANCH ENTRY TO STAGE 1 EXIT EFFECTOR    */
    void            *cvtpars;       /* 20C ADDRESS OF IKJPARS, TSO PARSE ROUTINE    */
    void            *cvtquis;       /* 210 BRANCH ENTRY TO QUIESCE                  */
    void            *cvtstxu;       /* 214 BRANCH ENTRY TO ATTENTION EXIT EPILOGUE  */
    void            *cvtopte;       /* 218 BRANCH ENTRY ADDRESS TO SYSEVENT         */
    void            *cvtsdrm;       /* 21C BRANCH ENTRY ADDRESS OF THE RESOURCE     */
                                    /*     MANAGER ROUTINE FOR SVC DUMP.  THIS      */
                                    /*     ROUTINE CAN BE INVOKED BY MEMORY         */
                                    /*     TERMINATION                              */
    void            *cvtioscs;      /* 220 ENTRY POINT OF I/O SUPERVISOR CHANNEL    */
                                    /*     SCHEDULER                                */
    void            *cvtaqtop;      /* 224 POINTER TO AREA CONTAINING QUIESCE       */
                                    /*     DESCRIPTOR BLOCK (QDB'S) FOR DEVICE      */
                                    /*     ALLOCATION                               */
    void            *cvtvvmdi;      /* 228 CONSTANT USED BY PAGED LINK PACK AREA    */
                                    /*     (LPA) DIRECTORY SEARCH ALGORITHM         */
    void            *cvtasvt;       /* 22C POINTER TO ADDRESS SPACE VECTOR TABLE    */
                                    /*     (ASVT)                                   */
    void            *cvtgda;        /* 230 POINTER TO GLOBAL DATA AREA (GDA) IN SQA */
    void            *cvtascbh;      /* 234 POINTER TO HIGHEST PRIORITY ADDRESS SPACE*/
                                    /*     CONTROL BLOCK (ASCB) ON THE ASCB         */
                                    /*     DISPATCHING QUEUE (HEAD OF ASCB QUEUE)   */
    void            *cvtascbl;      /* 238 POINTER TO LOWEST PRIORITY ASCB ON THE   */
                                    /*     ASCB DISPATCHING QUEUE                   */
    void            *cvtrtmct;      /* 23C POINTER TO RECOVERY/TERMINATION CONTROL  */
                                    /*     TABLE                                    */
    void            *cvtsv60;       /* 240 ADDRESS OF SVC 60 BRANCH ENTRY POINT     */
    void            *cvtsdmp;       /* 244 ADDRESS OF SVC DUMP BRANCH ENTRY POINT   */
    void            *cvtscbp;       /* 248 ADDRESS OF SCB PURGE RESOURCE MANAGER    */
    void            *cvtsdbf;       /* 24C ADDRESS OF 4K SQA BUFFER USED BY SVC     */
                                    /*     DUMP.  HIGH-ORDER BIT OF THIS CVT WORD   */
                                    /*     IS USED AS LOCK TO INDICATE BUFFER IS    */
                                    /*     IN USE                                   */
    void            *cvtrtms;       /* 250 ADDRESS OF SERVICABILITY LEVEL INDICATOR */
                                    /*     PROCESSING (SLIP) HEADER                 */
    void            *cvttpios;      /* 254 ADDRESS OF THE TELEPROCESSING I/O        */
                                    /*     SUPERVISOR ROUTINE (TPIOS)               */
    void            *cvtsic;        /* 258 BRANCH ADDRESS OF THE ROUTINE TO SCHEDULE*/
                                    /*     SYSTEM INITIALIZED CANCEL                */
    void            *cvtopctp;      /* 25C ADDRESS OF SYSTEM RESOURCES MANAGER (SRM)*/
                                    /*     CONTROL TABLE                            */
    void            *cvtexpro;      /* 260 ADDRESS OF EXIT PROLOGUE/TYPE 1 EXIT     */
    void            *cvtgsmq;       /* 264 ADDRESS OF GLOBAL SERVICE MANAGER QUEUE  */
    void            *cvtlsmq;       /* 268 ADDRESS OF LOCAL SERVICE MANAGER QUEUE   */
    void            *cvtgspl;       /* 26C ADDRESS OF GLOBAL SYSTEM PRIORITY LIST   */
                                    /*     QUEUE                                    */
    void            *cvtvwait;      /* 270 ADDRESS OF WAIT ROUTINE                  */
    void            *cvtparrl;      /* 274 ADDRESS OF PARTIALLY LOADED DELETE QUEUE */
    void            *cvtapft;       /* 278 ADDRESS OF AUTHORIZED PROGRAM FACILITY   */
                                    /*     (APF) TABLE.  INITIALIZED BY NIP.        */
    void            *cvtqcs01;      /* 27C BRANCH ENTRY ADDRESS TO PROGRAM MANAGER  */
                                    /*     USED BY ATTACH                           */
    void            *cvtfqcb;       /* 280 POINTER TO FIRST MAJOR QCB FOR ENQ       */
    void            *cvtlqcb;       /* 284 POINTER TO LAST MAJOR QCB FOR ENQ        */
    void            *cvtrenq;       /* 288 RESOURCE MANAGER ADDRESS FOR ENQ         */
    void            *cvtrspie;      /* 28C RESOURCE MANAGER FOR SPIE                */
    void            *cvtlkrma;      /* 290 RESOURCE MANAGER ADDRESS FOR LOCK MANAGER*/
    void            *cvtcsd;        /* 294 VIRTUAL ADDRESS OF COMMON SYSTEM DATA    */
                                    /*     AREA (CSD).  INITIALIZED BY NIP.         */
    void            *cvtdqiqe;      /* 298 RESOURCE MANAGER FOR EXIT EFFECTORS      */
    void            *cvtrpost;      /* 29C RESOURCE MANAGER FOR POST                */
    void            *cvt062r1;      /* 2A0 BRANCH ENTRY TO DETACH                   */
    void            *cvtveac0;      /* 2A4 ASCBCHAP BRANCH ENTRY                    */
    void            *cvtglmn;       /* 2A8 GLOBAL BRANCH ENTRY ADDRESS FOR          */
                                    /*     GETMAIN/FREEMAIN                         */
    void            *cvtspsa;       /* 2AC POINTER TO GLOBAL WORK/SAVE AREA VECTOR  */
                                    /*     TABLE (WSAG)                             */
    void            *cvtwsal;       /* 2B0 ADDRESS OF TABLE OF LENGTHS OF LOCAL     */
                                    /*     WORK/SAVE AREAS                          */
    void            *cvtwsag;       /* 2B4 ADDRESS OF TABLE OF LENGTHS OF GLOBAL    */
                                    /*     WORK/SAVE AREAS                          */
    void            *cvtwsac;       /* 2B8 ADDRESS OF TABLE OF LENGTHS OF CPU       */
                                    /*     WORK/SAVE AREAS                          */
    void            *cvtrecrq;      /* 2BC ADDRESS OF THE RECORDING REQUEST FACILITY*/
                                    /*     (PART OF RTM1 - CALLED BY RTM2 AND RMS)  */
    void            *cvtasmvt;      /* 2C0 POINTER TO AUXILIARY STORAGE MANAGEMENT  */
                                    /*     VECTOR TABLE (AMVT)                      */
    void            *cvtiobp;       /* 2C4 ADDRESS OF THE BLOCK PROCESSOR CVT       */
    void            *cvtspost;      /* 2C8 POST RESOURCE MANAGER TERMINATION ROUTINE*/
                                    /*     (RMTR) ENTRY POINT                       */
    void            *cvtrstwd;      /* 2CC RESTART RESOURCE MANAGEMENT WORD -       */
                                    /*     CONTAINS IDENTIFIER OF USER IF RESTART IS*/
                                    /*     IN USE.  OTHERWISE, ZERO.                */
    void            *cvtfetch;      /* 2D0 ADDRESS OF ENTRY POINT FOR BASIC FETCH   */
    void            *cvt044r2;      /* 2D4 ADDRESS OF IGC044R2 IN CHAP SERVICE      */
                                    /*     ROUTINE                                  */
    void            *cvtperfm;      /* 2D8 ADDRESS OF THE PERFORMANCE WORK AREA.    */
                                    /*     SET BY IGX00018.                         */
    void            *cvtdair;       /* 2DC ADDRESS OF IKJDAIR, TSO DYNAMIC          */
                                    /*     ALLOCATION INTERFACE ROUTINE             */
    void            *cvtehdef;      /* 2E0 ADDRESS OF IKJEHDEF, TSO DEFAULT SERVICE */
                                    /*     ROUTINE                                  */
    void            *cvtehcir;      /* 2E4 ADDRESS OF IKJEHCIR, TSO CATALOG         */
                                    /*     INFORMATION ROUTINE                      */
    void            *cvtssap;       /* 2E8 ADDRESS OF SYSTEM SAVE AREA              */
    void            *cvtaidvt;      /* 2EC POINTER TO APPENDAGE ID VECTOR TABLE     */
    void            *cvtipcds;      /* 2F0 BRANCH ENTRY FOR DIRECT SIGNAL           */
                                    /*     SERVICE ROUTINE                          */
    void            *cvtipcri;      /* 2F4 BRANCH ENTRY FOR REMOTE IMMEDIATE        */
                                    /*     SIGNAL SERVICE ROUTINE                   */
    void            *cvtipcrp;      /* 2F8 BRANCH ENTRY FOR REMOTE PENDABLE         */
                                    /*     SIGNAL SERVICE ROUTINE                   */
    void            *cvtpccat;      /* 2FC POINTER TO PHYSICAL CCA VECTOR TABLE     */
    void            *cvtlccat;      /* 300 POINTER TO LOGICAL CCA VECTOR TABLE      */
    unsigned char   cvtrv210;       /* 304 RESERVED                                 */
    unsigned char   cvtrv219;       /* 305 RESERVED                                 */
    unsigned char   cvtrv228;       /* 306 RESERVED                                 */
    unsigned char   cvtrv237;       /* 307 RESERVED                                 */
    unsigned char   cvtrv246;       /* 308 RESERVED                                 */
    unsigned char   cvtrv247;       /* 309 RESERVED                                 */
    unsigned char   cvtrv248;       /* 30A RESERVED                                 */
    unsigned char   cvtrv249;       /* 30B RESERVED                                 */
    unsigned char   cvtrv250;       /* 30C RESERVED                                 */
    unsigned char   cvtrv251;       /* 30D RESERVED                                 */
    unsigned short  cvtrv252;       /* 30E RESERVED                                 */
    unsigned short  cvtrv253;       /* 310 RESERVED                                 */
    unsigned short  cvtrv254;       /* 312 RESERVED                                 */
    void            *cvtpwi;        /* 314 ADDRESS OF THE WINDOW INTERCEPT ROUTINE  */
    void            *cvtpvbp;       /* 318 ADDRESS OF THE VIRTUAL BLOCK PROCESSOR   */
    void            *cvtmfctl;      /* 31C POINTER TO MEASUREMENT FACILITY CONTROL  */
                                    /*     BLOCK                                    */
    void            *cvtmfrtr;      /* 320 IF MEASUREMENT FACILITY IS ACTIVE,       */
                                    /*     CONTAINS ADDRESS OF MEASUREMENT FACILITY */
                                    /*     ROUTINE.  OTHERWISE, ADDRESS OF CVTBRET. */
#define CVTMFACT    0x80            /* ... IF ONE, I/O SUPERVISOR AND TIMER SECOND  */
                                    /*     LEVEL INTERRUPT HANDLER HOOKS BRANCH     */
                                    /*     TO MEASUREMENT FACILITY ROUTER.  USED TO */
                                    /*     SET HIGH-ORDER BIT OF CVTMFRTR.          */
    void            *cvtvpsib;      /* 324 BRANCH ENTRY TO PAGE SERVICES            */
    void            *cvtvsi;        /* 328 BRANCH ENTRY TO VAM SERVICES             */
    void            *cvtvfp;        /* 32C BRANCH ENTRY TO FINDPAGE                 */
    unsigned char   cvtrv262;       /* 330 RESERVED                                 */
    unsigned char   cvtrv271;       /* 331 RESERVED                                 */
    unsigned char   cvtrv280;       /* 332 RESERVED                                 */
    unsigned char   cvtrv289;       /* 333 RESERVED                                 */
    void            *cvttrca;       /* 334 ADDRESS OF TRACE TABLE HEADER            */
    unsigned short  cvtrv302;       /* 338 RESERVED                                 */
    unsigned short  cvtrv303;       /* 33A RESERVED                                 */
    unsigned short  cvtrv304;       /* 33C RESERVED                                 */
    unsigned short  cvtrv305;       /* 33E RESERVED                                 */
    unsigned short  cvtrv306;       /* 340 RESERVED                                 */
    unsigned short  cvtrv307;       /* 342 RESERVED                                 */
    void            *cvtviop;       /* 344 ENTRY POINT OF PAGE I/O POST             */
    void            *cvtrmbr;       /* 348 ADDRESS OF REGMAIN BRANCH ENTRY          */
    void            *cvtlfrm;       /* 34C LIST FORMAT FREEMAIN BRANCH ENTRY POINT  */
    void            *cvtgmbr;       /* 350 LIST FORMAT GETMAIN BRANCH ENTRY POINT   */
    void            *cvt0tc0a;      /* 354 ADDRESS OF TASK CLOSE MODULE IFG0TC0A    */
    unsigned        cvtrlstg;       /* 358 SIZE OF ACTUAL REAL STORAGE ONLINE AT    */
                                    /*     IPL TIME IN 'K'.  VALUE PLACED HERE BY   */
                                    /*     IEAVNIP0.                                */
    void            *cvtspfrr;      /* 35C 'SUPER FRR' ADDRESS (ADDRESS OF FUNCTIONAL*/
                                    /*     RECOVERY ROUTINE ESTABLISHED AT NIP0 TIME*/
                                    /*     TO PROTECT SUPERVISOR CONTROL PROGRAM)   */
    void            *cvtvems0;      /* 360 ADDRESS OF MEMORY SWITCH ROUTINE         */
    void            *cvtjrecm;      /* 364 ADDRESS OF SUBSYSTEM INTERFACE RESOURCE  */
                                    /*     MANAGER                                  */
    void            *cvtirecm;      /* 368 ADDRESS OF INITIATOR RESOURCE MANAGER    */
    void            *cvtdarcm;      /* 36C ADDRESS OF DEVICE ALLOCATION RESOURCE    */
                                    /*     MANAGER                                  */
    void            *cvt0pt02;      /* 370 ADDRESS OF POST ENTRY POINT IEA0PT02     */
    void            *cvtstprs;      /* 374 ENTRY POINT OF STOP AND RESTART          */
                                    /*     SUBROUTINE                               */
    void            *cvtwtcb;       /* 378 ADDRESS OF WAIT STATE TCB                */
    void            *cvtvacr;       /* 37C ACR/VARY CPU CHANNEL RECOVERY ROUTINE    */
                                    /*     ADDRESS.  ADDRESS FILLED IN BY VARY CPU  */
                                    /*     PROCESSOR.                               */
    void            *cvtquit;       /* 380 VARY CPU SHUTDOWN ROUTINE ADDRESS.       */
                                    /*     ADDRESS FILLED IN BY VARY CPU PROCESSOR. */
    void            *cvtgtfr8;      /* 384 GENERALIZED TRACE FACILITY (GTF) CONTROL */
                                    /*     REGISTER 8 INITIALIZATION ROUTINE ADDRESS*/
    void            *cvtvstop;      /* 388 ADDRESS OF VARY CPU STOP CPU ROUTINE     */
    void            *cvtvpsa;       /* 38C ADDRESS OF COPY OF SYSGEN'ED PSA - PLACED*/
                                    /*     HERE BY NIP                              */
    void            *cvtrmptt;      /* 390 ADDRESS OF ISTRAMA1, THE VTAM RESOURCE   */
                                    /*     MANAGER FOR NORMAL AND ABNORMAL TASK     */
                                    /*     TERMINATION                              */
    void            *cvtrmpmt;      /* 394 ADDRESS OF ISTRAMA2, THE VTAM RESOURCE   */
                                    /*     MANAGER FOR NORMAL AND ABNORMAL MEMORY   */
                                    /*     TERMINATION                              */
    void            *cvtexp1;       /* 398 ADDRESS OF EXIT PROLOGUE WHICH RETURNS TO*/
                                    /*     THE DISPATCHER                           */
    void            *cvtcsdrl;      /* 39C REAL ADDRESS OF COMMON SYSTEM DATA AREA  */
                                    /*     (CSD).  INITIALIZED BY NIP.              */
    void            *cvtssrb;       /* 3A0 STATUS STOP SRB ENTRY                    */
    void            *cvtrpt;        /* 3A4 ADDRESS OF IGARPT01 MODULE OF RADIX      */
                                    /*     PARTITION TREE SERVICES.  INITIALIZED    */
                                    /*     BY NIP.                                  */
    void            *cvtqv1;        /* 3A8 ADDRESS OF QUEUE VERIFICATION FOR SINGLE */
                                    /*     THREADED QUEUES WITH HEADERS ONLY        */
    void            *cvtqv2;        /* 3AC ADDRESS OF QUEUE VERIFICATION FOR SINGLE */
                                    /*     THREADED QUEUES WITH HEADER AND TRAILER  */
    void            *cvtqv3;        /* 3B0 ADDRESS OF QUEUE VERIFICATION FOR DOUBLE */
                                    /*     THREADED QUEUES                          */
    void            *cvtgsda;       /* 3B4 ADDRESS OF GLOBAL SYSTEM DUPLEX AREA.    */
                                    /*     ADDRESS FILLED IN BY NIP0.               */
#define CVTGSDAB    0x80            /* ... IF HIGH-ORDER BIT IS ONE, THERE IS A VALID */
                                    /*     VALUE IN FOLLOWING 31 BITS               */
    void            *cvtadv;        /* 3B8 ADDRESS OF ADDRESS VERIFICATION ROUTINE  */
    void            *cvttpio;       /* 3BC ADDRESS OF VTAM TPIO (SVC 124) ROUTINE   */
    void            *cvtcrca;       /* 3C0 WHEN CHANNEL RECONFIGURATION HARDWARE    */
                                    /*     (CRH) IS ACTIVE, ADDRESS OF CRH          */
                                    /*     COMMUNICATION AREA IECVCRCA.             */
                                    /*     OTHERWISE, ZERO.                         */
    void            *cvtevent;      /* 3C4 BRANCH ENTRY ADDRESS TO EVENTS (FAST     */
                                    /*     MULTIPLE WAIT ROUTINE)                   */
    void            *cvtsscr;       /* 3C8 ADDRESS OF STORAGE SYSTEM CONTROLLER     */
                                    /*     RECOVERY MANAGER CLEANUP ROUTINE         */
                                    /*     (SSC RMCR)                               */
    void            *cvtcbbr;       /* 3CC BRANCH ENTRY ADDRESS TO GETMAIN/FREEMAIN */
    void            *cvteff02;      /* 3D0 ADDRESS OF IKJEFF02, TSO MESSAGE ISSUER  */
                                    /*     SERVICE ROUTINE                          */
    void            *cvtrv604;      /* 3D4 RESERVED                                 */
    void            *cvtrv605;      /* 3D8 RESERVED                                 */
    void            *cvthsm;        /* 3DC POINTER TO HIERARCHICAL STORAGE MANAGER  */
                                    /*     (HSM) QUEUE CONTROL TABLE                */
    void            *cvtrac;        /* 3E0 ADDRESS OF ACCESS CONTROL CVT            */
    void            *cvtcgk;        /* 3E4 ADDRESS OF ROUTINE USED TO CHANGE THE KEY*/
                                    /*     OF VIRTUAL PAGES                         */
    void            *cvtrv609;      /* 3E8 RESERVED                                 */
    void            *cvt0pt0e;      /* 3EC ENTRY POINT TO IDENTIFY POST EXIT ROUTINES */
    void            *cvt0pt03;      /* 3F0 POST REINVOCATION ENTRY POINT FROM POST  */
                                    /*     EXIT ROUTINES                            */
    void            *cvttcasp;      /* 3F4 RESERVED FOR FUTURE USE                  */
    void            *cvtasmrm;      /* 3F8 ADDRESS OF AUXILIARY STORAGE MANAGEMENT  */
                                    /*     RESOURCE MANAGER FOR ADDRESS SPACE       */
                                    /*     TERMINATION                              */
    void            *cvtjterm;      /* 3FC ADDRESS OF AUXILIARY STORAGE MANAGEMENT  */
                                    /*     JOB TERMINATION RESOURCE MANAGER         */
    void            *cvtrsume;      /* 400 ADDRESS OF RESUME FUNCTION               */
    void            *cvttctl;       /* 404 ADDRESS OF TRANSFER CONTROL (TCTL)       */
                                    /*     FUNCTION                                 */
    void            *cvtcdal;       /* 408 ADDRESS OF COMMON DISPATCHER ACTIVE LIST */
    void            *cvtt6svc;      /* 40C ENTRY POINT ADDRESS FOR TYPE 6 SVC EXIT  */
                                    /*     FUNCTION                                 */
    void            *cvtsusp;       /* 410 ADDRESS OF SUSPEND ROUTINE               */
    void            *cvtihasu;      /* 414 ADDRESS OF BIT STRING                    */
    void            *cvtvdccr;      /* 418 ADDRESS OF DISABLED CONSOLE COMMUNICATION*/
                                    /*     ROUTINE (IEEVDCCR)                       */
    void            *cvtcst;        /* 41C ADDRESS OF CHANNEL SET TABLE (CST)       */
    void            *cvtrv623;      /* 420 RESERVED                                 */
    void            *cvtrv624;      /* 424 RESERVED                                 */
    void            *cvtrv625;      /* 428 RESERVED                                 */
    void            *cvtrv626;      /* 42C RESERVED                                 */
    void            *cvtrv627;      /* 430 RESERVED                                 */
    void            *cvtrv628;      /* 434 RESERVED                                 */
};                                  /* 438 (1080 bytes)                             */

/*              OS - OS/VS COMMON EXTENSION                                         */
/*              ADDRESS OF EXTENSION IS IN CVTEXT1                                  */
struct cvtxtnt1 {
    void            *cvtfachn;      /* 00 ADDRESS OF CHAIN OF DCB FIELD AREAS       */
                                    /*    (ISAM)                                    */
    void            *cvtrsv87;      /* 04 RESERVED                                  */
    void            *cvtrsv88;      /* 08 RESERVED                                  */
};

/*              OS/VS1 - OS/VS2 COMMON EXTENSION                                    */
/*              ADDRESS OF EXTENSION IS IN CVTEXT2                                  */
struct cvtxtnt2 {
    void            *cvtdssv;       /* 00 ADDRESS OF THE DYNAMIC SUPPORT SYSTEM     */
    unsigned char   cvtnucls;       /* 04 IDENTIFICATION OF THE NUCLEUS MEMBER      */
                                    /*    NAME                                      */
    unsigned char   cvtflgbt;       /* 05 FLAG BYTE  (OS/VS1)                       */
#define CVTNPE      0x80            /* ... INDICATES NON-PAGING ENVIRONMENT (VM     */
                                    /* ... HANDSHAKING)  (OS/VS1)                   */
#define CVTVME      0x40            /* ... INDICATES MACHINE IS OPERATING IN VM     */
                                    /*     ENVIRONMENT  (OS/VS1)                    */
#define CVTBAH      0x20            /* ... INDICATES THAT THE VM/370 - OS/VS1 BTAM  */
                                    /*     AUTOPOLL HANDSHAKE IS OPERATIONAL        */
                                    /*     (OS/VS1)                                 */
    unsigned short  cvtrsv91;       /* 06 RESERVED                                  */
    void            *cvtdebvr;      /* 08 ADDRESS OF BRANCH ENTRY POINT OF DEB      */
                                    /*    VALIDITY CHECK ROUTINE                    */
    void            *cvtrsv92;      /* 0C RESERVED                                  */
    void            *cvtrsv93;      /* 10 RESERVED                                  */
    void            *cvtrsv94;      /* 14 RESERVED                                  */
    void            *cvtqida;       /* 18 ADDRESS OF QUEUE IDENTIFICATION (QID)     */
                                    /*    TABLE PREFIX                              */
    void            *cvtoltep;      /* 1C POINTER TO CONTROL BLOCK CREATED BY SVC 59*/
                                    /*    TO POINT TO PSEUDO-DEB'S                  */
    unsigned short  cvtrsv96;       /* 20 RESERVED                                  */
    unsigned short  cvtrsv97;       /* 22 RESERVED                                  */
    unsigned        cvtrsv98;       /* 24 RESERVED                                  */
    void            *cvtccvt;       /* 28 ADDRESS OF CRYPTOGRAPHIC FACILITY CVT     */
    void            *cvtskta;       /* 2C ADDRESS OF STORAGE KEY TABLE (VM          */
                                    /*    HANDSHAKING)  (OS/VS1)                    */
    void            *cvticb;        /* 30 ADDRESS OF MASS STORAGE SYSTEM (MSS)      */
                                    /*    CONTROL BLOCK                             */
    unsigned char   cvtrv400;       /* 34 RESERVED                                  */
    unsigned char   cvtrv409;       /* 35 RESERVED                                  */
    unsigned char   cvtrv418;       /* 36 RESERVED                                  */
    unsigned char   cvtrv419;       /* 37 RESERVED                                  */
    unsigned short  cvtrv420;       /* 38 RESERVED                                  */
    unsigned short  cvtrv421;       /* 3A RESERVED                                  */
    unsigned short  cvtrv422;       /* 3C RESERVED                                  */
    unsigned short  cvtrv423;       /* 3E RESERVED                                  */
    void            *cvtatcvt;      /* 40 POINTER TO VTAM'S CVT                     */
#define CVTATACT    0x80            /* ... IF ON, VTAM IS ACTIVE                    */
    void            *cvtrv425;      /* 44 RESERVED                                  */
    void            *cvtrv426;      /* 48 RESERVED                                  */
    void            *cvtrv427;      /* 4C RESERVED                                  */
    void            *cvtrv428;      /* 50 RESERVED                                  */
    unsigned char   cvtrv429;       /* 54 RESERVED                                  */
    unsigned char   cvtrv438;       /* 55 RESERVED                                  */
    unsigned char   cvtrv447;       /* 56 RESERVED                                  */
    unsigned char   cvtrv448;       /* 57 RESERVED                                  */
    unsigned short  cvtrv449;       /* 58 RESERVED                                  */
    unsigned short  cvtrv450;       /* 5A RESERVED                                  */
    unsigned short  cvtrv451;       /* 5C RESERVED                                  */
    unsigned short  cvtrv452;       /* 5E RESERVED                                  */
    void            *cvtrv453;      /* 60 RESERVED                                  */
    void            *cvtrv454;      /* 64 RESERVED                                  */
    void            *cvtrv455;      /* 68 RESERVED                                  */
    void            *cvtrv456;      /* 6C RESERVED                                  */
    unsigned char   cvtrv457;       /* 70 RESERVED                                  */
    unsigned char   cvtrv466;       /* 71 RESERVED                                  */
    unsigned char   cvtrv475;       /* 72 RESERVED                                  */
    unsigned char   cvtrv476;       /* 73 RESERVED                                  */
    unsigned char   cvtrv477;       /* 74 RESERVED                                  */
    unsigned char   cvtrv478;       /* 75 RESERVED                                  */
    unsigned short  cvtrv479;       /* 76 RESERVED                                  */
    void            *cvtrv480;      /* 78 RESERVED                                  */
    void            *cvtrv481;      /* 7C RESERVED                                  */
    void            *cvtrv482;      /* 80 RESERVED                                  */
};                                  /* 84 (132 bytes)                               */

#endif /* CVT_H */
