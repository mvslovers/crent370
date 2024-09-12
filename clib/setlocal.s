 TITLE '/home/mike/repos/crent370/clib/setlocal.c'
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
@@LC0    EQU   *
         DC    C'.'
         DC    X'0'
@@LC1    EQU   *
         DC    X'0'
* Program data area
         DS    0F
@@2      EQU   *
         DC    A(@@LC0)
         DC    A(@@LC1)
         DC    A(@@LC1)
         DC    A(@@LC1)
         DC    A(@@LC1)
         DC    A(@@LC1)
         DC    A(@@LC1)
         DC    A(@@LC1)
         DC    A(@@LC1)
         DC    A(@@LC1)
         DC    X'FF'
         DC    X'FF'
         DC    X'FF'
         DC    X'FF'
         DC    X'FF'
         DC    X'FF'
         DC    X'FF'
         DC    X'FF'
* Program text area
         DS    0F
         EJECT
* external function 'setlocale' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'setlocale'
SETLOCAL PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'setlocale' code
         L     3,4(11) ==> locale
         L     2,=A(@@LC2)
         LTR   3,3 ==> locale
         BE    @@L1
         ST    3,88(13) ==> locale
         MVC   92(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LTR   15,15
         BE    @@L5
         ST    3,88(13) ==> locale
         MVC   92(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         SLR   2,2
         LTR   15,15
         BNE   @@L1
@@L5     EQU   *
         L     2,=A(@@LC2)
@@L1     EQU   *
         LR    15,2
* Function 'setlocale' epilogue
         PDPEPIL
* Function 'setlocale' literal pool
         DS    0D
         LTORG
* Function 'setlocale' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC2    EQU   *
         DC    C'C'
         DC    X'0'
         DS    0F
         EJECT
* external function 'localeconv' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'localeconv'
LOCALECO PDPPRLG CINDEX=1,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'localeconv' code
         L     15,=A(@@2)
* Function 'localeconv' epilogue
         PDPEPIL
* Function 'localeconv' literal pool
         DS    0D
         LTORG
* Function 'localeconv' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         END
