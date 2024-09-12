 TITLE '/home/mike/repos/crent370/clib/@@ardel.c'
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
         
&FUNC    SETC 'arraydel'
* Program text area
         DS    0F
         EJECT
* external function 'arraydel' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'arraydel'
@@ARDEL  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'arraydel' code
         L     5,4(11) ==> index
         SLR   7,7 ==> vitem
         L     4,0(11) ==> carray,varray
         LTR   4,4 ==> carray
         BE    @@L11
         L     2,0(4) ==> carray
         LTR   2,2
         BE    @@L11
         LR    6,2 ==> array
         A     6,=F'-12' ==> array
         ST    6,88(13) ==> array
         MVC   92(4,13),=A(@@LC0)
         MVC   96(4,13),=F'4'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> vitem
         BNE   @@L11
         LTR   5,5 ==> index
         BE    @@L11
         CL    5,8(6) ==> index,count
         BH    @@L11
         BCTR  5,0 ==> index
         L     3,0(4) ==> carray
         LR    2,5 ==> index
         MH    2,=H'4'
         L     7,0(2,3) ==> vitem
         CL    5,8(6) ==> index,count
         BNL   @@L13
         LA    3,4(0,0)
@@L10    EQU   *
         LR    2,5 ==> index
         MH    2,=H'4'
         A     2,0(4) ==> carray
         L     8,0(3,2)
         ST    8,0(2)
         A     5,=F'1' ==> index
         CL    5,8(6) ==> index,count
         BL    @@L10
@@L13    EQU   *
         L     2,8(6) ==> .count
         BCTR  2,0
         ST    2,8(6) ==> .count
         L     3,0(4) ==> carray
         MH    2,=H'4'
         SLR   4,4
         ST    4,0(2,3)
@@L11    EQU   *
         LR    15,7 ==> vitem
* Function 'arraydel' epilogue
         PDPEPIL
* Function 'arraydel' literal pool
         DS    0D
         LTORG
* Function 'arraydel' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'ARRY'
         DC    X'0'
         END
