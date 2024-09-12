 TITLE '/home/mike/repos/crent370/clib/@@crtres.c'
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
* external function '__CRTRES' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__CRTRES'
@@CRTRES PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__CRTRES' code
         L     8,=F'-1' ==> rc
         SLR   6,6 ==> locked
         L     7,540(6) ==> tcb
         LA    1,88(,13)
         L     15,=V(@@PPAGET)
         BALR  14,15
         LR    5,15 ==> ppa
         LTR   15,15 ==> ppa
         BE    @@L3
         ST    15,88(13) ==> ppa
         ST    6,92(13) ==> locked
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    6,15 ==> locked
         LTR   15,15 ==> locked
         BNE   @@L3
         LR    2,5 ==> ppa
         A     2,=F'12'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    4,6 ==> n,locked
         CLR   6,15 ==> locked,count
         BNL   @@L6
@@L10    EQU   *
         L     3,12(5) ==> .ppacrt
         LR    2,4 ==> n
         MH    2,=H'4'
         L     3,0(2,3) ==> crt
         LTR   3,3 ==> crt
         BE    @@L7
         L     2,8(3) ==> .crttcb
         CLR   2,7 ==> tcb
         BNE   @@L7
         LR    2,5 ==> ppa
         A     2,=F'12'
         ST    2,88(13)
         LR    2,4 ==> n
         A     2,=F'1'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@ARDEL)
         BALR  14,15
         ST    3,88(13) ==> crt
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         SLR   8,8 ==> rc
         B     @@L6
@@L7     EQU   *
         A     4,=F'1' ==> n
         CLR   4,15 ==> n,count
         BL    @@L10
@@L6     EQU   *
         LTR   6,6 ==> locked
         BNE   @@L3
         ST    5,88(13) ==> ppa
         ST    6,92(13) ==> locked
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L3     EQU   *
         LR    15,8 ==> rc
* Function '__CRTRES' epilogue
         PDPEPIL
* Function '__CRTRES' literal pool
         DS    0D
         LTORG
* Function '__CRTRES' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
