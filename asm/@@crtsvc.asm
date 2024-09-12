@@CRTSVC TITLE '@ @ C R T S V C  ***  MVS startup routine for C SVC'
         COPY  PDPTOP
SUBPOOL  EQU   250               Used for C style stack allocation
         USING PSA,R0
         PRINT ON
         CSECT
         ENTRY @@CRTSVC
         USING @@CRTSVC,R6
@@CRTSVC DS    0H                Note: we do not save registers
         B     AROUND            Skip over eye catcher
         DC    AL1(EYELEN)
EYE      DC    C'@@CRTSVC &SYSDATE &SYSTIME'
EYELEN   EQU   *-EYE
AROUND   DS    0H
         LA    R12,0(,R6)        Establish base register
         DROP  R6                (@@CRTSVC)
         USING @@CRTSVC,R12
         LR    R8,R14            Save R14
         LR    R9,R15            Save R15
         LR    R10,R0            Save R0
         LR    R11,R1            Save R1
*
* Allocate a save area + stack space
         GETMAIN RC,LV=STACKLEN,SP=SUBPOOL
         LTR   R2,R15            Save return code and test
         BZ    CHAINSTG          Success
*
* No storage available
*   fail the request (GETMAIN RC in R0, 0 in R1, -1 in R15)
         WTO   '*** Out Of Memory ***'
         LR    R0,R2             Save return code from GETMAIN
         SLR   R1,R1             Clear R1
         L     R15,=F'-1'        Indicate failure
         LR    R14,R8            Get return address
         BR    R14               Return to caller
*
* Chain the save areas
CHAINSTG DS    0H
         ST    R13,4(,R1)        Chain prev save area
***      ST    R1,8(,R13)        Chain next save area
         LR    R13,R1            Use next save area
         USING STACK,R13         Our Save Area
*
* Create C style stack frame
         LA    R0,0
         ST    R0,DUMMYPTR       Unused in C, used by PL/1
         LA    R0,MAINSTK        Next available stack location
         ST    R0,STACKNAB       => Next available stack (NAB)
*
* Build parameter list for @@SVC
         LA    R1,SVCREGS        => SVC registers
         ST    R1,PARMREGS       Save in parameter list
         STM   R9,R11,SVCREGS    Save R15, R0, R1
         STM   R3,R7,SVCCVT      Save CVT, TCB, SVRB, SVC, ASCB
         SLR   R0,R0             Clear for insert
         ICM   R0,B'0111',RBLINKB-RBBASIC(R5)
         ST    R0,SVCRBLNK       Save RBLINK address
         USING TCB,R4
         MVC   SVCJSCB,TCBJSCB   Save JSCB address
*
* Call @@SVC with parameter list
         LA    R1,PARMLIST       => @@SVC paremeter list
         L     R15,=V(@@SVC)
         BALR  R14,R15
*
* We should be in supervisor state and key 0
         MODESET EXTKEY=ZERO
*
* Get return regs (R15,R0,R1) from @@SVC
         LM    R9,R11,SVCREGS    save R15,R0,R1
*
* Release our savearea and stack storage
         LR    R1,R13            R1=A(storage to be freed)
         L     R13,4(,R1)        Original save area
         FREEMAIN RU,LV=STACKLEN,A=(R1),SP=SUBPOOL
         DROP  R13               (STACK)
*
* Return to system
         LR    R14,R8            Callers R14
         LR    R15,R9            Return R15
         LR    R0,R10            Return R0
         LR    R1,R11            Return R1
         BR    R14               Return to caller
         LTORG ,
         TITLE 'Our Save Area, Variables and Stack Frame'
STACK    DSECT
SAVEAREA DS    18F               Standard MVS style save area
DUMMYPTR DS    F                 => PL/I Language Work Space N/A
STACKNAB DS    F                 => Next Available Byte (NAB)
*
* Parameter list for @@SVC
PARMLIST DS    0D                Parameter list passed to @@SVC
PARMREGS DS    A                 => SVC registers
*
* Values passed to @@SVC via pointer reference
SVCREGS  DS    0F
SVCR15   DS    F                 SVC R15            (input/output)
SVCR0    DS    F                 SVC R0             (input/output)
SVCR1    DS    F                 SVC R1             (input/output)
SVCCVT   DS    A                 CVT address        (input)
SVCTCB   DS    A                 TCB address        (input)
SVCSVRB  DS    A                 SVRB address       (input)
SVCEPA   DS    A                 SVC entry address  (input)
SVCASCB  DS    A                 ASCB address       (input)
SVCRBLNK DS    A                 RBLINK address     (input)
SVCJSCB  DS    A                 JSCB address       (input)
         DS    2F                unused
*
* Stack area (next available byte 'STACKNAB' points here)
         DS    0D
MAINSTK  DS    8192F             stack for @@SVC -> svcmain()
MAINLEN  EQU   *-MAINSTK
STACKLEN EQU   *-STACK
         TITLE 'Dummy Sections'
*
         IKJTCB LIST=YES
         IEZJSCB
         IHAPSA
         IHARB
         IHACDE
         END
