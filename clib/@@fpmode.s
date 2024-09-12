 TITLE '/home/mike/repos/crent370/clib/@@fpmode.c'
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
* external function '__fpmode' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  '__fpmode'
@@FPMODE PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fpmode' code
         L     6,0(11) ==> fp
         L     5,4(11) ==> mode
         LA    7,1(0,0) ==> err
         LR    4,6 ==> s,fp
         A     4,=F'106' ==> s
         SLR   3,3 ==> c
         LA    2,86(0,0) ==> n
         
*** MEMSET ***
         LR    14,4           => target (s) ==> s
         LR    15,2           => length (n) ==> n
         SLR   0,0             => source (NULL)
         LR    1,3            fill character ==> c
         SLL   1,24            move fill to high byte
         MVCL  14,0            Set target to fill character
         LR    4,3 ==> i,c
         IC    2,0(5) ==> mode
         CLM   2,1,=XL1'00'
         BE    @@L28
@@L33    EQU   *
         SLR   2,2
         IC    2,0(5) ==> mode
         L     3,=V(@@TOLOW)
         L     3,0(3) ==> __tolow
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,106(6,4) ==> .mode
         SLR   2,2
         IC    2,106(6,4) ==> .mode
         LA    3,129(0,0)
         CR    2,3
         BE    @@L9
         BH    @@L31
         LA    3,78(0,0)
         CLR   2,3
         BE    @@L11
         LA    3,107(0,0)
         CLR   2,3
         BE    @@L19
         B     @@L5
@@L31    EQU   *
         LA    3,153(0,0)
         CR    2,3
         BE    @@L13
         BH    @@L32
         LA    3,130(0,0)
         CLR   2,3
         BE    @@L12
         B     @@L5
@@L32    EQU   *
         LA    3,166(0,0)
         CLR   2,3
         BE    @@L16
         B     @@L5
@@L9     EQU   *
         LH    3,40(6) ==> .flags
         LR    2,3
         N     2,=F'8192'
         O     3,=F'6144'
         CH    2,=H'0'
         BE    @@L37
         B     @@L11
@@L12    EQU   *
         OC    40(2,6),=H'1024' ==> .flags
         B     @@L5
@@L13    EQU   *
         LH    3,40(6) ==> .flags
         LR    2,3
         N     2,=F'4096'
         CH    2,=H'0'
         BNE   @@L11
         LR    2,3
         N     2,=F'2048'
         O     3,=F'8192'
         CH    2,=H'0'
         BE    @@L37
         B     @@L11
@@L16    EQU   *
         LH    3,40(6) ==> .flags
         LR    2,3
         N     2,=F'8192'
         CH    2,=H'0'
         BNE   @@L11
         O     3,=F'4096'
@@L37    EQU   *
         STH   3,40(6) ==> .flags
         B     @@L5
@@L19    EQU   *
         LR    15,4 ==> j,i
         LA    2,85(0,0)
         CLR   4,2 ==> i
         BH    @@L21
         IC    2,0(5) ==> mode
         CLM   2,1,=XL1'00'
         BE    @@L21
         L     8,=V(@@TOLOW)
@@L25    EQU   *
         SLR   2,2
         IC    2,0(5) ==> mode
         L     3,0(8) ==> __tolow
         MH    2,=H'2'
         IC    3,1(2,3)
         STC   3,106(6,15) ==> .mode
         A     5,=F'1' ==> mode
         A     15,=F'1' ==> j
         LA    3,85(0,0)
         CLR   15,3 ==> j
         BH    @@L21
         IC    2,0(5) ==> mode
         CLM   2,1,=XL1'00'
         BNE   @@L25
@@L21    EQU   *
         LR    2,6 ==> fp
         AR    2,4 ==> i
         A     2,=F'106'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRSTR)
         BALR  14,15
         LTR   15,15 ==> err
         BE    @@L26
         OC    40(2,6),=H'512' ==> .flags
@@L26    EQU   *
         LR    2,6 ==> fp
         AR    2,4 ==> i
         A     2,=F'106'
         ST    2,88(13)
         MVC   92(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(STRSTR)
         BALR  14,15
         LTR   15,15 ==> err
         BE    @@L28
         OC    40(2,6),=H'256' ==> .flags
         B     @@L28
@@L5     EQU   *
         A     4,=F'1' ==> i
         A     5,=F'1' ==> mode
         LA    2,85(0,0)
         CLR   4,2 ==> i
         BH    @@L28
         IC    2,0(5) ==> mode
         CLM   2,1,=XL1'00'
         BNE   @@L33
@@L28    EQU   *
         L     2,40(6)
         N     2,=F'805306368'
         LTR   2,2
         BE    @@L11
         SLR   7,7 ==> err
@@L11    EQU   *
         LR    15,7 ==> err
* Function '__fpmode' epilogue
         PDPEPIL
* Function '__fpmode' literal pool
         DS    0D
         LTORG
* Function '__fpmode' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'record'
         DC    X'0'
@@LC1    EQU   *
         DC    C'bsam'
         DC    X'0'
         END
