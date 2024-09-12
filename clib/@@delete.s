 TITLE '/home/mike/repos/crent370/clib/@@delete.c'
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
         
&FUNC    SETC '__delete'
* Program text area
         DS    0F
         EJECT
* external function '__delete' prologue
* frame base=88, local stack=16, call args=0
&FUNC    SETC  '__delete'
@@DELETE PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__delete' code
         L     6,0(11) ==> module
         SLR   7,7 ==> rc
         LA    4,88(,13)
         LA    5,12(0,0)
         LR    2,7 ==> rc
         LR    3,7 ==> rc
         MVCL  4,2 ==> rc
         LTR   6,6 ==> module
         BE    @@L4
         CLI   0(6),64 ==> module
         BNH   @@L4
         LR    15,7 ==> i,rc
         L     4,=V(@@TOUP)
@@L11    EQU   *
         IC    2,0(6) ==> module
         CLM   2,1,=XL1'00'
         BE    @@L9
         SLR   2,2
         IC    2,0(6) ==> module
         L     3,0(4) ==> __toup
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,88(13,15) ==> name
         A     6,=F'1' ==> module
         B     @@L7
@@L9     EQU   *
         LA    2,64(0,0)
         STC   2,88(13,15) ==> name
@@L7     EQU   *
         A     15,=F'1' ==> i
         LA    2,7(0,0)
         CR    15,2 ==> i
         BNH   @@L11
         LA    2,88(,13)
         DELETE EPLOC=(2)
         LR    7,15         save return code ==> rc
@@L4     EQU   *
         LR    15,7 ==> rc
* Function '__delete' epilogue
         PDPEPIL
* Function '__delete' literal pool
         DS    0D
         LTORG
* Function '__delete' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
