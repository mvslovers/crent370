 TITLE '/home/mike/repos/crent370/clib/@@aradf.c'
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
         
&FUNC    SETC 'arrayaddf'
* Program text area
         DS    0F
         EJECT
* external function 'arrayaddf' prologue
* frame base=88, local stack=1024, call args=16
&FUNC    SETC  'arrayaddf'
@@ARADF  PDPPRLG CINDEX=0,FRAME=1128,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'arrayaddf' code
         L     5,0(11) ==> varray
         L     4,=F'-1' ==> rc
         LTR   5,5 ==> varray
         BE    @@L5
         LA    2,104(,13)
         ST    2,88(13)
         MVC   92(4,13),4(11)
         LA    2,8(,11) ==> tlist
         ST    2,96(13) ==> tlist
         LA    1,88(,13)
         L     15,=V(VSPRINTF)
         BALR  14,15
         MVC   88(4,13),=F'1'
         A     15,=F'1'
         ST    15,92(13)
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    3,15 ==> ptr
         LTR   15,15 ==> ptr
         BE    @@L5
         ST    15,88(13) ==> ptr
         LA    2,104(,13)
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(STRCPY)
         BALR  14,15
         ST    5,88(13) ==> varray
         ST    3,92(13) ==> ptr
         LA    1,88(,13)
         L     15,=V(@@ARADD)
         BALR  14,15
         LR    4,15 ==> rc
@@L5     EQU   *
         LR    15,4 ==> rc
* Function 'arrayaddf' epilogue
         PDPEPIL
* Function 'arrayaddf' literal pool
         DS    0D
         LTORG
* Function 'arrayaddf' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
