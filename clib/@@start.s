 TITLE '/home/mike/repos/crent370/clib/@@start.c'
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
* external function '__start' prologue
* frame base=88, local stack=520, call args=16
&FUNC    SETC  '__start'
@@START  PDPPRLG CINDEX=0,FRAME=624,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__start' code
         L     4,0(11) ==> p
         L     9,4(11) ==> pgmname
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    7,15 ==> grt
         SLR   6,6 ==> parmLen
         IC    6,0(4) ==> parmLen,p
         SLL   6,8 ==> parmLen
         SLR   2,2
         IC    2,1(4)
         OR    6,2 ==> parmLen
         LTR   6,6 ==> parmLen
         BNH   @@L2
         IC    2,2(4)
         CLM   2,1,=XL1'00'
         BNE   @@L2
         OI    10(15),64 ==> .grtflag1
         SLR   8,8 ==> progLen
         IC    8,3(4) ==> progLen
@@L2     EQU   *
         MVC   88(4,13),=A(@@LC0)
         MVC   92(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(FOPEN)
         BALR  14,15
         LR    2,15 ==> grt
         LA    1,88(,13)
         L     15,=V(@@GTOUT)
         BALR  14,15
         ST    2,0(15) ==> grt
         LA    1,88(,13)
         L     15,=V(@@GTOUT)
         BALR  14,15
         L     2,0(15) ==> grt
         LTR   2,2
         BNE   @@L3
         MVC   88(4,13),=F'12'
         LA    1,88(,13)
         L     15,=V(@@EXITA)
         BALR  14,15
@@L3     EQU   *
         MVC   88(4,13),=A(@@LC2)
         MVC   92(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(FOPEN)
         BALR  14,15
         LR    2,15 ==> grt
         LA    1,88(,13)
         L     15,=V(@@GTERR)
         BALR  14,15
         ST    2,0(15) ==> grt
         LA    1,88(,13)
         L     15,=V(@@GTERR)
         BALR  14,15
         L     2,0(15) ==> grt
         LTR   2,2
         BNE   @@L4
         MVC   88(4,13),=A(@@LC3)
         LA    1,88(,13)
         L     15,=V(PRINTF)
         BALR  14,15
         LA    1,88(,13)
         L     15,=V(@@GTOUT)
         BALR  14,15
         MVC   88(4,13),0(15) ==> grt
         LA    1,88(,13)
         L     15,=V(FCLOSE)
         BALR  14,15
         MVC   88(4,13),=F'12'
         LA    1,88(,13)
         L     15,=V(@@EXITA)
         BALR  14,15
@@L4     EQU   *
         MVC   88(4,13),=A(@@LC4)
         MVC   92(4,13),=A(@@LC5)
         LA    1,88(,13)
         L     15,=V(FOPEN)
         BALR  14,15
         LR    2,15 ==> grt
         LA    1,88(,13)
         L     15,=V(@@GTIN)
         BALR  14,15
         ST    2,0(15) ==> grt
         LA    1,88(,13)
         L     15,=V(@@GTIN)
         BALR  14,15
         L     2,0(15) ==> grt
         LTR   2,2
         BNE   @@L5
         MVC   88(4,13),=A(@@LC6)
         MVC   92(4,13),=A(@@LC5)
         LA    1,88(,13)
         L     15,=V(FOPEN)
         BALR  14,15
         LR    2,15 ==> grt
         LA    1,88(,13)
         L     15,=V(@@GTIN)
         BALR  14,15
         ST    2,0(15) ==> grt
@@L5     EQU   *
         LA    1,88(,13)
         L     15,=V(@@GTIN)
         BALR  14,15
         L     2,0(15) ==> grt
         LTR   2,2
         BNE   @@L6
         LA    1,88(,13)
         L     15,=V(@@GTERR)
         BALR  14,15
         MVC   88(4,13),0(15) ==> grt
         MVC   92(4,13),=A(@@LC7)
         LA    1,88(,13)
         L     15,=V(FPRINTF)
         BALR  14,15
         LA    1,88(,13)
         L     15,=V(@@GTOUT)
         BALR  14,15
         MVC   88(4,13),0(15) ==> grt
         LA    1,88(,13)
         L     15,=V(FCLOSE)
         BALR  14,15
         LA    1,88(,13)
         L     15,=V(@@GTERR)
         BALR  14,15
         MVC   88(4,13),0(15) ==> grt
         LA    1,88(,13)
         L     15,=V(FCLOSE)
         BALR  14,15
         MVC   88(4,13),=F'12'
         LA    1,88(,13)
         L     15,=V(@@EXITA)
         BALR  14,15
@@L6     EQU   *
         MVC   88(4,13),=A(@@LC8)
         LA    1,88(,13)
         L     15,=V(LOADENV)
         BALR  14,15
         LTR   15,15 ==> grt
         BE    @@L7
         MVC   88(4,13),=A(@@LC9)
         LA    1,88(,13)
         L     15,=V(LOADENV)
         BALR  14,15
@@L7     EQU   *
         LA    1,88(,13)
         L     15,=V(TZSET)
         BALR  14,15
         LA    2,307(0,0)
         CLR   6,2 ==> parmLen
         BNH   @@L8
         LR    6,2 ==> parmLen
@@L8     EQU   *
         LTR   6,6 ==> parmLen
         BNL   @@L9
         SLR   6,6 ==> parmLen
@@L9     EQU   *
         LA    5,312(,13) ==> s
         SLR   2,2 ==> c
         LA    3,310(0,0) ==> n
         
*** MEMSET ***
         LR    14,5           => target (s) ==> s
         LR    15,3           => length (n) ==> n
         SLR   0,0             => source (NULL)
         LR    1,2            fill character ==> c
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
         IC    2,10(7) ==> .grtflag1
         N     2,=F'64'
         CLM   2,1,=XL1'00'
         BE    @@L11
         A     6,=F'-4' ==> parmLen
         ST    5,88(13) ==> s
         LR    2,4 ==> p
         A     2,=F'4'
         B     @@L53
@@L52    EQU   *
         SLR   6,6
         STC   6,0(3,5) ==> x
         B     @@L22
@@L11    EQU   *
         LA    2,312(,13)
         ST    2,88(13)
         LR    2,4 ==> p
         A     2,=F'2'
@@L53    EQU   *
         ST    2,92(13)
         ST    6,96(13) ==> parmLen
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         LA    4,312(,13) ==> p
         L     2,12(11) ==> pgmr1
         LTR   2,2
         BE    @@L13
         SLR   3,3 ==> x
         LR    5,7 ==> grt
         A     5,=F'76'
@@L19    EQU   *
         LR    2,3 ==> x
         MH    2,=H'4'
         L     6,12(11) ==> pgmr1
         L     2,0(2,6) ==> u
         ST    5,88(13)
         LR    6,2 ==> u
         N     6,=F'2147483647'
         ST    6,92(13)
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LTR   2,2 ==> u
         BL    @@L13
         A     3,=F'1' ==> x
         LA    2,9(0,0)
         CR    3,2 ==> x
         BNH   @@L19
@@L13    EQU   *
         IC    2,10(7) ==> .grtflag1
         N     2,=F'64'
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BE    @@L20
         ST    4,104(13) ==> p,argv
         SLR   3,3 ==> x
         CR    3,8 ==> x,progLen
         BH    @@L22
         LR    5,4 ==> p
@@L26    EQU   *
         IC    2,0(3,5) ==> x
         SLL   2,24
         SRA   2,24
         C     2,=F'64'
         BE    @@L52
         A     3,=F'1' ==> x
         CR    3,8 ==> x,progLen
         BNH   @@L26
@@L22    EQU   *
         AR    4,8 ==> p,progLen
         B     @@L27
@@L20    EQU   *
         ST    9,104(13) ==> pgmname,argv
         MVI   8(9),0
         ST    9,88(13) ==> pgmname
         MVC   92(4,13),=F'64'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LTR   15,15 ==> pgmname
         BE    @@L27
         MVI   0(15),0 ==> pgmname
@@L27    EQU   *
         CLI   0(4),64 ==> p
         BNE   @@L48
@@L32    EQU   *
         A     4,=F'1' ==> p
         CLI   0(4),64 ==> p
         BE    @@L32
@@L48    EQU   *
         LA    3,1(0,0) ==> x
         IC    2,0(4) ==> p
         CLM   2,1,=XL1'00'
         BE    @@L33
@@L44    EQU   *
         LA    5,64(0,0) ==> srch
         IC    2,0(4) ==> srch,p
         CLM   2,1,=XL1'7F' ==> srch
         BNE   @@L37
         A     4,=F'1' ==> p
         LR    5,2 ==> srch
@@L37    EQU   *
         LR    2,3 ==> x
         MH    2,=H'4'
         ST    4,104(13,2) ==> p,argv
         A     3,=F'1' ==> x
         ST    4,88(13) ==> p
         LR    2,5 ==> srch
         N     2,=XL4'000000FF' ==> srch
         ST    2,92(13) ==> srch
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LR    4,15 ==> p
         LTR   15,15 ==> p
         BE    @@L33
         MVI   0(15),0 ==> p
         A     4,=F'1' ==> p
         CLI   0(4),64 ==> p
         BNE   @@L51
@@L42    EQU   *
         A     4,=F'1' ==> p
         CLI   0(4),64 ==> p
         BE    @@L42
@@L51    EQU   *
         IC    2,0(4) ==> p
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BE    @@L33
         LA    6,49(0,0)
         CR    3,6 ==> x
         BNH   @@L44
@@L33    EQU   *
         LR    2,3 ==> x
         MH    2,=H'4'
         SLR   4,4
         ST    4,104(13,2) ==> argv
         ST    3,88(13) ==> x
         LA    2,104(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(MAIN)
         BALR  14,15
         LR    2,15 ==> rc
         ST    15,88(13) ==> rc
         LA    1,88(,13)
         L     15,=V(@@EXIT)
         BALR  14,15
         LR    15,2 ==> rc
* Function '__start' epilogue
         PDPEPIL
* Function '__start' literal pool
         DS    0D
         LTORG
* Function '__start' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'*SYSPRINT'
         DC    X'0'
@@LC1    EQU   *
         DC    C'w'
         DC    X'0'
@@LC2    EQU   *
         DC    C'*SYSTERM'
         DC    X'0'
@@LC3    EQU   *
         DC    C'SYSTERM DD not defined'
         DC    X'15'
         DC    X'0'
@@LC4    EQU   *
         DC    C'dd:SYSIN'
         DC    X'0'
@@LC5    EQU   *
         DC    C'r'
         DC    X'0'
@@LC6    EQU   *
         DC    C'''NULLFILE'''
         DC    X'0'
@@LC7    EQU   *
         DC    C'SYSIN DD not defined'
         DC    X'15'
         DC    X'0'
@@LC8    EQU   *
         DC    C'dd:SYSENV'
         DC    X'0'
@@LC9    EQU   *
         DC    C'dd:ENVIRON'
         DC    X'0'
         END
