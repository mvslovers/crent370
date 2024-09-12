 TITLE '/home/mike/repos/crent370/clib/@@txtrtc.c'
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
         DC    C'C'
         DC    X'0'
         DC    5X'00'
         DC    X'13'
         DC    C'COMP'
         DC    X'0'
         DC    2X'00'
         DC    X'08'
         DC    C'E'
         DC    X'0'
         DC    5X'00'
         DC    X'23'
         DC    C'ET'
         DC    X'0'
         DC    4X'00'
         DC    X'2B'
         DC    C'NOCOMP'
         DC    X'0'
         DC    X'04'
         DC    C'T'
         DC    X'0'
         DC    5X'00'
         DC    X'3B'
         DC    X'0'
         DC    6X'00'
         DC    X'00'
* Program text area
         DS    0F
         EJECT
* external function '__txtrtc' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__txtrtc'
@@TXTRTC PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__txtrtc' code
         L     6,4(11) ==> trtch
         LA    7,1(0,0) ==> err
         LTR   6,6 ==> trtch
         BE    @@L2
         ST    6,88(13) ==> trtch
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    5,15 ==> len
         B     @@L3
@@L2     EQU   *
         SLR   5,5 ==> len
@@L3     EQU   *
         LTR   5,5 ==> len
         BE    @@L11
         SLR   4,4 ==> i
         L     2,=A(@@2)
         IC    2,0(4,2) ==> .trtch
         CLM   2,1,=XL1'00'
         BE    @@L11
@@L12    EQU   *
         LR    3,4 ==> i
         MH    3,=H'8'
         LR    2,3
         A     2,=A(@@2)
         ST    2,88(13)
         ST    6,92(13) ==> trtch
         ST    5,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> len
         BNE   @@L7
         MVC   88(4,13),=F'79'
         MVC   92(4,13),=F'1'
         MVC   96(4,13),=F'1'
         LR    2,3
         A     2,=A(@@2+7)
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
         LR    7,15 ==> err
         B     @@L11
@@L7     EQU   *
         A     4,=F'1' ==> i
         LR    2,4 ==> i
         MH    2,=H'8'
         L     3,=A(@@2)
         IC    2,0(2,3) ==> .trtch
         CLM   2,1,=XL1'00'
         BNE   @@L12
@@L11    EQU   *
         LR    15,7 ==> err
* Function '__txtrtc' epilogue
         PDPEPIL
* Function '__txtrtc' literal pool
         DS    0D
         LTORG
* Function '__txtrtc' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
