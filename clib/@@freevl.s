 TITLE '/home/mike/repos/crent370/clib/@@freevl.c'
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
* external function '__freevl' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  '__freevl'
@@FREEVL PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__freevl' code
         L     4,0(11) ==> pppvollist
         LTR   4,4 ==> pppvollist
         BE    @@L1
         MVC   96(4,13),0(4) ==> pppvollist
         L     2,96(13)
         LTR   2,2
         BE    @@L1
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    3,15 ==> n
         LTR   15,15 ==> n
         BE    @@L13
@@L11    EQU   *
         LA    2,96(,13)
         ST    2,88(13)
         ST    3,92(13) ==> n
         LA    1,88(,13)
         L     15,=V(@@ARDEL)
         BALR  14,15
         LR    2,15 ==> v
         LTR   15,15 ==> v
         BE    @@L7
         L     15,36(15) ==> .comment
         LTR   15,15
         BE    @@L10
         ST    15,88(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         MVC   36(4,2),=F'0' ==> .comment
@@L10    EQU   *
         ST    2,88(13) ==> v
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L7     EQU   *
         BCTR  3,0 ==> n
         LTR   3,3 ==> n
         BNE   @@L11
@@L13    EQU   *
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
         MVC   0(4,4),=F'0' ==> pppvollist
@@L3     EQU   *
@@L1     EQU   *
* Function '__freevl' epilogue
         PDPEPIL
* Function '__freevl' literal pool
         DS    0D
         LTORG
* Function '__freevl' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
