@@EXITA  TITLE '@ @ E X I T A ***  Terminate C environment'
         COPY  PDPTOP
         PRINT OFF
         USING PSA,R0
         PRINT ON
         COPY  CLIBCRT
         COPY  CLIBPPA                  CLIB Program Properties Area
         CSECT
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
*
* Cleanup C process level area
         L     R15,=V(@@GRTRES)
         BALR  R14,R15           Reset CLIBGRT area
*
* Cleanup C main task (thread) area
         L     R15,=V(@@CRTRES)
         BALR  R14,R15           Release CLIBCRT, reset TCBUSER
*
* Release stack storage
*
         L     R2,PSATOLD
         USING TCB,R2
         SR    R15,R15
         ICM   R15,B'0111',TCBFSAB => TCB first save area
         L     R6,8(,R15)        get PPA from fsa next value
         USING CLIBPPA,R6
*
         L     R0,PPASAVE        get original "next" value
         ST    R0,8(,R15)        save original "next" in fsa
         LR    R1,R6             R1=A(storage to be freed)
         L     R13,4(,R1)        Original save area
         ICM   R0,1,PPASUBPL     Get subpool number
         SLL   R0,24             Put subpool in high byte
         AL    R0,PPASTKLN       Plus size of storage
         FREEMAIN R,LV=(0),A=(R1)
         DROP  R6                (CLIBPPA)
*
* Return to system
         LR    R15,R9            Get exit(rc) value
         RETURN (14,12),RC=(15)
         LTORG
         TITLE 'Dummy Sections'
         IKJTCB LIST=YES
         IEZJSCB
         IHAPSA
         IHARB
         IHACDE
         END
