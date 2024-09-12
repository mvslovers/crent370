 TITLE '/home/mike/repos/crent370/clib/vsprintf.c'
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
* external function 'vsprintf' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'vsprintf'
VSPRINTF PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'vsprintf' code
         L     2,0(11) ==> s
         MVC   88(4,13),4(11) ==> format
         MVC   92(4,13),8(11) ==> arg
         MVC   96(4,13),=F'0'
         ST    2,100(13) ==> s
         LA    1,88(,13)
         L     15,=V(VVPRINTF)
         BALR  14,15
         LTR   15,15 ==> ret
         BL    @@L2
         SLR   3,3
         STC   3,0(15,2) ==> ret
@@L2     EQU   *
* Function 'vsprintf' epilogue
         PDPEPIL
* Function 'vsprintf' literal pool
         DS    0D
         LTORG
* Function 'vsprintf' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
