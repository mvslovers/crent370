 TITLE '/home/mike/repos/crent370/clib/strncpy.c'
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
* external function 'strncpy' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'strncpy'
STRNCPY  PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'strncpy' code
         L     15,0(11) ==> s1
         L     5,4(11) ==> s2
         L     6,8(11) ==> n
         LR    3,15 ==> p,s1
         SLR   4,4 ==> x
         CLR   4,6 ==> x,n
         BNL   @@L3
@@L7     EQU   *
         MVC   0(1,3),0(5) ==> p,s2
         IC    2,0(5) ==> s2
         CLM   2,1,=XL1'00'
         BE    @@L3
         A     3,=F'1' ==> p
         A     5,=F'1' ==> s2
         A     4,=F'1' ==> x
         CLR   4,6 ==> x,n
         BL    @@L7
@@L3     EQU   *
         CLR   4,6 ==> x,n
         BNL   @@L15
@@L12    EQU   *
         MVI   0(3),0 ==> p
         A     3,=F'1' ==> p
         A     4,=F'1' ==> x
         CLR   4,6 ==> x,n
         BL    @@L12
@@L15    EQU   *
* Function 'strncpy' epilogue
         PDPEPIL
* Function 'strncpy' literal pool
         DS    0D
         LTORG
* Function 'strncpy' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
