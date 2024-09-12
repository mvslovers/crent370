 TITLE '/home/mike/repos/crent370/dyn75/@@75exit.c'
         COPY  PDPTOP
         CSECT
* GNU C version 3.2.3 - c2asm370 version 1.0 (mvs)
*        compiled by GNU C version 13.2.0.
*
* options passed:  -lang-c -I. -I/home/mike/repos/crent370/dyn75
* -I/home/mike/repos/crent370/include -iprefix -D__GNUC__=3
* -D__GNUC_MINOR__=2 -D__GNUC_PATCHLEVEL__=3 -D__GXX_ABI_VERSION=102
* -D__GCC__ -D__MVS__ -D__GCC__ -D__MVS__ -Asystem=mvs -Acpu=i370
* -Amachine=i370 -D__OPTIMIZE__ -D__STDC_HOSTED__=1 -trigraphs -O1
* -fverbose-asm
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
* external function '__75exit' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__75exit'
@@75EXIT PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__75exit' code
         MVC   88(4,13),=A(@@LC0)
         L     2,=V(@@75VECT)
         L     3,0(2) ==> __75vect
         MVC   92(4,13),8(3) ==> .inuse
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         L     2,0(2) ==> __75vect
         L     2,8(2) ==> p,inuse
         LTR   2,2 ==> p
         BE    @@L2
         LR    3,2 ==> p
         SLR   6,6 ==> i
@@L7     EQU   *
         MVC   88(4,13),=A(@@LC1)
         SLR   2,2
         IC    2,0(6,3) ==> i
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         A     6,=F'1' ==> i
         LA    2,127(0,0)
         CLR   6,2 ==> i
         BNH   @@L7
         MVC   88(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         SLR   6,6 ==> i
@@L14    EQU   *
         L     2,=V(@@75VECT)
         L     2,0(2) ==> __75vect
         L     5,8(2) ==> .inuse
         LR    3,6 ==> i
         SRL   3,5
         MH    3,=H'4'
         LR    4,6 ==> i
         N     4,=F'31'
         LA    2,1(0,0)
         SLL   2,0(4)
         N     2,0(3,5) ==> .fds_bits
         LTR   2,2
         BE    @@L12
         MVC   88(4,13),=A(@@LC3)
         ST    6,92(13) ==> i
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         ST    6,88(13) ==> i
         LA    1,88(,13)
         L     15,=V(@@75CLOS)
         BALR  14,15
         B     @@L10
@@L12    EQU   *
         MVC   88(4,13),=A(@@LC4)
         ST    6,92(13) ==> i
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
@@L10    EQU   *
         A     6,=F'1' ==> i
         LA    2,1023(0,0)
         CR    6,2 ==> i
         BNH   @@L14
@@L2     EQU   *
         MVC   88(4,13),=A(@@LC5)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
* Function '__75exit' epilogue
         PDPEPIL
* Function '__75exit' literal pool
         DS    0D
         LTORG
* Function '__75exit' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'in __75exit(), inuse=%08X'
         DC    X'15'
         DC    X'0'
@@LC1    EQU   *
         DC    C'%02X '
         DC    X'0'
@@LC2    EQU   *
         DC    X'15'
         DC    X'0'
@@LC3    EQU   *
         DC    C'closing socket %d'
         DC    X'15'
         DC    X'0'
@@LC4    EQU   *
         DC    C'socket %d is not in use'
         DC    X'15'
         DC    X'0'
@@LC5    EQU   *
         DC    C'leaving __75exit()'
         DC    X'15'
         DC    X'0'
         END
