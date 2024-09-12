 TITLE '/home/mike/repos/crent370/clib/hello.c'
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
         COPY  PDPMAIN
         EJECT
* external function 'main' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'main'
MAIN     PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'main' code
         L     4,0(11) ==> argc
         L     5,4(11) ==> argv
         MVC   88(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         SLR   3,3 ==> i
         CR    3,4 ==> i,argc
         BNL   @@L8
@@L6     EQU   *
         MVC   88(4,13),=A(@@LC1)
         ST    3,92(13) ==> i
         LR    2,3 ==> i
         MH    2,=H'4'
         L     2,0(2,5)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         A     3,=F'1' ==> i
         CR    3,4 ==> i,argc
         BL    @@L6
@@L8     EQU   *
         LA    1,88(,13)
         L     15,=V(@@TZGET)
         BALR  14,15
         MVC   88(4,13),=A(@@LC2)
         ST    15,92(13)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         LA    1,88(,13)
         L     15,=V(TZSET)
         BALR  14,15
         LA    1,88(,13)
         L     15,=V(@@TZGET)
         BALR  14,15
         MVC   88(4,13),=A(@@LC2)
         ST    15,92(13)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   88(4,13),=F'-21600'
         LA    1,88(,13)
         L     15,=V(@@TZSET)
         BALR  14,15
         LA    1,88(,13)
         L     15,=V(@@TZGET)
         BALR  14,15
         MVC   88(4,13),=A(@@LC2)
         ST    15,92(13)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   88(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(TIME)
         BALR  14,15
         ST    15,104(13)
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(CTIME)
         BALR  14,15
         MVC   88(4,13),=A(@@LC3)
         ST    15,92(13)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKTEST)
         BALR  14,15
         MVC   88(4,13),=A(@@LC4)
         ST    15,92(13)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         MVC   88(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(TIME)
         BALR  14,15
         ST    15,104(13)
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(CTIME)
         BALR  14,15
         MVC   88(4,13),=A(@@LC5)
         ST    15,92(13)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         MVC   88(4,13),=A(@@LC4)
         ST    15,92(13)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         SLR   15,15
* Function 'main' epilogue
         PDPEPIL
* Function 'main' literal pool
         DS    0D
         LTORG
* Function 'main' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'Hello World'
         DC    X'15'
         DC    X'0'
@@LC1    EQU   *
         DC    C'argv#%d="%s"'
         DC    X'15'
         DC    X'0'
@@LC2    EQU   *
         DC    C'The current time zone offset is: %d'
         DC    X'15'
         DC    X'0'
@@LC3    EQU   *
         DC    C'Issuing TESTLOCK %s'
         DC    X'0'
@@LC4    EQU   *
         DC    C'rc=%d'
         DC    X'15'
         DC    X'0'
@@LC5    EQU   *
         DC    C'Issuing UNLOCK %s'
         DC    X'0'
         END   @@MAIN
