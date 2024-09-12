 TITLE '/home/mike/repos/crent370/clib/@@uatask.c'
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
* external function '__uatask' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__uatask'
@@UATASK PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__uatask' code
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         LR    3,15 ==> crt
         SLR   4,4 ==> rc
         LTR   15,15 ==> crt
         BE    @@L3
         IC    2,269(15) ==> .crtauth
         N     2,=F'-128'
         CLM   2,1,=XL1'00'
         BE    @@L3
         MVC   88(4,13),=A(@@2)
         ST    4,92(13) ==> rc
         LA    1,88(,13)
         L     15,=V(@@@TRY)
         BALR  14,15
         NI    269(3),127 ==> .crtauth
@@L3     EQU   *
         LR    15,4 ==> rc
* Function '__uatask' epilogue
         PDPEPIL
* Function '__uatask' literal pool
         DS    0D
         LTORG
* Function '__uatask' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'unauthorize'
         DS    0F
         EJECT
* static function 'unauthorize' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'unauthorize'
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
* Function 'unauthorize' code
         SR    0,0
         SR    1,1
         SVC   244
* Function 'unauthorize' epilogue
         PDPEPIL
* Function 'unauthorize' literal pool
         DS    0D
         LTORG
* Function 'unauthorize' page table
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
