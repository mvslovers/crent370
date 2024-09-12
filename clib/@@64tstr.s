 TITLE '/home/mike/repos/crent370/clib/@@64tstr.c'
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
         
&FUNC    SETC '__64_to_string'
* Program text area
         DS    0F
         EJECT
* external function '__64_to_string' prologue
* frame base=88, local stack=80, call args=16
&FUNC    SETC  '__64_to_string'
@@64TSTR PDPPRLG CINDEX=0,FRAME=184,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_to_string' code
         L     9,0(11) ==> n
         L     8,8(11) ==> nbytes
         SLR   7,7 ==> i
         LR    6,7 ==> x,i
         L     2,=A(@@LC0)
         MVC   104(2,13),0(2) ==> work
         LA    4,106(,13)
         LA    5,48(0,0)
         LR    2,7 ==> i
         LR    3,7 ==> i
         MVCL  4,2 ==> i
         LA    2,160(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'10'
         LA    1,88(,13)
         L     15,=V(@@64FI32)
         BALR  14,15
         LTR   9,9 ==> n
         BE    @@L1
         L     2,4(11) ==> str
         LTR   2,2
         BE    @@L1
         ST    9,88(13) ==> n
         LA    2,168(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@64COPY)
         BALR  14,15
         B     @@L3
@@L7     EQU   *
         LA    2,168(,13)
         ST    2,88(13)
         LA    2,160(,13)
         ST    2,92(13)
         LA    2,168(,13)
         ST    2,96(13)
         LA    2,176(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@64DMOD)
         BALR  14,15
         LH    3,182(13) ==> .array
         N     3,=XL4'0000FFFF'
         L     2,=A(@@LC1)
         IC    2,0(3,2) ==> u
         STC   2,104(6,13) ==> work
         A     6,=F'1' ==> x
@@L3     EQU   *
         LA    2,168(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64IS0)
         BALR  14,15
         LTR   15,15
         BNE   @@L4
         CR    6,8 ==> x,nbytes
         BL    @@L7
@@L4     EQU   *
         LTR   6,6 ==> x
         BNE   @@L8
         CR    7,8 ==> i,nbytes
         BNL   @@L10
         L     2,=F'-16'
         L     3,4(11) ==> str
         STC   2,0(7,3) ==> i
         A     7,=F'1' ==> i
         B     @@L10
@@L8     EQU   *
         BCTR  6,0 ==> x
         LTR   6,6 ==> x
         BL    @@L10
         CR    7,8 ==> i,nbytes
         BNL   @@L10
@@L16    EQU   *
         IC    2,104(13,6) ==> work
         L     3,4(11) ==> str
         STC   2,0(7,3) ==> i
         BCTR  6,0 ==> x
         A     7,=F'1' ==> i
         LTR   6,6 ==> x
         BL    @@L10
         CR    7,8 ==> i,nbytes
         BL    @@L16
@@L10    EQU   *
         CR    7,8 ==> i,nbytes
         BNL   @@L1
         SLR   2,2
         L     3,4(11) ==> str
         STC   2,0(7,3) ==> i
@@L1     EQU   *
* Function '__64_to_string' epilogue
         PDPEPIL
* Function '__64_to_string' literal pool
         DS    0D
         LTORG
* Function '__64_to_string' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'0'
         DC    X'0'
         DC    48X'00'
@@LC1    EQU   *
         DC    C'0123456789'
         DC    X'0'
         END
