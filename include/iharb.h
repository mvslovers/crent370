#ifndef IHARB_H
#define IHARB_H

typedef struct rbprfx       RBPRFX;
typedef struct rbbasic      RBBASIC;

/* **************************************************************** */
/*               OS/VS REQUEST BLOCKS                               */
/*                                                                  */
/*  OS/VS2 SU64, 05/12/78, LEVEL=2                                  */
/*                                                                  */
/* **************************************************************** */

struct rbbasic {
    union {
        char        rbexrtnm[8];        /* 00 EIGHT-CHARACTER NAME OF ERROR EXIT        */
                                        /*    ROUTINE (SIRB)                            */
        struct {
            char    rbtmfld;            /* 00 INDICATORS FOR TIMER ROUTINES.  WHEN      */
                                        /*    THERE ARE NO TIMER ROUTINES, THIS FIELD   */
                                        /*    IS ZERO.  (IRB)                           */
#define RBTMQUE     0x80                /* ... TIMER ELEMENT NOT ON QUEUE               */
#define RBTMTOD     0x40                /* ... LOCAL TIME-OF-DAY OPTION IS USED         */
#define RBWLIM      0x10                /* ... WAIT LIMIT EXCEEDED                      */
#define RBTMCMP     0x08                /* ... INTERVAL HAS EXPIRED                     */
#define RBTMIND2    0x04                /* ... EXIT SPECIFIED WITH TASK OR REAL REQUEST */
#define RBTMIND3    0x03                /* ... TYPE OF REQUEST                          */
#define RBTREQ      0x00                /* ... TASK REQUEST                             */
#define RBWREQ      0x01                /* ... WAIT REQUEST                             */
#define RBRREQ      0x03                /* ... REAL REQUEST                             */
            char    rbppsav1[3];        /* 01 ADDRESS OF PROBLEM PROGRAM REGISTER SAVE  */
                                        /*    AREA (IRB)                                */
            char    rbabopsw[4];        /* 04 AFTER EXECUTION OF TRANSIENT AREA HANDLER */
                                        /*    ROUTINE - FOUR LOW-ORDER BYTES OF NAME OF */
                                        /*    REQUESTED ROUTINE  (SVRB-TRANS)           */
        };
    };

    unsigned short  rbsize;             /* 08 SIZE OF THIS RB IN DOUBLEWORDS (ALL RB'S) */
    unsigned char   rbstab[2];          /* 0A STATUS AND ATTRIBUTE BITS  (ALL RB'S)     */
#define XSTAB       rbstab              /* 0A SAME AS RBSTAB                            */
#define RBSTAB1     rbstab[0]           /* 0A FIRST BYTE OF STATUS AND ATTRIBUTE BITS   */

#define RBFTP       0xE0                /* ... BIT0+BIT1+BIT2 TYPE OF RB                */
#define RBFTPRB     0x00                /* ... PRB                                      */
#define RBFTTIRB    0x60                /* ... TIRB                                     */
#define RBFTIRB     0x40                /* ... IRB                                      */
#define RBFTSIRB    0x80                /* ... SIRB                                     */
#define RBFTSVRB    0xC0                /* ... SVRB                                     */

#define RBTRSVRB    0x10                /* ... IF RBTRSVRB=0 AND RBCDE=0, THEN TYPE 2   */
                                        /*     SVC IN NUCLEUS.  IF RBTRSVRB=0 AND       */
                                        /*     RBCDE1 NOT 0, THEN SECOND OR SUBSEQUENT  */
                                        /*     LOAD OF TYPE 4 SVC IN FIXED OR MODIFIED  */
                                        /*     LPA (RBCDE1 = ADDRESS OF CDE).  IF       */
                                        /*     RBTRSVRB=1 AND RBCDE1=0, THEN TYPE 3 OR  */
                                        /*     FIRST LOAD OF TYPE 4 SVC IN PAGED, FIXED */
                                        /*     OR MODIFIED LPA.  IF RBTRSVRB=1 AND      */
                                        /*     RBCDE1 NOT 0, THEN SECOND OR SUBSEQUENT  */
                                        /*     LOAD OF TYPE 4 SVC IN PAGED LPA (RBCDE1  */
                                        /*     = ADDRESS OF LPDE).                      */
#define RBFNSVRB    0x10                /* ... ALIAS FOR RBTRSVRB                       */
#define RBWAITP     0x08                /* ... INDICATES THAT AN ECB IS POINTING AT THE */
                                        /*     RB.                                      */
#define RBATNXIT    0x02                /* ... THIS IRB IS AN ATTENTION IRB             */
#define RBPMSVRB    0x01                /* ... THIS IS A PROGRAM MANAGER SVRB - VALID   */
                                        /*     ONLY ON LINK, LOAD, XCTL OR ATTACH       */

#define XSTAB1      rbstab[0]           /* ... SAME AS RBSTAB1                          */
                                        /*     BITS 0-4 ARE SYSTEM-DEPENDENT BITS       */
#define RBFTCKPT    0x04                /* ... A CHECKPOINT MAY BE TAKEN IN A USER EXIT */
                                        /*     FROM THIS SVC ROUTINE (SVRB-BOTH)        */
#define XRBCKPT     0x04                /* ... SAME AS RBFTCKPT                         */
                                        /*     BITS 6-7 ARE SYSTEM-DEPENDENT BITS       */
#define RBSTAB2     rbstab[1]           /* 0B SECOND BYTE OF STATUS AND ATTRIBUTE BITS  */
#define XSTAB2      rbstab[1]           /* 0B SAME AS RBSTAB2                           */
#define RBATTN      0x20                /* ... EXITING PROGRAM IS AN ATTENTION EXIT     */
                                        /*     (IRB)                                    */
#define RBETXR      0x10                /* ... IRB IS FOR AN ETXR EXIT ROUTINE          */
#define RBUSIQE     0x10                /* ... SAME AS RBETXR                           */

#define RBIQETP     0x0C                /* ... BIT4+BIT5 -                              */
#define RBRQENR     0x00                /* ... REQUEST QUEUE ELEMENT IS NOT TO BE       */
                                        /*     RETURNED                                 */
#define RBIRBAER    0x04                /* ... IRB HAS QUEUE ELEMENTS FOR ASYNCHRONOUSLY*/
                                        /*     EXECUTED ROUTINES THAT ARE RQE'S         */
#define RBIQENR     0x08                /* ... IQE IS NOT TO BE RETURNED AT EXIT        */
#define RBIRBAIQ    0x0C                /* ... IRB HAS QUEUE ELEMENTS FOR ASYNCHRONOUSLY*/
                                        /*     EXECUTED ROUTINES THAT ARE IQE'S         */
#define RBTCBNXT    0x80                /* ... RBLINK FIELD POINTS TO TCB (ALL RB'S)    */
#define XRBTCBP     0x80                /* ... SAME AS RBTCBNXT                         */
#define RBFACTV     0x40                /* ... IRB OR SIRB IS QUEUED TO TCB - PROGRAM IS*/
                                        /*     ACTIVE                                   */
#define XRBACTV     0x40                /* ... ACTIVE PROGRAM (ALL RB'S EXCEPT LPRB AND */
                                        /*     LRB FOR OS/VS1)                          */
                                        /*     BITS 2-5 ARE SYSTEM-DEPENDENT BITS       */
#define RBFDYN      0x02                /* ... RB STORAGE CAN BE FREED AT EXIT          */
#define XRBFRRB     0x02                /* ... SAME AS RBFDYN                           */
#define RBECBWT     0x01                /* ... IF ZERO, WAIT FOR A SINGLE EVENT OR ALL  */
                                        /*     OF A NUMBER OF EVENTS ---                */
                                        /*     IF ONE, WAIT FOR A NUMBER OF EVENTS THAT */
                                        /*     IS LESS THAN THE TOTAL NUMBER OF EVENTS  */
                                        /*     WAITING                                  */
#define XRBWAIT     0x01                /* ... SAME AS RBECBWT                          */
    void            *rbep;              /* 0C ENTRY POINT ADDRESS OF ASYNCHRONOUSLY     */
                                        /*    EXECUTED ROUTINE (IRB, SIRB)              */
    unsigned char   rbopsw[8];          /* 10 USER'S OLD PSW (ALL RB'S EXCEPT FRB)      */
#define XRBPSW      rbopsw              /* ... SAME AS RBOPSW                           */
#define RBOPSWB1    rbopsw[0]           /* 10 OLD PSW BYTE 1                            */
#define RBOPER      0x40                /* ... PER BIT IN RBOPSWB1                      */
#define RBOPSWB2    rbopsw[1]           /* 11 OLD PSW BYTE 2                            */
#define RBOPSWPS    0x01                /* ... PROBLEM STATE BIT IN OLD PSW             */

    unsigned        unused4;            /* 18 SYSTEM-DEPENDENT FIELD                    */
    union {
        unsigned    rblink;             /* 1C SAME AS RBLINKB BELOW                     */
        unsigned    xrblnk;             /* 1C SAME AS RBLINKB BELOW                     */
        struct {
            char    rbwcf;              /* 1C NUMBER OF REQUESTS WAITING (WAIT COUNT)   */
                                        /*    (ALL RB'S FOR OS/VS2)                     */
            char    rblinkb[3];         /* 1D ADDRESS OF PREVIOUS RB, OR ADDRESS OF TCB */
                                        /*    WHEN THIS IS FIRST RB ON THE QUEUE        */
                                        /*    (ALL RB'S FOR OS/VS2)                     */
        };
        struct {
            char    xrbwt;              /* 1C SAME AS RBWCF (ALL RB'S EXCEPT LPRB AND   */
                                        /*    LRB FOR OS/VS1)                           */
            char    xrblnkb[3];         /* 1D SAME AS RBLINKB (ALL RB'S EXCEPT LPRB AND */
                                        /*    LRB FOR OS/VS1)                           */
        };
    };

    union {
        char        rbgrsave[64];       /* 20 GENERAL REGISTER SAVE AREA                */
                                        /*    (SVRB-BOTH, IRB, TIRB FOR OS/VS2)         */
        char        xrbreg[64];         /* 20 SAME AS RBGRSAVE                          */
                                        /*    (IRB, SIRB, SVRB FOR OS/VS1)              */
        struct {
            unsigned rbgrs0;            /* 20 SAVE AREA FOR GENERAL REGISTER 0          */
#define XRBREG0     rbgrs0              /* ... SAME AS RBGRS0                           */
            unsigned rbgrs1;            /* 24 SAVE AREA FOR GENERAL REGISTER 1          */
#define XRBREG1     rbgrs1              /* ... SAME AS RBGRS1                           */
            unsigned rbgrs2;            /* 28 SAVE AREA FOR GENERAL REGISTER 2          */
#define XRBREG2     rbgrs2              /* ... SAME AS RBGRS2                           */
            unsigned rbgrs3;            /* 2C SAVE AREA FOR GENERAL REGISTER 3          */
#define XRBREG3     rbgrs3              /* ... SAME AS RBGRS3                           */
            unsigned rbgrs4;            /* 30 SAVE AREA FOR GENERAL REGISTER 4          */
#define XRBREG4     rbgrs4              /* ... SAME AS RBGRS4                           */
            unsigned rbgrs5;            /* 34 SAVE AREA FOR GENERAL REGISTER 5          */
#define XRBREG5     rbgrs5              /* ... SAME AS RBGRS5                           */
            unsigned rbgrs6;            /* 38 SAVE AREA FOR GENERAL REGISTER 6          */
#define XRBREG6     rbgrs6              /* ... SAME AS RBGRS6                           */
            unsigned rbgrs7;            /* 3C SAVE AREA FOR GENERAL REGISTER 7          */
#define XRBREG7     rbgrs7              /* ... SAME AS RBGRS7                           */
            unsigned rbgrs8;            /* 40 SAVE AREA FOR GENERAL REGISTER 8          */
#define XRBREG8     rbgrs8              /* ... SAME AS RBGRS8                           */
            unsigned rbgrs9;            /* 44 SAVE AREA FOR GENERAL REGISTER 9          */
#define XRBREG9     rbgrs9              /* ... SAME AS RBGRS9                           */
            unsigned rbgrs10;           /* 48 SAVE AREA FOR GENERAL REGISTER 10         */
#define XRBREG10    rbgrs10             /* ... SAME AS RBGRS10                          */
            unsigned rbgrs11;           /* 4C SAVE AREA FOR GENERAL REGISTER 11         */
#define XRBREG11    rbgrs11             /* ... SAME AS RBGRS11                          */
            unsigned rbgrs12;           /* 50 SAVE AREA FOR GENERAL REGISTER 12         */
#define XRBREG12    rbgrs12             /* ... SAME AS RBGRS12                          */
            unsigned rbgrs13;           /* 54 SAVE AREA FOR GENERAL REGISTER 13         */
#define XRBREG13    rbgrs13             /* ... SAME AS RBGRS13                          */
            unsigned rbgrs14;           /* 58 SAVE AREA FOR GENERAL REGISTER 14         */
#define XRBREG14    rbgrs14             /* ... SAME AS RBGRS14                          */
            unsigned rbgrs15;           /* 5C SAVE AREA FOR GENERAL REGISTER 15         */
#define XRBREG15    rbgrs15             /* ... SAME AS RBGRS15                          */
        };
    };

    /* IRBEND   DS    0F -           END OF IRB UNLESS OPTIONAL FIELDS                  */

    union {
        char        rbexsave[48];       /* 60 EXTENDED SAVE AREA FOR SVC ROUTINES       */
                                        /*    (SVRB-BOTH) (OS/VS2)                      */
        struct {
            void    *rbrsv135;          /* 60 RESERVED                                  */
            short   rbrsv136;           /* 64 RESERVED                                  */
            char    rbrsv137;           /* 66 RESERVED                                  */
            char    rbrsv138;           /* 67 RESERVED                                  */
    /* PRBEND   DS    0F -                 68 END OF PRB                                */
    /* TIRBEND  DS    0F -                 68 END OF TIRB                               */
            char    rbrsv139[40];       /* 68 LAST 40 BYTES OF RBEXSAVE                 */
    /* RBSCBB   DS    0CL20 -              90 AREA CONTAINING STAE CONTROL BLOCK (SCB)  */
    /*                                        (SVRB ONLY)                               */
            void    *rbschain;          /* 90 POINTER TO NEXT SCB ON CHAIN              */
            void    *rbsexit;           /* 94 POINTER TO USER WRITTEN EXIT ROUTINE      */
    /* RBSPARM  DS    0A -                 98 ADDRESS OF PARAMETER LIST FOR STA EXIT    */
            char    rbsflgs1;           /* 98 FIRST FLAG BYTE                           */
#define RBSSTAI     0x80                /* ... STAI SCB                                 */
#define RBSSTAR     0x40                /* ... STAR SCB.  SCB IF FOR STAE IF NEITHER    */
                                        /*     RBSSTAI NOR RBSSTAR BIT IS SET ON.       */
#define RBSDUMMY    0x20                /* ... DUMMY SCB (WILL NOT BE SCHEDULED)        */
#define RBSESTAE    0x10                /* ... ESTAE INDICATOR                          */
#define RBRSV162    0x08                /* ... RESERVED                                 */
#define RBSASYNC    0x04                /* ... ALLOW ASYNCHRONOUS INTERRUPTS            */
#define RBSIOPRC    0x03                /* ... I/O PROCESSING OPTION.  BOTH BITS OFF    */
                                        /*     MEANS QUIESCE I/O.  BOTH BITS ON IS NOT  */
                                        /*     DEFINED.                                 */
#define RBSNOIOP    0x02                /* ... BYPASS I/O INTERVENTION                  */
#define RBSHALT     0x01                /* ... HALT I/O                                 */
            char    rbsparma[3];        /* 99 ADDRESS OF PARAMETER LIST FOR STA EXIT    */
    /* RBSOWNR  DS    0A -                 9C TCB/RB ADDRESS CONTROLLING THIS SCB       */
            char    rbsflgs2;           /* 9C SECOND FLAG BYTE                          */
#define RBRSV163    0x80                /* ... RESERVED                                 */
#define RBSXCTL2    0x40                /* ... RETAIN THIS SCB ACROSS XCTL              */
#define RBRSV164    0x20                /* ... RESERVED                                 */
#define RBSINUSE    0x10                /* ... THIS SCB IN USE                          */
#define RBRSV165    0x08                /* ... RESERVED                                 */
#define RBRSV166    0x04                /* ... RESERVED                                 */
#define RBSKEY0     0x02                /* ... USER IN KEY 0                            */
#define RBSSUPER    0x01                /* ... USER IN SUPERVISOR MODE                  */
            char    rbsownra[3];        /* 9D RB ADDRESS IF STAE/STAR, TCB ADDRESS IF   */
                                        /*    STAI  (MDC325)                            */
    /* RBSDATA  DS    0F -                 A0 FLAGS AND DATA FIELD                      */
            char    rbsflg3;            /* A0 OPTION FLAGS                              */
#define RBRSV167    0x80                /* ... RESERVED                                 */
#define RBSTERMI    0x40                /* ... AUTHORIZED FOR TERM PROCESSING           */
#define RBSRECRD    0x20                /* ... ERROR RECORD TO BE WRITTEN TO SYS1.LOGREC*/
#define RBSCNCEL    0x10                /* ... SCB IS LOGICALLY CANCELED                */
#define RBSPRNTR    0x08                /* ... SCB IS PREVIOUSLY ENTERED                */
#define RBSBRNTR    0x04                /* ... BRANCH ENTERED SVC 60                    */
#define RBSTERMO    0x02                /* ... TERM PROCESSING ONLY                     */
#define RBRSV168    0x01                /* ... RESERVED                                 */
            char    rbspkey;            /* A1 PROGRAM KEY                               */
            char    rbsid;              /* A2 SCB IDENTIFIER                            */
            char    rbrsv169;           /* A3 RESERVED                                  */
            short   rbrsv148;           /* A4 RESERVED                                  */
            char    rbrsv149;           /* A6 RESERVED                                  */
            char    rbrsv150;           /* A7 RESERVED                                  */
    /* SIRBEND  DS    0F -                 A8 END OF SIRB                               */
            unsigned rbfeparm[6];       /* A8 PARAMETER AREA FOR ROUTINES THAT USE      */
                                        /*    FESTAE AND DEFAULT TO USE THIS AREA       */
                                        /*    (I.E., DO NOT CODE PARAM=)                */
    /* SVRBEND  DS    0F -                 C0 END OF SVRB (BOTH)                        */
        };
        char        xrbesa[80];         /* 60 SVRB - EXTENDED SAVE AREA OF UP TO TEN    */
                                        /*    DOUBLEWORDS REQUESTED FOR SVC ROUTINE     */
                                        /*    (OS/VS1)                                  */
    };
};                                      /* C0 (176 bytes)                               */

struct rbprfx {
    unsigned        reserved1[10];      /* 00 PREFIX IS SYSTEM DEPENDENT                */
    union {
        char        rbrtopsw[16];       /* 28 PROGRAM STATUS INFORMATION STORED AT      */
                                        /*    TIME OF INTERRUPT CAUSING ENTRY INTO THE  */
                                        /*    RTM                                       */
        struct {
            char    rbrtpsw1[8];        /* 28 FIRST DOUBLE WORD OF PSW - SYSTEM AND     */
                                        /*    PROGRAM MASKS, KEY CONDITION CODE AND     */
                                        /*    INSTRUCTION COUNTER                       */
            char    rbrtpsw2[8];        /* 30 SECOND DOUBLE WORD OF PSW                 */
#define RBRSV160    rbrtpsw2[0]         /* 30 RESERVED - SET TO ZERO IN LOW CORE BY     */
                                        /*    HARDWARE                                  */
#define RBRTILC     rbrtpsw2[1]         /* 31 INSTRUCTION LENGTH COUNTER - NUMBER OF    */
                                        /*    BYTES IN INSTRUCTION CAUSING INTERRUPT    */
#define RBRTINCD    rbrtpsw2[2]         /* 32 DS H - INTERRUPT CODE                     */
#define RBRTRAN     rbrtpsw2[4]         /* 34 DS A - VIRTUAL ADDRESS CAUSING TRANSLATION*/
                                        /*    EXCEPTION IF PROGRAM INTERRUPT 16, 17 OR  */
                                        /*    18.  OTHERWISE, NOT USED.                 */
        };
    };

    unsigned char   rbflags1;           /* 38 FLAG BYTE                                 */
#define RBSLOCK     0x80                /* ... INDICATES THAT THIS RB IS                */
                                        /*     NON-DISPATCHABLE UNTIL THE SUPERVISOR    */
                                        /*     LOCK (CVTSYLK) IS RESET  (ALL RB'S)      */
#define RBXWAIT     0x40                /* ... INDICATES THAT THE PROGRAM OPERATING     */
                                        /*     UNDER THIS RB HAS ISSUED AN EXPLICIT     */
                                        /*     (SVC) WAIT  (ALL RB'S)                   */
#define RBABEND     0x20                /* ... ABEND SVRB  (SVRB-BOTH)                  */
#define RBRSV159    0x10                /* ... RESERVED                                 */
#define RBASIR      0x08                /* ... ASIR IS RUNNING UNDER THIS RB            */
#define RBLONGWT    0x04                /* ... LONG WAIT ISSUED UNDER THIS RB           */
#define RBSCB       0x02                /* ... SET BY SVC 60 TO INDICATE RB HAS AN      */
                                        /*     ASSOCIATED ESTAE OR STAE EXIT            */
#define RBSSSYN     0x01                /* ... SYNCHRONIZED STATUS STOP PENDING FOR     */
                                        /*     THIS RB                                  */

    unsigned char   rbrsv004[3];        /* 39 RESERVED                                  */

    unsigned char   rbwcsa;             /* 3C NUMBER OF REQUESTS WAITING AT TIME OF     */
                                        /*    TERMINATION (WAIT COUNT SAVE AREA)        */
                                        /*    (ALL RB'S)                                */
    /* RBINTCDA DS    0CL3 -         INTERRUPT CODE  (ALL RB'S)                         */
    unsigned char   rbinlnth;           /* 3D INSTRUCTION LENGTH CODE - 4 HIGH-ORDER    */
                                        /*    BITS MUST BE ZERO  (ALL RB'S)             */
    unsigned short  rbintcod;           /* 3E INTERRUPT CODE  (ALL RB'S)                */

    RBBASIC         rbbasic[0];         /* 40 START OF BASIC SECTION OF RB              */
#define RBSECT      rbbasic             /* 40 RBSECPTR - THIS IS THE START OF THE       */
                                        /*    BASIC SECTION OF THE RB                   */
};

#define SIRBWALN    64                  /* LENGTH OF RBSIRBWA                           */
#define RBPRFXLN    0x40                /* TOTAL PREFIX LENGTH INCLUDING                */
                                        /* AREA RESERVED FOR FUTURE EXPANSION           */
#define RBPRFLNA    0x20                /* ASSIGNED PREFIX LENGTH                       */

#define PRBLEN      0x88                /* REAL PRB LENGTH FOR GETMAIN                  */
#define SIRBLEN     0xC8                /* REAL SIRB LENGTH FOR GETMAIN                 */
#define TIRBLEN     0x88                /* REAL TIRB LENGTH FOR GETMAIN                 */
#define IRBLEN      0x80                /* REAL IRB LENGTH FOR GETMAIN UNLESS           */
                                        /* OPTIONAL FIELDS ARE ALSO PRESENT             */
#define SVRBLEN     0xE0                /* REAL SVRB LENGTH FOR GETMAIN                 */


#endif /* IHARB_H */
