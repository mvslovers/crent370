 TITLE '/home/mike/repos/crent370/clib/@@fread.c'
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
* external function '__fread' prologue
* frame base=88, local stack=8, call args=16
&FUNC    SETC  '__fread'
@@FREAD  PDPPRLG CINDEX=0,FRAME=112,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__fread' code
         SLR   8,8 ==> nmemb
         SLR   9,9 ==> nmemb
         L     4,4(11) ==> size
         L     7,8(11) ==> nmemb
         L     6,12(11) ==> fp
         L     3,0(11) ==> p,ptr
         MVC   108(4,13),=F'0'
         LH    2,40(6) ==> .flags
         N     2,=F'1'
         SLR   5,5 ==> i
         CH    2,=H'0'
         BNE   @@L3
         LH    2,40(6) ==> .flags
         N     2,=F'512'
         CH    2,=H'0'
         BE    @@L4
         LR    9,7 ==> nmemb
         MR    8,4 ==> nmemb,size
         LR    4,9 ==> size,nmemb
         MVC   88(4,13),8(6) ==> .dcb
         LA    2,104(,13)
         ST    2,92(13)
         LA    2,108(,13)
         ST    2,96(13)
         LA    1,88(,13)
         L     15,=V(@@AREAD)
         BALR  14,15
         LTR   15,15 ==> i
         BE    @@L5
         OC    40(2,6),=H'1' ==> .flags
         SLR   5,5 ==> i
         B     @@L3
@@L5     EQU   *
         LR    5,7 ==> i,nmemb
         CL    9,108(13) ==> size
         BNH   @@L6
         L     4,108(13) ==> size
@@L6     EQU   *
         MVC   88(4,13),0(11) ==> ptr
         MVC   92(4,13),104(13)
         ST    4,96(13) ==> size
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         L     2,24(6) ==> .filepos
         A     2,=F'1'
         ST    2,24(6) ==> .filepos
         B     @@L3
@@L4     EQU   *
         SLR   5,5 ==> i
         CLR   5,7 ==> i,nmemb
         BNL   @@L3
@@L17    EQU   *
         SLR   2,2 ==> j
         CLR   2,4 ==> j,size
         BNL   @@L20
@@L16    EQU   *
         ST    6,88(13) ==> fp
         LA    1,88(,13)
         L     15,=V(@@FGETC)
         BALR  14,15
         L     8,=F'-1'
         CLR   15,8 ==> c
         BE    @@L3
         STC   15,0(3) ==> c,p
         A     3,=F'1' ==> p
         A     2,=F'1' ==> j
         CLR   2,4 ==> j,size
         BL    @@L16
@@L20    EQU   *
         A     5,=F'1' ==> i
         CLR   5,7 ==> i,nmemb
         BL    @@L17
@@L3     EQU   *
         LR    15,5 ==> i
* Function '__fread' epilogue
         PDPEPIL
* Function '__fread' literal pool
         DS    0D
         LTORG
* Function '__fread' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
