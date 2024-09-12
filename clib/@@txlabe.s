 TITLE '/home/mike/repos/crent370/clib/@@txlabe.c'
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
* Program data area
@@2      EQU   *
         DC    C'NL'
         DC    X'0'
         DC    1X'00'
         DC    X'01'
         DC    C'SL'
         DC    X'0'
         DC    1X'00'
         DC    X'02'
         DC    C'NSL'
         DC    X'0'
         DC    X'04'
         DC    C'SUL'
         DC    X'0'
         DC    X'0A'
         DC    C'BLP'
         DC    X'0'
         DC    X'10'
         DC    C'LTM'
         DC    X'0'
         DC    X'21'
         DC    C'AL'
         DC    X'0'
         DC    1X'00'
         DC    X'40'
         DC    C'AUL'
         DC    X'0'
         DC    X'48'
         DC    X'0'
         DC    3X'00'
         DC    X'00'
* Program text area
         DS    0F
         EJECT
* external function '__txlabe' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__txlabe'
@@TXLABE PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__txlabe' code
         L     6,4(11) ==> label
         LA    8,1(0,0) ==> err
         LTR   6,6 ==> label
         BE    @@L2
         ST    6,88(13) ==> label
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    5,15 ==> len
         B     @@L3
@@L2     EQU   *
         SLR   5,5 ==> len
@@L3     EQU   *
         LA    2,1(0,0)
         CR    5,2 ==> len
         BNH   @@L11
         SLR   3,3 ==> i
         L     2,=A(@@2)
         IC    2,0(3,2) ==> .label
         CLM   2,1,=XL1'00'
         BE    @@L11
         L     7,=A(@@2)
@@L12    EQU   *
         LR    2,3 ==> i
         SLL   2,2
         LR    4,2
         AR    4,3 ==> i
         LR    2,4
         A     2,=A(@@2)
         ST    2,88(13)
         ST    6,92(13) ==> label
         ST    5,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> len
         BNE   @@L7
         MVC   88(4,13),=F'30'
         MVC   92(4,13),=F'1'
         MVC   96(4,13),=F'1'
         LR    2,4
         A     2,=A(@@2+4)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@NWTX99)
         BALR  14,15
         LTR   15,15 ==> tu
         BE    @@L11
         MVC   88(4,13),0(11) ==> txt99
         ST    15,92(13) ==> tu
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LR    8,15 ==> err
         B     @@L11
@@L7     EQU   *
         A     3,=F'1' ==> i
         LR    2,3 ==> i
         SLL   2,2
         AR    2,3 ==> i
         IC    2,0(2,7) ==> .label
         CLM   2,1,=XL1'00'
         BNE   @@L12
@@L11    EQU   *
         LR    15,8 ==> err
* Function '__txlabe' epilogue
         PDPEPIL
* Function '__txlabe' literal pool
         DS    0D
         LTORG
* Function '__txlabe' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
