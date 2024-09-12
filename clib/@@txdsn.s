 TITLE '/home/mike/repos/crent370/clib/@@txdsn.c'
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
* external function '__txdsn' prologue
* frame base=88, local stack=80, call args=16
&FUNC    SETC  '__txdsn'
@@TXDSN  PDPPRLG CINDEX=0,FRAME=184,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__txdsn' code
         L     5,0(11) ==> txt99
         L     4,4(11) ==> dataset
         LA    2,1(0,0) ==> err
         LTR   4,4 ==> dataset
         BE    @@L4
         ST    4,88(13) ==> dataset
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    3,15 ==> len
         LA    6,79(0,0)
         CLR   15,6 ==> len
         BH    @@L4
         LA    2,104(,13)
         ST    2,88(13)
         ST    4,92(13) ==> dataset
         ST    15,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         SLR   4,4
         STC   4,104(13,3) ==> dsn
         ST    2,88(13)
         MVC   92(4,13),=F'77'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LR    2,15 ==> member
         LTR   15,15 ==> member
         BE    @@L5
         MVI   0(15),0 ==> member
         A     2,=F'1' ==> member
         ST    2,88(13) ==> member
         MVC   92(4,13),=F'93'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LTR   15,15 ==> p
         BE    @@L6
         MVI   0(15),0 ==> p
@@L6     EQU   *
         ST    2,88(13) ==> member
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         MVC   88(4,13),=F'3'
         MVC   92(4,13),=F'1'
         ST    15,96(13) ==> len
         ST    2,100(13) ==> member
         LA    1,88(,13)
         L     15,=V(@@NWTX99)
         BALR  14,15
         ST    5,88(13) ==> txt99
         ST    15,92(13) ==> len
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LR    2,15 ==> err
         LTR   15,15 ==> err
         BNE   @@L4
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    3,15 ==> len
@@L5     EQU   *
         MVC   88(4,13),=F'2'
         MVC   92(4,13),=F'1'
         ST    3,96(13) ==> len
         LA    2,104(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@NWTX99)
         BALR  14,15
         ST    5,88(13) ==> txt99
         ST    15,92(13) ==> len
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LR    2,15 ==> err
@@L4     EQU   *
         LR    15,2 ==> err
* Function '__txdsn' epilogue
         PDPEPIL
* Function '__txdsn' literal pool
         DS    0D
         LTORG
* Function '__txdsn' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
