 TITLE '/home/mike/repos/crent370/clib/@@load.c'
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
         
&FUNC    SETC '__load'
* Program text area
         DS    0F
         EJECT
* external function '__load' prologue
* frame base=88, local stack=80, call args=8
&FUNC    SETC  '__load'
@@LOAD   PDPPRLG CINDEX=0,FRAME=176,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__load' code
         L     7,0(11) ==> dcb
         L     15,4(11) ==> module
         L     8,8(11) ==> size
         L     9,12(11) ==> ac
         SLR   6,6 ==> epa
         LA    4,96(,13)
         LA    5,80(0,0)
         LR    2,6 ==> epa
         LR    3,6 ==> epa
         MVCL  4,2 ==> epa
         LTR   15,15 ==> module
         BE    @@L4
         CLI   0(15),64 ==> module
         BNH   @@L4
         LR    4,6 ==> i,epa
         L     5,=V(@@TOUP)
@@L11    EQU   *
         IC    2,0(15) ==> module
         CLM   2,1,=XL1'00'
         BE    @@L9
         SLR   2,2
         IC    2,0(15) ==> module
         L     3,0(5) ==> __toup
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,100(4,13) ==> .name
         A     15,=F'1' ==> module
         B     @@L7
@@L9     EQU   *
         LA    2,64(0,0)
         STC   2,100(4,13) ==> .name
@@L7     EQU   *
         A     4,=F'1' ==> i
         LA    2,7(0,0)
         CLR   4,2 ==> i
         BNH   @@L11
         LA    2,96(,13)
         ST    2,88(13)
         ST    7,92(13) ==> dcb
         LA    1,88(,13)
         L     15,=V(@@BLDL)
         BALR  14,15
         LTR   15,15 ==> rc
         BNE   @@L4
         LA    2,100(,13)
         LOAD DE=(2),DCB=(7),ERRET=LOADFAIL ==> dcb
         LR    6,0          Success, save EPA ==> epa
         LR    3,1          Success, save AC and Size ==> work
         B     LOADDONE
LOADFAIL DS    0H
         XR    6,6         Failed, no EPA ==> epa
         XR    3,3         Failed, no AC or Size ==> work
LOADDONE DS    0H
         LTR   6,6 ==> epa
         BE    @@L4
         LTR   8,8 ==> size
         BE    @@L14
         LR    2,3 ==> work
         SLL   2,3
         N     2,=F'134217720'
         ST    2,0(8) ==> size
@@L14    EQU   *
         LTR   9,9 ==> ac
         BE    @@L4
         LR    2,3 ==> work
         SRL   2,24
         STC   2,0(9) ==> ac
@@L4     EQU   *
         LR    15,6 ==> epa
* Function '__load' epilogue
         PDPEPIL
* Function '__load' literal pool
         DS    0D
         LTORG
* Function '__load' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
