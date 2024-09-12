 TITLE '/home/mike/repos/crent370/clib/tanh.c'
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
* external function 'tanh' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'tanh'
TANH     PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'tanh' code
         LD    0,0(11) ==> x
         MD    0,=D'-2.0E0'
         STD   0,88(13)
         LA    1,88(,13)
         L     15,=V(EXP)
         BALR  14,15
         LD    2,=D'1.0E0' ==> dexp2
         SDR   2,0 ==> dexp2
         AD    0,=D'1.0E0'
         DDR   2,0 ==> dexp2
         LDR   0,2 ==> dexp2
* Function 'tanh' epilogue
         PDPEPIL
* Function 'tanh' literal pool
         DS    0D
         LTORG
* Function 'tanh' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
