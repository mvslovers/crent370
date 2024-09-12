@@PPAGET TITLE '@ @ P P A G E T ***  Retrieve CLIBPPA from stack'
         COPY  PDPTOP
         PRINT OFF
         USING PSA,R0
         PRINT ON
         COPY  CLIBCRT
         COPY  CLIBPPA                  CLIB Program Properties Area
         CSECT
         ENTRY @@PPAGET
@@PPAGET DS    0H
         SAVE  (14,12),,@@PPAGET
         LA    R12,0(,R15)
         USING @@PPAGET,R12
         SR    R15,R15
*
         USING PSA,R0
         L     R2,PSATOLD
         USING TCB,R2
         SR    R3,R3
         ICM   R3,B'0111',TCBFSAB       -> first TCB save area
         BZ    PPAOWNER                 No save area, try owner TCB
         ICM   R3,B'1111',8(R3)         -> next TCB save area
         BZ    PPAOWNER                 No next, try owner TCB
         CL    R3,=F'16777215'          GT X'FFFFFF'?
         BH    PPAOWNER                 Yes, not 24 bit address
         USING CLIBPPA,R3               Program Properties Area
         CLC   PPAEYE,=A(PPAEYE$)       Valid eye catcher?
         BE    PPAFND                   Yes, PPA found
*
* See if owner TCB has PPA
PPAOWNER DS    0H
         ICM   R2,B'0111',TCBOTC+1      Get owner TCB
         BZ    PPASTCK                  None, check stack
*
         SR    R3,R3
         ICM   R3,B'0111',TCBFSAB       -> first TCB save area
         BZ    PPAONEXT                 No save area, try next owner
         ICM   R3,B'1111',8(R3)         -> next TCB save area
         BZ    PPAONEXT                 No next, try next owner TCB
         CL    R3,=F'16777215'          GT X'FFFFFF'?
         BH    PPAONEXT                 Yes, not 24 bit address
         CLC   PPAEYE,=A(PPAEYE$)       Valid eye catcher?
         BE    PPAFND                   Yes, PPA found
*
PPAONEXT DS    0H
         C     R2,TCBJSTCB              Is this the Job Step TCB?
         BE    PPASTCK                  Yes, check stack
         B     PPAOWNER                 No, try owner TCB
*
* We didn't find the PPA as the "next" SA in the TCBFSA.
* So we'll run the SA chain backward and try to find it.
PPASTCK  DS    0H
         L     R2,PSATOLD
         ICM   R3,B'1111',4(R13)        Get prev SA
PPALOOP  DS    0H
         CLC   PPAEYE,=A(PPAEYE$)       Valid eye catcher?
         BE    PPAFND                   Yes, PPA found
         ICM   R3,B'1111',4(R3)         Get prev SA
         BZ    PPAFAIL                  Zero, not found
         CLM   R3,B'0111',TCBFSAB       Same as TCBFSAB?
         BE    PPAFAIL                  Yes, not found
         B     PPALOOP
*
PPAFND   DS    0H
         B     PPAEXIT
PPAFAIL  DS    0H
         SR    R3,R3
PPAEXIT  DS    0H
         LR    R15,R3                   Return PPA
         RETURN (14,12),RC=(15)
         LTORG ,
         TITLE 'Dummy Sections'
         IKJTCB LIST=YES
         IEZJSCB
         IHAPSA
         IHARB
         IHACDE
         END
