 TITLE '/home/mike/repos/crent370/time64/tm64jdbm.c'
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
         DC    F'0'
         DC    F'31'
         DC    F'59'
         DC    F'90'
         DC    F'120'
         DC    F'151'
         DC    F'181'
         DC    F'212'
         DC    F'243'
         DC    F'273'
         DC    F'304'
         DC    F'334'
         DC    F'0'
         DC    F'31'
         DC    F'60'
         DC    F'91'
         DC    F'121'
         DC    F'152'
         DC    F'182'
         DC    F'213'
         DC    F'244'
         DC    F'274'
         DC    F'305'
         DC    F'335'
         
&FUNC    SETC 'julian_days_by_month'
         DS    0F
         EJECT
* external function 'julian_days_by_month' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'julian_days_by_month'
TM64JDBM PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'julian_days_by_month' code
         L     2,0(11) ==> isleap
         SLL   2,1
         A     2,0(11) ==> isleap
         SLL   2,2
         A     2,4(11) ==> month
         MH    2,=H'4'
         L     3,=A(@@0)
         L     15,0(2,3) ==> jdbm
* Function 'julian_days_by_month' epilogue
         PDPEPIL
* Function 'julian_days_by_month' literal pool
         DS    0D
         LTORG
* Function 'julian_days_by_month' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
