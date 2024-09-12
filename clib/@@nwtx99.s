 TITLE '/home/mike/repos/crent370/clib/@@nwtx99.c'
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
* external function '__nwtx99' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__nwtx99'
@@NWTX99 PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__nwtx99' code
         SLR   4,4 ==> size
         SLR   5,5 ==> size
         L     6,4(11) ==> count
         L     7,8(11) ==> size
         L     8,12(11) ==> text
         LR    5,7 ==> size
         MR    4,6 ==> size,count
         MVC   88(4,13),=F'1'
         LR    2,5
         A     2,=F'8'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    3,15 ==> txt99
         LTR   15,15 ==> txt99
         BE    @@L2
         L     2,0(11) ==> dal
         STH   2,0(15) ==> .dal
         STH   6,2(15) ==> count,count
         STH   7,4(15) ==> size,size
         LTR   8,8 ==> text
         BE    @@L2
         LR    2,15 ==> txt99
         A     2,=F'6'
         ST    2,88(13)
         ST    8,92(13) ==> text
         ST    5,96(13) ==> size
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L2     EQU   *
         LR    15,3 ==> txt99
* Function '__nwtx99' epilogue
         PDPEPIL
* Function '__nwtx99' literal pool
         DS    0D
         LTORG
* Function '__nwtx99' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
