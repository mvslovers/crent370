 TITLE '/home/mike/repos/crent370/clib/@@grtset.c'
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
* external function '__grtset' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__grtset'
@@GRTSET PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__grtset' code
         L     5,=F'-1' ==> rc
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         LR    3,15 ==> crt
         LTR   15,15 ==> crt
         BE    @@L5
         LA    1,88(,13)
         L     15,=V(@@PPAGET)
         BALR  14,15
         LR    4,15 ==> ppa
         LTR   15,15 ==> ppa
         BE    @@L5
         MVC   88(4,13),=F'1'
         MVC   92(4,13),=F'80'
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    2,15 ==> crt
         LTR   15,15 ==> crt
         BE    @@L5
         ST    15,88(13) ==> crt
         MVC   92(4,13),=A(@@LC0)
         MVC   96(4,13),=F'8'
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         MVC   8(2,2),=H'80' ==> .grtclibl
         ST    2,280(3) ==> crt,crtgrt
         ST    2,16(4) ==> crt,ppagrt
         SLR   5,5 ==> rc
@@L5     EQU   *
         LR    15,5 ==> rc
* Function '__grtset' epilogue
         PDPEPIL
* Function '__grtset' literal pool
         DS    0D
         LTORG
* Function '__grtset' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'CLIBGRT '
         DC    X'0'
         END
