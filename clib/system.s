 TITLE '/home/mike/repos/crent370/clib/system.c'
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
* external function 'system' prologue
* frame base=88, local stack=16, call args=24
&FUNC    SETC  'system'
SYSTEM   PDPPRLG CINDEX=0,FRAME=128,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'system' code
         L     3,0(11) ==> string
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    6,15 ==> grt
         ST    3,88(13) ==> string
         MVC   92(4,13),=F'64'
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LR    4,15 ==> p
         LTR   15,15 ==> p
         BNE   @@L2
         ST    3,88(13) ==> string
         ST    15,92(13) ==> p
         LA    1,88(,13)
         L     15,=V(STRCHR)
         BALR  14,15
         LR    4,15 ==> p
@@L2     EQU   *
         LR    5,4 ==> pgm_len,p
         SR    5,3 ==> pgm_len,string
         L     15,=F'-1' ==> grt
         LA    2,8(0,0)
         CLR   5,2 ==> pgm_len
         BH    @@L1
         LA    2,112(,13)
         ST    2,88(13)
         ST    3,92(13) ==> string
         ST    5,96(13) ==> pgm_len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         SLR   2,2
         STC   2,112(13,5) ==> pgm
         SLR   3,3 ==> cnt
         CLR   3,5 ==> cnt,pgm_len
         BNL   @@L13
         L     2,=V(@@TOUP)
         L     15,0(2) ==> __toup
@@L8     EQU   *
         SLR   2,2
         IC    2,112(13,3) ==> pgm
         MH    2,=H'2'
         IC    2,1(2,15)
         STC   2,112(13,3) ==> pgm
         A     3,=F'1' ==> cnt
         CLR   3,5 ==> cnt,pgm_len
         BL    @@L8
@@L13    EQU   *
         IC    2,0(4) ==> p
         CLM   2,1,=XL1'00'
         BE    @@L9
         A     4,=F'1' ==> p
@@L9     EQU   *
         ST    4,88(13) ==> p
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         IC    2,10(6) ==> .grtflag1
         N     2,=F'64'
         N     2,=XL4'000000FF'
         BCTR  2,0
         SRL   2,31
         LA    3,2(0,0)
         SR    3,2
         ST    3,88(13)
         ST    5,92(13) ==> pgm_len
         LA    2,112(,13)
         ST    2,96(13)
         ST    15,100(13) ==> grt
         ST    4,104(13) ==> p
         LA    1,88(,13)
         L     15,=V(@@SYSTEM)
         BALR  14,15
@@L1     EQU   *
* Function 'system' epilogue
         PDPEPIL
* Function 'system' literal pool
         DS    0D
         LTORG
* Function 'system' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
