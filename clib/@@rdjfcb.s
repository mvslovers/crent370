 TITLE '/home/mike/repos/crent370/clib/@@rdjfcb.c'
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
* external function '__rdjfcb' prologue
* frame base=88, local stack=16, call args=0
&FUNC    SETC  '__rdjfcb'
@@RDJFCB PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__rdjfcb' code
         L     5,0(11) ==> dcb
         L     3,4(11) ==> jfcb
         MVC   92(4,13),=F'-1'
         LR    2,3 ==> jfcb
         N     2,=F'16777215'
         O     2,=F'-2030043136'
         ST    2,88(13)
         MVC   96(4,13),=F'-2147483648'
         LTR   5,5 ==> dcb
         BE    @@L3
         LTR   3,3 ==> jfcb
         BE    @@L3
         L     4,36(5) ==> exlst,dcbexlst
         LR    3,4 ==> exlst
         N     3,=F'-16777216'
         LA    2,88(,13)
         OR    3,2
         ST    3,36(5) ==> .dcbexlst
         LA    2,96(,13)
         RDJFCB ((5)),MF=(E,(2)) ==> dcb
         ST     15,92(13)
         ST    4,36(5) ==> exlst,dcbexlst
@@L3     EQU   *
         L     15,92(13)
* Function '__rdjfcb' epilogue
         PDPEPIL
* Function '__rdjfcb' literal pool
         DS    0D
         LTORG
* Function '__rdjfcb' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
