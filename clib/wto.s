 TITLE '/home/mike/repos/crent370/clib/wto.c'
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
* external function 'wto' prologue
* frame base=88, local stack=136, call args=16
&FUNC    SETC  'wto'
WTO      PDPPRLG CINDEX=0,FRAME=240,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'wto' code
         L     5,0(11) ==> buf
         ST    5,88(13) ==> buf
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    4,15 ==> len
@@L2     EQU   *
         LA    2,124(0,0)
         CR    4,2 ==> len
         BH    @@L5
         LR    2,4 ==> len
         A     2,=F'4'
         STH   2,104(13) ==> .len
         MVC   106(2,13),=H'0' ==> .mcsflags
         LTR   4,4 ==> len
         BNH   @@L6
         LA    2,108(,13)
         ST    2,88(13)
         ST    5,92(13) ==> buf
         ST    4,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L6     EQU   *
         SLR   4,4 ==> len
         B     @@L7
@@L5     EQU   *
         LR    3,5 ==> p,buf
         A     3,=F'124' ==> p
         CLI   0(3),64 ==> p
         BE    @@L9
         CLR   3,5 ==> p,buf
         BNH   @@L9
@@L12    EQU   *
         BCTR  3,0 ==> p
         CLI   0(3),64 ==> p
         BE    @@L9
         CLR   3,5 ==> p,buf
         BH    @@L12
@@L9     EQU   *
         CLR   3,5 ==> p,buf
         BNE   @@L13
         LR    3,5 ==> p,buf
         A     3,=F'124' ==> p
         B     @@L14
@@L13    EQU   *
         CLI   0(3),64 ==> p
         BNE   @@L14
         A     3,=F'1' ==> p
@@L14    EQU   *
         LR    2,3 ==> p
         SR    2,5 ==> buf
         STH   2,104(13) ==> .len
         MVC   106(2,13),=H'0' ==> .mcsflags
         LA    2,108(,13)
         ST    2,88(13)
         ST    5,92(13) ==> buf
         LH    6,104(13) ==> .len
         SLL   6,16
         SRA   6,16
         ST    6,96(13)
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         LH    2,104(13) ==> .len
         SLR   6,6
         STC   6,108(2,13) ==> .buf
         SR    4,2 ==> len
         BNH   @@L16
         ST    5,88(13) ==> buf
         ST    3,92(13) ==> p
         ST    4,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L16    EQU   *
         SLR   2,2
         STC   2,0(4,5) ==> len
         LH    2,104(13) ==> .len
         AH    2,=H'4'
         STH   2,104(13) ==> .len
@@L7     EQU   *
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(WTOLINE)
         BALR  14,15
         LTR   4,4 ==> len
         BH    @@L2
* Function 'wto' epilogue
         PDPEPIL
* Function 'wto' literal pool
         DS    0D
         LTORG
* Function 'wto' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
