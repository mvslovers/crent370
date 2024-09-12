 TITLE '/home/mike/repos/crent370/time64/tm64gmtr.c'
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
         
&FUNC    SETC 'gmtime64_r'
         DS    0F
         EJECT
* external function 'gmtime64_r' prologue
* frame base=88, local stack=88, call args=16
&FUNC    SETC  'gmtime64_r'
TM64GMTR PDPPRLG CINDEX=0,FRAME=192,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'gmtime64_r' code
         SLR   2,2
         SLR   3,3
         ST    2,168(13)
         ST    3,4+168(13)
         ST    2,176(13)
         ST    3,4+176(13)
         LR    4,2
         LR    5,3
         LR    8,2
         LR    9,3
         L     2,0(11) ==> in_time
         MVC   104(8,13),0(2) ==> in_time
         LA    7,70(0,0) ==> year
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'60'
         ST    2,96(13)
         LA    2,112(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@64VU32)
         BALR  14,15
         LA    2,112(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64TI32)
         BALR  14,15
         ST    15,136(13) ==> v_tm_sec
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'60'
         ST    2,96(13)
         LA    2,112(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@64VU32)
         BALR  14,15
         LA    2,112(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64TI32)
         BALR  14,15
         ST    15,140(13) ==> v_tm_min
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'24'
         ST    2,96(13)
         LA    2,112(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@64VU32)
         BALR  14,15
         LA    2,112(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64TI32)
         BALR  14,15
         ST    15,144(13) ==> v_tm_hour
         L     2,104(13)
         L     3,4+104(13)
         ST    2,160(13) ==> v_tm_tday
         ST    3,4+160(13) ==> v_tm_tday
         ST    2,120(13)
         ST    3,4+120(13)
         LA    2,120(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'4'
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64AU32)
         BALR  14,15
         LA    2,120(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'7'
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64QU32)
         BALR  14,15
         LA    2,120(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64TI32)
         BALR  14,15
         ST    15,152(13) ==> v_tm_wday
         LTR   15,15
         BNL   @@L2
         LR    3,15
         A     3,=F'7'
         ST    3,152(13) ==> v_tm_wday
@@L2     EQU   *
         L     2,160(13) ==> v_tm_tday
         L     3,4+160(13) ==> v_tm_tday
         ST    2,128(13)
         ST    3,4+128(13)
         LA    2,128(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'13879'
         LA    1,88(,13)
         L     15,=V(@@64CU32)
         BALR  14,15
         L     3,=F'-1'
         CLR   15,3 ==> v_tm_sec
         BE    @@L3
         LA    7,108(0,0) ==> year
         LA    2,128(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'13879'
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64SU32)
         BALR  14,15
@@L3     EQU   *
         LA    2,128(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@64CU32)
         BALR  14,15
         L     2,=F'-1'
         CLR   15,2 ==> v_tm_sec
         BE    @@L4
         LA    2,128(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'146097'
         LA    2,120(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64DU32)
         BALR  14,15
         LA    2,120(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64TI32)
         BALR  14,15
         LR    3,15 ==> cycles
         LTR   15,15 ==> cycles
         BE    @@L5
         LA    2,120(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'146097'
         LA    1,88(,13)
         L     15,=V(@@64FU32)
         BALR  14,15
         LA    2,120(,13)
         ST    2,88(13)
         ST    3,92(13) ==> cycles
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64MU32)
         BALR  14,15
         LA    2,128(,13)
         ST    2,88(13)
         LA    2,120(,13)
         ST    2,92(13)
         LA    2,128(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64SUB)
         BALR  14,15
         LA    2,120(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'400'
         LA    1,88(,13)
         L     15,=V(@@64FU32)
         BALR  14,15
         LA    2,120(,13)
         ST    2,88(13)
         ST    3,92(13) ==> cycles
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64MU32)
         BALR  14,15
         LA    2,120(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64TI32)
         BALR  14,15
         AR    7,15 ==> year,v_tm_sec
@@L5     EQU   *
         SLR   6,6 ==> leap
         LR    3,7 ==> year
         A     3,=F'1900'
         ST    3,184(13)
         ST    3,168(13)
         L     2,168(13)
         L     3,4+168(13)
         SRDA  2,32
         LA    15,400(0,0)
         DR    2,15
         LTR   2,2
         BE    @@L7
         L     2,184(13)
         N     2,=F'3'
         LTR   2,2
         BNE   @@L6
         MVC   176(4,13),184(13)
         L     2,176(13)
         L     3,4+176(13)
         SRDA  2,32
         LA    15,100(0,0)
         DR    2,15
         LTR   2,2
         BE    @@L6
@@L7     EQU   *
         LA    6,1(0,0) ==> leap
@@L6     EQU   *
         LTR   6,6 ==> leap
         BE    @@L9
         B     @@L21
@@L15    EQU   *
         LA    2,128(,13)
         ST    2,88(13)
         LR    3,6 ==> leap
         MH    3,=H'4'
         L     2,=A(@@2)
         L     2,0(3,2) ==> length_of_year
         ST    2,92(13)
         LA    2,128(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64SI32)
         BALR  14,15
         A     7,=F'1' ==> year
         SLR   6,6 ==> leap
         LR    3,7 ==> year
         A     3,=F'1900'
         LR    4,3
         SRDA  4,32
         LA    2,400(0,0)
         DR    4,2
         LTR   4,4
         BE    @@L13
         LR    2,3
         N     2,=F'3'
         LTR   2,2
         BNE   @@L12
         LR    8,3
         SRDA  8,32
         LA    3,100(0,0)
         DR    8,3
         LTR   8,8
         BE    @@L12
@@L13    EQU   *
         LA    6,1(0,0) ==> leap
@@L12    EQU   *
         LTR   6,6 ==> leap
         BE    @@L9
@@L21    EQU   *
         LA    6,1(0,0) ==> leap
@@L9     EQU   *
         LA    2,128(,13)
         ST    2,88(13)
         LR    3,6 ==> leap
         MH    3,=H'4'
         L     2,=A(@@2)
         L     2,0(3,2) ==> length_of_year
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@64CI32)
         BALR  14,15
         MVC   148(4,13),=F'0' ==> v_tm_mon
         L     2,=F'-1'
         CLR   15,2 ==> v_tm_sec
         BE    @@L16
         B     @@L15
@@L19    EQU   *
         ST    6,88(13) ==> leap
         MVC   92(4,13),148(13) ==> v_tm_mon
         LA    1,88(,13)
         L     15,=V(TM64DIM)
         BALR  14,15
         LA    2,128(,13)
         ST    2,88(13)
         ST    15,92(13) ==> v_tm_sec
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@64SI32)
         BALR  14,15
         L     3,148(13) ==> v_tm_mon
         A     3,=F'1'
         ST    3,148(13) ==> v_tm_mon
@@L16    EQU   *
         ST    6,88(13) ==> leap
         MVC   92(4,13),148(13) ==> v_tm_mon
         LA    1,88(,13)
         L     15,=V(TM64DIM)
         BALR  14,15
         LA    2,128(,13)
         ST    2,88(13)
         ST    15,92(13) ==> v_tm_sec
         LA    1,88(,13)
         L     15,=V(@@64CI32)
         BALR  14,15
         L     4,=F'-1'
         CLR   15,4 ==> v_tm_sec
         BNE   @@L19
@@L4     EQU   *
         L     15,4(11) ==> p
         ST    7,20(15) ==> year,tm_year
         LA    2,128(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@64TI32)
         BALR  14,15
         LR    3,15 ==> i
         LR    2,15 ==> i
         A     2,=F'1'
         L     4,4(11) ==> p
         ST    2,12(4) ==> .tm_mday
         ST    6,88(13) ==> leap
         MVC   92(4,13),148(13) ==> v_tm_mon
         LA    1,88(,13)
         L     15,=V(TM64JDBM)
         BALR  14,15
         AR    15,3 ==> i
         ST    15,28(4) ==> .tm_yday
         MVC   0(4,4),136(13) ==> .tm_sec,v_tm_sec
         MVC   4(4,4),140(13) ==> .tm_min,v_tm_min
         MVC   8(4,4),144(13) ==> .tm_hour,v_tm_hour
         MVC   16(4,4),148(13) ==> .tm_mon,v_tm_mon
         MVC   24(4,4),152(13) ==> .tm_wday,v_tm_wday
         LR    15,4 ==> p
* Function 'gmtime64_r' epilogue
         PDPEPIL
* Function 'gmtime64_r' literal pool
         DS    0D
         LTORG
* Function 'gmtime64_r' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
