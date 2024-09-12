 TITLE '/home/mike/repos/crent370/clib/@@crtset.c'
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
* external function '__CRTSET' prologue
* frame base=88, local stack=16, call args=16
&FUNC    SETC  '__CRTSET'
@@CRTSET PDPPRLG CINDEX=0,FRAME=120,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__CRTSET' code
         L     2,=F'-1' ==> rc
         SLR   6,6 ==> locked
         L     5,540(6) ==> tcb
         MVC   104(4,13),132(5) ==> otcb
         MVC   108(4,13),180(5) ==> jscb
         LA    1,88(,13)
         L     15,=V(@@PPAGET)
         BALR  14,15
         LR    7,15 ==> ppa
         ST    6,112(13) ==> locked,grt
         LTR   15,15 ==> ppa
         BE    @@L3
         ST    15,88(13) ==> ppa
         ST    6,92(13) ==> locked
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         LR    6,15 ==> locked
         LTR   15,15 ==> locked
         BNE   @@L3
         MVC   88(4,13),=F'1'
         MVC   92(4,13),=F'392'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    8,15 ==> crt
         LTR   15,15 ==> crt
         BE    @@L5
         LR    2,7 ==> ppa
         A     2,=F'12'
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LR    4,6 ==> n,locked
         CLR   6,15 ==> locked,count
         BNL   @@L7
         L     9,12(7) ==> .ppacrt
@@L12    EQU   *
         LR    2,4 ==> n
         MH    2,=H'4'
         L     3,0(2,9)
         L     2,8(3) ==> .crttcb
         CL    2,104(13) ==> otcb
         BNE   @@L8
         LTR   3,3
         BE    @@L7
         MVC   112(4,13),280(3) ==> grt,crtgrt
         B     @@L7
@@L8     EQU   *
         A     4,=F'1' ==> n
         CLR   4,15 ==> n,count
         BL    @@L12
@@L7     EQU   *
         ST    8,88(13) ==> crt
         MVC   92(4,13),=A(@@LC0)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         ST    5,8(8) ==> tcb,crttcb
         MVC   280(4,8),112(13) ==> .crtgrt,grt
         LA    2,16(0,0)
         L     2,0(2) ==> cvt
         L     2,304(2)
         MVC   80(4,13),=XL8'4E00000080000000'
         ST    2,84(,13)
         XI    84(13),128
         LD    2,80(,13)
         SD    2,=XL8'4E00000080000000'
         MD    2,=D'1.04857649999999980039E0'
         LDR   0,2
         AD    0,=XL8'4F08000000000000'
         STD   0,80(,13)
         L     2,84(,13)
         ST    2,52(8) ==> .crttzoff
         MVC   60(4,8),=F'392' ==> .crtuserl
         L     2,108(13) ==> jscb
         MVC   269(1,8),236(2) ==> .crtauth
         LR    2,7 ==> ppa
         A     2,=F'12'
         ST    2,88(13)
         ST    8,92(13) ==> crt
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LR    2,15 ==> rc
@@L5     EQU   *
         LTR   6,6 ==> locked
         BNE   @@L3
         ST    7,88(13) ==> ppa
         ST    6,92(13) ==> locked
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L3     EQU   *
         LR    15,2 ==> rc
* Function '__CRTSET' epilogue
         PDPEPIL
* Function '__CRTSET' literal pool
         DS    0D
         LTORG
* Function '__CRTSET' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'CLIBCRT '
         DC    X'0'
         END
