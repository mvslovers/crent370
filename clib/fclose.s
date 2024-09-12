 TITLE '/home/mike/repos/crent370/clib/fclose.c'
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
* external function 'fclose' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'fclose'
FCLOSE   PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'fclose' code
         L     4,0(11) ==> fp
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    5,15 ==> grt
         LTR   4,4 ==> fp
         BE    @@L3
         ST    4,88(13) ==> fp
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LR    3,15 ==> grt
         LTR   15,15 ==> grt
         BNE   @@L3
         LH    2,40(4) ==> .flags
         N     2,=F'16384'
         CH    2,=H'0'
         BE    @@L5
         ST    4,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FFLUSH)
         BALR  14,15
         MVC   88(4,13),8(4) ==> .dcb
         LA    1,88(,13)
         L     15,=V(@@ACLOSE)
         BALR  14,15
         ST    3,8(4) ==> grt,dcb
         ST    3,12(4) ==> grt,asmbuf
@@L5     EQU   *
         L     2,28(4) ==> .buf
         LTR   2,2
         BE    @@L6
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         MVC   28(4,4),=F'0' ==> .buf
         MVC   32(4,4),=F'0' ==> .upto
         MVC   36(4,4),=F'0' ==> .endbuf
@@L6     EQU   *
         LH    2,40(4) ==> .flags
         N     2,=F'-32768'
         CH    2,=H'0'
         BE    @@L7
         ST    4,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FPFREE)
         BALR  14,15
@@L7     EQU   *
         LR    2,5 ==> grt
         A     2,=F'24'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@ARCOU)
         BALR  14,15
         LTR   15,15 ==> count
         BE    @@L9
         LR    6,2
@@L12    EQU   *
         BCTR  15,0 ==> count
         L     2,24(5) ==> .grtfile
         LR    3,15 ==> count
         MH    3,=H'4'
         L     2,0(3,2)
         CLR   2,4 ==> fp
         BNE   @@L8
         ST    6,88(13)
         LR    2,15 ==> count
         A     2,=F'1'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@ARDEL)
         BALR  14,15
         B     @@L9
@@L8     EQU   *
         LTR   15,15 ==> count
         BNE   @@L12
@@L9     EQU   *
         LR    2,5 ==> grt
         A     2,=F'24'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         ST    4,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L3     EQU   *
         SLR   15,15
* Function 'fclose' epilogue
         PDPEPIL
* Function 'fclose' literal pool
         DS    0D
         LTORG
* Function 'fclose' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'F I L E'
         DC    X'0'
         END
