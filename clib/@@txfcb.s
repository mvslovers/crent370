 TITLE '/home/mike/repos/crent370/clib/@@txfcb.c'
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
* external function '__txfcb' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__txfcb'
@@TXFCB  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__txfcb' code
         L     3,4(11) ==> fcb
         LA    4,1(0,0) ==> err
         LTR   3,3 ==> fcb
         BE    @@L2
         ST    3,88(13) ==> fcb
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    2,15 ==> len
         B     @@L3
@@L2     EQU   *
         SLR   2,2 ==> len
@@L3     EQU   *
         LTR   2,2 ==> len
         BNH   @@L10
         ST    3,88(13) ==> fcb
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LTR   15,15 ==> len
         BNE   @@L5
         MVC   88(4,13),=F'38'
         MVC   92(4,13),=F'1'
         MVC   96(4,13),=F'1'
         MVC   100(4,13),=A(@@LC1)
         B     @@L11
@@L5     EQU   *
         ST    3,88(13) ==> fcb
         MVC   92(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LTR   15,15 ==> len
         BNE   @@L7
         MVC   88(4,13),=F'38'
         MVC   92(4,13),=F'1'
         MVC   96(4,13),=F'1'
         MVC   100(4,13),=A(@@LC3)
         B     @@L11
@@L7     EQU   *
         MVC   88(4,13),=F'37'
         MVC   92(4,13),=F'1'
         ST    2,96(13) ==> len
         ST    3,100(13) ==> fcb
@@L11    EQU   *
         LA    1,88(,13)
         L     15,=V(@@NWTX99)
         BALR  14,15
         LTR   15,15 ==> tu
         BE    @@L10
         MVC   88(4,13),0(11) ==> txt99
         ST    15,92(13) ==> tu
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LR    4,15 ==> err
@@L10    EQU   *
         LR    15,4 ==> err
* Function '__txfcb' epilogue
         PDPEPIL
* Function '__txfcb' literal pool
         DS    0D
         LTORG
* Function '__txfcb' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'ALIGN'
         DC    X'0'
@@LC1    EQU   *
         DC    X'8'
         DC    X'0'
@@LC2    EQU   *
         DC    C'VERIFY'
         DC    X'0'
@@LC3    EQU   *
         DC    X'4'
         DC    X'0'
         END
