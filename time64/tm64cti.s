 TITLE '/home/mike/repos/crent370/time64/tm64cti.c'
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
         
&FUNC    SETC 'ctime64'
* Program text area
         DS    0F
         EJECT
* external function 'ctime64' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'ctime64'
TM64CTI  PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'ctime64' code
         MVC   88(4,13),0(11) ==> time
         LA    1,88(,13)
         L     15,=V(TM64LTM)
         BALR  14,15
         ST    15,88(13)
         LA    1,88(,13)
         L     15,=V(TM64ASC)
         BALR  14,15
* Function 'ctime64' epilogue
         PDPEPIL
* Function 'ctime64' literal pool
         DS    0D
         LTORG
* Function 'ctime64' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
