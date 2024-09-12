 TITLE '/home/mike/repos/crent370/clib/@@64test.c'
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
         
&FUNC    SETC 'test_return_from_ptr'
* Program text area
         DS    0F
         EJECT
* static function 'test_return_from_ptr' prologue
* frame base=88, local stack=8, call args=0
&FUNC    SETC  'test_return_from_ptr'
@@6      PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'test_return_from_ptr' code
         LR    3,0
         L     2,0(11) ==> value
         MVC   0(8,3),0(2) ==> <result>,value
         LR    15,0
* Function 'test_return_from_ptr' epilogue
         PDPEPIL
* Function 'test_return_from_ptr' literal pool
         DS    0D
         LTORG
* Function 'test_return_from_ptr' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'test_return_from_struct'
         DS    0F
         EJECT
* static function 'test_return_from_struct' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'test_return_from_struct'
@@7      PDPPRLG CINDEX=1,FRAME=88,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'test_return_from_struct' code
         LR    2,0
         MVC   0(8,2),0(11) ==> <result>,value
         LR    15,0
* Function 'test_return_from_struct' epilogue
         PDPEPIL
* Function 'test_return_from_struct' literal pool
         DS    0D
         LTORG
* Function 'test_return_from_struct' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         
&FUNC    SETC 'main'
         DS    0F
         COPY  PDPMAIN
         EJECT
* external function 'main' prologue
* frame base=88, local stack=288, call args=16
&FUNC    SETC  'main'
MAIN     PDPPRLG CINDEX=2,FRAME=392,BASER=12,ENTRY=YES
         B     @@FEN2
         LTORG
@@FEN2   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG2    EQU   *
         LR    11,1
         L     10,=A(@@PGT2)
* Function 'main' code
         MVC   88(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         LA    2,368(,13)
         ST    2,88(13)
         MVC   92(8,13),=XL8'FFEEDDCCBBAA9988'
         LA    1,88(,13)
         L     15,=V(@@64FU64)
         BALR  14,15
         LA    2,368(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'8'
         MVC   96(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
         LA    2,368(,13)
         ST    2,88(13)
         LA    0,360(,13)
         LA    1,88(,13)
         L     15,=V(@@64TU64)
         BALR  14,15
         MVC   376(8,13),360(13)
         LA    2,376(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'8'
         MVC   96(4,13),=A(@@LC2)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
         SLR   4,4 ==> i
         LA    3,368(,13)
@@L8     EQU   *
         ST    3,88(13)
         LA    2,368(,13)
         ST    2,92(13)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(@@64LSFT)
         BALR  14,15
         LA    2,368(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'8'
         MVC   96(4,13),=A(@@LC3)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
         A     4,=F'1' ==> i
         LA    2,7(0,0)
         CR    4,2 ==> i
         BNH   @@L8
         MVC   88(4,13),=A(@@LC4)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         MVC   88(4,13),=A(@@LC5)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         LA    2,368(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'-2147483648'
         LA    1,88(,13)
         L     15,=V(@@64FU32)
         BALR  14,15
         LA    2,368(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'2'
         LA    1,88(,13)
         L     15,=V(@@64LSHW)
         BALR  14,15
         MVC   384(8,13),368(13)
         LA    2,384(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'8'
         MVC   96(4,13),=A(@@LC6)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
         LA    2,368(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'8'
         MVC   96(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
         SLR   4,4 ==> i
@@L13    EQU   *
         LA    2,368(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64RSH1)
         BALR  14,15
         L     2,384(13)
         L     3,4+384(13)
         SRDL  2,1
         ST    2,384(13)
         ST    3,4+384(13)
         LA    2,384(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'8'
         MVC   96(4,13),=A(@@LC7)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
         LA    2,368(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'8'
         MVC   96(4,13),=A(@@LC8)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
         A     4,=F'1' ==> i
         LA    2,63(0,0)
         CR    4,2 ==> i
         BNH   @@L13
         SLR   15,15
* Function 'main' epilogue
         PDPEPIL
* Function 'main' literal pool
         DS    0D
         LTORG
* Function 'main' page table
@@PGT2   DS    0F
         DC    A(@@PG2)
@@LC0    EQU   *
         DC    C'__64_lshift()'
         DC    X'0'
@@LC1    EQU   *
         DC    C'starting result value'
         DC    X'0'
@@LC2    EQU   *
         DC    C'tmp.u64=__64_to_u64(result)'
         DC    X'0'
@@LC3    EQU   *
         DC    C'result after shift 8 bits'
         DC    X'0'
@@LC4    EQU   *
         DC    C'================================================'
         DC    C'========='
         DC    X'0'
@@LC5    EQU   *
         DC    C'__64_rshift_one_bit()'
         DC    X'0'
@@LC6    EQU   *
         DC    C'Uresult value'
         DC    X'0'
@@LC7    EQU   *
         DC    C'Uresult after right shift 1 bit'
         DC    X'0'
@@LC8    EQU   *
         DC    C'result after __64_rshift_one_bit()'
         DC    X'0'
         END   @@MAIN
