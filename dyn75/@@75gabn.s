 TITLE '/home/mike/repos/crent370/dyn75/@@75gabn.c'
         COPY  PDPTOP
         CSECT
* GNU C version 3.2.3 - c2asm370 version 1.0 (mvs)
*        compiled by GNU C version 13.2.0.
*
* options passed:  -lang-c -I. -I/home/mike/repos/crent370/dyn75
* -I/home/mike/repos/crent370/include -iprefix -D__GNUC__=3
* -D__GNUC_MINOR__=2 -D__GNUC_PATCHLEVEL__=3 -D__GXX_ABI_VERSION=102
* -D__GCC__ -D__MVS__ -D__GCC__ -D__MVS__ -Asystem=mvs -Acpu=i370
* -Amachine=i370 -D__OPTIMIZE__ -D__STDC_HOSTED__=1 -trigraphs -O1
* -fverbose-asm
* 
* options enabled:  -fdefer-pop -fthread-jumps -fpeephole
* -ffunction-cse -fkeep-static-consts -fpcc-struct-return -fgcse-lm
* -fgcse-sm -fsched-interblock -fsched-spec -fbranch-count-reg
* -fcprop-registers -fcommon -fverbose-asm -fgnu-linker
* -fargument-alias -fmerge-constants -fident
* -fguess-branch-probability -fmath-errno -ftrapping-math
* -mchar-instructions -mno-pickax -mno-constants-first
*
         
&FUNC    SETC 'getaddrbyname'
* Program text area
         DS    0F
         EJECT
* external function 'getaddrbyname' prologue
* frame base=88, local stack=64, call args=8
&FUNC    SETC  'getaddrbyname'
@@75GABN PDPPRLG CINDEX=0,FRAME=160,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'getaddrbyname' code
         L     4,0(11) ==> name
         SLR   3,3 ==> addr
         LA    2,96(,13)
         XC    0(64,2),0(2)     clear __75 parameter list
         ST    4,88(13) ==> name
         LA    1,88(,13)
         L     15,=V(STRLEN)
         BALR  14,15
         LTR   15,15 ==> len
         BE    @@L3
         ST    15,100(13) ==> len,r1
         ST    4,116(13) ==> name,r5
         MVC   124(4,13),=F'4' ==> .r7
         LA    2,96(,13)
         ST    2,88(13)
         LA    1,88(,13)
         L     15,=V(@@75)
         BALR  14,15
         L     3,112(13) ==> addr,r4
@@L3     EQU   *
         LR    15,3 ==> addr
* Function 'getaddrbyname' epilogue
         PDPEPIL
* Function 'getaddrbyname' literal pool
         DS    0D
         LTORG
* Function 'getaddrbyname' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
