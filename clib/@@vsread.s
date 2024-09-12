 TITLE '/home/mike/repos/crent370/clib/@@vsread.c'
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
* external function '__vsread' prologue
* frame base=88, local stack=72, call args=24
&FUNC    SETC  '__vsread'
@@VSREAD PDPPRLG CINDEX=0,FRAME=184,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__vsread' code
         L     6,0(11) ==> vs
         L     8,4(11) ==> rec
         L     15,12(11) ==> key
         L     7,16(11) ==> keylen
         LA    4,112(,13)
         LA    5,64(0,0)
         SLR   2,2
         LR    3,2
         MVCL  4,2
         MVC   176(4,13),=F'0'
         LTR   15,15 ==> key
         BE    @@L2
         LTR   7,7 ==> keylen
         BE    @@L2
         ST    6,88(13) ==> vs
         ST    8,92(13) ==> rec
         MVC   96(4,13),8(11)
         ST    15,100(13) ==> key
         ST    7,104(13) ==> keylen
         LA    1,88(,13)
         L     15,=V(@@VSSTEQ)
         BALR  14,15
         B     @@L3
@@L2     EQU   *
         ST    6,88(13) ==> vs
         ST    8,92(13) ==> rec
         MVC   96(4,13),8(11)
         ST    15,100(13) ==> key
         ST    7,104(13) ==> keylen
         LA    1,88(,13)
         L     15,=V(@@VSMDFY)
         BALR  14,15
@@L3     EQU   *
         NI    17(6),223 ==> .flags
         LR    3,6 ==> vs
         A     3,=F'104'
         LA    2,GETDONE
         GET   RPL=(3)
GETDONE  DS    0H
         ST    15,176(13) ==> rc
         IC    2,17(6) ==> .flags
         N     2,=F'2'
         CLM   2,1,=XL1'00'
         BE    @@L4
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   0(4,15),=F'154'
         MVC   8(4,11),=F'-2'
         B     @@L5
@@L4     EQU   *
         IC    2,17(6) ==> .flags
         N     2,=F'1'
         CLM   2,1,=XL1'00'
         BE    @@L6
         MVC   8(4,11),=F'-1'
         B     @@L5
@@L6     EQU   *
         LR    4,6 ==> vs
         A     4,=F'104'
         LA    3,112(,13)
         LA    2,8(,11)
         SHOWCB RPL=(4),FIELDS=RECLEN,AREA=(2),LENGTH=4,MF=(G,(3))
@@L5     EQU   *
         L     15,8(11)
* Function '__vsread' epilogue
         PDPEPIL
* Function '__vsread' literal pool
         DS    0D
         LTORG
* Function '__vsread' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
