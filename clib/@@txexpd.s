 TITLE '/home/mike/repos/crent370/clib/@@txexpd.c'
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
* external function '__txexpd' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__txexpd'
@@TXEXPD PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__txexpd' code
         L     2,4(11) ==> yyddd
         LA    3,1(0,0) ==> err
         LTR   2,2 ==> yyddd
         BE    @@L2
         ST    2,88(13) ==> yyddd
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         B     @@L3
@@L2     EQU   *
         SLR   15,15 ==> len
@@L3     EQU   *
         LA    4,5(0,0)
         CLR   15,4 ==> len
         BNE   @@L6
         MVC   88(4,13),=F'34'
         MVC   92(4,13),=F'1'
         ST    15,96(13) ==> len
         ST    2,100(13) ==> yyddd
         LA    1,88(,13)
         L     15,=V(@@NWTX99)
         BALR  14,15
         LTR   15,15 ==> tu
         BE    @@L6
         MVC   88(4,13),0(11) ==> txt99
         ST    15,92(13) ==> tu
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LR    3,15 ==> err
@@L6     EQU   *
         LR    15,3 ==> err
* Function '__txexpd' epilogue
         PDPEPIL
* Function '__txexpd' literal pool
         DS    0D
         LTORG
* Function '__txexpd' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
