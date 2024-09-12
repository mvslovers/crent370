 TITLE '/home/mike/repos/crent370/clib/rename.c'
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
* external function 'rename' prologue
* frame base=88, local stack=576, call args=16
&FUNC    SETC  'rename'
RENAME   PDPPRLG CINDEX=0,FRAME=680,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'rename' code
         LA    2,104(,13) ==> p
         ST    2,88(13) ==> p
         MVC   92(4,13),=A(@@LC0)
         MVC   96(4,13),0(11) ==> old
         MVC   100(4,13),4(11) ==> newnam
         LA    1,88(,13)
         L     15,=V(SPRINTF)
         BALR  14,15
         LR    15,2 ==> p
         IC    2,0(2) ==> p
         CLM   2,1,=XL1'00'
         BE    @@L7
         L     2,=V(@@TOUP)
         L     3,0(2) ==> __toup
@@L5     EQU   *
         SLR   2,2
         IC    2,0(15) ==> p
         MH    2,=H'2'
         IC    2,1(2,3)
         STC   2,0(15) ==> p
         A     15,=F'1' ==> p
         IC    2,0(15) ==> p
         CLM   2,1,=XL1'00'
         BNE   @@L5
@@L7     EQU   *
         MVC   88(4,13),=V(IDCAMS)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(IDCAMS)
         BALR  14,15
         LR    2,15 ==> ret
         MVC   88(4,13),=V(IDCAMS)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LR    15,2 ==> ret
* Function 'rename' epilogue
         PDPEPIL
* Function 'rename' literal pool
         DS    0D
         LTORG
* Function 'rename' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C' ALTER %s NEWNAME(%s)'
         DC    X'0'
         END
