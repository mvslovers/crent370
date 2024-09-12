 TITLE '/home/mike/repos/crent370/clib/@@txbufo.c'
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
* external function '__txbufo' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  '__txbufo'
@@TXBUFO PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__txbufo' code
         L     3,4(11) ==> offset
         LA    4,1(0,0) ==> err
         LTR   3,3 ==> offset
         BE    @@L2
         ST    3,88(13) ==> offset
         LA    1,88(,13)
         L     15,=V(ATOI)
         BALR  14,15
         B     @@L3
@@L2     EQU   *
         SLR   15,15 ==> tu
@@L3     EQU   *
         ST    15,104(13) ==> tu
         LTR   15,15
         BNE   @@L4
         LTR   3,3 ==> offset
         BE    @@L4
         ST    3,88(13) ==> offset
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LTR   15,15 ==> tu
         BNE   @@L4
         MVC   104(4,13),=F'128'
@@L4     EQU   *
         L     2,104(13)
         LA    3,99(0,0)
         CLR   2,3
         BNH   @@L7
         LA    3,128(0,0)
         CLR   2,3
         BNE   @@L9
@@L7     EQU   *
         MVC   88(4,13),=F'53'
         MVC   92(4,13),=F'1'
         MVC   96(4,13),=F'1'
         LA    2,107(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@NWTX99)
         BALR  14,15
         LTR   15,15 ==> tu
         BE    @@L9
         MVC   88(4,13),0(11) ==> txt99
         ST    15,92(13) ==> tu
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LR    4,15 ==> err
@@L9     EQU   *
         LR    15,4 ==> err
* Function '__txbufo' epilogue
         PDPEPIL
* Function '__txbufo' literal pool
         DS    0D
         LTORG
* Function '__txbufo' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'L'
         DC    X'0'
         END
