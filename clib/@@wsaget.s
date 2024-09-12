 TITLE '/home/mike/repos/crent370/clib/@@wsaget.c'
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
* external function '__wsaget' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__wsaget'
@@WSAGET PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__wsaget' code
         L     5,0(11) ==> key
         L     8,4(11) ==> len
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    6,15 ==> grt
         SLR   3,3 ==> wsa
         LR    7,8 ==> size,len
         A     7,=F'16' ==> size
         LR    2,15 ==> grt
         A     2,=F'68'
         ST    2,88(13)
         ST    3,92(13) ==> wsa
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LTR   15,15 ==> count
         BE    @@L3
         L     4,68(6) ==> .grtwsa
@@L7     EQU   *
         BCTR  15,0 ==> count
         LR    2,15 ==> count
         MH    2,=H'4'
         L     3,0(2,4) ==> wsa
         LTR   3,3 ==> wsa
         BE    @@L2
         L     2,8(3) ==> .wsakey
         CLR   2,5 ==> key
         BNE   @@L6
         L     2,12(3) ==> .wsasize
         CLR   2,7 ==> size
         BE    @@L3
@@L6     EQU   *
         SLR   3,3 ==> wsa
@@L2     EQU   *
         LTR   15,15 ==> count
         BNE   @@L7
@@L3     EQU   *
         LTR   3,3 ==> wsa
         BNE   @@L8
         MVC   88(4,13),=F'1'
         ST    7,92(13) ==> size
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    3,15 ==> wsa
         LTR   15,15 ==> wsa
         BE    @@L9
         ST    15,88(13) ==> wsa
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         ST    5,8(3) ==> key,wsakey
         ST    7,12(3) ==> size,wsasize
         L     2,=F'8192'
         CLR   5,2 ==> key
         BNH   @@L10
         L     2,=F'-16777217'
         CLR   5,2 ==> key
         BH    @@L10
         LR    2,3 ==> wsa
         A     2,=F'16'
         ST    2,88(13)
         ST    5,92(13) ==> key
         ST    8,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L10    EQU   *
         LR    2,6 ==> grt
         A     2,=F'68'
         ST    2,88(13)
         ST    3,92(13) ==> wsa
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LTR   15,15 ==> grt
         BE    @@L8
         MVC   88(4,13),=A(@@LC1)
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
         ST    3,88(13) ==> wsa
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         SLR   3,3 ==> wsa
         B     @@L8
@@L9     EQU   *
         MVC   88(4,13),=A(@@LC2)
         ST    7,92(13) ==> size
         LA    1,88(,13)
         L     15,=V(WTOF)
         BALR  14,15
@@L8     EQU   *
         LR    2,6 ==> grt
         A     2,=F'68'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         LR    15,3 ==> grt,wsa
         A     15,=F'16' ==> grt
         LTR   3,3 ==> wsa
         BNE   @@L14
         SLR   15,15 ==> grt
@@L14    EQU   *
* Function '__wsaget' epilogue
         PDPEPIL
* Function '__wsaget' literal pool
         DS    0D
         LTORG
* Function '__wsaget' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'CLIBWSA '
         DC    X'0'
@@LC1    EQU   *
         DC    C'__wsaget() error adding new writable static area'
         DC    X'0'
@@LC2    EQU   *
         DC    C'__wsaget() out of memory for requested size %u b'
         DC    C'ytes'
         DC    X'0'
         END
