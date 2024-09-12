 TITLE '/home/mike/repos/crent370/clib/vvprintf.c'
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
* external function 'vvprintf' prologue
* frame base=88, local stack=64, call args=24
&FUNC    SETC  'vvprintf'
VVPRINTF PDPPRLG CINDEX=0,FRAME=176,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'vvprintf' code
         SLR   6,6 ==> uvint
         SLR   7,7 ==> uvint
         LR    4,6 ==> uvint
         LR    5,7 ==> uvint
         L     9,12(11) ==> s
         SLR   8,8 ==> chcount
         ST    8,168(13) ==> chcount,fin
         L     2,8(11) ==> fq
         LTR   2,2
         BE    @@L2
         ST    2,88(13)
         ST    8,92(13) ==> chcount
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
@@L2     EQU   *
         L     3,168(13) ==> fin
         LTR   3,3
         BNE   @@L50
@@L47    EQU   *
         L     2,0(11)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BNE   @@L6
         MVC   168(4,13),=F'1' ==> fin
         B     @@L7
@@L6     EQU   *
         L     2,0(11)
         CLI   0(2),108
         BNE   @@L8
         A     2,=F'1'
         ST    2,0(11)
         CLI   0(2),132
         BNE   @@L9
         L     2,4(11)
         A     2,=F'4'
         ST    2,4(11)
         A     2,=F'-4'
         MVC   172(4,13),0(2) ==> vint
         L     2,172(13) ==> vint
         LPR   15,2 ==> uvint
         LA    3,112(,13) ==> nptr
@@L12    EQU   *
         LR    6,15 ==> uvint
         SRDL  6,32 ==> uvint
         LA    2,10(0,0)
         DR    6,2 ==> uvint
         LA    2,240(,6)
         STC   2,0(3) ==> nptr
         A     3,=F'1' ==> nptr
         LR    4,15 ==> uvint
         SRDL  4,32 ==> uvint
         LA    15,10(0,0)
         DR    4,15 ==> uvint
         LR    15,5 ==> uvint
         LTR   5,5 ==> uvint
         BNE   @@L12
         L     2,172(13) ==> vint
         LTR   2,2
         BNL   @@L17
         MVI   0(3),96 ==> nptr
         A     3,=F'1' ==> nptr
@@L17    EQU   *
         BCTR  3,0 ==> nptr
         L     15,8(11) ==> fq
         LTR   15,15
         BNE   @@L20
         MVC   0(1,9),0(3) ==> s,nptr
         A     9,=F'1' ==> s
         B     @@L21
@@L20    EQU   *
         SLR   2,2
         IC    2,0(3) ==> nptr
         ST    2,88(13)
         MVC   92(4,13),8(11) ==> fq
         LA    1,88(,13)
         L     15,=V(@@FPUTC)
         BALR  14,15
@@L21    EQU   *
         A     8,=F'1' ==> chcount
         LA    2,112(,13)
         CLR   3,2 ==> nptr
         BE    @@L7
         B     @@L17
@@L9     EQU   *
         MVC   88(4,13),=A(@@LC0)
         L     2,0(11)
         SLR   3,3
         IC    3,0(2)
         ST    3,92(13)
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LTR   15,15 ==> len
         BE    @@L24
         L     2,0(11)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BE    @@L24
         L     2,4(11)
         A     2,=F'8'
         ST    2,4(11)
         A     2,=F'-8'
         MVC   88(8,13),0(2)
         L     2,0(11)
         SLR   15,15
         IC    15,0(2)
         ST    15,96(13)
         MVC   100(4,13),=F'0'
         MVC   104(4,13),=F'6'
         LA    2,112(,13)
         ST    2,108(13)
         LA    1,88(,13)
         L     15,=V(@@DBLCVT)
         BALR  14,15
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    3,15 ==> len
         L     15,8(11) ==> fq
         LTR   15,15
         BE    @@L54
         LA    2,112(,13)
         ST    2,88(13)
         MVC   92(4,13),8(11) ==> fq
         LA    1,88(,13)
         L     15,=V(FPUTS)
         BALR  14,15
         B     @@L51
@@L24    EQU   *
         L     2,0(11)
         CLI   0(2),162
         BNE   @@L28
         L     2,4(11)
         A     2,=F'4'
         ST    2,4(11)
         A     2,=F'-4'
         L     2,0(2) ==> vcptr
         LTR   2,2 ==> vcptr
         BNE   @@L29
         L     2,=A(@@LC1) ==> vcptr
@@L29    EQU   *
         L     3,8(11) ==> fq
         LTR   3,3
         BNE   @@L30
         ST    2,88(13) ==> vcptr
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    3,15 ==> len
@@L54    EQU   *
         ST    9,88(13) ==> s
         ST    2,92(13) ==> vcptr
         ST    3,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         AR    9,3 ==> s,len
@@L51    EQU   *
         AR    8,3 ==> chcount,len
         B     @@L7
@@L30    EQU   *
         ST    2,88(13) ==> vcptr
         MVC   92(4,13),8(11) ==> fq
         LA    1,88(,13)
         L     15,=V(FPUTS)
         BALR  14,15
         ST    2,88(13) ==> vcptr
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         AR    8,15 ==> chcount,len
         B     @@L7
@@L28    EQU   *
         L     2,0(11)
         CLI   0(2),131
         BNE   @@L33
         L     2,4(11)
         A     2,=F'4'
         ST    2,4(11)
         A     2,=F'-4'
         MVC   172(4,13),0(2) ==> vint
         L     15,8(11) ==> fq
         LTR   15,15
         BNE   @@L34
         MVC   0(1,9),175(13) ==> s,vint
         B     @@L53
@@L34    EQU   *
         MVC   88(4,13),172(13) ==> vint
         B     @@L52
@@L33    EQU   *
         L     2,0(11)
         CLI   0(2),149
         BNE   @@L37
         L     2,4(11)
         A     2,=F'4'
         ST    2,4(11)
         A     2,=F'-4'
         L     2,0(2) ==> viptr
         ST    8,0(2) ==> chcount,viptr
         B     @@L7
@@L37    EQU   *
         L     2,0(11)
         IC    2,0(2)
         CLM   2,1,=XL1'6C'
         BNE   @@L39
         L     3,8(11) ==> fq
         LTR   3,3
         BNE   @@L40
         STC   2,0(9) ==> s
         B     @@L53
@@L40    EQU   *
         MVC   88(4,13),=F'108'
         B     @@L52
@@L39    EQU   *
         ST    11,88(13)
         MVC   92(4,13),8(11) ==> fq
         ST    9,96(13) ==> s
         LA    2,4(,11)
         ST    2,100(13)
         ST    8,104(13) ==> chcount
         LA    1,88(,13)
         L     15,=V(@@EXAMIN)
         BALR  14,15
         AR    8,15 ==> chcount,extraCh
         LTR   9,9 ==> s
         BE    @@L7
         AR    9,15 ==> s,extraCh
         B     @@L7
@@L8     EQU   *
         L     15,8(11) ==> fq
         LTR   15,15
         BNE   @@L45
         L     2,0(11)
         MVC   0(1,9),0(2) ==> s
@@L53    EQU   *
         A     9,=F'1' ==> s
         B     @@L46
@@L45    EQU   *
         L     2,0(11)
         SLR   3,3
         IC    3,0(2)
         ST    3,88(13)
@@L52    EQU   *
         MVC   92(4,13),8(11) ==> fq
         LA    1,88(,13)
         L     15,=V(@@FPUTC)
         BALR  14,15
@@L46    EQU   *
         A     8,=F'1' ==> chcount
@@L7     EQU   *
         L     2,0(11)
         A     2,=F'1'
         ST    2,0(11)
         L     15,168(13) ==> fin
         LTR   15,15
         BE    @@L47
@@L50    EQU   *
         L     2,8(11) ==> fq
         LTR   2,2
         BE    @@L48
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L48    EQU   *
         LR    15,8 ==> chcount
* Function 'vvprintf' epilogue
         PDPEPIL
* Function 'vvprintf' literal pool
         DS    0D
         LTORG
* Function 'vvprintf' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'eEgGfF'
         DC    X'0'
@@LC1    EQU   *
         DC    C'(null)'
         DC    X'0'
         END
