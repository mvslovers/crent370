 TITLE '/home/mike/repos/crent370/clib/@@txvols.c'
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
* external function '__txvols' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  '__txvols'
@@TXVOLS PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__txvols' code
         L     5,4(11) ==> vols
         LA    6,1(0,0) ==> err
         LTR   5,5 ==> vols
         BE    @@L2
         ST    5,88(13) ==> vols
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    3,15 ==> len
         B     @@L3
@@L2     EQU   *
         SLR   3,3 ==> len
@@L3     EQU   *
         MVC   104(4,13),=F'0'
         MVC   88(4,13),=F'1'
         LR    2,3 ==> len
         A     2,=F'1'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    4,15 ==> buf
         LTR   3,3 ==> len
         BE    @@L5
         LTR   15,15 ==> buf
         BE    @@L5
         ST    15,88(13) ==> buf
         ST    5,92(13) ==> vols
         ST    3,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         ST    4,88(13) ==> buf
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         LTR   15,15 ==> p
         BE    @@L17
         LA    2,104(,13)
@@L11    EQU   *
         ST    2,88(13)
         ST    15,92(13) ==> p
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         MVC   88(4,13),=F'0'
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRTOK)
         BALR  14,15
         LTR   15,15 ==> p
         BNE   @@L11
@@L17    EQU   *
         L     2,104(13)
         LTR   2,2
         BE    @@L5
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         MVC   88(4,13),=F'16'
         ST    15,92(13) ==> len
         MVC   96(4,13),104(13)
         LA    1,88(,13)
         L     15,=V(@@NWTX9A)
         BALR  14,15
         LTR   15,15 ==> tu
         BE    @@L5
         MVC   88(4,13),0(11) ==> txt99
         ST    15,92(13) ==> tu
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LR    6,15 ==> err
@@L5     EQU   *
         L     2,104(13)
         LTR   2,2
         BE    @@L14
         LA    2,104(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARFRE)
         BALR  14,15
@@L14    EQU   *
         LTR   4,4 ==> buf
         BE    @@L15
         ST    4,88(13) ==> buf
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L15    EQU   *
         LR    15,6 ==> err
* Function '__txvols' epilogue
         PDPEPIL
* Function '__txvols' literal pool
         DS    0D
         LTORG
* Function '__txvols' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C' ,'
         DC    X'0'
         END
