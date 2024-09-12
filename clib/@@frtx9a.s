 TITLE '/home/mike/repos/crent370/clib/@@frtx9a.c'
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
* external function '__frtx9a' prologue
* frame base=88, local stack=8, call args=8
&FUNC    SETC  '__frtx9a'
@@FRTX9A PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__frtx9a' code
         L     5,0(11) ==> txt99
         LTR   5,5 ==> txt99
         BE    @@L1
         L     2,0(5) ==> txt99
         LTR   2,2
         BE    @@L1
         ST    2,96(13)
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    4,15 ==> count
         SLR   3,3 ==> n
         CLR   3,15 ==> n,count
         BNL   @@L9
@@L7     EQU   *
         LR    2,3 ==> n
         MH    2,=H'4'
         A     2,96(13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@FRTX99)
         BALR  14,15
         A     3,=F'1' ==> n
         CLR   3,4 ==> n,count
         BL    @@L7
@@L9     EQU   *
         ST    5,88(13) ==> txt99
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
@@L1     EQU   *
* Function '__frtx9a' epilogue
         PDPEPIL
* Function '__frtx9a' literal pool
         DS    0D
         LTORG
* Function '__frtx9a' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
