 TITLE '/home/mike/repos/crent370/clib/@@vsmdfy.c'
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
* external function '__vsmdfy' prologue
* frame base=88, local stack=64, call args=0
&FUNC    SETC  '__vsmdfy'
@@VSMDFY PDPPRLG CINDEX=0,FRAME=152,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__vsmdfy' code
         L     8,0(11) ==> vs
         L     3,4(11) ==> rec
         L     2,8(11) ==> reclen
         L     9,12(11) ==> key
         LA    6,88(,13)
         LA    7,64(0,0)
         SLR   4,4
         LR    5,4
         MVCL  6,4
         LR    4,8 ==> vs
         A     4,=F'104'
         LA    5,88(,13)
         
         MODCB RPL=(4),RECLEN=(2),                                     X ==> reclen
               AREALEN=(2),AREA=(3),MF=(G,(5)) ==> reclen,rec
         LTR   9,9 ==> key
         BE    @@L3
         IC    3,21(8) ==> .type
         LA    2,255(,3)
         CLM   2,1,=XL1'01'
         BH    @@L4
         MODCB RPL=(4),ARG=(9),MF=(G,(5)) ==> key
         B     @@L3
@@L4     EQU   *
         IC    2,21(8) ==> .type
         CLM   2,1,=XL1'00'
         BNE   @@L3
         LR    3,8 ==> vs
         A     3,=F'104'
         LA    2,88(,13)
         L     4,16(11) ==> keylen
         MODCB RPL=(3),ARG=(9),KEYLEN=(4),MF=(G,(2)) ==> key
@@L3     EQU   *
         SLR   15,15
* Function '__vsmdfy' epilogue
         PDPEPIL
* Function '__vsmdfy' literal pool
         DS    0D
         LTORG
* Function '__vsmdfy' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
