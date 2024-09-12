 TITLE '/home/mike/repos/crent370/clib/ldexp.c'
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
* external function 'ldexp' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  'ldexp'
LDEXP    PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'ldexp' code
         MVC   88(8,13),0(11) ==> x
         LA    2,104(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(FREXP)
         BALR  14,15
         STD   0,80(,13) ==> split
         LM    4,5,80(13) ==> split
         L     2,8(11) ==> exp
         A     2,104(13)
         ST    2,104(13)
         BNL   @@L2
         A     2,=F'3'
@@L2     EQU   *
         LR    6,2 ==> hex_exp
         SRA   6,2 ==> hex_exp
         LR    2,6 ==> hex_exp
         MH    2,=H'4'
         L     15,104(13) ==> adj_exp
         SR    15,2 ==> adj_exp
         BNL   @@L3
         BCTR  6,0 ==> hex_exp
         A     15,=F'4' ==> adj_exp
@@L3     EQU   *
         LR    2,4
         SRL   2,16
         SLL   2,16
         SRA   2,16
         N     2,=F'33023'
         SLL   2,16
         N     4,=F'65535'
         OR    4,2
         LR    3,4
         SRL   3,16
         LR    2,6 ==> hex_exp
         A     2,=F'64'
         SLL   2,8
         N     2,=F'32512'
         SLL   2,16
         SRA   2,16
         OR    3,2
         SLL   3,16
         N     4,=F'65535'
         OR    4,3
         LTR   15,15 ==> adj_exp
         BNH   @@L9
@@L7     EQU   *
         STM   4,5,80(13) ==> split
         LD    0,80(,13) ==> split
         ADR   0,0 ==> split
         STD   0,80(,13) ==> split
         LM    4,5,80(13) ==> split
         BCTR  15,0 ==> adj_exp
         LTR   15,15 ==> adj_exp
         BH    @@L7
@@L9     EQU   *
         STM   4,5,80(13) ==> split
         LD    0,80(,13) ==> split
* Function 'ldexp' epilogue
         PDPEPIL
* Function 'ldexp' literal pool
         DS    0D
         LTORG
* Function 'ldexp' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
