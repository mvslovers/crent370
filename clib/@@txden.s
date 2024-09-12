 TITLE '/home/mike/repos/crent370/clib/@@txden.c'
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
         DC    C'200'
         DC    X'0'
         DC    1X'00'
         DC    X'03'
         DC    C'556'
         DC    X'0'
         DC    1X'00'
         DC    X'43'
         DC    C'800'
         DC    X'0'
         DC    1X'00'
         DC    X'83'
         DC    C'1600'
         DC    X'0'
         DC    X'C3'
         DC    C'6250'
         DC    X'0'
         DC    X'D3'
         DC    X'0'
         DC    4X'00'
         DC    X'00'
* Program text area
         DS    0F
         EJECT
* external function '__txden' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__txden'
@@TXDEN  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__txden' code
         L     6,4(11) ==> density
         LA    7,1(0,0) ==> err
         LTR   6,6 ==> density
         BE    @@L9
         SLR   3,3 ==> i
         L     2,=A(@@2)
         IC    2,0(3,2) ==> .density
         CLM   2,1,=XL1'00'
         BE    @@L9
         L     5,=A(@@2)
@@L10    EQU   *
         LR    2,3 ==> i
         SLL   2,2
         AR    2,3 ==> i
         LR    4,2
         AR    4,3 ==> i
         LR    2,4
         A     2,=A(@@2)
         ST    2,88(13)
         ST    6,92(13) ==> density
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LTR   15,15 ==> tu
         BNE   @@L5
         MVC   88(4,13),=F'59'
         MVC   92(4,13),=F'1'
         MVC   96(4,13),=F'1'
         LR    2,4
         A     2,=A(@@2+5)
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
         LR    7,15 ==> err
         B     @@L9
@@L5     EQU   *
         A     3,=F'1' ==> i
         LR    2,3 ==> i
         SLL   2,2
         AR    2,3 ==> i
         AR    2,3 ==> i
         IC    2,0(2,5) ==> .density
         CLM   2,1,=XL1'00'
         BNE   @@L10
@@L9     EQU   *
         LR    15,7 ==> err
* Function '__txden' epilogue
         PDPEPIL
* Function '__txden' literal pool
         DS    0D
         LTORG
* Function '__txden' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
