 TITLE '/home/mike/repos/crent370/clib/@@tmrid.c'
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
         
&FUNC    SETC 'tmr_id'
* Program text area
         DS    0F
         EJECT
* external function 'tmr_id' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'tmr_id'
@@TMRID  PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'tmr_id' code
         SLR   4,4
         SLR   5,5
         LR    6,4 ==> id
         LR    7,5 ==> id
         LA    1,88(,13)
         L     15,=V(@@TMRGET)
         BALR  14,15
         LR    3,15 ==> tmr
         LA    1,88(,13)
         L     15,=V(@@TMINIT)
         BALR  14,15
         ST    3,88(13) ==> tmr
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    8,15 ==> lockrc
@@L2     EQU   *
         LA    1,88(,13)
         L     15,=V(RAND)
         BALR  14,15
         X     15,28(3) ==> .id
         N     15,=F'16777215'
         ST    15,28(3) ==> .id
         N     15,=F'3'
         LA    9,1(0,0)
         CLR   15,9
         BE    @@L7
         BL    @@L6
         LA    9,2(0,0)
         CLR   15,9
         BE    @@L8
         LA    9,3(0,0)
         CLR   15,9
         BE    @@L12
         B     @@L5
@@L6     EQU   *
         LA    1,88(,13)
         L     15,=V(RAND)
         BALR  14,15
         L     2,28(3) ==> id,id
         SR    2,15 ==> id,tmr
         B     @@L5
@@L7     EQU   *
         LA    1,88(,13)
         L     15,=V(RAND)
         BALR  14,15
         LR    2,15 ==> id,tmr
         X     2,28(3) ==> id,id
         B     @@L5
@@L8     EQU   *
         LA    1,88(,13)
         L     15,=V(RAND)
         BALR  14,15
         L     4,28(3) ==> .id
         A     15,=F'1'
         CLR   15,4
         BH    @@L11
         LTR   15,15
         BL    @@L10
         LA    2,1(0,0)
         CLR   15,2
         BE    @@L9
         SRDL  4,32
         DR    4,15
         B     @@L11
@@L9     EQU   *
         SLR   4,4
         B     @@L11
@@L10    EQU   *
         SR    4,15
@@L11    EQU   *
         LR    2,4 ==> id
         B     @@L5
@@L12    EQU   *
         LA    1,88(,13)
         L     15,=V(RAND)
         BALR  14,15
         N     15,=F'255'
         L     7,28(3) ==> id,id
         MR    6,15 ==> id
         LR    2,7 ==> id
@@L5     EQU   *
         N     2,=F'16777215' ==> id
         LA    9,1000(0,0)
         CLR   2,9 ==> id
         BNH   @@L2
         ST    3,88(13) ==> tmr
         ST    2,92(13) ==> id
         LA    1,88(,13)
         L     15,=A(@@6)
         BALR  14,15
         LTR   15,15 ==> tmr
         BE    @@L2
         LTR   8,8 ==> lockrc
         BNE   @@L17
         ST    3,88(13) ==> tmr
         ST    8,92(13) ==> lockrc
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L17    EQU   *
         LR    15,2 ==> id
* Function 'tmr_id' epilogue
         PDPEPIL
* Function 'tmr_id' literal pool
         DS    0D
         LTORG
* Function 'tmr_id' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         
&FUNC    SETC 'unique_id'
         DS    0F
         EJECT
* static function 'unique_id' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'unique_id'
@@6      PDPPRLG CINDEX=1,FRAME=96,BASER=12,ENTRY=NO
         B     @@FEN1
         LTORG
@@FEN1   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG1    EQU   *
         LR    11,1
         L     10,=A(@@PGT1)
* Function 'unique_id' code
         L     6,0(11) ==> tmr
         L     7,4(11) ==> id
         LA    5,1(0,0) ==> rc
         LR    2,6 ==> tmr
         A     2,=F'24'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         SLR   3,3 ==> n
         CLR   3,15 ==> n,count
         BNL   @@L20
         L     4,24(6) ==> .tqe
@@L25    EQU   *
         LR    2,3 ==> n
         MH    2,=H'4'
         L     2,0(2,4) ==> tqe
         LTR   2,2 ==> tqe
         BE    @@L21
         L     2,40(2) ==> .id
         CLR   2,7 ==> id
         BNE   @@L21
         SLR   5,5 ==> rc
         B     @@L20
@@L21    EQU   *
         A     3,=F'1' ==> n
         CLR   3,15 ==> n,count
         BL    @@L25
@@L20    EQU   *
         LTR   5,5 ==> rc
         BE    @@L26
         ST    7,28(6) ==> id,id
@@L26    EQU   *
         LR    15,5 ==> rc
* Function 'unique_id' epilogue
         PDPEPIL
* Function 'unique_id' literal pool
         DS    0D
         LTORG
* Function 'unique_id' page table
@@PGT1   DS    0F
         DC    A(@@PG1)
         END
