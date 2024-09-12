 TITLE '/home/mike/repos/crent370/clib/wtor.c'
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
* external function 'wtor' prologue
* frame base=88, local stack=144, call args=16
&FUNC    SETC  'wtor'
WTOR     PDPPRLG CINDEX=0,FRAME=248,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'wtor' code
         L     8,0(11) ==> reply
         L     6,4(11) ==> replymax
         L     7,8(11) ==> text
         MVC   240(4,13),=F'0'
         SLR   15,15 ==> len
         LA    4,104(,13)
         LA    5,136(0,0)
         LR    2,15 ==> len
         LR    3,15 ==> len
         MVCL  4,2 ==> len
         LTR   7,7 ==> text
         BE    @@L2
         ST    7,88(13) ==> text
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LA    2,122(0,0)
         CLR   15,2 ==> len
         BNH   @@L2
         LR    15,2 ==> len
@@L2     EQU   *
         LTR   8,8 ==> reply
         BE    @@L4
         LTR   6,6 ==> replymax
         BE    @@L4
         LA    2,119(0,0)
         CLR   6,2 ==> replymax
         BNH   @@L5
         LR    6,2 ==> replymax
@@L5     EQU   *
         ST    8,104(13) ==> reply,reply
         STC   6,104(13) ==> replymax,reply_len
         LA    2,240(,13)
         ST    2,108(13) ==> .ecb
@@L4     EQU   *
         LTR   15,15 ==> len
         BE    @@L6
         LR    2,15 ==> len
         A     2,=F'4'
         STH   2,112(13) ==> .text_len
         LA    2,116(,13)
         ST    2,88(13)
         ST    7,92(13) ==> text
         ST    15,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L6     EQU   *
         LA    2,104(,13)
         LR    1,2
         SVC   35
         L     2,108(13) ==> .ecb
         LTR   2,2
         BE    @@L1
         WAIT  1,ECB=(2)
@@L1     EQU   *
* Function 'wtor' epilogue
         PDPEPIL
* Function 'wtor' literal pool
         DS    0D
         LTORG
* Function 'wtor' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
