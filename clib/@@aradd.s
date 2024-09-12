 TITLE '/home/mike/repos/crent370/clib/@@aradd.c'
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
         
&FUNC    SETC 'arrayadd'
* Program text area
         DS    0F
         EJECT
* external function 'arrayadd' prologue
* frame base=88, local stack=0, call args=16
&FUNC    SETC  'arrayadd'
@@ARADD  PDPPRLG CINDEX=0,FRAME=104,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'arrayadd' code
         SLR   6,6 ==> rc
         L     4,0(11) ==> carray,varray
         LTR   4,4 ==> carray
         BNE   @@L2
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         B     @@L10
@@L2     EQU   *
         L     2,0(4) ==> carray
         LTR   2,2
         BNE   @@L4
         MVC   88(4,13),=F'20'
         LA    1,88(,13)
         L     15,=V(@@ARNEW)
         BALR  14,15
         ST    15,0(4) ==> rc,carray
@@L4     EQU   *
         L     2,0(4) ==> carray
         LTR   2,2
         BE    @@L11
         L     5,0(4) ==> array,carray
         A     5,=F'-12' ==> array
         ST    5,88(13) ==> array
         MVC   92(4,13),=A(@@LC0)
         MVC   96(4,13),=F'4'
         LA    1,88(,13)
         L     15,=V(MEMCMP)
         BALR  14,15
         LTR   15,15 ==> rc
         BE    @@L6
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
@@L10    EQU   *
         MVC   0(4,15),=F'22' ==> rc
         B     @@L9
@@L6     EQU   *
         L     2,4(5) ==> .size
         CL    2,8(5) ==> .count
         BH    @@L7
         LR    3,2 ==> oldbytes
         MH    3,=H'4' ==> oldbytes
         A     3,=F'12' ==> oldbytes
         MH    2,=H'4' ==> newbytes
         A     2,=F'92' ==> newbytes
         MVC   88(4,13),=F'1'
         ST    2,92(13) ==> newbytes
         LA    1,88(,13)
         L     15,=V(CALLOC)
         BALR  14,15
         LR    2,15 ==> vnew
         LTR   15,15 ==> vnew
         BNE   @@L8
@@L11    EQU   *
         LA    1,88(,13)
         L     15,=V(@@ERRNO)
         BALR  14,15
         MVC   0(4,15),=F'12' ==> rc
@@L9     EQU   *
         L     6,=F'-1' ==> rc
         B     @@L3
@@L8     EQU   *
         ST    15,88(13) ==> vnew
         ST    5,92(13) ==> array
         ST    3,96(13) ==> oldbytes
         LA    1,88(,13)
         L     15,=V(MEMCPY)
         BALR  14,15
         ST    5,88(13) ==> array
         LA    1,88(,13)
         L     15,=V(FREE)
         BALR  14,15
         LR    5,2 ==> array,vnew
         L     2,4(2) ==> .size
         A     2,=F'20'
         ST    2,4(5) ==> .size
         LR    2,5 ==> vnew,array
         A     2,=F'12' ==> vnew
         ST    2,0(4) ==> vnew,carray
@@L7     EQU   *
         A     5,=F'8'
         L     2,0(5) ==> .count
         L     4,0(4) ==> carray
         LR    3,2
         MH    3,=H'4'
         L     7,4(11) ==> vitem
         ST    7,0(3,4)
         A     2,=F'1'
         ST    2,0(5) ==> .count
@@L3     EQU   *
         LR    15,6 ==> rc
* Function 'arrayadd' epilogue
         PDPEPIL
* Function 'arrayadd' literal pool
         DS    0D
         LTORG
* Function 'arrayadd' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
@@LC0    EQU   *
         DC    C'ARRY'
         DC    X'0'
         END
