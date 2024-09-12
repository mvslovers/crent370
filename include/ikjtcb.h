#ifndef IKJTCB_H
#define IKJTCB_H

typedef struct tcb      TCB;
typedef struct tcbfix   TCBFIX;
typedef struct tcbxtnt2 TCBXTNT2;

/* **************************************************************** */
/*                                                                  */
/*            TASK CONTROL BLOCK                                    */
/*                                                                  */
/*  OS/VS2 SU64, 11/28/78, LEVEL=8                                  */
/*                                                                  */
/* **************************************************************** */

struct tcbfix {
    unsigned        tcbfrs0[2];     /* 00 SAVE AREA FOR FLOATING POINT REGISTER 0           */
    unsigned        tcbfrs2[2];     /* 08 SAVE AREA FOR FLOATING POINT REGISTER 2           */
    unsigned        tcbfrs4[2];     /* 10 SAVE AREA FOR FLOATING POINT REGISTER 4           */
    unsigned        tcbfrs6[2];     /* 18 SAVE AREA FOR FLOATING POINT REGISTER 6           */
};                                  /* 20 (32 bytes)                                        */
#define TCBPXLEN    sizeof(TCBFIX)

struct tcb {
    void            *tcbrbp;        /* 00 ADDRESS OF THE RB FOR EXECUTING PROGRAM           */
    union {
        void        *tcbpie;        /* 04 ADDRESS OF SPIE CONTROL AREA.  THE FIRST WORD OF  */
                                    /*    THIS AREA CONTAINS THE PROGRAM INTERRUPT ELEMENT  */
                                    /*    (PIE) ADDRESS.                                    */
        struct {
            char    tcbpmask;       /* 04 SPIE BITS                                         */
#define TCBPM       0x0F            /* ... PROGRAM MASK AT TIME OF SPIE INITIATION.  MASK   */
                                    /*     RESTORED AT TIME OF SPIE NULLIFICATION.          */
            char    tcbpiea[3];     /* 05  ADDRESS OF SPIE CONTROL AREA.  THE FIRST WORD OF */
                                    /*     THIS AREA CONTAINS THE PROGRAM INTERRUPT ELEMENT */
                                    /*     (PIE) ADDRESS.                                   */
        } __attribute__((packed));
    };

    void            *tcbdeb;        /* 08 ADDRESS OF THE DEB QUEUE                          */
    void            *tcbtio;        /* 0C ADDRESS OF THE TASK I/O TABLE (TIOT)              */
    union {
        unsigned    tcbcmp;         /* 10 TASK COMPLETION CODE AND INDICATORS               */
        struct {
            char    tcbcmpf;        /* 10 INDICATOR FLAGS                                   */
#define TCBCREQ     0x80            /* ... A DUMP HAS BEEN REQUESTED                        */
#define TCBCSTEP    0x40            /* ... A STEP ABEND HAS BEEN REQUESTED                  */
#define TCBDMPO     0x20            /* ... DUMP OPTIONS WERE PROVIDED ON CALLRTM OR SETRP   */
                                    /*     MACRO (OS/VS2)                                   */
#define TCBNOCC     0x10            /* ... A COMPLETION CODE WAS NOT PROVIDED ON CALLRTM    */
                                    /*     MACRO.  A DEFAULT CODE IS BEING USED.            */
                                    /*     (OS/VS2)                                         */
#define TCBCASID    0x08            /* ... ABEND WAS SCHEDULED VIA CROSS MEMORY ABTERM      */
                                    /*     (OS/VS2)                                         */
#define TCBRV316    0x04            /* ... RESERVED FOR CALLRTM FLAG (OS/VS2)               */
#define TCBRV317    0x02            /* ... RESERVED FOR CALLRTM FLAG (OS/VS2)               */
#define TCBRV318    0x01            /* ... RESERVED FOR CALLRTM FLAG (OS/VS2)               */
#if 0   /* OS/VS1 N/A */
#define TCBCPP      0x20            /* ... SOME PROBLEM PROGRAM STORAGE WAS OVERLAID BY THE */
                                    /*     SECOND LOAD OF ABEND.  A FIRST LOAD OVERLAY IS   */
                                    /*     INDICATED IN TCBFLGS FIELD (OFFSET 29 DECIMAL).  */
                                    /*     (OS/VS1)                                         */
#define TCBSTCC     0x10            /* ... COMPLETION CODE IS NOT TO BE STORED IN TCBCMPC   */
                                    /*     (OFFSET 17 DECIMAL) IF AN ABEND IS ENCOUNTERED.  */
                                    /*     THIS IS TO PREVENT AN OVERLAY OF THE ORIGINAL    */
                                    /*     COMPLETION CODE.  (OS/VS1)                       */
#define TCBCDBL     0x08            /* ... A DOUBLE ABEND HAS OCCURRED (OS/VS1)             */
#define TCBCWTO     0x04            /* ... A DUMP MESSAGE (WTO) IS TO BE ISSUED TO THE      */
                                    /*     OPERATOR (OS/VS1)                                */
#define TCBCIND     0x02            /* ... ABEND TO OUTPUT AN INDICATIVE DUMP  (OS/VS1)     */
#define TCBCMSG     0x01            /* ... AN ABEND MESSAGE IS PROVIDED TO BE PRINTED BY    */
                                    /*     ABDUMP (OS/VS1)                                  */
#endif
            char    tcbcmpc[3];     /* 11  SYSTEM COMPLETION CODE IN FIRST 12 BITS,         */
                                    /*     USER COMPLETION CODE IN LAST 12 BITS             */
        } __attribute__((packed));
    };

    union {
        void        *tcbrtn;        /* 14 ADDRESS OF TESTRAN CONTROL CORE TABLE             */
        struct {
            char    tcbabf;         /* 14 FLAG BYTE                                         */
#define TCBMOD91    0x80            /* ... BOTH TESTRAN AND DECIMAL SIMULATOR ON A MOD 91   */
#define TCBNOCHK    0x40            /* ... SUPPRESS TAKING CHECKPOINTS FOR THIS STEP        */
                                    /*     (JOB STEP TCB)                                   */
#define TCBGRPH     0x20            /* ... THIS IS A GRAPHICS FOREGROUND JOB OR THE         */
                                    /*     GRAPHIC JOB PROCESSOR                            */
#define TCBRSV01    0x10            /* ... RESERVED                                         */
#define TCBTCPP     0x08            /* ... TCAM POST-PENDING  (RORI)                        */
#define TCBTCP      0x04            /* ... TEST TASK - USED BY TEST SVC                     */
#define TCBOLTEP    0x02            /* ... OLTEP FUNCTIONS REQUIRE CLEANUP BEFORE ABNORMAL  */
                                    /*     TERMINATION CAN BE INVOKED                       */
#define TCBRSV02    0x01            /* ... RESERVED                                         */
            char    tcbtrnb[3];     /* 15 ADDRESS OF TESTRAN CONTROL CORE TABLE             */
        } __attribute__((packed));
    };

    union {
        void        *tcbmss;        /* 18 FOR JOB STEP TCB, ADDRESS OF THE BOUNDARY BOX.    */
                                    /*    FOR SUBTASK TCB, ADDRESS OF THE GOTTEN SUBTASK    */
                                    /*    AREA QUEUE ELEMENT (GQE).  A GQE IS PRESENT       */
                                    /*    ONLY IF THE SYSTEM HAS ISSUED A GETMAIN MACRO     */
                                    /*    INSTRUCTION FOR THE SPACE.  (OS/VS1)              */
                                    /*    ADDRESS OF LAST SPQE ON MSS QUEUE (OS/VS2)        */
        struct {
            char    tcbrsv03;       /* 18 ** TCBNROC  FIELD UNUSED IN OS/VS **              */
            char    tcbmssb[3];     /* 19 FOR JOB STEP TCB, ADDRESS OF THE BOUNDARY BOX.    */
                                    /*    FOR SUBTASK TCB, ADDRESS OF THE GOTTEN SUBTASK    */
                                    /*    AREA QUEUE ELEMENT (GQE).  A GQE IS PRESENT       */
                                    /*    ONLY IF THE SYSTEM HAS ISSUED A GETMAIN MACRO     */
                                    /*    INSTRUCTION FOR THE SPACE.  (OS/VS1)              */
                                    /*    ADDRESS OF LAST SPQE ON MSS QUEUE (OS/VS2)        */
        } __attribute((packed));
    };

    unsigned char   tcbpkf;         /* 1C STORAGE PROTECTION KEY FOR THIS TASK.  IF THERE   */
                                    /*    IS NO STORAGE PROTECTION, ALL BITS ARE ZERO.      */
#define TCBFLAG     0xF0            /* ... STORAGE PROTECTION KEY                           */
#define TCBZERO     0x0F            /* ... MUST BE ZERO                                     */

    /* TCBFLGS  DS    0BL5 -           1D FLAG BYTE FIELDS                                  */
    unsigned char   tcbflgs1;       /* 1D FIRST TCB FLAG BYTE                               */
#define TCBFA       0x80            /* ... ABNORMAL TERMINATION IN PROGRESS                 */
#define TCBFE       0x40            /* ... NORMAL TERMINATION IN PROGRESS                   */
#define TCBFERA     0x20            /* ... ENTER ABEND ERASE ROUTINE WHEN IN CONTROL AGAIN  */
                                    /*     (OS/VS2)                                         */
#define TCBNONPR    0x10            /* ... TASK IS NON-PREEMPTABLE (OS/VS2)                 */
#define TCBPDUMP    0x08            /* ... PREVENT DUMP INDICATOR  (OS/VS2)                 */
#define TCBFT       0x04            /* ... TOP TASK IN TREE BEING ABTERMED (OS/VS2)         */
#define TCBFS       0x02            /* ... ABTERM DUMP COMPLETED (OS/VS2)                   */
#define TCBFX       0x01            /* ... PROHIBIT QUEUEING OF ASYNCHRONOUS EXITS FOR      */
                                    /*     THIS TASK                                        */

    unsigned char   tcbflgs2;       /* 1E SECOND FLAG BYTE                                  */
#define TCBFOINP    0x80            /* ... THE TASK IS ABENDING AND IS IN THE PROCESS OF    */
                                    /*     (1) OPEN FOR DUMP DATA SET PROCESSING,           */
                                    /*     (2) CLOSE FOR USER DATA SET OR                   */
                                    /*     (3) PURGE FOR ENQ'ED RESOURCES.  THIS BIT IS     */
                                    /*     USED IN CONJUNCTION WITH TCBSTACK.               */
                                    /*     (OS/VS2)                                         */
#define TCBFSTI     0x40            /* ... SECOND JOB STEP INTERVAL HAS EXPIRED             */
                                    /*     (OS/VS2 INITIATOR TCB)                           */
#define TCBFABOP    0x20            /* ... IF 1, THE SYSABEND DUMP DATA SET HAS BEEN OPENED */
                                    /*     FOR ABEND.  IF 0, THE SYSUDUMP DUMP DATA SET WAS */
                                    /*     OPENED.  THIS BIT IS ONLY USED FOR THE JOB STEP  */
                                    /*     TCB AND IS USED IN CONJUNCTION WITH TCBFDSOP     */
                                    /*     BIT.  (OS/VS2)                                   */
#define TCBFSMC     0x10            /* ... TASK HAS ISSUED A SYSTEM-MUST-COMPLETE AND SET   */
                                    /*     ALL OTHER TASKS IN THE SYSTEM NON-DISPATCHABLE   */
#define TCBFJMC     0x08            /* ... TASK HAS ISSUED A STEP-MUST-COMPLETE AND TURNED  */
                                    /*     OFF ALL OTHER TASKS IN THE STEP                  */
#define TCBFDSOP    0x04            /* ... SYSABEND OPEN FOR JOB STEP  (OS/VS2)             */
#define TCBFETXR    0x02            /* ... ETXR TO BE SCHEDULED                             */
#define TCBFTS      0x01            /* ... THIS TASK IS A MEMBER OF A TIME-SLICED GROUP     */

    unsigned char   tcbflgs3;       /* 1F THIRD FLAG BYTE                                   */
#define TCBFSM      0x80            /* ... ALL PSW'S IN SUPERVISOR STATE  (OS/VS2)          */
#define TCBADINP    0x40            /* ... USED IN CONJUNCTION WITH TCBONDSP.  FLAG         */
                                    /*     INDICATING THAT ABDUMP IS CURRENTLY PROCESSING   */
                                    /*     FOR SOME TASK IN JOB STEP.  A HIGHER LEVEL TASK  */
                                    /*     IS NOT ALLOWED TO ENTER MAINLINE ABEND           */
                                    /*     PROCESSING IF THIS BIT IS SET IN JOB STEP TCB    */
                                    /*     UNLESS JOB STEP TASK IS FAILING.  BIT SET ONLY   */
                                    /*     IN JOB STEP TCB AND TASK INVOKING ABDUMP.        */
                                    /*     (OS/VS2)                                         */
#define TCBABTRM    0x20            /* ... ABTERM BIT TO PREVENT MULTIPLE ABENDS  (OS/VS2)  */
#define TCBABGM     0x10            /* ... GETMAIN IS TO DEFAULT LSQA REQUESTS TO SQA       */
                                    /*     REQUESTS WHEN REQUEST CANNOT BE SATISFIED FROM   */
                                    /*     LSQA  (OS/VS2)                                   */
#define TCBRSV06    0x08            /* ... RESERVED (OS/VS2)                                */
#define TCBRSV07    0x04            /* ... RESERVED (OS/VS2)                                */
#define TCBRSV08    0x02            /* ... RESERVED (OS/VS2)                                */
#define TCBDWSTA    0x01            /* ... THIS TASK WAS DETACHED WITH STAE=YES OPTION      */
                                    /*     (OS/VS2)                                         */

    unsigned char   tcbflgs4;       /* 20 NON-DISPATCHABILITY FLAGS  (OS/VS2)               */
#define TCBNDUMP    0x80            /* ... ABDUMP NON-DISPATCHABILITY INDICATOR             */
#define TCBSER      0x40            /* ... SER1 NON-DISPATCHABILITY INDICATOR               */
#define TCBRQENA    0x20            /* ... I/O RQE'S EXHAUSTED                              */
#define TCBHNDSP    0x10            /* ... TASK OR JOB STEP IS MOMENTARILY 'FROZEN' UNTIL   */
                                    /*     THE REQUIRED RESOURCES ARE AVAILABLE.  THE BIT   */
                                    /*     IS SET THROUGH THE USE OF THE 'STATUS' SVC       */
#define TCBUXNDV    0x08            /* ... TASK IS TEMPORARILY NON-DISPATCHABLE BECAUSE     */
                                    /*     SMF TIME LIMIT OR SYSOUT LIMIT USER EXIT         */
                                    /*     ROUTINE IS BEING EXECUTED FOR THIS STEP          */
#define TCBMPCVQ    0x04            /* ... VARY OR QUIESCE IN MULTIPROCESSING SYSTEM        */
#define TCBMPCND    0x02            /* ... M65 MULTIPROCESSING NON-DISPATCHABILITY          */
                                    /*     INDICATOR FOR ALL CPU'S                          */
#define TCBONDSP    0x01            /* ... TASK TERMINATING AND NON-DISPATCHABLE BECAUSE    */
                                    /*     EITHER OPEN FOR DUMP DATA SET IS IN PROCESS OR   */
                                    /*     CLOSE BY ABEND IS IN PROCESS                     */

    unsigned char   tcbflgs5;       /* 21 MORE NON-DISPATCHABILITY FLAGS.  IF ANY BIT IN    */
                                    /*    THIS BYTE IS 1, THE TASK IS NON-DISPATCHABLE.     */
#define TCBFC       0x80            /* ... TASK TERMINATED  (OS/VS2)                        */
#define TCBABWF     0x40            /* ... ABNORMAL WAIT   (OS/VS2)                         */
#define TCBPAGE     0x20            /* ... TASK IS NON-DISPATCHABLE DUE TO EXCESSIVE PAGING */
                                    /*     RATE                                             */
#define TCBANDSP    0x10            /* ... TASK IS TEMPORARILY NON-DISPATCHABLE BECAUSE IT  */
                                    /*     WAS ATTACHED UNDER THE DISP=NO OPERAND           */
#define TCBSYS      0x08            /* ... ANOTHER TASK IS IN SYSTEM-MUST-COMPLETE STATUS   */
                                    /*     OR A SUMMARY BIT FOR FIELD TCBSYSCT              */
#define TCBSTP      0x04            /* ... ANOTHER TASK IN THIS JOB STEP IS IN              */
                                    /*     STEP-MUST-COMPLETE STATUS                        */
#define TCBFCD1     0x02            /* ... INITIATOR WAITING FOR REGION   (OS/VS2)          */
#define TCBPNDSP    0x01            /* ... PRIMARY NON-DISPATCHABILITY BIT.  THIS BIT IS    */
                                    /*     SET TO 1 IF ANY OF THE SECONDARY                 */
                                    /*     NON-DISPATCHABILITY BITS (OFFSETS 173, 174, 175, */
                                    /*     200 OR 201 DECIMAL) IS SET TO 1.  THIS BIT IS    */
                                    /*     SET TO 0 IF A SECONDARY NON-DISPATCHABILITY BIT  */
                                    /*     IS SET TO 0 AND ALL OTHER SECONDARY              */
                                    /*     NON-DISPATCHABILITY BITS ARE 0.                  */

    unsigned char   tcblmp;         /* 22 TASK LIMIT PRIORITY  (OS/VS2)                     */
    unsigned char   tcpdsp;         /* 23 DISPATCHING PRIORITY FOR THIS TASK                */
    void            *tcblls;        /* 24 ADDRESS OF LAST LOAD LIST ELEMENT (LLE) IN LOAD   */
                                    /*    LIST  (OS/VS2)                                    */
    void            *tcbjlb;        /* 28 ADDRESS OF A JOBLIB DCB                           */

    union {
        void        *tcbjpq;        /* 2C ADDRESS OF LAST CDE FOR JOB PACK AREA (JPA)       */
                                    /*    CONTROL QUEUE  (OS/VS2)                           */
        struct {
            char    tcbpurge;       /* 2C PURGE FLAGS  (OS/VS2)                             */
#define TCBJPQF     0x80            /* ... JPQ PURGE FLAG                                   */
            char    tcbjpqb[3];     /* 2D ADDRESS OF LAST CDE FOR JOB PACK AREA (JPA)       */
                                    /*    CONTROL QUEUE  (OS/VS2)                           */
        } __attribute__((packed));
    };

    union {
        unsigned    tcbgrs[16];     /* 30 GENERAL REGISTER SAVE AREA                        */
        struct {
            unsigned tcbgrs0;       /* 30 SAVE AREA FOR GENERAL REGISTER 0                  */
            unsigned tcbgrs1;       /* 34 SAVE AREA FOR GENERAL REGISTER 1                  */
            unsigned tcbgrs2;       /* 38 SAVE AREA FOR GENERAL REGISTER 2                  */
            unsigned tcbgrs3;       /* 3C SAVE AREA FOR GENERAL REGISTER 3                  */
            unsigned tcbgrs4;       /* 40 SAVE AREA FOR GENERAL REGISTER 4                  */
            unsigned tcbgrs5;       /* 44 SAVE AREA FOR GENERAL REGISTER 5                  */
            unsigned tcbgrs6;       /* 48 SAVE AREA FOR GENERAL REGISTER 6                  */
            unsigned tcbgrs7;       /* 4C SAVE AREA FOR GENERAL REGISTER 7                  */
            unsigned tcbgrs8;       /* 50 SAVE AREA FOR GENERAL REGISTER 8                  */
            unsigned tcbgrs9;       /* 54 SAVE AREA FOR GENERAL REGISTER 9                  */
            unsigned tcbgrs10;      /* 58 SAVE AREA FOR GENERAL REGISTER 10                 */
            unsigned tcbgrs11;      /* 5C SAVE AREA FOR GENERAL REGISTER 11                 */
            unsigned tcbgrs12;      /* 60 SAVE AREA FOR GENERAL REGISTER 12                 */
            unsigned tcbgrs13;      /* 64 SAVE AREA FOR GENERAL REGISTER 13                 */
            unsigned tcbgrs14;      /* 68 SAVE AREA FOR GENERAL REGISTER 14                 */
            unsigned tcbgrs15;      /* 6C SAVE AREA FOR GENERAL REGISTER 15                 */
        } __attribute__((packed));
    };

    union {
        void        *tcbfsa;        /* 70 ADDRESS OF THE FIRST PROBLEM PROGRAM SAVE AREA    */
        struct {
            char    tcbqel;         /* 70 ENQUEUE COUNT  (OS/VS2)                           */
            char    tcbfsab[3];     /* 71 ADDRESS OF THE FIRST PROBLEM PROGRAM SAVE AREA    */
        } __attribute__((packed));
    };

    void            *tcbtcb;        /* 74 ADDRESS OF NEXT TCB OF LOWER PRIORITY ON THE      */
                                    /*    READY QUEUE                                       */

    void            *tcbtme;        /* 78 ADDRESS OF THE TIMER QUEUE ELEMENT (TQE)          */
#define TCBTQET     0x80            /* ... IF ZERO, TASK TYPE TQE.                          */
                                    /*     IF ONE, REAL/WAIT TYPE TQE.                      */

    union {
        void        *tcbjstcb;      /* 7C ADDRESS OF FIRST JOB STEP TCB                     */
                                    /*    OR OF THIS TCB IF KEY ZERO  (OS/VS2)              */
        struct {
            char    tcbrsv16;       /* 7C RESERVED                                          */
            char    tcbjstca[3];    /* 7D ADDRESS OF FIRST JOB STEP TCB                     */
                                    /*    OR OF THIS TCB IF KEY ZERO  (OS/VS2)              */
        } __attribute__((packed));
    };

    void            *tcbntc;        /* 80 ADDRESS OF THE TCB FOR THE TASK PREVIOUSLY        */
                                    /*    ATTACHED BY THE TASK THAT ATTACHED THIS TASK.     */
                                    /*    FOR EXAMPLE, IF TASK A ATTACHED TASK B AND THEN   */
                                    /*    TASK C, THIS FIELD IN TASK C'S TCB POINTS TO      */
                                    /*    TASK B'S TCB, AND THIS FIELD IN TASK B'S TCB      */
                                    /*    IS ZERO.                                          */

    void            *tcbotc;        /* 84 ADDRESS OF THE TCB FOR THE TASK (THE ORIGINATING  */
                                    /*    TASK) THAT ATTACHED THIS TASK.  THIS FIELD IS     */
                                    /*    ZERO IN THE TCB FOR A SYSTEM TASK.                */

    void            *tcbltc;        /* 88 ADDRESS OF THE TCB FOR THE TASK LAST ATTACHED BY  */
                                    /*    THIS TASK.  NOTE - IF A TASK (THE ORIGINATING     */
                                    /*    TASK) HAS ATTACHED OTHER TASKS, THE TCB'S FOR     */
                                    /*    THE OTHER TASKS ARE ON THE SUBTASK QUEUE OF THE   */
                                    /*    ORIGINATING TASK.  TCBLTC IN THE TCB FOR THE      */
                                    /*    ORIGINATING TASK POINTS TO THE LAST TCB (THE      */
                                    /*    TCB FOR THE LAST ATTACHED TASK) IN THE SUBTASK    */
                                    /*    QUEUE.  IN EACH TCB ON THE SUBTASK QUEUE,         */
                                    /*    EXCEPT THE FIRST TCB, TCBNTC POINTS TO THE        */
                                    /*    PRECEDING TCB ON THE QUEUE.                       */

    void            *tcbiqe;        /* 8C ADDRESS OF AN INTERRUPTION QUEUE ELEMENT (IQE)    */
                                    /*    FOR SCHEDULING THE ETXR ROUTINE OF THE TASK       */
                                    /*    THAT ATTACHED THIS TASK.                          */

    void            *tcbecb;        /* 90 ADDRESS OF THE ECB THAT WILL BE POSTED BY THE     */
                                    /*    SUPERVISOR'S TASK TERMINATION ROUTINES WHEN       */
                                    /*    NORMAL OR ABNORMAL TERMINATION OCCURS.            */

    unsigned char   tcbtsflg;       /* 94 TIME SHARING FLAGS                                */
#define TCBTSTSK    0x80            /* ... SWAPPED TIME SHARING TASK (OS/VS1)               */
#define TCBRV300    0x80            /* ... RESERVED (WAS TCBTSTSK) (OS/VS2)                 */
#define TCBSTPPR    0x40            /* ... TASK SHOULD BE MADE NON-DISPATCHABLE VIA TCBSTPP */
                                    /*     WHEN IT IS NO LONGER RUNNING A PRIVILEGED        */
                                    /*     PROGRAM                                          */
#define TCBATT      0x20            /* ... TASK SHOULD NOT HAVE ATTENTION EXITS             */
                                    /*     SCHEDULED ON IT BY EXIT EFFECTOR                 */
#define TCBTIOTG    0x10            /* ... PURGE TGET/TPUT AFTER ATTENTION                  */
#define TCBRSV17    0x08            /* ... RESERVED                                         */
#define TCBRSV18    0x04            /* ... RESERVED                                         */
#define TCBDYDSP    0x02            /* ... M195 TASK IS MEMBER OF DYNAMIC DISPATCHING       */
                                    /*     GROUP                                            */
#define TCBCPUBN    0x01            /* ... FOR M195, ZERO MEANS I/O BOUND AND ONE MEANS     */
                                    /*     CPU BOUND                                        */

    unsigned char   tcbstpct;       /* 95 NUMBER OF SETTASK STARTS WHICH MUST BE            */
                                    /*    ISSUED BEFORE TASK IS MADE DISPATCHABLE -         */
                                    /*    FIELD NOT RESTRICTED TO TSO                       */
    unsigned char   tcptslp;        /* 96 LIMIT PRIORITY OF TIME SHARING TASK               */
    unsigned char   tcptsdp;        /* 97  DISPATCHING PRIORITY OF TIME SHARING TASK        */

    void            *tcbpqe;        /* 98 POINTER TO DPQE MINUS 8 FOR THE JOB STEP (OS/VS2) */
    void            *tcbaqe;        /* 9C LIST ORIGIN OF AQE(S) FOR THIS TASK (OS/VS2)      */

    union {
        void        *tcbstab;       /* A0 ADDRESS OF THE CURRENT STAE CONTROL BLOCK         */
        struct {
            char    tcbnstae;       /* A0 FLAGS INTERNAL TO STAE ROUTINE                    */
#define TCBSTABE    0x80            /* ... ABEND ENTERED BECAUSE OF ERROR IN STAE           */
                                    /*     PROCESSING                                       */
#define TCBQUIES    0x40            /* ... STAE INVOKED PURGE I/O ROUTINE WITH QUIESCE I/O  */
                                    /*     OPTION                                           */
#define TCB33E      0x20            /* ... A 33E ABEND HAS OCCURRED FOR TASK  (OS/VS2)      */
#define TCBPPSUP    0x10            /* ... 1=SUPERVISOR MODE, 0=PROBLEM PROGRAM MODE.       */
                                    /*     INDICATOR TO SYNCH OF THE MODE OF THE USER       */
                                    /*     EXIT (OS/VS2)                                    */
#define TCBHALT     0x08            /* ... PURGE I/O ROUTINE DID NOT SUCCESSFULLY QUIESCE   */
                                    /*     I/O, BUT I/O WAS HALTED                          */
#define TCBSYNCH    0x04            /* ... SYNCH ISSUED BY ASIR TO SCHEDULE EXIT ROUTINE    */
                                    /*     (OS/VS2)                                         */
#define TCBRV301    0x02            /* ... RESERVED (WAS TCBNPURG) (OS/VS2)                 */
#define TCBSTCUR    0x01            /* ... STAE RECURSION VALID  (OS/VS2)                   */
            char    tcbstabb[3];    /* A1  ADDRESS OF THE CURRENT STAE CONTROL BLOCK        */
        } __attribute__((packed));
    };

    union {
        void        *tcbtct;        /* A4 ADDRESS OF THE TIMING CONTROL TABLE (TCT) IF      */
                                    /*    SYSTEM MANAGEMENT FACILITIES (SMF) DATA IS BEING  */
                                    /*    COLLECTED FOR THE TASK.  ZERO IF SMF DATA IS NOT  */
                                    /*    BEING COLLECTED FOR THE TASK OR FOR OS/VS1, IF    */
                                    /*    SMF IS NOT IN THE SYSTEM.                         */
        struct {
            char    tcbtctgf;       /* A4 FLAG BYTE FOR TIMING CONTROL TABLE                */
#define TCBSMFGF    0x80            /* ... IF ZERO, THE TCT CORE TABLE IS NOT TO BE         */
                                    /*     UPDATED BY GETMAIN/FREEMAIN.                     */
                                    /*     IF ONE, THE TCT CORE TABLE IS TO BE UPDATED BY   */
                                    /*     GETMAIN/FREEMAIN.                                */
            char    tcbtctb[3];     /* A5 ADDRESS OF THE TIMING CONTROL TABLE (TCT) IF      */
                                    /*    SYSTEM MANAGEMENT FACILITIES (SMF) DATA IS BEING  */
                                    /*    COLLECTED FOR THE TASK.  ZERO IF SMF DATA IS NOT  */
                                    /*    BEING COLLECTED FOR THE TASK OR FOR OS/VS1, IF    */
                                    /*    SMF IS NOT IN THE SYSTEM.                         */
        } __attribute__((packed));
    };

    void            *tcbuser;       /* A8 A WORD AVAILABLE TO THE USER                      */

    union {
        char        tcbscndy[4];    /* AC SECONDARY NON-DISPATCHABILITY BITS.  IF ANY BIT   */
                                    /*    IN THE FOLLOWING FOUR BYTES IS 1, THE PRIMARY     */
                                    /*    NON-DISPATCHABILITY BIT (OFFSET 33.7 DECIMAL)     */
                                    /*    IS 1, AND THE TASK IS NON-DISPATCHABLE.           */
        char        tcbndsp[4];     /* AC SAME AS TCBSCNDY                                  */
        struct {
            char    tcbndsp0;       /* AC BYTE 0                                            */
            char    tcbndsp1;       /* AD BYTE 1                                            */
#define TCBDARTN    0x80            /* ... THE TASK IS TEMPORARILY NON-DISPATCHABLE -       */
                                    /*     DAMAGE ASSESSMENT ROUTINE (DAR)                  */
#define TNONDISP    TCBDARTN        /* ... * ALIAS *                                        */
#define TCBDARPN    0x40            /* ... THE TASK IS PERMANENTLY NON-DISPATCHABLE -       */
                                    /*     DAMAGE ASSESSMENT ROUTINE (DAR)                  */
#define PNONDISP    TCBDARPN        /* ... * ALIAS *                                        */
#define TCBRSTND    0x20            /* ... THE TASK IS TEMPORARILY NON-DISPATCHABLE -       */
                                    /*     RECOVERY MANAGEMENT SUPPORT AND SYSTEM ERROR     */
                                    /*     RECOVERY (RMS/SER)                               */
#define TCBRSPND    0x10            /* ... THE TASK IS PERMANENTLY NON-DISPATCHABLE -       */
                                    /*     RECOVERY MANAGEMENT SUPPORT AND SYSTEM ERROR     */
                                    /*     RECOVERY (RMS/SER)                               */
                                    /*     (IF THIS BIT IS ON THEN THE PREVIOUS BIT         */
                                    /*     MUST BE ON TOO)                                  */
#define TCBDDRND    0x08            /* ... THE TASK IS IN DEVICE ALLOCATION AND DYNAMIC     */
                                    /*     DEVICE RECONFIGURATION (DDR) HAS MADE IT         */
                                    /*     NON-DISPATCHABLE -                               */
                                    /*     RECOVERY MANAGEMENT SUPPORT AND SYSTEM ERROR     */
                                    /*     RECOVERY (RMS/SER)   (OS/VS1)                    */
#define TCBTPSP     0x04            /* ... DISPATCHING OF TCAM TASK MUST BE DELAYED UNTIL   */
                                    /*     TCAM I/O APPENDAGE OR SVC ROUTINE HAS COMPLETED  */
                                    /*     EXECUTION  (TCAM IN MULTIPROCESSING ENVIRONMENT) */
#define TCBPIEND    0x02            /* ... SRB IS TO BE SCHEDULED TO PERFORM PIE/PICA       */
                                    /*     PROCESSING (FIRST LEVEL INTERRUPT HANDLER)       */
#define TCBRSV22    0x01            /* ... RESERVED                                         */

            char    tcbndsp2;       /* AE BYTE 2                                            */
#define TCBABD      0x80            /* ... ABDUMP IS PROCESSING  (OS/VS1)                   */
#define TCBSTPP     0x40            /* ... TASK SET NON-DISPATCHABLE BY SETTASK             */
#define TCBNDSVC    0x20            /* ... TASK IS NON-DISPATCHABLE BECAUSE SVC DUMP IS     */
                                    /*     EXECUTING FOR ANOTHER TASK                       */
#define TCBNDTS     0x10            /* ... TASK IS NON-DISPATCHABLE BECAUSE IT IS BEING     */
                                    /*     SWAPPED OUT                                      */
#define TCBIWAIT    0x08            /* ... TASK IS NON-DISPATCHABLE DUE TO AN INPUT WAIT    */
#define TCBOWAIT    0x04            /* ... TASK IS NON-DISPATCHABLE DUE TO AN OUTPUT WAIT   */
#define TCBDSS      0x02            /* ... DYNAMIC SUPPORT SYSTEM (DSS) HAS SET THIS        */
                                    /*     TASK NON-DISPATCHABLE                            */
#define TCBABE      0x01            /* ... ABEND ROUTINE WAS ENTERED FOR THIS TASK WHILE    */
                                    /*     THE DCB FOR SYSABEND (OR SYSUDUMP) DATA SET WAS  */
                                    /*     BEING OPENED FOR ANOTHER TASK  (OS/VS1)          */

            char    tcbndsp3;       /* AF BYTE 3                                            */
#define TCBLJSND    0x80            /* ... TASK IS ABENDING AND NON-DISPATCHABLE BECAUSE IT */
                                    /*     HAS A JOB STEP SUBTASK.  TCBONDSP MUST ALSO BE   */
                                    /*     ON.  (OS/VS2)                                    */
#define TCBRV302    0x40            /* ... RESERVED (WAS TCBSTAND) (OS/VS2)                 */
#define TCBSRBND    0x20            /* ... TCB NON-DISPATCHABLE BECAUSE SRB'S ARE STOPPED   */
                                    /*     (OS/VS2)                                         */
#define TCBSLPER    0x10            /* ... SET NON-DISPATCHABLE SO THAT SLIP/PER CAN ALTER  */
                                    /*     RB PSW PER BIT (OS/VS2)                          */
#define TCBRSV25    0x08            /* ... RESERVED                                         */
#define TCBAREQ     0x04            /* ... TSO AUTHORIZED REQUEST PROCESSING ACTIVE         */
#define TCBRSV27    0x02            /* ... RESERVED                                         */
#define TCBNDINT    0x01            /* ... INITIATOR SETS THIS BIT TO PREVENT JOB STEP      */
                                    /*     EXECUTION IN ORDER TO DO CANCEL PROCESSING       */
                                    /*     (CAN CANCEL LOOP)   (OS/VS2)                     */
        } __attribute__((packed));
    };

    unsigned        tcbmdids;       /* B0 RESERVED FOR MODEL-DEPENDENT SUPPORT AND FOR      */
                                    /*    IBM PROPRIETARY PROGRAMMING SUPPORT               */

    union {
        void        *tcbjscb;       /* B4 ADDRESS OF THE JOB STEP CONTROL BLOCK             */
        struct {
            char    tcbrecde;       /* B4 ABEND RECURSION BYTE                              */
#define TCBREC      0x80            /* ... VALID REENTRY TO ABEND IF NON-ZERO VALUE IN      */
                                    /*     FOLLOWING 7 BITS                                 */
#define TCBOPEN     0x01            /* ... OPEN DUMP DATA SET                               */
#define TCBCLOSD    0x02            /* ... CLOSE DIRECT SYSOUT ON TAPE                      */
#define TCBCLOSE    0x03            /* ... CLOSE OPEN DATA SETS                             */
#define TCBCLOSF    0x04            /* ... RESERVED                                         */
#define TCBGREC     0x05            /* ... GRAPHICS                                         */
#define TCBADUMP    0x07            /* ... ABDUMP                                           */
#define TCBPTAXE    0x08            /* ... PURGE TAXE                                       */
#define TCBMESG     0x09            /* ... MESSAGE RECURSION                                */
#define TCBDYNAM    0x0A            /* ... DD-DYNAM TIOT CLEANUP                            */
#define TCBDAMSG    0x0B            /* ... ABEND IS ISSUING A WTOR ASKING WHETHER THE JOB   */
                                    /*     STEP TASK SHOULD WAIT FOR THE DUMP AREA          */
                                    /*     (OS/VS1)                                         */
#define TCBQTIP     0x0C            /* ... PURGE TSO INTERPARTITION POSTS                   */
#define TCBTCAMP    0x0D            /* ... PURGE TCAM INTERPARTITION POSTS                  */
#define TCBINDRC    0x0E            /* ... INDICATIVE DUMP (LOAD 8 OF ABEND) HAS ABENDED.   */
                                    /*     ABEND WILL HANDLE THIS ABEND.  (OS/VS1)          */
#define TCBSAVCD    0x0F            /* ... ASIR RECURSION.  SAVE OLD COMPLETION CODE        */
#define TCBTYP1W    0x10            /* ... TYPE 1 MESSAGE WRITE TO PROGRAMMER               */
#define TCBWTPSE    0x20            /* ... WRITE-TO-PROGRAMMER (WTP) FAILED.  JOB STEP      */
                                    /*     TIMER EXPIRED DURING JOB STEP ABEND AND THE      */
                                    /*     STAE EXIT IS DENIED.  (OS/VS1)                   */
#define TCBVTAM1    0x21            /* ... ABEND IS ENTERING FIRST VTAM INTERFACE,          */
                                    /*     ISTRAAA1, FOR TERMINATION OF TASK OR SUBTASK     */
                                    /*     (OS/VS1)                                         */
#define TCBVTAM2    0x22            /* ... ABEND IS ENTERING SECOND VTAM INTERFACE,         */
                                    /*     ISTRAAA2, BECAUSE ISTRAAA1 ABENDED  (OS/VS1)     */
#define TCBVTAM3    0x23            /* ... ABEND IS ENTERING FIRST VTAM INTERFACE,          */
                                    /*     ISTRAAA0, BECAUSE VTAM ABENDED  (OS/VS1)         */
#define TCBVTAM4    0x24            /* ... ABEND IS ENTERING SECOND VTAM INTERFACE,         */
                                    /*     ISTRAAA2, BECAUSE ISTRAAA0 ABENDED  (OS/VS1)     */
#define TCBNOSTA    0x30            /* ... STAE/STAI NOT TO BE HONORED                      */
#define TCBSTRET    0x31            /* ... RETURN FROM DUMP PROCESSING                      */
#define TCBCONVR    0x32            /* ... CONVERT TO STEP ABEND                            */
#define TCBDARET    0x33            /* ... RETURN FROM DAMAGE ASSESSMENT ROUTINES           */
#define TCBTYP1R    0x34            /* ... RETURN FROM TYPE 1 MESSAGE MODULE                */
#define TCBNEWRB    0x35            /* ... ABEND ISSUED SVC 13 TO TRANSFER CONTROL (XCTL)   */
                                    /*     TO A NON-ABEND MODULE                            */
#define TCBMCCNS    0x40            /* ... A MUST COMPLETE TASK HAS ABNORMALLY TERMINATED   */
                                    /*     WITHOUT ENOUGH STORAGE FOR 2 RB'S FOR A WTOR     */
                                    /*     ASKING WHETHER THE TASK'S RESOURCES ARE          */
                                    /*     CRITICAL.  THE RESOURCES ARE ASSUMED TO BE       */
                                    /*     CRITICAL, AND THE PARTITION IS MARKED            */
                                    /*     PERMANENTLY NON-DISPATCHABLE. (OS/VS1)           */
            char    tcbjscbb[3];    /* B5  ADDRESS OF THE JOB STEP CONTROL BLOCK            */
        } __attribute__((packed));
    };

    unsigned short  tcbddexc;       /* B8 NUMBER OF TIMES A DYNAMIC DISPATCHING TASK HAS    */
                                    /*    HAD ITS TIME SLICE EXPIRE (OS/VS1)                */
    unsigned short  tcbddwtc;       /* BA NUMBER OF TIMES A DYNAMIC DISPATCHING TASK IS     */
                                    /*    NOT INTERRUPTED BY THE END OF A TIME SLICE        */
                                    /*    BETWEEN WAITS  (OS/VS1)                           */

    void            *tcbiobrc;      /* BC ADDRESS OF IOB RESTORE CHAIN FOR I/O QUIESCED     */
                                    /*    BY EOT                                            */

    void            *tcbexcpd;      /* C0 ADDRESS OF EXCP DEBUG AREA (OS/VS2)               */

    union {
        void        *tcbext1;       /* C4 ADDRESS OF OS-OS/VS COMMON TCB EXTENSION          */
        struct {
            char    tcbrsv32;       /* C4 RESERVED                                          */
            char    tcbext1a[3];    /* C5 ADDRESS OF OS-OS/VS COMMON TCB EXTENSION          */
        } __attribute__((packed));
    };

    /*              OS/VS1 - OS/VS2 COMMON SECTION                                          */

    union {
        char        tcbbits[4];     /* C8 FLAG BYTES.  IF A BIT IN THE FOLLOWING TWO BYTES  */
                                    /*    IS SET TO 1, THE PRIMARY NON-DISPATCHABILITY BIT  */
                                    /*    (OFFSET 33.7 DECIMAL) IS SET TO 1, AND THE TASK   */
                                    /*    IS NON-DISPATCHABLE.                              */
        struct {
            char    tcbndsp4;       /* C8 SECONDARY NON-DISPATCHABILITY FLAGS COMMON TO     */
                                    /*    OS/VS1 AND OS/VS2.  COORDINATED WITH PRIMARY      */
                                    /*    NON-DISPATCHABILITY FLAG TCBPNDSP.  THIS BYTE IS  */
                                    /*    NOT CURRENTLY SUPPORTED BY OS/VS2.                */
            char    tcbndsp5;       /* C9 SECONDARY NON-DISPATCHABILITY FLAGS UNIQUE TO     */
                                    /*    OS/VS1 OR OS/VS2.  COORDINATED WITH PRIMARY       */
                                    /*    NON-DISPATCHABILITY FLAG TCBPNDSP.  THIS BYTE IS  */
                                    /*    NOT CURRENTLY SUPPORTED BY OS/VS2.                */
            char    tcbndsp6;       /* CA TASK-RELATED FLAGS                                */
#define TCBRV       0x80            /* ... THE PARTITION IS FIXED IN REAL STORAGE.  VIRTUAL */
                                    /*     ADDRESSES ARE EQUAL TO REAL ADDRESSES.           */
#define TCBPIE17    0x40            /* ... PAGE FAULT INTERRUPT IS TO BE PASSED TO THE      */
                                    /*     TASK'S INTERRUPT EXIT AND AN 8-BYTE PICA IS IN   */
                                    /*     EFFECT FOR THIS TASK  (OS/VS2)                   */
#define TCBCPU      0x20            /* ... TASK IS CPU-BOUND MEMBER OF AUTOMATIC PRIORITY   */
                                    /*     GROUP (APG)  (OS/VS2)                            */
#define TCBSPVLK    0x10            /* ... TASK SCHEDULED FOR ABTERM WHILE OWNING           */
                                    /*     SUPERVISOR LOCK  (OS/VS2)                        */
#define TCBRV303    0x08            /* ... RESERVED (WAS TCBOLSQA) (OS/VS2)                 */
#define TCBMIGR     0x04            /* ... REGION SELECTED FOR MIGRATION FROM PRIMARY       */
                                    /*     PAGING DEVICE  (OS/VS2)                          */
#define TCBAPG      0x02            /* ... TASK IS IN AUTOMATIC PRIORITY GROUP (APG)(OS/VS2)*/
#define TCBNTJS     0x01            /* ... JOB STEP TASK BUT NOT HIGHEST IN FAILING TREE    */
                                    /*     (OS/VS2)                                         */
            char    tcbflgs7;       /* CB TASK-RELATED FLAGS                                */
#define TCBGPECB    0x80            /* ... TASK IS IN AN ECB WAIT FOR A GETPART  (OS/VS2)   */
#define TCBRSV33    0x40            /* ... RESERVED  (OS/VS2)                               */
#define TCBRSV34    0x20            /* ... RESERVED  (OS/VS2)                               */
#define TCBSTACK    0x10            /* ... SET IN JOB STEP TCB TO INDICATE THAT A TASK IN   */
                                    /*     THE JOB STEP IS IN SERIAL ABEND PROCESSING.      */
                                    /*     USED IN CONJUNCTION WITH TCBFOINP. (OS/VS2)      */
#define TCBSVCS     0x08            /* ... RESERVED (enables SVC screening)                 */
#define TCBRSTSK    0x04            /* ... RESIDENT SYSTEM TASK  (OS/VS2)                   */
#define TCBADMP     0x02            /* ... ALL OTHER TASKS IN JOB STEP HAVE BEEN SET        */
                                    /*     NON-DISPATCHABLE BY ABDUMP.  THIS BIT IS SET TO  */
                                    /*     CONTROL JOB STEP DURING THE DUMPING PROCESS.     */
                                    /*     (OS/VS2)                                         */
#define TCBGTOFM    0x01            /* ... GENERALIZED TRACE FACILITY (GTF) TRACING HAS     */
                                    /*     BEEN TEMPORARILY DISABLED UNDER THIS TASK        */
        } __attribute__((packed));
    };

    unsigned char   tcbdar;         /* CC DAMAGE ASSESSMENT ROUTINE (DAR) FLAGS             */
#define TCBDARP     0x80            /* ... PRIMARY DAR RECURSION.  DAR HAS BEEN ENTERED FOR */
                                    /*     THIS TASK.                                       */
#define TCBDARS     0x40            /* ... SECONDARY DAR RECURSION.  IF DAR IS REENTERED,   */
                                    /*     THIS TASK WILL BE SET NON-DISPATCHABLE.          */
#define TCBDARD     0x20            /* ... A DUMP HAS BEEN REQUESTED FOR A WRITER OR        */
                                    /*     SCHEDULER ABEND, AND THE USER HAS PROVIDED NO    */
                                    /*     SYSABEND DD CARD (OS/VS1)                        */
#define TCBDARC     0x10            /* ... RECURSION PERMITTED IN CLOSE -                   */
                                    /*     AFTER DAR PROCESSING COMPLETED (PCP)             */
#define TCBDARMC    0x10            /* ... DAR HAS BEEN ENTERED TO HANDLE A VALID RECURSION */
                                    /*     IN MUST-COMPLETE STATUS THROUGH ABEND            */
#define TCBDARO     0x08            /* ... SYSTEM ERROR TASK IS FAILING.  DAR DUMP SHOULD   */
                                    /*     NOT REQUEST ANY ERROR RECOVERY PROCEDURE (ERP)   */
                                    /*     PROCESSING.                                      */
#define TCBDARWT    0x04            /* ... A WTO OPERATION WITH A 'REINSTATEMENT FAILURE'   */
                                    /*     MESSAGE IS IN PROCESS FOR DAR                    */
#define TCBDARMS    0x02            /* ... WTO OPERATION WITH A 'DAR IN PROGRESS' MESSAGE   */
                                    /*     IS IN PROCESS FOR DAR (OS/VS1)                   */
#define TCBEXSVC    0x01            /* ... THE DUMP SVC ROUTINE IS EXECUTING FOR THIS TASK  */

    unsigned char   tcbrsv37;       /* CD RESERVED FOR USER                                 */

    unsigned char   tcbsysct;       /* CE NUMBER OF OUTSTANDING SYSTEM-MUST-COMPLETE        */
                                    /*    REQUESTS (ICB497)                                 */
    unsigned char   tcbstmct;       /* CF NUMBER OF OUTSTANDING STEP-MUST-COMPLETE          */
                                    /*    REQUESTS (ICB497)                                 */

    union {
        void        *tcbext2;       /* D0 ADDRESS OF OS/VS1 - OS/VS2 COMMON EXTENSION       */
        struct {
            char    tcbrsv39;       /* D0 RESERVED                                          */
            char    tcbext2a[3];    /* D1 ADDRESS OF OS/VS1 - OS/VS2 COMMON EXTENSION       */
        } __attribute__((packed));
    };

    /*              OS/VS2 TCB OVERLAY                                                      */

    unsigned        tcbaecb;        /* D4 ABEND ECB.  POSTED BY A MOTHER TASK IN RTM2       */
                                    /*    PROCESSING WHEN A DAUGHTER IS WAITING TO          */
                                    /*    TERMINATE IT.                                     */
    void            *tcbtirb;       /* D8 ADDRESS OF TIRB FOR TASK                          */
    void            *tcbback;       /* DC ADDRESS OF PREVIOUS TCB ON READY QUEUE.  ZERO     */
                                    /*    IN TOP TCB.                                       */
    void            *tcbrtwa;       /* E0 POINTER TO CURRENT RTM2 WORK AREA                 */
    unsigned        tcbiotim;       /* E4 TIME IN 16-MICROSECOND UNITS BETWEEN TIME         */
                                    /*    ORIGINAL TIME SLICE INTERVAL WAS ASSIGNED AND     */
                                    /*    TIME AUTOMATIC PRIORITY GROUP (APG) TASK WENT     */
                                    /*    INTO VOLUNTARY WAIT                               */
    unsigned        tcbtmsav;       /* E8 TIME IN 16-MICROSECOND UNITS REMAINING FROM       */
                                    /*    ORIGINAL TIME SLICE INTERVAL WHEN AUTOMATIC       */
                                    /*    PRIORITY GROUP (APG) TASK WAS LAST DISPATCHED     */
    unsigned char   tcbabcur;       /* EC ABEND RECURSION BYTE                              */
    unsigned char   tcbrsvaa;       /* ED RESERVED (ICB497)                                 */
    unsigned char   tcbid;          /* EE TASK ID NUMBER                                    */
#define TCBPAGID    255             /* ... ID FOR PAGING SUPERVISOR TASK                    */
#define TCBSYERR    254             /* ... ID FOR SYSTEM ERROR TASK                         */
#define TCBCOMM     253             /* ... ID FOR COMMUNCIATIONS TASK                       */
#define TCBIORMS    252             /* ... ID FOR I/O RMS TASK                              */
#define TCBMASTR    251             /* ... ID FOR MASTER SCHEDULER TASK                     */
#define TCBJES      250             /* ... ID FOR JOB ENTRY SUBSYSTEM (JES) MONITOR TASK    */
#define TCBDSSID    249             /* ... ID FOR DYNAMIC SUPPORT SYSTEM (DSS) TASK         */
#define TCBLOGID    248             /* ... ID FOR SYSTEM LOG TASK                           */
    unsigned char   tcbrsv41;       /* EF RESERVED                                          */

    union {
        unsigned    tcbxsct;        /* F0 DISPATCHER INTERSECT CONTROL WORD                 */
        struct {
            char    tcbxsct1;       /* F0 FLAG BYTE                                         */
#define TCBACTIV    0x80            /* ... BIT ON MEANS THIS TCB IS CURRENTLY ACTIVE ON A   */
                                    /*     CPU.  USED TO SYNCHRONIZE SOME STATUS SAVING AND */
                                    /*     DISPATCHABILITY INDICATORS WHEN ACTIVE OR NOT    */
                                    /*     UNDER THE LOCAL LOCK.                            */
#define TCBS3A      0x40            /* ... STAGE 3 EXIT EFFECTOR/RESUME/TCTL INTERSECT FLAG */
            char    tcbrv325;       /* F1 RESERVED                                          */
            short   tcbccpvi;       /* F2 ID OF THE CURRENT CPU RUNNING THIS TASK.  USED    */
                                    /*    FOR RECOVERY AND CPU AFFINITY.                    */
        } __attribute__((packed));
    };

    union {
        void        *tcbfoe;        /* F4 ADDRESS OF FIRST FIX OWNERSHIP ELEMENT (FOE)      */
                                    /*    IN LIST FOR THIS TASK                             */
        struct {
            char    tcbrsv42;       /* F4 RESERVED                                          */
            char    tcbfoea[3];     /* F5 ADDRESS OF FIRST FIX OWNERSHIP ELEMENT (FOE)      */
                                    /*    IN LIST FOR THIS TASK                             */
        } __attribute__((packed));
    };

    void            *tcbswa;        /* F8 ADDRESS OF FIRST SCHEDULER WORK AREA (SWA) SPQE   */
                                    /*    ON SWA SPQE CHAIN                                 */
    void            *tcbstawa;      /* FC ESTAE ROUTINE WORK AREA POINTER                   */

    char            tcbtcbid[4];    /* 100 CONTAINS BLOCK ID - 'TCB '                       */
#define TCBTCBID "TCB "

    void            *tcbrtm12;      /* 104 POINTER TO PARAMETER AREAS PASSED FROM RTM1 TO   */
                                    /*     RTM2                                             */
    union {
        char        tcbestae[4];    /* 108 AREA TO CONTAIN RECOVERY DATA FOR RTM            */
        struct {
            char    tcbscbky;       /* 108 KEY IN WHICH SYNCH IS TO PASS CONTROL TO THE     */
                                    /*     USER EXIT                                        */
            char    tcbestrm;       /* 109 ESTAE TERM OPTIONS                               */
#define TCBETERM    0x80            /* ... ESTAE EXIT ENTERED WITH TERM OPTION              */
#define TCBSTAFX    0x40            /* ... SERIALIZED BY TCB ACTIVE                         */
            char    tcbertyp;       /* 10A TYPE OF ERROR CAUSING ENTRY TO THE RTM.  SET     */
                                    /*     BY RTM1.                                         */
            char    tcbmode;        /* 10B MASK INDICATING MODE OF SYSTEM AT TIME OF ERROR. */
                                    /*     SEE IHART1W/MODE FOR INDIVIDUAL BIT DEFINITIONS. */
        } __attribute__((packed));
    };

    void            *tcbukysp;      /* 10C ADDRESS OF SPQE'S FOR SUBPOOLS 229 AND 230       */
                                    /*     (USER KEY STORAGE IN THE PRIVATE AREA)           */
    short           tcbrv326;       /* 110 RESERVED  (MDC321)                               */

    char            tcbaffn[2];     /* 112 CPU AFFINITY INDICATOR                           */
    char            tcbfbyt1;       /* 114 FLAG BYTE                                        */
#define TCBEOTFM    0x80            /* ... END OF TASK FLAG FOR FREEMAIN.  SET TO 1 BY TASK */
                                    /*     TERMINATION AT START OF TERMINATION PROCESSING   */
                                    /*     AND RESET TO 0 AT FINISH.  INDICATES THAT A      */
                                    /*     FREEMAIN ON A BLOCK OF LOCAL STORAGE THAT IS     */
                                    /*     STILL FIXED BY RSM SHOULD RESULT IN A RETURN     */
                                    /*     CODE OF 8 RATHER THAN ABNORMAL TERMINATION.      */
#define TCBRV327    0x40            /* ... RESERVED                                         */
#define TCBNDIOS    0x20            /* ... TASK HAS BEEN SET NON-DISPATCHABLE VIA STATUSND  */
                                    /*     WHILE SVC 16 (PURGE) SCANS THE RB CHAIN PURGING  */
                                    /*     APPENDAGE-SCHEDULED ASYNCHRONOUS EXIT ROUTINES   */
                                    /*     RUNNING UNDER AN IRB/RQE OR NON-RESIDENT ERP'S   */
                                    /*     RUNNING UNDER THE SIRB.                          */
#define TCBPGNLY    0x10            /* ... SET BY RTM2 TO INDICATE ONLY PURGE PHASE TO BE   */
                                    /*     PERFORMED                                        */
#define TCBRTM2     0x08            /* ... SET BY RTM2 TO INDICATE RTM2 HAS BEEN ENTERED    */
                                    /*     FOR THIS TASK                                    */
#define TCBEOT      0x04            /* ... SET BY RTM2 TO INDICATE TO EXIT THAT END OF TASK */
                                    /*     PROCESSING IS COMPLETE                           */
#define TCBRV113    0x02            /* ... RESERVED                                         */
#define TCBLLH      0x01            /* ... LOCALLY LOCKED TCB HAS PAGE FAULTED, AND I/O IS  */
                                    /*     REQUIRED (FIRST LEVEL INTERRUPT HANDLER)         */
    char            tcbfbyt2;       /* 115 FLAG BYTE                                        */
#define TCBCNCB     0x80            /* ... SET BY RTM2 IN THE JOB STEP TCB WHEN IT HAS BEEN */
                                    /*     ENTERED ON THE TCB FOR AN X22 ABEND              */
#define TCBFMW      0x40            /* ... MOTHER WAITING FLAG.  TURNED ON IN A SUBTASK IN  */
                                    /*     RTM2 PROCESSING WHEN AN ANCESTOR TASK IS WAITING */
                                    /*     TO ABEND IT.                                     */
#define TCBFDW      0x20            /* ... DAUGHTER WAITING FLAG.  TURNED ON IN A MOTHER    */
                                    /*     TASK IN RTM2 PROCESSING WHEN A DAUGHTER IS       */
                                    /*     WAITING TO ABEND IT.                             */
#define TCBFPRAP    0x10            /* ... SET BY RTM2 TO PREVENT PERCOLATION TO THE TASK   */
                                    /*     OF AN ASYNCHRONOUS ABEND                         */
#define TCBSSSYN    0x08            /* ... SYNCHRONIZED STATUS STOP PENDING FOR THIS TCB    */
#define TCBECBNV    0x04            /* ... IF 1, ECB POINTED TO BY TCBECB IS NOT TO BE      */
                                    /*     VALIDITY CHECKED.  IF 0, ECB POINTED TO BY       */
                                    /*     TCBECB IS TO BE VALIDITY CHECKED.                */
#define TCBRV122    0x02            /* ... RESERVED                                         */
#define TCBRV123    0x01            /* ... RESERVED                                         */

    unsigned char   tcbrv124;       /* 116 RESERVED                                         */
    unsigned char   tcbrv133;       /* 117 RESERVED                                         */
    void            *tcbrpt;        /* 118 ADDRESS OF RADIX PARTITION TREE FOR LOCAL        */
                                    /*     STORAGE MANAGEMENT                               */
    void            *tcbvat;        /* 11C ADDRESS OF THE VAT (VSAM). THERE IS ONE          */
                                    /*     VAT PER JOB STEP TCB.                            */
    void            *tcbswasa;      /* 120 ADDRESS OF SAVE AREA USED BY SWA MANAGER         */
    void            *tcbsvca2;      /* 124 RESERVED  (TCB screening table)                  */
} __attribute__((packed));          /* 128 (286 bytes)                                      */
#define TCBMNLEN    sizeof(TCB)     /* LENGTH OF MAIN SECTION OF TCB                        */

/*              OS/VS1 - OS/VS2 COMMON EXTENSION                                            */
/*              ADDRESS OF EXTENSION IS IN TCBEXT2                                          */
struct tcbxtnt2 {
    union {
        void        *tcbgtf;        /* 00 ADDRESS OF GENERALIZED TRACE FACILITY (GTF)       */
                                    /*    TEMPORARY TRACE BUFFER                            */
        struct {
            char    tcbtflg;        /* 00 GTF FLAG BYTE                                     */
#define TCBASYNC    0x80            /* ... GTF ASYNCHRONOUS GATHER ROUTINE IS IN CONTROL    */
#define TCBERRTN    0x40            /* ... GTF ASYNCHRONOUS GATHER ERROR ROUTINE IS IN      */
                                    /*     CONTROL                                          */
#define TCBDSPIT    0x20            /* ... MACHINE CHECK INTERRUPTION HANDLER SHOULD        */
                                    /*     UNCONDITIONALLY BRANCH TO THE DISPATCHER         */
            char    tcbgtfa[3];     /* 01 ADDRESS OF GTF TEMPORARY TRACE BUFFER             */
        } __attribute__((packed));
    };

    unsigned char   tcbrsvab;       /* 04 RESERVED                                          */
    unsigned char   tcbrcmp[3];     /* 05 MOST RECENT ABEND COMPLETION CODE (INCLUDING      */
                                    /*    VALID RECURSIONS IN STAE)                         */
    void            *tcbevent;      /* 08 ADDRESS OF EVENT TABLES QUEUE                     */
    unsigned        tcbrsv49;       /* 0C RESERVED                                          */
    void            *tcbrv142;      /* 10 RESERVED                                          */
    void            *tcbcauf;       /* 14 ADDRESS OF SUBSYSTEM FACILITY CONTROL BLOCK       */
                                    /*    (OS/VS2)                                          */
    short           tcbrv144;       /* 18 RESERVED                                          */
    short           tcbrv145;       /* 1A RESERVED                                          */
    unsigned char   tcbrv146;       /* 1C RESERVED                                          */
    unsigned char   tcbrv155;       /* 1D RESERVED                                          */
    unsigned char   tcbrv164;       /* 1E RESERVED                                          */
    unsigned char   tcbrv173;       /* 1F RESERVED                                          */
} __attribute__((packed));
#define TCBX2LEN    sizeof(TCBXTNT2)    /* LENGTH OF COMMON EXTENSION                       */
#define TCBLEN      (TCBPXLEN+TCBMNLEN+TCBX2LEN)    /* TCB LENGTH INCLUDING PREFIX          */


#endif /* IKJTCB_H */
