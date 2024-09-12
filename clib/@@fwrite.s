 TITLE '/home/mike/repos/crent370/clib/@@fwrite.c'
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
* external function '__fwrite' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  '__fwrite'
@@FWRITE PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fwrite' code
         SLR   8,8 ==> nmemb
         SLR   9,9 ==> nmemb
         L     6,4(11) ==> size
         L     7,12(11) ==> fp
         L     4,0(11) ==> ptr,vptr
         SLR   5,5 ==> i
         LH    2,40(7) ==> .flags
         N     2,=F'512'
         CH    2,=H'0'
         BE    @@L2
         L     9,8(11) ==> nmemb
         MR    8,6 ==> nmemb,size
         ST    9,108(13) ==> nmemb
         MVC   104(4,13),12(7) ==> .asmbuf
         MVC   88(4,13),104(13)
         ST    4,92(13) ==> ptr
         ST    9,96(13) ==> nmemb
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         MVC   88(4,13),8(7) ==> .dcb
         LA    2,104(,13)
         ST    2,92(13)
         LA    2,108(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@AWRITE)
         BALR  14,15
         LTR   15,15 ==> i
         BNE   @@L4
         L     2,24(7) ==> .filepos
         A     2,=F'1'
         ST    2,24(7) ==> .filepos
         LA    5,1(0,0) ==> i
         B     @@L4
@@L2     EQU   *
         SLR   5,5 ==> i
         CL    5,8(11) ==> i,nmemb
         BNL   @@L4
@@L15    EQU   *
         SLR   3,3 ==> j
         CLR   3,6 ==> j,size
         BNL   @@L18
@@L14    EQU   *
         SLR   2,2
         IC    2,0(4) ==> ptr
         ST    2,88(13)
         A     4,=F'1' ==> ptr
         ST    7,92(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FPUTC)
         BALR  14,15
         L     2,=F'-1'
         CLR   15,2 ==> i
         BE    @@L4
         A     3,=F'1' ==> j
         CLR   3,6 ==> j,size
         BL    @@L14
@@L18    EQU   *
         A     5,=F'1' ==> i
         CL    5,8(11) ==> i,nmemb
         BL    @@L15
@@L4     EQU   *
         LR    15,5 ==> i
* Function '__fwrite' epilogue
         PDPEPIL
* Function '__fwrite' literal pool
         DS    0D
         LTORG
* Function '__fwrite' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
