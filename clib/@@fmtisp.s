 TITLE '/home/mike/repos/crent370/clib/@@fmtisp.c'
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
* external function '__fmtisp' prologue
* frame base=88, local stack=48, call args=32
&FUNC    SETC  '__fmtisp'
@@FMTISP PDPPRLG CINDEX=0,FRAME=168,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fmtisp' code
         SLR   8,8
         SLR   9,9
         ST    8,160(13)
         ST    9,4+160(13)
         L     4,0(11) ==> pdslist
         L     15,=F'-1' ==> rc
         LR    6,4 ==> data,pdslist
         A     6,=F'12' ==> data
         LTR   4,4 ==> pdslist
         BNE   @@L3
         SLR   6,6 ==> data
@@L3     EQU   *
         L     5,4(11) ==> stat,ispfstat
         LTR   6,6 ==> data
         BE    @@L5
         LTR   5,5 ==> stat
         BE    @@L5
         SLR   3,3 ==> c
         LA    2,76(0,0) ==> n
         
*** MEMSET ***
         LR    14,5           => target (s) ==> stat
         LR    15,2           => length (n) ==> n
         SLR   0,0             => source (NULL)
         LR    1,3            fill character ==> c
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
         CLI   0(4),64 ==> .name
         BNH   @@L9
@@L13    EQU   *
         IC    2,0(3,4) ==> .name
         STC   2,0(3,5) ==> .name
         A     3,=F'1' ==> i
         LA    2,7(0,0)
         CR    3,2 ==> i
         BH    @@L9
         IC    2,0(3,4) ==> .name
         CLM   2,1,=XL1'40'
         BH    @@L13
@@L9     EQU   *
         LR    2,5 ==> stat
         A     2,=F'9'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC0)
         L     2,8(4)
         SRL   2,8
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         IC    15,11(4) ==> .idc
         N     15,=F'31' ==> rc
         MH    15,=H'2' ==> rc
         LTR   15,15 ==> rc
         BE    @@L5
         LR    2,5 ==> stat
         A     2,=F'16'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC1)
         SLR   2,2
         IC    2,0(6) ==> .ver
         ST    2,96(13)
         SLR   2,2
         IC    2,1(6) ==> .mod
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         SLR   2,2
         IC    2,4(6) ==> .crecent
         ST    2,88(13)
         LR    2,6 ==> data
         A     2,=F'5'
         ST    2,92(13)
         LA    2,120(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=A(@@2)
         BALR  14,15
         LTR   15,15 ==> rc
         BNE   @@L15
         LR    2,5 ==> stat
         A     2,=F'22'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC2)
         L     8,140(13) ==> .tm_year
         SRDA  8,32
         LA    3,100(0,0)
         DR    8,3
         ST    8,96(13)
         L     2,136(13) ==> .tm_mon
         A     2,=F'1'
         ST    2,100(13)
         MVC   104(4,13),132(13) ==> .tm_mday
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
@@L15    EQU   *
         SLR   2,2
         IC    2,8(6) ==> .modcent
         ST    2,88(13)
         LR    2,6 ==> data
         A     2,=F'9'
         ST    2,92(13)
         LA    2,120(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=A(@@2)
         BALR  14,15
         LTR   15,15 ==> rc
         BNE   @@L16
         LR    2,5 ==> stat
         A     2,=F'31'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC3)
         MVC   160(4,13),140(13) ==> .tm_year
         L     2,160(13)
         L     3,4+160(13)
         SRDA  2,32
         LA    4,100(0,0)
         DR    2,4
         ST    2,160(13)
         ST    3,4+160(13)
         MVC   96(4,13),160(13)
         L     2,136(13) ==> .tm_mon
         A     2,=F'1'
         ST    2,100(13)
         MVC   104(4,13),132(13) ==> .tm_mday
         SLR   2,2
         IC    2,12(6) ==> .modhm
         ST    2,108(13)
         SLR   2,2
         IC    2,13(6) ==> .modhm
         ST    2,112(13)
         SLR   2,2
         IC    2,3(6) ==> .seconds
         ST    2,116(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
@@L16    EQU   *
         LR    2,5 ==> stat
         A     2,=F'49'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC4)
         LH    2,16(6) ==> .initlines
         N     2,=XL4'0000FFFF'
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         LR    2,5 ==> stat
         A     2,=F'55'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC4)
         LH    2,14(6) ==> .curlines
         N     2,=XL4'0000FFFF'
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         LR    2,5 ==> stat
         A     2,=F'61'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC4)
         LH    2,18(6) ==> .modlines
         N     2,=XL4'0000FFFF'
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         SLR   3,3 ==> i
         CLI   20(6),64 ==> .userid
         BNH   @@L18
@@L22    EQU   *
         IC    2,20(6,3) ==> .userid
         STC   2,67(3,5) ==> .userid
         A     3,=F'1' ==> i
         LA    4,7(0,0)
         CR    3,4 ==> i
         BH    @@L18
         IC    2,20(6,3) ==> .userid
         CLM   2,1,=XL1'40'
         BH    @@L22
@@L18    EQU   *
         SLR   15,15 ==> rc
@@L5     EQU   *
* Function '__fmtisp' epilogue
         PDPEPIL
* Function '__fmtisp' literal pool
         DS    0D
         LTORG
* Function '__fmtisp' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'%06X'
         DC    X'0'
@@LC1    EQU   *
         DC    C'%02u.%02u'
         DC    X'0'
@@LC2    EQU   *
         DC    C'%02u-%02u-%02u'
         DC    X'0'
@@LC3    EQU   *
         DC    C'%02u-%02u-%02u %02X:%02X:%02X'
         DC    X'0'
@@LC4    EQU   *
         DC    C'%u'
         DC    X'0'
         DS    0F
         EJECT
* static function 'cvtdate' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'cvtdate'
@@2      PDPPRLG CINDEX=1,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'cvtdate' code
         L     5,4(11) ==> date
         L     4,8(11) ==> tm
         SLR   3,3 ==> c
         LA    2,36(0,0) ==> n
         
*** MEMSET ***
         LR    14,4           => target (s) ==> tm
         LR    15,2           => length (n) ==> n
         SLR   0,0             => source (NULL)
         LR    1,3            fill character ==> c
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
         IC    3,0(5) ==> date
         N     3,=XL4'000000FF'
         SRL   3,4
         N     3,=XL4'000000FF'
         LR    2,3
         SLL   2,3
         AR    2,3
         AR    2,3
         ST    2,20(4) ==> .tm_year
         IC    2,0(5) ==> date
         N     2,=F'15'
         A     2,20(4) ==> .tm_year
         ST    2,20(4) ==> .tm_year
         L     2,0(11) ==> century
         LTR   2,2 ==> century
         BE    @@L27
         L     2,20(4) ==> .tm_year
         A     2,=F'100'
         ST    2,20(4) ==> .tm_year
@@L27    EQU   *
         IC    3,1(5)
         N     3,=XL4'000000FF'
         SRL   3,4
         N     3,=XL4'000000FF'
         LR    2,3
         SLL   2,3
         AR    2,3
         AR    2,3
         ST    2,12(4) ==> .tm_mday
         IC    3,1(5)
         N     3,=F'15'
         AR    3,2
         LR    2,3
         SLL   2,3
         AR    2,3
         AR    2,3
         ST    2,12(4) ==> .tm_mday
         IC    2,2(5)
         N     2,=XL4'000000FF'
         SRL   2,4
         N     2,=XL4'000000FF'
         A     2,12(4) ==> .tm_mday
         ST    2,12(4) ==> .tm_mday
         ST    4,88(13) ==> tm
         LA    1,88(,13)
         L     15,=V(MKTIME)
         BALR  14,15
         SLR   15,15
* Function 'cvtdate' epilogue
         PDPEPIL
* Function 'cvtdate' literal pool
         DS    0D
         LTORG
* Function 'cvtdate' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         END
