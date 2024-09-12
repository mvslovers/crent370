 TITLE '/home/mike/repos/crent370/clib/@@b64enc.c'
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
* external function 'base64_encode' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'base64_encode'
@@B64ENC PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'base64_encode' code
         SLR   2,2 ==> olen
         SLR   3,3 ==> olen
         LR    4,2 ==> olen
         LR    5,3 ==> olen
         L     7,0(11) ==> src
         L     6,4(11) ==> len
         LR    2,6 ==> len
         MH    2,=H'4'
         SRDL  2,32 ==> olen
         LA    8,3(0,0)
         DR    2,8 ==> olen
         A     3,=F'4' ==> olen
         LR    4,3 ==> olen
         SRDL  4,32 ==> olen
         LA    2,72(0,0)
         DR    4,2 ==> olen
         AR    3,5 ==> olen
         A     3,=F'1' ==> olen
         SLR   15,15 ==> out
         CLR   3,6 ==> olen,len
         BL    @@L1
         MVC   88(4,13),=F'1'
         ST    3,92(13) ==> olen
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    9,15 ==> out
         LTR   15,15 ==> out
         BE    @@L1
         LR    8,7 ==> end,src
         AR    8,6 ==> end,len
         LR    6,7 ==> in,src
         LR    5,15 ==> pos,out
         SLR   7,7 ==> line_len
         LR    2,8 ==> end
         SR    2,6 ==> in
         LA    3,2(0,0)
         CR    2,3
         BNH   @@L14
         L     4,=V(@@B64TBL)
@@L8     EQU   *
         IC    2,0(6) ==> in
         N     2,=XL4'000000FF'
         SRL   2,2
         N     2,=XL4'000000FF'
         IC    2,0(2,4) ==> __b64tbl
         STC   2,0(5) ==> pos
         A     5,=F'1' ==> pos
         IC    3,0(6) ==> in
         N     3,=F'3'
         SLL   3,4
         IC    2,1(6)
         N     2,=XL4'000000FF'
         SRL   2,4
         N     2,=XL4'000000FF'
         OR    3,2
         IC    3,0(3,4) ==> __b64tbl
         STC   3,0(5) ==> pos
         A     5,=F'1' ==> pos
         IC    3,1(6)
         N     3,=F'15'
         SLL   3,2
         IC    2,2(6)
         N     2,=XL4'000000FF'
         SRL   2,6
         N     2,=XL4'000000FF'
         OR    3,2
         IC    3,0(3,4) ==> __b64tbl
         STC   3,0(5) ==> pos
         A     5,=F'1' ==> pos
         IC    2,2(6)
         N     2,=F'63'
         IC    2,0(2,4) ==> __b64tbl
         STC   2,0(5) ==> pos
         A     5,=F'1' ==> pos
         A     6,=F'3' ==> in
         A     7,=F'4' ==> line_len
         LA    2,71(0,0)
         CR    7,2 ==> line_len
         BNH   @@L4
         MVI   0(5),21 ==> pos
         A     5,=F'1' ==> pos
         SLR   7,7 ==> line_len
@@L4     EQU   *
         LR    2,8 ==> end
         SR    2,6 ==> in
         LA    3,2(0,0)
         CR    2,3
         BH    @@L8
@@L14    EQU   *
         CLR   8,6 ==> end,in
         BE    @@L9
         L     3,=V(@@B64TBL)
         IC    2,0(6) ==> in
         N     2,=XL4'000000FF'
         SRL   2,2
         N     2,=XL4'000000FF'
         IC    2,0(2,3) ==> __b64tbl
         STC   2,0(5) ==> pos
         A     5,=F'1' ==> pos
         LR    2,8 ==> end
         SR    2,6 ==> in
         LA    4,1(0,0)
         CLR   2,4
         BNE   @@L10
         IC    2,0(6) ==> in
         N     2,=F'3'
         SLL   2,4
         IC    3,0(2,3) ==> __b64tbl
         STC   3,0(5) ==> pos
         AR    5,4 ==> pos
         MVI   0(5),126 ==> pos
         AR    5,4 ==> pos
         B     @@L11
@@L10    EQU   *
         L     4,=V(@@B64TBL)
         IC    3,0(6) ==> in
         N     3,=F'3'
         SLL   3,4
         IC    2,1(6)
         N     2,=XL4'000000FF'
         SRL   2,4
         N     2,=XL4'000000FF'
         OR    3,2
         IC    3,0(3,4) ==> __b64tbl
         STC   3,0(5) ==> pos
         A     5,=F'1' ==> pos
         IC    2,1(6)
         N     2,=F'15'
         SLL   2,2
         IC    4,0(2,4) ==> __b64tbl
         STC   4,0(5) ==> pos
         A     5,=F'1' ==> pos
@@L11    EQU   *
         MVI   0(5),126 ==> pos
         A     5,=F'1' ==> pos
@@L9     EQU   *
         MVI   0(5),0 ==> pos
         L     8,8(11) ==> out_len
         LTR   8,8
         BE    @@L12
         LR    2,5 ==> pos
         SR    2,9 ==> out
         ST    2,0(8)
@@L12    EQU   *
         LR    15,9 ==> out
@@L1     EQU   *
* Function 'base64_encode' epilogue
         PDPEPIL
* Function 'base64_encode' literal pool
         DS    0D
         LTORG
* Function 'base64_encode' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
