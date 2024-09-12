 TITLE '/home/mike/repos/crent370/time64/tm64dim.c'
         COPY  PDPTOP
         CSECT
* GNU C version 3.2.3 - c2asm370 version 1.0 (mvs)
*        compiled by GNU C version 13.2.0.
*
* options passed:  -lang-c -I. -I/home/mike/repos/crent370/time64
* -I/home/mike/repos/crent370/include -iprefix -D__GNUC__=3
* -D__GNUC_MINOR__=2 -D__GNUC_PATCHLEVEL__=3 -D__GXX_ABI_VERSION=102
* -D__GCC__ -D__MVS__ -D__GCC__ -D__MVS__ -Asystem=mvs -Acpu=i370
* -Amachine=i370 -D__OPTIMIZE__ -D__STDC_HOSTED__=1 -trigraphs -O1
* -fverbose-asm
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
@@0      EQU   *
         DC    F'31'
         DC    F'28'
         DC    F'31'
         DC    F'30'
         DC    F'31'
         DC    F'30'
         DC    F'31'
         DC    F'31'
         DC    F'30'
         DC    F'31'
         DC    F'30'
         DC    F'31'
         DC    F'31'
         DC    F'29'
         DC    F'31'
         DC    F'30'
         DC    F'31'
         DC    F'30'
         DC    F'31'
         DC    F'31'
         DC    F'30'
         DC    F'31'
         DC    F'30'
         DC    F'31'
         
&FUNC    SETC 'days_in_month'
         DS    0F
         EJECT
* external function 'days_in_month' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'days_in_month'
TM64DIM  PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'days_in_month' code
         L     2,0(11) ==> isleap
         SLL   2,1
         A     2,0(11) ==> isleap
         SLL   2,2
         A     2,4(11) ==> month
         MH    2,=H'4'
         L     3,=A(@@0)
         L     15,0(2,3) ==> dim
* Function 'days_in_month' epilogue
         PDPEPIL
* Function 'days_in_month' literal pool
         DS    0D
         LTORG
* Function 'days_in_month' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
