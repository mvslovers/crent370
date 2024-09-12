 TITLE '/home/mike/repos/crent370/clib/tsocmd.c'
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
@@6      EQU   *
         DC    C'tsocmd'
         DC    X'0'
         DS    0F
         EJECT
* external function 'tsocmd' prologue
* frame base=88, local stack=24, call args=16
&FUNC    SETC  'tsocmd'
TSOCMD   PDPPRLG CINDEX=0,FRAME=128,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'tsocmd' code
         L     8,0(11) ==> pgm
         MVC   120(4,13),=F'8'
         SLR   9,9 ==> buflen
         ST    9,124(13) ==> buflen,pgmlen
         LA    1,88(,13)
         L     15,=V(@@PPAGET)
         BALR  14,15
         LR    7,15 ==> ppa
         LR    6,9 ==> cbuf,buflen
         LA    4,104(,13)
         LA    5,16(0,0)
         LR    2,9 ==> cbuf
         LR    3,9 ==> cbuf
         MVCL  4,2 ==> cbuf
         LTR   8,8 ==> pgm
         BNE   @@L2
         MVC   88(4,13),=A(@@LC0)
         B     @@L14
@@L2     EQU   *
         LTR   15,15 ==> ppa
         BNE   @@L4
         MVC   88(4,13),=A(@@LC1)
         B     @@L14
@@L4     EQU   *
         L     2,44(15) ==> .ppacppl
         LTR   2,2
         BNE   @@L5
         MVC   88(4,13),=A(@@LC2)
         B     @@L14
@@L5     EQU   *
         LTR   8,8 ==> pgm
         BE    @@L6
         IC    2,0(8) ==> pgm
         CLM   2,1,=XL1'00'
         BE    @@L6
         ST    8,88(13) ==> pgm
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         ST    15,124(13) ==> pgmlen
@@L6     EQU   *
         L     2,4(11) ==> buf
         LTR   2,2
         BE    @@L7
         IC    2,0(2)
         CLM   2,1,=XL1'00'
         BE    @@L7
         MVC   88(4,13),4(11) ==> buf
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    9,15 ==> buflen
@@L7     EQU   *
         MVC   88(4,13),=F'1'
         L     2,124(13) ==> pgmlen
         AR    2,9 ==> buflen
         A     2,=F'8'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    6,15 ==> cbuf
         LTR   15,15 ==> cbuf
         BNE   @@L8
         MVC   88(4,13),=A(@@LC3)
@@L14    EQU   *
         MVC   92(4,13),=A(@@6)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         B     @@L3
@@L8     EQU   *
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),44(7) ==> .ppacppl
         MVC   96(4,13),=F'16'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         L     5,116(13) ==> ect,cpplect
         LR    3,5 ==> s,ect
         A     3,=F'12' ==> s
         LA    2,64(0,0) ==> c
         LA    4,8(0,0) ==> n
         
*** MEMSET ***
         LR    14,3           => target (s) ==> s
         LR    15,4           => length (n) ==> n
         SLR   0,0             => source (NULL)
         LR    1,2            fill character ==> c
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
         L     2,124(13) ==> pgmlen
         CLR   2,4
         BNH   @@L10
         ST    4,124(13) ==> n,pgmlen
@@L10    EQU   *
         LR    2,5 ==> ect
         A     2,=F'12'
         ST    2,88(13)
         ST    8,92(13) ==> pgm
         MVC   96(4,13),124(13) ==> pgmlen
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         MVC   0(2,6),=H'4' ==> .cbuflen
         L     3,124(13) ==> pgmlen
         STH   3,2(6) ==> .cmdlen
         LTR   9,9 ==> buflen
         BNE   @@L11
         OI    28(5),128 ==> .ectsws
         LR    2,6 ==> cbuf
         A     2,=F'4'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC4)
         ST    8,96(13) ==> pgm
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         SLL   15,16 ==> ppa
         SRA   15,16 ==> ppa
         AH    15,0(6) ==> .cbuflen
         STH   15,0(6) ==> .cbuflen
         B     @@L12
@@L11    EQU   *
         NI    28(5),127 ==> .ectsws
         LR    2,6 ==> cbuf
         A     2,=F'4'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC5)
         ST    8,96(13) ==> pgm
         MVC   100(4,13),4(11) ==> buf
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         SLL   15,16 ==> ppa
         SRA   15,16 ==> ppa
         AH    15,0(6) ==> .cbuflen
         STH   15,0(6) ==> .cbuflen
         LH    2,2(6) ==> .cmdlen
         AH    2,=H'1'
         STH   2,2(6) ==> .cmdlen
@@L12    EQU   *
         ST    6,104(13) ==> cbuf,cpplcbuf
         ST    8,88(13) ==> pgm
         MVC   92(4,13),=F'0'
         LA    2,104(,13)
         ST    2,96(13)
         LA    2,120(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@LINK)
         BALR  14,15
@@L3     EQU   *
         LTR   6,6 ==> cbuf
         BE    @@L13
         ST    6,88(13) ==> cbuf
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L13    EQU   *
         L     15,120(13)
* Function 'tsocmd' epilogue
         PDPEPIL
* Function 'tsocmd' literal pool
         DS    0D
         LTORG
* Function 'tsocmd' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'%s: Missing pgm pointer'
         DC    X'0'
@@LC1    EQU   *
         DC    C'%s: No PPA'
         DC    X'0'
@@LC2    EQU   *
         DC    C'%s: No CPPL'
         DC    X'0'
@@LC3    EQU   *
         DC    C'%s: No memory for CBUF'
         DC    X'0'
@@LC4    EQU   *
         DC    C'%s'
         DC    X'0'
@@LC5    EQU   *
         DC    C'%s %s'
         DC    X'0'
         END
