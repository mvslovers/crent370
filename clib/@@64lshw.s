 TITLE '/home/mike/repos/crent370/clib/@@64lshw.c'
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
         
&FUNC    SETC '__64_lshift_word'
* Program text area
@@2      EQU   *
         DC    C'__64_lshift_word'
         DC    X'0'
         DS    0F
         EJECT
* external function '__64_lshift_word' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__64_lshift_word'
@@64LSHW PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__64_lshift_word' code
         L     4,0(11) ==> a
         L     2,4(11) ==> nwords
         LR    6,2 ==> shift,nwords
         LTR   4,4 ==> a
         BE    @@L1
         LTR   2,2 ==> shift
         BNL   @@L3
         SLR   6,6 ==> shift
@@L3     EQU   *
         LA    3,4(0,0)
         CR    6,3 ==> shift
         BNH   @@L4
         LR    6,3 ==> shift
@@L4     EQU   *
         CLR   6,2 ==> shift,nwords
         BE    @@L5
         MVC   88(4,13),=A(@@LC0)
         MVC   92(4,13),=A(@@2)
         ST    2,96(13) ==> nwords
         ST    6,100(13) ==> shift
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
@@L5     EQU   *
         SLR   5,5 ==> i
         CR    5,6 ==> i,shift
         BNL   @@L1
         LA    3,2(0,0)
@@L15    EQU   *
         SLR   15,15 ==> j
@@L14    EQU   *
         LR    2,15 ==> j
         MH    2,=H'2'
         AR    2,4 ==> a
         LH    7,0(3,2) ==> .array
         STH   7,0(2) ==> .array
         A     15,=F'1' ==> j
         LA    2,2(0,0)
         CR    15,2 ==> j
         BNH   @@L14
         LR    2,15 ==> j
         MH    2,=H'2'
         SLR   7,7
         STH   7,0(2,4) ==> .array
         A     5,=F'1' ==> i
         CR    5,6 ==> i,shift
         BL    @@L15
@@L1     EQU   *
* Function '__64_lshift_word' epilogue
         PDPEPIL
* Function '__64_lshift_word' literal pool
         DS    0D
         LTORG
* Function '__64_lshift_word' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'%s: *** shift corrected from %d to %d ***'
         DC    X'0'
         END
