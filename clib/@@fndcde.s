 TITLE '/home/mike/repos/crent370/clib/@@fndcde.c'
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
         
&FUNC    SETC 'clib_find_cde'
* Program text area
         DS    0F
         EJECT
* external function 'clib_find_cde' prologue
* frame base=88, local stack=16, call args=16
&FUNC    SETC  'clib_find_cde'
@@FNDCDE PDPPRLG CINDEX=0,FRAME=120,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'clib_find_cde' code
         L     15,0(11) ==> name
         SLR   3,3 ==> psa
         L     2,540(3) ==> tcb
         L     2,124(2) ==> jstcb
         L     4,44(2) ==> cde
         L     2,=A(@@LC0)
         MVC   104(9,13),0(2) ==> temp
         IC    2,0(15) ==> name
         SLL   2,24
         SRA   2,24
         C     2,=F'0'
         BE    @@L3
@@L7     EQU   *
         IC    2,0(3,15) ==> i
         STC   2,104(13,3) ==> temp
         A     3,=F'1' ==> i
         LA    2,7(0,0)
         CR    3,2 ==> i
         BH    @@L3
         IC    2,0(3,15) ==> i
         CLM   2,1,=XL1'00'
         BNE   @@L7
@@L3     EQU   *
         LTR   4,4 ==> cde
         BE    @@L15
         LA    3,104(,13)
@@L12    EQU   *
         LR    2,4 ==> cde
         A     2,=F'8'
         ST    2,88(13)
         ST    3,92(13)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LR    2,4 ==> cde
         LTR   15,15 ==> cde
         BE    @@L1
         L     4,0(4) ==> cde,CDCHAIN
         LTR   4,4 ==> cde
         BNE   @@L12
@@L15    EQU   *
         SLR   2,2 ==> cde
@@L1     EQU   *
         LR    15,2 ==> cde
* Function 'clib_find_cde' epilogue
         PDPEPIL
* Function 'clib_find_cde' literal pool
         DS    0D
         LTORG
* Function 'clib_find_cde' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'        '
         DC    X'0'
         END
