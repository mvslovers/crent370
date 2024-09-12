 TITLE '/home/mike/repos/crent370/clib/atan2.c'
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
* external function 'atan2' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'atan2'
ATAN2    PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'atan2' code
         LD    2,0(11) ==> y
         LD    4,8(11) ==> x
         CDR   4,2 ==> x,y
         BL    @@L2
         LCDR  0,2 ==> y
         CDR   4,0 ==> x
         BL    @@L5
         LDR   0,2 ==> y
         DDR   0,4 ==> x
         STD   0,88(13)
         LA    1,88(,13)
         L     15,=V(ATAN)
         BALR  14,15
         LDR   2,0
         B     @@L3
@@L5     EQU   *
         LDR   0,4 ==> x
         DDR   0,2 ==> y
         STD   0,88(13)
         LA    1,88(,13)
         L     15,=V(ATAN)
         BALR  14,15
         LD    2,=D'-1.570796326794896558E0'
         B     @@L14
@@L2     EQU   *
         LCDR  0,2 ==> y
         CDR   4,0 ==> x
         BL    @@L8
         LDR   0,4 ==> x
         DDR   0,2 ==> y
         STD   0,88(13)
         LA    1,88(,13)
         L     15,=V(ATAN)
         BALR  14,15
         LD    2,=D'1.570796326794896558E0'
@@L14    EQU   *
         SDR   2,0
         B     @@L3
@@L8     EQU   *
         LTDR  2,2 ==> y
         BL    @@L11
         LDR   0,2 ==> y
         DDR   0,4 ==> x
         STD   0,88(13)
         LA    1,88(,13)
         L     15,=V(ATAN)
         BALR  14,15
         LDR   2,0
         AD    2,=D'3.141592653589793116E0'
         B     @@L3
@@L11    EQU   *
         LDR   0,2 ==> y
         DDR   0,4 ==> x
         STD   0,88(13)
         LA    1,88(,13)
         L     15,=V(ATAN)
         BALR  14,15
         LDR   2,0
         AD    2,=D'-3.141592653589793116E0'
@@L3     EQU   *
         LDR   0,2
* Function 'atan2' epilogue
         PDPEPIL
* Function 'atan2' literal pool
         DS    0D
         LTORG
* Function 'atan2' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
