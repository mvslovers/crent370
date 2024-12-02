#ifndef IEECUCM_H
#define IEECUCM_H

#include <iezbits.h>

typedef struct ucm      UCM;        /* CVT->CVTCUCB                 */
typedef struct ucm2ext  UCM2EXT;
typedef struct ucmprfx  UCMPRFX;
typedef struct ucmeil   UCMEIL;
typedef struct ucmlist  UCMLIST;    /* ucm->ucmvea, ucm->ucmvel     */
typedef struct ucmexit  UCMEXIT;
typedef struct ucmfexta UCMFEXTA;
typedef struct ucmefext UCMEFEXT;   /* ucmlist->ucmfextp            */
typedef struct ucmpexta UCMPEXTA;   /* ucmfexta->ucmefpex           */

/**********************************************************************
*                                                                     *
*                   UNIT CONTROL MODULE (UCM) BASE                    *
*                                                                     *
**********************************************************************/
struct ucm {
    unsigned        ucmxecb;        /* 00 EXTERNAL INTERRUPT ECB    */
    unsigned        ucmaecb;        /* 04 ATTENTION INTERRUPT ECB   */
    unsigned        ucmoecb;        /* 08 WTO/WTOR REQUEST ECB      */
    union {
        unsigned    ucmdecb;        /* 0C DOM REQUEST ECB           */
        unsigned    ucmlecb;        /* 0C WTL REQUEST ECB           */
    };

    unsigned        ucmarecb;       /* 10 CONSOLE RECOVERY ECB      */
    void            *ucmlstp;       /* 14 ADDRESS OF EVENT INDICATION LIST (EIL) */

/* WTO/WTOR CONTROL FIELDS */

    void            *ucmwtoq;       /* 18 ADDRESS OF FIRST WQE (SYSOUT QUEUE) */
    void            *ucmrpyq;       /* 1C ADDRESS OF FIRST ORE (REPLY-Q ELEMENT) */

    char            ucmrpti[13];    /* 20 REPLY ID ASSIGNMENT PATTERN (100 BITS) */
    char            ucmrqlm;        /* 2D I.D. ASSIGNMENT LIMIT     */
    short           ucmwqlm;        /* 2E WQE BUFFER LIMIT          */

    unsigned        ucmrqecb;       /* 30 REPLY REQUEST WAITING ECB */
    unsigned        ucmwqecb;       /* 34 BUFFER REQUEST WAITING ECB */
    short           ucmrqnr;        /* 38 CURRENT ORE COUNT         */
    short           ucmwqnr;        /* 3A CURRENT WQE COUNT         */
    void            *ucmwqend;      /* 3C ADDRESS OF LAST WQE - OR ZERO */

    void            *ucmpxa;        /* 40 ADDR OF COMMUNICATIONS TASK TCB */
    char            ucmmode;        /* 44 MODE FLAGS                */
#define UCMRSV11    BIT0            /* ... RESERVED                 */
#define UCMRSV66    BIT1            /* ... RESERVED                 */
#define UCMTPUTA    BIT2            /* ... TPUTTER IS ACTIVE (OS/VS2) */
#define UCMRSV14    BIT3            /* ... RESERVED                 */
#define UCMAMFA     BIT4            /* ... ACCEPT 'VARY' CMD W/MSTCONS OPND FROM    
                                    /*     ANY MCS SECONDARY CONSOLE */
#define UCMOGCE     BIT5            /* ... ONLY GRAPHIC CONSOLES ACTIVE */
#define UCMMCS      BIT6            /* ... MCS GENERATED WITH SYSTEM */
#define UCMFIX      BIT7            /* ... CONTROL PROGRAM MODE  
                                    /      (0 = OS/VS2) (1 = OS/VS1) */
    char            ucmrsv74;       /* 45 RESERVED                  */
    char            ucmrsv67;       /* 46 RESERVED                  */
    char            ucmrsv76;       /* 47 RESERVED                  */

/* THE FOLLOWING FIELDS ARE USED FOR ACCESSING UCM INDIVIDUAL
 * DEVICE ENTRIES.  THEY MUST BE DEFINED IN THE ORDER SHOWN.
*/
    union {
        char        ucmvdata[12];   /* 48 UCM ENTRY ACCESSING DATA  */
        struct {
            UCMLIST *ucmvea;        /* 48 ADDRESS OF FIRST UCM ENTRY */
            unsigned ucmvez;        /* 4C LENGTH OF A UCM ENTRY     */
            UCMLIST *ucmvel;        /* 50 ADDRESS OF LAST UCM ENTRY */
        };
    };

/* SAVE AREA FOR REFRESHABILITY ROUTINES */
    char            ucmrsv77[56];   /* 54 RESERVED                  */
    unsigned        ucmsave4[16];   /* 8C SAVE AREA FOR IEAVCTSK    */
    unsigned        ucmr9sv;        /* CC SAVE AREA FOR IEAVMWSV    */

/* THE FIELDS DEFINED FOLLOWING THIS STATEMENT ARE PRESENT       
 * ONLY IN VARIABLE MODE SYSTEMS (OS/VS2)                        
*/
    void            *ucmmntr;       /* D0 ADDRESS OF MONITOR ROUTINE */
    unsigned        ucmmnecb;       /* D4 ECB INDICATING MONITOR TPUTS TO DO */
    unsigned        ucmtrecb;       /* D8 ECB INDICATING TPUTTER SHOULD TERMINATE */
    void            *ucmmqptr;      /* DC POINTER TO FIRST ELEMENT ON 
                                          MONITOR QUEUE             */

    void            *ucmmqend;      /* E0 POINTER TO LAST ELEMENT ON 
                                          MONITOR QUEUE             */
    void            *ucmmqnxt;      /* E4 POINTER TO NEXT ELEMENT ON 
                                          MONITOR QUEUE TO BE PROCESSED */
    void            *ucmmbptr;      /* E8 POINTER TO FIRST ELEMENT ON 
                                          MONITOR MESSAGE BLOCK QUEUE */
    char            ucmrqlm1;       /* EC IPL-SPECIFIED ORE BUFFER LIMIT */
    char            ucmrv001;       /* ED RESERVED                  */
    short           ucmwqlm1;       /* EE IPL-SPECIFIED WQE BUFFER LIMIT */

    void            *ucmbfext;      /* F0 ADDRESS OF UCM FIXED EXTENSION BASE */
    void            *ucmrp2ad;      /* F4 POINTER TO REPLY PROCESSOR, STAGE 2 */
    short           ucmrsv61;       /* F8 RESERVED                  */
    short           ucmctid;        /* FA ASID OF COMMUNICATIONS TASK */
    void            *ucmmbend;      /* FC POINTER TO LAST ELEMENT ON 
                                          MONITOR MESSAGE BLOCK QUEUE */

    void            *ucmwecbh;      /* 100 POINTER TO START OF WQE ECB CHAIN */
    void            *ucmwecbt;      /* 104 POINTER TO END OF WQE ECB CHAIN */
    void            *ucmoecbh;      /* 108 POINTER TO START OF ORE ECB CHAIN */
    void            *ucmoecbt;      /* 10C POINTER TO END OF ORE ECB CHAIN */

    unsigned        ucmorecp;       /* 110 ORE CELLPOOL ID          */
    unsigned        ucmwqecp;       /* 114 WQE CELLPOOL ID          */
    void            *ucmascb;       /* 118 ASCB ADDRESS OF COMMUNICATIONS TASK */
    void            *ucmswch;       /* 11C ADDRESS OF CONSOLE SWITCH ROUTINE */

    void            *ucmfrrad;      /* 120 ADDRESS OF COMMUNICATIONS TASK'S         
                                           RECOVERY ROUTINE (IEAVMFRR) */
    void            *ucmwakup;      /* 124 ADDRESS OF COMMUNICATIONS TASK'S POST    
                                           ERROR RECOVERY ROUTINE (IEAVMEST, ALIAS  
                                           FOR IEAVMFRR)            */
    void            *ucmjes3t;      /* 128 ADDRESS OF SUBSYSTEM ASCB */
    char            ucmrsv42;       /* 12C RESERVED                 */
    char            ucmrsv51;       /* 12D RESERVED                 */
    short           ucmrsv60;       /* 12E RESERVED                 */

    void            *ucmmtplp;      /* 130 IEETRACE PARAMETER LIST AND 
                                           SAVE AREA POINTER        */
    char            ucmrsv62[60];   /* 134 RESERVED                 */
};                                  /* 170 (368 bytes)              */
         
struct ucm2ext {
    unsigned short  ucm2wid;        /* 00 ASID OF USER WAITING ON UCMWQECB */
    unsigned short  ucm2rid;        /* 02 ASID OF USER WAITING ON UCMRQECB */
    void            *ucm2pst;       /* 04 BRANCH ENTRY POINT INTO 'POST' ROUTINE */

    union {
        void        *ucm2sta;       /* 08 POINTER TO STAR WORK AREA (SDWA) */
        struct {                    
            char    ucm2sflg;       /* 08 STAR CONTROL FLAGS        */
#define UCM2SDWA    0x80            /* ... SDWA OBTAINED            */
#define UCM2SENT    0x40            /* ... STAR ENTERED             */
#define UCM2DTAK    0x20            /* ... DUMP TAKEN               */
#define UCM2DSTR    0x10            /* ....DUMP STARTED             */
#define UCM2WTOI    0x08            /* ... STAR ABEND MESSAGE ISSUED*/
            char    ucm2staa[3];    /* 09 ADDRESS OF SDWA OR ZERO   */
        };
    };

    void            *ucmrsv78;      /* 0C RESERVED  (MDC303)        */
    void            *ucmrsv73;      /* 10 RESERVED  (MDC386)        */
    void            *ucmrsv74;      /* 14 RESERVED  (MDC387)        */
};

struct ucmprfx {                    /* START OF MCS PREFIX */
    union {
        void        *mcsucm;        /* 00 ALIAS FOR START OF MCS PREFIX */
        void        *ucmmcent;      /* 00 ADDRESS OF MASTER CONSOLE UCM ENTRY */
    };

    union {
        char        ucmsave0[72];   /* 04 RESIDENT REGISTER SAVE AREA FOR IEACVTSK */
        struct {
            void    *ucmsva0;       /* 04 WORD 1                    */
            void    *ucmsvb0;       /* 08 WORD 2                    */
            void    *ucmsvc0;       /* 0C WORD 3                    */
            void    *ucmsvd0;       /* 10 WORD 4                    */
            void    *ucmsve0;       /* 14 WORD 5                    */
            void    *ucmsvf0;       /* 18 WORD 6                    */
            void    *ucmsvg0;       /* 1C WORD 7                    */
            void    *ucmsvh0;       /* 20 WORD 8                    */
            void    *ucmsvi0;       /* 24 WORD 9                    */
            void    *ucmsvj0;       /* 28 WORD 10                   */
            void    *ucmsvk0;       /* 2C WORD 11                   */
            void    *ucmsvl0;       /* 30 WORD 12                   */
            void    *ucmsvm0;       /* 34 WORD 13                   */
            void    *ucmsvn0;       /* 38 WORD 14                   */
            void    *ucmsvo0;       /* 3C WORD 15                   */
            void    *ucmsvp0;       /* 40 WORD 16                   */
            void    *ucmsvq0;       /* 44 WORD 17                   */
            void    *ucmsvr0;       /* 48 WORD 18                   */
        };
    };

    void            *ucmdome;       /* 4C ADDRESS OF FIRST DOM ELEMENT */
    void            *ucmwtox;       /* 50 ZERO (OS/VS2)  (MDC383)   */

    union {
        char        ucmsflgs[2];    /* 54 SYSTEM CONTROL FLAGS      */
        struct {
            char    ucmsflg1;       /* 54 BYTE 1 OF SYSTEM CONTROL FLAGS */
#define UCMRSV01    0x80            /* ... RESERVED                 */
#define UCMSYSB     0x40            /* ... HARD COPY SUPPORT REQUIRED */
#define UCMSYSC     0x20            /* ... COMMANDS TO HARD COPY    */
#define UCMSYSD     0x10            /* ... CONSOLE SWITCH FOR MASTER*/
#define UCMSYSE     0x08            /* ... NO CONSOLES ACTIVE       */
#define UCMSYSF     0x04            /* ... GRAPHIC CONSOLES EXIST   */
#define UCMSYSG     0x02            /* ... HARD COPY DEVICE IS SYSLOG */
#define UCMRSV35    0x01            /* ... RESERVED                 */
            char    ucmsflg2;       /* 55 BYTE 2 OF SYSTEM CONTROL FLAGS */
#define UCMSYSI     0x80            /* ... WQE HOUSEKEEPING REQUIRED*/
#define UCMSYSJ     0x40            /* ... HARD COPY TO BE WRITTEN  */
#define UCMSYSK     0x20            /* ... NEW CONSOLE IS COMPOSITE */
#define UCMSYSL     0x10            /* ... DEVICE BEING ACCESSED BY CONSOLE SWITCH  
                                    **     TO SOUND CONSOLE ALARM  (MDC384) */
#define UCMSYSM     0x08            /* ... FAILING CONSOLE IS COMPOSITE */
#define UCMSYSN     0x04            /* ... GRAPHIC CONSOLES ACTIVE  */
#define UCMSYSO     0x02            /* ... DUMMY ATTENTION BY WTL   */
#define UCMSYSP     0x01            /* ... DEVICE BEING ACCESSED BY CONSOLE SWITCH  
                                    **     TO SOUND MAIN POWER ALARM */
        };
    };

    char            ucmowtor[2];    /* 56 DEFAULT VALUES FOR OLD WTO/R MACROS */

    unsigned        ucmcmid;        /* 58 CURRENT MSG IDENTIFICATION NUMBER */
    void            *ucmhcucm;      /* 5C ADDRESS OF HARD COPY UCM ENTRY (OR ZERO) */
    
    char            ucmxct;         /* 60 EXTERNAL REQUEST COUNT    */
    char            ucmuexit[3];    /* 61 ZERO (WAS ADDRESS OF USER EXIT DATA) */
    char            ucmhrdrt[2];    /* 64 HARD COPY ROUTING CODE ASSIGNMENTS */
    char            ucmrsv03[2];    /* 66 RESERVED                  */

    union {
        char        ucmxsa[24];     /* 68 6-WORD PARAMETER LIST FOR SVC 72 */
        struct {
            void    *ucm1wd;        /* 68 PTR TO 3RD WORD  OF SVC 72 PARM LIST */
            void    *ucm2wd;        /* 6C 2ND WORD OF SVC 72 PARM LIST */
            void    *ucm3wd;        /* 70 3RD WORD OF SVC 72 PARM LIST */
            void    *ucm4wd;        /* 74 4TH WORD OF SVC 72 PARM LIST */
            void    *ucm5wd;        /* 78 5TH WORD OF SVC 72 PARM LIST */
            void    *ucm6wd;        /* 7C 6TH WORD OF SVC 72 PARM LIST */
        };
    };

    void            *ucmqrtn;       /* 80 ADDRESS OF ENQ ROUTINE ENTRY POINT */
    void            *ucmswsa1;      /* 84 SAVE AREA FOR IEAVSWCH    */
    void            *ucmswsa2;      /* 88 SAVE AREA FOR IEAVSWCH    */
    void            *ucmrsv69;      /* 8C RESERVED                  */

    unsigned        ucmnpecb;       /* 90 NIP ECB - POSTED WHEN NIP ROUTINE'S 
                                          HARD COPY CAN BE WRITTEN  */
    void            *ucmlogad;      /* 94 ADDRESS OF WTL BUFFER     */
    void            *ucmrsv72;      /* 98 RESERVED                  */
    char            ucmsds1;        /* 9C SDS FLAGS                 */
#define UCMSDS1A    BIT0            /* ... STCMDS TO HARDCOPY       */
#define UCMSDS1B    BIT1            /* ... INCMDS TO HARDCOPY       */
#if 0
#define UCMRSV04    BIT2            /* ... RESERVED                 */
#define UCMRSV05    BIT3            /* ... RESERVED                 */
#define UCMRSV06    BIT4            /* ... RESERVED                 */
#define UCMRSV07    BIT5            /* ... RESERVED                 */
#define UCMRSV08    BIT6            /* ... RESERVED                 */
#define UCMRSV09    BIT7            /* ... RESERVED                 */
#endif

    char            ucmsds2;        /* 9D RESERVED FOR SDS FLAGS    */
    short           ucmrsv65;       /* 9E RESERVED                  */
    
/**********************************************************************
*                                                                     *
*        POINTERS TO UCM MCS PREFIX AND UCM EXTENSION                 *
*        LOCATED IMMEDIATELY PRECEDING UCM BASE SECTION               *
*                                                                     *
**********************************************************************/

    UCM2EXT         *ucm2ext;       /* A0 ADDRESS OF UCM EXTENSION  */
    UCMPRFX         *ucmprfx;       /* A4 ADDRESS OF UCM MCS PREFIX */
};                                  /* A8 (168 bytes)               */
         
/**********************************************************************
*                                                                     *
*                   UCM EVENT INDICATION LIST (EIL)            @G51AP9A
*                                                                     *
**********************************************************************/
struct ucmeil {
    char            _00;            /* 00 LENGTH OF EIL (IN WORDS)  */
    char            ucmrpyl;        /* 01 LAST ASSIGNED REPLY I.D.  */
    char            ucmrtct;        /* 02 ROUTE COUNT               */
    char            ucmrsv15;       /* 03 RESERVED                  */
    void            *ucmniptr;      /* 04 ADDRESS OF NIP'S 2K WTL BUFFER */
    void            *ucmxecba;      /* 08 ADDRESS OF EXTERNAL INTRPT ECB */
    void            *ucmaecba;      /* 0C ADDRESS OF ATTENTION INTRPT ECB */

    void            *ucmoecba;      /* 10 ADDRESS OF WTO/R REQUEST ECB */
    void            *ucmdecba;      /* 14 ADDRESS OF DOM REQUEST ECB */
    void            *ucmrecba;      /* 18 ADDRESS OF CONSOLE RECOVERY ECB (ACR) */

/* THE FOLLOWING PART OF THE EIL IS A LIST OF POINTERS TO I/O    
 * ECBS FOR EACH CONSOLE DEVICE DEFINED AT SYSGEN.  FOR OS/VS2,  
 * THE LIST CONTAINS A MINIMUM OF 2 ENTRIES.  THE LIST IS        
 * VARIABLE ONLY AT SYSGEN.  THE LAST ENTRY HAS A HIGH-ORDER     
 * BYTE OF X'80'.                                                
*/
    union {
        unsigned    ucmiecba;       /* 1C I/O ECB PTR LIST ENTRY MAPPING */
        struct {
            char    ucmiecbf;       /* 1C I/O ECB PTR LIST LAST ENTRY FLAG */
            char    ucmiecbp[3];    /* 1D ADDR OF I/O REQUEST ECB   */
        };
    };
};
         
/**********************************************************************
*                                                                     *
*               UCM INDIVIDUAL DEVICE ENTRY MAP (UCME)         @G51AP9A
*                                                                     *
*        EACH  UCM DEVICE ENTRY DEFINES SUPPORT FOR A CONSOLE UNIT    *
*        SPECIFIED AT SYSGEN                                          *
*                                                                     *
**********************************************************************/
struct ucmlist {
    unsigned        ucmecb;         /* 00 I/O COMPLETION ECB OR, 
                                       FOR 2740, ADDRESS OF I/O COMPLETION ECB */
    void            *ucmsbr;        /* 04 ADDRESS OF RESIDENT PROCESSOR MODULE */
    void            *ucmdcb;        /* 08 ADDRESS OF DCB            */
    void            *ucmucb;        /* 0C UCB NAME (DEV ADDR) OR PTR TO UCB */
    
    char            ucmname[8];     /* 10 PROCESSING MODULE NAME    */
    char            ucmsts;         /* 18 STATUS FLAGS              */
#define UCMAF       BIT0            /* ... ATTENTION PENDING        */
#define UCMPF       BIT1            /* ... OUTPUT PENDING           */
#define UCMBF       BIT2            /* ... DEVICE BUSY              */
#define UCMCF       BIT3            /* ... CLOSE PENDING            */
#define UCMTA       BIT4            /* ... OPEN PENDING             */
#define UCMTB       BIT5            /* ... DEQ APPROPRIATE OUTPUT QUEUE ENTRIES */
#define UCMEMCLS    BIT6            /* ... EMERGENCY CLOSE PENDING  */
#define UCMTC       BIT7            /* ... CONSOLE HAS INLINE WTO   */

    char            ucmatr;         /* 19 ATTRIBUTE FLAGS           */
#define UCMOF       BIT0            /* ... WTO SUPPORT              */
#define UCMIF       BIT1            /* ... ATTENTION SUPPORT        */
#define UCMXF       BIT2            /* ... EXTERNAL INTERRUPT SUPPORT */
#define UCMUF       BIT3            /* ... DEVICE ACTIVE            */
#define UCMLF       BIT4            /* ... LOAD FLAG                */
#define UCMAT04     BIT5            /* ... DEVICE STATUS TO CHANGE  */
#define UCMRSV16    BIT6            /* ... RESERVED                 */
#define UCMRSV17    BIT7            /* ... RESERVED                 */

// UCMXA    DS    0H                                                      
    char            ucmid;          /* 1A UNIQUE ENTRY I.D.         */
    char            ucmrsv18;       /* 1B RESERVED                  */
    void            *ucmxb;         /* 1C ADDRESS OF DCM(GRAPHICS) OR ZERO */

    char            ucmrtcd[2];     /* 20 ROUTING CODES ASSIGNED TO THIS CONSOLE */
    char            _22[2];         /* 22 RESERVED                  */
    void            *ucmoutq;       /* 24 ADDRESS OF CQE QUEUE      */
// UCMAUTH  DS    0BL2 -         COMMAND CODE AUTHORIZATION       @G51AP9A
    char            ucmautha;       /* 28 1ST BYTE OF COMMAND CODE AUTH FLAGS */
#define UCMAUTH1    BIT0            /* ... COMMAND GROUP 1 (SYS)    */
#define UCMAUTH2    BIT1            /* ... COMMAND GROUP 2 (I/O)    */
#define UCMAUTH3    BIT2            /* ... COMMAND GROUP 3 (CONS)   */
#define UCMRSV19    BIT3            /* ... RESERVED                 */
#define UCMRSV20    BIT4            /* ... RESERVED                 */
#define UCMRSV21    BIT5            /* ... RESERVED                 */
#define UCMRSV22    BIT6            /* ... RESERVED                 */
#define UCMRSV23    BIT7            /* ... RESERVED                 */

    char            ucmauthb;       /* 29 2ND BYTE OF COMMAND CODE AUTH FLAGS */
// UCMDISP  DS    0BL2 -         DISPOSITION FLAGS (2 BYTES)              
    char            ucmdisp1;       /* 2A FIRST BYTE - DISPOSITION FLAGS */
#define UCMDISPA    BIT0            /* ... MASTER CONSOLE           */
#define UCMDISPB    BIT1            /* ... HARD COPY DEVICE/CONSOLE */
#define UCMDISPC    BIT2            /* ,.. GRAPHICS                 */
#define UCMDISPD    BIT3            /* ... OUTPUT ONLY              */
#define UCMDISPE    BIT4            /* ... CONSOLE HAS FULL I/O CAPABILITY */
#define UCMDISPF    BIT5            /* ... CONSOLE IS MESSAGE STREAM ONLY */
#define UCMDISPG    BIT6            /* ... CONSOLE IS STATUS DISPLAY ONLY */
#define UCMDISPH    BIT7            /* ... INTEGRATED OPERATOR'S CONSOLE (OS/VS2) */

    char            ucmdisp2;       /* 2B SECOND BYTE - DISPOSITION FLAGS */
#define UCMDISPI    BIT0            /* ... DISPLAY TIME AND JOB NAME (OS/VS2) */
#define UCMDISPJ    BIT1            /* ... DISPLAY JOB NAME ONLY (OS/VS2) */
#define UCMDISPK    BIT2            /* ... JES3 DUMMY CONSOLE FLAG  (OS/VS2) */
#define UCMRV003    BIT3            /* ... RESERVED                 */
#define UCMRV004    BIT4            /* ... RESERVED                 */
#define UCMRV005    BIT5            /* ... RESERVED                 */
#define UCMRV006    BIT6            /* ... RESERVED                 */
#define UCMRV007    BIT7            /* ... RESERVED                 */

    void            *ucmalten;      /* 2C ADDRESS OF ALTERNATE INPUT UCM ENTRY */

    void            *ucmoaoen;      /* 30 ADDRESS OF OUTPUT/ALTERNATE 
                                          OUTPUT UCM ENTRY          */
    void            *ucmwlast;      /* 34 ADDRESS OF LAST WQE SERVICED IN OUTPUT Q */
    void            *ucmcompc;      /* 38 ADDRESS OF OTHER DEVICE ENTRY IF 
                                          THIS IS A COMPOSITE CONSOLE */
// UCMMSG   DS    0BL2 -         MESSAGE FLAGS                    @G51AP9A
    char            ucmmsg1;        /* 3C FIRST BYTE - MESSAGE FLAGS */
#define UCMMSGA     BIT0            /* ... 'DISPLAY JOBNAMES' REQUESTED */
#define UCMMSGB     BIT1            /* ... 'DISPLAY STATUS' REQUESTED */
#define UCMRSV70    BIT2            /* ... RESERVED                 */
#define UCMMSGD     BIT3            /* ... RESQID REQUEST           */
#define UCMRSV71    BIT4            /* ... RESERVED                 */
#define UCMMSGF     BIT5            /* ... MONITOR SESSIONS         */
#define UCMRSV26    BIT6            /* ... RESERVED                 */
#define UCMRSV27    BIT7            /* ... RESERVED                 */

    char            ucmmsg2;        /* 3D SECOND BYTE - MESSAGE FLAGS */
    char            ucmxor;         /* 3E XOR MASK - SET TO ZERO    */
    char            ucmdevc;        /* 3F DEVICE CONTROL FLAGS      */
#define UCMDEVA     BIT0            /* ... FULL SCREEN ON GRAPHICS CONSOLES */
#define UCMDEVB     BIT1            /* ... 'PREPARE' COMMAND ISSUED */
#define UCMDEVCC    BIT2            /* ... CONSOLE SWITCH INDICATOR */
#define UCMDEVD     BIT3            /* ... DOM ISSUED               */
#define UCMDEVE     BIT4            /* ... I/O COMPLETE             */
#define UCMDEVF     BIT5            /* ... DCM MODIFIED FOR DOM     */
#define UCMDEVG     BIT6            /* ... HIO ISSUED ON THE 2740   */
#define UCMVHRSN    BIT7            /* ... CONSOLE I/O PATH AFFECTED  (OS/VS2) */

    void            *ucmmlast;      /* 40 ADDRESS OF LAST MINOR WQE HANDLED */
    union {
        void        *ucmrct;        /* 44 POINTER TO RCT            */
        struct {
            char    ucmsds5;        /* 44 SDS FLAGS                 */
#define UCMSDS5A    BIT0            /* ... MLWTO LINE NEEDED TO KEEP WRITING */
#define UCMSDS5B    BIT1            /* ... INLINE OUTPUT PENDING    */
#define UCMSDS5C    BIT2            /* ... OUT-OF-LINE OUTPUT PENDING */
#define UCMSDS5D    BIT3            /* ... K Q ISSUED FOR THIS CONSOLE */
#define UCMRSV30    BIT4            /* ... RESERVED                 */
#define UCMSDS5F    BIT5            /* ... FOR CRT, UCMMLAST VALID  */
#define UCMSDS5G    BIT6            /* ... I/O HARDWARE IN OUTPUT-ONLY STATUS */
#define UCMRSV31    BIT7            /* ... RESERVED                 */
            char    ucmrcta[3];     /* 45 ADDRESS OF RCT            */
        };
    };
    UCMEFEXT        *ucmfextp;      /* 48 ADDRESS OF UCME FIXED EXTENSION */
    unsigned        ucmrsv64;       /* 4C RESERVED                  */
};
#define UCMESIZE    sizeof(UCMLIST) /* 50 (80 bytes)                */

/**********************************************************************
*                                                                     *
*                       USER EXIT WORK AREA                           *
*                                                                     *
*        NOTE - THIS AREA IS NOT PART OF THE UCM.  IT IS A            *
*        MAPPING OF THE SPACE GOTTEN AND FREED BY IEAVVWTO.           *
*                                                                     *
**********************************************************************/
struct ucmexit {
    char            ucmmstxt[128];  /* 00 MESSAGE TEXT              */
    unsigned        ucmroutc;       /* 80 ROUTE CODES               */
    unsigned        ucmdescd;       /* 84 DESCRIPTOR CODES          */
};

/**********************************************************************
*                                                                     *
*           UNIT CONTROL MODULE (UCM) FIXED EXTENSION BASE     @G51AP9A
*                      (PRESENT IN OS/VS2 ONLY)                @ZA11870
*                                                                     *
**********************************************************************/
struct ucmfexta {
    char            ucmfucmf;       /* 00 ACRONYM IN EBCDIC -UCMF-  */
    void            *ucmfpptr;      /* 04 ADDRESS OF UCM PAGEABLE EXTENSION BASE */
// UCMFMGFS DS    0CL8 -         FLAGS FOR FIXED EXTENSION BASE           
    char            ucmfflg1;       /* 08 MESSAGE FLAGS             */
#define UCMFMSGE    BIT0            /* ... WQE SHORTAGE MESSAGE ISSUED */
#define UCMFMSGA    BIT1            /* ... WQE CRITICAL MESSAGE ISSUED */
#define UCMFMSGN    BIT2            /* ... NO WQE THRESHOLD MESSAGES 
                                           SHOULD BE ISSUED         */
#define UCMFBR03    BIT3            /* ... RESERVED                 */
#define UCMFBR04    BIT4            /* ... RESERVED                 */
#define UCMFBR05    BIT5            /* ... RESERVED                 */
#define UCMFBR06    BIT6            /* ... RESERVED                 */
#define UCMFBR07    BIT7            /* ... RESERVED                 */
    
    char            ucmfflg2;       /* 09 RESERVED                  */
    short           ucmfrsv1;       /* 0A RESERVED                  */
    unsigned        ucmfrsv2;       /* 0C RESERVED                  */

    short           ucmf60wq;       /* 10 60% OF WQE LIMIT SPECIFIED AT IPL */
    short           ucmf80wq;       /* 12 80% OF WQE LIMIT SPECIFIED AT IPL */
    char            ucmfrsv3[8];    /* 14 RESERVED                  */
// UCMFECBL DS    0CL8 -         ECB LIST THAT IEAVMQWR WAITS ON IN A     
// *                             NO-CONSOLES CONDITION  (MDC334)  @G51AP9A
    void            *ucmfxecb;      /* 1C ADDRESS OF EXTERNAL INTERRUPT ECB */

    union {
        void        *ucmfrecb;      /* 20 ADDRESS OF CONSOLE RECOVERY ECB */
        struct {
            char    ucmfrbyt;       /* 20 HIGH-ORDER BYTE OF UCMFRECB */
#define UCMFRB0     BIT0            /* ... END OF LIST INDICATOR    */
            char    ucmfrad[3];     /* 21 ADDRESS OF CONSOLE RECOVERY ECB */
        };
    };
    void            *ucmfatcn;      /* 24 ADDRESS OF UCME CANDIDATE FOR 
                                          NEW MASTER CONSOLE (ATTENTION 
                                          WAS GENERATED ON THIS DEVICE 
                                          WHEN IN A NO-CONSOLES CONDITION) */
    void            *ucmfe1st;      /* 28 ADDRESS OF FIRST UCME FIXED EXTENSION */
    unsigned        ucmfelen;       /* 2C LENGTH OF A UCME FIXED EXTENSION */

    void            *ucmfelst;      /* 30 ADDRESS OF LAST UCME FIXED EXTENSION */
};

/**********************************************************************
*                                                                     *
*         UNIT CONTROL MODULE (UCM) PAGEABLE EXTENSION BASE    @G51AP9A
*                      (PRESENT IN OS/VS2 ONLY)                @ZA11870
*                                                                     *
**********************************************************************/
struct ucmpexta {
    char            ucmpucmp[4];    /* 00 ACRONYM IN EBCDIC -UCMP-  */
// UCMPDM1  DS    0CL32 -        DOM ID'S  (MDC321)               @G64DP9A
    unsigned        ucmpwqe;        /* 04 WQE CRITICAL MESSAGE DOM ID */
    unsigned        ucmpnmcc;       /* 08 NO MASTER CONSOLE CONDITION 
                                          MESSAGE DOM ID            */
    unsigned        ucmpncc;        /* 0C NO-CONSOLE CONDITION MESSAGE DOM ID */
    
    unsigned        ucmpwqes;       /* 10 WQE SHORTAGE MESSAGE DOM ID */
    unsigned        ucmprsv1[4];    /* 14 RESERVED                  */
    char            ucmprsv2[12];   /* 24 RESERVED                  */

    void            *ucmpe1st;      /* 30 ADDRESS OF FIRST UCME PAGEABLE EXTENSION */
    unsigned        ucmpelen;       /* 34 LENGTH OF A UCME PAGEABLE EXTENSION */
    void            *ucmpelst;      /* 38 ADDRESS OF LAST UCME PAGEABLE EXTENSION */
    char            ucmpedum[4];    /* 3C DUMMY UCME PAGEABLE EXTENSION */
};

/**********************************************************************
*                                                                     *
*         INDIVIDUAL DEVICE ENTRY (UCME) FIXED EXTENSION       @G51AP9A
*                    (PRESENT IN OS/VS2 ONLY)                  @G51AP9A
*                                                                     *
**********************************************************************/
struct ucmefext {
    char            ucmeflg1;       /* 00 FLAGS FOR UCME FIXED EXTENSION */
#define UCMEFLGA    BIT0            /* ... ATTENTION INDEX IN UCMEFATT IS VALID */
#define UCMEFLGB    BIT1            /* ... UCBSYSR FOR THIS DEVICE WAS FORCED 
                                           TO 1 AND SHOULD BE RESTORED TO 0 */
#define UCMEFLGC    BIT2            /* ... RESERVED                 */
#define UCMEFLGD    BIT3            /* ... RESERVED                 */
#define UCMEFLGE    BIT4            /* ... RESERVED                 */
#define UCMEFLGF    BIT5            /* ... RESERVED                 */
#define UCMEFLGG    BIT6            /* ... RESERVED                 */
#define UCMEFLGH    BIT7            /* ... RESERVED                 */

    char            ucmeflg2;       /* 01 RESERVED                  */
    char            ucmefatt;       /* 02 ATTENTION INDEX.  
                                          VALID ONLY IF UCMEFLGA IS 1. */
    char            ucmefsa1;       /* 03 ATTENTION INDEX SAVED BY 1052 
                                          DEVICE SERVICE PROCESSOR  */
    UCMPEXTA        *ucmefpex;      /* 04 ADDRESS OF UCME PAGEABLE EXTENSION */
    void            *ucmefrv1;      /* 08 RESERVED                  */
};
#define UCMEFLEN    sizeof(UCMEFEXT);

#endif  /* IEECUCM_H */
