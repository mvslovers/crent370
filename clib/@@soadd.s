 TITLE '/home/mike/repos/crent370/clib/@@soadd.c'
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
* external function '__soadd' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__soadd'
@@SOADD  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__soadd' code
         L     5,4(11) ==> name
         L     6,8(11) ==> peer
         LA    1,88(,13)
         L     15,=V(@@GRTGET)
         BALR  14,15
         LR    4,15 ==> grt
         MVC   88(4,13),=F'1'
         MVC   92(4,13),=F'48'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    3,15 ==> s
         LTR   15,15 ==> s
         BE    @@L3
         ST    15,88(13) ==> s
         MVC   92(4,13),=A(@@LC0)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         MVC   8(4,3),0(11) ==> .socket,ss
         LTR   5,5 ==> name
         BE    @@L4
         LR    2,3 ==> s
         A     2,=F'16'
         ST    2,88(13)
         ST    5,92(13) ==> name
         MVC   96(4,13),=F'16'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L4     EQU   *
         LTR   6,6 ==> peer
         BE    @@L5
         LR    2,3 ==> s
         A     2,=F'32'
         ST    2,88(13)
         ST    6,92(13) ==> peer
         MVC   96(4,13),=F'16'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
@@L5     EQU   *
         LR    2,4 ==> grt
         A     2,=F'28'
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LK)
         BALR  14,15
         ST    2,88(13)
         ST    3,92(13) ==> s
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         ST    2,88(13)
         MVC   92(4,13),=F'0'
         LA    1,88(,13)
         L     15,=V(@@LKUNLK)
         BALR  14,15
@@L3     EQU   *
         L     15,=F'-1'
* Function '__soadd' epilogue
         PDPEPIL
* Function '__soadd' literal pool
         DS    0D
         LTORG
* Function '__soadd' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'CLIBSOCK'
         DC    X'0'
         END
