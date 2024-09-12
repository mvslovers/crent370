 TITLE '/home/mike/repos/crent370/clib/@@b64dec.c'
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
* external function 'base64_decode' prologue
* frame base=88, local stack=264, call args=16
&FUNC    SETC  'base64_decode'
@@B64DEC PDPPRLG CINDEX=0,FRAME=368,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'base64_decode' code
         L     7,0(11) ==> src
         L     6,4(11) ==> len
         SLR   9,9 ==> pad
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),=F'128'
         MVC   96(4,13),=F'256'
         LA    1,88(,13)
         L     15,=V(MEMSET)
         BALR  14,15
         LR    4,9 ==> i,pad
         L     3,=V(@@B64TBL)
@@L6     EQU   *
         SLR   2,2
         IC    2,0(4,3) ==> __b64tbl
         STC   4,104(13,2) ==> i,dtable
         A     4,=F'1' ==> i
         LA    2,63(0,0)
         CLR   4,2 ==> i
         BNH   @@L6
         MVI   230(13),0 ==> dtable
         SLR   4,4 ==> i
         LR    3,4 ==> count,i
         CLR   4,6 ==> i,len
         BNL   @@L32
@@L12    EQU   *
         SLR   2,2
         IC    2,0(4,7) ==> i
         IC    2,104(13,2) ==> dtable
         CLM   2,1,=XL1'80'
         BE    @@L9
         A     3,=F'1' ==> count
@@L9     EQU   *
         A     4,=F'1' ==> i
         CLR   4,6 ==> i,len
         BL    @@L12
@@L32    EQU   *
         LTR   3,3 ==> count
         BE    @@L36
         LR    2,3 ==> count
         N     2,=F'3'
         LTR   2,2
         BNE   @@L36
         LR    2,3 ==> olen,count
         SRL   2,2 ==> olen
         LR    3,2 ==> olen
         SLL   3,1
         AR    2,3 ==> olen
         MVC   88(4,13),=F'1'
         ST    2,92(13) ==> olen
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         ST    15,364(13) ==> out
         LR    8,15 ==> pos
         LTR   15,15 ==> out
         BE    @@L1
         B     @@L15
@@L34    EQU   *
         BCTR  8,0 ==> pos
         B     @@L17
@@L35    EQU   *
         A     8,=F'-2' ==> pos
         B     @@L17
@@L15    EQU   *
         SLR   4,4 ==> i
         LR    3,4 ==> count,i
         CLR   4,6 ==> i,len
         BNL   @@L17
         LA    15,361(,13)
@@L28    EQU   *
         SLR   2,2
         IC    2,0(4,7) ==> i
         IC    5,104(13,2) ==> tmp,dtable
         CLM   5,1,=XL1'80' ==> tmp
         BE    @@L18
         IC    2,0(4,7) ==> i
         CLM   2,1,=XL1'7E'
         BNE   @@L21
         A     9,=F'1' ==> pad
@@L21    EQU   *
         STC   5,360(3,13) ==> tmp,block
         A     3,=F'1' ==> count
         LA    2,4(0,0)
         CLR   3,2 ==> count
         BNE   @@L18
         SLR   2,2
         IC    2,360(13)
         SLL   2,2
         IC    3,0(15) ==> block
         N     3,=XL4'000000FF'
         SRL   3,4
         OR    3,2
         STC   3,0(8) ==> pos
         A     8,=F'1' ==> pos
         IC    3,0(15) ==> block
         SLL   3,4
         IC    2,362(13) ==> block
         N     2,=XL4'000000FF'
         SRL   2,2
         OR    3,2
         STC   3,0(8) ==> pos
         A     8,=F'1' ==> pos
         IC    2,362(13) ==> block
         SLL   2,6
         IC    3,363(13) ==> block
         OR    3,2
         STC   3,0(8) ==> pos
         A     8,=F'1' ==> pos
         SLR   3,3 ==> count
         LTR   9,9 ==> pad
         BE    @@L18
         LA    2,1(0,0)
         CLR   9,2 ==> pad
         BE    @@L34
         LA    3,2(0,0)
         CLR   9,3 ==> pad
         BE    @@L35
         MVC   88(4,13),364(13) ==> out
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L36    EQU   *
         SLR   15,15 ==> out
         B     @@L1
@@L18    EQU   *
         A     4,=F'1' ==> i
         CLR   4,6 ==> i,len
         BL    @@L28
@@L17    EQU   *
         LR    3,8 ==> pos
         S     3,364(13) ==> out
         L     2,8(11) ==> out_len
         ST    3,0(2) ==> out_len
         L     15,364(13) ==> out
@@L1     EQU   *
* Function 'base64_decode' epilogue
         PDPEPIL
* Function 'base64_decode' literal pool
         DS    0D
         LTORG
* Function 'base64_decode' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
