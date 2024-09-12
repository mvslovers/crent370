 TITLE '/home/mike/repos/crent370/clib/perror.c'
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
         DS    0F
@@2      EQU   *
         DC    24X'00'
* Program text area
         DS    0F
         EJECT
* external function 'perror' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'perror'
PERROR   PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'perror' code
         L     4,0(11) ==> s
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   88(4,13),0(15) ==> str
         LA    1,88(,13)
         L     15,=V(STRERROR)
         BALR  14,15
         LR    3,15 ==> str
         LTR   4,4 ==> s
         BE    @@L2
         IC    2,0(4) ==> s
         CLM   2,1,=XL1'00'
         BE    @@L2
         LA    1,88(,13)
         L     15,=V(@@GTERR)
         BALR  14,15
         MVC   88(4,13),0(15) ==> str
         MVC   92(4,13),=A(@@LC0)
         ST    4,96(13) ==> s
         LA    1,88(,13)
         L     15,=V(FPRINTF)
         BALR  14,15
@@L2     EQU   *
         LTR   3,3 ==> str
         BNE   @@L3
         L     3,=A(@@2) ==> str
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         ST    3,88(13) ==> str
         MVC   92(4,13),=A(@@LC1)
         MVC   96(4,13),0(15) ==> str
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
@@L3     EQU   *
         LA    1,88(,13)
         L     15,=V(@@GTERR)
         BALR  14,15
         MVC   88(4,13),0(15) ==> str
         MVC   92(4,13),=A(@@LC2)
         ST    3,96(13) ==> str
         LA    1,88(,13)
         L     15,=V(FPRINTF)
         BALR  14,15
* Function 'perror' epilogue
         PDPEPIL
* Function 'perror' literal pool
         DS    0D
         LTORG
* Function 'perror' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'%s: '
         DC    X'0'
@@LC1    EQU   *
         DC    C'unknown error:%d'
         DC    X'0'
@@LC2    EQU   *
         DC    C'%s'
         DC    X'15'
         DC    X'0'
         END
