 TITLE '/home/mike/repos/crent370/time64/tm64sby.c'
         COPY  PDPTOP
         CSECT
* GNU C version 3.2.3 - c2asm370 version 1.0 (mvs)
*        compiled by GNU C version 13.2.0.
*
* options passed:  -lang-c -I. -I/home/mike/repos/crent370/time64
* -I/home/mike/repos/crent370/include -iprefix -D__GNUC__=3
* -D__GNUC_MINOR__=2 -D__GNUC_PATCHLEVEL__=3 -D__GXX_ABI_VERSION=102
* -D__GCC__ -D__MVS__ -D__GCC__ -D__MVS__ -Asystem=mvs -Acpu=i370
* -Amachine=i370 -D__OPTIMIZE__ -D__STDC_HOSTED__=1 -trigraphs -O1
* -fverbose-asm
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
@@2      EQU   *
         DC    F'365'
         DC    F'366'
         
&FUNC    SETC 'seconds_between_years'
         DS    0F
         EJECT
* external function 'seconds_between_years' prologue
* frame base=88, local stack=40, call args=16
&FUNC    SETC  'seconds_between_years'
TM64SBY  PDPPRLG CINDEX=0,FRAME=144,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'seconds_between_years' code
         SLR   2,2
         SLR   3,3
         ST    2,120(13)
         ST    3,4+120(13)
         ST    2,128(13)
         ST    3,4+128(13)
         LR    4,2 ==> right_year
         LR    5,3 ==> right_year
         ST    2,136(13) ==> right_year
         ST    3,4+136(13) ==> right_year
         LR    6,2
         LR    7,3
         ST    0,112(13)
         L     3,4(11) ==> right_year
         MVC   116(4,13),=F'1' ==> increment
         L     8,0(11) ==> left_year
         CR    8,3 ==> right_year
         BH    @@L3
         MVC   116(4,13),=F'-1' ==> increment
@@L3     EQU   *
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64INIT)
         BALR  14,15
         L     2,0(11) ==> left_year
         LA    9,2400(0,0)
         CR    2,9
         BNH   @@L4
         A     2,=F'-2400'
         ST    2,120(13)
         L     8,120(13)
         L     9,4+120(13)
         SRDA  8,32
         LA    2,400(0,0)
         DR    8,2
         ST    8,120(13)
         ST    9,4+120(13)
         L     2,124(13)
         MH    2,=H'400'
         L     8,0(11) ==> left_year
         SR    8,2
         ST    8,0(11) ==> left_year
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(8,13),=XL8'00000002F0605980'
         LA    1,88(,13)
         L     15,=V(@@64FU64)
         BALR  14,15
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),124(13)
         B     @@L16
@@L4     EQU   *
         L     2,0(11) ==> left_year
         LA    9,1599(0,0)
         CR    2,9
         BH    @@L5
         A     2,=F'-1600'
         ST    2,128(13)
         L     8,128(13)
         L     9,4+128(13)
         SRDA  8,32
         LA    2,400(0,0)
         DR    8,2
         ST    8,128(13)
         ST    9,4+128(13)
         L     2,132(13)
         MH    2,=H'400'
         A     2,0(11) ==> left_year
         ST    2,0(11) ==> left_year
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(8,13),=XL8'00000002F0605980'
         LA    1,88(,13)
         L     15,=V(@@64FU64)
         BALR  14,15
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),132(13)
@@L16    EQU   *
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64MI32)
         BALR  14,15
@@L5     EQU   *
         L     8,0(11) ==> left_year
         CLR   8,3 ==> right_year
         BE    @@L15
@@L13    EQU   *
         LA    2,104(,13)
         ST    2,88(13)
         LR    4,3 ==> right_year
         SRDA  4,32 ==> right_year
         LA    9,400(0,0)
         DR    4,9 ==> right_year
         LTR   4,4
         BE    @@L12
         LR    2,3 ==> right_year
         N     2,=F'3'
         LTR   2,2
         BNE   @@L10
         ST    3,136(13) ==> right_year
         L     8,136(13)
         L     9,4+136(13)
         SRDA  8,32
         LA    2,100(0,0)
         DR    8,2
         ST    8,136(13)
         ST    9,4+136(13)
         LTR   8,8
         BE    @@L10
@@L12    EQU   *
         LA    2,4(0,0)
         B     @@L11
@@L10    EQU   *
         SLR   2,2
@@L11    EQU   *
         L     7,=F'86400'
         L     8,=A(@@2)
         M     6,0(2,8) ==> length_of_year
         ST    7,92(13)
         LA    2,104(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64AI32)
         BALR  14,15
         A     3,116(13) ==> right_year,increment
         L     9,0(11) ==> left_year
         CLR   9,3 ==> right_year
         BNE   @@L13
@@L15    EQU   *
         L     2,112(13)
         MVC   0(8,2),104(13) ==> <result>
         LR    15,2
* Function 'seconds_between_years' epilogue
         PDPEPIL
* Function 'seconds_between_years' literal pool
         DS    0D
         LTORG
* Function 'seconds_between_years' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
