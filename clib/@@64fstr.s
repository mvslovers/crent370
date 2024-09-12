 TITLE '/home/mike/repos/crent370/clib/@@64fstr.c'
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
         
&FUNC    SETC '__64_from_string'
* Program text area
         DS    0F
         EJECT
* external function '__64_from_string' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  '__64_from_string'
@@64FSTR PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_from_string' code
         L     5,0(11) ==> n
         L     4,4(11) ==> str
         CLI   0(4),64 ==> str
         BNE   @@L18
@@L5     EQU   *
         A     4,=F'1' ==> str
         CLI   0(4),64 ==> str
         BE    @@L5
@@L18    EQU   *
         ST    4,88(13) ==> str
         MVC   92(4,13),=A(@@LC0)
         MVC   96(4,13),=F'2'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> c
         BNE   @@L6
         L     6,=A(@@LC1) ==> table
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'16'
         LA    1,88(,13)
         L     15,=V(@@64FI32)
         BALR  14,15
         A     4,=F'2' ==> str
         B     @@L7
@@L6     EQU   *
         ST    4,88(13) ==> str
         MVC   92(4,13),=A(@@LC2)
         MVC   96(4,13),=F'2'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> c
         BNE   @@L8
         L     6,=A(@@LC3) ==> table
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'2'
         LA    1,88(,13)
         L     15,=V(@@64FI32)
         BALR  14,15
         A     4,=F'1' ==> str
         B     @@L7
@@L8     EQU   *
         L     6,=A(@@LC4) ==> table
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'10'
         LA    1,88(,13)
         L     15,=V(@@64FI32)
         BALR  14,15
@@L7     EQU   *
         LTR   5,5 ==> n
         BE    @@L1
         ST    5,88(13) ==> n
         LA    1,88(,13)
         L     15,=V(@@64INIT)
         BALR  14,15
         IC    2,0(4) ==> str
         CLM   2,1,=XL1'00'
         BE    @@L1
@@L16    EQU   *
         SLR   2,2
         IC    2,0(4) ==> str
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(TOLOWER)
         BALR  14,15
         ST    6,88(13) ==> table
         ST    15,92(13) ==> c
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LTR   15,15 ==> p
         BE    @@L1
         LR    2,15 ==> tmp,p
         SR    2,6 ==> tmp,table
         SLL   2,16 ==> tmp
         SRA   2,16 ==> tmp
         ST    5,88(13) ==> n
         LA    3,104(,13)
         ST    3,92(13)
         ST    5,96(13) ==> n
         LA    1,88(,13)
         L     15,=V(@@64MUL)
         BALR  14,15
         AH    2,6(5) ==> .array
         STH   2,6(5) ==> .array
         A     4,=F'1' ==> str
         IC    2,0(4) ==> str
         CLM   2,1,=XL1'00'
         BNE   @@L16
@@L1     EQU   *
* Function '__64_from_string' epilogue
         PDPEPIL
* Function '__64_from_string' literal pool
         DS    0D
         LTORG
* Function '__64_from_string' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'0x'
         DC    X'0'
@@LC1    EQU   *
         DC    C'0123456789abcdef'
         DC    X'0'
@@LC2    EQU   *
         DC    C'0b'
         DC    X'0'
@@LC3    EQU   *
         DC    C'01'
         DC    X'0'
@@LC4    EQU   *
         DC    C'0123456789'
         DC    X'0'
         END
