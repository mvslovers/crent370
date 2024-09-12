 TITLE '/home/mike/repos/crent370/clib/@@tqeena.c'
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
         
&FUNC    SETC 'tqe_enable'
* Program text area
         DS    0F
         EJECT
* external function 'tqe_enable' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'tqe_enable'
@@TQEENA PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'tqe_enable' code
         L     6,0(11) ==> id
         LA    8,2(0,0) ==> rc
         LA    1,88(,13)
         L     15,=V(@@TMRGET)
         BALR  14,15
         LR    5,15 ==> tmr
         LA    1,88(,13)
         L     15,=V(@@TMINIT)
         BALR  14,15
         ST    5,88(13) ==> tmr
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    7,15 ==> lockrc
         LR    2,5 ==> tmr
         A     2,=F'24'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         SLR   4,4 ==> n
         CLR   4,15 ==> n,count
         BNL   @@L3
@@L10    EQU   *
         L     3,24(5) ==> .tqe
         LR    2,4 ==> n
         MH    2,=H'4'
         L     3,0(2,3) ==> tqe
         LTR   3,3 ==> tqe
         BE    @@L4
         L     2,40(3) ==> .id
         CLR   2,6 ==> id
         BNE   @@L4
         NI    8(3),223 ==> .flags
         L     2,24(3) ==> .bintvl
         LTR   2,2
         BE    @@L8
         MVC   88(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@TMSECS)
         BALR  14,15
         LDR   2,0
         L     2,24(3) ==> .bintvl
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    2,84(,13)
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         LTR   2,2
         BNL   @@L9
         AD    0,=D'4.294967296E9'
@@L9     EQU   *
         DD    0,=D'1.0E2'
         ADR   0,2
         STD   0,16(3) ==> .expires
         LR    2,5 ==> tmr
         A     2,=F'20'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@ECBPST)
         BALR  14,15
@@L8     EQU   *
         SLR   8,8 ==> rc
         B     @@L3
@@L4     EQU   *
         A     4,=F'1' ==> n
         CLR   4,15 ==> n,count
         BL    @@L10
@@L3     EQU   *
         LTR   7,7 ==> lockrc
         BNE   @@L11
         ST    5,88(13) ==> tmr
         ST    7,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L11    EQU   *
         LR    15,8 ==> rc
* Function 'tqe_enable' epilogue
         PDPEPIL
* Function 'tqe_enable' literal pool
         DS    0D
         LTORG
* Function 'tqe_enable' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
