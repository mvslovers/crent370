 TITLE '/home/mike/repos/crent370/clib/@@soupd.c'
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
* external function '__soupd' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  '__soupd'
@@SOUPD  PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__soupd' code
         L     6,0(11) ==> ss
         L     3,4(11) ==> name
         L     5,8(11) ==> peer
         SLR   4,4 ==> rc
         ST    4,104(13) ==> rc
         ST    6,88(13) ==> ss
         LA    2,104(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@SOFIND)
         BALR  14,15
         LTR   15,15 ==> rc
         BNE   @@L2
         ST    6,88(13) ==> ss
         ST    3,92(13) ==> name
         ST    5,96(13) ==> peer
         LA    1,88(,13)
         L     15,=V(@@SOADD)
         BALR  14,15
         LR    4,15 ==> rc
         B     @@L3
@@L2     EQU   *
         LTR   3,3 ==> name
         BE    @@L4
         L     2,104(13)
         A     2,=F'16'
         ST    2,88(13)
         ST    3,92(13) ==> name
         MVC   96(4,13),=F'16'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L4     EQU   *
         LTR   5,5 ==> peer
         BE    @@L3
         L     2,104(13)
         A     2,=F'32'
         ST    2,88(13)
         ST    5,92(13) ==> peer
         MVC   96(4,13),=F'16'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L3     EQU   *
         LR    15,4 ==> rc
* Function '__soupd' epilogue
         PDPEPIL
* Function '__soupd' literal pool
         DS    0D
         LTORG
* Function '__soupd' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
