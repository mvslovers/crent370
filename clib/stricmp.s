 TITLE '/home/mike/repos/crent370/clib/stricmp.c'
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
* external function 'stricmp' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'stricmp'
STRICMP  PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'stricmp' code
         L     3,0(11) ==> p1,s1
         L     5,4(11) ==> p2,s2
         IC    2,0(3) ==> p1
         CLM   2,1,=XL1'00'
         BE    @@L12
         L     2,=V(@@TOLOW)
         L     6,0(2) ==> __tolow
@@L8     EQU   *
         SLR   2,2
         IC    2,0(3) ==> p1
         MH    2,=H'2'
         IC    4,1(2,6) ==> c1
         SLR   2,2
         IC    2,0(5) ==> p2
         MH    2,=H'2'
         IC    2,1(2,6) ==> c2
         L     15,=F'-1'
         STC   2,80(,13) ==> c2
         CLM   4,1,80(13) ==> c1
         BL    @@L1
         LA    15,1(0,0)
         BH    @@L1
         A     3,=F'1' ==> p1
         A     5,=F'1' ==> p2
         IC    2,0(3) ==> p1
         CLM   2,1,=XL1'00'
         BNE   @@L8
@@L12    EQU   *
         SLR   2,2
         IC    2,0(5) ==> p2
         LCR   2,2
         LR    15,2
         SRL   15,31
         LCR   15,15
@@L1     EQU   *
* Function 'stricmp' epilogue
         PDPEPIL
* Function 'stricmp' literal pool
         DS    0D
         LTORG
* Function 'stricmp' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
