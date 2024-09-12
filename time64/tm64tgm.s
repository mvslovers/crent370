 TITLE '/home/mike/repos/crent370/time64/tm64tgm.c'
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
         
&FUNC    SETC 'timegm64'
         DS    0F
         EJECT
* external function 'timegm64' prologue
* frame base=88, local stack=40, call args=16
&FUNC    SETC  'timegm64'
TM64TGM  PDPPRLG CINDEX=0,FRAME=144,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'timegm64' code
         SLR   4,4
         SLR   5,5
         LR    8,4
         LR    9,5
         ST    4,128(13)
         ST    5,4+128(13)
         ST    4,136(13)
         ST    5,4+136(13)
         ST    0,120(13)
         L     7,0(11) ==> date
         L     3,20(7) ==> orig_year,tm_year
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64INIT)
         BALR  14,15
         LA    2,112(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64INIT)
         BALR  14,15
         LA    2,470(0,0)
         CR    3,2 ==> orig_year
         BNH   @@L20
         LA    6,104(,13)
         LR    2,6
@@L5     EQU   *
         ST    6,88(13)
         MVC   92(4,13),=F'146097'
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64AU32)
         BALR  14,15
         A     3,=F'-400' ==> orig_year
         LA    15,470(0,0)
         CR    3,15 ==> orig_year
         BH    @@L5
@@L20    EQU   *
         LA    2,70(0,0)
         CR    3,2 ==> orig_year
         BNH   @@L6
         LR    6,2 ==> year
         CR    2,3 ==> year,orig_year
         BNL   @@L14
@@L13    EQU   *
         LA    2,104(,13)
         ST    2,88(13)
         LR    15,6 ==> year
         A     15,=F'1900'
         LR    4,15
         SRDA  4,32
         LA    2,400(0,0)
         DR    4,2
         LTR   4,4
         BE    @@L12
         LR    2,15
         N     2,=F'3'
         LTR   2,2
         BNE   @@L10
         LR    8,15
         SRDA  8,32
         LA    15,100(0,0)
         DR    8,15
         LTR   8,8
         BE    @@L10
@@L12    EQU   *
         LA    2,4(0,0)
         B     @@L11
@@L10    EQU   *
         SLR   2,2
@@L11    EQU   *
         L     15,=A(@@2)
         L     2,0(2,15) ==> length_of_year
         ST    2,92(13)
         LA    2,104(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64AI32)
         BALR  14,15
         A     6,=F'1' ==> year
         CR    6,3 ==> year,orig_year
         BNL   @@L14
         B     @@L13
@@L6     EQU   *
         LA    2,69(0,0)
         CR    3,2 ==> orig_year
         BH    @@L14
         DS    0H  year < 70 - indicate failure
         LA    2,112(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'1'
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64SI32)
         BALR  14,15
         L     3,120(13)
         MVC   0(8,3),112(13) ==> <result>
         B     @@L1
@@L14    EQU   *
         SLR   4,4
         A     3,=F'1900'
         ST    3,128(13)
         L     8,128(13)
         L     9,4+128(13)
         SRDA  8,32
         LA    15,400(0,0)
         DR    8,15
         LTR   8,8
         BE    @@L17
         LR    2,3
         N     2,=F'3'
         LTR   2,2
         BNE   @@L16
         ST    3,136(13)
         L     2,136(13)
         L     3,4+136(13)
         SRDA  2,32
         LA    5,100(0,0)
         DR    2,5
         LTR   2,2
         BE    @@L16
@@L17    EQU   *
         LA    4,1(0,0)
@@L16    EQU   *
         ST    4,88(13)
         MVC   92(4,13),16(7) ==> .tm_mon
         LA    1,88(,13)
         L     15,=V(TM64JDBM)
         BALR  14,15
         LA    2,104(,13)
         ST    2,88(13)
         ST    15,92(13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64AI32)
         BALR  14,15
         LA    2,104(,13)
         ST    2,88(13)
         L     2,12(7) ==> .tm_mday
         BCTR  2,0
         ST    2,92(13)
         LA    2,104(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64AI32)
         BALR  14,15
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'86400'
         LA    2,112(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64MI32)
         BALR  14,15
         LA    2,112(,13)
         ST    2,88(13)
         L     2,8(7) ==> .tm_hour
         MH    2,=H'3600'
         ST    2,92(13)
         LA    2,112(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64AI32)
         BALR  14,15
         LA    2,112(,13)
         ST    2,88(13)
         L     2,4(7) ==> .tm_min
         SLL   2,4
         S     2,4(7) ==> .tm_min
         SLL   2,2
         ST    2,92(13)
         LA    2,112(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64AI32)
         BALR  14,15
         LA    2,112(,13)
         ST    2,88(13)
         MVC   92(4,13),0(7) ==> .tm_sec
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64AI32)
         BALR  14,15
@@L18    EQU   *
         L     8,120(13)
         MVC   0(8,8),112(13) ==> <result>
@@L1     EQU   *
         L     15,120(13)
* Function 'timegm64' epilogue
         PDPEPIL
* Function 'timegm64' literal pool
         DS    0D
         LTORG
* Function 'timegm64' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
