 TITLE '/home/mike/repos/crent370/clib/bcopy.c'
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
* external function 'bcopy' prologue
* frame base=88, local stack=0, call args=0
&FUNC    SETC  'bcopy'
BCOPY    PDPPRLG CINDEX=0,FRAME=88,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'bcopy' code
         L     2,0(11) ==> src
         L     4,4(11) ==> dest
         L     15,8(11) ==> len
         CLR   4,2 ==> dest,src
         BNL   @@L2
         LR    3,2 ==> firsts,src
         LR    2,4 ==> firstd,dest
         BCTR  15,0 ==> len
         L     4,=F'-1'
         CLR   15,4 ==> len
         BE    @@L1
@@L6     EQU   *
         MVC   0(1,2),0(3) ==> firstd,firsts
         A     3,=F'1' ==> firsts
         A     2,=F'1' ==> firstd
         BCTR  15,0 ==> len
         L     4,=F'-1'
         CLR   15,4 ==> len
         BE    @@L1
         B     @@L6
@@L2     EQU   *
         LR    3,2 ==> lasts,src
         AR    3,15 ==> lasts,len
         BCTR  3,0 ==> lasts
         LR    2,4 ==> lastd,dest
         AR    2,15 ==> lastd,len
         BCTR  2,0 ==> lastd
         BCTR  15,0 ==> len
         L     4,=F'-1'
         CLR   15,4 ==> len
         BE    @@L1
@@L11    EQU   *
         MVC   0(1,2),0(3) ==> lastd,lasts
         BCTR  3,0 ==> lasts
         BCTR  2,0 ==> lastd
         BCTR  15,0 ==> len
         L     4,=F'-1'
         CLR   15,4 ==> len
         BNE   @@L11
@@L1     EQU   *
* Function 'bcopy' epilogue
         PDPEPIL
* Function 'bcopy' literal pool
         DS    0D
         LTORG
* Function 'bcopy' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
