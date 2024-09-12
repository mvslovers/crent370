 TITLE '/home/mike/repos/crent370/clib/memcpy.c'
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
* external function 'memcpy' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'memcpy'
MEMCPY   PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'memcpy' code
         
         L    14,0(11)    => target (s1) ==> s1
         L    15,8(11)    => length (n) ==> n
         L    0,4(11)     => source (s2) ==> s2
         L    1,8(11)     => length (n) ==> n
         MVCL 14,0     Copy source to target
         L     15,0(11)
* Function 'memcpy' epilogue
         PDPEPIL
* Function 'memcpy' literal pool
         DS    0D
         LTORG
* Function 'memcpy' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
