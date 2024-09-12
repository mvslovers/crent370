@@CRT0   TITLE '@ @ C R T 0  ***  Mini startup routine for C main pgm'
***********************************************************************
*  Provided by: Mike Rayborn                                          *
*                                                                     *
*  This startup code create a minimal environment for C programs      *
*                                                                     *
*  RELEASED TO THE PUBLIC DOMAIN                                      *
***********************************************************************
         COPY  PDPTOP
         PRINT OFF
*
SUBPOOL  EQU   0
         USING PSA,R0
         PRINT ON
         COPY  CLIBCRT
         COPY  CLIBPPA                  CLIB Program Properties Area
         CSECT
         ENTRY @@CRT0
@@CRT0   DS    0H
         SAVE  (14,12),,@@CRT0
         LA    R12,0(,R15)
         USING @@CRT0,R12
         LR    R10,R0
         LR    R11,R1
*
         WXTRN @@STKLEN
         ICM   R8,15,=V(@@STKLEN)       Get stack length address
         BZ    USEDFLT                  No, use default
         L     R8,0(R8)                 Yes, load stack size value
         C     R8,=F'4096'              At least 4K?
         BNL   ROUNDUP                  Yes, continue
USEDFLT  DS    0H
         L     R8,=A(STACKLEN)          Default stack length
ROUNDUP  DS    0H
         LA    R8,7(,R8)                Plus 7 for rounding
         N     R8,=X'00FFFFF8'          Round to nearest double word
         LA    R0,SUBPOOL               Subpool number
         SLL   R0,24                    Shift into high byte
         ALR   R0,R8                    Plus size of storage we want
         GETMAIN R,LV=(0)
*
         ST    R13,4(,R1)
         ST    R1,8(,R13)
         LR    R13,R1
         USING STACK,R13                Our Save Area
*
CRTSETUP DS    0H
         LA    R0,0
         ST    R0,DUMMYPTR       Unused in C, used by PL/1
         LA    R0,MAINSTK        Next available stack location
         ST    R0,THEIRSTK       => Next available stack (NAB)
*
* Save R13 in CRTSAVE
         L     R15,=V(@@CRTGET)
         BALR  R14,R15           Get our CLIBCRT area
         L     R0,CRTSAVE-CLIBCRT(,R15) Get previous save area
         ST    R0,OLDSAVE        Save for later
         ST    R13,CRTSAVE-CLIBCRT(,R15) Save our save area address
*
         L     R2,PSATOLD
         USING TCB,R2
*
         L     R7,TCBRBP
         USING RBBASIC,R7
         SLR   R8,R8
         ICM   R8,B'0111',RBCDE1
         DROP  R7                (RBBASIC)
*
         USING CDENTRY,R8
         MVC   PGMNAME,CDNAME
         MVI   PGMNAMEN,0
         DROP  R8                (CDENTRY)
*
         L     R2,TCBJSCB
         USING IEZJSCB,R2
         LH    R2,JSCBTJID
         ST    R2,TYPE           TSO terminal job identifier
         DROP  R2                (IEZJSCB)
*
         ST    R10,PGMR0         R10 == R0 on entry to @@CRT0
         ST    R11,PGMR1         R11 == R1 on entry to @@CRT0
         LA    R2,PGMNAME
         ST    R2,PGMNPTR        A(program name)
*
         LA    R1,PARMLIST       A(parms,program,type)
         L     R15,=V(@@START)
         BALR  R14,R15           Should never return
*
* The call to @@START never returns because it will call @@EXIT
* after it calls main().
* But just in case @@START returns here, we'll call @@EXIT which
* eventually calls @@EXITA below.
         LA    R1,=F'-1'
         L     R15,=V(@@EXIT)
         BR    R15               Just in case @@START returns
***      LTORG
         TITLE '@@EXITA - exit C runtime environment'
         ENTRY @@EXITA
@@EXITA  DS    0H
* SWITCH BACK TO OUR OLD SAVE AREA
         LA    R12,0(,R15)
         USING @@EXITA,R12
         L     R9,0(R1)          Get exit(rc) value
*
* Get save area address from CLIBCRT area
         L     R15,=V(@@CRTGET)
         BALR  R14,R15           Get our CLIBCRT area
         L     R13,CRTSAVE-CLIBCRT(,R15) Restore original stack
		 L     R0,OLDSAVE        Get old CRTSAVE value
         ST    R0,CRTSAVE-CLIBCRT(,R15) restore CRTSAVE
*
* Release stack storage
*
         LR    R1,R13            R1=A(storage to be freed)
         L     R13,4(,R1)        Original save area
***      WXTRN @@STKLEN
         ICM   R8,15,=V(@@STKLEN)       Get stack length address
         BZ    EXITDFLT                 No, use default
         L     R8,0(R8)                 Yes, load stack size value
         C     R8,=F'4096'              At least 4K?
         BNL   EXITSIZE                 Yes, continue
EXITDFLT DS    0H
         L     R8,=A(STACKLEN)          Default stack length
EXITSIZE DS    0H
         LA    R8,7(,R8)                Plus 7 for rounding
         N     R8,=X'00FFFFF8'          Round to nearest double word
         LA    R0,SUBPOOL               Subpool number
         SLL   R0,24                    Shift into high byte
         ALR   R0,R8                    Plus size of storage we want
         FREEMAIN R,LV=(0),A=(R1)
*
* Return to system
         LR    R15,R9            Get exit(rc) value
         RETURN (14,12),RC=(15)
         LTORG
         TITLE 'Dummy Sections'
* Stack for C thread
STK      DSECT
STKSV    DS    18F               00 (0)  callers registers go here
STKSVLWS DS    A                 48 (72) PL/I Language Work Space N/A
STKSVNAB DS    A                 4C (76) next available byte -------+
STKCTHD  DS    A                 50 (80) A(CTHDTASK)                |
STKAVAIL DS    F                 54 (84) unused/available           |
STKNAB   DS    0D                58 stack next available byte <-----+
*
         IKJTCB LIST=YES
         IEZJSCB
         IHAPSA
         IHARB
         IHACDE
STACK    DSECT
SAVEAREA DS    18F
DUMMYPTR DS    F                 => PL/I Language Work Space N/A
THEIRSTK DS    F                 => Next Available Byte (NAB)
PARMLIST DS    0F                Parameter list passed to @@START
PGMR0    DS    F                 R0 at entry to program
PGMNPTR  DS    F                 A(program name)
TYPE     DS    F                 F'TSO job id'
PGMR1    DS    F                 R1 at entry to program
PGMNAME  DS    CL8
PGMNAMEN DS    C                 NUL BYTE FOR C
OLDSAVE  DS    F                 Old CRTSAVE value
         DS    0D
MAINSTK  DS    16384F            stack for @@START -> main()
MAINLEN  EQU   *-MAINSTK
STACKLEN EQU   *-STACK
         END

