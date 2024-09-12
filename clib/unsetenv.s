 TITLE '/home/mike/repos/crent370/clib/unsetenv.c'
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
* external function 'unsetenv' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'unsetenv'
UNSETENV PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'unsetenv' code
         L     8,0(11) ==> name
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    5,15 ==> grt
         LR    3,15 ==> grt
         A     3,=F'32'
         ST    3,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LTR   8,8 ==> name
         BE    @@L2
         L     2,0(3) ==> .grtenv
         LTR   2,2
         BE    @@L2
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    7,15 ==> count
         SLR   6,6 ==> i
         CLR   6,15 ==> i,count
         BNL   @@L2
@@L10    EQU   *
         L     2,32(5) ==> .grtenv
         LR    4,6 ==> i
         MH    4,=H'4'
         L     2,0(4,2) ==> envvar
         LTR   2,2 ==> envvar
         BE    @@L5
         L     3,0(2) ==> .name
         LTR   3,3
         BNE   @@L8
         ST    2,88(13) ==> envvar
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         L     2,32(5) ==> .grtenv
         ST    3,0(4,2)
         B     @@L5
@@L8     EQU   *
         MVC   88(4,13),0(2) ==> .name
         ST    8,92(13) ==> name
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LR    4,15 ==> grt
         LTR   15,15 ==> grt
         BNE   @@L5
         ST    2,88(13) ==> envvar
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         L     3,32(5) ==> .grtenv
         LR    2,6 ==> i
         MH    2,=H'4'
         ST    4,0(2,3) ==> grt
@@L5     EQU   *
         A     6,=F'1' ==> i
         CLR   6,7 ==> i,count
         BL    @@L10
@@L2     EQU   *
         LR    2,5 ==> grt
         A     2,=F'32'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         SLR   15,15
* Function 'unsetenv' epilogue
         PDPEPIL
* Function 'unsetenv' literal pool
         DS    0D
         LTORG
* Function 'unsetenv' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
