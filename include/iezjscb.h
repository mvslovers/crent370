#ifndef IEZJSCB_H
#define IEZJSCB_H

typedef struct iezjscb  IEZJSCB;
typedef struct iezjscb  JSCB;

/* **************************************************************** */
/*                                                                  */
/*            ***** JOB/STEP CONTROL BLOCK *****                    */
/*                                                                  */
/*  OS/VS2 SU64, 04/13/78, LEVEL=1                                  */
/*  PTF FOR APAR OZ95568                                    @ZA95568*/
/*                                                                  */
/*  METHOD OF ACCESS                                                */
/*      PL/S - %INCLUDE SYSLIB(IKJTCB) TO DEFINE TCBJSCB            */
/*      BAL  - L     REG,TCBJSCB                                    */
/*             USING IEZJSCB,REG                                    */
/*                                                                  */
/*             WHERE REG IS ANY REGISTER OTHER THAN ZERO GIVES      */
/*             ADDRESSABILITY FOR ALL SYMBOLS.                      */
/*                                                                  */
/*  NOTE                                                            */
/*      IN ADDITION TO THE MANDATORY USE OF THIS MACRO FOR          */
/*      REFERENCES TO THE JSCB, MODULES IN 0S/VS1 AND OS/VS2 WHICH  */
/*      ALLOCATE AND/OR FREE THE JSCB ARE REQUIRED TO USE THE       */
/*      GETJSCB AND FREEJSCB MACROS.                                */
/*                                                                  */
/*  FUNCTION                                                        */
/*      COMMUNICATION OF JOB OR STEP RELATED DATA ITEMS             */
/*                                                                  */
/*  CHANGE ACTIVITY -                                               */
/*      CODES: OZ95568                                      @ZA95568*/
/*                                                                  */
/* **************************************************************** */
/* JSCRIUCP - ADDRESS OF THE DYNAMIC ALLOCATION             @ZA95568*/
/*            COMMUNICATION TABLE.                          @ZA95568*/

/*
         L     R2,PSATOLD-PSA          OUR TCB ADDRESS                  00281000
         L     R2,TCBJSCB-TCB(,R2)     JSCB ADDRESS                     00282000
         USING IEZJSCB,R2                                               00283000
         L     R2,JSCBACT              ACTIVE JSCB ADDRESS              00284000
*/

struct iezjscb {                    /* 00 IEZJSCB  DSECT                            */
    /*     ORG   IEZJSCB+188 -  ALLOWS ADDRESSABILITY FROM TCBJSCB                  */
    unsigned char   __1[188];       /* 00                                           */
/**********************************************************************
*                                                                     *
*  SECTION 1   DATA ITEMS USED IN OS/VS1 AND OS/VS2                   *
*                                                                     *
**********************************************************************/
#define JSCBSEC1    188             /* EQU   * -            START OF JSCB SECTION 1 */
    unsigned        JSCRSV01;       /* BC RESERVED                                  */
    void            *JSCHPCE;       /* C0 ADDRESS OF OPTIONAL JOB ENTRY SUBSYSTEM
                                          (JES) PROCESSOR CONTROL ELEMENT           */
    void            *JSCBSHR;       /* C4 ADDRESS OF ASSEMBLY CHAIN (VSAM)          */
    void            *JSCBTCP;       /* C8 ADDRESS OF TIOT CHAINING ELEMENT CHAIN
                                          (VSAM)                                    */
    void            *JSCBPCC;       /* CC ADDRESS OF PRIVATE CATALOG CONTROL BLOCK
                                          CHAIN (VSAM)                              */
    void            *JSCBTCBP;      /* D0 ADDRESS OF INITIATOR'S TCB (VSAM)         */
    void            *JSCBIJSC;      /* D4 ADDRESS OF JSCB OF THE INITIATOR THAT
                                          ATTACHED THIS JOB STEP (OS/VS1)           */
    void            *JSCBDBTB;      /* D8 ADDRESS OF THE DEB TABLE FOR THIS JOB
                                          STEP  (OS/VS1)                            */
    unsigned char   JSCBID[4];      /* DC JOB SERIAL NUMBER                         */
    void            *JSCBDCB;       /* E0 ADDRESS OF DCB FOR DATA SET CONTAINING
                                          SCHEDULER TABLES FOR THIS JOB             */
    unsigned char   JSCBSTEP;       /* E4 CURRENT STEP NUMBER.  THE FIRST STEP IS
                                          NUMBER 1.                                 */
    unsigned char   JSCRSV03[3];    /* E5 RESERVED                                  */
    unsigned        JSCBSECB;       /* E8 ECB FOR COMMUNICATION BETWEEN MAIN
                                          STORAGE SUPERVISOR AND THE INITIATOR      */
    unsigned char   JSCBOPTS;       /* EC OPTION SWITCHES                           */
#define JSCRSV04    0x80            /* ... RESERVED                                 */
#define JSCRSV05    0x40            /* ... RESERVED                                 */
#define JSCBLONG    0x20            /* ... THE PARTITION CANNOT BE REDEFINED BECAUSE
                                           THE JOB OCCUPYING IT IS DEFINED AS LONG
                                           RUNNING  (OS/VS1)                        */
#define JSCRSV06    0x10            /* ... RESERVED                                 */
#define JSCRSV07    0x08            /* ... RESERVED                                 */
#define JSCRSV08    0x04            /* ... RESERVED                                 */
#define JSCSIOTS    0x02            /* ... CHECKPOINT MUST SCAN SIOT                */
#define JSCBAUTH    0x01            /* ... THE STEP REPRESENTED BY THIS JSCB IS
                                           AUTHORIZED TO ISSUE THE MODESET MACRO
                                           INSTRUCTION                              */
    unsigned char   JSCRSV10[3];    /* ED RESERVED                                  */
    unsigned char   JSCBTTTR[3];    /* F0 JOB QUEUE ADDRESS (TTR) OF TIOT
                                          EXTENSION (OS/VS2)                        */
    unsigned char   JSCBSWT1;       /* F3 STATUS SWITCHES  (OS/VS2)                 */
#define JSCBPASS    0x80            /* ... WHEN THIS BIT IS SET TO ONE AND A
                                           CORRESPONDING BIT IN THE DCB IS SET TO
                                           ONE, OPEN WILL BYPASS PASSWORD
                                           PROTECTION FOR THE DATA SET BEING OPENED
                                           (OS/VS2)                                 */
#define JSCRSV11    0x40            /* ... RESERVED                                 */
#define JSCRSV12    0x20            /* ... RESERVED                                 */
#define JSCRSV13    0x10            /* ... RESERVED                                 */
#define JSCRSV14    0x08            /* ... RESERVED                                 */
#define JSCRSV15    0x04            /* ... RESERVED                                 */
#define JSCRSV16    0x02            /* ... RESERVED                                 */
#define JSCBPMSG    0x01            /* ... A MESSAGE HAS BEEN ISSUED BECAUSE THE
                                           DUMP DATA SET WAS NOT SUCCESSFULLY
                                           OPENED.  PREVENTS USE OF MULTIPLE SMB'S
                                           FOR MULTIPLE OPEN FAILURES IN JOB STEP.
                                           (OS/VS2)                                 */
    void            *JSCBQMPI;      /* F4 ADDRESS OF THE QUEUE MANAGER PARAMETER
                                          AREA (QMPA) FOR THE JOB'S INPUT QUEUE
                                          TABLE ENTRIES   (OS/VS2)                  */
    unsigned        __2;            /* F8 RESERVED (WAS JSCBQMPO)                   */
    /* JSCBWTP  DS    0CL4 -         WRITE-TO-PROGRAMMER (WTP) DATA                 */
    unsigned char   JSCBWTFG;       /* FC FLAGS USED BY WTP SUPPORT                 */
#define JSCBIOFG    0x80            /* ... THE PREVIOUS WTP I/O OPERATION HAD AN
                                           I/O ERROR                                */
#define JSCBRET     0x40            /* ... TEXT BREAKING INDICATOR, ADDITIONAL
                                           MESSAGE TEXT SCANNING REQUIRED
                                           (OS/VS1)                                 */
#define JSCRSV18    0x20            /* ... RESERVED                                 */
#define JSCRSV19    0x10            /* ... RESERVED                                 */
#define JSCRSV20    0x08            /* ... RESERVED                                 */
#define JSCRSV21    0x04            /* ... RESERVED                                 */
#define JSCRSV22    0x02            /* ... RESERVED                                 */
#define JSCRSV23    0x01            /* ... RESERVED                                 */
    unsigned char   JSCBWTSP;       /* FD NUMBER OF THE LAST JOB STEP TO ISSUE WTP  */
    unsigned short  JSCBPMG;        /* FE NUMBER OF WTP OPERATIONS ISSUED FOR THE
                                          STEP IDENTIFIED BY JSCBWTSP               */
    void            *JSCBCSCB;      /* 100 ADDRESS OF COMMAND SCHEDULING CONTROL
                                           BLOCK (CSCB) USED TO PROCESS COMMANDS
                                           RECEIVED FOR THIS JOB STEP               */
#define JSCBS1LN    72              /* 104 EQU   (*-JSCBSEC1) - LENGTH OF SECTION 1 */

/**********************************************************************
*                                                                     *
*  SECTION 2   DATA ITEMS USED ONLY IN OS/VS1                         *
*                                                                     *
**********************************************************************/
#define JSCBSEC2    260             /* 104 EQU   * -        START OF JSCB SECTION 2 */
/*  CURRENTLY NO OS/VS1 ONLY DATA ITEMS                                             */
#define JSCBS2LN    0               /* 104 EQU   (*-JSCBSEC2) - LENGTH OF SECTION 2 */

/**********************************************************************
*                                                                     *
*  SECTION 3   DATA ITEMS USED ONLY IN OS/VS2                         *
*                                                                     *
**********************************************************************/
    /*     ORG   JSCBSEC2 -                                                         */
#define JSCBSEC3    JSCBSEC2        /* 104 EQU   * -        START OF JSCB SECTION 3 */
    unsigned        JSCBJCT;        /* 104 TTR OF JOB'S JCT                         */
    void            *JSCBPSCB;      /* 108 ADDRESS OF TSO PROTECTED STEP CONTROL
                                           BLOCK                                    */
    unsigned short  JSCBASID;       /* 10C ADDRESS SPACE IDENTIFIER (MDC028)        */
#define JSCBTJID    JSCBASID        /* 10C TSO TERMINAL JOB IDENTIFIER              */
    unsigned char   JSCBFBYT;       /* 10E FLAG BYTE  (MDC300)                      */
#define JSCBRV01    0x80            /* ... RESERVED                                 */
#define JSCBADSP    0x40            /* ... AUTOMATIC DATA SET PROTECTION FOR THIS
                                           USER  (MDC302)                           */
#define JSCBRV02    0x20            /* ... RESERVED                                 */
#define JSCBRV03    0x10            /* ... RESERVED                                 */
#define JSCBRV04    0x08            /* ... RESERVED                                 */
#define JSCBRV05    0x04            /* ... RESERVED                                 */
#define JSCBRV06    0x02            /* ... RESERVED                                 */
#define JSCBRV07    0x01            /* ... RESERVED                                 */

    unsigned char   JSCBRV08;       /* 10F RESERVED                                 */
    unsigned        JSCBIECB;       /* 110 ECB USED FOR COMMUNICATION BETWEEN
                                           DYNAMIC ALLOCATION AND THE INITIATOR
                                           IN ORDER TO PERFORM DATA SET INTEGRITY   */
    unsigned char   JSCBJRBA[8];    /* 114 JOB JOURNAL RELATIVE BYTE ADDRESS (RBA)  */
    unsigned        __3;            /* 11C RESERVED (WAS JSCBSWAB)                  */
    union {
        void        *JSCBJNL;       /* 120 INITIATOR JSCB ONLY - ADDRESS OF JSCB
                                           FOR STEP BEING INITIATED.  OTHERWISE,
                                           ZERO                                     */
        struct {
            char    JSCBJJSB;       /* 120 JOB JOURNAL STATUS INDICATORS            */
#define JSCBJNLN    0x80            /* ... NOTHING SHOULD BE WRITTEN IN
                                           JOURNAL                                  */
#define JSCBJNLF    0x40            /* ... NO JOB JOURNAL                           */
#define JSCBJNLE    0x20            /* ... ERROR IN JOURNAL, DO NOT WRITE           */
/*        EQU   X'10' -        RESERVED (WAS JSCBJSBJ)            MDC001            */
#define JSCBJSBI    0x08            /* ... JOB HAS NOT ENTERED ALLOCATION FOR THE
                                           FIRST TIME                               */
#define JSCBJSBA    0x04            /* ... JOB HAS ENTERED ALLOCATION               */
#define JSCBJSBX    0x02            /* ... JOB HAS COMPLETED ALLOCATION             */
#define JSCBJSBT    0x01            /* ... JOB HAS ENTERED TERMINATION              */

            char    JSCBJNLA[3];    /* 121 INITIATOR JSCB ONLY - ADDRESS OF JSCB
                                           FOR STEP BEING INITIATED.  OTHERWISE,
                                           ZERO                                     */
        };
    };
    void            *JSCBJNLR;      /* 124 POINTER TO JOB JOURNAL RPL               */
    void            *JSCBSMLR;      /* 128 ADDRESS OF SYSTEM MESSAGE DATA
                                           SET RPL                                  */
    void            *JSCBSUB;       /* 12C ADDRESS OF JES-SUBTL FOR THIS JOB
                                           STEP                                     */
    unsigned short  JSCBSONO;       /* 130 THE NUMBER OF SYSOUT DATA SETS PLUS
                                           ONE                                      */
    unsigned short  JSCRSV28;       /* 132 RESERVED                                 */
    unsigned char   JSCBFRBA[8];    /* 134 RELATIVE BYTE ADDRESS (RBA) OF THE FIRST
                                           JOURNAL BLOCK  (MDC032)                  */
    void            *JSCBSSIB;      /* 13C ADDRESS OF THE SUBSYSTEM IDENTIFICATION
                                           BLOCK                                    */
    void            *JSCDSABQ;      /* 140 ADDRESS OF QDB FOR DSAB CHAIN            */
    void            *JSCRSV54;      /* 144 RESERVED                                 */
    unsigned        JSCSCT;         /* 148 TTR OF SCT                               */
    void            *JSCTMCOR;      /* 14C ADDRESS OF TIOT MAIN STORAGE MANAGEMENT
                                           AREA                                     */
    void            *JSCBVATA;      /* 150 ADDRESS OF VAT USED DURING SYSTEM RESTART
                                           OR AUTOMATIC RESTART                     */
    unsigned short  JSCDDNNO;       /* 154 COUNTER USED BY DYNAMIC ALLOCATION TO
                                           GENERATE DD NAMES                        */
    unsigned short  JSCRSV53;       /* 156 RESERVED                                 */
    unsigned short  JSCDDNUM;       /* 158 NUMBER OF DD ENTRIES CURRENTLY ALLOCATED
                                           INCLUDING IN USE AND NOT IN USE ENTRIES  */
    unsigned char   JSCRSV33;       /* 15A RESERVED                                 */
    unsigned char   JSCBSWSP;       /* 15B SWA SUBPOOL                              */
    void            *JSCBACT;       /* 15C POINTER TO ACTIVE JSCB                   */
    void            *JSCBUFPT;      /* 160 ADDRESS OF ALLOCATION/UNALLOCATION
                                           WRITE-TO-PROGRAMMER BUFFER               */
    void            *JSCBASWA;      /* 164 POINTER TO THE LAST ALLOCATION ESTAE WORK
                                           AREA  (MDC303)                           */
    unsigned char   JSCBPGMN[8];    /* 168 JOB STEP PROGRAM NAME  (MDC304)          */
    void            *JSCRIUCP;      /* 170 ADDRESS OF DYNAMIC ALLOCATION
                                           COMMUNICATION TABLE                      */
    unsigned char   JSCRSV48;       /* 174 RESERVED                                 */
    unsigned char   JSCRSV49;       /* 175 RESERVED                                 */
    unsigned char   JSCRSV50;       /* 176 RESERVED                                 */
    unsigned char   JSCRSV51;       /* 177 RESERVED                                 */
    void            *JSCRSV52;      /* 178 RESERVED                                 */
#define JSCBS3LN    120             /* EQU   (*-JSCBSEC3) - LENGTH OF SECTION 3     */
};                                  /* 17C (380 bytes)                              */

#endif
