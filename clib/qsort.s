 TITLE '/home/mike/repos/crent370/clib/qsort.c'
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
* external function 'qsort' prologue
* frame base=88, local stack=72, call args=16
&FUNC    SETC  'qsort'
QSORT    PDPPRLG CINDEX=0,FRAME=176,BASER=12,ENTRY=YES
         B     @@FEN0
         LTORG
@@FEN0   EQU   *
         DROP  12
         BALR  12,0
         USING *,12
@@PG0    EQU   *
         LR    11,1
         L     10,=A(@@PGT0)
* Function 'qsort' code
         SLR   2,2
         SLR   3,3
         ST    2,112(13)
         ST    3,4+112(13)
         ST    2,120(13)
         ST    3,4+120(13)
         ST    2,128(13)
         ST    3,4+128(13)
         LR    8,2 ==> b
         LR    9,3 ==> b
         ST    2,136(13) ==> b
         ST    3,4+136(13) ==> b
         ST    2,144(13) ==> b
         ST    3,4+144(13) ==> b
         ST    2,152(13) ==> b
         ST    3,4+152(13) ==> b
         ST    2,160(13) ==> b
         ST    3,4+160(13) ==> b
         L     7,8(11) ==> size
         L     6,0(11) ==> base2,base
         L     4,4(11) ==> nmemb
         LA    3,1(0,0)
         CLR   4,3
         BNH   @@L29
@@L27    EQU   *
         MVC   104(4,13),=F'0' ==> a
         L     5,4(11) ==> b,nmemb
         BCTR  5,0 ==> b
         LR    2,5 ==> b
         SRL   2,1
         ST    2,108(13) ==> c
         B     @@L8
@@L11    EQU   *
         L     3,104(13) ==> a
         A     3,=F'1'
         ST    3,104(13) ==> a
@@L8     EQU   *
         MVC   116(4,13),108(13) ==> c
         L     2,112(13)
         L     3,4+112(13)
         MR    2,7 ==> size
         ST    2,112(13)
         ST    3,4+112(13)
         L     2,116(13)
         AR    2,6 ==> base2
         ST    2,88(13)
         MVC   124(4,13),104(13) ==> a
         L     2,120(13)
         L     3,4+120(13)
         MR    2,7 ==> size
         ST    2,120(13)
         ST    3,4+120(13)
         L     2,124(13)
         AR    2,6 ==> base2
         ST    2,92(13)
         L     3,12(11) ==> compar
         LA    1,88(,13)
         LA    15,0(3)
         BALR  14,15
         LTR   15,15
         BH    @@L11
         B     @@L12
@@L15    EQU   *
         BCTR  5,0 ==> b
@@L12    EQU   *
         MVC   132(4,13),108(13) ==> c
         L     2,128(13)
         L     3,4+128(13)
         MR    2,7 ==> size
         ST    2,128(13)
         ST    3,4+128(13)
         L     2,132(13)
         AR    2,6 ==> base2
         ST    2,88(13)
         LR    9,5 ==> b
         MR    8,7 ==> b,size
         LR    2,6 ==> base2
         AR    2,9 ==> b
         ST    2,92(13)
         L     3,12(11) ==> compar
         LA    1,88(,13)
         LA    15,0(3)
         BALR  14,15
         LTR   15,15
         BL    @@L15
         L     4,104(13) ==> a
         CLR   4,5 ==> b
         BNL   @@L6
         SLR   15,15 ==> i
         CLR   15,7 ==> i,size
         BNL   @@L31
@@L21    EQU   *
         MVC   140(4,13),104(13) ==> a
         L     2,136(13)
         L     3,4+136(13)
         MR    2,7 ==> size
         ST    2,136(13)
         ST    3,4+136(13)
         L     2,140(13)
         AR    2,15 ==> i
         AR    2,6 ==> base2
         ST    2,168(13)
         IC    4,0(2) ==> tmp
         ST    5,148(13) ==> b
         L     2,144(13)
         L     3,4+144(13)
         MR    2,7 ==> size
         ST    2,144(13)
         ST    3,4+144(13)
         L     2,148(13)
         AR    2,15 ==> i
         AR    2,6 ==> base2
         L     3,168(13)
         MVC   0(1,3),0(2)
         STC   4,0(2) ==> tmp
         A     15,=F'1' ==> i
         CLR   15,7 ==> i,size
         BL    @@L21
@@L31    EQU   *
         L     4,108(13) ==> c
         CL    4,104(13) ==> a
         BNE   @@L22
         ST    5,108(13) ==> b,c
         B     @@L23
@@L22    EQU   *
         L     2,108(13) ==> c
         CLR   2,5 ==> b
         BNE   @@L23
         MVC   108(4,13),104(13) ==> c,a
@@L23    EQU   *
         L     3,104(13) ==> a
         A     3,=F'1'
         ST    3,104(13) ==> a
         BCTR  5,0 ==> b
         B     @@L8
@@L6     EQU   *
         A     5,=F'1' ==> b
         L     2,4(11) ==> nmemb
         SR    2,5 ==> nmemb,b
         CLR   5,2 ==> b,nmemb
         BNL   @@L25
         ST    6,88(13) ==> base2
         ST    5,92(13) ==> b
         ST    7,96(13) ==> size
         MVC   100(4,13),12(11) ==> compar
         LA    1,88(,13)
         L     15,=A(QSORT)
         BALR  14,15
         ST    5,156(13) ==> b
         L     4,152(13)
         L     5,4+152(13)
         MR    4,7 ==> size
         ST    4,152(13)
         ST    5,4+152(13)
         AR    6,5 ==> base2
         ST    2,4(11) ==> nmemb
         B     @@L2
@@L25    EQU   *
         ST    5,164(13) ==> b
         L     2,160(13)
         L     3,4+160(13)
         MR    2,7 ==> size
         ST    2,160(13)
         ST    3,4+160(13)
         L     2,164(13)
         AR    2,6 ==> base2
         ST    2,88(13)
         L     2,4(11) ==> nmemb
         SR    2,5 ==> b
         ST    2,92(13)
         ST    7,96(13) ==> size
         MVC   100(4,13),12(11) ==> compar
         LA    1,88(,13)
         L     15,=A(QSORT)
         BALR  14,15
         ST    5,4(11) ==> b,nmemb
@@L2     EQU   *
         L     4,4(11) ==> nmemb
         LA    3,1(0,0)
         CLR   4,3
         BH    @@L27
@@L29    EQU   *
* Function 'qsort' epilogue
         PDPEPIL
* Function 'qsort' literal pool
         DS    0D
         LTORG
* Function 'qsort' page table
@@PGT0   DS    0F
         DC    A(@@PG0)
         END
