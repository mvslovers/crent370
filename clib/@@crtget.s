 TITLE '/home/mike/repos/crent370/clib/@@crtget.c'
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
@@6      EQU   *
         DC    C'__CRTGET'
         DC    X'0'
         DS    0F
         EJECT
* external function '__CRTGET' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__CRTGET'
@@CRTGET PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__CRTGET' code
         SLR   5,5 ==> locked
         L     9,540(5) ==> tcb
         LA    1,88(,13)
         L     15,=V(@@PPAGET)
         BALR  14,15
         LR    4,15 ==> ppa
         LR    7,5 ==> crt,locked
         LR    8,5 ==> count,crt
         LTR   15,15 ==> ppa
         BE    @@L3
         ST    15,88(13) ==> ppa
         MVC   92(4,13),=F'1'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    5,15 ==> locked
         LTR   15,15 ==> locked
         BNE   @@L3
         LR    2,4 ==> ppa
         A     2,=F'12'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    8,15 ==> count
         LR    3,7 ==> n,crt
         CLR   7,15 ==> crt,count
         BNL   @@L6
         L     6,12(4) ==> .ppacrt
@@L10    EQU   *
         LR    2,3 ==> n
         MH    2,=H'4'
         L     15,0(2,6) ==> crt
         L     2,8(15) ==> .crttcb
         CLR   2,9 ==> tcb
         BNE   @@L7
         LR    7,15 ==> crt
         B     @@L6
@@L7     EQU   *
         A     3,=F'1' ==> n
         CLR   3,8 ==> n,count
         BL    @@L10
@@L6     EQU   *
         LTR   5,5 ==> locked
         BNE   @@L3
         ST    4,88(13) ==> ppa
         MVC   92(4,13),=F'1'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L3     EQU   *
         LTR   7,7 ==> crt
         BNE   @@L12
         MVC   88(4,13),=A(@@LC0)
         MVC   92(4,13),=A(@@6)
         ST    9,96(13) ==> tcb
         ST    4,100(13) ==> ppa
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         LTR   4,4 ==> ppa
         BE    @@L12
         LTR   8,8 ==> count
         BE    @@L12
         MVC   88(4,13),12(4) ==> .ppacrt
         LR    2,8 ==> count
         MH    2,=H'4'
         ST    2,92(13)
         MVC   96(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(WTODUMPF)
         BALR  14,15
@@L12    EQU   *
         LR    15,7 ==> crt
* Function '__CRTGET' epilogue
         PDPEPIL
* Function '__CRTGET' literal pool
         DS    0D
         LTORG
* Function '__CRTGET' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'%s CRT for TCB(%08X) was not found in PPA(%08X)'
         DC    X'0'
@@LC1    EQU   *
         DC    C'PPACRT'
         DC    X'0'
         END
