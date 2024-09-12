 TITLE '/home/mike/repos/crent370/clib/svcmain.c'
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
* external function 'svcmain' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'svcmain'
SVCMAIN  PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'svcmain' code
         L     4,0(11) ==> svcregs
         L     5,4(11) ==> r15
         L     15,32(4) ==> rb,rblink
         L     3,8(4) ==> .r1
         LA    2,4(0,0)
         CLR   3,2
         BH    @@L10
         MH    3,=H'4'
         L     2,=A(@@L11)
         L     14,0(3,2)
         BR    14
         DS    0F
         DS    0F
         DS    0F
         LTORG
         DS    0F
@@L11    EQU   *
         DC    A(@@L3)
         DC    A(@@L4)
         DC    A(@@L5)
         DC    A(@@L8)
         DC    A(@@L9)
@@L3     EQU   *
         SLR   2,2
         IC    2,17(15) ==> .rbopsw
         X     2,=F'1'
         N     2,=F'1'
         ST    2,0(5) ==> r15
         NI    17(15),254 ==> .rbopsw
         B     @@L2
@@L4     EQU   *
         IC    2,17(15) ==> .rbopsw
         N     2,=F'1'
         N     2,=XL4'000000FF'
         ST    2,0(5) ==> r15
         OI    17(15),1 ==> .rbopsw
         B     @@L2
@@L5     EQU   *
         IC    2,17(15) ==> .rbopsw
         N     2,=F'240'
         ST    2,0(5) ==> r15
         CLI   3(4),255 ==> .r15
         BE    @@L2
         NI    17(15),15 ==> .rbopsw
         IC    2,3(4) ==> .r15
         N     2,=F'-16'
         IC    3,17(15) ==> .rbopsw
         OR    3,2
         STC   3,17(15) ==> .rbopsw
         B     @@L2
@@L8     EQU   *
         L     3,36(4) ==> p,jscb
         IC    2,236(3)
         N     2,=F'1'
         N     2,=XL4'000000FF'
         ST    2,0(5) ==> r15
         OI    236(3),1
         B     @@L2
@@L9     EQU   *
         L     3,36(4) ==> p,jscb
         SLR   2,2
         IC    2,236(3)
         X     2,=F'1'
         N     2,=F'1'
         ST    2,0(5) ==> r15
         NI    236(3),254
         B     @@L2
@@L10    EQU   *
         MVC   0(4,5),=F'-1' ==> r15
@@L2     EQU   *
         SLR   15,15
* Function 'svcmain' epilogue
         PDPEPIL
* Function 'svcmain' literal pool
         DS    0D
         LTORG
* Function 'svcmain' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
