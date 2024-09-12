 TITLE '/home/mike/repos/crent370/clib/@@uastep.c'
         COPY  PDPTOP
         CSECT
* GNU C version 3.2.3 - c2asm370 version 1.0 (mvs)
*        compiled by GNU C version 13.2.0.
*
* options passed:  -lang-c -I. -I/home/mike/repos/crent370/include
* -iprefix -D__GNUC__=3 -D__GNUC_MINOR__=2 -D__GNUC_PATCHLEVEL__=3
* -D__GXX_ABI_VERSION=102 -D__GCC__ -D__MVS__ -D__GCC__ -D__MVS__
* -Asystem=mvs -Acpu=i370 -Amachine=i370 -D__OPTIMIZE__
* -D__STDC_HOSTED__=1 -trigraphs -O1 -fverbose-asm
* 
* options enabled:  -fdefer-pop -fthread-jumps -fpeephole
* -ffunction-cse -fkeep-static-consts -fpcc-struct-return -fgcse-lm
* -fgcse-sm -fsched-interblock -fsched-spec -fbranch-count-reg
* -fcprop-registers -fcommon -fverbose-asm -fgnu-linker
* -fargument-alias -fmerge-constants -fident
* -fguess-branch-probability -fmath-errno -ftrapping-math
* -mchar-instructions -mno-pickax -mno-constants-first
*
* Program text area
         DS    0F
         EJECT
* external function '__uastep' prologue
* frame base=88, local stack=8, call args=0
&FUNC    SETC  '__uastep'
@@UASTEP PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__uastep' code
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         LR    3,15 ==> crt
         MVC   88(4,13),=F'0' ==> rc
         TESTAUTH FCTN=1
         ST    15,88(13) ==> rc
         L     2,88(13) ==> rc
         LTR   2,2
         BNE   @@L3
         LTR   15,15 ==> crt
         BE    @@L4
         IC    2,269(15) ==> .crtauth
         N     2,=F'64'
         CLM   2,1,=XL1'00'
         BE    @@L3
@@L4     EQU   *
         
         MODESET KEY=ZERO,MODE=SUP
         ICM   1,15,PSATOLD-PSA(0) Get our TCB address
         ICM   1,15,TCBJLB-TCB(1)  Get STEPLIB DCB
         LA    1,0(,1)             Purify DCB address
         LTR   14,1                Save DCB address
         BZ    QUITOFF             No STEPLIB
         USING IHADCB,1            DECLARE IT
         L     1,DCBDEBAD          LOAD DEB FOR STEPLIB
         N     1,=X'00FFFFFF'      FIX HIGH BYTE
         USING DEBBASIC,1
RESETAPF DS    0H
         NI    DEBFLGS1,X'FF'-DEBAPFIN   TURN OFF APF LIBRARY BIT
         DROP  1
QUITOFF  DS    0H
         MODESET KEY=NZERO,MODE=PROB
         LTR   3,3 ==> crt
         BE    @@L3
         NI    269(3),191 ==> .crtauth
@@L3     EQU   *
         L     15,88(13) ==> crt,rc
* Function '__uastep' epilogue
         PDPEPIL
* Function '__uastep' literal pool
         DS    0D
         LTORG
* Function '__uastep' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         PRINT NOGEN
         IHAPSA ,            MAP LOW STORAGE
         CVT DSECT=YES
         IKJTCB DSECT=YES
         DCBD DSORG=PO,DEVD=DA
         IEZDEB
         PRINT GEN
         CSECT
         END
