 TITLE '/home/mike/repos/crent370/clib/vsnprint.c'
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
* external function 'vsnprintf' prologue
* frame base=88, local stack=72, call args=24
&FUNC    SETC  'vsnprintf'
VSNPRINT PDPPRLG CINDEX=0,FRAME=184,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'vsnprintf' code
         SLR   6,6 ==> uvint
         SLR   7,7 ==> uvint
         LR    4,6 ==> uvint
         LR    5,7 ==> uvint
         L     9,0(11) ==> s
         SLR   8,8 ==> chcount
         ST    8,168(13) ==> chcount,fin
@@L57    EQU   *
         L     2,8(11)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BNE   @@L5
         MVC   168(4,13),=F'1' ==> fin
         B     @@L6
@@L5     EQU   *
         L     2,8(11)
         CLI   0(2),108
         BNE   @@L7
         A     2,=F'1'
         ST    2,8(11)
         CLI   0(2),132
         BNE   @@L8
         L     2,12(11)
         A     2,=F'4'
         ST    2,12(11)
         A     2,=F'-4'
         MVC   172(4,13),0(2) ==> vint
         L     2,172(13) ==> vint
         LPR   15,2 ==> uvint
         LA    3,112(,13) ==> nptr
@@L11    EQU   *
         LR    6,15 ==> uvint
         SRDL  6,32 ==> uvint
         LA    2,10(0,0)
         DR    6,2 ==> uvint
         LA    2,240(,6)
         STC   2,0(3) ==> nptr
         A     3,=F'1' ==> nptr
         LR    4,15 ==> uvint
         SRDL  4,32 ==> uvint
         LA    2,10(0,0)
         DR    4,2 ==> uvint
         LR    15,5 ==> uvint
         LTR   5,5 ==> uvint
         BNE   @@L11
         L     2,172(13) ==> vint
         LTR   2,2
         BNL   @@L15
         MVI   0(3),96 ==> nptr
         A     3,=F'1' ==> nptr
@@L15    EQU   *
         LA    2,112(,13)
@@L16    EQU   *
         BCTR  3,0 ==> nptr
         C     8,4(11) ==> chcount,n
         BNL   @@L19
         MVC   0(1,9),0(3) ==> s,nptr
         A     9,=F'1' ==> s
@@L19    EQU   *
         A     8,=F'1' ==> chcount
         CLR   3,2 ==> nptr
         BE    @@L6
         B     @@L16
@@L8     EQU   *
         MVC   88(4,13),=A(@@LC0)
         L     2,8(11)
         SLR   3,3
         IC    3,0(2)
         ST    3,92(13)
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LTR   15,15 ==> len
         BE    @@L22
         L     2,8(11)
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BE    @@L22
         L     2,12(11)
         A     2,=F'8'
         ST    2,12(11)
         A     2,=F'-8'
         MVC   88(8,13),0(2)
         L     2,8(11)
         SLR   3,3
         IC    3,0(2)
         ST    3,96(13)
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
         SLR   3,3 ==> i
         CR    3,15 ==> i,len
         BNL   @@L6
@@L28    EQU   *
         C     8,4(11) ==> chcount,n
         BNL   @@L27
         IC    2,112(13,3) ==> numbuf
         STC   2,0(9) ==> s
         A     9,=F'1' ==> s
@@L27    EQU   *
         A     8,=F'1' ==> chcount
         A     3,=F'1' ==> i
         CR    3,15 ==> i,len
         BNL   @@L6
         B     @@L28
@@L22    EQU   *
         L     2,8(11)
         CLI   0(2),162
         BNE   @@L30
         L     2,12(11)
         A     2,=F'4'
         ST    2,12(11)
         A     2,=F'-4'
         MVC   176(4,13),0(2) ==> vcptr
         L     3,176(13) ==> vcptr
         LTR   3,3
         BNE   @@L31
         MVC   176(4,13),=A(@@LC1) ==> vcptr
@@L31    EQU   *
         MVC   88(4,13),176(13) ==> vcptr
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         SLR   3,3 ==> i
         CR    3,15 ==> i,len
         BNL   @@L6
@@L37    EQU   *
         C     8,4(11) ==> chcount,n
         BNL   @@L36
         L     2,176(13) ==> vcptr
         IC    2,0(3,2) ==> i
         STC   2,0(9) ==> s
         A     9,=F'1' ==> s
@@L36    EQU   *
         A     8,=F'1' ==> chcount
         A     3,=F'1' ==> i
         CR    3,15 ==> i,len
         BNL   @@L6
         B     @@L37
@@L30    EQU   *
         L     2,8(11)
         IC    2,0(2)
         SLL   2,24
         SRA   2,24
         C     2,=F'-125'
         BNE   @@L39
         L     2,12(11)
         A     2,=F'4'
         ST    2,12(11)
         A     2,=F'-4'
         MVC   172(4,13),0(2) ==> vint
         C     8,4(11) ==> chcount,n
         BNL   @@L56
         MVC   0(1,9),175(13) ==> s,vint
         B     @@L64
@@L39    EQU   *
         L     2,8(11)
         CLI   0(2),149
         BNE   @@L42
         L     2,12(11)
         A     2,=F'4'
         ST    2,12(11)
         A     2,=F'-4'
         L     2,0(2) ==> viptr
         ST    8,0(2) ==> chcount,viptr
         B     @@L6
@@L42    EQU   *
         L     2,8(11)
         IC    2,0(2)
         SLL   2,24
         SRA   2,24
         C     2,=F'108'
         BNE   @@L44
         C     8,4(11) ==> chcount,n
         BNL   @@L56
         STC   2,0(9) ==> s
         B     @@L64
@@L44    EQU   *
         L     15,4(11) ==> extraCh,n
         SR    15,8 ==> extraCh,chcount
         BNL   @@L47
         SLR   15,15 ==> extraCh
@@L47    EQU   *
         LA    2,8(,11)
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         ST    9,96(13) ==> s
         LA    2,12(,11)
         ST    2,100(13)
         ST    15,104(13) ==> extraCh
         LA    1,88(,13)
         L     15,=V(@@EXAMIN)
         BALR  14,15
         LTR   9,9 ==> s
         BE    @@L48
         SLR   3,3 ==> i
         CR    3,15 ==> i,extraCh
         BNL   @@L6
@@L54    EQU   *
         C     8,4(11) ==> chcount,n
         BNL   @@L53
         A     9,=F'1' ==> s
@@L53    EQU   *
         A     8,=F'1' ==> chcount
         A     3,=F'1' ==> i
         CR    3,15 ==> i,extraCh
         BNL   @@L6
         B     @@L54
@@L48    EQU   *
         AR    8,15 ==> chcount,extraCh
         B     @@L6
@@L7     EQU   *
         C     8,4(11) ==> chcount,n
         BNL   @@L56
         L     2,8(11)
         MVC   0(1,9),0(2) ==> s
@@L64    EQU   *
         A     9,=F'1' ==> s
@@L56    EQU   *
         A     8,=F'1' ==> chcount
@@L6     EQU   *
         L     2,8(11)
         A     2,=F'1'
         ST    2,8(11)
         L     3,168(13) ==> fin
         LTR   3,3
         BE    @@L57
         C     8,4(11) ==> chcount,n
         BNL   @@L58
         MVI   0(9),0 ==> s
@@L58    EQU   *
         LR    15,8 ==> chcount
* Function 'vsnprintf' epilogue
         PDPEPIL
* Function 'vsnprintf' literal pool
         DS    0D
         LTORG
* Function 'vsnprintf' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'eEgGfF'
         DC    X'0'
@@LC1    EQU   *
         DC    C'(null)'
         DC    X'0'
         END
