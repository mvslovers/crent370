 TITLE '/home/mike/repos/crent370/clib/strchr.c'
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
* external function 'strchr' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'strchr'
STRCHR   PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'strchr' code
         L     15,0(11) ==> s
         L     3,4(11) ==> c
         IC    2,0(15) ==> s
         CLM   2,1,=XL1'00'
         BE    @@L9
@@L6     EQU   *
         CLM   3,1,0(15) ==> c,s
         BE    @@L1
         A     15,=F'1' ==> s
         IC    2,0(15) ==> s
         CLM   2,1,=XL1'00'
         BNE   @@L6
@@L9     EQU   *
         LTR   3,3 ==> c
         BE    @@L1
         SLR   15,15 ==> s
@@L1     EQU   *
* Function 'strchr' epilogue
         PDPEPIL
* Function 'strchr' literal pool
         DS    0D
         LTORG
* Function 'strchr' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
