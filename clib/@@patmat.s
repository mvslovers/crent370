 TITLE '/home/mike/repos/crent370/clib/@@patmat.c'
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
* external function '__patmat' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__patmat'
@@PATMAT PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__patmat' code
         L     3,0(11) ==> str
         L     4,4(11) ==> pat
         IC    2,0(4) ==> pat
         CLM   2,1,=XL1'00'
         BNE   @@L2
         CLI   0(3),64 ==> str
         BNE   @@L28
@@L6     EQU   *
         A     3,=F'1' ==> str
         CLI   0(3),64 ==> str
         BE    @@L6
@@L28    EQU   *
         IC    2,0(3) ==> str
         CLM   2,1,=XL1'00'
         BE    @@L8
         B     @@L9
@@L2     EQU   *
         CLI   0(4),92 ==> pat
         BNE   @@L10
         CLI   1(4),92
         BNE   @@L30
@@L14    EQU   *
         A     4,=F'1' ==> pat
         CLI   1(4),92
         BE    @@L14
@@L30    EQU   *
         IC    2,1(4)
         CLM   2,1,=XL1'00'
         BE    @@L8
         A     3,=F'1' ==> str
         IC    2,0(3) ==> str
         CLM   2,1,=XL1'00'
         BE    @@L9
@@L22    EQU   *
         CLC   0(1,3),1(4) ==> str
         BE    @@L20
         CLI   1(4),111
         BNE   @@L16
@@L20    EQU   *
         LR    2,3 ==> str
         A     2,=F'1'
         ST    2,88(13)
         LR    2,4 ==> pat
         A     2,=F'2'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=A(@@PATMAT)
         BALR  14,15
         LTR   15,15
         BNE   @@L8
@@L16    EQU   *
         A     3,=F'1' ==> str
         IC    2,0(3) ==> str
         CLM   2,1,=XL1'00'
         BE    @@L9
         B     @@L22
@@L10    EQU   *
         IC    2,0(3) ==> str
         CLM   2,1,=XL1'00'
         BE    @@L9
         CLI   0(4),111 ==> pat
         BE    @@L25
         CLM   2,1,0(4) ==> pat
         BNE   @@L9
@@L25    EQU   *
         LR    2,3 ==> str
         A     2,=F'1'
         ST    2,88(13)
         LR    2,4 ==> pat
         A     2,=F'1'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=A(@@PATMAT)
         BALR  14,15
         LTR   15,15
         BNE   @@L8
@@L9     EQU   *
         SLR   15,15
         B     @@L1
@@L8     EQU   *
         LA    15,1(0,0)
@@L1     EQU   *
* Function '__patmat' epilogue
         PDPEPIL
* Function '__patmat' literal pool
         DS    0D
         LTORG
* Function '__patmat' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
