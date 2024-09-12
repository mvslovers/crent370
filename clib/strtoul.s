 TITLE '/home/mike/repos/crent370/clib/strtoul.c'
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
* external function 'strtoul' prologue
* frame base=88, local stack=8, call args=0
&FUNC    SETC  'strtoul'
STRTOUL  PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'strtoul' code
         SLR   2,2
         SLR   3,3
         ST    2,88(13)
         ST    3,4+88(13)
         LR    6,2 ==> base
         LR    7,3 ==> base
         L     4,0(11) ==> nptr
         L     5,8(11) ==> base
         SLR   15,15 ==> x
         LPR   8,5 ==> undecided,base
         BCTR  8,0 ==> undecided
         SRL   8,31 ==> undecided
         SLR   2,2
         IC    2,0(4) ==> nptr
         L     3,=V(@@ISBUF)
         L     3,0(3) ==> __isbuf
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BE    @@L27
@@L6     EQU   *
         A     4,=F'1' ==> nptr
         SLR   2,2
         IC    2,0(4) ==> nptr
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BNE   @@L6
@@L27    EQU   *
         SLR   2,2
         IC    2,0(4) ==> nptr
         L     3,=V(@@ISBUF)
         L     3,0(3) ==> __isbuf
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'8'
         CH    2,=H'0'
         BE    @@L10
         LTR   5,5 ==> base
         BNE   @@L11
         CLI   0(4),240 ==> nptr
         BNE   @@L12
         LA    5,8(0,0) ==> base
         B     @@L11
@@L12    EQU   *
         LA    5,10(0,0) ==> base
         SLR   8,8 ==> undecided
@@L11    EQU   *
         ST    5,92(13) ==> base
         L     2,88(13)
         L     3,4+88(13)
         MR    2,15 ==> x
         ST    2,88(13)
         ST    3,4+88(13)
         SLR   2,2
         IC    2,0(4) ==> nptr
         L     15,92(13) ==> x
         AR    15,2 ==> x
         A     15,=F'-240' ==> x
         B     @@L30
@@L10    EQU   *
         SLR   2,2
         IC    2,0(4) ==> nptr
         L     3,=V(@@ISBUF)
         L     3,0(3) ==> __isbuf
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'2'
         CH    2,=H'0'
         BE    @@L8
         IC    2,0(4) ==> nptr
         CLM   2,1,=XL1'E7'
         BE    @@L17
         CLM   2,1,=XL1'A7'
         BNE   @@L16
@@L17    EQU   *
         LTR   5,5 ==> base
         BE    @@L19
         LA    3,8(0,0)
         CLR   5,3 ==> base
         BNE   @@L18
         LTR   8,8 ==> undecided
         BE    @@L18
@@L19    EQU   *
         LA    5,16(0,0) ==> base
         SLR   8,8 ==> undecided
         B     @@L30
@@L18    EQU   *
         LA    2,16(0,0)
         CLR   5,2 ==> base
         BNE   @@L8
         B     @@L30
@@L16    EQU   *
         LA    3,10(0,0)
         CR    5,3 ==> base
         BNH   @@L8
         LR    7,5 ==> base
         MR    6,15 ==> base,x
         SLR   2,2
         IC    2,0(4) ==> nptr
         L     3,=V(@@TOUP)
         L     3,0(3) ==> __toup
         MH    2,=H'2'
         LH    2,0(2,3)
         LR    15,2 ==> x
         AR    15,7 ==> x,base
         A     15,=F'-183' ==> x
@@L30    EQU   *
         A     4,=F'1' ==> nptr
         B     @@L27
@@L8     EQU   *
         L     2,4(11) ==> endptr
         LTR   2,2
         BE    @@L28
         ST    4,0(2) ==> nptr
@@L28    EQU   *
* Function 'strtoul' epilogue
         PDPEPIL
* Function 'strtoul' literal pool
         DS    0D
         LTORG
* Function 'strtoul' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
