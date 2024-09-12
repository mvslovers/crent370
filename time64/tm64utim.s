 TITLE '/home/mike/repos/crent370/time64/tm64utim.c'
         COPY  PDPTOP
         CSECT
* GNU C version 3.2.3 - c2asm370 version 1.0 (mvs)
*        compiled by GNU C version 13.2.0.
*
* options passed:  -lang-c -I. -I/home/mike/repos/crent370/time64
* -I/home/mike/repos/crent370/include -iprefix -D__GNUC__=3
* -D__GNUC_MINOR__=2 -D__GNUC_PATCHLEVEL__=3 -D__GXX_ABI_VERSION=102
* -D__GCC__ -D__MVS__ -D__GCC__ -D__MVS__ -Asystem=mvs -Acpu=i370
* -Amachine=i370 -D__OPTIMIZE__ -D__STDC_HOSTED__=1 -trigraphs -O1
* -fverbose-asm
* 
* options enabled:  -fdefer-pop -fthread-jumps -fpeephole
* -ffunction-cse -fkeep-static-consts -fpcc-struct-return -fgcse-lm
* -fgcse-sm -fsched-interblock -fsched-spec -fbranch-count-reg
* -fcprop-registers -fcommon -fverbose-asm -fgnu-linker
* -fargument-alias -fmerge-constants -fident
* -fguess-branch-probability -fmath-errno -ftrapping-math
* -mchar-instructions -mno-pickax -mno-constants-first
*
         
&FUNC    SETC 'utime64'
* Program text area
         DS    0F
         EJECT
* external function 'utime64' prologue
* frame base=88, local stack=8, call args=0
&FUNC    SETC  'utime64'
TM64UTIM PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'utime64' code
         LR    4,0
         L     5,0(11) ==> utimer
         LA    0,88(,13)
         LA    1,88(,13)
         L     15,=V(TM64UCLK)
         BALR  14,15
         L     2,88(13) ==> tt
         L     3,4+88(13) ==> tt
         LTR   5,5 ==> utimer
         BE    @@L2
         ST    2,0(5) ==> tt,utimer
         ST    3,4+0(5) ==> tt,utimer
@@L2     EQU   *
         ST    2,0(4) ==> tt,<result>
         ST    3,4+0(4) ==> tt,<result>
         LR    15,4
* Function 'utime64' epilogue
         PDPEPIL
* Function 'utime64' literal pool
         DS    0D
         LTORG
* Function 'utime64' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
