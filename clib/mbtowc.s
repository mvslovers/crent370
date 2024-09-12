 TITLE '/home/mike/repos/crent370/clib/mbtowc.c'
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
* external function 'mbtowc' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'mbtowc'
MBTOWC   PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'mbtowc' code
         L     4,0(11) ==> pwc
         L     3,4(11) ==> s
         LR    15,3 ==> s
         LTR   3,3 ==> s
         BE    @@L1
         L     15,=F'-1' ==> s
         L     2,8(11) ==> n
         LA    5,1(0,0)
         CLR   2,5 ==> n
         BNE   @@L1
         LTR   4,4 ==> pwc
         BE    @@L4
         MVC   0(1,4),0(3) ==> pwc,s
@@L4     EQU   *
         LA    15,1(0,0) ==> s
@@L1     EQU   *
* Function 'mbtowc' epilogue
         PDPEPIL
* Function 'mbtowc' literal pool
         DS    0D
         LTORG
* Function 'mbtowc' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
