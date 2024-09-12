 TITLE '/home/mike/repos/crent370/clib/acos.c'
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
* external function 'acos' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'acos'
ACOS     PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'acos' code
         LM    2,3,0(11) ==> x
         ST    2,88(13) ==> x
         ST    3,4+88(13) ==> x
         LA    1,88(,13)
         L     15,=V(FABS)
         BALR  14,15
         CD    0,=D'1.0E0'
         BNH   @@L2
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   0(4,15),=F'33'
         LD    2,=D'9.99999999999999983034E72'
         B     @@L1
@@L2     EQU   *
         STM   2,3,80(13) ==> x
         LD    0,80(,13)
         LTDR  0,0
         BNL   @@L4
         LCDR  0,0
         STD   0,88(13)
         LA    1,88(,13)
         L     15,=A(ACOS)
         BALR  14,15
         LD    2,=D'3.141592653589793116E0'
         SDR   2,0
         B     @@L1
@@L4     EQU   *
         STM   2,3,80(13) ==> x
         LD    0,80(,13)
         MDR   0,0
         LD    2,=D'1.0E0'
         SDR   2,0
         STD   2,88(13)
         LA    1,88(,13)
         L     15,=V(SQRT)
         BALR  14,15
         STD   0,88(13)
         LA    1,88(,13)
         L     15,=V(ASIN)
         BALR  14,15
         LDR   2,0
@@L1     EQU   *
         LDR   0,2
* Function 'acos' epilogue
         PDPEPIL
* Function 'acos' literal pool
         DS    0D
         LTORG
* Function 'acos' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
