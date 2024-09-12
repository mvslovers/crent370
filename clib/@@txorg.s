 TITLE '/home/mike/repos/crent370/clib/@@txorg.c'
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
         DS    0H
@@2      EQU   *
         DC    C'CQ'
         DC    X'0'
         DC    3X'00'
         DC    X'0800'
         DC    C'CX'
         DC    X'0'
         DC    3X'00'
         DC    X'1000'
         DC    C'DA'
         DC    X'0'
         DC    3X'00'
         DC    X'2000'
         DC    C'DAU'
         DC    X'0'
         DC    2X'00'
         DC    X'2100'
         DC    C'GS'
         DC    X'0'
         DC    3X'00'
         DC    X'0080'
         DC    C'MQ'
         DC    X'0'
         DC    3X'00'
         DC    X'0400'
         DC    C'PO'
         DC    X'0'
         DC    3X'00'
         DC    X'0200'
         DC    C'POU'
         DC    X'0'
         DC    2X'00'
         DC    X'0300'
         DC    C'PS'
         DC    X'0'
         DC    3X'00'
         DC    X'4000'
         DC    C'PSU'
         DC    X'0'
         DC    2X'00'
         DC    X'4100'
         DC    C'TCAM'
         DC    X'0'
         DC    1X'00'
         DC    X'0004'
         DC    C'3705'
         DC    X'0'
         DC    1X'00'
         DC    X'0004'
         DC    C'TQ'
         DC    X'0'
         DC    3X'00'
         DC    X'0020'
         DC    C'TX'
         DC    X'0'
         DC    3X'00'
         DC    X'0040'
         DC    C'VSAM'
         DC    X'0'
         DC    1X'00'
         DC    X'0008'
         DC    X'0'
         DC    5X'00'
         DC    X'0000'
* Program text area
         DS    0F
         EJECT
* external function '__txorg' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__txorg'
@@TXORG  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__txorg' code
         L     6,4(11) ==> dsorg
         LA    7,1(0,0) ==> err
         LTR   6,6 ==> dsorg
         BE    @@L9
         SLR   3,3 ==> i
         L     2,=A(@@2)
         IC    2,0(3,2) ==> .dsorg
         CLM   2,1,=XL1'00'
         BE    @@L9
         L     5,=A(@@2)
@@L10    EQU   *
         LR    4,3 ==> i
         MH    4,=H'8'
         LR    2,4
         A     2,=A(@@2)
         ST    2,88(13)
         ST    6,92(13) ==> dsorg
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LTR   15,15 ==> tu
         BNE   @@L5
         MVC   88(4,13),=F'60'
         MVC   92(4,13),=F'1'
         MVC   96(4,13),=F'2'
         LR    2,4
         A     2,=A(@@2+6)
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
         MH    2,=H'8'
         IC    2,0(2,5) ==> .dsorg
         CLM   2,1,=XL1'00'
         BNE   @@L10
@@L9     EQU   *
         LR    15,7 ==> err
* Function '__txorg' epilogue
         PDPEPIL
* Function '__txorg' literal pool
         DS    0D
         LTORG
* Function '__txorg' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
