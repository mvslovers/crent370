 TITLE '/home/mike/repos/crent370/clib/fprintf.c'
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
* external function 'fprintf' prologue
* frame base=88, local stack=8192, call args=16
&FUNC    SETC  'fprintf'
FPRINTF  PDPPRLG CINDEX=0,FRAME=8296,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'fprintf' code
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'8192'
         MVC   96(4,13),4(11)
         LA    2,8(,11) ==> arg
         ST    2,100(13) ==> arg
         LA    1,88(,13)
         L     15,=V(VSNPRINT)
         BALR  14,15
         L     2,=F'8192'
         CLR   15,2 ==> len
         BNH   @@L2
         LR    15,2 ==> len
@@L2     EQU   *
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'1'
         ST    15,96(13) ==> len
         MVC   100(4,13),0(11) ==> stream
         LA    1,88(,13)
         L     15,=V(FWRITE)
         BALR  14,15
* Function 'fprintf' epilogue
         PDPEPIL
* Function 'fprintf' literal pool
         DS    0D
         LTORG
* Function 'fprintf' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
