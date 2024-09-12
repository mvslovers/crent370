 TITLE '/home/mike/repos/crent370/clib/@@txspac.c'
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
* external function '__txspac' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  '__txspac'
@@TXSPAC PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__txspac' code
         L     6,0(11) ==> txt99
         L     3,4(11) ==> space
         LA    5,1(0,0) ==> err
         LTR   3,3 ==> space
         BE    @@L2
         ST    3,88(13) ==> space
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         B     @@L3
@@L2     EQU   *
         SLR   15,15 ==> p
@@L3     EQU   *
         ST    15,104(13) ==> p
         MVC   88(4,13),=F'1'
         LR    2,15 ==> p
         A     2,=F'1'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    4,15 ==> buf
         L     2,104(13)
         LTR   2,2
         BE    @@L5
         LTR   15,15 ==> buf
         BE    @@L5
         ST    15,88(13) ==> buf
         ST    3,92(13) ==> space
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         ST    4,88(13) ==> buf
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         LR    2,15 ==> p
         MVC   88(4,13),=F'0'
         MVC   92(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         LR    3,15 ==> s
         LTR   2,2 ==> p
         BE    @@L7
         ST    2,88(13) ==> p
         LA    1,88(,13)
         L     15,=V(ATOI)
         BALR  14,15
         B     @@L8
@@L7     EQU   *
         SLR   15,15 ==> p
@@L8     EQU   *
         ST    15,104(13) ==> p
         MVC   88(4,13),=F'10'
         MVC   92(4,13),=F'1'
         MVC   96(4,13),=F'3'
         LA    2,105(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@NWTX99)
         BALR  14,15
         LTR   15,15 ==> tu
         BE    @@L5
         ST    6,88(13) ==> txt99
         ST    15,92(13) ==> tu
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LR    5,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L5
         LA    5,1(0,0) ==> err
         LTR   3,3 ==> s
         BE    @@L11
         ST    3,88(13) ==> s
         LA    1,88(,13)
         L     15,=V(ATOI)
         BALR  14,15
         B     @@L12
@@L11    EQU   *
         SLR   15,15 ==> p
@@L12    EQU   *
         ST    15,104(13) ==> p
         MVC   88(4,13),=F'11'
         MVC   92(4,13),=F'1'
         MVC   96(4,13),=F'3'
         LA    2,105(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@NWTX99)
         BALR  14,15
         LTR   15,15 ==> tu
         BE    @@L5
         ST    6,88(13) ==> txt99
         ST    15,92(13) ==> tu
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LR    5,15 ==> err
@@L5     EQU   *
         LTR   4,4 ==> buf
         BE    @@L14
         ST    4,88(13) ==> buf
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L14    EQU   *
         LR    15,5 ==> err
* Function '__txspac' epilogue
         PDPEPIL
* Function '__txspac' literal pool
         DS    0D
         LTORG
* Function '__txspac' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C' ,'
         DC    X'0'
@@LC1    EQU   *
         DC    X'0'
         END
