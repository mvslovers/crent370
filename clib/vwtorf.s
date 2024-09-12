 TITLE '/home/mike/repos/crent370/clib/vwtorf.c'
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
* external function 'vwtorf' prologue
* frame base=88, local stack=4096, call args=16
&FUNC    SETC  'vwtorf'
VWTORF   PDPPRLG CINDEX=0,FRAME=4200,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'vwtorf' code
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'4096'
         MVC   96(4,13),8(11) ==> text
         MVC   100(4,13),12(11) ==> tList
         LA    1,88(,13)
         L     15,=V(VSNPRINT)
         BALR  14,15
         LR    3,15 ==> len
         LA    2,4095(0,0)
         CLR   15,2 ==> len
         BNH   @@L2
         LR    3,2 ==> len
@@L2     EQU   *
         SLR   2,2
         STC   2,104(13,3) ==> buf
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'21'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LR    2,15 ==> p
         LTR   15,15 ==> p
         BE    @@L3
         LA    3,104(,13)
@@L7     EQU   *
         MVI   0(2),0 ==> p
         A     2,=F'1' ==> p
         ST    3,88(13)
         LA    1,88(,13)
         L     15,=V(WTO)
         BALR  14,15
         ST    3,88(13)
         ST    2,92(13) ==> p
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         ST    3,88(13)
         MVC   92(4,13),=F'21'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LR    2,15 ==> p
         LTR   15,15 ==> p
         BNE   @@L7
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    3,15 ==> len
         LTR   15,15 ==> len
         BE    @@L1
@@L3     EQU   *
         SLR   2,2
         STC   2,104(13,3) ==> buf
         MVC   88(4,13),0(11) ==> reply
         MVC   92(4,13),4(11) ==> replymax
         LA    2,104(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(WTOR)
         BALR  14,15
@@L1     EQU   *
* Function 'vwtorf' epilogue
         PDPEPIL
* Function 'vwtorf' literal pool
         DS    0D
         LTORG
* Function 'vwtorf' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
