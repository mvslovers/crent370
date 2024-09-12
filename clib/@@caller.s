 TITLE '/home/mike/repos/crent370/clib/@@caller.c'
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
* external function '__caller' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  '__caller'
@@CALLER PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__caller' code
         L     4,0(11) ==> caller
         LTR   4,4 ==> caller
         BNE   @@L2
         L     4,=A(@@LC0) ==> caller
         B     @@L3
@@L2     EQU   *
         MVI   0(4),0 ==> caller
         LA    2,104(,13)
         DS    0H
        L      1,4(,13)        => callers stack
        L      1,4(,1)         => callers stack
        L      1,4(,1)         => callers stack
        L      1,16(,1)        => function ep address
        ST     1,0(,2)        return ep address
         L     3,104(13) ==> p
         CLI   0(3),71 ==> p
         BNE   @@L3
         CLI   1(3),240
         BNE   @@L3
         A     3,=F'4' ==> p
         ST    4,88(13) ==> caller
         LR    2,3 ==> p
         A     2,=F'1'
         ST    2,92(13)
         SLR   2,2
         IC    2,0(3) ==> p
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         SLR   2,2
         IC    2,0(3) ==> p
         SLR   3,3
         STC   3,0(2,4)
@@L3     EQU   *
         LR    15,4 ==> caller
* Function '__caller' epilogue
         PDPEPIL
* Function '__caller' literal pool
         DS    0D
         LTORG
* Function '__caller' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    X'0'
         END
