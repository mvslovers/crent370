 TITLE '/home/mike/repos/crent370/clib/@@nwtx9a.c'
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
* external function '__nwtx9a' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  '__nwtx9a'
@@NWTX9A PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function '__nwtx9a' code
         L     8,4(11) ==> count
         L     9,8(11) ==> array
         SLR   4,4 ==> i
         LR    6,4 ==> len,i
         CR    4,8 ==> i,count
         BNL   @@L17
@@L7     EQU   *
         LR    2,4 ==> i
         MH    2,=H'4'
         L     2,0(2,9)
         LTR   2,2
         BE    @@L4
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         AR    6,15 ==> len
@@L4     EQU   *
         A     4,=F'1' ==> i
         CR    4,8 ==> i,count
         BL    @@L7
@@L17    EQU   *
         LR    2,8 ==> bytes,count
         MH    2,=H'2' ==> bytes
         AR    2,6 ==> bytes,len
         MVC   88(4,13),=F'1'
         A     2,=F'8'
         ST    2,92(13)
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    7,15 ==> txt99
         LTR   15,15 ==> txt99
         BE    @@L8
         L     2,0(11) ==> dal
         STH   2,0(15) ==> .dal
         STH   8,2(15) ==> count,count
         LR    3,15 ==> next,txt99
         A     3,=F'4' ==> next
         SLR   4,4 ==> i
         CR    4,8 ==> i,count
         BNL   @@L8
@@L15    EQU   *
         LR    5,4 ==> i
         MH    5,=H'4'
         L     2,0(5,9)
         LTR   2,2
         BE    @@L13
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LR    6,15 ==> len
         STH   15,0(3) ==> len,size
         LR    2,3 ==> next
         A     2,=F'2'
         ST    2,88(13)
         L     5,0(5,9)
         ST    5,92(13)
         ST    15,96(13) ==> len
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         B     @@L14
@@L13    EQU   *
         SLR   6,6 ==> len
@@L14    EQU   *
         AR    3,6 ==> next,len
         A     3,=F'2' ==> next
         A     4,=F'1' ==> i
         CR    4,8 ==> i,count
         BL    @@L15
@@L8     EQU   *
         LR    15,7 ==> txt99
* Function '__nwtx9a' epilogue
         PDPEPIL
* Function '__nwtx9a' literal pool
         DS    0D
         LTORG
* Function '__nwtx9a' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
