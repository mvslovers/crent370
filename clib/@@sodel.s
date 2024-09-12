 TITLE '/home/mike/repos/crent370/clib/@@sodel.c'
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
* external function '__sodel' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__sodel'
@@SODEL  PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__sodel' code
         L     7,0(11) ==> ss
         SLR   6,6 ==> rc
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    5,15 ==> grt
         LR    2,15 ==> grt
         A     2,=F'28'
         ST    2,88(13)
         ST    6,92(13) ==> rc
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    4,6 ==> n,rc
         CLR   6,15 ==> rc,count
         BNL   @@L3
@@L8     EQU   *
         L     3,28(5) ==> .grtsock
         LR    2,4 ==> n
         MH    2,=H'4'
         L     3,0(2,3) ==> p
         LTR   3,3 ==> p
         BE    @@L4
         L     2,8(3) ==> .socket
         CLR   2,7 ==> ss
         BNE   @@L4
         LR    2,5 ==> grt
         A     2,=F'28'
         ST    2,88(13)
         LR    2,4 ==> n
         A     2,=F'1'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@ARDEL)
         BALR  14,15
         ST    3,88(13) ==> p
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         B     @@L3
@@L4     EQU   *
         A     4,=F'1' ==> n
         CLR   4,15 ==> n,count
         BL    @@L8
@@L3     EQU   *
         LR    2,5 ==> grt
         A     2,=F'28'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L9     EQU   *
         LR    15,6 ==> rc
* Function '__sodel' epilogue
         PDPEPIL
* Function '__sodel' literal pool
         DS    0D
         LTORG
* Function '__sodel' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
