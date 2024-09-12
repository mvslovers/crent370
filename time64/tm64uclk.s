 TITLE '/home/mike/repos/crent370/time64/tm64uclk.c'
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
         
&FUNC    SETC 'uclock64'
* Program text area
         DS    0F
         EJECT
* external function 'uclock64' prologue
* frame base=88, local stack=8, call args=0
&FUNC    SETC  'uclock64'
TM64UCLK PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'uclock64' code
         LR    15,0
         LA    2,88(13) get address of 8 byte work area
         STCK  0(2) store clock into work area
         
         L     4,88(13)
         L     5,4+88(13)
         LR    3,5
         A     3,=F'905969664'
         LA    6,1(0,0)
         CLR   3,5
         BH    @@L2
         SLR   6,6
@@L2     EQU   *
         LR    2,4
         A     2,=F'-2106655883'
         SR    2,6
         SRDL  2,12
         ST    2,0(15) ==> <result>
         ST    3,4+0(15) ==> <result>
* Function 'uclock64' epilogue
         PDPEPIL
* Function 'uclock64' literal pool
         DS    0D
         LTORG
* Function 'uclock64' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
