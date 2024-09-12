 TITLE '/home/mike/repos/crent370/clib/iefssreq.c'
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
* external function 'iefssreq' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'iefssreq'
IEFSSREQ PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'iefssreq' code
         SLR   2,2 ==> rc
         L     2,16(2) ==> cvt
         L     2,296(2) ==> jesct
         L     3,20(2) ==> ssreq
         L     2,0(11) ==> ssob
         A     2,=F'-2147483648' ==> ssob
         MODESET MODE=SUP
         ST    2,88(13) ==> ssob
         LA    1,88(,13)
         LA    15,0(3) ==> ssreq
         BALR  14,15
         LR    2,15 ==> rc
         MODESET MODE=PROB
         LR    15,2 ==> rc
* Function 'iefssreq' epilogue
         PDPEPIL
* Function 'iefssreq' literal pool
         DS    0D
         LTORG
* Function 'iefssreq' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
