#ifndef CLIBSDWA_H
#define CLIBSDWA_H

typedef struct sdwa     SDWA;

#pragma pack(1)

struct sdwa {
    void        *SDWAPARM;      /* PARAMETER LIST ADDRESS IF (E)STA MACRO
                                   SPECIFIED PARAM OPTION OR 0. FOR FRRS THIS
                                   IS THE ADDRESS OF THE 6 WORD PARM AREA
                                   RETURNED BY THE SETFRR MACRO WHEN THE
                                   PARMAD KEYWORD IS SPECIFIED ON THE SETFRR */

/*  unsigned    SDWAFIOB;          ADDRESS OF PURGE I/O REQUEST LIST (PIRL)
                                   OR 0 IF HALT I/O IS REQUESTED ON ENTRY TO
                                   RETRY ROUTINE FOR (E)STA.                 */
/*  char        SDWAABCC;          ABEND COMPLETION CODE ON ENTRY TO EXIT
                                   ROUTINE.                                  */
    char        SDWACMPF;       /* FLAG BITS IN COMPLETION CODE.             */
#define SDWAREQ     0x80        /* ... DUMP TO BE GIVEN. SET IF DUMP REQUESTED
                                       BY ABEND, CALLRTM OR SETRP MACRO.     */
#define SDWASTEP    0x40        /* ... JOBSTEP TO BE TERMINATED.
                                       SET IF STEP OPTION SPECIFIED
                                       ON ABEND MACRO.                       */
#define SDWASTCC    0x10        /* ... DON'T STORE COMPLETION CODE.
                                       NOT USED IN OS/VS2 R2.                */
    char        SDWACMPC[3];    /* SYSTEM COMPLETION CODE (FIRST 12 BITS) AND
                                   USER COMPLETION CODE (SECOND 12 BITS).    */

/*  SDWACTL1 DS    0CL8 -  BC MODE PSW AT TIME OF ERROR
    *                      NOT INITIALIZED FOR FRRS.                         */
    char        SDWACMKA;       /* CHANNEL INTERRUPT MASKS.                  */
#define SDWAIOA     0xFE        /* ... I/O INTERRUPTS (ALL ZEROS OR ALL ONES)*/
#define SDWAEXTA    0x01        /* ... EXTERNAL INTERRUPT.                   */

    char        SDWAMWPA;       /* PSW KEY AND 'M-W-P'.                      */
#define SDWAKEYA    0xF0        /* ... PSW KEY.                              */
#define SDWAMCKA    0x04        /* ... MACHINE CHECK INTERRUPT.              */
#define SDWAWATA    0x02        /* ... WAIT STATE.                           */
#define SDWASPVA    0x01        /* ... SUPERVISOR/PROBLEM-PROGRAM MODE.      */

    char        SDWAINTA[2];    /* INTERRUPT CODE (LAST 2 BYTES OF INTERRUPT
                                   CODE IF I/O INTERRUPT).                   */

    char        SDWAPMKA;       /* INSTRUCTION LENGTH CODE, CONDITION CODE,
                                   AND PROGRAM MASKS.                        */
#define SDWAILA     0xC0        /* ... INSTRUCTION LENGTH CODE.              */
#define SDWACCA     0x30        /* ... LAST CONDITION CODE.                  */
#define SDWAFPA     0x08        /* ... FIXED-POINT OVERFLOW.                 */
#define SDWADOA     0x04        /* ... DECIMAL OVERFLOW.                     */
#define SDWAEUA     0x02        /* ... EXPONENT UNDERFLOW.                   */
#define SDWASGA     0x01        /* ... SIGNIFICANCE.                         */

    char        SDWANXTA[3];    /* ADDRESS OF NEXT INSTRUCTION TO BE EXECUTED*/

/*  SDWACTL2 DS    0CL8 -  BC MODE PSW FROM LAST PRB ON RB CHAIN.
    *                      ZERO FOR FRRS.                                    */
    char        SDWACMKP;       /* CHANNEL INTERRUPT MASKS.                  */
#define SDWAIOP     0xFE        /* ... I/O INTERRUPTS (ALL ZEROS OR ALL ONES)*/
#define SDWAEXTP    0x01        /* ... EXTERNAL INTERRUPT.                   */

    char        SDWAMWPP;       /* PSW KEY AND 'M-W-P'.                      */
#define SDWAKEYP    0xF0        /* ... PSW KEY.                              */
#define SDWAMCKP    0x04        /* ... MACHINE CHECK INTERRUPT.              */
#define SDWAWATP    0x02        /* ... WAIT STATE.                           */
#define SDWASPVP    0x01        /* ... SUPERVISOR/PROBLEM-PROGRAM MODE.      */

    char        SDWAINTP[2];    /* INTERRUPT CODE (LAST 2 BYTES OF INTERRUPT
                                   CODE IF I/O INTERRUPT).                   */

    char        SDWAPMKP;       /* INSTRUCTION LENGTH CODE, CONDITION CODE,
                                   AND PROGRAM MASKS.                        */
#define SDWAILP     0xC0        /* ... INSTRUCTION LENGTH CODE.              */
#define SDWACCP     0x30        /* ... LAST CONDITION CODE.                  */
#define SDWAFPP     0x08        /* ... FIXED-POINT OVERFLOW.                 */
#define SDWADOP     0x04        /* ... DECIMAL OVERFLOW.                     */
#define SDWAEUP     0x02        /* ... EXPONENT UNDERFLOW.                   */
#define SDWASGP     0x01        /* ... SIGNIFICANCE.                         */

    char        SDWANXTP[3];    /* ADDRESS OF NEXT INSTRUCTION TO BE EXECUTED*/

/*  SDWAGRSV DS    0CL64 - GENERAL PURPOSE REGISTERS AT TIME OF ERROR        */
    unsigned    SDWAGR00;       /* GPR 0.                                    */
    unsigned    SDWAGR01;       /* GPR 1.                                    */
    unsigned    SDWAGR02;       /* GPR 2.                                    */
    unsigned    SDWAGR03;       /* GPR 3.                                    */
    unsigned    SDWAGR04;       /* GPR 4.                                    */
    unsigned    SDWAGR05;       /* GPR 5.                                    */
    unsigned    SDWAGR06;       /* GPR 6.                                    */
    unsigned    SDWAGR07;       /* GPR 7.                                    */
    unsigned    SDWAGR08;       /* GPR 8.                                    */
    unsigned    SDWAGR09;       /* GPR 9.                                    */
    unsigned    SDWAGR10;       /* GPR 10.                                   */
    unsigned    SDWAGR11;       /* GPR 11.                                   */
    unsigned    SDWAGR12;       /* GPR 12.                                   */
    unsigned    SDWAGR13;       /* GPR 13.                                   */
    unsigned    SDWAGR14;       /* GPR 14.                                   */
    unsigned    SDWAGR15;       /* GPR 15.                                   */

    char        SDWANAME[8];    /* IF PROBLEM PROGRAM MODE NAME
                                   OF ABENDING PROGRAM, OR ZERO
                                   IF NO NAME IS AVAILABLE.
                                   ZERO IF NOT RUNNING UNDER AN RB           */
/*  SDWARBAD DS    A -     RB ADDRESS OF ABENDING PROGRAM (IF SUPERVISOR
    *                      MODE PROGRAM RUNNING UNDER AN RB)
             DS    XL4 -   CONTAINS ZEROS IF SUPERVISOR MODE PROGRAM
    *                      RUNNING UNDER AN RB OR IF PROGRAM NOT
    *                      RUNNING UNDER AN RB                               */

    unsigned    SDWAEPA;        /* ENTRY POINT ADDRESS OF ABENDING PROGRAM.
                                   ZERO IF NOT RUNNING UNDER AN RB           */

    unsigned    SDWAIOBR;       /* POINTER TO SDWAFIOB FIELD,
                                   OR 0 IF NO RETRY, OR 0 IF HALT I/O
                                   IS REQUESTED FOR (E)STA EXITS.
                                   ZERO FOR FRRS                             */

/*  SDWAEC1  DS    0CL8    EXTENDED CONTROL PSW AT TIME OF ERROR(ABEND)      */
    char        SDWAEMK1;       /* INTERRUPT INFORMATION MASKS               */
#define SDWAPER1    0x40        /* ... ON,PROGRAM EVENT RECORDING
                                       INTERRUPTS CAN OCCUR
                                       OFF, PROGRAM EVENT RECORDING
                                       INTERRUPTS CANNOT OCCUR               */
#define SDWATRM1    0x04        /* ... ON,ADDRESS TRANSLATION ACTIVE         */
#define SDWAIO1     0x02        /* ... OFF,I/0 INTERRUPTION CAN NOT OCCUR
                                       ON,I/0 INTERRUPTIONS CAN OCCUR SUBJECT
                                       TO CHANNEL MASK BITS IN CONTROL
                                       REGS 2 AND 3                          */
#define SDWAEXT1    0x01        /* ... OFF,EXTERNAL INTERRUPTION CANNOT OCCUR
                                       ON,EXTERNAL INTERRUPTIONS CAN OCCUR
                                       SUBJECT TO EXTERNAL SUBCLASS MASK BITS
                                       OF CONTROL REG 0                      */

    char        SDWAMWP1;       /* PSW KEY AND 'M-W-P'                       */
#define SDWAKEY1    0xF0        /* ... PSW KEY                               */
#define SDWAECT1    0x08        /* ... EXTENDED CONTROL MODE BIT             */
#define SDWAMCK1    0x04        /* ... OFF,MACHINE CHECK CANNOT OCCUR
                                       ON,MACHINE CHECK DUE TO SYSTEM DAMAGE AND
                                       INSTRUCTION-PROCESSING DAMAGE CAN OCCUR
                                       OTHER MACHINE CHECKS SUBJECT TO MASK BITS
                                       IN CONTROL REGISTER 14                */
#define SDWAWAT1    0x02        /* ... ON,CPU IN WAIT STATE                  */
#define SDWAPGM1    0x01        /* ... ON,PROBLEM STATE
                                       OFF, SUPERVISOR STATE                 */

    char        SDWAINT1;       /* CONDITION CODE AND PROGRAM MASK           */
#define SDWACC1     0x30        /* ... CONDITION CODE                        */
#define SDWAFPO1    0x08        /* ... FIXED POINT OVERFLOW                  */
#define SDWADEC1    0x04        /* ... DECIMAL OVERFLOW                      */
#define SDWAEXP1    0x02        /* ... EXPONENT UNDERFLOW                    */
#define SDWASGN1    0x01        /* ... SIGNIFICANCE                          */

    char        _1;             /* RESERVED                                  */

    unsigned    SDWANXT1;       /* ADDRESS OF NEXT INSTRUCTION TO BE EXECUTED*/

/*  SDWAAEC1 DS    0CL8    ADDITIONAL EC MODE INFORMATION                    */
    char        _2;             /* RESERVED                                  */

    char        SDWAILC1;       /* INSTRUCTION LENGTH CODE FOR PSW DEFINED
                                   BY SDWAEC1                                */
#define SDWAIL1     0x06        /* ... ILC                                   */

/*  SDWAINC1 DS    0CL2    INTERRUPT CODE. IF PROGRAM CHECK OCCURRED
    *                      THE SUBFIELDS ARE FURTHER DIVIDED                 */
    char        _3;             /* RESERVED FOR IMPRECISE INTERRUPTS
                                   ON PROGRAM CHECK INTERRUPT                */
    char        SDWAICD1;       /* 8 BIT INTERRUPT CODE IF PROGRAM CHECK     */
#define SDWAIPR1    0x80        /* ... PER INTERRUPT OCCURRED                */
#define SDWAIMC1    0x40        /* ... MONITOR CALL INTERRUPT OCCURRED       */
#define SDWAIPC1    0x3F        /* ... AN UNSOLICITED PROGRAM CHECK
                                       HAS OCCURRED                          */

    unsigned    SDWATRAN;       /* VIRTUAL ADDRESS CAUSING TRANSLATION
                                   EXCEPTION                                 */

/*  SDWAEC2  DS    0CL8    EXTENDED CONTROL PSW FROM THE RB
    *                      LEVEL WHICH CREATED THE
    *                      ESTAE EXIT AT THE TIME IT LAST
    *                      INCURRED AN INTERRUPT OR 0 FOR ESTAI.
    *                      OR PSW USED TO GIVE FRR CONTROL                   */
    char        SDWAEMK2;       /* INTERRUPT INFORMATION MASKS               */
#define SDWAPER2    0x40        /* ... ON,PROGRAM EVENT RECORDING
                                       INTERRUPTS CAN OCCUR
                                       OFF,PROGRAM EVENT RECORDING
                                       INTERRUPTS CANNOT OCCUR               */
#define SDWATRM2    0x04        /* ... ON,ADDRESS TRANSLATION ACTIVE         */
#define SDWAIO2     0x02        /* ... OFF,I/0 INTERRUPTION CANNOT OCCUR
                                       ON,I/0 INTERRUPTIONS CAN OCCUR SUBJECT TO
                                       TO CHANNEL MASK BITS IN CONTROL
                                       REGS 2 AND 3                          */
#define SDWAEXT2    0x01        /* ... OFF,EXTERNAL INTERRUPTION CANNOT OCCUR
                                       ON,EXTERNAL INTERRUPTIONS CAN OCCUR
                                       SUBJECT TO EXTERNAL SUBCLASS MASK BITS
                                       OF CONTROL REG 0                      */

    char        SDWAMWP2;       /* PSW KEY AND 'M-W-P'                       */
#define SDWAKEY2    0xF0        /* ... PSW KEY                               */
#define SDWAECT2    0x08        /* ... EXTENDED CONTROL MODE BIT             */
#define SDWAMCK2    0x04        /* ... OFF,MACHINE CHECK CANNOT OCCUR
                                       ON,MACHINE CHECK DUE TO SYSTEM DAMAGE AND
                                       INSTRUCTION-PROCESSING DAMAGE CAN OCCUR
                                       OTHER MACHINE CHECKS SUBJECT TO MASK BITS
                                       IN CONTROL REGISTER 14                */
#define SDWAWAT2    0x02        /* ... ON,CPU IN WAIT STATE                  */
#define SDWAPGM2    0x01        /* ... ON,PROBLEM STATE
                                       OFF, SUPERVISOR STATE                 */

    char        SDWAINT2;       /* CONDITION CODE AND PROGRAM MASK           */
#define SDWACC2     0x30        /* ... CONDITION CODE                        */
#define SDWAFPO2    0x08        /* ... FIXED POINT OVERFLOW                  */
#define SDWADEC2    0x04        /* ... DECIMAL OVERFLOW                      */
#define SDWAEXP2    0x02        /* ... EXPONENT UNDERFLOW                    */
#define SDWASGN2    0x01        /* ... SIGNIFICANCE                          */

    char        _4;             /* RESERVED                                  */

    unsigned    SDWANXT2;       /* ADDRESS OF NEXT INSTRUCTION TO BE EXECUTED*/

/*  SDWAAEC2 DS    0CL8    ADDITIONAL EC MODE INFORMATION                    */
    char        _5;             /* RESERVED                                  */

    char        SDWAILC2;       /* INSTRUCTION LENGTH CODE FOR PSW DEFINED
                                   BY SDWAEC2                                */
#define SDWAIL2     0x06        /* ILC                                       */

/*  SDWAINC2 DS    0CL2    INTERRUPT CODE. IF PROGRAM CHECK OCCURRED
    *                      THE SUBFIELDS ARE FURTHER DIVIDED                 */
    char        _6;             /* RESERVED FOR IMPRECISE INTERRUPTS
                                   ON PROGRAM CHECK INTERRUPT                */

    char        SDWAICD2;       /* 8 BIT INTERRUPT CODE IF PROGRAM CHECK     */
#define SDWAIPR2    0x80        /* ... PER INTERRUPT OCCURRED                */
#define SDWAIMC2    0x40        /* ... MONITOR CALL INTERRRUPT OCCURRED      */
#define SDWAIPC2    0x3F        /* ... AN UNSOLICITED PROGRAM CHECK OCCURRED */

    unsigned    SDWATRN2;       /* VIRTUAL ADDRESS CAUSING TRANSLATION
                                   EXCEPTION                                 */
/*  SDWASRSV DS    0CL64   GENERAL PURPOSE REGISTERS OF THE RB LEVEL
    *                      WHICH CREATED THE ESTAE EXIT AT THE TIME
    *                      IT LAST INCURRED AN INTERRUPT OR 0 FOR ESTAI
    *                      FOR FRRS INITIALIZED TO REGISTERS
    *                      AT TIME OF ERROR.
    *                      THIS REGISTER AREA IS USED TO
    *                      UPDATE REGISTER CONTENTS FOR RETRY IF REQUESTED   */
    unsigned    SDWASR00;       /* GPR 0.                                    */
    unsigned    SDWASR01;       /* GPR 1.                                    */
    unsigned    SDWASR02;       /* GPR 2.                                    */
    unsigned    SDWASR03;       /* GPR 3.                                    */
    unsigned    SDWASR04;       /* GPR 4.                                    */
    unsigned    SDWASR05;       /* GPR 5.                                    */
    unsigned    SDWASR06;       /* GPR 6.                                    */
    unsigned    SDWASR07;       /* GPR 7.                                    */
    unsigned    SDWASR08;       /* GPR 8.                                    */
    unsigned    SDWASR09;       /* GPR 9.                                    */
    unsigned    SDWASR10;       /* GPR 10.                                   */
    unsigned    SDWASR11;       /* GPR 11.                                   */
    unsigned    SDWASR12;       /* GPR 12.                                   */
    unsigned    SDWASR13;       /* GPR 13.                                   */
    unsigned    SDWASR14;       /* GPR 14.                                   */
    unsigned    SDWASR15;       /* GPR 15.                                   */

/*  SDWAIDNT DS    0CL4    SDWA IDENTIFICATION ATTRIBUTES                    */
    char        SDWASPID;       /* SUBPOOL ID OF STORAGE CONTAINING THIS SDWA*/
    char        SDWALNTH[3];    /* LENGTH OF THIS SDWA IN BYTES              */

/*  SDWAMCH  DS    0CL28   CONTAINS MACHINE CHECK DATA IF SDWAMCHK IS ON     */
/*  SDWASTCK DS    0CL8    BEGINNING AND ENDING STORAGE CHECK ADDRESSES.
    *                      FILLED IN DUE TO STORAGE ERROR (SDWASCK)
    *                      OR A KEY FAILURE (SDWASKYF).
    *                      THESE ADDRESSES ARE VALID ONLY IF
    *                      INDICATED BY THE SDWASRVL FLAG.                   */
    unsigned    SDWASCKB;       /* BEGINNING VIRTUAL ADDRESS OF STORAGE CHECK*/
    unsigned    SDWASCKE;       /* ENDING VIRTUAL ADDRESS OF STORAGE CHECK   */

/*  SDWAMCHI DS    0BL2    ADDITIONAL MCH INFORMATION FLAGS                  */
    char        SDWAMCHS;       /* MCH FLAG BYTE                             */
#define SDWASRVL    0x80        /* ... ON,STORAGE ADDRESSES SUPPLIED
                                       (SDWASTCK, SDWARFSA) ARE VALID.       */
#define SDWARCDF    0x40        /* ... ON,MACHINE CHECK RECORD NOT RECORDED  */
#define SDWATSVL    0x20        /* ... ON,TIME STAMP IS VALID                */
#define SDWAINVP    0x10        /* ... ON,STORAGE IS RECONFIGURED,
                                       PAGE IS INVALIDATED                   */
#define SDWARSRC    0x08        /* ... ON,STORAGE RECONFIGURATION
                                       (SDWARSR1,SDWARSR2) STATUS AVAILABLE. */
#define SDWARSRF    0x04        /* ... ON,STORAGE RECONFIGURATION NOT ATTEMPTED.
                                       (SDWARSR1 AND SDWARSR2 ARE INVALID)   */

    char        SDWAMCHD;       /* INPUT INFORMATION TO RECOVERY ROUTINE
                                   CONCERNING A MACHINE CHECK ERROR          */
#define SDWASKYF    0x80        /* ... ON,STORAGE KEY FAILURE                */
#define SDWAREGU    0x40        /* ... ON,GENERAL PURPOSE REGISTER CONTENTS AT
                                       TIME OF MACHINE CHECK UNPREDICTABLE   */
#define SDWAPSWU    0x20        /* ... ON,PSW AND/OR CONTROL REGISTERS AT TIME
                                       OF MACHINE CHECK UNPREDICTABLE        */
#define SDWASCK     0x10        /* ... ON,INDICATES STORAGE DATA CHECK       */
#define SDWAACR     0x08        /* ... ON,INDICATES ACR REQUEST              */
#define SDWAINSF    0x04        /* ... ON,INSTRUCTION FAILURE                */
#define SDWAFPRX    0x02        /* ... ON,CONTENTS OF FLOATING POINT REGISTERS
                                      AT TIME MACHINE CHECK ARE UNPREDICTABLE*/
#define SDWATERR    0x01        /* ... ON,TIMER ERROR - CAUSES ENTRY TO
                                       RECOVERY ROUTINES ONLY IF LOGOUT
                                       FAILED.                               */

    char        SDWACPID[2];    /* ID OF OF FAILING CPU CAUSING ACR          */

    char        SDWARSR1;       /* ADDITIONAL STORAGE FRAME ERROR INDICATORS
                                   AS RETURNED FROM REAL STORAGE
                                   RECONFIGURATION.                          */
#define SDWAMSER    0x02        /* ... STORAGE ERROR ALREADY SET IN FRAME.   */
#define SDWACHNG    0x01        /* ... CHANGE INDICATOR WAS ON IN FRAME.     */

    char        SDWARSR2;       /* ADDITIONAL STORAGE ERROR INDICATORS.      */
#define SDWAOFLN    0x80        /* ... FRAME OFFLINE OR SCHEDULED TO GO OFFLINE
                                       IF SDWAINTC IS ON                     */
#define SDWAINTC    0x40        /* ... INTERCEPT
                                       THE FRAME IS SCHEDULED TO GO OFFLINE,
                                                    OR
                                       THE FRAME HAS INCURRED A STORAGE ERROR,
                                       OR IS V=R                             */
#define SDWASPER    0x20        /* ... STORAGE ERROR PERMANENT ON FRAME.     */
#define SDWANUCL    0x10        /* ... FRAME CONTAINS PERMANENT RESIDENT
                                       STORAGE, I.E. NUCLEUS.                */
#define SDWAFSQA    0x08        /* ... FRAME IN SQA                          */
#define SDWAFLSQ    0x04        /* ... FRAME IN LSQA                         */
#define SDWAPGFX    0x02        /* ... FRAME IS PAGE FIXED                   */
#define SDWAVEQR    0x01        /* ... FRAME IS VIRTUAL = REAL,OR SCHEDULED
                                       FOR VIRTUAL = REAL IF SDWAINTC IS ON  */

    char        _7[2];          /* RESERVED                                  */

    unsigned    SDWARFSA;       /* REAL STORAGE FAILING ADDRESS
                                   ( VALID ONLY IF INDICATED BY SDWASRVL )   */

    unsigned    SDWATIME[2];    /* TIME STAMP OF ASSOCIATED MACHINE CHECK
                                   RECORD                                    */

/*  SDWAFLGS DS    0BL4    INPUT FLAGS DESCRIBING REASONS AND CONDITIONS
    *                      FOR ENTERING A RECOVERY EXIT ROUTINE.             */
    char        SDWAERRA;       /* ERROR TYPE CAUSING ENTRY TO RECOVERY EXIT */
#define SDWAMCHK    0x80        /* ... ON INDICATES MACHINE CHECK            */
#define SDWAPCHK    0x40        /* ... ON INDICATES PROGRAM CHECK            */
#define SDWARKEY    0x20        /* ... ON INDICATES CONSOLE RESTART KEY WAS
                                       DEPRESSED                             */
#define SDWASVCD    0x10        /* ... ON INDICATES TASK ISSUED SVC 13       */
#define SDWAABTM    0x08        /* ... ON INDICATES SYSTEM FORCED SVC 13
                                       (I.E.ABTERM)                          */
#define SDWASVCE    0x04        /* ... ON,INDICATES AN SVC WAS ISSUED BY
                                       A LOCKED OR SRB ROUTINE               */
#define SDWATEXC    0x02        /* ... ON,INDICATES AN UNRECOVERABLE
                                       TRANSLATION FAILURE                   */
#define SDWAPGIO    0x01        /* ... ON,INDICATES A PAGE I/O ERROR         */

    char        SDWAERRB;       /* ADDITIONAL ERROR ENTRY INFORMATION        */
#define SDWATYP1    0x08        /* ... ON TYPE 1 SVC IN CONTROL AT TIME OF
                                       ERROR                                 */
#define SDWAENRB    0x04        /* ... ON ENABLED RB IN CONTROL AT TIME OF
                                       ERROR                                 */
#define SDWALDIS    0x02        /* ... ON A LOGICALLY OR PHYSICALLY DISABLED
                                       ROUTINE WAS IN CONTROL AT THE TIME OF
                                       ERROR.                                */
#define SDWASRBM    0x01        /* ... ON SYSTEM IN SRB MODE AT TIME OF ERROR*/

    char        SDWAERRC;       /* ADDITIONAL ERROR ENTRY INFORMATION        */
#define SDWASTAF    0x80        /* ... ON INDICATES A PREVIOUS (E)STA  OR FRR
                                       EXIT FAILED.                          */
#define SDWASTAI    0x40        /* ... ON A (E)STAI EXIT PREVIOUSLY RECEIVED
                                       CONTROL                               */
#define SDWAIRB     0x20        /* ... ON AN IRB PRECEDED THE RB THAT IS
                                       ASSOCIATED WITH THIS EXIT             */
#define SDWAPERC    0x10        /* ... ON THIS RECOVERY ROUTINE IS BEING
                                       PERCOLATED TO                         */
#define SDWAEAS     0x08        /* ... ON INDICATES A LOWER LEVEL EXIT HAS
                                       RECOGNIZED AN ERROR AND PROVIDED
                                       SERVICEABILITY INFORMATION            */

    char        SDWAERRD;       /* ADDITIONAL ERROR ENTRY INFORMATION        */
#define SDWACLUP    0x80        /* ... ON INDICATES RECOVERY EXIT ONLY TO
                                       CLEANUP AND NOT RETRY (IF ESTA EXIT AND
                                       33E COMPLETION CODE THE DUMP IS TAKEN
                                       AFTER ENTRY TO THE RECOVERY ROUTINE,
                                       IF THE COMPLETION CODE IS OTHER THAN
                                       33E AND IT IS AN ESTA EXIT THE DUMP IS
                                       TAKEN BEFORE ENTRY TO THE RECOVERY
                                       ROUTINE)                              */
#define SDWANRBE    0x40        /* ... ON RB ASSOCIATED WITH THIS ESTA EXIT WAS
                                       NOT IN CONTROL AT TIME OF ERROR NEVER ON
                                       FOR FRRS                              */
#define SDWASTAE    0x20        /* ... ON THIS ESTA EXIT HAS BEEN ENTERED FOR A
                                       PREVIOUS ABEND. NEVER ON FOR FRRS     */
#define SDWACTS     0x10        /* ... ON,THIS TASK WAS NOT IN CONTROL AT TIME
                                       OF ERROR BUT A TASK WITHIN THE SAME
                                       JOBSTEP TREE REQUESTED A 'STEP' ABEND.
                                       ONLY 'ON' IF SDWACLUP IS 'ON'         */
#define SDWAMABD    0x08        /* ... ON,THIS TASK WAS NOT IN CONTROL AT TIME
                                       OF ERROR BUT AN ANCESTOR OF THIS TASK HAS
                                       ABEND'ED. ONLY 'ON' IF SDWACLUP IS 'ON'*/
#define SDWARPIV    0x04        /* ... ON, THE REGISTERS AND PSW AT TIME OF
                                       ERROR ARE UNAVAILABLE                 */
#define SDWAMCIV    0x02        /* ... ON,MACHINE CHECK ERROR INFORMATION
                                       IS UNAVAILABLE.                       */
#define SDWAERFL    0x01        /* ... ON,ERRORID INFORMATION AVAILABLE      */

    unsigned short  SDWAFMID;   /* ASID OF MEMORY IN WHICH ERROR OCCURRED.
                                   =0, IF THE MEMORY IS CURRENT
                                   NOT=0 IF  OTHER MEMORY IS CURRENT
                                   FOR FRRS-
                                      IF THE VALUE IS NON ZERO THE
                                      FRR IS RECEIVING CONTROL IN THE
                                      MASTER SCHEDULER ADDRESS SPACE AND CANNOT
                                      ADDRESS THE PRIVATE AREA OF THE FAILING
                                      ADDRESS SPACE.
                                   FOR ESTA-
                                      IF THE VALUE IS NON ZERO
                                      ENTRY IS DUE TO CROSS MEMORY
                                      ABTERM.                                */
    char        SDWAIOFS;       /* THIS IS THE CURRENT I/O STATUS (THE I/O
                                   PROCESSING REQUESTED BY THE FIRST (E)STA
                                   EXIT IS THE ONLY REQUEST HONORED )        */
#define SDWAIOQR    0x80        /* ... ON,I/O FOR FAILING PROGRAM HAS BEEN
                                       QUIESCED AND IS RESTOREABLE           */
#define SDWAIOHT    0x40        /* ... ON,I/O FOR FAILING PROGRAM HAS BEEN
                                       HALTED AND IS NOT RESTOREABLE         */
#define SDWANOIO    0x20        /* ... ON,FAILING PROGRAM HAS NO I/O
                                       OUTSTANDING                           */
#define SDWANIOP    0x10        /* ... ON,USER REQUESTED NO I/O PROCESSING   */

    char        SDWACPUI;       /* ERRORID LOGICAL CPUID                     */

    unsigned    SDWARTYA;       /* ADDRESS OF RETRY ROUTINE                  */

    unsigned    SDWARECA;       /* ADDRESS OF VARIABLE RECORDING AREA WITHIN
                                   SDWA                                      */

/*  SDWACPUA DS    0CL4    ADDRESS OF CPU HOLDING RESOURCE WHICH CAUSES
    *                      VALID SPIN ON CURRENT CPU - USED WITH RESTART
    *                      KEY ERROR TYPE.IF THIS FIELD IS VALIDLY FILLED
    *                      IN BY AN FRR THE FRRS MAINLINE PROGRAM WILL BE
    *                      RESUMED AT THE NEXT SEQUENTIAL INSTRUCTION.
    *                      NOT VALID FOR ESTAE EXITS.                        */
    char        _8[2];          /* RESERVED                                  */

    unsigned short SDWALCPU;    /* LOGICAL ADDRESS OF CPU HOLDING RESOURCE   */

/*  SDWAPARQ DS    0BL4    FLAGS SET BY RECOVERY ROUTINE TO REQUEST FURTHER
    *                      PROCESSING ACTION                                 */
    char        SDWARCDE;       /* RETURN CODE FROM RECOVERY ROUTINE TO INDICATE
                                   RETRY OR TERMINATION                      */
#define SDWACWT     0           /* ... 0 ,CONTINUE WITH TERMINATION. THIS
                                       INDICATION IMPLIES PERCOLATION        */
#define SDWARETY    4           /* ... 4 ,RETRY USING RETRY ADDRESS IN SDWARTYA
                                       FIELD                                 */
#define SDWAPSTI    16          /* ... 16,PREVENT FURTHER (E)STAI PROCESSING */

    char        SDWAACF2;       /* FLAGS TO INDICATE ADDITIONAL PROCESSING
                                   REQUESTS                                  */
#define SDWARCRD    0x80        /* ... ON,RECORDING REQUESTED                */
#define SDWASPIN    0x20        /* ... ON,PROGRAM INTERRUPTED VIA  THE RESTART
                                       KEY WAS IN A VALID SPIN(SET BY THE SETRP
                                       MACRO WHEN CPU ADDRESS IS SPECIFIED
                                       ALONG WITH THE CPU ADDRESS IN SDWACPUA
                                       FIELD TO ALLOW RESTART OF THE ALTERNATE
                                       CPU)                                  */
#define SDWAUPRG    0x08        /* ... ON,UPDATED REGISTERS STARTING WITH
                                       SDWASR00 ARE TO BE USED FOR RETRY     */
#define SDWAFREE    0x04        /* ... ON,SDWA/RTCA TO BE FREED PRIOR TO RETRY.
                                       ONLY VALID FOR ESTA EXITS             */

    char        SDWAACF3;       /* FLAGS INDICATING WHAT GLOBAL LOCKS ARE TO
                                   BE FREED (KEY 0 SUPERVISOR ONLY)
                                   ONLY VALID FOR FRRS.                      */
#define SDWADISP    0x10        /* ... ON,THE DISPATCHER LOCK                */
#define SDWAASMP    0x08        /* ... ON,THE ASM CLASS LOCK                 */
#define SDWASALL    0x04        /* ... ON, THE SALLOC LOCK                   */
#define SDWAIPRG    0x02        /* ... ON, THE IOSYNCH LOCK                  */
#define SDWAICAT    0x01        /* ... ON,THE IOSCAT LOCK                    */

    char        SDWAACF4;       /* ADDITIONAL LOCKS TO BE FREED  FOR FRRS    */
#define SDWAIUCB    0x80        /* ... ON, THE IOSUCB LOCK                   */
#define SDWAILCH    0x40        /* ... ON, THE IOSLCH LOCK                   */
#define SDWATNCB    0x20        /* ... RESERVED LOCK                         */
#define SDWATDNB    0x10        /* ... RESERVED LOCK                         */
#define SDWATADB    0x08        /* ... RESERVED LOCK                         */
#define SDWAOPTM    0x04        /* ... ON,THE SYSTEM RESOURCES MGR(SRM)
                                       LOCK LOCK                             */
#define SDWACMS     0x02        /* ... ON,THE CMS LOCK                       */
#define SDWAFLLK    0x01        /* ... ON,THE LOCAL LOCK                     */

/*  SDWALKWA DS    0CL32   LOCK AREA                              @ZA05516
    SDWALKWS DS    0CL32   LOCKWORDS REQUIRED TO FREE GLOBAL LOCKS
    *                      ONLY USED FOR FRRS                                */
    unsigned    SDWAICLW;       /* LOCKWORD FOR THE IOSCAT LOCK              */
    unsigned    SDWAIULW;       /* LOCKWORD FOR THE IOSUCB LOCK              */
    unsigned    SDWAILLW;       /* LOCKWORD FOR THE IOSLCH LOCK              */
    unsigned    SDWAIPLW;       /* LOCKWORD FOR THE IOSYNCH LOCK             */
    unsigned    SDWAAPLW;       /* LOCKWORD FOR THE ASM CLASS LOCK           */
    unsigned    SDWATNLW;       /* LOCKWORD - RESERVED                       */
    unsigned    SDWATDLW;       /* LOCKWORD - RESERVED                       */
    unsigned    SDWATALW;       /* LOCKWORD - RESERVED                       */

    unsigned short SDWAASID;    /* ASID FOR LOGREC DEBUGGING                 */
    unsigned short SDWASEQ_;    /* ERRORID SEQUENCE NUMBER                   */

/*  SDWARECP DS    0CL24   RECORDING PARAMETERS (MODULE,CSECT AND RECOVERY
    *                      ROUTINE NAMES-RESPECTIVELY)                       */
    char        SDWAMODN[8];    /* THE MODULE NAME INVOLVED IN THE ERROR
                                   (SUPPLIED BY THE RECOVERY ROUTINE)        */
    char        SDWACSCT[8];    /* THE CSECT NAME INVOLVED IN THE ERROR
                                   (SUPPLIED BY THE RECOVERY ROUTINE)        */
    char        SDWAREXN[8];    /* THE RECOVERY ROUTINE NAME HANDLING THE
                                   ERROR                                     */

    unsigned    SDWADPLA;       /* POINTER TO DUMP PARAMETER LIST
                                   RESIDING IN SDWA.                         */

/*  SDWASNPA DS   0CL8     SNAP PARAMETER LIST FLAGS                         */
/*  SDWADUMP DS   0CL4     DUMP CHARACTERISTICS                              */
    char        SDWADPID;       /* ID OF DUMP REQUESTED                      */
    char        SDWADPFS;       /* DUMP FLAGS                                */
#define SDWADPT     0x80        /* ... ALWAYS OFF,INDICATES SNAP DUMP REQUEST*/
#define SDWADLST    0x40        /* ... ALWAYS ON,INDICATES THAT OS/VS2 REL. 2
                                       DUMP PARAMETER LIST SUPPLIED USED BY RTM
                                       TO INDICATE DUMP OPTIONS ARE AVAILABLE
                                       IN THE SDWA                           */
#define SDWAENSN    0x20        /* ... ON,ENHANCED DUMP OPTIONS              */
#define SDWASLST    0x02        /* ... ON,STORAGE LISTS SUPPLIED FOR DUMP    */

    char        _9[2];          /* RESERVED                                  */

/*  SDWADDAT DS   0CL4     SDATA AND PDATA OPTIONS                           */
/*  SDWASDAT DS   0CL2     SDATA OPTIONS                          @G33SPHW   */
    char        SDWASDA0;       /* SDATA OPTIONS FLAG ONE                    */
#define SDWANUC     0x80        /* ... DISPLAY NUCLEUS                       */
#define SDWASQA     0x40        /* ... DISPLAY SQA                           */
#define SDWALSQA    0x20        /* ... DISPLAY LSQA                          */
#define SDWASWA     0x10        /* ... DISPLAY SWA                           */
#define SDWAGTF     0x08        /* ... DISPLAY GTF INCORE TRACE TABLE        */
#define SDWACBS     0x04        /* ... FORMAT AND DISPLAY CONTROL BLOCKS     */
#define SDWAQQS     0x02        /* ... FORMAT AND DISPLAY QCBS/QELS          */
#define SDWADM      0x01        /* ... FORMAT DATA MGT CONTROL BLOCKS        */

    char        SDWASDA1;       /* SDATA OPTIONS                             */
#define SDWAIO      0x80        /* ... FORMAT I/O SUPERVISOR CONTROL BLOCKS  */
#define SDWAERR     0x40        /* ... FORMAT ERROR CONTROL BLOCKS           */

    char        SDWAPDAT;       /* PDATA OPTIONS                             */
#define SDWADSAS    0x80        /* ... DISPLAY SAVE AREAS                    */
#define SDWADSAH    0x40        /* ... DISPLAY SAVE AREA HEADER              */
#define SDWADREG    0x20        /* ... DISPLAY REGISTERS                     */
#define SDWATLPA    0x10        /* ... DISPLAY LPA MODULES OF TASK           */
#define SDWATJPA    0x08        /* ... DISPLAY JPA MODULES OF TASK           */
#define SDWADPSW    0x04        /* ... DISPLAY PSW                           */
#define SDWAUSPL    0x02        /* ... DISPLAY USER SUBPOOLS                 */

    char        _10;            /* RESERVED                                  */

/*  SDWADPSA DS   0CL36    DUMP RANGES AREA                                  */
/*  SDWADPSL DS   0CL32    DUMP STORAGE LISTS (MAX 4 RANGES AVAILABLE)       */
    unsigned    SDWAFRM1;       /* BEGINNING ADDRESS FOR STORAGE RANGE 1     */
    unsigned    SDWATO1;        /* ENDING ADDRESS FOR STORAGE RANGE 1        */

    unsigned    SDWAFRM2;       /* BEGINNING ADDRESS FOR STORAGE RANGE2      */
    unsigned    SDWATO2;        /* ENDING ADDRESS FOR STORAGE RANGE 2        */

    unsigned    SDWAFRM3;       /* BEGINNING ADDRESS FOR STORAGE RANGE 3     */
    unsigned    SDWATO3;        /* ENDING ADDRESS FOR STORAGE RANGE 3        */

    unsigned    SDWAFRM4;       /* BEGINNING ADDRESS FOR STORAGE RANGE 4     */
    unsigned    SDWATO4;        /* ENDING ADDRESS FOR STORAGE RANGE 4        */

    unsigned    _11;            /* RESERVED                                  */

    char        SDWARCPL[28];   /* RESERVED FOR RTM USE.                     */

    unsigned    SDWACOMP;       /* THIS WORD IS PROVIDED FOR COMMUNICATION OF
                                   ADDITIONAL RECOVERY DATA ON A PER COMPONENT
                                   BASIS (FOR OS/VS2 RELEASE 2 THIS FIELD IS
                                   ONLY USED BY DATA MANAGER )               */

    char        SDWAERTM[4];    /* ERRORID TIME STAMP                        */

/*  SDWARA   DS   0CL112   VARIABLE RECORDING AREA PREFIXED BY A TWO BYTE
    *                      LENGTH FIELD OF AREA AND A TWO BYTE
    *                      LENGTH FIELD OF USER SUPPLIED RECORDING DATA      */
    char        SDWAVRAL[2];    /* LENGTH OF VARIABLE RECORDING AREA         */

    char        SDWADPVA;       /* DEFINES DUMPING OF DATA IN VARIABLE AREA  */
#define SDWAHEX     0x80        /* ... DATA TO BE DUMPED BY EREP IN HEX.     */
#define SDWAEBC     0x40        /* ... DATA TO BE DUMPED BY EREP IN EBCDIC   */

    char        SDWAURAL;       /* LENGTH OF USER SUPPLIED RECORDING DATA    */

    char        SDWAVRA[108];   /* VARIABLE RECORDING AREA                   */

/*  SDWAEND  DS   0D       END OF SDWA FORCED TO DOUBLE WORD                 */
};
#define SDWALEN     ((sizeof(SDWA)+7) & 0x7FFFFFF8)
#define SDWAFLEN    (SDWALEN+272)   /* GETMAIN LENGTH FOR FRR SDWA           */

#pragma pack(reset)

#endif
