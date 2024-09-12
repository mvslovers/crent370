 TITLE '/home/mike/repos/crent370/clib/@@reopen.c'
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
* external function '__reopen' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__reopen'
@@REOPEN PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__reopen' code
         L     3,8(11) ==> fp
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    6,15 ==> grt
         SLR   5,5 ==> dynamic
         LTR   3,3 ==> fp
         BE    @@L3
         LH    2,40(3) ==> .flags
         N     2,=F'16384'
         CH    2,=H'0'
         BE    @@L3
         ST    3,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(FFLUSH)
         BALR  14,15
         MVC   88(4,13),0(11) ==> fn
         MVC   92(4,13),4(11) ==> mode
         LA    1,88(,13)
         L     15,=V(FOPEN)
         BALR  14,15
         LR    4,15 ==> f
         LTR   15,15 ==> f
         BNE   @@L6
         OC    40(2,3),=H'2' ==> .flags
         LR    3,15 ==> fp,f
         B     @@L3
@@L6     EQU   *
         LH    2,40(3) ==> .flags
         N     2,=F'16384'
         CH    2,=H'0'
         BE    @@L7
         MVC   88(4,13),8(3) ==> .dcb
         LA    1,88(,13)
         L     15,=V(@@ACLOSE)
         BALR  14,15
@@L7     EQU   *
         MVC   8(4,3),8(4) ==> .dcb
         MVC   8(4,4),=F'0' ==> .dcb
         MVC   12(4,3),12(4) ==> .asmbuf
         MVC   12(4,4),=F'0' ==> .asmbuf
         MVC   16(2,3),16(4) ==> .lrecl
         MVC   18(2,3),18(4) ==> .blksize
         MVC   24(4,3),24(4) ==> .filepos
         L     2,28(3) ==> .buf
         LTR   2,2
         BE    @@L8
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L8     EQU   *
         MVC   28(4,3),28(4) ==> .buf
         MVC   28(4,4),=F'0' ==> .buf
         MVC   32(4,3),32(4) ==> .upto
         MVC   32(4,4),=F'0' ==> .upto
         MVC   36(4,3),36(4) ==> .endbuf
         MVC   36(4,4),=F'0' ==> .endbuf
         LH    2,40(3) ==> .flags
         N     2,=F'-32768'
         CH    2,=H'0'
         BE    @@L9
         LR    2,3 ==> fp
         A     2,=F'43'
         ST    2,88(13)
         LR    2,4 ==> f
         A     2,=F'43'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCMP)
         BALR  14,15
         LTR   15,15 ==> grt
         BE    @@L10
         ST    3,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FPFREE)
         BALR  14,15
         B     @@L9
@@L19    EQU   *
         LR    2,6 ==> grt
         A     2,=F'24'
         ST    2,88(13)
         LR    2,15 ==> count
         A     2,=F'1'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(@@ARDEL)
         BALR  14,15
         B     @@L14
@@L10    EQU   *
         LA    5,1(0,0) ==> dynamic
@@L9     EQU   *
         MVC   40(2,3),40(4) ==> .flags
         LTR   5,5 ==> dynamic
         BE    @@L12
         OC    40(2,3),=H'-32768' ==> .flags
@@L12    EQU   *
         MVC   40(2,4),=H'0' ==> .flags
         MVC   42(1,3),42(4) ==> .recfm
         LR    2,3 ==> fp
         A     2,=F'43'
         ST    2,88(13)
         LR    2,4 ==> f
         A     2,=F'43'
         ST    2,92(13)
         MVC   96(4,13),=F'9'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         LR    2,3 ==> fp
         A     2,=F'52'
         ST    2,88(13)
         LR    2,4 ==> f
         A     2,=F'52'
         ST    2,92(13)
         MVC   96(4,13),=F'9'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         LR    2,3 ==> fp
         A     2,=F'61'
         ST    2,88(13)
         LR    2,4 ==> f
         A     2,=F'61'
         ST    2,92(13)
         MVC   96(4,13),=F'45'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         LR    2,3 ==> fp
         A     2,=F'106'
         ST    2,88(13)
         LR    2,4 ==> f
         A     2,=F'106'
         ST    2,92(13)
         MVC   96(4,13),=F'86'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         LR    2,6 ==> grt
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
         BE    @@L14
         L     5,24(6) ==> .grtfile
@@L17    EQU   *
         BCTR  15,0 ==> count
         LR    2,15 ==> count
         MH    2,=H'4'
         L     2,0(2,5)
         CLR   2,4 ==> f
         BE    @@L19
         LTR   15,15 ==> count
         BNE   @@L17
@@L14    EQU   *
         LR    2,6 ==> grt
         A     2,=F'24'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
         ST    4,88(13) ==> f
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
@@L3     EQU   *
         LR    15,3 ==> fp
* Function '__reopen' epilogue
         PDPEPIL
* Function '__reopen' literal pool
         DS    0D
         LTORG
* Function '__reopen' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
