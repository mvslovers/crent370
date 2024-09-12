 TITLE '/home/mike/repos/crent370/clib/strtok.c'
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
* Program data area
         DS    0F
@@2      EQU   *
         DC    F'0'
* Program text area
         DS    0F
         EJECT
* external function 'strtok' prologue
* frame base=88, local stack=0, call args=8
&FUNC    SETC  'strtok'
STRTOK   PDPPRLG CINDEX=0,FRAME=96,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'strtok' code
         L     2,0(11) ==> s1
         L     5,4(11) ==> s2
         LA    1,88(,13)
         L     15,=V(@@CRTGET)
         BALR  14,15
         LR    3,15 ==> old,crt
         A     3,=F'276' ==> old
         LTR   15,15 ==> crt
         BNE   @@L3
         L     3,=A(@@2) ==> old
@@L3     EQU   *
         LTR   2,2 ==> s1
         BE    @@L4
         ST    2,0(3) ==> s1,old
@@L4     EQU   *
         L     2,0(3) ==> p,old
         LR    15,2 ==> p
         LTR   2,2 ==> p
         BE    @@L1
         L     4,0(3) ==> p,old
         ST    4,88(13) ==> p
         ST    5,92(13) ==> s2
         LA    1,88(,13)
         L     15,=V(STRSPN)
         BALR  14,15
         LR    2,15 ==> len
         ST    4,88(13) ==> p
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         CLR   15,2 ==> remain,len
         BH    @@L6
         MVC   0(4,3),=F'0' ==> old
         SLR   15,15 ==> p
         B     @@L1
@@L6     EQU   *
         AR    4,2 ==> p,len
         ST    4,88(13) ==> p
         ST    5,92(13) ==> s2
         LA    1,88(,13)
         L     15,=V(STRCSPN)
         BALR  14,15
         LR    2,15 ==> len
         ST    4,88(13) ==> p
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         CLR   15,2 ==> remain,len
         BH    @@L7
         MVC   0(4,3),=F'0' ==> old
         B     @@L8
@@L7     EQU   *
         SLR   5,5
         STC   5,0(2,4) ==> len
         AR    2,4 ==> p
         A     2,=F'1'
         ST    2,0(3) ==> old
@@L8     EQU   *
         LR    15,4 ==> p
@@L1     EQU   *
* Function 'strtok' epilogue
         PDPEPIL
* Function 'strtok' literal pool
         DS    0D
         LTORG
* Function 'strtok' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
