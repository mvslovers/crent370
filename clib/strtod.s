 TITLE '/home/mike/repos/crent370/clib/strtod.c'
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
* external function 'strtod' prologue
* frame base=88, local stack=8, call args=0
&FUNC    SETC  'strtod'
STRTOD   PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'strtod' code
         L     15,0(11) ==> nptr
         L     5,4(11) ==> endptr
         LD    6,=D'0.0E0' ==> x
         LD    0,=D'1.0E0'
         STD   0,88(13) ==> es
         STD   0,80(,13)
         LM    8,9,80(13) ==> xs
         LDR   4,6 ==> xf,x
         STD   0,80(,13)
         LM    6,7,80(13) ==> xd
         SLR   2,2
         IC    2,0(15) ==> nptr
         L     3,=V(@@ISBUF)
         L     3,0(3) ==> __isbuf
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BE    @@L41
@@L5     EQU   *
         A     15,=F'1' ==> nptr
         SLR   2,2
         IC    2,0(15) ==> nptr
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'256'
         CH    2,=H'0'
         BNE   @@L5
@@L41    EQU   *
         CLI   0(15),96 ==> nptr
         BNE   @@L6
         LM    8,9,=D'-1.0E0' ==> xs
         B     @@L46
@@L44    EQU   *
         LDR   0,4 ==> xf
         STM   6,7,80(13) ==> xd
         LD    2,80(,13)
         DDR   0,2
         STM   8,9,80(13) ==> xs
         LD    2,80(,13)
         MDR   0,2
         ADR   6,0 ==> x
         B     @@L15
@@L45    EQU   *
         STM   6,7,80(13) ==> xd
         LD    0,80(,13)
         DDR   6,0 ==> x
         B     @@L22
@@L6     EQU   *
         CLI   0(15),78 ==> nptr
         BNE   @@L7
@@L46    EQU   *
         A     15,=F'1' ==> nptr
@@L7     EQU   *
         L     2,=V(@@ISBUF)
         L     4,0(2) ==> __isbuf
@@L14    EQU   *
         SLR   3,3
         IC    3,0(15) ==> nptr
         LR    2,3
         MH    2,=H'2'
         LH    2,0(2,4)
         N     2,=F'8'
         CH    2,=H'0'
         BE    @@L12
         LDR   2,6 ==> x
         MD    2,=D'1.0E1'
         LR    2,3
         A     2,=F'-240'
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    2,84(,13)
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         LDR   6,2 ==> x
         ADR   6,0 ==> x
         A     15,=F'1' ==> nptr
         B     @@L14
@@L12    EQU   *
         STM   8,9,80(13) ==> xs
         LD    2,80(,13)
         MDR   6,2 ==> x
         CLI   0(15),75 ==> nptr
         BNE   @@L15
         A     15,=F'1' ==> nptr
         L     2,=V(@@ISBUF)
         L     3,0(2) ==> __isbuf
@@L21    EQU   *
         SLR   2,2
         IC    2,0(15) ==> nptr
         MH    2,=H'2'
         LH    2,0(2,3)
         N     2,=F'8'
         CH    2,=H'0'
         BE    @@L44
         LDR   0,4 ==> xf
         MD    0,=D'1.0E1'
         SLR   2,2
         IC    2,0(15) ==> nptr
         A     2,=F'-240'
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    2,84(,13)
         XI    84(13),128
         LD    2,80(,13)
         SD    2,=XL8'4E00000080000000'
         LDR   4,0 ==> xf
         ADR   4,2 ==> xf
         STM   6,7,80(13) ==> xd
         LD    0,80(,13)
         MD    0,=D'1.0E1'
         STD   0,80(,13)
         LM    6,7,80(13) ==> xd
         A     15,=F'1' ==> nptr
         B     @@L21
@@L15    EQU   *
         IC    2,0(15) ==> nptr
         CLM   2,1,=XL1'85'
         BE    @@L23
         CLM   2,1,=XL1'C5'
         BNE   @@L22
@@L23    EQU   *
         A     15,=F'1' ==> nptr
         CLI   0(15),96 ==> nptr
         BNE   @@L24
         LD    2,=D'-1.0E0'
         STD   2,88(13) ==> es
         A     15,=F'1' ==> nptr
@@L24    EQU   *
         LM    6,7,=D'1.0E0' ==> xd
         LD    4,=D'0.0E0' ==> xf
         L     2,=V(@@ISBUF)
         L     4,0(2) ==> __isbuf
@@L37    EQU   *
         SLR   3,3
         IC    3,0(15) ==> nptr
         LR    2,3
         MH    2,=H'2'
         LH    2,0(2,4)
         N     2,=F'8'
         CH    2,=H'0'
         BE    @@L28
         LDR   2,4 ==> xf
         MD    2,=D'1.0E1'
         LR    2,3
         A     2,=F'-240'
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    2,84(,13)
         XI    84(13),128
         LD    0,80(,13)
         SD    0,=XL8'4E00000080000000'
         LDR   4,2 ==> xf
         ADR   4,0 ==> xf
         A     15,=F'1' ==> nptr
         B     @@L37
@@L28    EQU   *
         LTDR  4,4 ==> xf
         BNH   @@L43
@@L33    EQU   *
         STM   6,7,80(13) ==> xd
         LD    0,80(,13)
         MD    0,=D'1.0E1'
         STD   0,80(,13)
         LM    6,7,80(13) ==> xd
         SD    4,=D'1.0E0' ==> xf
         BH    @@L33
@@L43    EQU   *
         LD    2,88(13) ==> es
         LTDR  2,2
         BL    @@L45
         STM   6,7,80(13) ==> xd
         LD    0,80(,13)
         MDR   6,0 ==> x
@@L22    EQU   *
         LTR   5,5 ==> endptr
         BE    @@L38
         ST    15,0(5) ==> nptr,endptr
@@L38    EQU   *
         LDR   0,6 ==> x
* Function 'strtod' epilogue
         PDPEPIL
* Function 'strtod' literal pool
         DS    0D
         LTORG
* Function 'strtod' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
