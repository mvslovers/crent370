 TITLE '/home/mike/repos/crent370/clib/isxdigit.c'
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
* external function 'isxdigit' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'isxdigit'
ISXDIGIT PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'isxdigit' code
         L     2,=V(@@ISBUF)
         L     3,0(2) ==> __isbuf
         L     2,0(11) ==> c
         SLL   2,1
         LH    15,0(2,3)
         N     15,=F'1024'
         N     15,=XL4'0000FFFF'
* Function 'isxdigit' epilogue
         PDPEPIL
* Function 'isxdigit' literal pool
         DS    0D
         LTORG
* Function 'isxdigit' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
