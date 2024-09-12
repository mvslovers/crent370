 TITLE '/home/mike/repos/crent370/clib/mtxunlk.c'
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
* external function 'mtxunlk' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'mtxunlk'
MTXUNLK  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'mtxunlk' code
         L     3,0(11) ==> mutex
         ST    3,88(13) ==> mutex
         LA    1,88(,13)
         L     15,=V(MTXHELD)
         BALR  14,15
         LTR   15,15 ==> crt
         BE    @@L1
         L     2,4(3) ==> .count
         BCTR  2,0
         ST    2,4(3) ==> .count
         LTR   2,2
         BNE   @@L1
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         LR    4,15 ==> crt
         LR    2,15 ==> crt
         A     2,=F'340'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    2,15 ==> count
         LTR   15,15 ==> count
         BE    @@L5
         A     4,=F'340'
@@L8     EQU   *
         ST    4,88(13)
         ST    2,92(13) ==> count
         LA    1,88(,13)
         L     15,=V(@@ARGET)
         BALR  14,15
         CLR   15,3 ==> x,mutex
         BNE   @@L7
         ST    4,88(13)
         ST    2,92(13) ==> count
         LA    1,88(,13)
         L     15,=V(@@ARDEL)
         BALR  14,15
         B     @@L5
@@L7     EQU   *
         BCTR  2,0 ==> count
         LTR   2,2 ==> count
         BNE   @@L8
@@L5     EQU   *
         MVC   0(4,3),=F'0' ==> .owner
         MVC   88(4,13),=A(@@LC0)
         MVC   92(4,13),=F'0'
         ST    3,96(13) ==> mutex
         LA    1,88(,13)
         L     15,=V(@@LKRNUF)
         BALR  14,15
@@L1     EQU   *
* Function 'mtxunlk' epilogue
         PDPEPIL
* Function 'mtxunlk' literal pool
         DS    0D
         LTORG
* Function 'mtxunlk' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'MUTEX.%08X'
         DC    X'0'
         END
