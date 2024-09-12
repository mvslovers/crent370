 TITLE '/home/mike/repos/crent370/clib/@@txrecf.c'
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
* Program data area
@@2      EQU   *
         DC    X'D4'
         DC    X'02'
         DC    X'D9'
         DC    X'02'
         DC    X'C1'
         DC    X'04'
         DC    X'C7'
         DC    X'04'
         DC    X'E2'
         DC    X'08'
         DC    X'C2'
         DC    X'10'
         DC    X'C4'
         DC    X'20'
         DC    X'E3'
         DC    X'20'
         DC    X'E5'
         DC    X'40'
         DC    X'C6'
         DC    X'80'
         DC    X'E4'
         DC    X'C0'
         DC    X'00'
         DC    X'00'
* Program text area
         DS    0F
         EJECT
* external function '__txrecf' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  '__txrecf'
@@TXRECF PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__txrecf' code
         L     7,4(11) ==> recfm
         LA    9,1(0,0) ==> err
         LTR   7,7 ==> recfm
         BE    @@L15
         MVI   104(13),0
         SLR   6,6 ==> i
         IC    2,0(7) ==> recfm
         CLM   2,1,=XL1'00'
         BE    @@L18
         L     8,=A(@@2)
@@L13    EQU   *
         IC    4,0(6,7) ==> c,i
         O     4,=XL4'40' ==> c
         SLR   15,15 ==> j
         IC    2,0(15,8) ==> .recfm
         CLM   2,1,=XL1'00'
         BE    @@L5
         L     5,=A(@@2)
@@L12    EQU   *
         LR    2,15 ==> j
         MH    2,=H'2'
         IC    3,0(2,5) ==> .recfm
         STC   3,80(,13)
         CLM   4,1,80(13) ==> c
         BNE   @@L9
         AR    2,5
         OC    104(1,13),1(2) ==> .type
         B     @@L5
@@L9     EQU   *
         A     15,=F'1' ==> j
         LR    2,15 ==> j
         MH    2,=H'2'
         L     3,=A(@@2)
         IC    2,0(2,3) ==> .recfm
         CLM   2,1,=XL1'00'
         BNE   @@L12
@@L5     EQU   *
         A     6,=F'1' ==> i
         IC    2,0(6,7) ==> i
         CLM   2,1,=XL1'00'
         BNE   @@L13
@@L18    EQU   *
         CLI   104(13),0
         BE    @@L15
         MVC   88(4,13),=F'73'
         MVC   92(4,13),=F'1'
         MVC   96(4,13),=F'1'
         LA    2,104(,13)
         ST    2,100(13)
         LA    1,88(,13)
         L     15,=V(@@NWTX99)
         BALR  14,15
         LTR   15,15 ==> tu
         BE    @@L15
         MVC   88(4,13),0(11) ==> txt99
         ST    15,92(13) ==> tu
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LR    9,15 ==> err
@@L15    EQU   *
         LR    15,9 ==> err
* Function '__txrecf' epilogue
         PDPEPIL
* Function '__txrecf' literal pool
         DS    0D
         LTORG
* Function '__txrecf' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
