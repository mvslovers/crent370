 TITLE '/home/mike/repos/crent370/clib/@@64mul.c'
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
         
&FUNC    SETC '__64_mul'
* Program text area
@@2      EQU   *
         DC    C'__64_mul'
         DC    X'0'
         DS    0F
         EJECT
* external function '__64_mul' prologue
* frame base=88, local stack=32, call args=32
&FUNC    SETC  '__64_mul'
@@64MUL  PDPPRLG CINDEX=0,FRAME=152,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_mul' code
         SLR   4,4 ==> intermediate
         SLR   5,5 ==> intermediate
         L     2,0(11) ==> a
         LTR   2,2
         BE    @@L1
         L     3,4(11) ==> b
         LTR   3,3
         BE    @@L1
         L     8,8(11) ==> c
         LTR   8,8
         BE    @@L1
         LA    2,120(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64INIT)
         BALR  14,15
         MVC   148(4,13),=F'3' ==> i
@@L15    EQU   *
         LA    2,128(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64INIT)
         BALR  14,15
         LA    6,3(0,0) ==> j
@@L14    EQU   *
         L     3,148(13) ==> k,i
         AR    3,6 ==> k,j
         LA    9,2(0,0)
         CR    3,9 ==> k
         BNH   @@L9
         L     7,148(13) ==> i
         MH    7,=H'2'
         L     8,0(11) ==> a
         LH    2,0(7,8) ==> .array
         N     2,=XL4'0000FFFF'
         LR    8,6 ==> j
         MH    8,=H'2'
         L     9,4(11) ==> b
         LH    5,0(8,9) ==> .array
         N     5,=XL4'0000FFFF'
         MR    4,2 ==> intermediate
         ST    5,144(13) ==> intermediate
         LTR   5,5 ==> intermediate
         BE    @@L9
         LA    9,6(0,0) ==> x
         SR    9,3 ==> x,k
         LA    2,3(0,0)
         CLR   9,2 ==> x
         BNH   @@L13
         MVC   88(4,13),=A(@@LC0)
         MVC   92(4,13),=A(@@2)
         ST    9,96(13) ==> x
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),0(11) ==> a
         MVC   92(4,13),=F'8'
         MVC   96(4,13),=A(@@LC1)
         MVC   100(4,13),=A(@@2)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
         MVC   88(4,13),4(11) ==> b
         MVC   92(4,13),=F'8'
         MVC   96(4,13),=A(@@LC2)
         MVC   100(4,13),=A(@@2)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC3)
         MVC   92(4,13),=A(@@2)
         MVC   96(4,13),148(13) ==> i
         ST    6,100(13) ==> j
         ST    3,104(13) ==> k
         L     3,0(11) ==> a
         LH    2,0(7,3) ==> .array
         N     2,=XL4'0000FFFF'
         ST    2,108(13)
         L     3,4(11) ==> b
         LH    2,0(8,3) ==> .array
         N     2,=XL4'0000FFFF'
         ST    2,112(13)
         ST    5,116(13) ==> intermediate
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
@@L13    EQU   *
         LA    2,136(,13)
         ST    2,88(13)
         MVC   92(4,13),144(13) ==> intermediate
         LA    1,88(,13)
         L     15,=V(@@64FU32)
         BALR  14,15
         LA    2,136(,13)
         ST    2,88(13)
         ST    9,92(13) ==> x
         LA    1,88(,13)
         L     15,=V(@@64LSHW)
         BALR  14,15
         LA    2,136(,13)
         ST    2,88(13)
         LA    2,128(,13)
         ST    2,92(13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64ADD)
         BALR  14,15
@@L9     EQU   *
         BCTR  6,0 ==> j
         LTR   6,6 ==> j
         BNL   @@L14
         LA    2,120(,13)
         ST    2,88(13)
         LA    2,128(,13)
         ST    2,92(13)
         LA    2,120(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64ADD)
         BALR  14,15
         L     8,148(13) ==> i
         BCTR  8,0
         ST    8,148(13) ==> i
         LTR   8,8
         BNL   @@L15
         LA    2,120(,13)
         ST    2,88(13)
         MVC   92(4,13),8(11) ==> c
         LA    1,88(,13)
         L     15,=V(@@64COPY)
         BALR  14,15
@@L1     EQU   *
* Function '__64_mul' epilogue
         PDPEPIL
* Function '__64_mul' literal pool
         DS    0D
         LTORG
* Function '__64_mul' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'%s: *** x=%d is out of range ***'
         DC    X'0'
@@LC1    EQU   *
         DC    C'%s: a'
         DC    X'0'
@@LC2    EQU   *
         DC    C'%s: b'
         DC    X'0'
@@LC3    EQU   *
         DC    C'%s: i=%d, j=%d, k=%d, 0x%04X * 0x%04X intermedia'
         DC    C'te=%u'
         DC    X'0'
         END
