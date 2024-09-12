 TITLE '/home/mike/repos/crent370/clib/strtol.c'
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
* external function 'strtol' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'strtol'
STRTOL   PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'strtol' code
         L     15,0(11) ==> nptr
         SLR   5,5 ==> neg
         SLR   2,2
         IC    2,0(15) ==> nptr
         L     3,=V(@@ISBUF)
         L     3,0(3) ==> __isbuf
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BE    @@L12
@@L5     EQU   *
         A     15,=F'1' ==> nptr
         SLR   2,2
         IC    2,0(15) ==> nptr
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BNE   @@L5
@@L12    EQU   *
         CLI   0(15),96 ==> nptr
         BNE   @@L6
         LA    5,1(0,0) ==> neg
         AR    15,5 ==> nptr
         B     @@L7
@@L6     EQU   *
         CLI   0(15),78 ==> nptr
         BNE   @@L7
         A     15,=F'1' ==> nptr
@@L7     EQU   *
         ST    15,88(13) ==> nptr
         MVC   92(4,13),4(11) ==> endptr
         MVC   96(4,13),8(11) ==> base
         LA    1,88(,13)
         L     15,=V(STRTOUL)
         BALR  14,15
         LR    2,15 ==> y
         LCR   15,15 ==> x,y
         LTR   5,5 ==> neg
         BNE   @@L10
         LR    15,2 ==> x,y
@@L10    EQU   *
* Function 'strtol' epilogue
         PDPEPIL
* Function 'strtol' literal pool
         DS    0D
         LTORG
* Function 'strtol' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
