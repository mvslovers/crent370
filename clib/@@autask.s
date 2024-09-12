 TITLE '/home/mike/repos/crent370/clib/@@autask.c'
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
         
&FUNC    SETC '__autask'
* Program text area
         DS    0F
         EJECT
* external function '__autask' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  '__autask'
@@AUTASK PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__autask' code
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         LR    3,15 ==> crt
         MVC   96(4,13),=F'0' ==> rc
         TESTAUTH FCTN=1
         ST    15,96(13) ==> rc
         L     2,96(13) ==> rc
         LTR   2,2
         BE    @@L3
         MVC   88(4,13),=A(@@2)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         TESTAUTH FCTN=1
         ST    15,96(13) ==> rc
         L     2,96(13) ==> rc
         LTR   2,2
         BNE   @@L3
         LTR   3,3 ==> crt
         BE    @@L3
         OI    269(3),128 ==> .crtauth
@@L3     EQU   *
         L     15,96(13) ==> crt,rc
* Function '__autask' epilogue
         PDPEPIL
* Function '__autask' literal pool
         DS    0D
         LTORG
* Function '__autask' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'authorize'
         DS    0F
         EJECT
* static function 'authorize' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'authorize'
@@2      PDPPRLG CINDEX=1,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'authorize' code
         SR    0,0
         LA    1,1
         SVC   244
* Function 'authorize' epilogue
         PDPEPIL
* Function 'authorize' literal pool
         DS    0D
         LTORG
* Function 'authorize' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         PRINT NOGEN
         IHAPSA ,            MAP LOW STORAGE
         CVT DSECT=YES
         IKJTCB DSECT=YES
         DCBD DSORG=PO,DEVD=DA
         IEZDEB
         PRINT GEN
         CSECT
         END
